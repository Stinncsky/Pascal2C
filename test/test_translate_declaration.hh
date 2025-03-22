#ifndef TEST_TRANSLATE_DECLARATION_HH
#define TEST_TRANSLATE_DECLARATION_HH
#include "../translate.cc"
#include <iostream>
#include <iomanip>

// Basic tokens (FinalNode)
FinalNode a(Token("a", TokenType::Identifier));        // Identifier 'a'
FinalNode b(Token("b", TokenType::Identifier));        // Identifier 'b'
FinalNode f(Token("f", TokenType::Identifier));        // Function identifier 'f'
FinalNode p(Token("p", TokenType::Identifier));        // Procedure identifier 'p'
FinalNode integer(Token("integer", TokenType::Keyword)); // Keyword 'integer'
FinalNode num_1(Token("1", TokenType::Number));        // Numeric constant '1'
FinalNode num_3(Token("3", TokenType::Number));        // Numeric constant '3'
FinalNode num_8(Token("8", TokenType::Number));        // Numeric constant '8'

// Expression components
FactorNode factor_num_3(&num_3);                         // Factor containing value 3
TermNode term_num_3(&factor_num_3);                        // Term containing factor with value 3
SimpleExpressionNode Sexpression_num_3(&term_num_3);       // Simple expression with term value 3
ExpressionNode expression_num(&Sexpression_num_3);       // Expression with value 3

// Variable related nodes
IdVarpartNode id_varpart(nullptr);                     // Empty variable part
VariableNode variable_a(&a, &id_varpart);              // Variable reference to 'a'
StatementNode statement_2(&variable_a, &expression_num); // Assignment statement 'a = 3'

// Type definitions
BasicTypeNode basic_integer(&integer);                 // Basic type 'integer'
BasicTypeNode basic_integer_array(&integer);           // Basic type 'integer' for array
TypeNode type_integer(&basic_integer);                 // Type definition for 'integer'

// Array related nodes
PeriodNode period(&num_1, &num_8);                     // Array range '1..8'
PeriodNode period_2(&num_1, &num_8, &period);          // Multi-dimensional array range '1..8, 1..8'
TypeNode type_integer_array(&basic_integer_array, &period); // Array type 'array[1..8] of integer'
TypeNode type_integer_array_2(&basic_integer_array, &period_2); // 2D array type 'array[1..8, 1..8] of integer'

// Variable declarations
IdListNode id_a(&a);                                   // Identifier list containing 'a'
IdListNode id_a_b(&b, &id_a);                          // Identifier list containing 'b, a'
VarDeclarationNode var_declaration(&id_a, &type_integer); // Variable declaration 'a: integer'
VarDeclarationNode var_declaration_array(&id_a_b, &type_integer_array); // Variable declaration 'b, a: array[1..8] of integer'
VarDeclarationNode var_declaration_array_2(&id_a_b, &type_integer_array_2); // Variable declaration 'b, a: array[1..8, 1..8] of integer'

// Parameter related nodes
ValueParameterNode value_parameter(&id_a_b, &basic_integer); // Value parameter 'b, a: integer'
VarParameterNode var_parameter(&value_parameter);       // VAR parameter 'var b, a: integer'
ParameterNode parameter(&value_parameter);              // Parameter node for value parameters
ParameterNode parameter_2(&var_parameter);              // Parameter node for VAR parameters

// Subprogram related nodes
ParameterListNode parameter_list(&parameter);           // Parameter list for function
ParameterListNode parameter_list_2(&parameter_2);       // Parameter list for procedure
FormalParameterNode formal_parameter(&parameter_list);  // Formal parameter section for function
FormalParameterNode formal_parameter_2(&parameter_list_2); // Formal parameter section for procedure
SubprogramHeadNode subprogram_head(&f, &formal_parameter, &basic_integer); // Function header 'function f(b, a: integer): integer'
SubprogramHeadNode subprogram_head_2(&p, &formal_parameter_2); // Procedure header 'procedure p(var b, a: integer)'

#endif