#ifndef __translate_HH__
#define __translate_HH__
#include "AST.hh"
#include <map>

class Table{
    public:
        std::map<FinalNode, std::pair<int,std::vector<int>>> table;
        FinalNode &now_funcid;
};

#endif