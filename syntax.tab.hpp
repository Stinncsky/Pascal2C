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
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    Identifier = 258,              /* Identifier  */
    Number = 259,                  /* Number  */
    String_var = 260,              /* String_var  */
    Char_var = 261,                /* Char_var  */
    ProgramKey = 262,              /* ProgramKey  */
    Const = 263,                   /* Const  */
    Var = 264,                     /* Var  */
    Array = 265,                   /* Array  */
    Of = 266,                      /* Of  */
    Basictype = 267,               /* Basictype  */
    Procedure = 268,               /* Procedure  */
    Function = 269,                /* Function  */
    Begin = 270,                   /* Begin  */
    End = 271,                     /* End  */
    If = 272,                      /* If  */
    Then = 273,                    /* Then  */
    For = 274,                     /* For  */
    To = 275,                      /* To  */
    Do = 276,                      /* Do  */
    Read = 277,                    /* Read  */
    Write = 278,                   /* Write  */
    Else = 279,                    /* Else  */
    Booltype = 280,                /* Booltype  */
    Notop = 281,                   /* Notop  */
    Mulop = 282,                   /* Mulop  */
    Addop = 283,                   /* Addop  */
    Relop = 284,                   /* Relop  */
    Assignop = 285,                /* Assignop  */
    Dotdot = 286,                  /* Dotdot  */
    Semi = 287,                    /* Semi  */
    Dot = 288,                     /* Dot  */
    Lparen = 289,                  /* Lparen  */
    Rparen = 290,                  /* Rparen  */
    Lbra = 291,                    /* Lbra  */
    Rbra = 292,                    /* Rbra  */
    Colon = 293,                   /* Colon  */
    Comma = 294,                   /* Comma  */
    Null = 295,                    /* Null  */
    While = 296                    /* While  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "syntax.y"

    Token* token;
    AST* ast;

#line 110 "syntax.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAX_TAB_HPP_INCLUDED  */
