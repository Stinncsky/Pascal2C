#include "test_translate_declaration.hh"

void test_FinalNode() {
    std::string expected_a = "a";
    std::string expected_integer = "int";
    std::string expected_num = "3";
    std::string actual_a = a.trans();
    std::string actual_integer = integer.trans();
    std::string actual_num = num_3.trans();
    std::cout << "Test FinalNode: \n";
    std::cout << std::setw(10) << "Expected: " << std::setw(10) << "Actual: " << std::endl;
    std::cout << std::setw(10) << expected_a << std::setw(10) << actual_a << std::endl;
    std::cout << std::setw(10) << expected_integer << std::setw(10) << actual_integer << std::endl;
    std::cout << std::setw(10) << expected_num << std::setw(10) << actual_num << std::endl;
    bool result = expected_a == actual_a && expected_integer == actual_integer && expected_num == actual_num;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}

void test_StatementNode() {
    std::string expected = "a = 3;\n";
    std::string actual = statement_2.trans();
    std::cout << "Test StatementNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}

void test_VarDeclarationNode() {
    std::string expected = "int a;\n";
    std::string actual = var_declaration.trans();
    std::cout << "Test VarDeclarationNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}
//数组测试

void test_array_VarDeclarationNode() {
    std::string expected = "int a[8];\nint b[8];\n";
    std::string actual = var_declaration_array.trans();
    std::cout << "Test VarDeclarationNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}
//多维数组测试 array [1..8, 1..8] of integer

void test_array_VarDeclarationNode_2(){
    std::string expected = "int a[8][8];\nint b[8][8];\n";
    std::string actual = var_declaration_array_2.trans();
    std::cout << "Test VarDeclarationNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}
//函数声明测试 function f(a, b: integer): integer

void test_subprogram_head(){
    std::string expected = "int f(int a, int b)";
    std::string actual = subprogram_head.trans();
    std::cout << "Test SubprogramHeadNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}
//过程声明&引用测试 procedure p(var a, b: integer)

void test_subprogram_head_2(){
    std::string expected = "void p(int *a, int *b)";
    std::string actual = subprogram_head_2.trans();
    std::cout << "Test SubprogramHeadNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}
int main() {
    test_FinalNode();
    test_StatementNode();
    test_VarDeclarationNode();
    test_array_VarDeclarationNode();
    test_array_VarDeclarationNode_2();
    test_subprogram_head();
    test_subprogram_head_2();
    return 0;
}