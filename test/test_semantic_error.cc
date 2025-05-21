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
    t.table[*b] = std::make_tuple(ID_CHAR, std::vector<int>{}, std::vector<int>{});
    // 直接使用声明头文件中的节点
    try {
        stmt->trans();
    } catch (...) {}
    clear_table();
}
// 6. 数组下标为负数
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
// 7. 数组维度不匹配（如声明为二维，使用一维）
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
// 8. 传引用参数时，传入的不是变量
void test_pass_by_reference() {
    clear_table();
    t.table[*p] = std::make_tuple(FUNC_INT, std::vector<int>{ID_INT, ID_INT + CITE}, std::vector<int>{});
    // 直接使用声明头文件中的节点
    try {
        proc_call->trans();
    } catch (...) {}
    clear_table();
}

// 9. 关系运算符两边类型不匹配
void test_relop_type_mismatch() {
    clear_table();
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>{}, std::vector<int>{});
    t.table[*b] = std::make_tuple(ID_CHAR, std::vector<int>{}, std::vector<int>{});
    // 直接使用声明头文件中的节点
    try {
        expr_a_lt_b->trans();
    } catch (...) {}
    clear_table();
}
// 10. 加减运算符两边类型不匹配
void test_addop_type_mismatch() {
    clear_table();
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>{}, std::vector<int>{});
    t.table[*b] = std::make_tuple(ID_CHAR, std::vector<int>{}, std::vector<int>{});
    // 直接使用声明头文件中的节点
    try {
        simple_expr_a_plus_b->trans();
    } catch (...) {}
    clear_table();
}
// 11. 乘除运算符两边类型不匹配
void test_mulop_type_mismatch() {
    clear_table();
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>{}, std::vector<int>{});
    t.table[*b] = std::make_tuple(ID_CHAR, std::vector<int>{}, std::vector<int>{});
    // 直接使用声明头文件中的节点
    try {
        term_a_mul_b->trans();
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
    test_pass_by_reference();
    test_relop_type_mismatch();
    test_addop_type_mismatch();
    test_mulop_type_mismatch();
    return 0;
}