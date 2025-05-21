#include "../header/AST.hh"
#include "../AST.cc"

static std::string LINE_FORMAT_OUT = "";
void FinalNode::output() const{
    std::cout << "\""+token.property+"\"";
}

void ProgramHeadNode::output() const{
    std::cout << LINE_FORMAT_OUT + "ProgramHeadNode {\n";
    LINE_FORMAT_OUT += "\t";
    std::cout << LINE_FORMAT_OUT;
    id->output();
    std::cout << '\n';
    if (id_list != nullptr){
        id_list->output();
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void ProgramBodyNode::output() const{
    std::cout << LINE_FORMAT_OUT + "ProgramBodyNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (const_declarations != nullptr){
        const_declarations->output();
    }
    if (var_declarations != nullptr){
        var_declarations->output();
    }
    if (subprogram_declarations != nullptr){
        subprogram_declarations->output();
    }
    compound_statement->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void ProgramStructNode::output() const{
    std::cout << LINE_FORMAT_OUT + "ProgramStructNode {\n";
    LINE_FORMAT_OUT += "\t";
    program_head->output();
    program_body->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void IdListNode::output() const{
    std::cout << LINE_FORMAT_OUT + "IdListNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (id_list != nullptr){
        id_list->output();
    }
    std::cout << LINE_FORMAT_OUT;
    id->output();
    std::cout << '\n';
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void ConstDeclarationsNode::output() const{
    std::cout << LINE_FORMAT_OUT + "ConstDeclarationsNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (const_declaration != nullptr){
        const_declaration->output();
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void ConstDeclarationNode::output() const{
    std::cout << LINE_FORMAT_OUT + "ConstDeclarationNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (const_declaration != nullptr){
        const_declaration->output();
    }
    std::cout << LINE_FORMAT_OUT;
    id->output();
    std::cout << '\n';
    const_value->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void ConstValueNode::output() const{
    std::cout << LINE_FORMAT_OUT + "ConstValueNode {\n";
    LINE_FORMAT_OUT += "\t";
    std::cout << LINE_FORMAT_OUT;
    if (op != nullptr){
        op->output();
    }
    numletter->output();
    std::cout << '\n';
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void VarDeclarationsNode::output() const{
    std::cout << LINE_FORMAT_OUT + "VarDeclarationsNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (var_declaration != nullptr){
        var_declaration->output();
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void VarDeclarationNode::output() const{
    std::cout << LINE_FORMAT_OUT + "VarDeclarationNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (var_declaration != nullptr){
        var_declaration->output();
    }
    id_list->output();
    type->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void TypeNode::output() const{
    std::cout << LINE_FORMAT_OUT + "TypeNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (period != nullptr){
        period->output();
    }
    basic_type->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void BasicTypeNode::output() const{
    std::cout << LINE_FORMAT_OUT + "BasicTypeNode {\n";
    LINE_FORMAT_OUT += "\t";
    std::cout << LINE_FORMAT_OUT;
    basic_type->output();
    std::cout << '\n';
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void PeriodNode::output() const{
    std::cout << LINE_FORMAT_OUT + "PeriodNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (period != nullptr){
        period->output();
    }
    std::cout << LINE_FORMAT_OUT;
    num1->output();
    std::cout << ", ";
    num2->output();
    std::cout << '\n';
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void SubprogramDeclarationsNode::output() const{
    std::cout << LINE_FORMAT_OUT + "SubprogramDeclarationsNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (subprogram_declarations != nullptr){
        subprogram_declarations->output();
    }
    if (subprogram != nullptr){
        subprogram->output();
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void SubprogramNode::output() const{
    std::cout << LINE_FORMAT_OUT + "SubprogramNode {\n";
    LINE_FORMAT_OUT += "\t";
    subprogram_head->output();
    subprogram_body->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void SubprogramHeadNode::output() const{
    std::cout << LINE_FORMAT_OUT + "SubprogramHeadNode {\n";
    LINE_FORMAT_OUT += "\t";
    std::cout << LINE_FORMAT_OUT;
    id->output();
    std::cout << '\n';
    if (formal_parameter != nullptr){
        formal_parameter->output();
    }
    if (basic_type != nullptr){
        basic_type->output();
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void SubprogramBodyNode::output() const{
    std::cout << LINE_FORMAT_OUT + "SubprogramBodyNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (const_declarations != nullptr){
        const_declarations->output();
    }
    if (var_declarations != nullptr){
        var_declarations->output();
    }
    compound_statement->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void FormalParameterNode::output() const{
    std::cout << LINE_FORMAT_OUT + "FormalParameterNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (parameter_list != nullptr){
        parameter_list->output();
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void ParameterListNode::output() const{
    std::cout << LINE_FORMAT_OUT + "ParameterListNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (parameter_list != nullptr){
        parameter_list->output();
    }
    parameter->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void ParameterNode::output() const{
    std::cout << LINE_FORMAT_OUT + "ParameterNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (var_parameter != nullptr){
        var_parameter->output();
    }
    if (value_parameter != nullptr){
        value_parameter->output();
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void VarParameterNode::output() const{
    std::cout << LINE_FORMAT_OUT + "VarParameterNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (value_parameter != nullptr){
        value_parameter->output();
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void ValueParameterNode::output() const{
    std::cout << LINE_FORMAT_OUT + "ValueParameterNode {\n";
    LINE_FORMAT_OUT += "\t";
    id_list->output();
    basic_type->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void CompoundStatementNode::output() const{
    std::cout << LINE_FORMAT_OUT + "CompoundStatementNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (statement_list != nullptr){
        statement_list->output();
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void StatementListNode::output() const{
    std::cout << LINE_FORMAT_OUT + "StatementListNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (statement_list != nullptr){
        statement_list->output();
    }
    statement->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void StatementNode::output() const{
    std::cout << LINE_FORMAT_OUT + "StatementNode {\n";
    LINE_FORMAT_OUT += "\t";
    switch (this->kind){
        case 1:
            std::cout << LINE_FORMAT_OUT + "ε\n";
            break;
        case 2:
            variable->output();
            expression->output();
            break;
        case 3:
            std::cout << LINE_FORMAT_OUT;
            id->output();
            std::cout << '\n';
            expression->output();
            break;
        case 4:
            procedure_call->output();
            break;
        case 5:
            compound_statement->output();
            break;
        case 6:
            expression->output();
            statement->output();
            else_part->output();
            break;
        case 7:
            std::cout << LINE_FORMAT_OUT;
            id->output();
            std::cout << '\n';
            expression->output();
            expression_2->output();
            statement->output();
            break;
        case 8:
            std::cout << LINE_FORMAT_OUT;
            w_r->output();
            std::cout << '\n';
            variable_list->output();
            break;
        case 9:
            std::cout << LINE_FORMAT_OUT;
            w_r->output();
            std::cout << '\n';
            expression_list->output();
            break;
        case 10:
            expression->output();
            statement->output();
            break;
        case 11:
            std::cout << LINE_FORMAT_OUT;
            break_key->output();
            std::cout << '\n';
            break;
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void VariableListNode::output() const{
    std::cout << LINE_FORMAT_OUT + "VariableListNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (variable_list != nullptr){
        variable_list->output();
    }
    variable->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void ExpressionListNode::output() const{
    std::cout << LINE_FORMAT_OUT + "ExpressionListNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (expression_list != nullptr){
        expression_list->output();
    }
    expression->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void IdVarpartNode::output() const{
    std::cout << LINE_FORMAT_OUT + "IdVarpartNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (expression_list != nullptr){
        expression_list->output();
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void ProcedureCallNode::output() const{
    std::cout << LINE_FORMAT_OUT + "ProcedureCallNode {\n";
    LINE_FORMAT_OUT += "\t";
    std::cout << LINE_FORMAT_OUT;
    id->output();
    std::cout << '\n';
    if (expression_list != nullptr){
        expression_list->output();
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void ElsePartNode::output() const{
    std::cout << LINE_FORMAT_OUT + "ElsePartNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (statement != nullptr){
        statement->output();
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void VariableNode::output() const{
    std::cout << LINE_FORMAT_OUT + "VariableNode {\n";
    LINE_FORMAT_OUT += "\t";
    std::cout << LINE_FORMAT_OUT;
    id->output();
    std::cout << '\n';
    id_varpart->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void ExpressionNode::output() const{
    std::cout << LINE_FORMAT_OUT + "ExpressionNode {\n";
    LINE_FORMAT_OUT += "\t";
    simple_expression->output();
    if (relop != nullptr){
        std::cout << LINE_FORMAT_OUT;
        relop->output();
        std::cout << '\n';
        simple_expression_2->output();
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void SimpleExpressionNode::output() const{
    std::cout << LINE_FORMAT_OUT + "SimpleExpressionNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (simple_expression != nullptr){
        simple_expression->output();
    }
    if (addop != nullptr){
        std::cout << LINE_FORMAT_OUT;
        addop->output();
        std::cout << '\n';
    }
    term->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void TermNode::output() const{
    std::cout << LINE_FORMAT_OUT + "TermNode {\n";
    LINE_FORMAT_OUT += "\t";
    if (term != nullptr){
        term->output();
    }
    if (mulop != nullptr){
        std::cout << LINE_FORMAT_OUT;
        mulop->output();
        std::cout << '\n';
    }
    factor->output();
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

void FactorNode::output() const{
    std::cout << LINE_FORMAT_OUT + "FactorNode {\n";
    LINE_FORMAT_OUT += "\t";
    switch (this->kind){
        case 1:
            std::cout << LINE_FORMAT_OUT;
            num->output();
            std::cout << '\n';
            break;
        case 2:
            variable->output();
            break;
        case 3:
            expression->output();
            break;
        case 4:
            std::cout << LINE_FORMAT_OUT;
            id->output();
            std::cout << '\n';
            expression_list->output();
            break;
        case 5:
            std::cout << LINE_FORMAT_OUT;
            not_uminus->output();
            std::cout << '\n';
            factor->output();
            break;
    }
    LINE_FORMAT_OUT = LINE_FORMAT_OUT.substr(0, LINE_FORMAT_OUT.size() - 1);
    std::cout << LINE_FORMAT_OUT + "}\n";
}

