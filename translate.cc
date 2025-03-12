#include "./header/translate.hh"

#include "AST.cc"

std::string FinalNode::trans() const{
    switch(this->token.type){
        case TokenType::Number:
            return this->token.property;
        case TokenType::Char:
            return this->token.property;
        case TokenType::String:
            return this->token.property;
        case TokenType::Identifier:
            return this->token.property;
        case TokenType::Operator:
            if (this->token.property == ":=")
                return "=";
            else if (this->token.property == "<>")
                return "!=";
            else if (this->token.property == "=")
                return "==";
            else
                return this->token.property;
        case TokenType::Keyword:
            if (this->token.property == "integer")
                return "int";
            else if (this->token.property == "real")
                return "double";
            else if (this->token.property == "char")
                return "char";
            else if (this->token.property == "boolean")
                return "int";
            else if (this->token.property == "true")
                return "1";
            else if (this->token.property == "false")
                return "0";
            else if (this->token.property == "read")
                return "scanf";
            else if (this->token.property == "write")
                return "printf";
            else if (this->token.property == "and")
                return "&&";
            else if (this->token.property == "or")
                return "||";
            else if (this->token.property == "not")
                return "!";
            else if (this->token.property == "div")
                return "/";
            else if (this->token.property == "mod")
                return "%";
            else if (this->token.property == "nil")
                return "NULL";
            else
                return this->token.property;
        default:
            return "";
    }
}

std::string ProgramStructNode::trans() const{
    std::string res = "#include <stdio.h>\n";
    res += "#include <stdlib.h>\n";
    res += "#include <string.h>\n";
    res += program_head->trans();
    res += program_body->trans();
    return res;
}

std::string ProgramHeadNode::trans() const{
    return "";
}

std::string ProgramBodyNode::trans() const{
    std::string res = "";
    res += this->const_declarations->trans();
    res += this->var_declarations->trans();
    res += this->subprogram_declarations->trans();
    res += this->compound_statement->trans();
    return res;
}

std::string IdListNode::trans(const std::string type, const std::string tmp, const std::string end) const{
    std::string res = "";
    if(this->id_list != nullptr){
        res += this->id_list->trans(type, tmp, end);
    }
    res += type + this->id->trans() + tmp + end;
    return res;
}

std::string ConstDeclarationsNode::trans() const{
    std::string res = "";
    if(this->const_declaration != nullptr){
        res += this->const_declaration->trans();
    }
    return res;
}

std::string ConstDeclarationNode::trans() const{
    std::string res = "const ";
    if (this->const_value->numletter->token.type == TokenType::Number){
        if (this->const_value->numletter->token.property.find(".") != std::string::npos){
            res += "double ";
        } else {
            res += "int ";
        }
        res += this->id->trans() + " = ";
        res += this->const_value->trans() + ";\n";
    } else if (this->const_value->numletter->token.type == TokenType::Char){
        res += "char ";
        res += this->id->trans() + " = ";
        res += "\'" + this->const_value->trans() + "\';\n";
    } else if (this->const_value->numletter->token.type == TokenType::String){
        res += "char *";
        res += this->id->trans() + " = ";
        res += "\"" + this->const_value->trans() + "\";\n";
    }

    if (this->const_declaration != nullptr){
        res += this->const_declaration->trans();
    }

    return res;
}

std::string ConstValueNode::trans() const{
    std::string res = "";
    if (this->op != nullptr){
        res += this->op->trans();
    }
    res += this->numletter->trans();
    return res;
}

std::string VarDeclarationsNode::trans() const{
    std::string res = "";
    if(this->var_declaration != nullptr){
        res += this->var_declaration->trans();
    }
    return res;
}

std::string VarDeclarationNode::trans() const{
    std::string res = "";
    if (this->var_declaration != nullptr){
        res += this->var_declaration->trans();
    }
    std::string type = this->type->trans();
    std::string tmp;
    if (this->type->period != nullptr){
        tmp = this->type->period->trans();
    }
    res += this->id_list->trans(type, tmp, ";\n");
    return res;
}

std::string TypeNode::trans() const{
    std::string res = "";
    res += this->basic_type->trans();
    return res;
}

std::string BasicTypeNode::trans() const{
    std::string res = "";
    res += this->basic_type->trans();
    return res;
}

std::string PeriodNode::trans() const{
    std::string res = "";
    if (this->period != nullptr){
        res += this->period->trans();
    }
    int start = std::stoi(this->num1->trans());
    int end = std::stoi(this->num2->trans());
    int len = end - start + 1;
    res += "[" + std::to_string(len) + "]";
    return res;
}

std::string SubprogramDeclarationsNode::trans() const{
    std::string res = "";
    if (this->subprogram != nullptr){
        res += this->subprogram_declarations->trans();
        res += this->subprogram->trans();
    }
    return res;
}

std::string SubprogramNode::trans() const{
    std::string res = "";
    res += this->subprogram_head->trans();
    res += this->subprogram_body->trans();
    return res;
}

std::string SubprogramHeadNode::trans() const{
    std::string res = "";
    if (this->basic_type == nullptr){
        res += "void ";
    } else {
        res += this->basic_type->trans() + " ";
    }
    res += this->id->trans();
    res += this->formal_parameter->trans();
    return res;
}

std::string FormalParameterNode::trans() const{
    std::string res = "(";
    if (this->parameter_list != nullptr){
        res += this->parameter_list->trans();
    }
    res += ")";
    return res;
}

std::string ParameterListNode::trans() const{
    std::string res = "";
    if (this->parameter_list != nullptr){
        res += this->parameter_list->trans();
        res += ", ";
    }
    res += this->parameter->trans();
    return res;
}

std::string ParameterNode::trans() const{
    std::string res = "";
    if (this->var_parameter != nullptr){
        res += this->var_parameter->trans();
    } else if (this->value_parameter != nullptr){
        res += this->value_parameter->trans();
    }
    return res;
}

std::string VarParameterNode::trans() const{
    std::string res = "";
    res += this->value_parameter->trans(true);
    return res;
}

std::string ValueParameterNode::trans(const bool is_ptr) const{
    std::string res = "";
    std::string type = this->basic_type->trans();
    if (is_ptr){
        type += "*";
    }
    res += this->id_list->trans(type, "", ", ");
    res = res.substr(0, res.size() - 2);
    return res;
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
