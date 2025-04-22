/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNTAX_TAB_HPP_INCLUDED
# define YY_YY_SYNTAX_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    Tk_YYEMPTY = -2,
    Tk_YYEOF = 0,                  /* "end of file"  */
    Tk_YYerror = 256,              /* error  */
    Tk_YYUNDEF = 257,              /* "invalid token"  */
    Tk_ID = 258,                   /* ID  */
    Tk_NUM = 259,                  /* NUM  */
    Tk_STR_V = 260,                /* STR_V  */
    Tk_CHAR_V = 261,               /* CHAR_V  */
    Tk_PROGRAM = 262,              /* PROGRAM  */
    Tk_CONST = 263,                /* CONST  */
    Tk_VAR = 264,                  /* VAR  */
    Tk_ARRAY = 265,                /* ARRAY  */
    Tk_OF = 266,                   /* OF  */
    Tk_TYPE = 267,                 /* TYPE  */
    Tk_PROCEDURE = 268,            /* PROCEDURE  */
    Tk_FUNCTION = 269,             /* FUNCTION  */
    Tk_BEGIN = 270,                /* BEGIN  */
    Tk_END = 271,                  /* END  */
    Tk_IF = 272,                   /* IF  */
    Tk_THEN = 273,                 /* THEN  */
    Tk_FOR = 274,                  /* FOR  */
    Tk_TO = 275,                   /* TO  */
    Tk_DO = 276,                   /* DO  */
    Tk_READ = 277,                 /* READ  */
    Tk_WRITE = 278,                /* WRITE  */
    Tk_ELSE = 279,                 /* ELSE  */
    Tk_BOOL = 280,                 /* BOOL  */
    Tk_NOTOP = 281,                /* NOTOP  */
    Tk_MULOP = 282,                /* MULOP  */
    Tk_ADDOP = 283,                /* ADDOP  */
    Tk_RELOP = 284,                /* RELOP  */
    Tk_ASSIGNOP = 285,             /* ASSIGNOP  */
    Tk_DOTDOT = 286,               /* DOTDOT  */
    Tk_SEMI = 287,                 /* SEMI  */
    Tk_DOT = 288,                  /* DOT  */
    Tk_LPAREN = 289,               /* LPAREN  */
    Tk_RPAREN = 290,               /* RPAREN  */
    Tk_LBRA = 291,                 /* LBRA  */
    Tk_RBRA = 292,                 /* RBRA  */
    Tk_COLON = 293,                /* COLON  */
    Tk_COMMA = 294,                /* COMMA  */
    Tk_Null = 295,                 /* Null  */
    Tk_WHILE = 296,                /* WHILE  */
    Tk_BREAK = 297                 /* BREAK  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "syntax_err.y"

    Token* token;
    AST* ast;

#line 111 "syntax.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAX_TAB_HPP_INCLUDED  */
