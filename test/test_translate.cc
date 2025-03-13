#include "../translate.cc"
#include <iostream>
#include <iomanip>
FinalNode a(Token("a", TokenType::Identifier));
FinalNode integer(Token("integer", TokenType::Keyword));
FinalNode num_3(Token("3", TokenType::Number));

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
FactorNode factor_num(&num_3);
TermNode term_num(&factor_num);
SimpleExpressionNode Sexpression_num(&term_num);
ExpressionNode expression_num(&Sexpression_num);
IdVarpartNode id_varpart(nullptr);
VariableNode variable_a(&a, &id_varpart);
StatementNode statement_2(&variable_a, &expression_num);
void test_StatementNode() {
    std::string expected = "a = 3;\n";
    std::string actual = statement_2.trans();
    std::cout << "Test StatementNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}
BasicTypeNode basic_integer(&integer);
TypeNode type_integer(&basic_integer);
IdListNode id_a(&a);
VarDeclarationNode var_declaration(&id_a, &type_integer);
void test_VarDeclarationNode() {
    std::string expected = "int a;\n";
    std::string actual = var_declaration.trans();
    std::cout << "Test VarDeclarationNode: \n";
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Actual: " << actual << std::endl;
    bool result = expected == actual;
    std::cout << "Result: " << (result ? "PASSED" : "FAILED") << std::endl;
}
int main() {
    test_FinalNode();
    test_StatementNode();
    test_VarDeclarationNode();
    return 0;
}