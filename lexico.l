%{
  #include "identificador.h"
  extern "C" {
    int yylex(void);
  }
%}

%option noyywrap
%option yylineno

%%
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
[a-zA-Z][a-zA-Z0-9]* {return Identificador::ID;}
[[:digit:]]+ {return Identificador::ICT;}
[[:digit:]]*\.[[:digit:]]* {return Identificador::FCT;}
\"(([^\"]|\\\")*[^\\])?\" {return Identificador::SCT;}
[ \n\t] {;}
[.[:digit:]]+ {return Identificador::ERR;}
. {return Identificador::ERR;}
%%

int yywrap() {
  return 1;
}
