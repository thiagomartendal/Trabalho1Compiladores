#ifndef ENTRADA_H
#define ENTRADA_H

#include <fstream>
#include <FlexLexer.h>
#include "analise_lexica.h"

class Entrada {
private:
  AnaliseLexica al; // Classe de análise léxica

public:
  Entrada() = default;
  bool lerArquivo(char *nome); // Lê arquivo
  void lerEntrada(); // Lê linha do console
  void exibirTokens(); // Exibe os tokens processados
  void exibirTabelaSimbolos(); // Exibe a tabela de símbolos
};

#endif
