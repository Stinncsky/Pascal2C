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

#endif