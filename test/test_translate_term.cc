#include "test_translate_declaration.hh"

// 测试 TermNode 的 trans() 方法
// 1. 测试单一因子 term → factor
void test_term_single_factor() {
    std::string expected = "3 %d";
    std::string actual = term_num_3->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] term_single_factor: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_term_single_factor failed\n");
    }
    clear_table();
}
// 2. 测试复合项 term → term * factor
void test_term_mul() {
    std::string expected = "3*8 %d";
    std::string actual = term_3_mul_8->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] term_mul: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_term_mul failed\n");
    }
    clear_table();
}
// 3. 测试复合项 term → term / factor
void test_term_div() {
    std::string expected = "8/3 %d";
    std::string actual = term_8_div_3->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] term_div: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_term_div failed\n");
    }
    clear_table();
}
int main() {
    test_term_single_factor();
    test_term_mul();
    test_term_div();
    return 0;
}
