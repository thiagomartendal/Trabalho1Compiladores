instalar-flex:
    sudo apt-get install flex

compilar:
	flex -+ lexico.l
	g++ main.cpp entrada.cpp analise_lexica.cpp lex.yy.cc -lfl -o Main
