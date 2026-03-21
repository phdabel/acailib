# ACAI-LIB — Arquitetura e Guia de Implementação

Biblioteca C++11 para redes neurais artificiais do tipo Multi-Layer Perceptron (MLP) com aprendizado supervisionado via backpropagation.

---

## Estrutura de Diretórios

```
acailib/
├── core/                    # Abstrações base (IUnit, Edge, ObjectID)
├── neuralnet/
│   ├── algorithms/          # Algoritmos de aprendizado
│   ├── functions/           # Funções de ativação
│   ├── neuron/              # Hierarquia de neurônios
│   ├── Layer.h/.cpp         # Camada da rede
│   ├── MultiLayerPerceptron.h/.cpp
│   ├── INeuralNetwork.h     # Interface da rede
│   ├── IAbstractLayer.h     # Interface de camada
│   └── LayerType.h          # Enum de tipos de camada
├── problem/                 # WeightMatrix (incompleto)
├── utils/                   # IdGenerator (singleton)
├── tests/                   # Testes unitários CppUnit
├── data/                    # Datasets (xor.dat)
└── project-uml/             # Diagrama UML (ACAI-LIB.png)
```

---

## Diagrama de Dependências

```
IUnit
 └── Edge
 └── AbstractNeuron
      ├── Neuron
      └── BiasNeuron

INeuralNetwork<Layer>
 └── MultiLayerPerceptron
      ├── Layer  (1..*)
      │    └── AbstractNeuron  (1..*)
      └── IActivationFunction

ILearningAlgorithm<MultiLayerPerceptron>
 └── BackPropagationLearning
      └── MultiLayerPerceptron*

IActivationFunction
 ├── FuncSigmoid
 ├── FuncTanH
 └── FuncRectifier

IMatrix
 └── WeightMatrix
```

---

## Classes — Referência Completa

---

### `core/` — Infraestrutura Base

#### `ObjectID`
> `core/ObjectID.h` | `core/ObjectID.cpp`

Identificador único para qualquer objeto da biblioteca. Gerado automaticamente via `IdGenerator`.

| Método | Descrição |
|--------|-----------|
| `ObjectID()` | Construtor: obtém ID único do singleton `IdGenerator` |
| `int getValue()` | Retorna o valor inteiro do ID |
| `bool equals(ObjectID &o)` | Compara dois IDs |
| `double random()` | Retorna um double aleatório entre -1 e 1 (usado para inicializar pesos) |
| `string toString()` | Representação textual |

---

#### `IUnit` *(interface)*
> `core/IUnit.h`

Interface base para qualquer unidade do grafo (neurônio ou aresta).

| Método | Descrição |
|--------|-----------|
| `ObjectID& getId()` | Retorna o ID do objeto |
| `void setId(ObjectID*)` | Define o ID |
| `double eval(int time=0)` | Avalia e retorna o valor da unidade |
| `string toString()` | Representação textual |

---

#### `UnitType` *(enum)*
> `core/UnitType.h`

```cpp
enum UnitType { NODE, FACTOR, POTENTIAL, NEURON, EDGE, BIAS };
```

---

#### `Edge`
> `core/Edge.h` | `core/Edge.cpp`

Aresta direcional entre dois `IUnit`. Representa uma conexão sináptica com peso `w`.

| Membro / Método | Descrição |
|-----------------|-----------|
| `Edge(IUnit &v1, IUnit &v2)` | Constrói a aresta de `v1` → `v2` |
| `double getWeight()` | Retorna o peso `w` |
| `void setWeight(double w)` | Define o peso |
| `IUnit& getVertex1()` | Neurônio de origem (`v1`) |
| `IUnit& getVertex2()` | Neurônio de destino (`v2`) |
| `double eval(int time=0)` | Retorna `w × v1.eval(time)` |
| `string getI()` / `getJ()` | Índices do neurônio origem / destino |

> **Nota:** o peso é inicializado aleatoriamente em `setId()` via `ObjectID::random()`.

---

#### `IdGenerator`
> `utils/IdGenerator.h` | `utils/IdGenerator.cpp`

Singleton que fornece IDs inteiros sequenciais a todos os objetos.

| Método | Descrição |
|--------|-----------|
| `static IdGenerator* getInstance()` | Retorna a instância única |
| `int getId()` | Retorna próximo ID e incrementa contador |
| `int totalObjects()` | Total de objetos criados |

---

### `neuralnet/` — Rede Neural

#### `LayerType` *(enum)*
> `neuralnet/LayerType.h`

```cpp
enum LayerType { INPUT, HIDDEN, OUTPUT };
```

---

#### `IAbstractLayer` *(interface)*
> `neuralnet/IAbstractLayer.h`

| Método | Descrição |
|--------|-----------|
| `vector<AbstractNeuron*> getNeurons()` | Todos os neurônios da camada |
| `void addNeuron(AbstractNeuron*)` | Adiciona neurônio |
| `AbstractNeuron& getNeuron(int i)` | Neurônio pelo índice de inserção |

---

#### `Layer`
> `neuralnet/Layer.h` | `neuralnet/Layer.cpp`

Implementa `IAbstractLayer`. Armazena neurônios num `map<ObjectID*, AbstractNeuron*>` ordenado por ID.

| Método | Descrição |
|--------|-----------|
| `Layer()` / `Layer(LayerType)` | Construtores |
| `LayerType getType()` | Retorna `INPUT`, `HIDDEN` ou `OUTPUT` |
| `void setType(LayerType)` | Define o tipo |
| `void addNeuron(AbstractNeuron*)` | Insere neurônio no mapa |
| `vector<AbstractNeuron*> getNeurons()` | Todos os neurônios em ordem de ID |
| `AbstractNeuron& getNeuron(int i)` | Neurônio pelo índice ordinal |

---

### `neuralnet/neuron/` — Hierarquia de Neurônios

#### `AbstractNeuron`
> `neuralnet/neuron/AbstractNeuron.h` | `.cpp`

Classe base abstrata para neurônios. Implementa `IUnit` e toda a lógica de forward pass.

| Membro | Tipo | Descrição |
|--------|------|-----------|
| `delta` | `double` | Gradiente local δ (usado no backprop) |
| `error` | `double` | Erro do neurônio (usado no backprop) |
| `edges` | `vector<Edge*>` | Arestas de entrada |
| `timeCache` | `int` | Último instante de avaliação (evita recomputação) |

| Método | Descrição |
|--------|-----------|
| `double eval(int time=0)` | Se não tem arestas: retorna `getValue()`. Caso contrário: calcula `f(net)` e armazena em `value`. Usa cache por `time`. |
| `double computeNetwork()` | Soma `edge->eval()` para todas as arestas: Σ(wᵢ · xᵢ) |
| `void addEdge(Edge*)` | Adiciona aresta de entrada |
| `vector<Edge*> getEdges()` | Retorna lista de arestas |
| `Edge& getEdge(int id)` | Busca aresta por ID |
| `void setFunction(IActivationFunction&)` | Define função de ativação |
| `IActivationFunction& getFunction()` | Retorna função de ativação |
| `double getDelta()` / `setDelta(double)` | Getter/setter de δ |
| `double getError()` / `setError(double)` | Getter/setter de erro |
| `virtual double getValue()` | Valor de saída do neurônio (abstrato) |
| `virtual void setValue(double)` | Define valor de saída (abstrato) |

---

#### `Neuron`
> `neuralnet/neuron/Neuron.h` | `.cpp`

Neurônio comum. Herda `AbstractNeuron`.

| Membro | Tipo | Valor padrão |
|--------|------|--------------|
| `value` | `double` | `-1.0` |
| `index` | `string` | `""` |

| Método | Descrição |
|--------|-----------|
| `double getValue()` | Retorna `value` |
| `void setValue(double)` | Define `value` |
| `string getIndex()` | Retorna rótulo do neurônio |
| `void setIndex(string)` | Define rótulo |

---

#### `BiasNeuron`
> `neuralnet/neuron/BiasNeuron.h` | `.cpp`

Neurônio de bias. Herda `AbstractNeuron`. O valor é fixo em `1.0`.

| Membro | Tipo | Valor fixo |
|--------|------|------------|
| `value` | `double` | `1.0` |

> `getValue()` sempre retorna `1.0`. `setValue()` existe mas não altera o valor efetivo.

---

### `neuralnet/functions/` — Funções de Ativação

#### `IActivationFunction` *(interface)*
> `neuralnet/functions/IActivationFunction.h`

| Método | Descrição |
|--------|-----------|
| `double run(double x)` | Calcula f(x) |
| `double derive(double x)` | Calcula f'(x) |

---

#### `FuncSigmoid`
> `neuralnet/functions/FuncSigmoid.h` | `.cpp`

| Método | Fórmula |
|--------|---------|
| `run(x)` | `1 / (1 + e^(-x))` |
| `derive(x)` | `f(x) · (1 - f(x))` |

---

#### `FuncTanH`
> `neuralnet/functions/FuncTanH.h` | `.cpp`

| Método | Fórmula |
|--------|---------|
| `run(x)` | `(2 / (1 + e^(-2x))) - 1` |
| `derive(x)` | `1 - f(x)²` |

---

#### `FuncRectifier` (ReLU)
> `neuralnet/functions/FuncRectifier.h` | `.cpp`

| Método | Fórmula |
|--------|---------|
| `run(x)` | `max(0, x)` |
| `derive(x)` | `0 se x < 0, senão 1` |

---

### `INeuralNetwork<T>` *(interface template)*
> `neuralnet/INeuralNetwork.h`

Interface genérica parametrizada pelo tipo de camada `T`.

| Método | Descrição |
|--------|-----------|
| `T* getLayer(int i)` | Retorna camada de índice `i` |
| `void configure(vector<int>, bool)` | Configura rede com neurônios por camada |
| `void setActivationFunction(IActivationFunction*)` | Define função de ativação global |
| `IActivationFunction* getActivationFunction()` | Retorna função de ativação |
| `double getSumSquaredError()` | SSE atual |
| `double getMeanSquaredError()` | MSE atual |
| *(protected)* `bool checkNetworkConstraints()` | Valida restrições estruturais |
| *(protected)* `void addLayer(T*)` | Adiciona camada |
| *(protected)* `void setNeurons(T*, int)` | Popula camada com neurônios |
| *(protected)* `void setEdges(bool)` | Cria arestas entre camadas |
| *(protected)* `void setSumSquaredError()` | ⚠️ Não implementado |
| *(protected)* `void setMeanSquaredError()` | ⚠️ Não implementado |

---

#### `MultiLayerPerceptron`
> `neuralnet/MultiLayerPerceptron.h` | `.cpp`

Implementação concreta do MLP. Armazena camadas em `map<int, Layer*>` ordenado.

| Método | Status | Descrição |
|--------|--------|-----------|
| `MultiLayerPerceptron()` | ✅ | Construtor padrão |
| `MultiLayerPerceptron(IActivationFunction*)` | ✅ | Construtor com função de ativação |
| `void configure(vector<int>, bool=true)` | ✅ | Monta a rede: cria camadas, neurônios e arestas |
| `Layer* getLayer(int i)` | ✅ | Retorna camada `i` (índice 0-based) |
| `int countLayers()` | ✅ | Número de camadas |
| `bool checkNetworkConstraints()` | ✅ | Verifica se tem camada de entrada e saída |
| `void setActivationFunction(IActivationFunction*)` | ✅ | Define `f` |
| `IActivationFunction* getActivationFunction()` | ✅ | Retorna `f` |
| `double getMeanSquaredError()` | ✅ | Getter do MSE |
| `double getSumSquaredError()` | ✅ | Getter do SSE |
| *(protected)* `void addLayer(Layer*)` | ✅ | Valida ordem e insere no mapa |
| *(protected)* `void setNeurons(Layer*, int)` | ✅ | Cria `BiasNeuron` + `n` `Neuron`s na camada |
| *(protected)* `void setEdges(bool)` | ✅ | Liga todos neurônios de camada `l-1` a todos de camada `l` |
| *(protected)* `void setMeanSquaredError()` | ⚠️ **Vazio** | Deve calcular MSE a partir dos erros dos neurônios de saída |
| *(protected)* `void setSumSquaredError()` | ⚠️ **Vazio** | Deve somar erros quadráticos dos neurônios de saída |

> **Estrutura interna:** `configure({2,3,1})` cria 3 camadas. Camada 0 tem 1 bias + 2 neurônios, camada 1 tem 1 bias + 3 neurônios, camada 2 tem 1 neurônio (sem bias na saída).

---

### `neuralnet/algorithms/` — Algoritmos de Aprendizado

#### `ILearningAlgorithm<T>` *(interface template)*
> `neuralnet/algorithms/ILearningAlgorithm.h`

| Método | Descrição |
|--------|-----------|
| `void setIterations(int)` | Define número de épocas |
| `int getIterations()` | Retorna número de épocas |
| `void setLearningRate(double)` | Define taxa de aprendizado η |
| `double getLearningRate()` | Retorna η |
| `void run()` | Executa o treinamento |
| `void setNetwork(T*)` | Define a rede alvo |
| `T* getNetwork()` | Retorna a rede |
| *(protected)* `void learn()` | Uma época de aprendizado |

---

#### `BackPropagationLearning`
> `neuralnet/algorithms/BackPropagationLearning.h` | `.cpp`

Implementa `ILearningAlgorithm<MultiLayerPerceptron>`.

| Membro | Tipo | Descrição |
|--------|------|-----------|
| `network` | `MultiLayerPerceptron*` | Rede alvo |
| `iterations` | `int` | Número de épocas |
| `learningRate` | `double` | Taxa η |
| `squaredError` | `double` | Erro quadrático acumulado |
| `meanSquaredError` | `double` | MSE calculado |

| Método | Status | Descrição |
|--------|--------|-----------|
| `void setIterations(int)` | ✅ | Setter |
| `int getIterations()` | ✅ | Getter |
| `void setLearningRate(double)` | ✅ | Setter |
| `double getLearningRate()` | ✅ | Getter |
| `void setNetwork(MultiLayerPerceptron*)` | ✅ | Setter |
| `MultiLayerPerceptron* getNetwork()` | ✅ | Getter |
| `void run()` | ⚠️ **Vazio** | Loop principal: executa `learn()` por `iterations` vezes |
| `void learn()` | ⚠️ **Vazio** | Uma época: apresenta amostra, propaga, retropropaga |
| `void propagate()` | ⚠️ **Vazio** | Forward pass: avalia neurônios camada a camada |
| `void backpropagate()` | ⚠️ **Vazio** | Backward pass: calcula δ e atualiza pesos |
| `double computeSquaredError(Neuron&)` | ⚠️ **Vazio** | Erro quadrático de um neurônio |
| `double computeMeanSquaredError()` | ⚠️ **Vazio** | MSE sobre neurônios de saída |

---

### `problem/` — Estruturas Auxiliares

#### `IMatrix` *(interface)*
> `problem/IMatrix.h`

| Método | Descrição |
|--------|-----------|
| `double getCell(int x, int y)` | Lê célula da matriz |
| `void setCell(int x, int y, double)` | Escreve célula |
| `void load()` | Carrega dados |

---

#### `WeightMatrix`
> `problem/WeightMatrix.h` | `.cpp`

Matriz de pesos 2D. **Todos os métodos estão vazios.**

| Método | Status | Descrição |
|--------|--------|-----------|
| `WeightMatrix(int x, int y)` | ⚠️ Parcial | Chama `define()` mas alocação está comentada |
| `double getCell(int x, int y)` | ⚠️ **Vazio** | Deveria retornar `matrix[x][y]` |
| `void setCell(int x, int y, double)` | ⚠️ **Vazio** | Deveria escrever em `matrix[x][y]` |
| `void load()` | ⚠️ **Vazio** | Sem implementação |
| *(private)* `void define(int x, int y)` | ⚠️ Parcial | Salva dimensões; alocação de `matrix` comentada |

> `WeightMatrix` não é usada pelo algoritmo backpropagation atualmente.

---

## O que está faltando para concluir o Backpropagation

### Passo 1 — Definir estrutura de dados de treinamento

O algoritmo atualmente não tem como receber os dados de treino. É necessário:

- Criar uma estrutura para amostras de entrada/saída (ex.: `vector<pair<vector<double>, vector<double>>>`)
- Adicionar `setTrainingData(...)` em `BackPropagationLearning`
- Ou, alternativamente, implementar `WeightMatrix` para transportar os dados

---

### Passo 2 — Implementar `propagate()`
> `BackPropagationLearning.cpp`, linha 55

Forward pass: percorre as camadas da entrada para a saída, chamando `eval(time)` em cada neurônio.

```
para cada camada l de 0 até L:
    para cada neurônio n na camada l:
        n.eval(time)   // já implementado em AbstractNeuron
```

`time` deve ser incrementado a cada apresentação de amostra para invalidar o cache.

---

### Passo 3 — Implementar `computeSquaredError(Neuron &n)`
> `BackPropagationLearning.cpp`, linha 67

```
erro(n) = (target(n) - output(n))²
```

Requer acesso ao valor alvo (`target`) da amostra atual.

---

### Passo 4 — Implementar `computeMeanSquaredError()`
> `BackPropagationLearning.cpp`, linha 63

```
MSE = (1/|saída|) × Σ computeSquaredError(nᵢ)
      para cada neurônio nᵢ na camada de saída
```

---

### Passo 5 — Implementar `backpropagate()`
> `BackPropagationLearning.cpp`, linha 59

**5a. Calcular δ para neurônios de saída:**
```
erro(j)  = target(j) - output(j)
delta(j) = erro(j) × f'(net(j))
```

**5b. Propagar δ para camadas ocultas (de trás para frente):**
```
para cada camada l de L-1 até 1:
    para cada neurônio j na camada l:
        erro(j) = Σ [ delta(k) × w(k←j) ]
                  para cada neurônio k da camada l+1 que j conecta
        delta(j) = erro(j) × f'(net(j))
```

**5c. Atualizar pesos:**
```
para cada neurônio j (de qualquer camada com arestas):
    para cada aresta e entrando em j (e conecta i → j):
        e.weight += learningRate × delta(j) × output(i)
```

> `output(i)` = `e.getVertex1().getValue()`
> `delta(j)` = `j.getDelta()`
> `f'(net(j))` = `j.getFunction().derive(net(j))`

---

### Passo 6 — Implementar `learn()`
> `BackPropagationLearning.cpp`, linha 51

```
para cada amostra (entrada, target) no dataset:
    1. Atribuir valores de entrada aos neurônios da camada 0
    2. propagate()
    3. backpropagate()
    4. Acumular erro com computeSquaredError()
```

---

### Passo 7 — Implementar `run()`
> `BackPropagationLearning.cpp`, linha 47

```
para t de 1 até iterations:
    learn()
    computeMeanSquaredError()
    (opcional) imprimir MSE
```

---

### Passo 8 — Implementar `setMeanSquaredError()` e `setSumSquaredError()` no MLP
> `MultiLayerPerceptron.cpp`, linhas 183 e 190

Esses métodos devem ser chamados por `BackPropagationLearning` após cada época para atualizar os campos `meanSquaredError` e `sumSquaredError` da rede.

---

### Passo 9 *(Opcional)* — Implementar `WeightMatrix`
> `problem/WeightMatrix.cpp`

Necessário se quiser exportar/importar pesos treinados. Não é bloqueador para o backpropagation funcionar.

---

## Dependências de Implementação

```
run()
 └── learn()
      ├── [atribuir entradas]
      ├── propagate()          → usa AbstractNeuron::eval() ✅
      ├── backpropagate()
      │    ├── computeSquaredError()
      │    ├── [calcula delta de saída]
      │    ├── [propaga delta para ocultas]
      │    └── [atualiza Edge::weight]
      └── computeMeanSquaredError()
           └── computeSquaredError()
```

---

## Exemplo de Uso Esperado (XOR)

```cpp
FuncSigmoid fs;
MultiLayerPerceptron mlp{&fs};
mlp.configure({2, 3, 1});   // 2 entradas, 3 ocultos, 1 saída

BackPropagationLearning bp;
bp.setNetwork(&mlp);
bp.setLearningRate(0.5);
bp.setIterations(10000);
// bp.setTrainingData(...)   <-- a ser implementado

bp.run();
```

---

## Status Geral

| Componente | Status |
|------------|--------|
| `ObjectID`, `IdGenerator` | ✅ Completo |
| `Edge` | ✅ Completo |
| `AbstractNeuron`, `Neuron`, `BiasNeuron` | ✅ Completo |
| `FuncSigmoid`, `FuncTanH`, `FuncRectifier` | ✅ Completo |
| `Layer` | ✅ Completo |
| `MultiLayerPerceptron` (estrutura e configuração) | ✅ Completo |
| `MultiLayerPerceptron::setMeanSquaredError/SSE` | ⚠️ Vazio |
| `BackPropagationLearning` (getters/setters) | ✅ Completo |
| `BackPropagationLearning::run/learn/propagate/backpropagate` | ❌ Não implementado |
| `BackPropagationLearning::computeSquaredError/MSE` | ❌ Não implementado |
| `WeightMatrix` | ❌ Não implementado |
| Estrutura de dados de treino | ❌ Ausente |
