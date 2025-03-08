#ifndef __AST_HH__
#define __AST_HH__

#include <vector>
#include "token.hh"

class AST {
    public:
        std::vector<AST *> children;
        Token token;
};

#endif