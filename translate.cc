#include "./header/translate.hh"
#include <algorithm>

#include "AST.cc"
#include "test/output_AST.cc"
Table t;
static std::string LINE_FORMAT = "";
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
                return "float";
            else if (this->token.property == "char")
                return "char";
            else if (this->token.property == "boolean")
                return "int";
            else if (this->token.property == "true")
                return "-1";
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
                return "~";
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
    LINE_FORMAT += "\t";
    std::string main_func_body = this->compound_statement->trans();
    res += "{\n" + main_func_body + LINE_FORMAT + "return 0;\n}";
    LINE_FORMAT = LINE_FORMAT.substr(0, LINE_FORMAT.size()-1);
    return res;
}

std::string IdListNode::trans(const std::string type, const std::string tmp, const std::string end, const std::vector<int> *dim, const bool is_cite, std::vector<int> *func_p_is_cite) const{
    std::string res = "";
    if (dim == nullptr){
        std::vector<int> tmp;
        dim = &tmp;
    }
    if(this->id_list != nullptr){
        res += this->id_list->trans(type, tmp, end, dim, is_cite, func_p_is_cite);
    }
    res += LINE_FORMAT + type + this->id->trans() + tmp + end;
    // if (!t.table.count(*this->id)) { // 如果当前变量未声明过
    //     Token error_token = this->id->token;
    //     fprintf(stderr, "Error: In line %d column %d, the identifier is not defined yet\n", error_token.line, error_token.column);
    // }
    if (is_cite){
        if (type == "int *"){
            t.table[*(this->id)] = std::make_tuple(ID_INT, std::vector<int>(1,CITE), *dim);
        } else if (type == "float *") {
            t.table[*(this->id)] = std::make_tuple(ID_FLOAT, std::vector<int>(1,CITE), *dim);
        } else if (type == "char *"){
            t.table[*(this->id)] = std::make_tuple(ID_CHAR, std::vector<int>(1,CITE), *dim);
        }
    } else if (type == "int "){
        t.table[*(this->id)] = std::make_tuple(ID_INT, std::vector<int>(1,0), *dim);
    } else if (type == "float ") {
        t.table[*(this->id)] = std::make_tuple(ID_FLOAT, std::vector<int>(1,0), *dim);
    } else if (type == "char "){
        t.table[*(this->id)] = std::make_tuple(ID_CHAR, std::vector<int>(1,0), *dim);
    } else if (type == "string "){
        t.table[*(this->id)] = std::make_tuple(ID_STRING, std::vector<int>(1,0), *dim);
    }
    if (func_p_is_cite != nullptr){
        if (is_cite) {
            func_p_is_cite->push_back(CITE);
        } else {
            func_p_is_cite->push_back(0);
        }
        
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
    std::string res = "";
    if (this->const_declaration != nullptr){
        res += this->const_declaration->trans();
    }
    res += "const ";
    int type = 0;
    // if (!t.table.count(*this->id)) { // 如果当前变量未声明过
    //     Token error_token = this->id->token;
    //     fprintf(stderr, "Error: In line %d column %d, the identifier is not defined yet\n", error_token.line, error_token.column);
    // }
    if (this->const_value->numletter->token.type == TokenType::Number){
        if (this->const_value->numletter->token.property.find(".") != std::string::npos){
            res += "float ";
            type = ID_FLOAT;
        } else {
            res += "int ";
            type = ID_INT;
        }
        t.table[*(this->id)] = std::make_tuple(type, std::vector<int>(1,0), std::vector<int>());
        res += this->id->trans() + " = ";
        res += this->const_value->trans() + ";\n";
    } else if (this->const_value->numletter->token.type == TokenType::Char){
        res += "char ";
        t.table[*(this->id)] = std::make_tuple(ID_CHAR, std::vector<int>(1,0), std::vector<int>());
        res += this->id->trans() + " = ";
        res += "\'" + this->const_value->trans() + "\';\n";
    } else if (this->const_value->numletter->token.type == TokenType::String){
        res += "char *";
        t.table[*(this->id)] = std::make_tuple(ID_STRING, std::vector<int>(1,0), std::vector<int>());
        res += this->id->trans() + " = ";
        res += "\"" + this->const_value->trans() + "\";\n";
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
        res += this->period->trans(dim);
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
    std::vector<int> func_p_is_cite;
    Table tmp = t;
    res += this->subprogram_head->trans(&func_p_is_cite);
    FinalNode now_func = *t.now_funcid;
    int func_type;
    if (this->subprogram_head->basic_type == nullptr){
        func_type = FUNC_VOID;
    } else if (this->subprogram_head->basic_type->trans() == "int"){
        func_type = FUNC_INT;
    } else if (this->subprogram_head->basic_type->trans() == "float"){
        func_type = FUNC_FLOAT;
    } else if (this->subprogram_head->basic_type->trans() == "char"){
        func_type = FUNC_CHAR;
    }
    t.table[now_func] = std::make_tuple(func_type, func_p_is_cite, std::vector<int>());//自身递归需要
    if (func_type != FUNC_VOID){
        FinalNode tmp_func_id(Token(now_func.trans() + TMP_RETURN, TokenType::Identifier, -1, -1));
        t.table[tmp_func_id] = std::make_tuple(func_type - FUNC, std::vector<int>(1,0), std::vector<int>());  
    }
    LINE_FORMAT += "\t";
    res += this->subprogram_body->trans(); //先存符号表，再处理函数体：递归调用自身
    LINE_FORMAT = LINE_FORMAT.substr(0, LINE_FORMAT.size() - 1);
    t = tmp;
    t.table[now_func] = std::make_tuple(func_type, func_p_is_cite, std::vector<int>());//外部调用需要
    return res;
}

std::string SubprogramHeadNode::trans(std::vector<int> *func_p_is_cite) const{
    std::string res = "";
    if (this->basic_type == nullptr){
        res += "void ";
    } else {
        res += this->basic_type->trans() + " ";
    }
    res += this->id->trans();
    t.now_funcid = this->id;
    res += this->formal_parameter->trans(func_p_is_cite);
    return res;
}

std::string FormalParameterNode::trans(std::vector<int> *func_p_is_cite) const{
    std::string res = "(";
    if (this->parameter_list != nullptr){
        res += this->parameter_list->trans(func_p_is_cite);
    }
    res += ")";
    return res;
}

std::string ParameterListNode::trans(std::vector<int> *func_p_is_cite) const{
    std::string res = "";
    if (this->parameter_list != nullptr){
        res += this->parameter_list->trans(func_p_is_cite);
        res += ", ";
    }
    res += this->parameter->trans(func_p_is_cite);
    return res;
}

std::string ParameterNode::trans(std::vector<int> *func_p_is_cite) const{
    std::string res = "";
    if (this->var_parameter != nullptr){
        res += this->var_parameter->trans(func_p_is_cite);
    } else if (this->value_parameter != nullptr){
        res += this->value_parameter->trans(false, func_p_is_cite);
    }

    return res;
}

std::string VarParameterNode::trans(std::vector<int> *func_p_is_cite) const{
    std::string res = "";
    res += this->value_parameter->trans(true, func_p_is_cite);
    return res;
}

std::string ValueParameterNode::trans(const bool is_ptr, std::vector<int> *func_p_is_cite) const{
    std::string res = "";
    std::string type = this->basic_type->trans() + " ";
    if (is_ptr){
        type += "*";
    }
    auto nulldim = std::vector<int>();
    res += this->id_list->trans(type, "", ", ", &nulldim, is_ptr, func_p_is_cite);
    res = res.substr(0, res.size() - 2);
    return res;
}

std::string SubprogramBodyNode::trans() const {
    std::string constDecl = this->const_declarations->trans();
    std::string varDecl = this->var_declarations->trans();
    std::string com_state = this->compound_statement->trans();
    // if (!t.table.count(*t.now_funcid)) { // 如果当前变量未声明过
    //     Token error_token = t.now_funcid->token;
    //     fprintf(stderr, "Error: In line %d column %d, the identifier is not defined yet\n", error_token.line, error_token.column);
    // }
    if (t.now_funcid != nullptr && std::get<0>(t.table[*t.now_funcid]) != FUNC_VOID) {
        std::string ret_type;
        if (std::get<0>(t.table[*t.now_funcid]) == FUNC_INT) {
            ret_type = "int ";
        } else if (std::get<0>(t.table[*t.now_funcid]) == FUNC_FLOAT) {
            ret_type = "float ";
        } else if (std::get<0>(t.table[*t.now_funcid]) == FUNC_CHAR) {
            ret_type = "char ";
        }
        varDecl += LINE_FORMAT + ret_type + t.now_funcid->trans() + TMP_RETURN + " = 0;\n";
        com_state += LINE_FORMAT + "return " + t.now_funcid->trans() + TMP_RETURN + ";\n";
    }
    return "{\n" + constDecl + varDecl + com_state + "}\n";
}
std::string CompoundStatementNode::trans() const {
    std::string state_ls_str = this->statement_list->trans();
    return state_ls_str;
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
        return "";
    else if (this->kind == 2) {
        std::string var = this->variable->trans();
        size_t space_pos = var.find(' ');
        std::string var_kind = var.substr(space_pos);
        var = var.substr(0, space_pos);
        std::string exp = this->expression->trans();
        space_pos = exp.find(' ');
        std::string exp_kind = exp.substr(space_pos);
        exp = exp.substr(0, space_pos);
        if ((var_kind == "%s") ^ (exp_kind == "%s")) { // 如果赋值符号两边有且仅有一个字符串
            Token error_token = this->variable->id->token;
            fprintf(stderr, "Error: In line %d column %d, string assignment error\n", error_token.line, error_token.column);
        }
        if (var_kind != exp_kind) { // 如果赋值符号两边类型不一致
            Token error_token = this->variable->id->token;
            fprintf(stderr, "Warning: In line %d column %d, type mismatch\n", error_token.line, error_token.column);
        }
        return LINE_FORMAT + var + " = " + exp + ";\n";
    }
    else if (this->kind == 3){
        if(t.now_funcid != nullptr && *(this->id) == *(t.now_funcid)) {
            std::string exp = this->expression->trans();
            size_t space_pos = exp.find(' ');
            exp = exp.substr(0, space_pos);
            return LINE_FORMAT + t.now_funcid->trans() + TMP_RETURN + " = " + exp + ";\n";
        }
        else {
            std::string id_str = this->id->trans();
            std::string exp = this->expression->trans();
            size_t space_pos = exp.find(' ');
            auto exp_kind = exp.substr(space_pos);
            std::string id_kind;
            if(exp[exp.size() - 1] == ')'){
                exp = exp.substr(0, space_pos) + ")";
            } else {
                exp = exp.substr(0, space_pos);
            }
            if (!t.table.count(*this->id)) { // 如果当前变量未声明过
                Token error_token = this->id->token;
                fprintf(stderr, "Error: In line %d column %d, the identifier is not defined yet\n", error_token.line, error_token.column);
            }
            auto info = t.table[*id];
            if (std::get<0>(info) == ID_INT) {
                id_kind = " %d";
            }
            else if (std::get<0>(info) == ID_FLOAT) {
                id_kind = " %f";
            }
            else if (std::get<0>(info) == ID_CHAR) {
                id_kind = " %c";
            }
            else if (std::get<0>(info) == ID_STRING) {
                id_kind = " %s";
            }
            if (id_kind != exp_kind) { // 如果赋值符号两边类型不一致
                Token error_token = this->id->token;
                fprintf(stderr, "Warning: In line %d column %d, type mismatch\n", error_token.line, error_token.column);
            }
            if (!std::get<1>(info).empty() && std::get<1>(info).back() >= CITE)
                id_str = "(*" + id_str + ")";
            return LINE_FORMAT + id_str + " = " + exp + ";\n";
        }
    }
    else if (this->kind == 4)
        return LINE_FORMAT + this->procedure_call->trans() + ";\n";
    else if (this->kind == 5)
        return this->compound_statement->trans();
    else if (this->kind == 6) { // 后面用不用考虑变成else if的形式，更工整但可能不是很必要？
        std::string exp = this->expression->trans();
        size_t space_pos = exp.find(' ');
        if (exp[exp.size() - 1] == ')') {
            exp = exp.substr(0, space_pos) + ")";
        } else {
            exp = exp.substr(0, space_pos);
        }
        std::string res = LINE_FORMAT + "if (" + exp + ")";
        LINE_FORMAT += "\t";
        std::string statement_str = this->statement->trans();
        LINE_FORMAT = LINE_FORMAT.substr(0, LINE_FORMAT.size() - 1);
        res += "{\n" + statement_str + LINE_FORMAT + "}"+ this->else_part->trans() + "\n";
        return  res;
    }
    else if (this->kind == 7) {
        std::string exp = this->expression->trans();
        size_t space_pos = exp.find(' ');
        if (exp[exp.size() - 1] == ')') {
            exp = exp.substr(0, space_pos) + ")";
        } else {
            exp = exp.substr(0, space_pos);
        }
        std::string exp2 = this->expression_2->trans();
        space_pos = exp2.find(' ');
        if (exp2[exp2.size() - 1] == ')') {
            exp2 = exp2.substr(0, space_pos) + ")";
        } else {
            exp2 = exp2.substr(0, space_pos);
        }
        std::string i = this->id->trans();
        std::string res = LINE_FORMAT + "for (" + i + " = " + exp + "; " + i + " <= " + exp2 + "; " + i + "++)";
        LINE_FORMAT += "\t";
        std::string statement_str = this->statement->trans();
        LINE_FORMAT = LINE_FORMAT.substr(0, LINE_FORMAT.size() - 1);
        res += "{\n" + statement_str + LINE_FORMAT + "}\n";
        return  res;
    }
    else if (this->kind == 8) {
        std::string var_list = this->variable_list->trans();
        std::vector<std::string> var, kind;
        size_t space_pos = var_list.find(' ');
        while (space_pos != std::string::npos) {
            size_t del_pos = var_list.find(',');
            var.push_back(var_list.substr(0, space_pos));
            if (del_pos != std::string::npos) {
                kind.push_back(var_list.substr(space_pos + 1, del_pos - space_pos  - 1)); // 删去','
                var_list = var_list.erase(0, del_pos + 1);
            }
            else {
                kind.push_back(var_list.substr(space_pos + 1));
                var_list = "";
            }
            space_pos = var_list.find(' ');
        }
        int n = var.size();
        std::string res = "";
        for (int i = n - 1; i >= 0; i--) {
            if (var[i].at(var[i].size() - 1) == ')' && var[i].at(var[i].size() - 2) == '(') {
                var[i].pop_back(), var[i].pop_back();
                if(t.now_funcid != nullptr && var[i] == t.now_funcid->token.property){
                    var[i] += TMP_RETURN;
                }
            }
            if (kind[i] != "%s")
                res += LINE_FORMAT + "scanf(\"" + kind[i] + "\", &" + var[i] + ");\n";
            else
                res += LINE_FORMAT + "scanf(\"%s\", " + var[i] + ");\n";
        }
        return res;
    }
    else if (this->kind == 9) {
        std::string expr_list = this->expression_list->trans();
        std::vector<std::string> expr, kind;
        size_t space_pos = expr_list.find(' ');
        while (space_pos != std::string::npos) {
            expr.push_back(expr_list.substr(0, space_pos));
            expr_list.erase(0, space_pos + 1);
            size_t del_pos = expr_list.find(',');
            if (del_pos != std::string::npos) {
                kind.push_back(expr_list.substr(0, del_pos));
                expr_list = expr_list.erase(0, del_pos + 1);
            }
            else {
                kind.push_back(expr_list);
                expr_list = "";
            }
            space_pos = expr_list.find(' ');
        }
        int n = expr.size();
        std::string res = "";
        for (int i = 0; i < n; i++) {
            if (kind[i][int(kind[i].size()) - 1] == ',')
                kind[i].erase(kind[i].end() - 1);
            res += LINE_FORMAT + "printf(\"" + kind[i] + "\", " + expr[i] + ");\n";
        }
        return res;
    }
    else if(kind == 10){ //  statement → while expression do statement
        std::string exp = this->expression->trans();
        size_t space_pos = exp.find(' ');
        if (exp[exp.size() - 1] == ')') {
            exp = exp.substr(0, space_pos) + ")";
        } else {
            exp = exp.substr(0, space_pos);
        }
        LINE_FORMAT += "\t";
        const std::string statement_str = this->statement->trans();
        LINE_FORMAT = LINE_FORMAT.substr(0, LINE_FORMAT.size() - 1);
        int end_index = statement_str.size() - 1;
        while(end_index > 0){ 
            if(statement_str[end_index] != '\n' && statement_str[end_index] != ' ' && statement_str[end_index] != '\t'){
                break;
            }
            end_index--;
        } //去掉结尾的'\n', ' ', '\t'等方便判断是否以'}'结尾
        if(end_index >= 0 && statement_str[0] == '{' && statement_str[end_index] == '}'){
            return LINE_FORMAT + "while (" + exp + ") " + statement_str + "\n"; //若以{}包裹则不需要再加{}
        }
        else {
            return LINE_FORMAT + "while (" + exp + ") {\n" + statement_str + LINE_FORMAT + "}\n";
        }
    }
    else if(kind == 11){
        return LINE_FORMAT + "break;\n";
    }
    return "";
}

std::string VariableListNode::trans() const {
    if (this->variable_list == nullptr)
        return this->variable->trans();
    else
        return this->variable->trans() + "," + this->variable_list->trans();
}

bool isInteger(const std::string& str) {
    // TODO: 目前不充分的考量，只要不是小数常量就认为是整数，变量也被允许
    if(str.empty()) return false;
    if(std::find(str.begin(), str.end(), '.') != str.end()) return false;
    return true;
}

bool is_int(const std::string& str) {
    // TODO: 判断是否为纯粹的整数，而不是变量
    if (str[0] != '+' && str[0] != '-' && !isdigit(str[0])) return false;
    for (std::string::size_type i = 1; i < str.length(); i++)
        if (!isdigit(str[i])) return false;
    return true;
}

std::string VariableNode::trans() const {
    if (!t.table.count(*this->id)) { // 如果当前变量未声明过
        Token error_token = this->id->token;
        fprintf(stderr, "Error: In line %d column %d, the identifier is not defined yet\n", error_token.line, error_token.column);
    }
    auto info = t.table[*id];
    std::string res = this->id->trans();
    std::string raw_index = this->id_varpart->trans();
    int i = 0;
    size_t space_pos = raw_index.find(' ');
    while (space_pos != std::string::npos) {
        int start_i = std::get<2>(info)[i];
        std::string raw_index_content = raw_index.substr(0, space_pos);
        if (!(isInteger(raw_index_content))) { // 如果索引不为整数
            Token error_token = this->id->token;
            fprintf(stderr, "Error: In line %d column %d, index of array is not integer\n", error_token.line, error_token.column);
        }
        std::string index = "";
        if (is_int(raw_index_content)) {
            index = std::to_string(std::stoi(raw_index_content) - start_i);
            if (index[0] == '-') { // 如果数组下标为负数
                Token error_token = this->id->token;
                fprintf(stderr, "Error: In line %d column %d, index of array is out of range\n", error_token.line, error_token.column);
            }
        }
        else {
            if (start_i > 0)
                index = raw_index_content + "-" + std::to_string(start_i);
            else if (start_i < 0)
                index = raw_index_content + "+" + std::to_string(-start_i);
            else
                index = raw_index_content;
        }
        res += "[" + index + "]";
        i++;
        raw_index.erase(0, space_pos + 1);
        space_pos = raw_index.find(' ');
    }
    if (i != int(std::get<2>(info).size())) { // 如果数组维度不匹配
        Token error_token = this->id->token;
        fprintf(stderr, "Error: In line %d column %d, the dimensions of the arrays do not match\n", error_token.line, error_token.column);
    }
    if (std::get<0>(info) == ID_INT) {
        res += " %d";
    }
    else if (std::get<0>(info) == ID_FLOAT) {
        res += " %f";
    }
    else if (std::get<0>(info) == ID_CHAR) {
        res += " %c";
    }
    else if (std::get<0>(info) == ID_STRING) {
        res += " %s";
    }
    else if (std::get<0>(info) == FUNC_INT) {
        res += "() %d";
    }
    else if (std::get<0>(info) == FUNC_FLOAT) {
        res += "() %f";
    }
    else if (std::get<0>(info) == FUNC_CHAR) {
        res += "() %c";
    }
    else if (std::get<0>(info) == FUNC_VOID) {
        res += ""; // error: 
    }
    if (!std::get<1>(info).empty() && std::get<1>(info).back() >= CITE) {
        size_t space_pos = res.find(" ");
        std::string res_content = res.substr(0, space_pos);
        std::string kind = res.substr(space_pos + 1);
        res = "(*" + res_content + ") " + kind;
    }
    // res += ");\n";
    return res;
    // eg: "a[1][2] %d"
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
            res += expr_list.substr(0, space_pos) + " "; // error: 应要求必须为整数，在variable中判断
            if (del_pos != std::string::npos)
                expr_list = expr_list.erase(0, del_pos + 1);
            else
                expr_list = "";
            space_pos = expr_list.find(' ');
        }
        return res;
        // eg: 1 2 3 (相当于[1][2][3])
    }
}

static bool is_expr(std::string s) {
    // 因为经过了词法语法分析，所以不会出现)(这种错误，用数字模拟栈就好
    int st = 0;
    for (char c : s) {
        if (c == '(') st++;
        else if (c == ')') st--;
    }
    if (st == 0) return true; // 说明()完全匹配，是一个完整的表达式
    return false; // 可能是函数的一部分
}

std::string ProcedureCallNode::trans() const {
    if (this->expression_list == nullptr) {
        if (!t.table.count(*this->id)) { // 如果当前函数未声明过
            Token error_token = this->id->token;
            fprintf(stderr, "Error: In line %d column %d, the identifier is not defined yet\n", error_token.line, error_token.column);
        }
        return this->id->trans() + "()";
    }
    else { // 找到每一个空格，从空格开始到逗号前的部分都去掉
        std::string expr_list = this->expression_list->trans();
        std::string expr1 = "";
        std::string temp = "";
        size_t space_pos = expr_list.find(' ');
        while (space_pos != std::string::npos) {
            expr1 += expr_list.substr(0, space_pos);
            expr_list.erase(0, space_pos);
            if (!is_expr(expr1)) {
                space_pos = expr_list.find(" ");
                continue;
            }
            size_t del_pos = expr_list.find(',');
            temp += expr1 + ",";
            expr1 = "";
            if (del_pos != std::string::npos)
                expr_list = expr_list.erase(0, del_pos + 1);
            else
                expr_list = "";
            space_pos = expr_list.find(' ');
        }
        if (temp[int(temp.size()) - 1] == ',') temp.erase(int(temp.size()) - 1);
        expr_list = temp;
        if (!t.table.count(*this->id)) { // 如果当前函数未声明过
            Token error_token = this->id->token;
            fprintf(stderr, "Error: In line %d column %d, the identifier is not defined yet\n", error_token.line, error_token.column);
        }
        auto info = t.table[*id];
        std::string res = this->id->trans() + "(";
        std::vector<int> cites = std::get<1>(t.table[*this->id]);
        int arg_num = cites.size();
        int k = 0; // 正在判断第k个expression要不要加&
        std::string expr = "";
        size_t del_pos = expr_list.find(",");
        while(del_pos != std::string::npos) {
            expr += expr_list.substr(0, del_pos);
            if (!is_expr(expr)) {
                expr += ",";
                expr_list.erase(0,del_pos + 1);
                del_pos = expr_list.find(",");
                continue;
            }
            if(k >= arg_num - 1){
                Token error_token = this->id->token;
                fprintf(stderr, "Error: In line %d column %d, Too many arguments in function call\n", error_token.line, error_token.column);
                if(arg_num == 0 && k == 0)
                    return res + ")";
                else
                    return res + expr + ")";
            }
            if (cites.at(k) >= CITE)
                res += "&";
            res += expr + ",";
            expr = "";
            k++;
            expr_list.erase(0,del_pos + 1);
            del_pos = expr_list.find(",");
        }
        if (k + 1 != arg_num) {
            if(arg_num == 0 && k == 0){
                Token error_token = this->id->token;
                fprintf(stderr, "Error: In line %d column %d, Too many arguments in function call\n", error_token.line, error_token.column);
                return res + ")";
            }
            else{
                Token error_token = this->id->token;
                fprintf(stderr, "Error: In line %d column %d, function call argument number error. %d expected, %d given\n", error_token.line, error_token.column, arg_num, k + 1);
            }
        }
        if (cites.at(k) >= CITE)
            res += "&";
        res += expr + expr_list + ")";
        return res; // eg: f(a,&b)
    }
}

std::string ElsePartNode::trans() const {
    if (this->statement == nullptr)
        return "";
    else{
        LINE_FORMAT += "\t";
        std::string statement_str = this->statement->trans();
        LINE_FORMAT = LINE_FORMAT.substr(0, LINE_FORMAT.size() - 1);
        return " else {\n" + statement_str + LINE_FORMAT + "}";
    }
}

std::string ExpressionListNode::trans() const {
    if (this->expression_list == nullptr)
        return this->expression->trans();
    else
        return this->expression_list->trans() + "," + this->expression->trans();
}

std::string ExpressionNode::trans() const {
    if (this->relop == nullptr)
        return this->simple_expression->trans(); // eg: "1*2+1*2 %d"
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
        if (simple_expr_kind == "%f" || simple_expr_2_kind == "%f") // error: 这里应该都是%d，因为返回值是一个等式或不等式的布尔判断结果
            kind = "%f";
        else
            kind = "%d";
        return simple_expr_content + op + simple_expr_2_content + " " + kind; // eg: "a==1*2+1*2 %d"
    }
}

std::string SimpleExpressionNode::trans() const {
    if (this->addop == nullptr)
        return this->term->trans(); // eg: "2 %d"
    else {
        std::string op = this->addop->trans(); // + - ||
        std::string term_expr = this->term->trans();
        size_t term_space_pos = term_expr.find(' ');
        std::string term_content = term_expr.substr(0, term_space_pos);
        std::string term_kind = term_expr.substr(term_space_pos + 1);
        std::string simple_expr = this->simple_expression->trans();
        size_t simple_expr_space_pos = simple_expr.find(' ');
        std::string simple_expr_content = simple_expr.substr(0, simple_expr_space_pos);
        std::string simple_expr_kind = simple_expr.substr(simple_expr_space_pos + 1);
        std::string kind = "";
        std::string res_num = "";
        if (op == "+" || op == "-") {
            if (term_kind == "%f" || simple_expr_kind == "%f") // error: 这里应该按符号具体判断种类，可能会有错误处理
                kind = "%f";
            else if (term_kind == "%d" || simple_expr_kind == "%d")
                kind = "%d";
            else
                kind = "%c";
            if (is_int(simple_expr_content) && is_int(term_content)) {
                if (op == "+")
                    res_num = std::to_string(std::stoi(simple_expr_content) + std::stoi(term_content));
                else
                    res_num = std::to_string(std::stoi(simple_expr_content) - std::stoi(term_content));
            }
        }
        else
            kind = "%d";
        if (term_content != "" && term_content.substr(0, 1) == op)
            return simple_expr_content + op + "(" + term_content + ") " + kind;
        if (res_num == "")
            return simple_expr_content + op + term_content + " " + kind;
        else
            return res_num  + " " + kind;
    }
}

std::string TermNode::trans() const {
    if (this->mulop == nullptr)
        return this->factor->trans(); // eg: "1 %d"
    else {
        std::string term_expr = this->term->trans();
        size_t term_space_pos = term_expr.find(' ');
        std::string term_content = term_expr.substr(0, term_space_pos);
        std::string term_kind = term_expr.substr(term_space_pos + 1);
        std::string factor_expr = this->factor->trans();
        size_t factor_space_pos = factor_expr.find(' ');
        std::string factor_content = factor_expr.substr(0, factor_space_pos);
        std::string factor_kind = factor_expr.substr(factor_space_pos + 1);
        std::string kind = "";
        std::string res_num = "";
        std::string op = this->mulop->trans(); // * / % &&
        if (op == "*" || op == "/") {
            if (term_kind == "%f" || factor_kind == "%f") // error: 这里应该按符号具体判断种类，可能会有错误处理
                kind = "%f";
            else if (term_kind == "%d" || factor_kind == "%d")
                kind = "%d";
            else
                kind = "%c";
            if (is_int(term_content) && is_int(factor_content)) {
                if (op == "*")
                    res_num = std::to_string(std::stoi(term_content) * std::stoi(factor_content));
                else
                    res_num = std::to_string(std::stoi(term_content) / std::stoi(factor_content));
            }
        }
        else
            kind = "%d";
        // return term_content + this->mulop->trans() + factor_content + " " + kind;
        if (res_num == "")
            return term_content + op + factor_content + " " + kind;
        else
            return res_num  + " " + kind;
        // eg: "1 * 2 %d" -> "1*2 %d"
    }
}

std::string FactorNode::trans() const {
    if (this->kind == 1) {
        std::string num_str = this->num->trans();
        std::string kind = "";
        if (num_str.find('.') != std::string::npos)
            kind = "%f";
        else
            kind = "%d";
        return num_str + " " + kind; // eg: "1 %d"
    }
    else if (this->kind == 2) {
        std::string str = this->variable->trans();
        return str; // eg: "a %d"
    }
    else if (this->kind == 3) {
        std::string expr = this->expression->trans();
        size_t space_pos = expr.find(' ');
        std::string before_space = "(" + expr.substr(0, space_pos) + ")";
        std::string after_space = expr.substr(space_pos);
        return before_space + after_space; // (1+1) %d
    }
    else if (this->kind == 4) { // 找到每一个空格，从空格开始到逗号前的部分都去掉
        std::string expr_list = this->expression_list->trans();
        std::string expr = "";
        std::string temp = "";
        size_t space_pos = expr_list.find(' ');
        while (space_pos != std::string::npos) {
            expr += expr_list.substr(0, space_pos);
            expr_list.erase(0, space_pos);
            if (!is_expr(expr)) {
                space_pos = expr_list.find(" ");
                continue;
            }
            size_t del_pos = expr_list.find(',');
            temp += expr + ",";
            expr = "";
            if (del_pos != std::string::npos)
                expr_list = expr_list.erase(0, del_pos + 1);
            else
                expr_list = "";
            space_pos = expr_list.find(' ');
        }
        if (temp[int(temp.size()) - 1] == ',') temp.erase(int(temp.size()) - 1);
        expr_list = temp;
        std::string res = this->id->trans() + "(";
        std::vector<int> cites = std::get<1>(t.table[*this->id]);
        int arg_num = cites.size();
        int k = 0; // 正在判断第k个expression要不要加&
        expr = "";
        size_t del_pos = expr_list.find(",");
        while(del_pos != std::string::npos) {
            expr += expr_list.substr(0, del_pos);
            if (!is_expr(expr)) {
                expr += ",";
                expr_list.erase(0,del_pos + 1);
                del_pos = expr_list.find(",");
                continue;
            }
            if(k >= arg_num - 1){
                Token error_token = this->id->token;
                fprintf(stderr, "Error: In line %d column %d, Too many arguments in function call\n", error_token.line, error_token.column);
                if(arg_num == 0 && k == 0)
                    res += ")";
                else
                    res += expr + ")";
                goto ret_kind_check;
            }
            if (cites.at(k) >= CITE)
                res += "&";
            res += expr + ",";
            expr = "";
            k++;
            expr_list.erase(0,del_pos + 1);
            del_pos = expr_list.find(",");
        }
        if (k + 1 != arg_num) {
            if (arg_num == 0 && k == 0){
                res += ")";
                Token error_token = this->id->token;
                fprintf(stderr, "Error: In line %d column %d, Too many arguments in function call\n", error_token.line, error_token.column);
                goto ret_kind_check;
            }
            else{
                Token error_token = this->id->token;
                fprintf(stderr, "Error: In line %d column %d, function call argument number error. %d expected, %d given\n", error_token.line, error_token.column, arg_num, k + 1);
            }
        }
        if (cites.at(k) >= CITE)
            res += "&";
        res += expr + expr_list + ")";
        // 判断函数返回值类型
        ret_kind_check:
        if (!t.table.count(*this->id)) { // 如果当前变量未声明过
            Token error_token = this->id->token;
            fprintf(stderr, "Error: In line %d column %d, the identifier is not defined yet\n", error_token.line, error_token.column);
        }
        auto info = t.table[*id];
        std::string kind = "";
        if (std::get<0>(info) == ID_INT) {
            kind = "%d";
        }
        else if (std::get<0>(info) == ID_FLOAT) {
            kind = "%f";
        }
        else if (std::get<0>(info) == ID_CHAR) {
            kind = "%c";
        }
        else if (std::get<0>(info) == ID_STRING) {
            kind = "%s";
        }
        else if (std::get<0>(info) == FUNC_INT) {
            kind = "%d";
        }
        else if (std::get<0>(info) == FUNC_FLOAT) {
            kind = "%f";
        }
        else if (std::get<0>(info) == FUNC_CHAR) {
            kind = "%c";
        }
        else if (std::get<0>(info) == FUNC_VOID) {
            kind = ""; // error: 
        }
        return res + " " + kind; // eg: f(a,&b) %d
    }
    else if (this->kind == 5) {
        std::string op = this->not_uminus->trans();
        std::string factor_str = this->factor->trans();
        if (factor_str != "" && factor_str.substr(0, 1) == op) {
            size_t space_pos = factor_str.find(' ');
            std::string factor_content = factor_str.substr(0, space_pos);
            std::string factor_kind = factor_str.substr(space_pos);
            return op + "(" + factor_content + ") " + factor_kind;
        }
        return op + factor_str; // -(-1) %d
    }
    return "";
}