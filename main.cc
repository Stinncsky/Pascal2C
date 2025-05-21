/* DEBUG USAGE: g++ -D_GLIBCXX_DEBUG -Wall -Wextra -pedantic -g -o main.exe .\main.cc */
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

#ifdef _WIN32
    #include <windows.h>
    #include <thread>
    #include <chrono>
#else
    #include <csignal>
    #include <unistd.h>
    #include <cstdlib>
#endif
#ifdef _WIN32
void windowsTimeoutThread(int seconds) { // Windows 实现：启动一个计时线程，等待超时时间后终止程序
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    std::cerr << "TLE ERROR" << std::endl;
    ExitProcess(1);
}
#else
void timeoutHandler(int signum) { // Linux 实现：使用 alarm 与信号处理函数
    std::cerr << "TLE ERROR" << std::endl;
    std::exit(signum);
}
#endif
const int timeoutSeconds = 10; // 设置超时时间为 10 秒

Syntax* syntax = nullptr;
std::vector<Token> tokens;
int tokenIndex = 0;

static std::string INPUT_FILE = "input.pas";
static std::string OUTPUT_FILE = "output.c";
const static std::string VERSION = "2.0.0-B";

void set_parameter(int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0) {
            debug_mode = DEBUG_PRINT;
        }
        if (strcmp(argv[i], "-i") == 0) {
            INPUT_FILE = argv[++i];
            // 将输出文件名设置为输入文件名 + ".c"
            std::string input_file_name = INPUT_FILE.substr(0, INPUT_FILE.find_last_of('.'));
            OUTPUT_FILE = input_file_name + ".c";
        }
        if(strcmp(argv[i], "-ii") == 0) {
            INPUT_FILE = argv[++i];
        }
        if (strcmp(argv[i], "-o") == 0) {
            OUTPUT_FILE = argv[++i];
        }
    }
}

int main(int argc, char *argv[]) {
    if(debug_mode) printf("Pascal2C version %s\n", VERSION.c_str());
    set_parameter(argc, argv);

    syntax = new Syntax(); // 这里初始化 syntax
    syntax->tree = nullptr;

    #ifdef _WIN32
        // 启动计时线程，并分离（后台运行）
        std::thread timerThread(windowsTimeoutThread, timeoutSeconds);
        timerThread.detach();
    #else
        // 设置信号处理函数，并启动定时器
        std::signal(SIGALRM, timeoutHandler);
        alarm(timeoutSeconds);
    #endif

    Program program;
    program.run();

    delete syntax;
    return 0;
}

void Program::run(){
    std::string source_code;
    // 读取源代码
    std::ifstream file(INPUT_FILE);
    if (!file.is_open()) {
        std::string err_out = "Error: Open file" + INPUT_FILE + " failed\n";
        fprintf(stderr, "%s", err_out.c_str());
        exit(1);
        return;
    }
    std::string line;
    while (getline(file, line)) {
        source_code += line + "\n";
    }
    if(debug_mode) printf("Read file %s\n", INPUT_FILE.c_str());
    file.close();
    
    lexicalAnalyzer.load(source_code);
    lexicalAnalyzer.run();
    tokens = lexicalAnalyzer.getTokens();

    extern int yydebug;
    yydebug = debug_mode;
    if(yyparse() == 0)  {
        // 语法分析成功
        if(syntax->tree != nullptr) {
            if(debug_mode) printf("Success in Syntax Analysis\n\n");

            tree_root = syntax->tree;
            std::string output = dynamic_cast<ProgramStructNode *>(tree_root)->trans();
            if(debug_mode) printf("Success in Translation to C-language\n");

            std::ofstream out(OUTPUT_FILE);
            out << output;
            out.close();
            if(debug_mode) printf("Output to file %s\n", OUTPUT_FILE.c_str());
        } else {
            fprintf(stderr, "Error: No syntax tree\n");
            exit(1);
        }
    } else {
        fprintf(stderr, "Error: Syntax Analysis failed\n");
        exit(1);
    }
}