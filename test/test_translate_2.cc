#include "test_translate_declaration.hh"

void test_const_declarations_1(){
    std::string expected = "const int a = -3;\n";
    std::string result = const_declarations_1.trans();
    std::cout << "Test ConstDeclarationsNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << result << std::endl;
    bool res = expected == result;
    std::cout << "Result: " << (res ? "PASSED" : "FAILED") << std::endl;
}

void test_const_declarations_2(){
    std::string expected = "const char b = 'b';\nconst int a = -3;\n";
    std::string result = const_declarations_2.trans();
    std::cout << "Test ConstDeclarationsNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << result << std::endl;
    bool res = expected == result;
    std::cout << "Result: " << (res ? "PASSED" : "FAILED") << std::endl;
}
int main() {
    test_const_declarations_1();
    test_const_declarations_2();
    return 0;
}