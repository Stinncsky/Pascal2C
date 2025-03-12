#include "./header/AST.hh"

class FinalNode : public AST { // 终结符节点
    public:
        Token token;
        FinalNode(Token token) : AST(NodeType::Final){
            this->token = token;
        }
};

class ProgramStructNode : public AST { 
    public:
        ProgramHeadNode *program_head;
        ProgramBodyNode *program_body;

        ProgramStructNode(ProgramHeadNode *program_head, ProgramBodyNode *program_body) : AST(NodeType::programStruct){
            this->program_head = program_head;
            this->program_body = program_body;
        }
};

class ProgramHeadNode : public AST { 
    public:
        FinalNode *id;
        IdListNode *id_list;

        ProgramHeadNode(FinalNode *id, IdListNode *id_list = nullptr) : AST(NodeType::program_head){
            this->id = id;
            this->id_list = id_list;
        }
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
};

class IdListNode : public AST { 
    public:
        FinalNode *id;
        IdListNode *id_list;

        IdListNode(FinalNode *id, IdListNode *id_list = nullptr) : AST(NodeType::idList){
            this->id = id;
            this->id_list = id_list;
        }
};

class ConstDeclarationsNode : public AST { 
    public:
        ConstDeclarationNode *const_declaration;

        ConstDeclarationsNode(ConstDeclarationNode *const_declaration = nullptr) : AST(NodeType::const_declarations){
            this->const_declaration = const_declaration;
        }
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
};

class ConstValueNode : public AST { 
    public:
        FinalNode *op;
        FinalNode *numletter;

        ConstValueNode(FinalNode *op = nullptr, FinalNode *numletter) : AST(NodeType::const_value){
            this->op = op;
            this->numletter = numletter;
        }
};

class VarDeclarationsNode : public AST { 
    public:
        VarDeclarationNode *var_declaration;

        VarDeclarationsNode(VarDeclarationNode *var_declaration = nullptr) : AST(NodeType::var_declarations){
            this->var_declaration = var_declaration;
        }
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
};

class TypeNode : public AST { 
    public:
        BasicTypeNode *basic_type;
        PeriodNode *period;

        TypeNode(BasicTypeNode *basic_type, PeriodNode *period = nullptr) : AST(NodeType::type){
            this->basic_type = basic_type;
            this->period = period;
        }
};

class BasicTypeNode : public AST { 
    public:
        FinalNode *basic_type;

        BasicTypeNode(FinalNode *basic_type) : AST(NodeType::basic_type){
            this->basic_type = basic_type;
        }
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
};

class SubprogramDeclarationsNode : public AST { 
    public:
        SubprogramDeclarationsNode *subprogram_declarations;
        SubprogramNode *subprogram;

        SubprogramDeclarationsNode(SubprogramDeclarationsNode *subprogram_declarations = nullptr, SubprogramNode *subprogram = nullptr) : AST(NodeType::subprogram_declarations){
            this->subprogram_declarations = subprogram_declarations;
            this->subprogram = subprogram;
        }
};

class SubprogramNode : public AST { 
    public:
        SubprogramHeadNode *subprogram_head;
        SubprogramBodyNode *subprogram_body;

        SubprogramNode(SubprogramHeadNode *subprogram_head, SubprogramBodyNode *subprogram_body) : AST(NodeType::subprogram){
            this->subprogram_head = subprogram_head;
            this->subprogram_body = subprogram_body;
        }
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
};

class FormalParameterNode : public AST { 
    public:
        ParameterListNode *parameter_list;

        FormalParameterNode(ParameterListNode *parameter_list = nullptr) : AST(NodeType::formal_parameter){
            this->parameter_list = parameter_list;
        }
};

class ParameterListNode : public AST { 
    public:
        ParameterNode *parameter;
        ParameterListNode *parameter_list;

        ParameterListNode(ParameterNode *parameter, ParameterListNode *parameter_list = nullptr) : AST(NodeType::parameter_list){
            this->parameter = parameter;
            this->parameter_list = parameter_list;
        }
};

class ParameterNode : public AST { 
    public:
        VarParameterNode *var_parameter;
        ValueParameterNode *value_parameter;

        ParameterNode(VarParameterNode *var_parameter = nullptr, ValueParameterNode *value_parameter = nullptr) : AST(NodeType::parameter){
            this->var_parameter = var_parameter;
            this->value_parameter = value_parameter;
        }
};

class VarParameterNode : public AST { 
    public:
        ValueParameterNode *value_parameter;

        VarParameterNode(ValueParameterNode *value_parameter) : AST(NodeType::var_parameter){
            this->value_parameter = value_parameter;
        }
};

class ValueParameterNode : public AST { 
    public:
        IdListNode *id_list;
        BasicTypeNode *basic_type;

        ValueParameterNode(IdListNode *id_list, BasicTypeNode *basic_type) : AST(NodeType::value_parameter){
            this->id_list = id_list;
            this->basic_type = basic_type;
        }
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
};

class CompoundStatementNode : public AST { 
    public:
        StatementListNode *statement_list;

        CompoundStatementNode(StatementListNode *statement_list) : AST(NodeType::compound_statement){
            this->statement_list = statement_list;
        }
};

class StatementListNode : public AST { 
    public:
        StatementNode *statement;
        StatementListNode *statement_list;

        StatementListNode(StatementNode *statement, StatementListNode *statement_list = nullptr) : AST(NodeType::statement_list){
            this->statement = statement;
            this->statement_list = statement_list;
        }
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

        StatementNode() : AST(NodeType::statement){} // statement → ε

        StatementNode(VariableNode *variable, ExpressionNode *expression) : AST(NodeType::statement){
            this->variable = variable;
            this->expression = expression;
        } //  statement → variable := expression

        StatementNode(FinalNode *func_id, ExpressionNode *expression) : AST(NodeType::statement){
            this->id = func_id;
            this->expression = expression;
        } //  statement → func_id := expression

        StatementNode(ProcedureCallNode *procedure_call) : AST(NodeType::statement){
            this->procedure_call = procedure_call;
        } //  statement → procedure_call

        StatementNode(CompoundStatementNode *compound_statement) : AST(NodeType::statement){
            this->compound_statement = compound_statement;
        } //  statement → compound_statement

        StatementNode(ExpressionNode *expression, StatementNode *statement, ElsePartNode *else_part) : AST(NodeType::statement){
            this->expression = expression;
            this->statement = statement;
            this->else_part = else_part;
        } //  statement → if expression then statement else_part

        StatementNode(FinalNode *id, ExpressionNode *expression, ExpressionNode *expression_2, StatementNode *statement) : AST(NodeType::statement){
            this->id = id;
            this->expression = expression;
            this->expression_2 = expression_2;
            this->statement = statement;
        } //  statement → for id := expression to expression_2 do statement

        StatementNode(FinalNode *read, VariableListNode *variable_list) : AST(NodeType::statement){
            this->w_r = read;
            this->variable_list = variable_list;
        } //  statement → read ( variable_list )

        StatementNode(FinalNode *write, ExpressionListNode *expression_list) : AST(NodeType::statement){
            this->w_r = write;
            this->expression_list = expression_list;
        } //  statement → write ( expression_list )
};

class VariableListNode : public AST { 
    public:
        VariableNode *variable;
        VariableListNode *variable_list;

        VariableListNode(VariableNode *variable, VariableListNode *variable_list = nullptr) : AST(NodeType::variable_list){
            this->variable = variable;
            this->variable_list = variable_list;
        }
};

class VariableNode : public AST { 
    public:
        FinalNode *id;
        IdVarpartNode *id_varpart;

        VariableNode(FinalNode *id, IdVarpartNode *id_varpart) : AST(NodeType::variable){
            this->id = id;
            this->id_varpart = id_varpart;
        }
};

class IdVarpartNode : public AST { 
    public:
        ExpressionListNode *expression_list;

        IdVarpartNode(ExpressionListNode *expression_list = nullptr) : AST(NodeType::id_varpart){
            this->expression_list = expression_list;
        }
};

class ProcedureCallNode : public AST { 
    public:
        FinalNode *id;
        ExpressionListNode *expression_list;

        ProcedureCallNode(FinalNode *id, ExpressionListNode *expression_list = nullptr) : AST(NodeType::procedure_call){
            this->id = id;
            this->expression_list = expression_list;
        }
};

class ElsePartNode : public AST { 
    public:
        StatementNode *statement;

        ElsePartNode(StatementNode *statement = nullptr) : AST(NodeType::else_part){
            this->statement = statement;
        }
};

class ExpressionListNode : public AST { 
    public:
        ExpressionNode *expression;
        ExpressionListNode *expression_list;

        ExpressionListNode(ExpressionNode *expression, ExpressionListNode *expression_list = nullptr) : AST(NodeType::expression_list){
            this->expression = expression;
            this->expression_list = expression_list;
        }
};

class ExpressionNode : public AST { 
    public:
        SimpleExpressionNode *simple_expression;
        FinalNode *relop;
        SimpleExpressionNode *simple_expression_2;

        ExpressionNode(SimpleExpressionNode *simple_expression) : AST(NodeType::expression){
            this->simple_expression = simple_expression;
        } // expression → simple_expression

        ExpressionNode(SimpleExpressionNode *simple_expression, FinalNode *relop, SimpleExpressionNode *simple_expression_2) : AST(NodeType::expression){
            this->simple_expression = simple_expression;
            this->relop = relop;
            this->simple_expression_2 = simple_expression_2;
        } // expression → simple_expression relop simple_expression
};

class SimpleExpressionNode : public AST { 
    public:
        SimpleExpressionNode *simple_expression;
        FinalNode *addop;
        TermNode *term;

        SimpleExpressionNode(SimpleExpressionNode *simple_expression = nullptr, FinalNode *addop = nullptr, TermNode *term) : AST(NodeType::simple_expression){
            this->simple_expression = simple_expression;
            this->addop = addop;
            this->term = term;
        }
};

class TermNode : public AST { 
    public:
        TermNode *term;
        FinalNode *mulop;
        FactorNode *factor;

        TermNode(TermNode *term = nullptr, FinalNode *mulop = nullptr, FactorNode *factor) : AST(NodeType::term){
            this->term = term;
            this->mulop = mulop;
            this->factor = factor;
        }
};

class FactorNode : public AST { 
    public:
        FinalNode *num;
        FinalNode *id;
        ExpressionListNode *expression_list;
        VariableNode *variable;
        FinalNode *not_keyword;
        FinalNode *uminus;
        FactorNode *factor;

        FactorNode(FinalNode *num) : AST(NodeType::factor){
            this->num = num;
        } // factor → num

        FactorNode(FinalNode *id, ExpressionListNode *expression_list) : AST(NodeType::factor){
            this->id = id;
            this->expression_list = expression_list;
        } // factor → id ( expression_list )

        FactorNode(VariableNode *variable) : AST(NodeType::factor){
            this->variable = variable;
        } // factor → variable

        FactorNode(FinalNode *not_keyword, FactorNode *factor) : AST(NodeType::factor){
            this->not_keyword = not_keyword;
            this->factor = factor;
        } // factor → not factor

        FactorNode(FinalNode *uminus, FactorNode *factor) : AST(NodeType::factor){
            this->uminus = uminus;
            this->factor = factor;
        } // factor → uminus factor
};