#include "./header/translate.hh"

#include "AST.cc"
Table t;
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
    res += "int main()";
    res += this->compound_statement->trans();
    return res;
}

std::string IdListNode::trans(const std::string type, const std::string tmp, const std::string end, const std::vector<int> *dim, const bool is_cite) const{
    std::string res = "";
    if(this->id_list != nullptr){
        res += this->id_list->trans(type, tmp, end, dim, is_cite);
    }
    res += type + this->id->trans() + tmp + end;
    if (is_cite){
        auto info = t.table[*id];
        info = std::make_tuple(std::get<0>(info), 1, std::get<2>(info));
        t.table[*id] = info;
    } else if (type == "int " || type == "double "){
        t.table[*(this->id)] = std::make_tuple(type == "int " ? 0 : 1, 0, *dim);
    } else if (type == "char "){
        t.table[*(this->id)] = std::make_tuple(2, 0, *dim);
    } else if (type == "string "){
        t.table[*(this->id)] = std::make_tuple(3, 0, *dim);
    }
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
    int type = 0;
    if (this->const_value->numletter->token.type == TokenType::Number){
        if (this->const_value->numletter->token.property.find(".") != std::string::npos){
            res += "double ";
            type = 1;
        } else {
            res += "int ";
            type = 0;
        }
        t.table[*(this->id)] = std::make_tuple(type, 0, std::vector<int>());
        res += this->id->trans() + " = ";
        res += this->const_value->trans() + ";\n";
    } else if (this->const_value->numletter->token.type == TokenType::Char){
        res += "char ";
        t.table[*(this->id)] = std::make_tuple(2, 0, std::vector<int>());
        res += this->id->trans() + " = ";
        res += "\'" + this->const_value->trans() + "\';\n";
    } else if (this->const_value->numletter->token.type == TokenType::String){
        res += "char *";
        t.table[*(this->id)] = std::make_tuple(3, 0, std::vector<int>());
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
    std::string type = this->type->trans() + " ";
    std::string tmp;
    std::vector<int> dim;
    if (this->type->period != nullptr){
        tmp = this->type->period->trans(dim);
    }
    res += this->id_list->trans(type, tmp, ";\n", &dim);
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

std::string PeriodNode::trans(std::vector<int> &dim) const{
    std::string res = "";
    if (this->period != nullptr){
        res += this->period->trans();
    }
    int start = std::stoi(this->num1->trans());
    dim.push_back(start);
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
    Table tmp = t;
    res += this->subprogram_body->trans();
    t = tmp;
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
    res += this->id_list->trans(type, "", ", ", nullptr, is_ptr);
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
    else if (this->kind == 8)
        return this->variable_list->trans();
    else if (this->kind == 9) {
        std::string expr_list = this->expression_list->trans();
        std::vector<std::string> expr, kind;
        size_t space_pos = expr_list.find(' ');
        while (space_pos != std::string::npos) {
            size_t del_pos = expr_list.find(',');
            expr.push_back(expr_list.substr(0, space_pos));
            if (del_pos != std::string::npos) {
                kind.push_back(expr_list.substr(space_pos + 1, del_pos - space_pos));
                expr_list = expr_list.erase(0, del_pos + 1);
            }
            else {
                kind.push_back(expr_list.substr(space_pos + 1));
                expr_list = "";
            }
            space_pos = expr_list.find(' ');
        }
        int n = expr.size();
        std::string res = "";
        for (int i = 0; i < n; i++) {
            res += "printf(" + kind[i] + ", " + expr[i] + ");\n";
        }
        return res;
    }
    return "";
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
    std::tuple<int, int, std::vector<int>> info = t.table[*id];
    std::string res = "";
    if (std::get<0>(info) == 1) {
        res = "scanf(\"%d\", &";
    } 
    else if (std::get<0>(info) == 2) {
        res = "scanf(\"%lf\", &";
    }
    else if (std::get<0>(info) == 3) {
        res = "scanf(\"%c\", &";
    }
    else if (std::get<0>(info) == 4) {
        res = "scanf(\"%s\", ";
    }
    res += this->id->trans();
    std::string index = this->id_varpart->trans();
    int i = 0;
    size_t space_pos = index.find(' ');
    while (space_pos != std::string::npos) {
        int int_index = std::stoi(index.substr(0, space_pos));
        int_index -= std::get<2>(info)[i];  // error: 维度要匹配
        res += "[" + std::to_string(int_index) + "]";
        i++;
        space_pos = index.find(' ');
    }
    res += ");\n";
    return res;
}

std::string IdVarpartNode::trans() const {
    if (this->expression_list == nullptr) 
        return "";
    else {
        std::string expr_list = this->expression_list->trans();
        std::string res = "";
        size_t space_pos = expr_list.find(' ');
        while (space_pos != std::string::npos) {
            size_t del_pos = expr_list.find(',');
            res += expr_list.substr(0, space_pos) + " ";  // error: 应要求必须为整数
            if (del_pos != std::string::npos)
                expr_list = expr_list.erase(0, del_pos + 1);
            else
                expr_list = "";
            space_pos = expr_list.find(' ');
        }
        return res;
    }
}

std::string ProcedureCallNode::trans() const {
    if (this->expression_list == nullptr)
        return this->id->trans() + "()";
    else {  //找到每一个空格，从空格开始到逗号前的部分都去掉
        std::string expr_list = this->expression_list->trans();
        size_t space_pos = expr_list.find(' ');
        while (space_pos != std::string::npos) {
            size_t del_pos = expr_list.find(',');
            expr_list = expr_list.erase(space_pos, del_pos - space_pos);
            space_pos = expr_list.find(' ');
        }
        std::tuple<int, int, std::vector<int>> info = t.table[*id];
        std::string kind = "";
        if (std::get<0>(info) == 1) {
            kind = "%d";
        }
        else if (std::get<0>(info) == 2) {
            kind = "%lf";
        }
        else if (std::get<0>(info) == 3) {
            kind = "%c";
        }
        else if (std::get<0>(info) == 4) {
            kind = "%s";
        }
        return this->id->trans() + "(" + expr_list + ")" + kind;
    }
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
        return this->expression->trans() + "," + this->expression_list->trans();
}

std::string ExpressionNode::trans() const {
    if (this->relop == nullptr)
        return this->simple_expression->trans();
    else {
        std::string op = this->relop->trans();
        std::string simple_expr = this->simple_expression->trans();
        size_t simple_expr_space_pos = simple_expr.find(' ');
        std::string simple_expr_content = simple_expr.substr(0, simple_expr_space_pos);
        std::string simple_expr_kind = simple_expr.substr(simple_expr_space_pos + 1);
        std::string simple_expr_2 = this->simple_expression_2->trans();
        size_t simple_expr_2_space_pos = simple_expr_2.find(' ');
        std::string simple_expr_2_content = simple_expr_2.substr(0, simple_expr_2_space_pos);
        std::string simple_expr_2_kind = simple_expr_2.substr(simple_expr_2_space_pos + 1);
        std::string kind = "";
        if (simple_expr_kind == "%lf" || simple_expr_2_kind == "%lf")  // error: 这里应该按符号具体判断种类，可能会有错误处理
            kind = "%lf";
        else
            kind = "%d";
        return simple_expr_content + op + simple_expr_2_content + kind;
    }
}

std::string SimpleExpressionNode::trans() const {
    if (this->addop == nullptr)
        return this->term->trans();
    else {
        std::string op = this->addop->trans();
        std::string term_expr = this->term->trans();
        size_t term_space_pos = term_expr.find(' ');
        std::string term_content = term_expr.substr(0, term_space_pos);
        std::string term_kind = term_expr.substr(term_space_pos + 1);
        std::string simple_expr = this->simple_expression->trans();
        size_t simple_expr_space_pos = simple_expr.find(' ');
        std::string simple_expr_content = simple_expr.substr(0, simple_expr_space_pos);
        std::string simple_expr_kind = simple_expr.substr(simple_expr_space_pos + 1);
        std::string kind = "";
        if (term_kind == "%lf" || simple_expr_kind == "%lf")  // error: 这里应该按符号具体判断种类，可能会有错误处理
            kind = "%lf";
        else
            kind = "%d";
        return simple_expr_content + op + term_content + kind;
    }
}

std::string TermNode::trans() const {
    if (this->mulop == nullptr)
        return this->factor->trans();
    else {
        std::string op = this->mulop->trans();
        std::string term_expr = this->term->trans();
        size_t term_space_pos = term_expr.find(' ');
        std::string term_content = term_expr.substr(0, term_space_pos);
        std::string term_kind = term_expr.substr(term_space_pos + 1);
        std::string factor_expr = this->factor->trans();
        size_t factor_space_pos = factor_expr.find(' ');
        std::string factor_content = factor_expr.substr(0, factor_space_pos);
        std::string factor_kind = factor_expr.substr(factor_space_pos + 1);
        std::string kind = "";
        if (term_kind == "%lf" || factor_kind == "%lf")
            kind = "%lf";
        else
            kind = "%d";
        return term_content + this->mulop->trans() + factor_content + kind;
    }
}

std::string FactorNode::trans() const {
    if (this->kind == 1) {
        std::tuple<int, int, std::vector<int>> info = t.table[*num];
        std::string kind = "";
        if (std::get<0>(info) == 1) {
            kind = "%d";
        }
        else if (std::get<0>(info) == 2) {
            kind = "%lf";
        }
        return this->num->trans() + " " + kind;
    }
    else if (this->kind == 2) {
        std::tuple<int, int, std::vector<int>> info = t.table[*id];
        std::string kind = "";
        if (std::get<0>(info) == 1) {
            kind = "%d";
        }
        else if (std::get<0>(info) == 2) {
            kind = "%lf";
        }
        else if (std::get<0>(info) == 3) {
            kind = "%c";
        }
        else if (std::get<0>(info) == 4) {
            kind = "%s";
        }
        return this->id->trans() + " " + kind;
    }
    else if (this->kind == 3) {
        std::string expr = this->expression->trans();
        size_t space_pos = expr.find(' ');
        std::string before_space = "(" + expr.substr(0, space_pos) + ")";
        std::string after_space = expr.substr(space_pos);
        return before_space + after_space;
    }
    else if (this->kind == 4) {  //找到每一个空格，从空格开始到逗号前的部分都去掉
        std::string expr_list = this->expression_list->trans();
        size_t space_pos = expr_list.find(' ');
        while (space_pos != std::string::npos) {
            size_t del_pos = expr_list.find(',');
            expr_list = expr_list.erase(space_pos, del_pos - space_pos);
            space_pos = expr_list.find(' ');
        }
        std::tuple<int, int, std::vector<int>> info = t.table[*id];
        std::string kind = "";
        if (std::get<0>(info) == 1) {
            kind = "%d";
        }
        else if (std::get<0>(info) == 2) {
            kind = "%lf";
        }
        else if (std::get<0>(info) == 3) {
            kind = "%c";
        }
        else if (std::get<0>(info) == 4) {
            kind = "%s";
        }
        return this->id->trans() + "(" + expr_list + ")" + kind;
    }
    else if (this->kind == 5) {
        std::string op = this->not_uminus->trans();
        return op + this->factor->trans();
    }
    return "";
}