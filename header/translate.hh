#ifndef __translate_HH__
#define __translate_HH__
#include "AST.hh"
#include "../AST.cc"
#include <map>
#include <iostream>

#define ID_INT 0
#define ID_DOUBLE 1
#define ID_CHAR 2
#define ID_STRING 3
#define FUNC_INT 4
#define FUNC_DOUBLE 5
#define FUNC_CHAR 6
#define FUNC_VOID -1
class Table {
public:
    std::map<FinalNode, std::tuple<int, std::vector<int>, std::vector<int>>> table;
    // tuple<int（0int，1double，2char，3string）, vector<int>（第几号位置的参数是怎么调用的：0为传值，1为传地址）, vector<int>（数组起始位置）>
    // 不过符号表中需要记载这个变量的值吗，不同作用域值不同感觉可能需要记一下？
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