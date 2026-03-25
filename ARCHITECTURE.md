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
├── problem/                 # WeightMatrix (matriz de pesos por camada)
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
      │    ├── AbstractNeuron  (1..*)
      │    └── WeightMatrix    (1, exceto camada de entrada)
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

Implementa `IAbstractLayer`. Armazena neurônios num `map<ObjectID*, AbstractNeuron*>` ordenado por ID. Cada camada (exceto a de entrada) possui uma `WeightMatrix` que centraliza todos os pesos de conexão com a camada anterior.

| Método | Descrição |
|--------|-----------|
| `Layer()` / `Layer(LayerType)` | Construtores |
| `LayerType getType()` | Retorna `INPUT`, `HIDDEN` ou `OUTPUT` |
| `void setType(LayerType)` | Define o tipo |
| `void addNeuron(AbstractNeuron*)` | Insere neurônio no mapa |
| `vector<AbstractNeuron*> getNeurons()` | Todos os neurônios em ordem de ID |
| `AbstractNeuron& getNeuron(int i)` | Neurônio pelo índice ordinal |
| `void initWeights(int prevNeuronCount, bool random)` | Cria a `WeightMatrix` desta camada: `rows` = neurônios não-bias desta camada, `cols` = todos os neurônios da camada anterior (incluindo bias). Se `random=true`, chama `randomize()`. |
| `void forward(Layer* prev)` | Forward pass: para cada neurônio não-bias `nj` (índice `j`), calcula `net_j = Σ_i W[j][i] * x_i`, depois `out_j = f(net_j)`. Chama `setNet()` e `setValue()` no neurônio. |
| `WeightMatrix* getWeights()` | Retorna ponteiro para a `WeightMatrix` desta camada |

> **Convenção de índices:** `W[j][i]` — linha `j` indexa o j-ésimo neurônio não-bias da camada atual; coluna `i` indexa o i-ésimo neurônio (incluindo bias) da camada anterior.

---

### `neuralnet/neuron/` — Hierarquia de Neurônios

#### `AbstractNeuron`
> `neuralnet/neuron/AbstractNeuron.h` | `.cpp`

Classe base abstrata para neurônios. Implementa `IUnit`. Na arquitetura baseada em `WeightMatrix`, o neurônio não armazena mais arestas nem calcula seu próprio net input — esse cálculo é delegado a `Layer::forward()`. O neurônio expõe `net` e `value` para que o algoritmo de aprendizado acesse os valores intermediários.

| Membro | Tipo | Descrição |
|--------|------|-----------|
| `delta` | `double` | Gradiente local δ (usado no backprop) |
| `error` | `double` | Erro do neurônio (usado no backprop) |
| `net` | `double` | Net input antes da ativação (definido por `Layer::forward()`) |

| Método | Descrição |
|--------|-----------|
| `double eval(int time=0)` | Retorna `getValue()` (usado na camada de entrada; nas demais camadas, `forward()` é quem atualiza o valor) |
| `void setFunction(IActivationFunction&)` | Define função de ativação |
| `IActivationFunction& getFunction()` | Retorna função de ativação |
| `double getDelta()` / `setDelta(double)` | Getter/setter de δ |
| `double getError()` / `setError(double)` | Getter/setter de erro |
| `double getNet()` / `setNet(double)` | Getter/setter do net input (pré-ativação) |
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
| *(protected)* `void initWeights(bool)` | Inicializa a `WeightMatrix` de cada camada (exceto a de entrada) |
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
| `void configure(vector<int>, bool=true)` | ✅ | Monta a rede: cria camadas, neurônios e inicializa as `WeightMatrix` |
| `Layer* getLayer(int i)` | ✅ | Retorna camada `i` (índice 0-based) |
| `int countLayers()` | ✅ | Número de camadas |
| `bool checkNetworkConstraints()` | ✅ | Verifica se tem camada de entrada e saída |
| `void setActivationFunction(IActivationFunction*)` | ✅ | Define `f` |
| `IActivationFunction* getActivationFunction()` | ✅ | Retorna `f` |
| `double getMeanSquaredError()` | ✅ | Getter do MSE |
| `double getSumSquaredError()` | ✅ | Getter do SSE |
| *(protected)* `void addLayer(Layer*)` | ✅ | Valida ordem e insere no mapa |
| *(protected)* `void setNeurons(Layer*, int)` | ✅ | Cria `BiasNeuron` + `n` `Neuron`s na camada |
| *(protected)* `void initWeights(bool)` | ✅ | Para cada camada `l` ≥ 1, chama `layer->initWeights(prevCount, random)` onde `prevCount` = tamanho total da camada `l-1` (incluindo bias) |
| *(protected)* `void setMeanSquaredError()` | ⚠️ **Vazio** | Deve calcular MSE a partir dos erros dos neurônios de saída |
| *(protected)* `void setSumSquaredError()` | ⚠️ **Vazio** | Deve somar erros quadráticos dos neurônios de saída |

> **Estrutura interna:** `configure({2,3,1})` cria 3 camadas. Camada 0 tem 1 bias + 2 neurônios, camada 1 tem 1 bias + 3 neurônios, camada 2 tem 1 neurônio (sem bias na saída). As arestas entre neurônios não existem mais; os pesos ficam em `WeightMatrix`: camada 1 tem matriz 3×3 (3 não-bias × 3 neurônios de entrada incluindo bias), camada 2 tem matriz 1×4 (1 saída × 4 neurônios ocultos incluindo bias).

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
| `inputData` | `vector<vector<double>>` | Amostras de entrada do conjunto de treino |
| `targetData` | `vector<vector<double>>` | Alvos correspondentes do conjunto de treino |
| `currentInputs` | `vector<double>` | Entrada da amostra atual |
| `currentTargets` | `vector<double>` | Alvo da amostra atual |

| Método | Status | Descrição |
|--------|--------|-----------|
| `void setIterations(int)` | ✅ | Setter |
| `int getIterations()` | ✅ | Getter |
| `void setLearningRate(double)` | ✅ | Setter |
| `double getLearningRate()` | ✅ | Getter |
| `void setNetwork(MultiLayerPerceptron*)` | ✅ | Setter |
| `MultiLayerPerceptron* getNetwork()` | ✅ | Getter |
| `void setTrainingData(vector<vector<double>>&, vector<vector<double>>&)` | ✅ | Define os dados de treino |
| `void run()` | ✅ | Loop principal: chama `learn()` por `iterations` vezes |
| `void learn()` | ✅ | Uma época: para cada amostra, chama `propagate()` e `backpropagate()` |
| `void propagate()` | ✅ | Atribui entradas à camada 0; executa `Layer::forward()` de l=1 até L-1 |
| `void backpropagate()` | ✅ | Calcula δ de saída, propaga δ pelas camadas ocultas via `W^T · δ`, atualiza `W` com `η · δ_j · x_i` |
| `double computeSquaredError(Neuron&)` | ✅ | `0.5 × (target - output)²` |
| `double computeMeanSquaredError()` | ✅ | Média de `(target - output)²` sobre os neurônios de saída |

**Fluxo do `backpropagate()`:**
1. **Saída:** `δ_j = (target_j - out_j) × f'(net_j)`
2. **Ocultas** (de trás para frente): `δ_i = f'(net_i) × Σ_j W[l+1][j][i] · δ_j`
3. **Atualização:** `W[l][j][i] += η × δ_j × out_i` (para todo `l` de 1 até L-1)

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

Matriz de pesos 2D usada por `Layer` para armazenar todos os pesos de conexão com a camada anterior. Substitui a abordagem anterior de peso por aresta (`Edge::weight`).

| Método | Status | Descrição |
|--------|--------|-----------|
| `WeightMatrix(int rows, int cols)` | ✅ | Aloca `matrix` como `vector<vector<double>>(rows, cols)` inicializada com zeros |
| `double getCell(int row, int col)` | ✅ | Retorna `matrix[row][col]` |
| `void setCell(int row, int col, double)` | ✅ | Escreve `matrix[row][col]` |
| `void randomize()` | ✅ | Preenche toda a matriz com valores aleatórios via `ObjectID::random()` (range [-1, 1]) |
| `int getRows()` | ✅ | Número de linhas |
| `int getCols()` | ✅ | Número de colunas |
| `void load()` | ⚠️ Vazio | Sem implementação |
| *(private)* `void define(int rows, int cols)` | ✅ | Salva dimensões e aloca a matriz |

> **Convenção:** linha = neurônio não-bias da camada atual (índice `j`); coluna = neurônio (incluindo bias) da camada anterior (índice `i`).

---

## Fluxo de Execução

```
run()
 └── learn()                         ← por cada amostra do dataset
      ├── [atribuir entradas à camada 0]
      ├── propagate()
      │    └── Layer::forward(prev)  ← l = 1..L-1
      │         └── W[j][i] * x_i → net_j → f(net_j)
      └── backpropagate()
           ├── [delta de saída]      ← (target - out) * f'(net)
           ├── [delta ocultas]       ← W^T · δ_{l+1} * f'(net)
           └── [atualiza W]          ← W[j][i] += η * δ_j * x_i
```

## O que ainda está pendente

| Item | Status |
|------|--------|
| `setMeanSquaredError()` / `setSumSquaredError()` no MLP | ⚠️ Vazios (não bloqueiam o treino) |
| `WeightMatrix::load()` | ⚠️ Vazio (para importar pesos salvos) |

---

## Exemplo de Uso Esperado (XOR)

```cpp
FuncSigmoid fs;
MultiLayerPerceptron mlp{&fs};
mlp.configure({2, 3, 1});   // 2 entradas, 3 ocultos, 1 saída

vector<vector<double>> inputs  = {{0,0},{0,1},{1,0},{1,1}};
vector<vector<double>> targets = {{0},  {1},  {1},  {0}};

BackPropagationLearning bp;
bp.setNetwork(&mlp);
bp.setLearningRate(0.5);
bp.setIterations(10000);
bp.setTrainingData(inputs, targets);

bp.run();
```

---

## Status Geral

| Componente | Status |
|------------|--------|
| `ObjectID`, `IdGenerator` | ✅ Completo |
| `Edge` | ✅ Completo (estrutura mantida; não usada no forward/backprop) |
| `AbstractNeuron`, `Neuron`, `BiasNeuron` | ✅ Completo |
| `FuncSigmoid`, `FuncTanH`, `FuncRectifier` | ✅ Completo |
| `Layer` (incluindo `forward`, `initWeights`, `getWeights`) | ✅ Completo |
| `WeightMatrix` (incluindo `randomize`, `getCell`, `setCell`) | ✅ Completo |
| `MultiLayerPerceptron` (estrutura, configuração e `initWeights`) | ✅ Completo |
| `MultiLayerPerceptron::setMeanSquaredError/SSE` | ⚠️ Vazio |
| `BackPropagationLearning` (todos os métodos) | ✅ Completo |
| `WeightMatrix::load()` | ⚠️ Vazio |
