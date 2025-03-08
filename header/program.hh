#ifndef __PROGRAM_HH__
#define __PROGRAM_HH__

#include "lexical.hh"
#include "syntax.hh"

class Program {
    private:
        std::string pascal_code, c_code;
        std::vector<Token> tokens;
        AST* tree_root;
        Lexical lexicalAnalyzer;
        Syntax syntaxAnalyzer;
    public:
        Program() { tree_root = nullptr; }
        void run();
};

#endif