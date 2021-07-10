// Leandro Hideki Aihara
// Thiago Martendal Salvador
// Pablo Daniel Riveros Strapasson

#ifndef ENTRADA_H
#define ENTRADA_H

#include <string>
#include <fstream>
#include <FlexLexer.h>
#include "analise_lexica.h"

extern "C" int coluna();

class Entrada {
private:
  AnaliseLexica al; // Classe de análise léxica
  bool houveErro(); // Checa se houve um erro léxico

public:
  Entrada() = default;
  bool lerArquivo(std::string nome); // Lê arquivo
  void lerEntrada(); // Lê linha do console
  void exibirTokens(); // Exibe os tokens processados
  void exibirTabelaSimbolos(); // Exibe a tabela de símbolos
};

#endif
