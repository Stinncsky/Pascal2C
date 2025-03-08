#ifndef __LEXICAL_HH__
#define __LEXICAL_HH__

#include "token.hh"

#include <vector>

class Lexical {
    private:
        std::vector<Token> tokens;
        std::string code;

    public:
        void load(std::string input) { this->code = input; }
        auto getTokens() -> std::vector<Token> { return this->tokens; }
        void run();
};

enum class State{
    START,
    IN_WORD,  // 标识符 关键字
    IN_STRING,  // 字符串
    IN_NUM,  // 整形/浮点型数字常量
    IN_COMMENT  // 注释中
};

enum class NumState {
    START, INTEGER, FRACTION_START, FRACTION
};

bool is_keyword(std::string word){ // Pascal-S
    std::vector<std::string> keywords = {
        "and", "array", "begin", "case", "const", "div", "do", "downto", "else", "end", "file", 
        "for", "function", "goto", "if", "in", "label", "mod", "nil", "not", "of", "or", "packed", "procedure", 
        "program", "record", "repeat", "set", "then", "to", "type", "until", "var", "while", "with",
        "integer", "real", "char", "boolean", "string", "true", "false"
    };
    for(auto keyword : keywords){
        if(word == keyword){
            return true;
        }
    }
    return false;
}

#endif