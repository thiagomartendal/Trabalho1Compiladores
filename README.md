# Trabalho1Compiladores

## Authors

[Leandro Hideki Aihara]
[Thiago Martendal Salvador]
[Pablo Daniel Riveros Strapasson]

# Compilação:

flex -+ lexico.l

g++ main.cpp entrada.cpp analise_lexica.cpp lex.yy.cc -lfl -o Main

# Execução:

./Main LCC-2021-1-20210627/exemplo1.lcc

# Compilação e Execução com makefile:

Esta seção trata o processo de compilação e execução automáticas com comandos do makefiel.

Compilação do projeot:

make compilar

Execução do programa 1:

make programa1

Execução do programa 2:

make programa2

Execução do programa 3:

make programa3
