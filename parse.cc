#include "parsetree.h"
extern FILE *yyin;
extern ParseTree *top;
int yyparse();

ParseTree * parse_decaf(FILE * input_file)
{
  top = nullptr;
  yyin = input_file;
  yyparse();
  return top;
}
