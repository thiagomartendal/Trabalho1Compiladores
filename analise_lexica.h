#ifndef ANALISE_LEXICA_H
#define ANALISE_LEXICA_H

#include <string>
#include <vector>
#include "token.h"
#include "identificador.h"

class AnaliseLexica {
private:
  std::vector<Token> tabelaSimbolos; // Tabela de símbolos que armazena os tokens processados

public:
  AnaliseLexica() = default;
  void tokenizar(int ntoken, std::string lexema, int linha); // Recebe os dados de entrada a respeito de um lexema, e os atribui a um token que será adicionado a tabela de símbolos
  void limpaTabela(); // Limpa a tabela de símbolos
  std::vector<Token> getTabelaSimbolos(); // Retorna a tabela de símbolos
};

#endif
