#include "test_translate_declaration.hh"
void test_StatementNode() {
    std::string expected = "a = 3;\n";
    std::string actual = statement_2->trans();
    std::cout << "Test StatementNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}

int main(){
    test_StatementNode();
    return 0;
}