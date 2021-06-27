# Trabalho1Compiladores

Compilação:

flex -+ lexico.l

g++ main.cpp entrada.cpp analise_lexica.cpp lex.yy.cc -lfl -o Main

Execução:

./Main LCC-2021-1-20210627/exemplo1.lcc
