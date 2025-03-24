#ifndef __SYNTAX_HH__
#define __SYNTAX_HH__

#include "token.hh"
#include "AST.hh"

int yyparse();

class Syntax {
public:
    AST* tree;
};

#endif