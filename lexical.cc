#include "header/lexical.hh"
#include <cctype>

bool is_keyword(std::string word){ // Pascal-S
    std::vector<std::string> keywords = {
        "and", "array", "begin", "case", "const", "div", "do", "downto", "else", "end", "file", "break",
        "for", "function", "goto", "if", "in", "label", "mod", "nil", "not", "of", "or", "packed", "procedure", 
        "program", "record", "repeat", "set", "then", "to", "type", "until", "var", "while", "with",
        "integer", "real", "char", "boolean", "string", "true", "false",
        "read", "write", "writeln", "readln"
    };
    for(auto keyword : keywords){
        if(word == keyword){
            return true;
        }
    }
    return false;
}

static void all_to_lower(std::string &str) {
    for (auto &ch : str) {
        ch = std::tolower(ch); // 转换为小写字母(Pascal-S不区分大小写)
    }
}

void Lexical::run() {
    int line_number = 1;  // 当前行号
    int column_number = 1;  // 当前列号
    State state = State::START;  // 当前状态
    NumState num_state = NumState::START;  // 数字常量状态

    std::string temp_token;
    std::string::size_type i = 0;
    while(i < code.size()){
        char ch = code[i];  // 先不转换为小写字母：字符常量和字符串常量中可能包含大写字母
        
        switch(state){
            case State::START:
                if(ch == '\n'){ 
                    line_number++;
                    column_number = 1;
                    i++;
                }
                else if(ch == '\r'){ // 处理 Windows 风格的换行符
                    line_number++;
                    column_number = 1;
                    i += 2; // 跳过 '\r' 和 '\n'
                }
                else if(ch == ' ' || ch == '\t'){ 
                    column_number++;
                    i++;
                }
                else if(ch == '{'){ // {...} 类型注释
                    while(i < code.size()){
                        ch = std::tolower(code[i]);
                        if(ch == '\n'){ 
                            line_number++; 
                            column_number = 1;
                            i++;
                        } else if(ch == '}'){
                            column_number++;
                            i++;
                            break;
                        } else{
                            column_number++;
                            i++;
                        }
                    }
                }
                else if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == '_'){  // 标识符或关键字
                    state = State::IN_WORD;
                    temp_token += ch;
                    column_number++;
                    i++;
                }
                else if(ch >= '0' && ch <= '9'){
                    state = State::IN_NUM;
                    num_state = NumState::INTEGER;
                    temp_token += ch;
                    column_number++;
                    i++;
                }
                else if(ch == '('){
                    if(i + 1 < code.size() && code[i + 1] == '*'){  // (*...*) 类型注释
                        state = State::IN_COMMENT;
                        i += 2;
                    } else{
                        Token new_token("(", TokenType::Delimiters, line_number, column_number);
                        tokens.push_back(new_token);
                        column_number++;
                        i++;
                    }
                }
                else if(ch == ')'){
                    Token new_token(")", TokenType::Delimiters, line_number, column_number);
                    tokens.push_back(new_token);
                    column_number++;
                    i++;
                }
                else if(ch == '['){
                    Token new_token("[", TokenType::Delimiters, line_number, column_number);
                    tokens.push_back(new_token);
                    column_number++;
                    i++;
                }
                else if(ch == ']'){
                    Token new_token("]", TokenType::Delimiters, line_number, column_number);
                    tokens.push_back(new_token);
                    column_number++;
                    i++;
                }
                else if(ch == ';'){
                    Token new_token(";", TokenType::Delimiters, line_number, column_number);
                    tokens.push_back(new_token);
                    column_number++;
                    i++;
                }
                else if(ch == '.'){
                    if(i + 1 < code.size() && code[i + 1] == '.'){ // Pascal-S数组：array[1..10] of integer
                        Token new_token("..", TokenType::Operator, line_number, column_number);
                        tokens.push_back(new_token);
                        column_number += 2;
                        i += 2;
                    } else{
                        Token new_token(".", TokenType::Delimiters, line_number, column_number);
                        tokens.push_back(new_token);
                        column_number++;
                        i++;
                    }
                }
                else if(ch == ':'){
                    if(i + 1 < code.size() && code[i + 1] == '='){
                        Token new_token(":=", TokenType::Operator, line_number, column_number);
                        tokens.push_back(new_token);
                        column_number += 2;
                        i += 2;
                    } else{
                        Token new_token(":", TokenType::Delimiters, line_number, column_number);
                        tokens.push_back(new_token);
                        column_number++;
                        i++;
                    }
                }
                else if(ch == ','){
                    Token new_token(",", TokenType::Delimiters, line_number, column_number);
                    tokens.push_back(new_token);
                    column_number++;
                    i++;
                }
                else if(ch == '+'){
                    Token new_token("+", TokenType::Operator, line_number, column_number);
                    tokens.push_back(new_token);
                    column_number++;
                    i++;
                }
                else if(ch == '-'){
                    Token new_token("-", TokenType::Operator, line_number, column_number);
                    tokens.push_back(new_token);
                    column_number++;
                    i++;
                }
                else if(ch == '*'){
                    Token new_token("*", TokenType::Operator, line_number, column_number);
                    tokens.push_back(new_token);
                    column_number++;
                    i++;
                }
                else if(ch == '/'){
                    if(i + 1 < code.size() && code[i + 1] == '/'){ // // 类型注释
                        while(i < code.size()){
                            ch = std::tolower(code[i]);
                            if(ch == '\n'){ 
                                line_number++; 
                                column_number = 1;
                                i++;
                                break;
                            } else{
                                column_number++;
                                i++;
                            }
                        }
                    } else {
                        Token new_token("/", TokenType::Operator, line_number, column_number);
                        tokens.push_back(new_token);
                        column_number++;
                        i++;
                    }
                }
                else if(ch == '='){
                    Token new_token("=", TokenType::Operator, line_number, column_number);
                    tokens.push_back(new_token);
                    column_number++;
                    i++;
                }
                else if(ch == '<'){
                    if(i + 1 < code.size() && code[i + 1] == '='){
                        Token new_token("<=", TokenType::Operator, line_number, column_number);
                        tokens.push_back(new_token);
                        column_number += 2;
                        i += 2;
                    } else if(i + 1 < code.size() && code[i + 1] == '>'){
                        Token new_token("<>", TokenType::Operator, line_number, column_number);
                        tokens.push_back(new_token);
                        column_number += 2;
                        i += 2;
                    } else{
                        Token new_token("<", TokenType::Operator, line_number, column_number);
                        tokens.push_back(new_token);
                        column_number++;
                        i++;
                    }
                }
                else if(ch == '>'){
                    if(i + 1 < code.size() && code[i + 1] == '='){
                        Token new_token(">=", TokenType::Operator, line_number, column_number);
                        tokens.push_back(new_token);
                        column_number += 2;
                        i += 2;
                    } else{
                        Token new_token(">", TokenType::Operator, line_number, column_number);
                        tokens.push_back(new_token);
                        column_number++;
                        i++;
                    }
                }
                else if(ch == '\''){
                    state = State::IN_STRING;
                    column_number++;
                    i++;
                }
                else{
                    fprintf(stderr, "Error: 在 %d 行 %d 列处存在非法字符 %c\n", line_number, column_number, ch);
                    column_number++;
                    i++;
                }
                break;

            case State::IN_WORD:
                if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_'){
                    temp_token += ch;
                    column_number++;
                    i++;
                } else {
                    all_to_lower(temp_token); // 转换为小写字母
                    if(is_keyword(temp_token)){
                        Token new_token(temp_token, TokenType::Keyword, line_number, column_number - temp_token.size());
                        tokens.push_back(new_token);
                    } else{
                        Token new_token(temp_token, TokenType::Identifier, line_number, column_number- temp_token.size());
                        tokens.push_back(new_token);
                    }
                    temp_token.clear();
                    state = State::START;
                }
                break;

            case State::IN_COMMENT: // 此处仅考虑 (*...*)
                if(ch == '*'){
                    if(i + 1 < code.size() && code[i + 1] == ')'){
                        state = State::START;
                        column_number += 2;
                        i += 2;
                    } else {
                        column_number++;
                        i++;
                    }
                }
                else {
                    column_number++;
                    i++;
                }
                break;

            case State::IN_NUM: // 数字常量
                if(num_state == NumState::INTEGER){
                    if(ch >= '0' && ch <= '9'){
                        temp_token += ch;
                        column_number++;
                        i++;
                    } else if(ch == '.'){
                        num_state = NumState::FRACTION_START;
                        temp_token += ch;
                        column_number++;
                        i++;
                    } else {
                        Token new_token(temp_token, TokenType::Number, line_number, column_number - temp_token.size());
                        tokens.push_back(new_token);
                        temp_token.clear();
                        state = State::START;
                    }
                }
                else if(num_state == NumState::FRACTION_START){
                    if(ch >= '0' && ch <= '9'){
                        num_state = NumState::FRACTION;
                        temp_token += ch;
                        column_number++;
                        i++;
                    } else if(ch == '.'){
                        temp_token.pop_back(); // 删除小数点
                        column_number--;
                        i--; // 重新扫描小数点, 以便识别 ".." 运算符

                        Token new_token(temp_token, TokenType::Number, line_number, column_number - temp_token.size());
                        tokens.push_back(new_token);
                        temp_token.clear();
                        state = State::START;
                    } else {
                        fprintf(stderr, "Error: 在 %d 行 %d 列处数字常量错误\n", line_number, column_number);
                        temp_token.pop_back(); // 删除小数点
                        Token new_token(temp_token, TokenType::Number, line_number, column_number - temp_token.size());
                        tokens.push_back(new_token);
                        temp_token.clear();
                        state = State::START;
                    }
                }
                else if(num_state == NumState::FRACTION){
                    if(ch >= '0' && ch <= '9'){
                        temp_token += ch;
                        column_number++;
                        i++;
                    } else {
                        Token new_token(temp_token, TokenType::Number, line_number, column_number - temp_token.size());
                        tokens.push_back(new_token);
                        temp_token.clear();
                        state = State::START;
                    }
                }
                break;

            case State::IN_STRING: // 字符串/字符常量（根据长度区分）
                if(ch == '\''){
                    if(i + 1 < code.size() && code[i + 1] == '\''){ // 单个字符 '
                        temp_token += ch;
                        column_number += 2;
                        i += 2;
                    } else { // 字符串结束
                        if(temp_token.size() == 1){
                            Token new_token(temp_token, TokenType::Char, line_number, column_number - 1);
                            tokens.push_back(new_token);
                        } else {
                            Token new_token(temp_token, TokenType::String, line_number, column_number - temp_token.size());
                            tokens.push_back(new_token);
                        }
                        temp_token.clear();
                        state = State::START;
                        column_number++;
                        i++;
                    }
                }
                else if(ch == '\n'){
                    fprintf(stderr, "Error: 在 %d 行 %d 列处字符串常量缺少右引号 \' 错误\n", line_number, column_number);
                    if(temp_token.size() == 1){
                        Token new_token(temp_token, TokenType::Char, line_number, column_number - 1);
                        tokens.push_back(new_token);
                    } else {
                        Token new_token(temp_token, TokenType::String, line_number, column_number - temp_token.size());
                        tokens.push_back(new_token);
                    } // 尝试修复错误：闭合字符串常量

                    temp_token.clear();
                    state = State::START;
                }
                else{
                    temp_token += ch;
                    column_number++;
                    i++;
                }
                break;
        }
        
    }

    if(state == State::IN_STRING){
        fprintf(stderr, "Error: 在 %d 行 %d 列处字符串常量缺少右引号 \" 错误\n", line_number, column_number);
        if(temp_token.size() == 1){
            Token new_token(temp_token, TokenType::Char, line_number, column_number - 1);
            tokens.push_back(new_token);
        } else {
            Token new_token(temp_token, TokenType::String, line_number, column_number - temp_token.size());
            tokens.push_back(new_token);
        } // 尝试修复错误：闭合字符串常量
        temp_token.clear();
    }

    if(state == State::IN_COMMENT){
        fprintf(stderr, "Error: 在 %d 行 %d 列处注释缺少右括号 *) 错误\n", line_number, column_number);
    }

    if(state == State::IN_WORD && temp_token.size() != 0){
        if(is_keyword(temp_token)){
            Token new_token(temp_token, TokenType::Keyword, line_number, column_number - temp_token.size());
            tokens.push_back(new_token);
        } else{
            Token new_token(temp_token, TokenType::Identifier, line_number, column_number - temp_token.size());
            tokens.push_back(new_token);
        }
        temp_token.clear();
    }

    if(state == State::IN_NUM && temp_token.size() != 0){
        if(num_state == NumState::INTEGER){
            Token new_token(temp_token, TokenType::Number, line_number, column_number - temp_token.size());
            tokens.push_back(new_token);
            temp_token.clear();
        }
        else if(num_state == NumState::FRACTION){
            fprintf(stderr, "Error: 在 %d 行 %d 列处数字常量错误\n", line_number, column_number);
            temp_token.pop_back(); // 删除小数点
            Token new_token(temp_token, TokenType::Number, line_number, column_number - temp_token.size());
            tokens.push_back(new_token);
            temp_token.clear();
        }
    }
}

int Token::to_yacc_token() const {
    switch(this->type){
        case TokenType::Identifier: return 1;
        case TokenType::Number: return 2;
        case TokenType::String: return 3;
        case TokenType::Char: return 4;
        case TokenType::Keyword: 
            if(this->property == "program") return 5;
            else if(this->property == "const") return 6;
            else if(this->property == "var") return 7;
            else if(this->property == "array") return 8;
            else if(this->property == "of") return 9;
            else if(this->property == "integer" || this->property == "real" || this->property == "boolean" || this->property == "char") return 10;
            else if(this->property == "procedure") return 11;
            else if(this->property == "function") return 12;
            else if(this->property == "begin") return 13;
            else if(this->property == "end") return 14;
            else if(this->property == "if") return 15;
            else if(this->property == "then") return 16;
            else if(this->property == "for") return 17;
            else if(this->property == "to") return 18;
            else if(this->property == "do") return 19;
            else if(this->property == "read") return 20;
            else if(this->property == "write") return 21;
            else if(this->property == "else") return 22;
            else if(this->property == "true" || this->property == "false") return 23;
            else if(this->property == "not") return 24;
            else if(this->property == "div" || this->property == "mod") return 25;
            else if(this->property == "or") return 26; // ADDOP
            else if(this->property == "and") return 25; // MULOP
            /*拓展语法：while, break*/
            else if(this->property == "while") return 39;
            else if(this->property == "break") return 40;
            break;
        case TokenType::Operator: 
            if(this->property == "*" || this->property == "/") return 25;
            else if(this->property == "+" || this->property == "-") return 26;
            else if(this->property == "<" || this->property == "<=" || this->property == ">" || this->property == ">=" || this->property == "=" || this->property == "<>") return 27; //RELOP
            else if(this->property == ":=") return 28;
            else if(this->property == "..") return 29;
            break;
        case TokenType::Delimiters: 
            if(this->property == ";") return 30;
            else if(this->property == ".") return 31;
            else if(this->property == "(") return 32;
            else if(this->property == ")") return 33;
            else if(this->property == "[") return 34;
            else if(this->property == "]") return 35;
            else if(this->property == ":") return 36;
            else if(this->property == ",") return 37;
            break;
        case TokenType::Null: return 38;
    }
    return 38;
}