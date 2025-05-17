#include <cassert>
#include "test_translate_declaration.hh"

// 1. 测试 VarDeclarationNode: int a;
void test_var_declaration() {
    std::string expected = "int a;\n";
    std::string actual = var_declaration->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] var_declaration: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_var_declaration failed\n");
    }
    clear_table();
}
// 2. 测试数组类型 TypeNode/PeriodNode: array[1..8] of int a, b;
void test_var_declaration_array() {
    std::string expected = "int a[8];\nint b[8];\n";
    std::string actual = var_declaration_array->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] var_declaration_array: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_var_declaration_array failed\n");
    }
    clear_table();
}
// 3. 测试多维数组 TypeNode/PeriodNode: array[1..8,1..8] of int a, b;
void test_var_declaration_array_2() {
    std::string expected = "int a[8][8];\nint b[8][8];\n";
    std::string actual = var_declaration_array_2->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] var_declaration_array_2: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_var_declaration_array_2 failed\n");
    }
    clear_table();
}
// 4. 测试 TypeNode/BasicTypeNode/PeriodNode 单独类型
void test_type_integer() {
    std::string expected = "int";
    std::string actual = type_integer->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] type_integer: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_type_integer failed\n");
    }
    clear_table();
}
void test_type_integer_array() {
    std::string expected = "int";
    std::string actual = type_integer_array->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] type_integer_array: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_type_integer_array failed\n");
    }
    clear_table();
}
void test_type_integer_array_2() {
    std::string expected = "int";
    std::string actual = type_integer_array_2->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] type_integer_array_2: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_type_integer_array_2 failed\n");
    }
    clear_table();
}
void test_period() {
    std::vector<int> dim;
    std::string expected = "[8]";
    std::string actual = period->trans(dim);
    if (expected != actual) {
        std::cerr << "[FAIL] period: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_period failed\n");
    }
    clear_table();
}
void test_period_2() {
    std::vector<int> dim;
    std::string expected = "[8][8]";
    std::string actual = period_2->trans(dim);
    if (expected != actual) {
        std::cerr << "[FAIL] period_2: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_period_2 failed\n");
    }
    clear_table();
}
int main() {
    test_var_declaration();
    test_var_declaration_array();
    test_var_declaration_array_2();
    test_type_integer();;
    test_period();
    test_period_2();
    return 0;
}