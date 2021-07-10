# Trabalho 1 - Análise Léxica

## Autores

Leandro Hideki Aihara

Thiago Martendal Salvador

Pablo Daniel Riveros Strapasson

## Sobre os programas escritos em LCC

Os programas de exemplos escritos a na linguagem LCC a serem testados estão na pasta programas.

### programa-lcc-1.lcc

Se trata de um programa que calcula funções matemáticas simples, e realisa a interação destas através de outras funções auxiliares.

### programa-lcc-2.lcc

O programa 2 trás a implementação do método numérico de Birge Vieta, para calcular raizes para um polinômio.

### programa-lcc-3.lcc

No programa 3, é implementado um algoritmo que aplica algumas operações em conjuntos.

## Compilação:

flex -+ lexico.l

g++ main.cpp entrada.cpp analise_lexica.cpp lex.yy.cc -lfl -o Main

## Execução:

./Main LCC-2021-1-20210627/exemplo1.lcc

## Compilação e Execução com makefile:

Esta seção trata o processo de compilação e execução automáticas com comandos do makefiel.

Compilação do projeot:

make compilar

Execução do programa 1:

make programa1

Execução do programa 2:

make programa2

Execução do programa 3:

make programa3
