#include "test_translate_declaration.hh"

extern Table t;

void test_VarDeclarationNode() {
    std::string expected = "int a;\n";
    std::string actual = var_declaration->trans();
    std::cout << "Test VarDeclarationNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}
//数组测试

void test_array_VarDeclarationNode() {
    std::string expected = "int a[8];\nint b[8];\n";
    std::string actual = var_declaration_array->trans();
    std::cout << "Test VarDeclarationNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}
//多维数组测试 array [1..8, 1..8] of integer

void test_array_VarDeclarationNode_2(){
    std::string expected = "int a[8][8];\nint b[8][8];\n";
    std::string actual = var_declaration_array_2->trans();
    std::cout << "Test VarDeclarationNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}

int main() {
    //test_VarDeclarationNode();
    //test_array_VarDeclarationNode();
    test_array_VarDeclarationNode_2();
    t.output();
    //cleanup();
    return 0;
}