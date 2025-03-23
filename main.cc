#include <cstring>
#include <iostream>
#include "header/header.hh"
#include "AST.cc"

Syntax* syntax = nullptr;
std::vector<Token> tokens;
int tokenIndex = 0;   

void set_parameter(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0) {
            debug_mode = DEBUG_PRINT;
        }
    }
}

int main(int argc, char *argv[]) {
    set_parameter(argc, argv);

    syntax = new Syntax(); // 这里初始化 syntax
    syntax->tree = nullptr;

    Program program;
    program.run();

    return 0;
}

void Program::run(){
    std::string source_code;
    // 读取源代码
    source_code = "program main;\nvar\n  a: integer;\n  b: integer;\n\nfunction func(p: integer): integer;\nbegin\n  p := p - 1;\n  func := p;\nend;\n\nbegin\n  a := 10;\n  b := func(a);\n\n  write(b);\nend.\n";
    
    lexicalAnalyzer.load(source_code);
    lexicalAnalyzer.run();
    tokens = lexicalAnalyzer.getTokens();

    extern int yydebug;
    yydebug = 1;
    if(yyparse() == 0)  {
        // 语法分析成功
        if(syntaxAnalyzer.tree != nullptr) {
            tree_root = syntaxAnalyzer.tree;
            std::cout << dynamic_cast<ProgramStructNode *>(tree_root)->trans() << std::endl;

            printf("Success: 语法分析成功\n");
        }
        else
            fprintf(stderr, "Error: 语法分析树为空\n");
    } else {
        fprintf(stderr, "Error: 语法分析失败\n");
    }
}