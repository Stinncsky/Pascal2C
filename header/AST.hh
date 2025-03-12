#ifndef __AST_HH__
#define __AST_HH__

#include <vector>
#include "token.hh"

enum class NodeType{ // 节点类型
    Final, // 终结符

    // 非终结符
    programStruct,
    program_head,
    program_body,
    idList,
    const_declarations,
    var_declarations,
    subprogram_declarations,
    compound_statement,
    const_declaration,
    const_value,
    var_declaration,
    type,
    basic_type,
    period,
    subprogram,
    subprogram_head,
    subprogram_body,
    formal_parameter,
    parameter_list,
    parameter,
    var_parameter,
    value_parameter,
    statement_list,
    statement,
    variable,
    expression,
    procedure_call,
    else_part,
    variable_list,
    expression_list,
    id_varpart,
    simple_expression,
    term,
    factor,
};

class AST {
    public:
        NodeType type;

        AST(NodeType type = NodeType::Final){
            this->type = type;
        }
};

class FinalNode;
class ProgramStructNode;
class ProgramHeadNode;
class ProgramBodyNode;
class IdListNode;
class ConstDeclarationsNode;
class VarDeclarationsNode;
class SubprogramDeclarationsNode;
class CompoundStatementNode;
class ConstDeclarationNode;
class ConstValueNode;
class VarDeclarationNode;
class TypeNode;
class BasicTypeNode;
class PeriodNode;
class SubprogramNode;
class SubprogramHeadNode;
class SubprogramBodyNode;
class FormalParameterNode;
class ParameterListNode;
class ParameterNode;
class VarParameterNode;
class ValueParameterNode;
class StatementListNode;
class StatementNode;
class VariableNode;
class ExpressionNode;
class ProcedureCallNode;
class ElsePartNode;
class VariableListNode;
class ExpressionListNode;
class IdVarpartNode;
class SimpleExpressionNode;
class TermNode;
class FactorNode;

#endif