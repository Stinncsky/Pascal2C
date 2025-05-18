#include "../lexical.cc"
#include <iostream>
#include <fstream>
#include <map>

const static std::map <TokenType, std::string> token_map = {
    {TokenType::Identifier, "Identifier"},
    {TokenType::Number, "Number"},
    {TokenType::String, "String"},
    {TokenType::Char, "Char"},
    {TokenType::Keyword, "Keyword"},
    {TokenType::Operator, "Operator"},
    {TokenType::Delimiters, "Delimiters"},
    {TokenType::Null, "Null"}
};

int main(){
    std::string source_code;
    std::ifstream file("./../input.pas");
    if (!file.is_open()) {
        std::string err_out = "Error: Open file failed\n";
        fprintf(stderr, "%s", err_out.c_str());
        exit(1);
    }
    std::string line;
    while (getline(file, line)) {
        source_code += line + "\n";
    }
    file.close();

    Lexical lexicalAnalyzer;
    lexicalAnalyzer.load(source_code);
    lexicalAnalyzer.run();
    auto tokens = lexicalAnalyzer.getTokens();

    for(const auto &token : tokens) {
        std::cout << "Token: " << token.property << "\t Type: " << token_map.at(token.type) 
                  << "\t Line: " << token.line << "\t Column: " << token.column << std::endl;
    }

    return 0;
}