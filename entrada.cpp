#include "entrada.h"

bool Entrada::lerArquivo(char *nome) {
  std::fstream arquivo; // Classe para ler arquivo
  arquivo.open(nome, std::ios_base::in); // Abre o arquivo
  if (arquivo.fail()) { // Verifica se houve erro na abertura
    return false;
  }
  yyFlexLexer *scanner = new yyFlexLexer(&arquivo); // Classe de leitura do flex, que lê do arquivo
  int ntoken = scanner->yylex(); // Processa cada palavra lida atribuindo um valor inteiro
  while(ntoken != 0) { // O loop é executado enquanto houver palavras a serem lidas
    al.tokenizar(ntoken, scanner->YYText(), scanner->lineno()); // Passa dados do arquivo para a classe de análise léxica realizar a tokenização
    ntoken = scanner->yylex(); // Lê próxima linha do arquivo, caso esta exista
  }
  return true;
}

void Entrada::lerEntrada() {
  yyFlexLexer *scanner = new yyFlexLexer; // Classe de leitura do flex, que lê da entrada do console
  int ntoken = scanner->yylex(); // Processa cada palavra lida atribuindo um valor inteiro
  while(ntoken != 0) { // O loop é executado enquanto houver palavras a serem lidas
    al.tokenizar(ntoken, scanner->YYText(), scanner->lineno()); // Passa dados da linha do console para a classe de análise léxica realizar a tokenização
    Entrada::exibirTokens(); // Para cada linha processada, é exibido os tokens que foram encontrados
    al.limpaTabela(); // Limpa a tabela de simbolos para não exibir tokens repetidos
    ntoken = scanner->yylex(); // Lê mais uma linha de entrada do console
  }
}

void Entrada::exibirTokens() {
  for (Token tk: al.getTabelaSimbolos()) { // Para cada token na tabela de símbolos, é exibido seus dados
    std::cout << "Id: " << tk.id << " - Lexema: " << tk.lexema << " - Linha: " << tk.linha << " - Descrição: " << tk.descricao << std::endl;
  }
}
