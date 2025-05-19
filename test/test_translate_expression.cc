#include "test_translate_declaration.hh"

// 1. 测试 ExpressionNode: expression → simple_expression
void test_expression_simple() {
    std::string expected = "3 %d";
    std::string actual = expression_num->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] expression_simple: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_expression_simple failed\n");
    }
    clear_table();
}
// 2. 测试 ExpressionNode: expression → simple_expression relop simple_expression
void test_expression_relop() {
    std::string expected = "3<3 %d";
    std::string actual = expression_relop->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] expression_relop: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_expression_relop failed\n");
    }
    clear_table();
}
// 3. 测试 SimpleExpressionNode: simple_expression → term
void test_simple_expression_term() {
    std::string expected = "3 %d";
    std::string actual = Sexpression_num_3->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] simple_expression_term: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_simple_expression_term failed\n");
    }
    clear_table();
}
// 4. 测试 SimpleExpressionNode: simple_expression → simple_expression addop term
void test_simple_expression_add() {
    std::string expected = "3+8 %d";
    std::string actual = simple_expression_add->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] simple_expression_add: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_simple_expression_add failed\n");
    }
    clear_table();
}
// 5. 测试 ExpressionListNode: 单元素
void test_expression_list_single() {
    std::string expected = "3 %d";
    std::string actual = expression_list_single->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] expression_list_single: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_expression_list_single failed\n");
    }
    clear_table();
}
// 6. 测试 ExpressionListNode: 多元素
void test_expression_list_multi() {
    std::string expected = "3 %d,3 %d";
    std::string actual = expression_list_multi->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] expression_list_multi: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_expression_list_multi failed\n");
    }
    clear_table();
}
int main() {
    test_expression_simple();
    test_expression_relop();
    test_simple_expression_term();
    test_simple_expression_add();
    test_expression_list_single();
    test_expression_list_multi();
    return 0;
}