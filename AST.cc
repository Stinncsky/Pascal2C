#include "./header/AST.hh"
#include "./header/translate.hh"
#ifndef __AST_CC__
#define __AST_CC__

class FinalNode : public AST { // 终结符节点
    public:
        Token token;
        FinalNode(Token token) : AST(NodeType::Final){
            this->token = token;
        }
        ~FinalNode() = default;

        bool operator==(const FinalNode &f) const{
            return this->token == f.token;
        }

        bool operator<(const FinalNode &f) const{
            return this->token < f.token;
        }

        std::string trans() const override;
};

class ProgramStructNode : public AST { 
    public:
        ProgramHeadNode *program_head;
        ProgramBodyNode *program_body;

        ProgramStructNode(ProgramHeadNode *program_head, ProgramBodyNode *program_body) : AST(NodeType::programStruct){
            this->program_head = program_head;
            this->program_body = program_body;
        }
        ~ProgramStructNode();

        std::string trans() const override;
};

class ProgramHeadNode : public AST { 
    public:
        FinalNode *id;
        IdListNode *id_list;

        ProgramHeadNode(FinalNode *id, IdListNode *id_list = nullptr) : AST(NodeType::program_head){
            this->id = id;
            this->id_list = id_list;
        }
        ~ProgramHeadNode();

        std::string trans() const override;
};

class ProgramBodyNode : public AST { 
    public:
        ConstDeclarationsNode *const_declarations;
        VarDeclarationsNode *var_declarations;
        SubprogramDeclarationsNode *subprogram_declarations;
        CompoundStatementNode *compound_statement;

        ProgramBodyNode(ConstDeclarationsNode *const_declarations, VarDeclarationsNode *var_declarations, SubprogramDeclarationsNode *subprogram_declarations, CompoundStatementNode *compound_statement) : AST(NodeType::program_body){
            this->const_declarations = const_declarations;
            this->var_declarations = var_declarations;
            this->subprogram_declarations = subprogram_declarations;
            this->compound_statement = compound_statement;
        }
        ~ProgramBodyNode();

        std::string trans() const override;
};

class IdListNode : public AST { 
    public:
        FinalNode *id;
        IdListNode *id_list;

        IdListNode(FinalNode *id, IdListNode *id_list = nullptr) : AST(NodeType::idList){
            this->id = id;
            this->id_list = id_list;
        }
        ~IdListNode();

        std::string trans(const std::string type, const std::string tmp = "", const std::string end = "", const std::vector<int> *dim = nullptr, const bool is_cite = false, std::vector<int> *func_p_is_cite = nullptr) const;
        std::string trans() const override { return trans("");} // 重载纯虚函数
};

class ConstDeclarationsNode : public AST { 
    public:
        ConstDeclarationNode *const_declaration;

        ConstDeclarationsNode(ConstDeclarationNode *const_declaration = nullptr) : AST(NodeType::const_declarations){
            this->const_declaration = const_declaration;
        }
        ~ConstDeclarationsNode();

        std::string trans() const override;
};

class ConstDeclarationNode : public AST { 
    public:
        FinalNode *id;
        ConstValueNode *const_value;
        ConstDeclarationNode *const_declaration;

        ConstDeclarationNode(FinalNode *id, ConstValueNode *const_value, ConstDeclarationNode *const_declaration = nullptr) : AST(NodeType::const_declaration){
            this->id = id;
            this->const_value = const_value;
            this->const_declaration = const_declaration;
        }
        ~ConstDeclarationNode();

        std::string trans() const override;
};

class ConstValueNode : public AST { 
    public:
        FinalNode *op;
        FinalNode *numletter;

        ConstValueNode(FinalNode *numletter, FinalNode *op = nullptr) : AST(NodeType::const_value){
            this->op = op;
            this->numletter = numletter;
        }
        ~ConstValueNode();

        std::string trans() const override;
};

class VarDeclarationsNode : public AST { 
    public:
        VarDeclarationNode *var_declaration;

        VarDeclarationsNode(VarDeclarationNode *var_declaration = nullptr) : AST(NodeType::var_declarations){
            this->var_declaration = var_declaration;
        }
        ~VarDeclarationsNode();

        std::string trans() const override;
};

class VarDeclarationNode : public AST { 
    public:
        IdListNode *id_list;
        TypeNode *type;
        VarDeclarationNode *var_declaration;

        VarDeclarationNode(IdListNode *id_list, TypeNode *type, VarDeclarationNode *var_declaration = nullptr) : AST(NodeType::var_declaration){
            this->id_list = id_list;
            this->type = type;
            this->var_declaration = var_declaration;
        }
        ~VarDeclarationNode();

        std::string trans() const override;
};

class TypeNode : public AST { 
    public:
        BasicTypeNode *basic_type;
        PeriodNode *period;

        TypeNode(BasicTypeNode *basic_type, PeriodNode *period = nullptr) : AST(NodeType::type){
            this->basic_type = basic_type;
            this->period = period;
        }
        ~TypeNode();

        std::string trans() const override;
};

class BasicTypeNode : public AST { 
    public:
        FinalNode *basic_type;

        BasicTypeNode(FinalNode *basic_type) : AST(NodeType::basic_type){
            this->basic_type = basic_type;
        }
        ~BasicTypeNode();

        std::string trans() const override;
};

class PeriodNode : public AST { 
    public:
        FinalNode *num1, *num2;
        PeriodNode *period;

        PeriodNode(FinalNode *num1, FinalNode *num2, PeriodNode *period = nullptr) : AST(NodeType::period){
            this->num1 = num1;
            this->num2 = num2;
            this->period = period;
        }
        ~PeriodNode();
        std::string trans(std::vector<int> &dim) const;
        std::string trans() const override{std::vector<int> tmp; return trans(tmp);}
};

class SubprogramDeclarationsNode : public AST { 
    public:
        SubprogramDeclarationsNode *subprogram_declarations;
        SubprogramNode *subprogram;

        SubprogramDeclarationsNode(SubprogramDeclarationsNode *subprogram_declarations = nullptr, SubprogramNode *subprogram = nullptr) : AST(NodeType::subprogram_declarations){
            this->subprogram_declarations = subprogram_declarations;
            this->subprogram = subprogram;
        }
        ~SubprogramDeclarationsNode();

        std::string trans() const override;
};

class SubprogramNode : public AST { 
    public:
        SubprogramHeadNode *subprogram_head;
        SubprogramBodyNode *subprogram_body;

        SubprogramNode(SubprogramHeadNode *subprogram_head, SubprogramBodyNode *subprogram_body) : AST(NodeType::subprogram){
            this->subprogram_head = subprogram_head;
            this->subprogram_body = subprogram_body;
        }
        ~SubprogramNode();

        std::string trans() const override;
};

class SubprogramHeadNode : public AST { 
    public:
        FinalNode *id;
        FormalParameterNode *formal_parameter;
        BasicTypeNode *basic_type;

        SubprogramHeadNode(FinalNode *id, FormalParameterNode *formal_parameter, BasicTypeNode *basic_type = nullptr) : AST(NodeType::subprogram_head){
            this->id = id;
            this->formal_parameter = formal_parameter;
            this->basic_type = basic_type;
        }
        ~SubprogramHeadNode();
        std::string trans(std::vector<int> *func_p_is_cite) const;
        std::string trans() const override{return trans(nullptr);};
};

class FormalParameterNode : public AST { 
    public:
        ParameterListNode *parameter_list;

        FormalParameterNode(ParameterListNode *parameter_list = nullptr) : AST(NodeType::formal_parameter){
            this->parameter_list = parameter_list;
        }
        ~FormalParameterNode();

        std::string trans(std::vector<int> *func_p_is_cite) const;
        std::string trans() const override{return trans(nullptr);};
};

class ParameterListNode : public AST { 
    public:
        ParameterNode *parameter;
        ParameterListNode *parameter_list;

        ParameterListNode(ParameterNode *parameter, ParameterListNode *parameter_list = nullptr) : AST(NodeType::parameter_list){
            this->parameter = parameter;
            this->parameter_list = parameter_list;
        }
        ~ParameterListNode();

        std::string trans(std::vector<int> *func_p_is_cite) const;
        std::string trans() const override{return trans(nullptr);};
};

class ParameterNode : public AST { 
    public:
        VarParameterNode *var_parameter = nullptr;
        ValueParameterNode *value_parameter = nullptr;

        ParameterNode(VarParameterNode *var_parameter) : AST(NodeType::parameter){
            this->var_parameter = var_parameter;
        }
        ParameterNode(ValueParameterNode *value_parameter) : AST(NodeType::parameter){
            this->value_parameter = value_parameter;
        }
        ~ParameterNode();

        std::string trans(std::vector<int> *func_p_is_cite) const;
        std::string trans() const override{return trans(nullptr);};
};

class VarParameterNode : public AST { 
    public:
        ValueParameterNode *value_parameter;

        VarParameterNode(ValueParameterNode *value_parameter) : AST(NodeType::var_parameter){
            this->value_parameter = value_parameter;
        }
        ~VarParameterNode();

        std::string trans(std::vector<int> *func_p_is_cite) const;
        std::string trans() const override{return trans(nullptr);}
};

class ValueParameterNode : public AST { 
    public:
        IdListNode *id_list;
        BasicTypeNode *basic_type;

        ValueParameterNode(IdListNode *id_list, BasicTypeNode *basic_type) : AST(NodeType::value_parameter){
            this->id_list = id_list;
            this->basic_type = basic_type;
        }
        ~ValueParameterNode();

        std::string trans(const bool is_ptr, std::vector<int> *func_p_is_ptr = nullptr) const;
        std::string trans() const override {return trans(false);} // 重载纯虚函数
};

class SubprogramBodyNode : public AST { 
    public:
        ConstDeclarationsNode *const_declarations;
        VarDeclarationsNode *var_declarations;
        CompoundStatementNode *compound_statement;

        SubprogramBodyNode(ConstDeclarationsNode *const_declarations, VarDeclarationsNode *var_declarations, CompoundStatementNode *compound_statement) : AST(NodeType::subprogram_body){
            this->const_declarations = const_declarations;
            this->var_declarations = var_declarations;
            this->compound_statement = compound_statement;
        }
        ~SubprogramBodyNode();

        std::string trans() const override;
};

class CompoundStatementNode : public AST { 
    public:
        StatementListNode *statement_list;

        CompoundStatementNode(StatementListNode *statement_list) : AST(NodeType::compound_statement){
            this->statement_list = statement_list;
        }
        ~CompoundStatementNode();

        std::string trans() const override;
};

class StatementListNode : public AST { 
    public:
        StatementNode *statement;
        StatementListNode *statement_list;

        StatementListNode(StatementNode *statement, StatementListNode *statement_list = nullptr) : AST(NodeType::statement_list){
            this->statement = statement;
            this->statement_list = statement_list;
        }
        ~StatementListNode();

        std::string trans() const override;
};

class StatementNode : public AST {
    public:
        VariableNode *variable = nullptr;
        ExpressionNode *expression = nullptr;
        FinalNode *id = nullptr;
        ProcedureCallNode *procedure_call = nullptr;
        CompoundStatementNode *compound_statement = nullptr;
        StatementNode *statement = nullptr;
        ElsePartNode *else_part = nullptr;
        ExpressionNode *expression_2 = nullptr; // 'for'
        VariableListNode *variable_list = nullptr;
        ExpressionListNode *expression_list = nullptr;
        FinalNode *w_r = nullptr; // 'write' or 'read'
        int kind = 0;

        StatementNode() : AST(NodeType::statement) {
            this->kind = 1;
        } // statement → ε

        StatementNode(VariableNode *variable, ExpressionNode *expression) : AST(NodeType::statement) {
            this->variable = variable;
            this->expression = expression;
            this->kind = 2;
        } //  statement → variable := expression

        StatementNode(FinalNode *func_id, ExpressionNode *expression) : AST(NodeType::statement) {
            this->id = func_id;
            this->expression = expression;
            this->kind = 3;
        } //  statement → func_id := expression

        StatementNode(ProcedureCallNode *procedure_call) : AST(NodeType::statement) {
            this->procedure_call = procedure_call;
            this->kind = 4;
        } //  statement → procedure_call

        StatementNode(CompoundStatementNode *compound_statement) : AST(NodeType::statement) {
            this->compound_statement = compound_statement;
            this->kind = 5;
        } //  statement → compound_statement

        StatementNode(ExpressionNode *expression, StatementNode *statement, ElsePartNode *else_part) : AST(NodeType::statement) {
            this->expression = expression;
            this->statement = statement;
            this->else_part = else_part;
            this->kind = 6;
        } //  statement → if expression then statement else_part

        StatementNode(FinalNode *id, ExpressionNode *expression, ExpressionNode *expression_2, StatementNode *statement) : AST(NodeType::statement) {
            this->id = id;
            this->expression = expression;
            this->expression_2 = expression_2;
            this->statement = statement;
            this->kind = 7;
        } //  statement → for id := expression to expression_2 do statement

        StatementNode(FinalNode *read, VariableListNode *variable_list) : AST(NodeType::statement) {
            this->w_r = read;
            this->variable_list = variable_list;
            this->kind = 8;
        } //  statement → read ( variable_list )

        StatementNode(FinalNode *write, ExpressionListNode *expression_list) : AST(NodeType::statement) {
            this->w_r = write;
            this->expression_list = expression_list;
            this->kind = 9;
        } //  statement → write ( expression_list )

        StatementNode(ExpressionNode *expression, StatementNode *statement) : AST(NodeType::statement) {
            this->expression = expression;
            this->statement = statement;
            this->kind = 10;
        } //  statement → while expression do statement
        ~StatementNode();

        std::string trans() const override;
};

class VariableListNode : public AST { 
    public:
        VariableNode *variable;
        VariableListNode *variable_list;

        VariableListNode(VariableNode *variable, VariableListNode *variable_list = nullptr) : AST(NodeType::variable_list){
            this->variable = variable;
            this->variable_list = variable_list;
        }
        ~VariableListNode();

        std::string trans() const override;
};

class VariableNode : public AST { 
    public:
        FinalNode *id;
        IdVarpartNode *id_varpart;

        VariableNode(FinalNode *id, IdVarpartNode *id_varpart) : AST(NodeType::variable){
            this->id = id;
            this->id_varpart = id_varpart;
        }
        ~VariableNode();

        std::string trans() const override;
};

class IdVarpartNode : public AST { 
    public:
        ExpressionListNode *expression_list;

        IdVarpartNode(ExpressionListNode *expression_list = nullptr) : AST(NodeType::id_varpart){
            this->expression_list = expression_list;
        }
        ~IdVarpartNode();

        std::string trans() const override;
};

class ProcedureCallNode : public AST { 
    public:
        FinalNode *id;
        ExpressionListNode *expression_list;

        ProcedureCallNode(FinalNode *id, ExpressionListNode *expression_list = nullptr) : AST(NodeType::procedure_call){
            this->id = id;
            this->expression_list = expression_list;
        }
        ~ProcedureCallNode();

        std::string trans() const override;
};

class ElsePartNode : public AST { 
    public:
        StatementNode *statement;

        ElsePartNode(StatementNode *statement = nullptr) : AST(NodeType::else_part){
            this->statement = statement;
        }
        ~ElsePartNode();

        std::string trans() const override;
};

class ExpressionListNode : public AST { 
    public:
        ExpressionNode *expression;
        ExpressionListNode *expression_list;

        ExpressionListNode(ExpressionNode *expression, ExpressionListNode *expression_list = nullptr) : AST(NodeType::expression_list){
            this->expression = expression;
            this->expression_list = expression_list;
        }
        ~ExpressionListNode();

        std::string trans() const override;
};

class ExpressionNode : public AST { 
    public:
        SimpleExpressionNode *simple_expression;
        FinalNode *relop = nullptr;
        SimpleExpressionNode *simple_expression_2 = nullptr;

        ExpressionNode(SimpleExpressionNode *simple_expression) : AST(NodeType::expression){
            this->simple_expression = simple_expression;
        } // expression → simple_expression

        ExpressionNode(SimpleExpressionNode *simple_expression, FinalNode *relop, SimpleExpressionNode *simple_expression_2) : AST(NodeType::expression){
            this->simple_expression = simple_expression;
            this->relop = relop;
            this->simple_expression_2 = simple_expression_2;
        } // expression → simple_expression relop simple_expression
        ~ExpressionNode();

        std::string trans() const override;
};

class SimpleExpressionNode : public AST { 
    public:
        SimpleExpressionNode *simple_expression;
        FinalNode *addop;
        TermNode *term;

        SimpleExpressionNode(TermNode *term, SimpleExpressionNode *simple_expression = nullptr, FinalNode *addop = nullptr) : AST(NodeType::simple_expression){
            this->simple_expression = simple_expression;
            this->addop = addop;
            this->term = term;
        }
        ~SimpleExpressionNode();

        std::string trans() const override;
};

class TermNode : public AST { 
    public:
        TermNode *term;
        FinalNode *mulop;
        FactorNode *factor;

        TermNode(FactorNode *factor, TermNode *term = nullptr, FinalNode *mulop = nullptr) : AST(NodeType::term){
            this->term = term;
            this->mulop = mulop;
            this->factor = factor;
        }
        ~TermNode();

        std::string trans() const override;
};

class FactorNode : public AST {
    public:
        FinalNode *num;
        FinalNode *id;
        ExpressionNode *expression;
        ExpressionListNode *expression_list;
        VariableNode *variable;
        FinalNode *not_uminus;
        FactorNode *factor;
        int kind = 0;

        FactorNode(FinalNode *num) : AST(NodeType::factor) {
            this->num = num;
            this->kind = 1;
        } // factor → num

        FactorNode(VariableNode *variable) : AST(NodeType::factor) {
            this->variable = variable;
            this->kind = 2;
        } // factor → variable

        FactorNode(ExpressionNode *expression) : AST(NodeType::factor) {
            this->expression = expression;
            this->kind = 3;
        } // factor → ( expression )

        FactorNode(FinalNode *id, ExpressionListNode *expression_list) : AST(NodeType::factor) {
            this->id = id;
            this->expression_list = expression_list;
            this->kind = 4;
        } // factor → id ( expression_list )

        FactorNode(FinalNode *not_uminus, FactorNode *factor) : AST(NodeType::factor) {
            this->not_uminus = not_uminus;
            this->factor = factor;
            this->kind = 5;
        } // factor → not factor | uminus factor
        ~FactorNode();

        std::string trans() const override;
};

ProgramStructNode::~ProgramStructNode() {
    delete program_body;
    delete program_head;
}
ProgramHeadNode::~ProgramHeadNode() {
    delete id;
    if(id_list != nullptr) delete id_list;
}
ProgramBodyNode::~ProgramBodyNode() {
    delete const_declarations;
    delete var_declarations;
    delete subprogram_declarations;
    delete compound_statement;
}
IdListNode::~IdListNode() {
    delete id;
    if(id_list != nullptr) delete id_list;
}
ConstDeclarationsNode::~ConstDeclarationsNode() {
    if(const_declaration != nullptr) delete const_declaration;
}
ConstDeclarationNode::~ConstDeclarationNode() {
    delete id;
    delete const_value;
    if(const_declaration != nullptr) delete const_declaration;
}
ConstValueNode::~ConstValueNode() {
    delete numletter;
    if(op != nullptr) delete op;
}
VarDeclarationsNode::~VarDeclarationsNode() {
    if(var_declaration != nullptr) delete var_declaration;
}
VarDeclarationNode::~VarDeclarationNode() {
    delete id_list;
    delete type;
    if(var_declaration != nullptr) delete var_declaration;
}
TypeNode::~TypeNode() {
    delete basic_type;
    if(period != nullptr) delete period;
}
BasicTypeNode::~BasicTypeNode() {
    delete basic_type;
}
PeriodNode::~PeriodNode() {
    delete num1;
    delete num2;
    if(period != nullptr) delete period;
}
SubprogramDeclarationsNode::~SubprogramDeclarationsNode() {
    if(subprogram_declarations != nullptr) delete subprogram_declarations;
    if(subprogram != nullptr) delete subprogram;
}
SubprogramNode::~SubprogramNode() {
    delete subprogram_head;
    delete subprogram_body;
}
SubprogramHeadNode::~SubprogramHeadNode() {
    delete id;
    delete formal_parameter;
    if(basic_type != nullptr) delete basic_type;
}
FormalParameterNode::~FormalParameterNode() {
    if(parameter_list != nullptr) delete parameter_list;
}
ParameterListNode::~ParameterListNode() {
    delete parameter;
    if(parameter_list != nullptr) delete parameter_list;
}
ParameterNode::~ParameterNode() {
    if(var_parameter != nullptr) delete var_parameter;
    if(value_parameter != nullptr) delete value_parameter;
}
VarParameterNode::~VarParameterNode() {
    delete value_parameter;
}
ValueParameterNode::~ValueParameterNode() {
    delete id_list;
    delete basic_type;
}
SubprogramBodyNode::~SubprogramBodyNode() {
    delete const_declarations;
    delete var_declarations;
    delete compound_statement;
}
CompoundStatementNode::~CompoundStatementNode() {
    delete statement_list;
}
StatementListNode::~StatementListNode() {
    delete statement;
    if(statement_list != nullptr) delete statement_list;
}
StatementNode::~StatementNode() {
    if(variable != nullptr) delete variable;
    if(expression != nullptr) delete expression;
    if(id != nullptr) delete id;
    if(procedure_call != nullptr) delete procedure_call;
    if(compound_statement != nullptr) delete compound_statement;
    if(statement != nullptr) delete statement;
    if(else_part != nullptr) delete else_part;
    if(expression_2 != nullptr) delete expression_2;
    if(variable_list != nullptr) delete variable_list;
    if(expression_list != nullptr) delete expression_list;
    if(w_r != nullptr) delete w_r;
}
VariableListNode::~VariableListNode() {
    delete variable;
    if(variable_list != nullptr) delete variable_list;
}
VariableNode::~VariableNode() {
    delete id;
    delete id_varpart;
}
IdVarpartNode::~IdVarpartNode() {
    if(expression_list != nullptr) delete expression_list;
}
ProcedureCallNode::~ProcedureCallNode() {
    delete id;
    if(expression_list != nullptr) delete expression_list;
}
ElsePartNode::~ElsePartNode() {
    if(statement != nullptr) delete statement;
}
ExpressionListNode::~ExpressionListNode() {
    delete expression;
    if(expression_list != nullptr) delete expression_list;
}
ExpressionNode::~ExpressionNode() {
    delete simple_expression;
    if(relop != nullptr) delete relop;
    if(simple_expression_2 != nullptr) delete simple_expression_2;
}
SimpleExpressionNode::~SimpleExpressionNode()  {
    delete term;
    if(addop != nullptr) delete addop;
    if(simple_expression != nullptr) delete simple_expression;
}
TermNode::~TermNode() {
    delete factor;
    if(term != nullptr) delete term;
    if(mulop != nullptr) delete mulop;
}
FactorNode::~FactorNode() {
    if(num != nullptr) delete num;
    if(id != nullptr) delete id;
    if(expression != nullptr) delete expression;
    if(expression_list != nullptr) delete expression_list;
    if(variable != nullptr) delete variable;
    if(not_uminus != nullptr) delete not_uminus;
    if(factor != nullptr) delete factor;
}

#endif