#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
#include "../syntax.tab.cpp"
// 包含必要的AST头文件
#include "../header/AST.hh"
#include "../header/translate.hh"
#include "../lexical.cc"
#include "../translate.cc"
#include "../header/header.hh"
#include "../AST.cc"
#include "../header/syntax.hh"
#include "../header/token.hh"
#include "../header/program.hh"
// 常量
static const char *INPUT_FILE = "AST_right_1.txt";  // 测试用输入文件

extern int yyparse(); // 由yacc/bison生成的解析函数
Syntax* syntax = nullptr; // 用于保存生成语法树的Syntax实例
AST *tree_root; // 用于保存语法树的根节点
std::vector<Token> tokens;
int tokenIndex = 0;


void loadTokens(const char *filename) {
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "错误：无法打开输入文件 " << filename << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(input_file, line)) {
        // 解析格式：Token: property Type: type Line: line Column: column
        std::string token_prefix, type_prefix, line_prefix, column_prefix;
        std::string property, type_str;
        int line_num, column_num;
        
        std::istringstream iss(line);
        
        if (!(iss >> token_prefix >> property >> type_prefix >> type_str >> line_prefix >> line_num >> column_prefix >> column_num) ||
            token_prefix != "Token:" || type_prefix != "Type:" || line_prefix != "Line:" || column_prefix != "Column:") {
            std::cerr << "错误：行格式错误，必须为 'Token: property Type: type Line: line Column: column' 格式" << std::endl;
            std::cerr << "有问题的行: " << line << std::endl;
            exit(1);
        }

        // 将字符串类型转换为枚举类型
        TokenType type;
        if (type_str == "Identifier") type = TokenType::Identifier;
        else if (type_str == "Number") type = TokenType::Number;
        else if (type_str == "String") type = TokenType::String;
        else if (type_str == "Char") type = TokenType::Char;
        else if (type_str == "Keyword") type = TokenType::Keyword;
        else if (type_str == "Operator") type = TokenType::Operator;
        else if (type_str == "Delimiters") type = TokenType::Delimiters;
        else type = TokenType::Null;

        // 创建 Token 并添加到 tokens 中
        Token token(property, type, line_num, column_num);
        tokens.push_back(token);
    }
    
    input_file.close();
}

int main() {
    // 加载 token 流    
    loadTokens(INPUT_FILE);
    syntax = new Syntax(); // 这里初始化 syntax
    syntax->tree = nullptr;
    // 调用解析器
    if (yyparse() == 0) { // 语法分析成功
        if (syntax->tree != nullptr) { // 检查是否生成了语法树
            if (debug_mode) std::cout << "语法分析成功\n\n";

            // 将语法树输出到标准输出以便可视化
            std::cout << "\n抽象语法树(AST)输出：\n";
            tree_root = syntax->tree;
            std::string output = dynamic_cast<ProgramStructNode *>(tree_root)->trans();
            tree_root->output();
        } else {
            std::cerr << "错误：未生成语法树\n";
            return 1;
        }
    } else {
        std::cerr << "错误：语法分析失败\n";
        return 1;
    }

    return 0;
}