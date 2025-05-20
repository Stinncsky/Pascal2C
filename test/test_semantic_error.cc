#include <cassert>
#include "test_translate_declaration.hh"
#include <iostream>
#include <cstdio>
#include <cstring>

// 1. 使用未声明变量
void test_undeclared_variable() {
    clear_table();
    try {
        statement_2->trans();
    } catch (...) {}
    clear_table();
}
// 2. 使用未声明函数
void test_undeclared_function() {
    clear_table();
    try {
        proc_call_p->trans();
    } catch (...) {}
    clear_table();
}
// 3. 函数参数个数不匹配
void test_function_arg_mismatch() {
    clear_table();
    t.table[*f] = std::make_tuple(FUNC_INT, std::vector<int>{ID_INT,ID_CHAR}, std::vector<int>{});
    try {
        factor_func_call->trans();
    } catch (...) {}
    clear_table();
}
// 4. 函数参数类型不匹配
void test_function_arg_type_mismatch() {
    clear_table();
    t.table[*p] = std::make_tuple(FUNC_INT, std::vector<int>{ID_INT, ID_CHAR}, std::vector<int>{});
    try {
        proc_call->trans();
    } catch (...) {}
    clear_table();
}
// 5. 左右类型不匹配（如 int = char）
void test_type_mismatch() {
    clear_table();
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>{}, std::vector<int>{});
    // 直接使用声明头文件中的节点
    try {
        stmt->trans();
    } catch (...) {}
    clear_table();
}
void test_array_index_negative() {
    clear_table();
    std::vector<int> dim = {1};
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>{}, dim);
    // 直接使用声明头文件中的节点
    try {
        stmt_arr_minus_one->trans();
    } catch (...) {}
    clear_table();
}
void test_array_dimension_mismatch() {
    clear_table();
    std::vector<int> dim = {1,1};
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>{}, dim);
    // 直接使用声明头文件中的节点
    try {
        stmt_arr_three->trans();
    } catch (...) {}
    clear_table();
}

int main() {
    test_undeclared_variable();
    test_undeclared_function();
    test_function_arg_mismatch();
    test_function_arg_type_mismatch();
    test_type_mismatch();
    test_array_index_negative();
    test_array_dimension_mismatch();
    return 0;
}