#ifndef __TOKEN_HH__
#define __TOKEN_HH__

#include <string>

enum class TokenType{
    Identifier, // 标识符
    Number,  // 数字常量
    String,  // 字符串常量
    Char,    // 字符常量
    Keyword, // 关键字
    Operator, // 运算符
    Delimiters, // 分隔符
    Null // 空
};

class Token{
    public:
        TokenType type;
        std::string property; // 词法单元的属性值
        int line, column; // 词法单元在源代码中的位置

        Token(std::string original = "", TokenType type = TokenType::Null, int line = -1, int column = -1){
            this->type = type;
            this->property = original;
            this->line = line;
            this->column = column;
        }

        bool operator==(const Token &t) const{
            return this->property == t.property && this->type == t.type;
        }

        bool operator<(const Token &t) const{
            return this->property < t.property;
        }

        int to_yacc_token() const;
};

#endif