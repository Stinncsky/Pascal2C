#include "test_translate_declaration.hh"

// 测试 FinalNode 的 trans() 方法
// 1. 测试数字常量
void test_final_num() {
    std::string expected = "3";
    std::string actual = num_3->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] final_num: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_final_num failed\n");
    }
    clear_table();
}
// 2. 测试字符常量
void test_final_char() {
    std::string expected = "b";
    std::string actual = b_char->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] final_char: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_final_char failed\n");
    }
    clear_table();
}
// 3. 测试标识符
void test_final_identifier() {
    std::string expected = "a";
    std::string actual = a->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] final_identifier: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_final_identifier failed\n");
    }
    clear_table();
}
// 4. 测试关键字
void test_final_keyword() {
    std::string expected = "int";
    std::string actual = integer->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] final_keyword: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_final_keyword failed\n");
    }
    clear_table();
}

int main() {
    test_final_num();
    test_final_char();
    test_final_identifier();
    test_final_keyword();
    return 0;
}