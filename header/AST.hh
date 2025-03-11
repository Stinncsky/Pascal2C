#ifndef __AST_HH__
#define __AST_HH__

#include <vector>
#include "token.hh"

enum class NoteType{ // 节点类型
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
        NoteType type;

        AST(NoteType type = NoteType::Final){
            this->type = type;
        }
};

#endif