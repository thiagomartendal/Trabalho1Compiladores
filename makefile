instalar-flex:
	sudo apt-get install flex

compilar:
	flex -+ lexico.l
	g++ main.cpp entrada.cpp analise_lexica.cpp lex.yy.cc -lfl -o Main

programa1:
	./Main programas/programa-lcc-1.lcc

programa2:
	./Main programas/programa-lcc-2.lcc

programa3:
	./Main programas/programa-lcc-3.lcc
