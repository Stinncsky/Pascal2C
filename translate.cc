#include "./header/translate.hh"

#include "AST.cc"

std::string FinalNode::trans() const {
    return token.property;  // 有待修改
}

std::string SubprogramBodyNode::trans() const {
    std::string com_state = this->compound_statement->trans();
    if (com_state != "") {
        com_state.erase(0, 1);
        return "{\n" + this->const_declarations->trans() + this->var_declarations->trans() + com_state;
    } 
	else
        return "";
}
std::string CompoundStatementNode::trans() const {
    if (this->statement_list->trans() != "")
        return "{\n" + this->statement_list->trans() + "}\n";
    else
        return "";
}

std::string StatementListNode::trans() const {
    std::string result = "";
    if (this->statement_list != nullptr) {
        result += this->statement_list->trans();
    }
    result += this->statement->trans();
    return result;
}

std::string StatementNode::trans() const {
    if (this->kind == 1)
        return "\n";
    else if (this->kind == 2)
        return this->variable->trans() + " = " + this->expression->trans() + ";\n";
    else if (this->kind == 3)
        return "return " + this->expression->trans() + ";\n";
    else if (this->kind == 4)
        return this->procedure_call->trans() + ";\n";
    else if (this->kind == 5)
        return this->compound_statement->trans();
    else if (this->kind == 6) {  // 后面用不用考虑变成else if的形式，更工整但可能不是很必要？
        return "if (" + this->expression->trans() + ") {\n" +
                     this->statement->trans() + "}" + this->else_part->trans() + "\n";
    } 
    else if (this->kind == 7) {
        std::string i = this->id->trans();
        return "for (" + i + " = " + this->expression->trans() + "; " + i +
                     " <= " + this->expression_2->trans() + "; " + i + "++) {\n" +
                     this->statement->trans() + "}\n";
    } 
    else if (this->kind == 8) {
        std::string var_list = this->variable_list->trans();
        while (var_list != "") {
            int pos = var_list.find(',');
            std::string var;
            if (pos == std::string::npos) {
                var = var_list;
                var_list = "";  // 清空var_list
            } 
			else {
                var = var_list.substr(0, pos);
                var_list.erase(0, pos + 1);
            }
        }
    } 
    else if (this->kind == 9)
        return "write(" + this->expression_list->trans() + ");\n";
}

std::string VariableListNode::trans() const {
    std::string result = "";
    if (this->variable_list != nullptr) {
        result += this->variable_list->trans();
    }
    result += this->variable->trans();
    return result;
}

std::string VariableNode::trans() const {
    return this->id->trans() + this->id_varpart->trans();
}

std::string IdVarpartNode::trans() const {
    if (this->expression_list == nullptr) return "";
    return "[" + this->expression_list->trans() + "]";
}

std::string ProcedureCallNode::trans() const {
    if (this->expression_list == nullptr)
        return this->id->trans() + "()";
    else
        return this->id->trans() + "(" + this->expression_list->trans() + ")";
}

std::string ElsePartNode::trans() const {
    if (this->statement == nullptr)
        return "";
    else
        return " else {\n" + this->statement->trans() + "}";
}

std::string ExpressionListNode::trans() const {
    if (this->expression_list == nullptr)
        return this->expression->trans();
    else
        return this->expression->trans() + ", " + this->expression_list->trans();
}

std::string ExpressionNode::trans() const {
    if (this->relop == nullptr)
        return this->simple_expression->trans();
    else
        return this->simple_expression->trans() + " " + this->relop->trans() + " " + this->simple_expression_2->trans();
}

std::string SimpleExpressionNode::trans() const {
    if (this->addop == nullptr)
        return this->simple_expression->trans();
    else
        return this->simple_expression->trans() + " " + this->addop->trans() + " " + this->term->trans();
}

std::string TermNode::trans() const {
    if (this->mulop == nullptr)
        return this->term->trans();
    else
        return this->term->trans() + " " + this->mulop->trans() + " " + this->factor->trans();
}

std::string FactorNode::trans() const {
    if (this->kind == 1)
        return this->num->trans();
    else if (this->kind == 2)
        return this->variable->trans();
    else if (this->kind == 3)
        return "(" + this->expression_list->trans() + ")";
    else if (this->kind == 4)
        return this->id->trans() + "(" + this->expression_list->trans() + ")";
    else if (this->kind == 5)
        return "!" + this->factor->trans();
    else if (this->kind == 6)
        return "-" + this->factor->trans();
}
