#include <cstring>

#include "header/header.hh"

void set_parameter(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0) {
            debug_mode = DEBUG_PRINT;
        }
    }
}

int main(int argc, char *argv[]) {
    set_parameter(argc, argv);

    Program program;
    program.run();

    return 0;
}

void Program::run(){
    std::string source_code;
    // 读取源代码

    lexicalAnalyzer.load(source_code);
    lexicalAnalyzer.run();
    tokens = lexicalAnalyzer.getTokens();
}