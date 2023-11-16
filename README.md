ACAI-LIB - AC Artificial Intelligence Library
=============================================

Esse é o repositório da ACAI-LIB, uma biblioteca modular para aprendizado de máquina para C++11.
Seu objetivo é oferecer algoritmos flexíveis e de uso fácil para tarefas de aprendizagem de máquina em uma variedade de ambientes pre-definidos.

A ACAI-LIB ainda está em desenvolvimento e deverá conter algoritmos para redes neurais (Multi Layer Perceptron - MLP, Self-Organizing Map - SOM, GrowingSOM - GSOM, entre outros), Redes Bayesianas, Modelos Ocultos de Markov, Grafos-fator e outros modelos gráficos bem como seus algoritmos de inferência.


Requisitos
------------

A biblioteca é escrita na linguagem C++11 e os testes unitários realizados com a biblioteca CPPUNIT.

Instalação
------------

Faça o checkout desse repositório no seu computador:

    git clone https://github.com/phdabel/acailib.git

O projeto tem a seguinte estrutura de pastas:

- core -> classes básicas para o funcionamento da biblioteca e desenvolvimento de novos módulos;
- neuralnet -> classes para modelos e algoritmos de redes neurais;
- tests -> testes unitários;
- utils -> classes utilitárias;
- project-uml -> arquivo do projeto no ASTAH (diagramas de classes e outras ferramentas do UML).


Como colaborar
===============

Você quer contribuir para o projeto ACAI-LIB? Ótimo! Mas para aumentar as chances de suas mudanças serem aceitas rapidamente, siga os seguintes passos.

Prepare seu ambiente de desenvolvimento
----------------------------------------

Os seguintes passos criarão um ambiente de desenvolvimento que você utilizará para trabalhar.
Esses passos deverão ser feitos a primeira vez que você contribuir.

### 1. [Fork](http://help.github.com/fork-a-repo/) o repositório do ACAI-LIB no GitLAB e clone seu fork to seu ambiente de desenvolvimento.


Se tiver problemas para configurar o Git com o GitLAB no Linux, ou está recebendo erros como "Permission Denied (publickey)", então você deve
[configurar sua instalação do Git para trabalhar com o GitLAB](http://help.github.com/linux-set-up-git/)

> Dica: se você não é fluente com GIT, recomenda-se a leitura do excelente livro gratuito [Pro Git](https://git-scm.com/book/en/v2). Também há livros de GIT disponíveis na pasta de livros do CPD.

### Unit tests

É possível executar os testes unitários diretamente no NetBeans pressionando ALT+F6, porém é necessário ter o pacote CPPUNIT instalado.
Sugere-se que cada módulo novo que for desenvolvido tenha um teste unitário para que sejam verificadas as funcionalidades como métodos e cálculos que o algoritmo deverá fazer.

Por exemplo, a rede neural Multi Layer Perceptron possui testes da montagem da rede, propagação dos valores de entrada até a saída da rede e retro-propagação do erro.
Dessa forma pode-se verificar que a rede está funcionando conforme o esperado.


Modelagem
----------

![alt tag](https://github.com/phdabel/acailib/raw/main/project-uml/ACAI-LIB.png)
