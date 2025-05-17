#include <cassert>
#include "test_translate_declaration.hh"

// 1. 测试函数声明头 function f(a, b: integer): integer
void test_subprogram_head() {
    std::string expected = "int f(int a, int b)";
    std::string actual = subprogram_head->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] subprogram_head: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_subprogram_head failed\n");
    }
    clear_table();
}
// 2. 测试过程声明头 procedure p(var a, b: integer)
void test_subprogram_head_2() {
    std::string expected = "void p(int *a, int *b)";
    std::string actual = subprogram_head_2->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] subprogram_head_2: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_subprogram_head_2 failed\n");
    }
    clear_table();
}
// 3. 测试子程序体
void test_subprogram_body() {
    t.table[*a] = std::make_tuple(ID_INT, std::vector<int>(), std::vector<int>());
    std::string expected = "{\na = 3;\n}\n";
    std::string actual = subprogram_body->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] subprogram_body: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_subprogram_body failed\n");
    }
    clear_table();
}
// 4. 测试单个子程序
void test_subprogram() {
    std::string expected = "int f(int a, int b){\n\tint f__tmp_return = 0;\n\ta = 3;\n\treturn f__tmp_return;\n}\n";
    std::string actual = subprogram->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] subprogram: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_subprogram failed\n");
    }
    clear_table();
}
// 5. 测试子程序声明序列
void test_subprogram_declarations() {
    std::string expected = "int f(int a, int b){\n\tint f__tmp_return = 0;\n\ta = 3;\n\treturn f__tmp_return;\n}\nvoid p(int *a, int *b){\n\t(*a) = 3;\n}\n";
    std::string actual = subprogram_declarations->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] subprogram_declarations: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_subprogram_declarations failed\n");
    }
    clear_table();
}
// 6. 测试参数相关
void test_value_parameter() {
    // 测试值参数节点
    std::string expected = "int a, int b";
    std::string actual = value_parameter->trans(false);
    if (expected != actual) {
        std::cerr << "[FAIL] value_parameter: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_value_parameter failed\n");
    }
    clear_table();
}
void test_var_parameter() {
    // 测试引用参数节点
    std::string expected = "int *a, int *b";
    std::string actual = var_parameter->trans(nullptr);
    if (expected != actual) {
        std::cerr << "[FAIL] var_parameter: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_var_parameter failed\n");
    }
    clear_table();
}
void test_parameter_node() {
    // 测试 ParameterNode
    std::string expected = "int a, int b";
    std::string actual = parameter->trans(nullptr);
    if (expected != actual) {
        std::cerr << "[FAIL] parameter_node: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_parameter_node failed\n");
    }
    clear_table();
}
void test_parameter_node_2() {
    // 测试 ParameterNode (var)
    std::string expected = "int *a, int *b";
    std::string actual = parameter_2->trans(nullptr);
    if (expected != actual) {
        std::cerr << "[FAIL] parameter_node_2: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_parameter_node_2 failed\n");
    }
    clear_table();
}
void test_parameter_list() {
    // 测试 ParameterListNode
    std::string expected = "int a, int b";
    std::string actual = parameter_list->trans(nullptr);
    if (expected != actual) {
        std::cerr << "[FAIL] parameter_list: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_parameter_list failed\n");
    }
    clear_table();
}
void test_parameter_list_2() {
    // 测试 ParameterListNode (var)
    std::string expected = "int *a, int *b";
    std::string actual = parameter_list_2->trans(nullptr);
    if (expected != actual) {
        std::cerr << "[FAIL] parameter_list_2: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_parameter_list_2 failed\n");
    }
    clear_table();
}

void test_parameter_list_3() {
    // 测试 ParameterListNode (var)
    std::string expected = "int *a, int *b, int c, int d";
    std::string actual = parameter_list_3->trans(nullptr);
    if (expected != actual) {
        std::cerr << "[FAIL] parameter_list_3: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_parameter_list_3 failed\n");
    }
    clear_table();
}

void test_formal_parameter() {
    // 测试 FormalParameterNode
    std::string expected = "(int a, int b)";
    std::string actual = formal_parameter->trans(nullptr);
    if (expected != actual) {
        std::cerr << "[FAIL] formal_parameter: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_formal_parameter failed\n");
    }
    clear_table();
}
void test_formal_parameter_2() {
    // 测试 FormalParameterNode (var)
    std::string expected = "(int *a, int *b)";
    std::string actual = formal_parameter_2->trans(nullptr);
    if (expected != actual) {
        std::cerr << "[FAIL] formal_parameter_2: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_formal_parameter_2 failed\n");
    }
    clear_table();
}

void test_formal_parameter_3() {
    // 测试 FormalParameterNode (var)
    std::string expected = "(int *a, int *b, int c, int d)";
    std::string actual = formal_parameter_3->trans(nullptr);
    if (expected != actual) {
        std::cerr << "[FAIL] formal_parameter_3: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_formal_parameter_3 failed\n");
    }
    clear_table();
}

int main() {
    test_subprogram_head();
    test_subprogram_head_2();
    test_subprogram_body();
    test_subprogram();
    test_subprogram_declarations();
    test_value_parameter();
    test_var_parameter();
    test_parameter_node();
    test_parameter_node_2();
    test_parameter_list();
    test_parameter_list_2();
    test_parameter_list_3();
    test_formal_parameter();
    test_formal_parameter_2();
    test_formal_parameter_3();
    return 0;
}