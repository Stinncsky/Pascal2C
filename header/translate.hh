#ifndef __translate_HH__
#define __translate_HH__
#include "AST.hh"
#include <map>

class Table {
public:
    std::map<FinalNode, std::tuple<int, std::vector<int>, std::vector<int>>> table;
    // tuple<int（0int，1double，2char，3string）, vector<int>（第几号位置的参数是怎么调用的：0为传值，1为传地址）, vector<int>（数组起始位置）>
    // 不过符号表中需要记载这个变量的值吗，不同作用域值不同感觉可能需要记一下？
    FinalNode *now_funcid = nullptr;
};

#endif