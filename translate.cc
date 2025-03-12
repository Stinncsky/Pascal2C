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