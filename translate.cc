#include "./header/translate.hh"
#include "AST.cc"

std::string FinalNode::trans() const{
    return token.property; // 有待修改
}