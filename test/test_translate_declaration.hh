#ifndef TEST_TRANSLATE_DECLARATION_HH
#define TEST_TRANSLATE_DECLARATION_HH
#include "../translate.cc"
#include <iostream>
#include <iomanip>

// Basic tokens (FinalNode)
FinalNode* a = new FinalNode(Token("a", TokenType::Identifier));        // Identifier 'a'
FinalNode* b = new FinalNode(Token("b", TokenType::Identifier));        // Identifier 'b'
FinalNode* f = new FinalNode(Token("f", TokenType::Identifier));        // Function identifier 'f'
FinalNode* p = new FinalNode(Token("p", TokenType::Identifier));        // Procedure identifier 'p'
FinalNode* integer = new FinalNode(Token("integer", TokenType::Keyword)); // Keyword 'integer'
FinalNode* num_1 = new FinalNode(Token("1", TokenType::Number));        // Numeric constant '1'
FinalNode* num_3 = new FinalNode(Token("3", TokenType::Number));        // Numeric constant '3'
FinalNode* num_8 = new FinalNode(Token("8", TokenType::Number));        // Numeric constant '8'
FinalNode* minus = new FinalNode(Token("-", TokenType::Operator));      // Operator '-'
FinalNode* plus = new FinalNode(Token("+", TokenType::Operator));       // Operator '+'
FinalNode* b_char = new FinalNode(Token("b", TokenType::Char));         // Character 'b'

// Expression components
FactorNode* factor_num_3 = new FactorNode(num_3);                         // Factor containing value 3
TermNode* term_num_3 = new TermNode(factor_num_3);                        // Term containing factor with value 3
SimpleExpressionNode* Sexpression_num_3 = new SimpleExpressionNode(term_num_3);       // Simple expression with term value 3
ExpressionNode* expression_num = new ExpressionNode(Sexpression_num_3);       // Expression with value 3
ConstValueNode* const_value_num_3 = new ConstValueNode(num_3, minus);        // Constant value node with value -3
ConstValueNode* const_value_char_b = new ConstValueNode(b_char);              // Constant value node with value 'b'

// Variable related nodes
IdVarpartNode* id_varpart = new IdVarpartNode(nullptr);                     // Empty variable part
VariableNode* variable_a = new VariableNode(a, id_varpart);              // Variable reference to 'a'
StatementNode* statement_2 = new StatementNode(variable_a, expression_num); // Assignment statement 'a = 3'

// Type definitions
BasicTypeNode* basic_integer = new BasicTypeNode(integer);                 // Basic type 'integer'
BasicTypeNode* basic_integer_array = new BasicTypeNode(integer);           // Basic type 'integer' for array
TypeNode* type_integer = new TypeNode(basic_integer);                 // Type definition for 'integer'

// Array related nodes
PeriodNode* period = new PeriodNode(num_1, num_8);                     // Array range '1..8'
PeriodNode* period_2 = new PeriodNode(num_1, num_8, period);          // Multi-dimensional array range '1..8, 1..8'
TypeNode* type_integer_array = new TypeNode(basic_integer_array, period); // Array type 'array[1..8] of integer'
TypeNode* type_integer_array_2 = new TypeNode(basic_integer_array, period_2); // 2D array type 'array[1..8, 1..8] of integer'

// Variable declarations
IdListNode* id_a = new IdListNode(a);                                   // Identifier list containing 'a'
IdListNode* id_a_b = new IdListNode(b, id_a);                          // Identifier list containing 'b, a'
VarDeclarationNode* var_declaration = new VarDeclarationNode(id_a, type_integer); // Variable declaration 'a: integer'
VarDeclarationNode* var_declaration_array = new VarDeclarationNode(id_a_b, type_integer_array); // Variable declaration 'b, a: array[1..8] of integer'
VarDeclarationNode* var_declaration_array_2 = new VarDeclarationNode(id_a_b, type_integer_array_2); // Variable declaration 'b, a: array[1..8, 1..8] of integer'
ConstDeclarationNode* const_declaration_a = new ConstDeclarationNode(a, const_value_num_3); // Constant declaration 'a = -3'
ConstDeclarationsNode* const_declarations_1 = new ConstDeclarationsNode(const_declaration_a); // Constant declarations node
ConstDeclarationNode* const_declaration_a_b = new ConstDeclarationNode(b, const_value_char_b, const_declaration_a); // Constant declaration 'b = 'b'; a = -3'
ConstDeclarationsNode* const_declarations_2 = new ConstDeclarationsNode(const_declaration_a_b);// Constant declarations node 'const b = 'b'; a = -3'

// Parameter related nodes
ValueParameterNode* value_parameter = new ValueParameterNode(id_a_b, basic_integer); // Value parameter 'b, a: integer'
VarParameterNode* var_parameter = new VarParameterNode(value_parameter);       // VAR parameter 'var b, a: integer'
ParameterNode* parameter = new ParameterNode(value_parameter);              // Parameter node for value parameters
ParameterNode* parameter_2 = new ParameterNode(var_parameter);              // Parameter node for VAR parameters

// Subprogram related nodes
ParameterListNode* parameter_list = new ParameterListNode(parameter);           // Parameter list for function
ParameterListNode* parameter_list_2 = new ParameterListNode(parameter_2);       // Parameter list for procedure
FormalParameterNode* formal_parameter = new FormalParameterNode(parameter_list);  // Formal parameter section for function
FormalParameterNode* formal_parameter_2 = new FormalParameterNode(parameter_list_2); // Formal parameter section for procedure
SubprogramHeadNode* subprogram_head = new SubprogramHeadNode(f, formal_parameter, basic_integer); // Function header 'function f(b, a: integer): integer'
SubprogramHeadNode* subprogram_head_2 = new SubprogramHeadNode(p, formal_parameter_2); // Procedure header 'procedure p(var b, a: integer)'

#endif