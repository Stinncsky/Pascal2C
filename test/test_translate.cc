#include "test_translate_declaration.hh"

void test_FinalNode() {
    std::string expected_a = "a";
    std::string expected_integer = "int";
    std::string expected_num = "3";
    std::string actual_a = a->trans();
    std::string actual_integer = integer->trans();
    std::string actual_num = num_3->trans();
    std::cout << "Test FinalNode: \n";
    std::cout << std::setw(10) << "Expected: " << std::setw(10) << "Actual: " << std::endl;
    std::cout << std::setw(10) << expected_a << std::setw(10) << actual_a << std::endl;
    std::cout << std::setw(10) << expected_integer << std::setw(10) << actual_integer << std::endl;
    std::cout << std::setw(10) << expected_num << std::setw(10) << actual_num << std::endl;
    bool result = expected_a == actual_a && expected_integer == actual_integer && expected_num == actual_num;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}


int main() {
    test_FinalNode();
    return 0;
}