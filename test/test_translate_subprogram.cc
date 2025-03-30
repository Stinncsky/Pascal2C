#include "test_translate_declaration.hh"

//函数声明测试 function f(a, b: integer): integer
void test_subprogram_head(){
    std::string expected = "int f(int a, int b)";
    std::string actual = subprogram_head->trans();
    std::cout << "Test SubprogramHeadNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}

//过程声明&引用测试 procedure p(var a, b: integer)
void test_subprogram_head_2(){
    std::string expected = "void p(int *a, int *b)";
    std::string actual = subprogram_head_2->trans();
    std::cout << "Test SubprogramHeadNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}

int main() {
    test_subprogram_head();
    test_subprogram_head_2();
    return 0;
}