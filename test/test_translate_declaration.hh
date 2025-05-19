#ifndef TEST_TRANSLATE_DECLARATION_HH
#define TEST_TRANSLATE_DECLARATION_HH
#include "../translate.cc"
#include <iostream>
#include <iomanip>
#include <cassert>

// ================== 基本 Token/FinalNode 声明 ==================
FinalNode* a = new FinalNode(Token("a", TokenType::Identifier)); // Pascal: a
FinalNode* b = new FinalNode(Token("b", TokenType::Identifier)); // Pascal: b
FinalNode* f = new FinalNode(Token("f", TokenType::Identifier)); // Pascal: f
FinalNode* p = new FinalNode(Token("p", TokenType::Identifier)); // Pascal: p
FinalNode* integer = new FinalNode(Token("integer", TokenType::Keyword)); // Pascal: integer
FinalNode* num_1 = new FinalNode(Token("1", TokenType::Number)); // Pascal: 1
FinalNode* num_3 = new FinalNode(Token("3", TokenType::Number)); // Pascal: 3
FinalNode* num_8 = new FinalNode(Token("8", TokenType::Number)); // Pascal: 8
FinalNode* minus = new FinalNode(Token("-", TokenType::Operator)); // Pascal: -
FinalNode* plus = new FinalNode(Token("+", TokenType::Operator)); // Pascal: +
FinalNode* b_char = new FinalNode(Token("b", TokenType::Char)); // Pascal: 'b'
FinalNode* mulop = new FinalNode(Token("*", TokenType::Operator)); // Pascal: *
FinalNode* divop = new FinalNode(Token("/", TokenType::Operator)); // Pascal: /
FinalNode* relop_lt = new FinalNode(Token("<", TokenType::Operator)); // Pascal: <
FinalNode* addop_plus = new FinalNode(Token("+", TokenType::Operator)); // Pascal: +
FinalNode* not_kw = new FinalNode(Token("not", TokenType::Keyword)); // Pascal: not
FinalNode* uminus_op = new FinalNode(Token("-", TokenType::Operator)); // Pascal: -
FinalNode* read_kw = new FinalNode(Token("read", TokenType::Keyword)); // Pascal: read
FinalNode* write_kw = new FinalNode(Token("write", TokenType::Keyword)); // Pascal: write

// ================== 基本表达式节点 ==================
FactorNode* factor_num_3 = new FactorNode(num_3); // Pascal: 3
FactorNode* factor_num_8 = new FactorNode(num_8); // Pascal: 8
TermNode* term_num_3 = new TermNode(factor_num_3); // Pascal: 3
TermNode* term_num_8 = new TermNode(factor_num_8); // Pascal: 8
SimpleExpressionNode* Sexpression_num_3 = new SimpleExpressionNode(term_num_3); // Pascal: 3
ExpressionNode* expression_num = new ExpressionNode(Sexpression_num_3); // Pascal: 3

// ================== 变量相关节点 ==================
IdVarpartNode* id_varpart_empty = new IdVarpartNode(nullptr); // Pascal: a
VariableNode* variable_a = new VariableNode(a, id_varpart_empty); // Pascal: a
VariableNode* variable_b = new VariableNode(b, id_varpart_empty); // Pascal: b

// ================== 赋值语句相关节点 ==================
StatementNode* statement_2 = new StatementNode(variable_a, expression_num); // Pascal: a := 3;

// ================== 常量声明相关节点 ==================
ConstValueNode* const_value_num_3 = new ConstValueNode(num_3, minus); // Pascal: -3
ConstValueNode* const_value_char_b = new ConstValueNode(b_char); // Pascal: 'b'
ConstDeclarationNode* const_declaration_a = new ConstDeclarationNode(a, const_value_num_3); // Pascal: a = -3
ConstDeclarationsNode* const_declarations_1 = new ConstDeclarationsNode(const_declaration_a); // Pascal: const a = -3;
ConstDeclarationNode* const_declaration_a_b = new ConstDeclarationNode(b, const_value_char_b, const_declaration_a); // Pascal: b = 'b'; a = -3
ConstDeclarationsNode* const_declarations_2 = new ConstDeclarationsNode(const_declaration_a_b); // Pascal: const b = 'b'; a = -3;

// ================== 类型与数组相关节点 ==================
BasicTypeNode* basic_integer = new BasicTypeNode(integer); // Pascal: integer
TypeNode* type_integer = new TypeNode(basic_integer); // Pascal: integer
PeriodNode* period = new PeriodNode(num_1, num_8); // Pascal: 1..8
PeriodNode* period_2 = new PeriodNode(num_1, num_8, period); // Pascal: 1..8, 1..8
TypeNode* type_integer_array = new TypeNode(basic_integer, period); // Pascal: array[1..8] of integer
TypeNode* type_integer_array_2 = new TypeNode(basic_integer, period_2); // Pascal: array[1..8,1..8] of integer

// ================== 变量声明相关节点 ==================
IdListNode* id_a = new IdListNode(a); // Pascal: a
IdListNode* id_a_b = new IdListNode(b, id_a); // Pascal: b, a
VarDeclarationNode* var_declaration = new VarDeclarationNode(id_a, type_integer); // Pascal: var a: integer;
VarDeclarationNode* var_declaration_array = new VarDeclarationNode(id_a_b, type_integer_array); // Pascal: var b, a: array[1..8] of integer;
VarDeclarationNode* var_declaration_array_2 = new VarDeclarationNode(id_a_b, type_integer_array_2); // Pascal: var b, a: array[1..8,1..8] of integer

// ================== 参数与子程序相关节点 ==================
ValueParameterNode* value_parameter = new ValueParameterNode(id_a_b, basic_integer); // Pascal: a, b: integer
VarParameterNode* var_parameter = new VarParameterNode(value_parameter); // Pascal: var a, b: integer
ParameterNode* parameter = new ParameterNode(value_parameter); // Pascal: a, b: integer
ParameterNode* parameter_2 = new ParameterNode(var_parameter); // Pascal: var a, b: integer
ParameterListNode* parameter_list = new ParameterListNode(parameter); // Pascal: (a, b: integer)
ParameterListNode* parameter_list_2 = new ParameterListNode(parameter_2); // Pascal: (var a, b: integer)
FormalParameterNode* formal_parameter = new FormalParameterNode(parameter_list); // Pascal: (a, b: integer)
FormalParameterNode* formal_parameter_2 = new FormalParameterNode(parameter_list_2); // Pascal: (var a, b: integer)
SubprogramHeadNode* subprogram_head = new SubprogramHeadNode(f, formal_parameter, basic_integer); // Pascal: function f(a, b: integer): integer
SubprogramHeadNode* subprogram_head_2 = new SubprogramHeadNode(p, formal_parameter_2); // Pascal: procedure p(var a, b: integer)

// 混合参数：var a, b: integer; c, d: integer
IdListNode* id_c = new IdListNode(new FinalNode(Token("c", TokenType::Identifier))); // Pascal: c
IdListNode* id_d = new IdListNode(new FinalNode(Token("d", TokenType::Identifier)), id_c); // Pascal: d, c
ValueParameterNode* value_parameter_cd = new ValueParameterNode(id_d, basic_integer); // Pascal: c, d: integer
ParameterNode* parameter_var_ab = new ParameterNode(var_parameter); // Pascal: var a, b: integer
ParameterNode* parameter_val_cd = new ParameterNode(value_parameter_cd); // Pascal: c, d: integer
ParameterListNode* parameter_list_3 = new ParameterListNode(parameter_val_cd, new ParameterListNode(parameter_var_ab)); // Pascal: (var a, b: integer; c, d: integer)
FormalParameterNode* formal_parameter_3 = new FormalParameterNode(parameter_list_3); // Pascal: (var a, b: integer; c, d: integer)

// ================== FactorNode 测试相关声明 ==================
FactorNode* factor_var_b = new FactorNode(variable_b); // Pascal: b
FactorNode* factor_paren_expr = new FactorNode(expression_num); // Pascal: (3)
ExpressionListNode* expr_list_single = new ExpressionListNode(expression_num); // Pascal: (3)
FactorNode* factor_func_call = new FactorNode(f, expr_list_single); // Pascal: f(3)
FactorNode* factor_not_num = new FactorNode(not_kw, factor_num_8); // Pascal: not 8
FactorNode* factor_uminus_var = new FactorNode(uminus_op, factor_var_b); // Pascal: -b

// ================== TermNode 测试相关声明 ==================
TermNode* term_3_mul_8 = new TermNode(factor_num_8, term_num_3, mulop); // Pascal: 3 * 8
TermNode* term_8_div_3 = new TermNode(factor_num_3, term_num_8, divop); // Pascal: 8 / 3

// ================== ExpressionNode/SimpleExpressionNode/ExpressionListNode 测试相关声明 ==================
SimpleExpressionNode* right_simple_expr = new SimpleExpressionNode(term_num_3); // Pascal: 3
ExpressionNode* expression_relop = new ExpressionNode(Sexpression_num_3, relop_lt, right_simple_expr); // Pascal: 3 < 3
TermNode* term_8 = new TermNode(factor_num_8); // Pascal: 8
SimpleExpressionNode* simple_expression_add = new SimpleExpressionNode(term_8, Sexpression_num_3, addop_plus); // Pascal: 8 + 3
ExpressionListNode* expression_list_single = new ExpressionListNode(expression_num); // Pascal: (3)
ExpressionListNode* expression_list_multi = new ExpressionListNode(expression_num, expression_list_single); // Pascal: (3, 3)

// ================== StatementNode 测试相关声明 ==================
ProcedureCallNode* proc_call_p = new ProcedureCallNode(p); // Pascal: p
StatementNode* statement_proc_call = new StatementNode(proc_call_p); // Pascal: p;
StatementListNode* stmt_list_single = new StatementListNode(statement_2); // Pascal: a := 3;
CompoundStatementNode* compound_stmt = new CompoundStatementNode(stmt_list_single); // Pascal: begin a := 3; end
StatementNode* statement_compound = new StatementNode(compound_stmt); // Pascal: begin a := 3; end
ElsePartNode* else_part_empty = new ElsePartNode(); // Pascal: (无 else)
StatementNode* statement_if = new StatementNode(expression_relop, statement_2, else_part_empty); // Pascal: if 3 < 3 then a := 3;
StatementNode* statement_for = new StatementNode(a, expression_num, expression_num, statement_2); // Pascal: for a := 3 to 3 do a := 3;
StatementNode* statement_while = new StatementNode(expression_relop, statement_2); // Pascal: while 3 < 3 do a := 3;

// if-else 语句 if (3<3) a = 3; else b = 3;
ElsePartNode* else_part_b = new ElsePartNode(new StatementNode(variable_b, expression_num)); // Pascal: else b := 3;
StatementNode* statement_if_else = new StatementNode(expression_relop, statement_2, else_part_b); // Pascal: if 3 < 3 then a := 3 else b := 3;
VariableListNode* variable_list_a = new VariableListNode(variable_a); // Pascal: a
StatementNode* statement_read = new StatementNode(read_kw, variable_list_a); // Pascal: read(a);
StatementNode* statement_write = new StatementNode(write_kw, expression_list_single); // Pascal: write(3);
StatementNode* statement_b_assign = new StatementNode(variable_b, expression_num); // Pascal: b := 3;
StatementListNode* statement_list = new StatementListNode(statement_b_assign, new StatementListNode(statement_2)); // Pascal: b := 3; a := 3;
CompoundStatementNode* compound_statement_multi = new CompoundStatementNode(statement_list); // Pascal: begin b := 3; a := 3; end

// ================== Subprogram 测试相关声明 ==================
SubprogramBodyNode* subprogram_body = new SubprogramBodyNode(new ConstDeclarationsNode(), new VarDeclarationsNode(), new CompoundStatementNode(new StatementListNode(statement_2))); // Pascal: const ...; var ...; begin a := 3; end
SubprogramNode* subprogram = new SubprogramNode(subprogram_head, subprogram_body); // Pascal: function f(a, b: integer): integer; ...
SubprogramNode* subprogram_2 = new SubprogramNode(subprogram_head_2, subprogram_body); // Pascal: procedure p(var a, b: integer); ...
SubprogramDeclarationsNode* subprogram_declarations = new SubprogramDeclarationsNode(new SubprogramDeclarationsNode(new SubprogramDeclarationsNode(), subprogram), subprogram_2); // Pascal: 多个子程序声明

// ================== Program 相关节点 ==================
ProgramHeadNode* program_head = new ProgramHeadNode(a); // Pascal: program a
ProgramBodyNode* program_body = new ProgramBodyNode(const_declarations_1, new VarDeclarationsNode(var_declaration), new SubprogramDeclarationsNode(), new CompoundStatementNode(new StatementListNode(statement_2))); // Pascal: const ...; var ...; begin a := 3; end
ProgramStructNode* program_struct = new ProgramStructNode(program_head, program_body); // Pascal: program a; ...

// ================== 语义错误相关声明 ==================
// 
ProcedureCallNode* proc_call = new ProcedureCallNode(p, expression_list_multi); // Pascal: p(3, 3)
// test_type_mismatch 用到 b_char
StatementNode* stmt = new StatementNode(variable_a, new ExpressionNode(new SimpleExpressionNode(new TermNode(new FactorNode(b_char))))); // Pascal: a := 'b';
// Pascal: a[-1] := 3; // 数组下标为负数
FinalNode* minus_one = new FinalNode(Token("-1", TokenType::Number)); // Pascal: -1
ExpressionNode* expr_minus_one = new ExpressionNode(new SimpleExpressionNode(new TermNode(new FactorNode(minus_one)))); // Pascal: -1
ExpressionListNode* expr_list_minus_one = new ExpressionListNode(expr_minus_one); // Pascal: [-1]
IdVarpartNode* id_varpart_minus_one = new IdVarpartNode(expr_list_minus_one); // Pascal: a[-1]
VariableNode* arr_var_minus_one = new VariableNode(a, id_varpart_minus_one); // Pascal: a[-1]
StatementNode* stmt_arr_minus_one = new StatementNode(arr_var_minus_one, expression_num); // Pascal: a[-1] := 3;
// Pascal: a[3] := 3; // 数组维度不匹配（如声明为二维，使用一维）
FinalNode* three = new FinalNode(Token("3", TokenType::Number)); // Pascal: 3
ExpressionNode* expr_three = new ExpressionNode(new SimpleExpressionNode(new TermNode(new FactorNode(three)))); // Pascal: 3
ExpressionListNode* expr_list_three = new ExpressionListNode(expr_three); // Pascal: [3]
IdVarpartNode* id_varpart_three = new IdVarpartNode(expr_list_three); // Pascal: a[3]
VariableNode* arr_var_three = new VariableNode(a, id_varpart_three); // Pascal: a[3]
StatementNode* stmt_arr_three = new StatementNode(arr_var_three, expression_num); // Pascal: a[3] := 3;

// ================== 工具函数和全局变量 ==================
extern Table t;
void clear_table() { t.table.clear(); t.now_funcid = nullptr; }

#endif