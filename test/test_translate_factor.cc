#include "test_translate_declaration.hh"

// 测试 FactorNode 的 trans() 方法
// 1. 测试常量因子 factor → num

void test_factor_num() {
    std::string expected = "8 %d";
    std::string actual = factor_num_8->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] factor_num: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_factor_num failed\n");
    }
    clear_table();
}
void test_factor_var() {
    t.table[*b] = std::make_tuple(ID_INT, std::vector<int>(1,0), std::vector<int>());
    std::string expected = "b %d";
    std::string actual = factor_var_b->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] factor_var: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_factor_var failed\n");
    }
    clear_table();
}
void test_factor_paren_expr() {
    std::string expected = "(3) %d";
    std::string actual = factor_paren_expr->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] factor_paren_expr: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_factor_paren_expr failed\n");
    }
    clear_table();
}
void test_factor_func_call() {
    t.table[*f] = std::make_tuple(FUNC_CHAR, std::vector<int>{ID_INT}, std::vector<int>{});
    std::string expected = "f(3) %c";
    std::string actual = factor_func_call->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] factor_func_call: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_factor_func_call failed\n");
    }
    clear_table();
}
void test_factor_not() {
    std::string expected = "~8 %d";
    std::string actual = factor_not_num->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] factor_not: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_factor_not failed\n");
    }
    clear_table();
}
void test_factor_uminus() {
    t.table[*b] = std::make_tuple(ID_INT, std::vector<int>(1,0), std::vector<int>());
    std::string expected = "-b %d";
    std::string actual = factor_uminus_var->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] factor_uminus: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_factor_uminus failed\n");
    }
    clear_table();
}
int main() {
    test_factor_num();
    test_factor_var();
    test_factor_paren_expr();
    test_factor_func_call();
    test_factor_not();
    test_factor_uminus();
    return 0;
}