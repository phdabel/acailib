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

## Como Contribuir

Estamos entusiasmados com sua contribuição ao *ACAI-LIB*! Aqui estão algumas diretrizes para ajudá-lo a começar:

### 1. Relatar Bugs e Sugerir Melhorias

Se você encontrar um bug ou tiver uma ideia para uma melhoria, por favor, abra uma issue no GitHub. Inclua o máximo de detalhes possível, como:

- Descrição do bug ou da melhoria.
- Passos para reproduzir o bug.
- Sugestões para possíveis soluções.

### 2. Enviar Pull Requests

Se você deseja adicionar uma nova funcionalidade ou corrigir um bug, siga estes passos:

1. Faça um fork do repositório.
2. Crie uma branch para suas mudanças (`git checkout -b feature/minha-nova-feature`).
3. Faça suas alterações e adicione testes se aplicável.
4. Commit suas mudanças (`git commit -am 'Adiciona nova feature'`).
5. Push para a branch (`git push origin feature/minha-nova-feature`).
6. Abra um Pull Request no GitHub.

### 3. Melhorar a Documentação

A documentação é tão importante quanto o código. Se você notar algo que pode ser melhorado ou se tem sugestões para novos conteúdos, sinta-se livre para contribuir.

### 4. Contribuir com Testes

Testes robustos são essenciais para garantir a estabilidade e a qualidade da biblioteca. Contribuições na forma de novos testes ou melhorias nos existentes são sempre bem-vindas.

### 5. Discutir Ideias

Se você tem ideias para novas features ou melhorias, não hesite em compartilhá-las na seção de issues. A discussão aberta é essencial para o desenvolvimento colaborativo.

### 6. Divulgar o Projeto

Ajude a aumentar a visibilidade do projeto compartilhando-o

