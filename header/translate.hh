#ifndef __translate_HH__
#define __translate_HH__
#include "AST.hh"
#include "../AST.cc"
#include <map>
#include <iostream>

#define ID_INT 0
#define ID_FLOAT 1
#define ID_CHAR 2
#define ID_STRING 3

#define FUNC 10
#define FUNC_INT FUNC+ID_INT
#define FUNC_FLOAT FUNC+ID_FLOAT
#define FUNC_CHAR FUNC+ID_CHAR
#define FUNC_VOID -1
const std::string TMP_RETURN = "__tmp_return";

#define CITE 100
class Table {
public:
    std::map<FinalNode, std::tuple<int, std::vector<int>, std::vector<int>>> table;
    // tuple<int（符号类型）, vector<int>（参数类型，调用方式）, vector<int>（数组起始位置）>
    FinalNode *now_funcid = nullptr;

    void output(){
        if (now_funcid != nullptr) {
            std::cout << "now_func:\t" << now_funcid->trans() << '\n';
        }
        std::cout << "table:\n";
        for (auto _:table){
            std::cout << "Final_Node:" << _.first.trans() << '\n';
            std::cout << "type:" << std::get<0>(_.second) << '\n';
            std::cout << "cites:";
            for (auto __:std::get<1>(_.second))
                std::cout << __ << ' ';
            std::cout << '\n';
            std::cout << "dim:";
            for (auto __:std::get<2>(_.second))
                std::cout << __ << ' ';
            std::cout << '\n';
        }
    }
};

#endif