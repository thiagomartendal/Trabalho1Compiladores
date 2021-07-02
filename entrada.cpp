#include "entrada.h"

bool Entrada::houveErro() {
  // A lista é percorrida para encontrar tokens de erro
  for (Token tk: al.getTokens()) {
    if (tk.id == Identificador::ERR) {
      return true;
    }
  }
  return false;
}

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
    // std::cout << scanner->YYLeng() << std::endl;
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
    al.limpaTokens(); // Limpa a lista de tokens para não exibir tokens repetidos
    ntoken = scanner->yylex(); // Lê mais uma linha de entrada do console
  }
}

void Entrada::exibirTokens() {
  std::cout << "Tokens Encontrados:\n" << std::endl;
  for (Token tk: al.getTokens()) { // Para cada token na tabela de símbolos, é exibido seus dados
    std::cout << "Id: " << tk.id << " - Lexema: " << tk.lexema << " - Linha: " << tk.linha << " - Descrição: " << tk.descricao << std::endl;
  }
  if (!Entrada::houveErro()) { // Caso não Haja erros léxicos é exibida a tabela de símbolos
    std::cout << "\nTabela de Símbolos:\n" << std::endl;
    Entrada::exibirTabelaSimbolos();
  }
}

void Entrada::exibirTabelaSimbolos() {
  // Para cada identificador é exibido as linhas onde ocorre
  for (auto const& it: al.getTabelaSimbolos()) {
    Atributo at = it.second;
    std::cout << "Id: " << it.first << " - Linhas: [";
    int i = 0;
    for (int linha: at.linhas) {
      std::cout << linha << "";
      if (i < at.linhas.size()-1) {
        std::cout << ", ";
      }
      i++;
    }
    std::cout << "]" << std::endl;
  }
}
