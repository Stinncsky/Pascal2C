#include <iostream>
#include <fstream>
#include "header/header.hh"
#include "AST.cc"
#include "test/output_AST.cc"
#include "translate.cc"
#ifndef FINAL
#include "lexical.cc"
#include "syntax.tab.cpp"
#endif

Syntax* syntax = nullptr;
std::vector<Token> tokens;
int tokenIndex = 0;

int main() {
    Lexical lexicalAnalyzer;
    std::string INPUT_FILE = "input.pas";
    std::string source_code;
    std::ifstream file(INPUT_FILE);
    if (!file.is_open()) {
        std::cerr << "Error: Open file " << INPUT_FILE << " failed\n";
        return 1;
    }
    std::string line;
    while (getline(file, line)) {
        source_code += line + "\n";
    }
    file.close();

    lexicalAnalyzer.load(source_code);
    lexicalAnalyzer.run();
    tokens = lexicalAnalyzer.getTokens();

    syntax = new Syntax();
    syntax->tree = nullptr;
    extern int yydebug;
    yydebug = 0;
    if (yyparse() == 0) {
        if (syntax->tree != nullptr) {
            syntax->tree->output();
        } else {
            std::cerr << "Error: No syntax tree\n";
            delete syntax;
            return 1;
        }
    } else {
        std::cerr << "Error: Syntax Analysis failed\n";
        delete syntax;
        return 1;
    }
    delete syntax;
    return 0;
}
