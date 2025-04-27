%{
    #include "./header/syntax.hh"
    #include "./header/token.hh"
    #include "./header/AST.hh"
    #include "./AST.cc"
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #define YYLEX yylex

    void yyerror(const char *s);
    void yyerror_at(const char *s, int line, int column, const Token * token = nullptr);
    int yylineno;
    int line = 1;
    int column = 1; 
    extern int yydebug;

    extern std::vector<Token> tokens;  // 声明词法分析结果
    extern int tokenIndex;              // 当前 Token 索引
    extern int yylex();
    extern Syntax* syntax;
%}
%define parse.error verbose
%define api.token.prefix {Tk_}
%debug


%union {
    Token* token;
    AST* ast;
}
// **声明终结符**
%token <token> ID NUM STR_V CHAR_V PROGRAM CONST VAR ARRAY OF TYPE PROCEDURE FUNCTION BEGIN END IF THEN FOR TO DO READ WRITE ELSE BOOL NOTOP MULOP ADDOP RELOP ASSIGNOP DOTDOT SEMI DOT LPAREN RPAREN LBRA RBRA COLON COMMA Null WHILE BREAK


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
ProgramStructNode: ProgramHeadNode SEMI ProgramBodyNode DOT {
    syntax->tree = new ProgramStructNode(dynamic_cast<ProgramHeadNode*>($1), dynamic_cast<ProgramBodyNode*>($3));
} | error {
    yyerror("Unrecoverable errors occurred");
    while(yychar != Tk_YYEOF) {
        yychar = yylex();
    }
    $$ = nullptr; 
} | ProgramHeadNode ProgramBodyNode error {
    syntax->tree = new ProgramStructNode(dynamic_cast<ProgramHeadNode*>($1), dynamic_cast<ProgramBodyNode*>($2));
    yyerror("Expected '.' at the end of the program");
}

ProgramHeadNode: PROGRAM ID {
    FinalNode* id = new FinalNode(*$2);
    $$ = new ProgramHeadNode(id);
} | PROGRAM ID LPAREN IdListNode RPAREN {
    FinalNode* id = new FinalNode(*$2);
    $$ = new ProgramHeadNode(id, dynamic_cast<IdListNode*>($4));
} | PROGRAM error {
    yyerror("Expected program name after 'program' keyword");
    FinalNode* id = new FinalNode(*$1);
    $$ = new ProgramHeadNode(id);
    yyerrok;
}

ProgramBodyNode: ConstDeclarationsNode VarDeclarationsNode SubprogramDeclarationsNode CompoundStatementNode {
    $$ = new ProgramBodyNode(dynamic_cast<ConstDeclarationsNode*>($1),
    dynamic_cast<VarDeclarationsNode*>($2),
    dynamic_cast<SubprogramDeclarationsNode*>($3),
    dynamic_cast<CompoundStatementNode*>($4));
}

IdListNode: ID {
    FinalNode* id = new FinalNode(*$1);
    $$ = new IdListNode(id);
} | IdListNode COMMA ID {
    FinalNode* id = new FinalNode(*$3);
    IdListNode* idList = dynamic_cast<IdListNode*>($1);
    $$ = new IdListNode(id, idList);
} | IdListNode error ID {
    yyerror_at("Expected ',' after IdListNode", $3->line, $3->column, $3);
    yyerrok;
    FinalNode* id = new FinalNode(*$3);
    IdListNode* idList = dynamic_cast<IdListNode*>($1);
    $$ = new IdListNode(id, idList);
} | IdListNode COMMA error {
    yyerror("Expected ID after ','");
    yyerrok;
    FinalNode* id = new FinalNode(*$2);
    IdListNode* idList = dynamic_cast<IdListNode*>($1);
    $$ = new IdListNode(id, idList);
}


ConstDeclarationsNode:
    {
        $$ = new ConstDeclarationsNode();
    } | CONST ConstDeclarationNode SEMI {
        $$ = new ConstDeclarationsNode(dynamic_cast<ConstDeclarationNode*>($2));
    } | CONST ConstDeclarationNode error{
        yyerror("Except ';' after ConstDeclarationsNode");
        yyerrok;
        $$ = new ConstDeclarationsNode(dynamic_cast<ConstDeclarationNode*>($2)); 
    }


ConstDeclarationNode: ID RELOP ConstValueNode {
    if($2->property == "=") {
        FinalNode* id = new FinalNode(*$1);
        $$ = new ConstDeclarationNode(id, dynamic_cast<ConstValueNode*>($3));
    }
    else {
        yyerror_at("Expected '='", $2->line, $2->column + 1, $2);
        YYERROR;
        yyerrok;
    }
} | ConstDeclarationNode SEMI ID RELOP ConstValueNode {
    if($4->property == "=") {
        FinalNode* id = new FinalNode(*$3);
        $$ = new ConstDeclarationNode(id, dynamic_cast<ConstValueNode*>($5), dynamic_cast<ConstDeclarationNode*>($1));
    }
    else {
        yyerror("Expected '='");
        YYERROR;
        yyerrok;
    }
} | ConstDeclarationNode error ID RELOP ConstValueNode {
    yyerror_at("Expected ';' after ConstDeclarationNode", $3->line, $3->column, $3);
    yyerrok;
    FinalNode* id = new FinalNode(*$3);
    $$ = new ConstDeclarationNode(id, dynamic_cast<ConstValueNode*>($5), dynamic_cast<ConstDeclarationNode*>($1));
}

ConstValueNode: ADDOP NUM {
    if($1->property == "+" || $1->property == "-") {
        FinalNode* op = new FinalNode(*$1);
        FinalNode* num = new FinalNode(*$2);
        $$ = new ConstValueNode(op,num);
    } else {
        yyerror_at("Expected '+' or '-'", $1->line, $1->column, $1);
        YYERROR;
        yyerrok;
    }
} | NUM {
    FinalNode* num = new FinalNode(*$1);
    $$ = new ConstValueNode(num);
} | CHAR_V {
    FinalNode* num = new FinalNode(*$1);
    $$ = new ConstValueNode(num);
} | STR_V {
    FinalNode* num = new FinalNode(*$1);
    $$ = new ConstValueNode(num);
}


VarDeclarationsNode: {
    $$ = new VarDeclarationsNode();
} | VAR VarDeclarationNode SEMI {
    $$ = new VarDeclarationsNode(dynamic_cast<VarDeclarationNode*>($2));
} | VAR VarDeclarationNode error {
    yyerror("Expected ';' after VarDeclarationsNode");
    yyerrok;
    $$ = new VarDeclarationsNode(dynamic_cast<VarDeclarationNode*>($2));
}

VarDeclarationNode: IdListNode COLON TypeNode {
    $$ = new VarDeclarationNode(dynamic_cast<IdListNode*>($1), dynamic_cast<TypeNode*>($3));

} | VarDeclarationNode SEMI IdListNode COLON TypeNode {
    $$ = new VarDeclarationNode(dynamic_cast<IdListNode*>($3), dynamic_cast<TypeNode*>($5), dynamic_cast<VarDeclarationNode*>($1));
} | IdListNode error TypeNode {
    yyerror("Expected ':' after IdListNode");
    yyerrok;
    $$ = new VarDeclarationNode(dynamic_cast<IdListNode*>($1), dynamic_cast<TypeNode*>($3));
} | VarDeclarationNode error IdListNode COLON TypeNode {
    yyerror("Expected ';' after VarDeclarationNode");
    yyerrok;
    $$ = new VarDeclarationNode(dynamic_cast<IdListNode*>($3), dynamic_cast<TypeNode*>($5), dynamic_cast<VarDeclarationNode*>($1));
} | VarDeclarationNode SEMI IdListNode error TypeNode {
    yyerror("Expected ':' after IdListNode");
    yyerrok;
    $$ = new VarDeclarationNode(dynamic_cast<IdListNode*>($3), dynamic_cast<TypeNode*>($5), dynamic_cast<VarDeclarationNode*>($1));
} 


TypeNode:
    BasicTypeNode {
        $$ = new TypeNode(dynamic_cast<BasicTypeNode*>($1));
    }
    | ARRAY LBRA PeriodNode RBRA OF BasicTypeNode {
        $$ = new TypeNode(dynamic_cast<BasicTypeNode*>($6), dynamic_cast<PeriodNode*>($3));
    } | error LBRA PeriodNode RBRA OF BasicTypeNode {
        yyerror_at("Expected 'array' keyword", $2->line, $2->column, $2);
        yyerrok;
    } | ARRAY error PeriodNode RBRA OF BasicTypeNode {
        yyerror_at("Expected '['", $4->line, $4->column, $4);
        yyerrok;
    } | ARRAY LBRA PeriodNode error OF BasicTypeNode {
        yyerror_at("Expected ']'", $5->line, $5->column, $5);
        yyerrok;
    } | ARRAY LBRA PeriodNode RBRA error BasicTypeNode {
        yyerror("Expected 'of'");
        yyerrok;
    } 


BasicTypeNode:
    TYPE {
        if ($1->property == "integer" || 
            $1->property == "real" || 
            $1->property == "boolean" || 
            $1->property == "char") {
            FinalNode* id = new FinalNode(*$1);
            $$ = new BasicTypeNode(id);
        } else {
            yyerror("Expected 'integer', 'real', 'boolean', or 'char' keyword");
            YYERROR; // 强制回溯，避免污染其他规则
            yyerrok;
        }
    }

PeriodNode: NUM DOTDOT NUM {
    if($2->property == "..") {
        FinalNode* id1 = new FinalNode(*$1);
        FinalNode* id2 = new FinalNode(*$3);
        $$ = new PeriodNode(id1, id2);
    }
    else {
        yyerror("Expected '..' operator");
        YYERROR;
    }
}| CHAR_V DOTDOT CHAR_V {
    if($2->property == "..") {
        FinalNode* id1 = new FinalNode(*$1);
        FinalNode* id2 = new FinalNode(*$3);
        $$ = new PeriodNode(id1,id2);
    }
    else {
        yyerror("Expected '..' operator");
        YYERROR;
    }
} | PeriodNode COMMA NUM DOTDOT NUM {
    if($4->property == ".." && $2->property == ",") {
        FinalNode* id1 = new FinalNode(*$3);
        FinalNode* id2 = new FinalNode(*$5);
        $$ = new PeriodNode(id1, id2, dynamic_cast<PeriodNode*>($1));
    }
    else {
        yyerror("Expected '..' or ',' operator");
        YYERROR;
    }
} | PeriodNode COMMA CHAR_V DOTDOT CHAR_V {
    if($4->property == ".." && $2->property == ",") {
        FinalNode* id1 = new FinalNode(*$3);
        FinalNode* id2 = new FinalNode(*$5);
        $$ = new PeriodNode(id1, id2, dynamic_cast<PeriodNode*>($1));
    }
    else {
        yyerror("Expected '..' or ',' operator");
        YYERROR;
    }
} | error DOTDOT NUM {
    yyerror_at("Expected 'num' before '..' operator", $2->line, $2->column, $2);
    yyerrok;
    FinalNode* id1 = new FinalNode(*$3);
    FinalNode* id2 = new FinalNode(*$3);
    $$ = new PeriodNode(id1, id2);
} | NUM DOTDOT error {
    yyerror("Expected 'num' after '..' operator");
    yyerrok;
    FinalNode* id1 = new FinalNode(*$1);
    FinalNode* id2 = new FinalNode(*$1);
    $$ = new PeriodNode(id1, id2);
} | PeriodNode COMMA error DOTDOT NUM {
    yyerror_at("Expected 'num' after ',' operator", $4->line, $4->column, $4);
    yyerrok;
    FinalNode* id1 = new FinalNode(*$5);
    FinalNode* id2 = new FinalNode(*$5);
    $$ = new PeriodNode(id1, id2, dynamic_cast<PeriodNode*>($1)); 
} | PeriodNode COMMA NUM DOTDOT error {
    yyerror("Expected 'num' after '..' operator");
    yyerrok;
    FinalNode* id1 = new FinalNode(*$3);
    FinalNode* id2 = new FinalNode(*$3);
    $$ = new PeriodNode(id1, id2, dynamic_cast<PeriodNode*>($1)); 
}


SubprogramDeclarationsNode: {
    $$ = new SubprogramDeclarationsNode();
} | SubprogramDeclarationsNode SubprogramNode SEMI {
    $$ = new SubprogramDeclarationsNode(dynamic_cast<SubprogramDeclarationsNode*>($1), dynamic_cast<SubprogramNode*>($2));
} | SubprogramDeclarationsNode SubprogramNode error {
    yyerror("Expected ';' after SubprogramDeclarationsNode");
    yyerrok;
    $$ = new SubprogramDeclarationsNode(dynamic_cast<SubprogramDeclarationsNode*>($1), dynamic_cast<SubprogramNode*>($2));
} 

SubprogramNode: SubprogramHeadNode SEMI SubprogramBodyNode {
    if($2->property == ";") {
        $$ = new SubprogramNode(dynamic_cast<SubprogramHeadNode*>($1), dynamic_cast<SubprogramBodyNode*>($3));
    }
    else {
        yyerror("Expected ';'");
        YYERROR;
    }
} | SubprogramHeadNode error SubprogramBodyNode {
    yyerror("Expected ';' after SubprogramHeadNode");
    yyerrok;
    $$ = new SubprogramNode(dynamic_cast<SubprogramHeadNode*>($1), dynamic_cast<SubprogramBodyNode*>($3));
} 

SubprogramHeadNode: PROCEDURE ID FormalParameterNode {
    FinalNode* id = new FinalNode(*$2);
    $$ = new SubprogramHeadNode(id, dynamic_cast<FormalParameterNode*>($3));

} | FUNCTION ID FormalParameterNode COLON BasicTypeNode {
    FinalNode* id = new FinalNode(*$2);
    $$ = new SubprogramHeadNode(id, dynamic_cast<FormalParameterNode*>($3), dynamic_cast<BasicTypeNode*>($5));
} | error ID FormalParameterNode {
    yyerror_at("Expected 'procedure' before ID", $2->line, $2->column, $2);
    yyerrok;
} | PROCEDURE error FormalParameterNode {
    yyerror("Expected 'ID' after 'procedure' keyword");
    yyerrok;
} | error ID FormalParameterNode COLON BasicTypeNode {
    yyerror_at("Expected 'procedure' before ID", $2->line, $2->column, $2);
    yyerrok;
} | FUNCTION error FormalParameterNode COLON BasicTypeNode {
    yyerror("Expected 'ID' after 'function' keyword");
    yyerrok;
} | FUNCTION ID FormalParameterNode error BasicTypeNode {
    yyerror("Expected ':' after 'function' keyword");
    yyerrok;
} 


FormalParameterNode: {
    $$ = new FormalParameterNode();
} | LPAREN ParameterListNode RPAREN {
    $$ = new FormalParameterNode(dynamic_cast<ParameterListNode*>($2));
} | LPAREN RPAREN {
    $$ = new FormalParameterNode();
} 

ParameterListNode: ParameterNode {
    $$ = new ParameterListNode(dynamic_cast<ParameterNode*>($1));
} | ParameterListNode SEMI ParameterNode {
    $$ = new ParameterListNode(dynamic_cast<ParameterNode*>($3), dynamic_cast<ParameterListNode*>($1));
} | ParameterListNode error ParameterNode {
    yyerror("Expected ';' after ParameterListNode");
    yyerrok;
    $$ = new ParameterListNode(dynamic_cast<ParameterNode*>($3), dynamic_cast<ParameterListNode*>($1));
}

ParameterNode: VarParameterNode {
    $$ = new ParameterNode(dynamic_cast<VarParameterNode*>($1));
} | ValueParameterNode {
    $$ = new ParameterNode(dynamic_cast<ValueParameterNode*>($1));
}

VarParameterNode: VAR ValueParameterNode {
    $$ = new VarParameterNode(dynamic_cast<ValueParameterNode*>($2));
} | error ValueParameterNode {
    yyerror("Expected 'var' before ValueParameterNode");
    yyerrok;
    $$ = new VarParameterNode(dynamic_cast<ValueParameterNode*>($2));
} 

ValueParameterNode: IdListNode COLON BasicTypeNode {
    $$ = new ValueParameterNode(dynamic_cast<IdListNode*>($1), dynamic_cast<BasicTypeNode*>($3));
} | IdListNode error BasicTypeNode {
    yyerror("Expected ':' after IdListNode");
    yyerrok;
    $$ = new ValueParameterNode(dynamic_cast<IdListNode*>($1), dynamic_cast<BasicTypeNode*>($3));
} 

SubprogramBodyNode: ConstDeclarationsNode VarDeclarationsNode CompoundStatementNode {
    $$ = new SubprogramBodyNode(dynamic_cast<ConstDeclarationsNode*>($1), dynamic_cast<VarDeclarationsNode*>($2), dynamic_cast<CompoundStatementNode*>($3));
}

CompoundStatementNode: BEGIN StatementListNode END {
    $$ = new CompoundStatementNode(dynamic_cast<StatementListNode*>($2));
} | BEGIN StatementListNode error {
    yyerror("Expected 'end' after statement list");
    yyerrok;
    $$ = new CompoundStatementNode(dynamic_cast<StatementListNode*>($2));
}

StatementListNode: StatementNode {
    $$ = new StatementListNode(dynamic_cast<StatementNode*>($1));
} | StatementListNode SEMI StatementNode {
    $$ = new StatementListNode(dynamic_cast<StatementNode*>($3), dynamic_cast<StatementListNode*>($1));
}

StatementNode: {
    $$ = new StatementNode();
} | VariableNode ASSIGNOP ExpressionNode {
    if($2->property == ":="){
        $$ = new StatementNode(dynamic_cast<VariableNode*>($1), dynamic_cast<ExpressionNode*>($3));
    }
    else {
        yyerror("Expected ':=' operator");
        YYERROR;
    }
} | ID ASSIGNOP ExpressionNode {
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
} | IF ExpressionNode THEN StatementNode ElsePartNode {
    $$ = new StatementNode(dynamic_cast<ExpressionNode*>($2), dynamic_cast<StatementNode*>($4), dynamic_cast<ElsePartNode*>($5));
} | FOR ID ASSIGNOP ExpressionNode TO ExpressionNode DO StatementNode {
    if($3->property == ":="){
        FinalNode* id = new FinalNode(*$2);
        $$ = new StatementNode(id, dynamic_cast<ExpressionNode*>($4), dynamic_cast<ExpressionNode*>($6), dynamic_cast<StatementNode*>($8));
    }
    else {
        yyerror("Expected ':=' operator");
        YYERROR;
    }
} | FOR error ASSIGNOP ExpressionNode TO ExpressionNode DO StatementNode {
    yyerror("Expected 'ID' after 'for' keyword");
    yyerrok;
    FinalNode* id = new FinalNode(Token("errId", TokenType::Identifier));
    $$ = new StatementNode(id, dynamic_cast<ExpressionNode*>($4), dynamic_cast<ExpressionNode*>($6), dynamic_cast<StatementNode*>($8));
} | FOR ID error ExpressionNode TO ExpressionNode DO StatementNode {
    yyerror("Expected ':=' operator after 'ID'");
    yyerrok;
    FinalNode* id = new FinalNode(*$2);
    $$ = new StatementNode(id, dynamic_cast<ExpressionNode*>($4), dynamic_cast<ExpressionNode*>($6), dynamic_cast<StatementNode*>($8));
} | FOR ID ASSIGNOP ExpressionNode error ExpressionNode DO StatementNode {
    yyerror("Expected 'to' after 'ExpressionNode'");
    yyerrok;
    FinalNode* id = new FinalNode(*$2);
    $$ = new StatementNode(id, dynamic_cast<ExpressionNode*>($4), dynamic_cast<ExpressionNode*>($6), dynamic_cast<StatementNode*>($8));
} | FOR ID ASSIGNOP ExpressionNode TO ExpressionNode error StatementNode {
    yyerror("Expected 'do' after 'ExpressionNode'");
    yyerrok;
    FinalNode* id = new FinalNode(*$2);
    $$ = new StatementNode(id, dynamic_cast<ExpressionNode*>($4), dynamic_cast<ExpressionNode*>($6), dynamic_cast<StatementNode*>($8));
} | READ LPAREN VariableListNode RPAREN {
    FinalNode* Re = new FinalNode(*$1);
    $$ = new StatementNode(Re, dynamic_cast<VariableListNode*>($3));
} | READ error VariableListNode RPAREN {
    yyerror("Expected '(' after 'read' keyword");
    yyerrok;
    FinalNode* Re = new FinalNode(*$1);
    $$ = new StatementNode(Re, dynamic_cast<VariableListNode*>($3));
} | READ LPAREN VariableListNode error {
    yyerror("Expected ')' after 'read' keyword");
    yyerrok;
    FinalNode* Re = new FinalNode(*$1);
    $$ = new StatementNode(Re, dynamic_cast<VariableListNode*>($3));
} | WRITE LPAREN ExpressionListNode RPAREN {
    FinalNode* Wr = new FinalNode(*$1);
    $$ = new StatementNode(Wr, dynamic_cast<ExpressionListNode*>($3));
} | WRITE error ExpressionListNode RPAREN {
    yyerror("Expected '(' after 'write' keyword");
    yyerrok;
    FinalNode* Wr = new FinalNode(*$1);
    $$ = new StatementNode(Wr, dynamic_cast<ExpressionListNode*>($3));
} | WRITE LPAREN ExpressionListNode error {
    yyerror("Expected ')' after 'write' keyword");
    yyerrok;
    FinalNode* Wr = new FinalNode(*$1);
    $$ = new StatementNode(Wr, dynamic_cast<ExpressionListNode*>($3));
} | WHILE ExpressionNode DO StatementNode{ // while语句拓展
    $$ = new StatementNode(dynamic_cast<ExpressionNode*>($2), dynamic_cast<StatementNode*>($4));
} | WHILE ExpressionNode error StatementNode {
    yyerror("Expected 'do' after 'ExpressionNode'");
    yyerrok;
    $$ = new StatementNode(dynamic_cast<ExpressionNode*>($2), dynamic_cast<StatementNode*>($4));
} | BREAK{ // break拓展
    FinalNode* bk = new FinalNode(*$1);
    $$ = new StatementNode(bk);
}

VariableListNode: VariableNode {
    $$ = new VariableListNode(dynamic_cast<VariableNode*>($1));
} | VariableListNode COMMA VariableNode {
    $$ = new VariableListNode(dynamic_cast<VariableNode*>($3), dynamic_cast<VariableListNode*>($1));
}

VariableNode: ID IdVarpartNode {
    FinalNode* id = new FinalNode(*$1);
    $$ = new VariableNode(id, dynamic_cast<IdVarpartNode*>($2));
}

IdVarpartNode: {
    $$ = new IdVarpartNode();
} | LBRA ExpressionListNode RBRA {
    $$ = new IdVarpartNode(dynamic_cast<ExpressionListNode*>($2));
} | LBRA ExpressionListNode error {
    yyerror("Expected ']' after '[' operator");
    yyerrok;
    $$ = new IdVarpartNode(dynamic_cast<ExpressionListNode*>($2));
} 

ProcedureCallNode: ID {
    FinalNode* id = new FinalNode(*$1);
    $$ = new ProcedureCallNode(id);
} | ID LPAREN ExpressionListNode RPAREN {
    FinalNode* id = new FinalNode(*$1);
    $$ = new ProcedureCallNode(id, dynamic_cast<ExpressionListNode*>($3));
} | ID LPAREN ExpressionListNode error {
    yyerror("Expected ')' after 'ExpressionListNode'");
    yyerrok;
    FinalNode* id = new FinalNode(*$1);
    $$ = new ProcedureCallNode(id, dynamic_cast<ExpressionListNode*>($3));
} | ID LPAREN RPAREN{
    FinalNode* id = new FinalNode(*$1);
    $$ = new ProcedureCallNode(id); // 语法拓展：无参数过程调用支持 foo()
} | ID LPAREN error {
    yyerror("Expected ')' after '(' operator");
    yyerrok;
    FinalNode* id = new FinalNode(*$1);
    $$ = new ProcedureCallNode(id); // 语法拓展：无参数过程调用支持 foo()
}

ElsePartNode:  {
    $$ = new ElsePartNode();
} | ELSE StatementNode {
    $$ = new ElsePartNode(dynamic_cast<StatementNode*>($2));
} 

ExpressionListNode: ExpressionNode {
    $$ = new ExpressionListNode(dynamic_cast<ExpressionNode*>($1));
} | ExpressionListNode COMMA ExpressionNode {
    $$ = new ExpressionListNode(dynamic_cast<ExpressionNode*>($3), dynamic_cast<ExpressionListNode*>($1));
}  

ExpressionNode: SimpleExpressionNode {
    $$ = new ExpressionNode(dynamic_cast<SimpleExpressionNode*>($1));
} | SimpleExpressionNode RELOP SimpleExpressionNode {
    FinalNode* id = new FinalNode(*$2);
    $$ = new ExpressionNode(dynamic_cast<SimpleExpressionNode*>($1), id, dynamic_cast<SimpleExpressionNode*>($3));
} 

SimpleExpressionNode: TermNode {
    $$ = new SimpleExpressionNode(dynamic_cast<TermNode*>($1));
} | SimpleExpressionNode ADDOP TermNode {
    FinalNode* op = new FinalNode(*$2);
    $$ = new SimpleExpressionNode(dynamic_cast<TermNode*>($3), dynamic_cast<SimpleExpressionNode*>($1), op);
} 

TermNode: FactorNode {
    $$ = new TermNode(dynamic_cast<FactorNode*>($1));
} | TermNode MULOP FactorNode {
    FinalNode* op = new FinalNode(*$2);
    $$ = new TermNode(dynamic_cast<FactorNode*>($3), dynamic_cast<TermNode*>($1), op);
}

FactorNode: NUM {
    FinalNode* id = new FinalNode(*$1);
    $$ = new FactorNode(id);
} | VariableNode {
    $$ = new FactorNode(dynamic_cast<VariableNode*>($1));
} | LPAREN ExpressionNode RPAREN {
    $$ = new FactorNode(dynamic_cast<ExpressionNode*>($2));
} | LPAREN ExpressionNode error {
    yyerror("Expected ')' after '(' operator");
    yyerrok;
    $$ = new FactorNode(dynamic_cast<ExpressionNode*>($2));
} | ID LPAREN ExpressionListNode RPAREN {
    FinalNode* id = new FinalNode(*$1);
    $$ = new FactorNode(id, dynamic_cast<ExpressionListNode*>($3));
} | ID LPAREN ExpressionListNode error {
    yyerror("Expected ')' after '(' operator");
    yyerrok;
    FinalNode* id = new FinalNode(*$1);
    $$ = new FactorNode(id, dynamic_cast<ExpressionListNode*>($3));
} | NOTOP FactorNode {
    if($1->property == "not"){
        FinalNode* id = new FinalNode(*$1);
        $$ = new FactorNode(id, dynamic_cast<FactorNode*>($2));
    }
    else {
        yyerror("Expected 'not' keyword");
        YYERROR;
    }
} | ADDOP FactorNode {
    if($1->property == "-" || $1->property == "+"){
        FinalNode* op = new FinalNode(*$1);
        $$ = new FactorNode(op,dynamic_cast<FactorNode*>($2));
    }
    else {
        yyerror("Expected '-' or '+'");
        YYERROR;
    }
} | BOOL {
    FinalNode* id = new FinalNode(*$1);
    $$ = new FactorNode(id);
} | ID LPAREN RPAREN{
    FinalNode* id = new FinalNode(*$1);
    IdVarpartNode* fake_idvar = new IdVarpartNode();
    VariableNode* fake_var = new VariableNode(id, fake_idvar);
    $$ = new FactorNode(fake_var); // 测试用例21: 无参数函数 a := foo(); write(foo())
} | ID LPAREN error {
    yyerror("Expected ')' after '(' operator");
    yyerrok;
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

    yylineno = current->line;
    line = current->line;
    column = current->column;

    return bison_type;
}

void yyerror(const char* msg) {
    if (strcmp(msg, "syntax error") == 0) {
        // 不输出默认的 "syntax error"
        return;
    }
    fprintf(stderr, "Syntax Error: %s at line %d", msg, yylineno);
    fprintf(stderr, " at token: %s line: %d, column: %d\n", tokens[tokenIndex - 1].property.c_str(), line, column);
}

void yyerror_at(const char* msg, int line, int column, const Token * token) {
    fprintf(stderr, "Syntax Error: %s at line %d", msg, line);
    fprintf(stderr, " at token: %s line: %d, column: %d\n", token->property.c_str(), line, column);
}