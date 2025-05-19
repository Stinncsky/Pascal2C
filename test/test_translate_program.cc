#include <cassert>
#include "test_translate_declaration.hh"

// 1. 测试 ProgramHeadNode
void test_program_head() {
    std::string expected = "";
    std::string actual = program_head->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] program_head: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_program_head failed\n");
    }
    clear_table();
}
// 2. 测试 ProgramBodyNode
void test_program_body() {
    std::string expected = "const int a = -3;\nint a;\nint main(){\n\ta = 3;\n\treturn 0;\n}";
    std::string actual = program_body->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] program_body: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_program_body failed\n");
    }
    clear_table();
}
// 3. 测试 ProgramStructNode
void test_program_struct() {
    std::string expected = "#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\nconst int a = -3;\nint a;\nint main(){\n\ta = 3;\n\treturn 0;\n}";
    std::string actual = program_struct->trans();
    if (expected != actual) {
        std::cerr << "[FAIL] program_struct: expected=[\n" << expected << "] actual=[\n" << actual << "]\n";
        fprintf(stderr, "test_program_struct failed\n");
    }
    clear_table();
}
int main() {
    test_program_head();
    test_program_body();
    test_program_struct();
    return 0;
}