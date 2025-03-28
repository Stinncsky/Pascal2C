%{
    #include "./header/syntax.hh"
    #include "./header/token.hh"
    #include "./header/AST.hh"
    #include "./AST.cc"
    #include <cstdio>
    #include <cstdlib>
    #define YYLEX yylex

    void yyerror(const char *s);
    extern int yylineno;
    extern int yydebug;
    
    extern std::vector<Token> tokens;  // 声明词法分析结果
    extern int tokenIndex;              // 当前 Token 索引
    extern int yylex();
    extern Syntax* syntax;
%}

%debug


%union {
    Token* token;
    AST* ast;
}
// **声明终结符**
%token <token> Identifier Number String_var Char_var ProgramKey Const Var Array Of Basictype Procedure Function Begin End If Then For To Do Read Write Else Booltype Notop Mulop Addop Relop Assignop Dotdot Semi Dot Lparen Rparen Lbra Rbra Colon Comma Null While


// **声明非终结符**
%type <ast> ProgramStructNode ProgramHeadNode ProgramBodyNode IdListNode 
%type <ast> ConstDeclarationsNode ConstDeclarationNode ConstValueNode
%type <ast> VarDeclarationsNode VarDeclarationNode TypeNode BasicTypeNode PeriodNode 
%type <ast> SubprogramDeclarationsNode SubprogramNode SubprogramHeadNode FormalParameterNode ParameterListNode
%type <ast> ParameterNode VarParameterNode ValueParameterNode SubprogramBodyNode CompoundStatementNode 
%type <ast> StatementListNode StatementNode VariableNode VariableListNode IdVarpartNode 
%type <ast> ProcedureCallNode ElsePartNode ExpressionListNode ExpressionNode SimpleExpressionNode TermNode FactorNode

%start ProgramStructNode


%%
ProgramStructNode: ProgramHeadNode Semi ProgramBodyNode Dot {
    syntax->tree = new ProgramStructNode(dynamic_cast<ProgramHeadNode*>($1), dynamic_cast<ProgramBodyNode*>($3));
};


ProgramHeadNode: ProgramKey Identifier {
    FinalNode* id = new FinalNode(*$2);
    $$ = new ProgramHeadNode(id);
} | ProgramKey Identifier Lparen IdListNode Rparen {
    FinalNode* id = new FinalNode(*$2);
    $$ = new ProgramHeadNode(id, dynamic_cast<IdListNode*>($4));
} 

ProgramBodyNode: ConstDeclarationsNode VarDeclarationsNode SubprogramDeclarationsNode CompoundStatementNode {
    $$ = new ProgramBodyNode(dynamic_cast<ConstDeclarationsNode*>($1),
    dynamic_cast<VarDeclarationsNode*>($2),
    dynamic_cast<SubprogramDeclarationsNode*>($3),
    dynamic_cast<CompoundStatementNode*>($4));
}

IdListNode: Identifier {
    FinalNode* id = new FinalNode(*$1);
    $$ = new IdListNode(id);
} | IdListNode Comma Identifier {
        FinalNode* id = new FinalNode(*$3);
        IdListNode* idList = dynamic_cast<IdListNode*>($1);
        $$ = new IdListNode(id, idList);
}


ConstDeclarationsNode:
    {
        $$ = new ConstDeclarationsNode();
    }
    | Const ConstDeclarationNode Semi {
        $$ = new ConstDeclarationsNode(dynamic_cast<ConstDeclarationNode*>($2));
    }


ConstDeclarationNode: Identifier Relop ConstValueNode {
    if($2->property == "=") {
        FinalNode* id = new FinalNode(*$1);
        $$ = new ConstDeclarationNode(id, dynamic_cast<ConstValueNode*>($3));
    }
    else {
        yyerror("Expected '='");
        YYERROR;
    }
}
| ConstDeclarationNode Semi Identifier Relop ConstValueNode {
    if($4->property == "=") {
        FinalNode* id = new FinalNode(*$3);
        $$ = new ConstDeclarationNode(id, dynamic_cast<ConstValueNode*>($5), dynamic_cast<ConstDeclarationNode*>($1));
    }
    else {
        yyerror("Expected '='");
        YYERROR;
    }
}

ConstValueNode: Addop Number {
    if($1->property == "+" || $1->property == "-") {
        FinalNode* op = new FinalNode(*$1);
        FinalNode* num = new FinalNode(*$2);
        $$ = new ConstValueNode(op,num);
    } else {
        yyerror("Expected '+' or '-'");
        YYERROR;
    }
} | Number {
    FinalNode* num = new FinalNode(*$1);
    $$ = new ConstValueNode(num);
} | Char_var {
    FinalNode* num = new FinalNode(*$1);
    $$ = new ConstValueNode(num);
} | String_var {
    FinalNode* num = new FinalNode(*$1);
    $$ = new ConstValueNode(num);
}


VarDeclarationsNode:
    {
        $$ = new VarDeclarationsNode();
    }
    | Var VarDeclarationNode Semi {
        $$ = new VarDeclarationsNode(dynamic_cast<VarDeclarationNode*>($2));
    }

VarDeclarationNode: IdListNode Colon TypeNode {
    $$ = new VarDeclarationNode(dynamic_cast<IdListNode*>($1), dynamic_cast<TypeNode*>($3));

} | VarDeclarationNode Semi IdListNode Colon TypeNode {
    $$ = new VarDeclarationNode(dynamic_cast<IdListNode*>($3), dynamic_cast<TypeNode*>($5), dynamic_cast<VarDeclarationNode*>($1));
}


TypeNode:
    BasicTypeNode {
        $$ = new TypeNode(dynamic_cast<BasicTypeNode*>($1));
    }
    | Array Lbra PeriodNode Rbra Of BasicTypeNode {
        $$ = new TypeNode(dynamic_cast<BasicTypeNode*>($6), dynamic_cast<PeriodNode*>($3));
    }


BasicTypeNode:
    Basictype {
        if ($1->property == "integer" || 
            $1->property == "real" || 
            $1->property == "boolean" || 
            $1->property == "char") {
            FinalNode* id = new FinalNode(*$1);
            $$ = new BasicTypeNode(id);
        } else {
            yyerror("Expected 'integer', 'real', 'boolean', or 'char' keyword");
            YYERROR; // 强制回溯，避免污染其他规则
        }
    }

PeriodNode: Number Dotdot Number {
    if($2->property == "..") {
        FinalNode* id1 = new FinalNode(*$1);
        FinalNode* id2 = new FinalNode(*$3);
        $$ = new PeriodNode(id1, id2);
    }
    else {
        yyerror("Expected '..' operator");
        YYERROR;
    }
}| Char_var Dotdot Char_var {
    if($2->property == "..") {
        FinalNode* id1 = new FinalNode(*$1);
        FinalNode* id2 = new FinalNode(*$3);
        $$ = new PeriodNode(id1,id2);
    }
    else {
        yyerror("Expected '..' operator");
        YYERROR;
    }
} | PeriodNode Comma Number Dotdot Number {
    if($4->property == ".." && $2->property == ",") {
        FinalNode* id1 = new FinalNode(*$3);
        FinalNode* id2 = new FinalNode(*$5);
        $$ = new PeriodNode(id1, id2, dynamic_cast<PeriodNode*>($1));
    }
    else {
        yyerror("Expected '..' or ',' operator");
        YYERROR;
    }
} | PeriodNode Comma Char_var Dotdot Char_var {
    if($4->property == ".." && $2->property == ",") {
        FinalNode* id1 = new FinalNode(*$3);
        FinalNode* id2 = new FinalNode(*$5);
        $$ = new PeriodNode(id1, id2, dynamic_cast<PeriodNode*>($1));
    }
    else {
        yyerror("Expected '..' or ',' operator");
        YYERROR;
    }
} 


SubprogramDeclarationsNode: {
    $$ = new SubprogramDeclarationsNode();
} | SubprogramDeclarationsNode SubprogramNode Semi {
    $$ = new SubprogramDeclarationsNode(dynamic_cast<SubprogramDeclarationsNode*>($1), dynamic_cast<SubprogramNode*>($2));
}

SubprogramNode: SubprogramHeadNode Semi SubprogramBodyNode {
    if($2->property == ";") {
        $$ = new SubprogramNode(dynamic_cast<SubprogramHeadNode*>($1), dynamic_cast<SubprogramBodyNode*>($3));
    }
    else {
        yyerror("Expected ';'");
        YYERROR;
    }
}

SubprogramHeadNode: Procedure Identifier FormalParameterNode {
    FinalNode* id = new FinalNode(*$2);
    $$ = new SubprogramHeadNode(id, dynamic_cast<FormalParameterNode*>($3));

} | Function Identifier FormalParameterNode Colon BasicTypeNode {
    FinalNode* id = new FinalNode(*$2);
    $$ = new SubprogramHeadNode(id, dynamic_cast<FormalParameterNode*>($3), dynamic_cast<BasicTypeNode*>($5));
} 

FormalParameterNode: {
    $$ = new FormalParameterNode();
} | Lparen ParameterListNode Rparen {
    $$ = new FormalParameterNode(dynamic_cast<ParameterListNode*>($2));
} | Lparen Rparen {
    $$ = new FormalParameterNode();
}

ParameterListNode: ParameterNode {
    $$ = new ParameterListNode(dynamic_cast<ParameterNode*>($1));
} | ParameterListNode Semi ParameterNode {
    $$ = new ParameterListNode(dynamic_cast<ParameterNode*>($3), dynamic_cast<ParameterListNode*>($1));
}

ParameterNode: VarParameterNode {
    $$ = new ParameterNode(dynamic_cast<VarParameterNode*>($1));
} | ValueParameterNode {
    $$ = new ParameterNode(dynamic_cast<ValueParameterNode*>($1));
}

VarParameterNode: Var ValueParameterNode {
    $$ = new VarParameterNode(dynamic_cast<ValueParameterNode*>($2));
}

ValueParameterNode: IdListNode Colon BasicTypeNode {
    $$ = new ValueParameterNode(dynamic_cast<IdListNode*>($1), dynamic_cast<BasicTypeNode*>($3));
}

SubprogramBodyNode: ConstDeclarationsNode VarDeclarationsNode CompoundStatementNode {
    $$ = new SubprogramBodyNode(dynamic_cast<ConstDeclarationsNode*>($1), dynamic_cast<VarDeclarationsNode*>($2), dynamic_cast<CompoundStatementNode*>($3));
}

CompoundStatementNode: Begin StatementListNode End {
    $$ = new CompoundStatementNode(dynamic_cast<StatementListNode*>($2));
} 

StatementListNode: StatementNode {
    $$ = new StatementListNode(dynamic_cast<StatementNode*>($1));
} | StatementListNode Semi StatementNode {
    $$ = new StatementListNode(dynamic_cast<StatementNode*>($3), dynamic_cast<StatementListNode*>($1));

}

StatementNode: {
    $$ = new StatementNode();
} | VariableNode Assignop ExpressionNode {
    if($2->property == ":="){
        $$ = new StatementNode(dynamic_cast<VariableNode*>($1), dynamic_cast<ExpressionNode*>($3));
    }
    else {
        yyerror("Expected ':=' operator");
        YYERROR;
    }
} | Identifier Assignop ExpressionNode {
    if($2->property == ":="){
        FinalNode* id = new FinalNode(*$1);
        $$ = new StatementNode(id, dynamic_cast<ExpressionNode*>($3));
    }
    else {
        yyerror("Expected ':=' operator");
        YYERROR;
    }
} | ProcedureCallNode {
    $$ = new StatementNode(dynamic_cast<ProcedureCallNode*>($1));
} | CompoundStatementNode {
    $$ = new StatementNode(dynamic_cast<CompoundStatementNode*>($1));
} | If ExpressionNode Then StatementNode ElsePartNode {
    $$ = new StatementNode(dynamic_cast<ExpressionNode*>($2), dynamic_cast<StatementNode*>($4), dynamic_cast<ElsePartNode*>($5));
} | For Identifier Assignop ExpressionNode To ExpressionNode Do StatementNode {
    if($3->property == ":="){
        FinalNode* id = new FinalNode(*$2);
        $$ = new StatementNode(id, dynamic_cast<ExpressionNode*>($4), dynamic_cast<ExpressionNode*>($6), dynamic_cast<StatementNode*>($8));
    }
    else {
        yyerror("Expected ':=' operator");
        YYERROR;
    }
} | Read Lparen VariableListNode Rparen {
    FinalNode* Re = new FinalNode(*$1);
    $$ = new StatementNode(Re, dynamic_cast<VariableListNode*>($3));
} | Write Lparen ExpressionListNode Rparen {
    FinalNode* Wr = new FinalNode(*$1);
    $$ = new StatementNode(Wr, dynamic_cast<ExpressionListNode*>($3));
} | While ExpressionNode Do StatementNode{ // while语句拓展
    $$ = new StatementNode(dynamic_cast<ExpressionNode*>($2), dynamic_cast<StatementNode*>($4));
}

VariableListNode: VariableNode {
    $$ = new VariableListNode(dynamic_cast<VariableNode*>($1));
} | VariableListNode Comma VariableNode {
    $$ = new VariableListNode(dynamic_cast<VariableNode*>($3), dynamic_cast<VariableListNode*>($1));
}

VariableNode: Identifier IdVarpartNode {
    FinalNode* id = new FinalNode(*$1);
    $$ = new VariableNode(id, dynamic_cast<IdVarpartNode*>($2));
}

IdVarpartNode: {
    $$ = new IdVarpartNode();
} | Lbra ExpressionListNode Rbra {
    $$ = new IdVarpartNode(dynamic_cast<ExpressionListNode*>($2));
}

ProcedureCallNode: Identifier {
    FinalNode* id = new FinalNode(*$1);
    $$ = new ProcedureCallNode(id);
} | Identifier Lparen ExpressionListNode Rparen {
    FinalNode* id = new FinalNode(*$1);
    $$ = new ProcedureCallNode(id, dynamic_cast<ExpressionListNode*>($3));
} | Identifier Lparen Rparen{
    FinalNode* id = new FinalNode(*$1);
    $$ = new ProcedureCallNode(id); // 语法拓展：无参数过程调用支持 foo()
}

ElsePartNode:  {
    $$ = new ElsePartNode();
} | Else StatementNode {
    $$ = new ElsePartNode(dynamic_cast<StatementNode*>($2));
} 

ExpressionListNode: ExpressionNode {
    $$ = new ExpressionListNode(dynamic_cast<ExpressionNode*>($1));
} | ExpressionListNode Comma ExpressionNode {
    $$ = new ExpressionListNode(dynamic_cast<ExpressionNode*>($3), dynamic_cast<ExpressionListNode*>($1));
}

ExpressionNode: SimpleExpressionNode {
    $$ = new ExpressionNode(dynamic_cast<SimpleExpressionNode*>($1));
} | SimpleExpressionNode Relop SimpleExpressionNode {
    FinalNode* id = new FinalNode(*$2);
    $$ = new ExpressionNode(dynamic_cast<SimpleExpressionNode*>($1), id, dynamic_cast<SimpleExpressionNode*>($3));
}

SimpleExpressionNode: TermNode {
    $$ = new SimpleExpressionNode(dynamic_cast<TermNode*>($1));
} | SimpleExpressionNode Addop TermNode {
    FinalNode* op = new FinalNode(*$2);
    $$ = new SimpleExpressionNode(dynamic_cast<TermNode*>($3), dynamic_cast<SimpleExpressionNode*>($1), op);
}

TermNode: FactorNode {
    $$ = new TermNode(dynamic_cast<FactorNode*>($1));
} | TermNode Mulop FactorNode {
    FinalNode* op = new FinalNode(*$2);
    $$ = new TermNode(dynamic_cast<FactorNode*>($3), dynamic_cast<TermNode*>($1), op);
}

FactorNode: Number {
    FinalNode* id = new FinalNode(*$1);
    $$ = new FactorNode(id);
} | VariableNode {
    $$ = new FactorNode(dynamic_cast<VariableNode*>($1));
} | Lparen ExpressionNode Rparen {
    $$ = new FactorNode(dynamic_cast<ExpressionNode*>($2));
} | Identifier Lparen ExpressionListNode Rparen {
    FinalNode* id = new FinalNode(*$1);
    $$ = new FactorNode(id, dynamic_cast<ExpressionListNode*>($3));
} | Notop FactorNode {
    if($1->property == "not"){
        FinalNode* id = new FinalNode(*$1);
        $$ = new FactorNode(id, dynamic_cast<FactorNode*>($2));
    }
    else {
        yyerror("Expected 'not' keyword");
        YYERROR;
    }
} | Addop FactorNode {
    if($1->property == "-" || $1->property == "+"){
        FinalNode* op = new FinalNode(*$1);
        $$ = new FactorNode(op,dynamic_cast<FactorNode*>($2));
    }
    else {
        yyerror("Expected '-' or '+'");
        YYERROR;
    }
} | Booltype {
    FinalNode* id = new FinalNode(*$1);
    $$ = new FactorNode(id);
} | Identifier Lparen Rparen{
    FinalNode* id = new FinalNode(*$1);
    IdVarpartNode* fake_idvar = new IdVarpartNode();
    VariableNode* fake_var = new VariableNode(id, fake_idvar);
    $$ = new FactorNode(fake_var); // 测试用例21: 无参数函数 a := foo(); write(foo())
}




%%

int yylex() {
    if (tokenIndex >= static_cast<int>(tokens.size())) return 0;
    Token* current = &tokens[tokenIndex];
    yylval.token = current;

    // 将词法分析器的 TokenType 数值(1..n) +257 转换为 Bison 的数值
    int bison_type = current->to_yacc_token() + 257;
    tokenIndex++;
    return bison_type;
}

void yyerror(const char* msg) {
    fprintf(stderr, "Syntax Error: %s\n", msg);
}