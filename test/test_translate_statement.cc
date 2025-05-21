#include <cassert>
#include "test_translate_declaration.hh"
// 测试 StatementNode 的 trans() 方法
// 1. 赋值语句 a = 3;
void test_statement_assign() {
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>(), std::vector<int>());
    std::string expected = "a = 3;\n";
    std::string actual = statement_2->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] assign: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_statement_assign failed\n");
    }
    clear_table();
}
// 2. 过程调用语句
void test_statement_proc_call() {
    t.table[*p] = std::make_tuple(FUNC_VOID, std::vector<int>(), std::vector<int>());
    std::string expected = "p();\n";
    std::string actual = statement_proc_call->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] proc_call: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_statement_proc_call failed\n");
    }
    clear_table();
}
// 3. 复合语句
void test_statement_compound() {
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>(), std::vector<int>());
    std::string expected = "a = 3;\n";
    std::string actual = statement_compound->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] compound: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_statement_compound failed\n");
    }
    clear_table();
}
// 4. if 语句
void test_statement_if() {
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>(), std::vector<int>());
    std::string expected = "if (3<3){\n\ta = 3;\n}\n";
    std::string actual = statement_if->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] if: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_statement_if failed\n");
    }
    clear_table();
}
// 4.1 if-else 语句
void test_statement_if_else() {
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>(), std::vector<int>());
    t.table[*b] = std::make_tuple(ID_INT, std::vector<int>(), std::vector<int>());
    std::string expected = "if (3<3){\n\ta = 3;\n} else {\n\tb = 3;\n}\n";
    std::string actual = statement_if_else->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] if_else: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_statement_if_else failed\n");
    }
    clear_table();
}
// 5. for 语句
void test_statement_for() {
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>(), std::vector<int>());
    std::string expected = "for (a = 3; a <= 3; a++){\n\ta = 3;\n}\n";
    std::string actual = statement_for->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] for: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_statement_for failed\n");
    }
    clear_table();
}
// 6. while 语句
void test_statement_while() {
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>(), std::vector<int>());
    std::string expected = "while (3<3) {\n\ta = 3;\n}\n";
    std::string actual = statement_while->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] while: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_statement_while failed\n");
    }
    clear_table();
}
// 7. read 语句
void test_statement_read() {
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>(), std::vector<int>());
    std::string expected = "scanf(\"%d\", &a);\n";
    std::string actual = statement_read->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] read: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_statement_read failed\n");
    }
    clear_table();
}
// 8. write 语句
void test_statement_write() {
    std::string expected = "printf(\"%d\", 3);\n";
    std::string actual = statement_write->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] write: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_statement_write failed\n");
    }
    clear_table();
}
// 9. 复合语句与语句序列
void test_statement_list() {
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>(), std::vector<int>());
    t.table[*b] = std::make_tuple(ID_INT, std::vector<int>(), std::vector<int>());
    std::string expected = "a = 3;\nb = 3;\n";
    std::string actual = statement_list->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] statement_list: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_statement_list failed\n");
    }
    clear_table();
}
void test_compound_statement_multi() {
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>(), std::vector<int>());
    t.table[*b] = std::make_tuple(ID_INT, std::vector<int>(), std::vector<int>());
    std::string expected = "a = 3;\nb = 3;\n";
    std::string actual = compound_statement_multi->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] compound_multi: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_compound_statement_multi failed\n");
    }
    clear_table();
}
int main() {
    test_statement_assign();
    test_statement_proc_call();
    test_statement_compound();
    test_statement_if();
    test_statement_if_else();
    test_statement_for();
    test_statement_while();
    test_statement_read();
    test_statement_write();
    test_statement_list();
    test_compound_statement_multi();
    return 0;
}