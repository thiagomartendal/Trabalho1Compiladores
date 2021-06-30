#ifndef ATRIBUTO_H
#define ATRIBUTO_H

#include <set>

// O atributo é a estrutura de elementos alocada a cada identificador na tabela de símbolos

typedef struct Atributo {
  std::set<int> linhas; // Número das linhas onde ocorre o identificador
} Atributo;

#endif
