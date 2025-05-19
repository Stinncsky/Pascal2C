#include <cassert>
#include "test_translate_declaration.hh"

// 1. 测试单个常量声明 const int a = -3;
void test_const_declarations_1() {
    std::string expected = "const int a = -3;\n";
    std::string actual = const_declarations_1->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] const_declarations_1: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_const_declarations_1 failed\n");
    }
    clear_table();
}
// 2. 测试多个常量声明 const int a = -3; const char b = 'b';
void test_const_declarations_2() {
    std::string expected = "const int a = -3;\nconst char b = 'b';\n";
    std::string actual = const_declarations_2->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] const_declarations_2: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_const_declarations_2 failed\n");
    }
    clear_table();
}
int main() {
    test_const_declarations_1();
    test_const_declarations_2();
    return 0;
}