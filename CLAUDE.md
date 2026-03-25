# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build

```bash
make          # compila → ./acailib
make clean    # remove objetos e binário
./acailib     # executa com dados de data/xor.dat
```

Padrão: C++11 com `-Wall -g`. Os testes unitários (CppUnit) têm runners próprios em `tests/neuralnet/` e são compilados separadamente — o `Makefile` raiz não os inclui.

## Arquitetura

Veja `ARCHITECTURE.md` para referência completa de classes e métodos. O resumo abaixo cobre os padrões não óbvios.

### WeightMatrix como estrutura de pesos

Os pesos não ficam mais nas arestas (`Edge`). Cada `Layer` (exceto a de entrada) possui uma `WeightMatrix W` onde `W[j][i]` é o peso do i-ésimo neurônio da camada anterior para o j-ésimo neurônio não-bias da camada atual. A coluna `i` percorre **todos** os neurônios da camada anterior, incluindo o bias.

### Forward pass via `Layer::forward()`

O forward pass é feito camada a camada por `Layer::forward(prev)`: `net_j = Σ_i W[j][i] · x_i`, depois `out_j = f(net_j)`. O neurônio recebe `net` via `setNet()` e `out` via `setValue()`. Não há mais recursão por arestas.

### `derive(x)` recebe net input, não output ativado

Todas as implementações de `IActivationFunction::derive(x)` esperam o valor **antes** da ativação (net input). `AbstractNeuron` armazena esse valor no campo `net`, atualizado por `Layer::forward()`. Use `getNet()` para acessá-lo no backprop.

### Hierarquia de neurônios

- `BiasNeuron`: `getValue()` sempre retorna `1.0`
- `Neuron`: neurônio comum com campo `index` (rótulo string, ex.: `"1"`, `"2"`)
- Ambos herdam `AbstractNeuron`, que contém `net`, `delta`, `error` e a função de ativação

### `Layer::getNeurons()` aloca a cada chamada

O método cria um novo `vector<AbstractNeuron*>` copiando do `map` interno toda vez que é chamado. Em loops internos do algoritmo de aprendizado, prefira capturar o resultado uma vez em variável local.

### Inicialização de pesos

Os pesos são inicializados aleatoriamente via `WeightMatrix::randomize()`, que usa `ObjectID::random()` (range [-1, 1]). Para pesos fixos, passar `randomWeight=false` em `configure()`.
