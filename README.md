# ACAI-LIB - AC Artificial Intelligence Library

## Sobre a ACAI-LIB

A *ACAI-LIB* é uma biblioteca modular de aprendizado de máquina para C++11. Seu foco está em oferecer algoritmos flexíveis e de fácil uso para uma variedade de tarefas de aprendizado de máquina, em ambientes pré-definidos. Atualmente em desenvolvimento, a biblioteca planeja incluir:

- Redes Neurais (Multi Layer Perceptron - MLP, Self-Organizing Map - SOM, GrowingSOM - GSOM, etc.)
- Redes Bayesianas
- Modelos Ocultos de Markov
- Grafos-fator e outros modelos gráficos
- Algoritmos de inferência correspondentes

## Requisitos

- **Linguagem:** C++11
- **Testes Unitários:** CPPUNIT

## Instalação

Clone o repositório para sua máquina local:

```bash
git clone https://github.com/phdabel/acailib.git
```

O projeto tem a seguinte estrutura de pastas:

- core -> classes básicas para o funcionamento da biblioteca e desenvolvimento de novos módulos;
- neuralnet -> classes para modelos e algoritmos de redes neurais;
- tests -> testes unitários;
- utils -> classes utilitárias;
- project-uml -> arquivo do projeto no ASTAH (diagramas de classes e outras ferramentas do UML).


### Unit tests

É possível executar os testes unitários diretamente no NetBeans pressionando ALT+F6, porém é necessário ter o pacote CPPUNIT instalado.
Sugere-se que cada módulo novo que for desenvolvido tenha um teste unitário para que sejam verificadas as funcionalidades como métodos e cálculos que o algoritmo deverá fazer.

Por exemplo, a rede neural Multi Layer Perceptron possui testes da montagem da rede, propagação dos valores de entrada até a saída da rede e retro-propagação do erro.
Dessa forma pode-se verificar que a rede está funcionando conforme o esperado.


Modelagem
----------

![alt tag](https://github.com/phdabel/acailib/raw/main/project-uml/ACAI-LIB.png)
