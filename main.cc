#include <cstring>
#include <iostream>
#include <fstream>
#include "header/header.hh"
#include "AST.cc"

#ifndef FINAL
    #include "lexical.cc"
    #include "syntax.tab.cpp"
    #include "translate.cc"
#endif

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

    delete syntax;
    return 0;
}

void Program::run(){
    std::string source_code;
    // 读取源代码
    std::ifstream file("input.pas");
    if (!file.is_open()) {
        fprintf(stderr, "Error: Open file \"input.pas\" failed\n");
        return;
    }
    std::string line;
    while (getline(file, line)) {
        source_code += line + "\n";
    }
    file.close();
    
    lexicalAnalyzer.load(source_code);
    lexicalAnalyzer.run();
    tokens = lexicalAnalyzer.getTokens();

    extern int yydebug;
    yydebug = 0;
    if(yyparse() == 0)  {
        // 语法分析成功
        if(syntax->tree != nullptr) {
            printf("Success in Syntax Analysis\n\n");

            tree_root = syntax->tree;
            std::cout << dynamic_cast<ProgramStructNode *>(tree_root)->trans() << std::endl;
            printf("Success in Translation to C-language\n");
        }
        else
            fprintf(stderr, "Error: No syntax tree\n");
    } else {
        fprintf(stderr, "Error: Syntax Analysis failed\n");
    }
}