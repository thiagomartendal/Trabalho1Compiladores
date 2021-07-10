%{
  #include "identificador.h"

  int yycolumn = 1;
  int start_line = 1, start_column = 1;

  #define YY_USER_ACTION                                                   \
    start_line = prev_yylineno; start_column = yycolumn;                   \
    if (yylineno == prev_yylineno) yycolumn += yyleng;                     \
    else {                                                                 \
      for (yycolumn = 1; yytext[yyleng - yycolumn] != '\n'; ++yycolumn) {} \
      prev_yylineno = yylineno;                                            \
    }

  extern "C" {
    int yylex(void);
    int coluna(void);
  }
%}

%option noyywrap
%option yylineno

%%
  int prev_yylineno = yylineno;
"new" {return Identificador::NEW;}
"def" {return Identificador::DF;}
"read" {return Identificador::RD;}
"print" {return Identificador::PR;}
"null" {return Identificador::NL;}
"int" {return Identificador::INT;}
"float" {return Identificador::FLT;}
"string" {return Identificador::STR;}
"if" {return Identificador::IF;}
"else" {return Identificador::ELS;}
"for" {return Identificador::FOR;}
"break" {return Identificador::BRK;}
"return" {return Identificador::RET;}
"+" {return Identificador::ADD;}
"-" {return Identificador::SUB;}
"*" {return Identificador::MUL;}
"/" {return Identificador::DIV;}
"%" {return Identificador::PRC;}
"=" {return Identificador::ATR;}
">" {return Identificador::MAR;}
"<" {return Identificador::MER;}
"==" {return Identificador::CMP;}
">=" {return Identificador::MAI;}
"<=" {return Identificador::MEI;}
"!=" {return Identificador::DIF;}
"(" {return Identificador::P1;}
")" {return Identificador::P2;}
"{" {return Identificador::CV1;}
"}" {return Identificador::CV2;}
"[" {return Identificador::CL1;}
"]" {return Identificador::CL2;}
"," {return Identificador::VI;}
";" {return Identificador::PV;}
[a-zA-Z_][a-zA-Z0-9_]* {return Identificador::ID;}
[[:digit:]]+ {return Identificador::ICT;}
[[:digit:]]+\.[[:digit:]]+ {return Identificador::FCT;}
\"(([^\"]|\\\")*[^\\])?\" {return Identificador::SCT;}
[ \n\t] {;}
. {return Identificador::ERR;}
%%

int yywrap() {
  return 1;
}

int coluna() {
  return start_column;
}
