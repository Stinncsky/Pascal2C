#ifndef __LEXICAL_HH__
#define __LEXICAL_HH__

#include "token.hh"

#include <vector>

class Lexical {
    private:
        std::vector<Token> tokens;
        std::string code;

    public:
        Lexical(std::string input) { this->code = input; }
        auto getTokens() -> std::vector<Token> { return this->tokens; }
        void run();
};

#endif