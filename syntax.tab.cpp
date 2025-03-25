/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"

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

#line 90 "syntax.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "syntax.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_Identifier = 3,                 /* Identifier  */
  YYSYMBOL_Number = 4,                     /* Number  */
  YYSYMBOL_String_var = 5,                 /* String_var  */
  YYSYMBOL_Char_var = 6,                   /* Char_var  */
  YYSYMBOL_ProgramKey = 7,                 /* ProgramKey  */
  YYSYMBOL_Const = 8,                      /* Const  */
  YYSYMBOL_Var = 9,                        /* Var  */
  YYSYMBOL_Array = 10,                     /* Array  */
  YYSYMBOL_Of = 11,                        /* Of  */
  YYSYMBOL_Basictype = 12,                 /* Basictype  */
  YYSYMBOL_Procedure = 13,                 /* Procedure  */
  YYSYMBOL_Function = 14,                  /* Function  */
  YYSYMBOL_Begin = 15,                     /* Begin  */
  YYSYMBOL_End = 16,                       /* End  */
  YYSYMBOL_If = 17,                        /* If  */
  YYSYMBOL_Then = 18,                      /* Then  */
  YYSYMBOL_For = 19,                       /* For  */
  YYSYMBOL_To = 20,                        /* To  */
  YYSYMBOL_Do = 21,                        /* Do  */
  YYSYMBOL_Read = 22,                      /* Read  */
  YYSYMBOL_Write = 23,                     /* Write  */
  YYSYMBOL_Else = 24,                      /* Else  */
  YYSYMBOL_Booltype = 25,                  /* Booltype  */
  YYSYMBOL_Relop = 26,                     /* Relop  */
  YYSYMBOL_Mulop = 27,                     /* Mulop  */
  YYSYMBOL_Addop = 28,                     /* Addop  */
  YYSYMBOL_Assignop = 29,                  /* Assignop  */
  YYSYMBOL_Dotdot = 30,                    /* Dotdot  */
  YYSYMBOL_Semi = 31,                      /* Semi  */
  YYSYMBOL_Dot = 32,                       /* Dot  */
  YYSYMBOL_Lparen = 33,                    /* Lparen  */
  YYSYMBOL_Rparen = 34,                    /* Rparen  */
  YYSYMBOL_Lbra = 35,                      /* Lbra  */
  YYSYMBOL_Rbra = 36,                      /* Rbra  */
  YYSYMBOL_Colon = 37,                     /* Colon  */
  YYSYMBOL_Comma = 38,                     /* Comma  */
  YYSYMBOL_Null = 39,                      /* Null  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_ProgramStructNode = 41,         /* ProgramStructNode  */
  YYSYMBOL_ProgramHeadNode = 42,           /* ProgramHeadNode  */
  YYSYMBOL_ProgramBodyNode = 43,           /* ProgramBodyNode  */
  YYSYMBOL_IdListNode = 44,                /* IdListNode  */
  YYSYMBOL_ConstDeclarationsNode = 45,     /* ConstDeclarationsNode  */
  YYSYMBOL_ConstDeclarationNode = 46,      /* ConstDeclarationNode  */
  YYSYMBOL_ConstValueNode = 47,            /* ConstValueNode  */
  YYSYMBOL_VarDeclarationsNode = 48,       /* VarDeclarationsNode  */
  YYSYMBOL_VarDeclarationNode = 49,        /* VarDeclarationNode  */
  YYSYMBOL_TypeNode = 50,                  /* TypeNode  */
  YYSYMBOL_BasicTypeNode = 51,             /* BasicTypeNode  */
  YYSYMBOL_PeriodNode = 52,                /* PeriodNode  */
  YYSYMBOL_SubprogramDeclarationsNode = 53, /* SubprogramDeclarationsNode  */
  YYSYMBOL_SubprogramNode = 54,            /* SubprogramNode  */
  YYSYMBOL_SubprogramHeadNode = 55,        /* SubprogramHeadNode  */
  YYSYMBOL_FormalParameterNode = 56,       /* FormalParameterNode  */
  YYSYMBOL_ParameterListNode = 57,         /* ParameterListNode  */
  YYSYMBOL_ParameterNode = 58,             /* ParameterNode  */
  YYSYMBOL_VarParameterNode = 59,          /* VarParameterNode  */
  YYSYMBOL_ValueParameterNode = 60,        /* ValueParameterNode  */
  YYSYMBOL_SubprogramBodyNode = 61,        /* SubprogramBodyNode  */
  YYSYMBOL_CompoundStatementNode = 62,     /* CompoundStatementNode  */
  YYSYMBOL_StatementListNode = 63,         /* StatementListNode  */
  YYSYMBOL_StatementNode = 64,             /* StatementNode  */
  YYSYMBOL_VariableListNode = 65,          /* VariableListNode  */
  YYSYMBOL_VariableNode = 66,              /* VariableNode  */
  YYSYMBOL_IdVarpartNode = 67,             /* IdVarpartNode  */
  YYSYMBOL_ProcedureCallNode = 68,         /* ProcedureCallNode  */
  YYSYMBOL_ElsePartNode = 69,              /* ElsePartNode  */
  YYSYMBOL_ExpressionListNode = 70,        /* ExpressionListNode  */
  YYSYMBOL_ExpressionNode = 71,            /* ExpressionNode  */
  YYSYMBOL_SimpleExpressionNode = 72,      /* SimpleExpressionNode  */
  YYSYMBOL_TermNode = 73,                  /* TermNode  */
  YYSYMBOL_FactorNode = 74                 /* FactorNode  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    44,    44,    49,    52,    57,    64,    67,    75,    78,
      83,    93,   104,   113,   116,   119,   126,   129,   133,   136,
     142,   145,   151,   164,   174,   184,   194,   207,   209,   213,
     223,   227,   232,   234,   239,   241,   245,   247,   251,   255,
     259,   263,   267,   269,   274,   276,   284,   293,   295,   297,
     299,   308,   311,   316,   318,   322,   327,   329,   333,   336,
     339,   344,   346,   350,   352,   356,   358,   363,   365,   370,
     372,   377,   380,   382,   384,   387,   396,   405,   408
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "Identifier", "Number",
  "String_var", "Char_var", "ProgramKey", "Const", "Var", "Array", "Of",
  "Basictype", "Procedure", "Function", "Begin", "End", "If", "Then",
  "For", "To", "Do", "Read", "Write", "Else", "Booltype", "Relop", "Mulop",
  "Addop", "Assignop", "Dotdot", "Semi", "Dot", "Lparen", "Rparen", "Lbra",
  "Rbra", "Colon", "Comma", "Null", "$accept", "ProgramStructNode",
  "ProgramHeadNode", "ProgramBodyNode", "IdListNode",
  "ConstDeclarationsNode", "ConstDeclarationNode", "ConstValueNode",
  "VarDeclarationsNode", "VarDeclarationNode", "TypeNode", "BasicTypeNode",
  "PeriodNode", "SubprogramDeclarationsNode", "SubprogramNode",
  "SubprogramHeadNode", "FormalParameterNode", "ParameterListNode",
  "ParameterNode", "VarParameterNode", "ValueParameterNode",
  "SubprogramBodyNode", "CompoundStatementNode", "StatementListNode",
  "StatementNode", "VariableListNode", "VariableNode", "IdVarpartNode",
  "ProcedureCallNode", "ElsePartNode", "ExpressionListNode",
  "ExpressionNode", "SimpleExpressionNode", "TermNode", "FactorNode", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,    21,    54,    45,    24,   -98,    74,    90,    94,    77,
      97,   -98,     8,    86,    82,   -98,    90,   -98,   -98,   111,
       7,   112,    25,    85,    56,   -98,   -98,   -98,   -98,   113,
     -98,    92,    31,    90,   117,   118,    72,    91,    93,   -98,
     -98,     7,    88,   -98,   -98,   -98,    67,    95,    95,   -14,
      52,   122,    98,    99,   -98,    -2,   -98,   100,   -98,   -98,
      74,   -98,    75,    31,    17,   -98,    89,    52,     6,    52,
     -98,    53,   -98,   -98,    52,    52,    52,   -98,   109,    64,
     106,   -98,   105,   132,    52,   -98,    72,    52,    97,   -98,
     107,   108,    60,   -98,    90,    73,    -9,   -98,   -98,   -98,
     124,   -98,   -98,    14,   -98,    65,    33,   -98,   -98,   110,
      72,    52,    52,    52,    52,   104,    15,   -98,    26,   -98,
     -98,   125,   137,   136,   134,    96,   -98,   124,    17,   -98,
     -98,   -98,    52,   -98,   -98,    34,   -98,   119,   120,   106,
     -98,   126,   -98,   132,   -98,   -98,   -98,   -98,   124,   121,
     123,   -98,   -98,   -98,   -98,    72,   -98,    52,   -98,   -98,
     143,   144,   -98,   128,   -98,   -98,    72,   -98
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     3,     1,     8,     0,     0,     0,
      16,     6,     0,     0,     0,     2,     0,    27,     4,     0,
       0,     9,     0,     0,     0,     7,    13,    15,    14,     0,
      10,     0,     0,    17,     0,     0,    44,     0,     0,     5,
      12,     0,     0,    22,    18,    20,     0,    32,    32,    58,
       0,     0,     0,     0,    48,     0,    42,     0,    47,    28,
       8,    11,     0,     0,     0,    30,     0,     0,     0,     0,
      55,    56,    71,    77,     0,     0,     0,    72,     0,    65,
      67,    69,     0,     0,     0,    41,    44,     0,    16,    29,
       0,     0,     0,    19,     0,     0,     0,    34,    36,    37,
       0,    46,    60,     0,    63,     0,     0,    75,    76,     0,
      44,     0,     0,     0,     0,    56,     0,    53,     0,    43,
      45,     0,     0,     0,     0,     0,    38,     0,     0,    33,
      31,    59,     0,    57,    78,     0,    73,    61,    66,    68,
      70,     0,    51,     0,    52,    40,    23,    24,     0,     0,
       0,    39,    35,    64,    74,    44,    49,     0,    54,    21,
       0,     0,    62,     0,    25,    26,    44,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -98,   -98,   -98,   -98,     0,   101,   -98,   114,    66,   -98,
     102,   -97,   -98,   -98,   -98,   -98,   115,   -98,    28,   -98,
      58,   -98,   -22,   -98,   -82,   -98,   -36,   -98,   -98,   -98,
     -61,   -49,    46,    47,   -69
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     9,    95,    10,    14,    30,    17,    23,
      44,    45,    92,    24,    37,    38,    65,    96,    97,    98,
      99,    89,    54,    55,    56,   116,    77,    70,    58,   156,
     103,   104,    79,    80,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    78,    39,   130,   119,   107,   108,    12,   105,    71,
      72,    26,    27,    28,    85,    67,    22,     1,   101,    68,
      11,    69,   128,   118,     4,   129,    94,   109,   137,    86,
     151,    73,    74,    46,    75,    29,    71,    72,   120,    76,
     102,    42,    18,    43,   140,   135,    19,   117,   131,   142,
      57,   159,   132,   143,     5,    71,    72,     7,    73,    74,
     144,    75,    32,    19,   132,   141,    76,   134,   154,    34,
      35,    36,   132,   162,    57,    49,     6,    73,    74,    90,
      75,    91,     8,   153,   167,    76,   106,    36,    69,    50,
     111,    51,   112,    11,    52,    53,   124,    13,   125,   145,
     149,   133,   150,   132,    63,    19,    16,   158,   163,    15,
     127,    19,    20,    21,    25,    31,    33,    40,    41,    57,
      47,    48,    59,    62,    60,    82,   100,   110,    64,    87,
      57,    83,    84,   113,   114,   115,    43,   122,   123,    69,
      36,   146,   147,   155,   136,   148,   157,   164,   112,   166,
     165,   160,   126,   161,   121,    61,   152,   138,     0,   139,
       0,    88,     0,    66,     0,    93
};

static const yytype_int16 yycheck[] =
{
      36,    50,    24,   100,    86,    74,    75,     7,    69,     3,
       4,     4,     5,     6,    16,    29,    16,     7,    67,    33,
       3,    35,    31,    84,     3,    34,     9,    76,   110,    31,
     127,    25,    26,    33,    28,    28,     3,     4,    87,    33,
      34,    10,    34,    12,   113,   106,    38,    83,    34,    34,
      86,   148,    38,    38,     0,     3,     4,    33,    25,    26,
      34,    28,    37,    38,    38,   114,    33,    34,    34,    13,
      14,    15,    38,   155,   110,     3,    31,    25,    26,     4,
      28,     6,     8,   132,   166,    33,    33,    15,    35,    17,
      26,    19,    28,     3,    22,    23,    36,     3,    38,   121,
       4,    36,     6,    38,    37,    38,     9,   143,   157,    32,
      37,    38,    26,    31,     3,     3,    31,     4,    26,   155,
       3,     3,    31,    35,    31,     3,    37,    18,    33,    29,
     166,    33,    33,    27,    29,     3,    12,    30,    30,    35,
      15,     4,     6,    24,    34,    11,    20,     4,    28,    21,
       6,    30,    94,    30,    88,    41,   128,   111,    -1,   112,
      -1,    60,    -1,    48,    -1,    63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    41,    42,     3,     0,    31,    33,     8,    43,
      45,     3,    44,     3,    46,    32,     9,    48,    34,    38,
      26,    31,    44,    49,    53,     3,     4,     5,     6,    28,
      47,     3,    37,    31,    13,    14,    15,    54,    55,    62,
       4,    26,    10,    12,    50,    51,    44,     3,     3,     3,
      17,    19,    22,    23,    62,    63,    64,    66,    68,    31,
      31,    47,    35,    37,    33,    56,    56,    29,    33,    35,
      67,     3,     4,    25,    26,    28,    33,    66,    71,    72,
      73,    74,     3,    33,    33,    16,    31,    29,    45,    61,
       4,     6,    52,    50,     9,    44,    57,    58,    59,    60,
      37,    71,    34,    70,    71,    70,    33,    74,    74,    71,
      18,    26,    28,    27,    29,     3,    65,    66,    70,    64,
      71,    48,    30,    30,    36,    38,    60,    37,    31,    34,
      51,    34,    38,    36,    34,    70,    34,    64,    72,    73,
      74,    71,    34,    38,    34,    62,     4,     6,    11,     4,
       6,    51,    58,    71,    34,    24,    69,    20,    66,    51,
      30,    30,    64,    71,     4,     6,    21,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    44,    44,    45,    45,
      46,    46,    47,    47,    47,    47,    48,    48,    49,    49,
      50,    50,    51,    52,    52,    52,    52,    53,    53,    54,
      55,    55,    56,    56,    57,    57,    58,    58,    59,    60,
      61,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    67,    67,    68,    68,
      68,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     2,     5,     4,     1,     3,     0,     3,
       3,     5,     2,     1,     1,     1,     0,     3,     3,     5,
       1,     6,     1,     3,     3,     5,     5,     0,     3,     3,
       3,     5,     0,     3,     1,     3,     1,     1,     2,     3,
       3,     3,     1,     3,     0,     3,     3,     1,     1,     5,
       8,     4,     4,     1,     3,     2,     0,     3,     1,     4,
       3,     0,     2,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     3,     4,     2,     2,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* ProgramStructNode: ProgramHeadNode Semi ProgramBodyNode Dot  */
#line 44 "syntax.y"
                                                            {
    syntax->tree = new ProgramStructNode(dynamic_cast<ProgramHeadNode*>((yyvsp[-3].ast)), dynamic_cast<ProgramBodyNode*>((yyvsp[-1].ast)));
}
#line 1264 "syntax.tab.cpp"
    break;

  case 3: /* ProgramHeadNode: ProgramKey Identifier  */
#line 49 "syntax.y"
                                       {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ProgramHeadNode(id);
}
#line 1273 "syntax.tab.cpp"
    break;

  case 4: /* ProgramHeadNode: ProgramKey Identifier Lparen IdListNode Rparen  */
#line 52 "syntax.y"
                                                   {
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new ProgramHeadNode(id, dynamic_cast<IdListNode*>((yyvsp[-1].ast)));
}
#line 1282 "syntax.tab.cpp"
    break;

  case 5: /* ProgramBodyNode: ConstDeclarationsNode VarDeclarationsNode SubprogramDeclarationsNode CompoundStatementNode  */
#line 57 "syntax.y"
                                                                                                            {
    (yyval.ast) = new ProgramBodyNode(dynamic_cast<ConstDeclarationsNode*>((yyvsp[-3].ast)),
    dynamic_cast<VarDeclarationsNode*>((yyvsp[-2].ast)),
    dynamic_cast<SubprogramDeclarationsNode*>((yyvsp[-1].ast)),
    dynamic_cast<CompoundStatementNode*>((yyvsp[0].ast)));
}
#line 1293 "syntax.tab.cpp"
    break;

  case 6: /* IdListNode: Identifier  */
#line 64 "syntax.y"
                       {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new IdListNode(id);
}
#line 1302 "syntax.tab.cpp"
    break;

  case 7: /* IdListNode: IdListNode Comma Identifier  */
#line 67 "syntax.y"
                                {
        FinalNode* id = new FinalNode(*(yyvsp[0].token));
        IdListNode* idList = dynamic_cast<IdListNode*>((yyvsp[-2].ast));
        (yyval.ast) = new IdListNode(id, idList);
}
#line 1312 "syntax.tab.cpp"
    break;

  case 8: /* ConstDeclarationsNode: %empty  */
#line 75 "syntax.y"
    {
        (yyval.ast) = new ConstDeclarationsNode();
    }
#line 1320 "syntax.tab.cpp"
    break;

  case 9: /* ConstDeclarationsNode: Const ConstDeclarationNode Semi  */
#line 78 "syntax.y"
                                      {
        (yyval.ast) = new ConstDeclarationsNode(dynamic_cast<ConstDeclarationNode*>((yyvsp[-1].ast)));
    }
#line 1328 "syntax.tab.cpp"
    break;

  case 10: /* ConstDeclarationNode: Identifier Relop ConstValueNode  */
#line 83 "syntax.y"
                                                      {
    if((yyvsp[-1].token)->property == "=") {
        FinalNode* id = new FinalNode(*(yyvsp[-2].token));
        (yyval.ast) = new ConstDeclarationNode(id, dynamic_cast<ConstValueNode*>((yyvsp[0].ast)));
    }
    else {
        yyerror("Expected '='");
        YYERROR;
    }
}
#line 1343 "syntax.tab.cpp"
    break;

  case 11: /* ConstDeclarationNode: ConstDeclarationNode Semi Identifier Relop ConstValueNode  */
#line 93 "syntax.y"
                                                            {
    if((yyvsp[-1].token)->property == "=") {
        FinalNode* id = new FinalNode(*(yyvsp[-2].token));
        (yyval.ast) = new ConstDeclarationNode(id, dynamic_cast<ConstValueNode*>((yyvsp[0].ast)), dynamic_cast<ConstDeclarationNode*>((yyvsp[-4].ast)));
    }
    else {
        yyerror("Expected '='");
        YYERROR;
    }
}
#line 1358 "syntax.tab.cpp"
    break;

  case 12: /* ConstValueNode: Addop Number  */
#line 104 "syntax.y"
                             {
    if((yyvsp[-1].token)->property == "+" || (yyvsp[-1].token)->property == "-") {
        FinalNode* op = new FinalNode(*(yyvsp[-1].token));
        FinalNode* num = new FinalNode(*(yyvsp[0].token));
        (yyval.ast) = new ConstValueNode(op,num);
    } else {
        yyerror("Expected '+' or '-'");
        YYERROR;
    }
}
#line 1373 "syntax.tab.cpp"
    break;

  case 13: /* ConstValueNode: Number  */
#line 113 "syntax.y"
           {
    FinalNode* num = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ConstValueNode(num);
}
#line 1382 "syntax.tab.cpp"
    break;

  case 14: /* ConstValueNode: Char_var  */
#line 116 "syntax.y"
             {
    FinalNode* num = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ConstValueNode(num);
}
#line 1391 "syntax.tab.cpp"
    break;

  case 15: /* ConstValueNode: String_var  */
#line 119 "syntax.y"
               {
    FinalNode* num = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ConstValueNode(num);
}
#line 1400 "syntax.tab.cpp"
    break;

  case 16: /* VarDeclarationsNode: %empty  */
#line 126 "syntax.y"
    {
        (yyval.ast) = new VarDeclarationsNode();
    }
#line 1408 "syntax.tab.cpp"
    break;

  case 17: /* VarDeclarationsNode: Var VarDeclarationNode Semi  */
#line 129 "syntax.y"
                                  {
        (yyval.ast) = new VarDeclarationsNode(dynamic_cast<VarDeclarationNode*>((yyvsp[-1].ast)));
    }
#line 1416 "syntax.tab.cpp"
    break;

  case 18: /* VarDeclarationNode: IdListNode Colon TypeNode  */
#line 133 "syntax.y"
                                              {
    (yyval.ast) = new VarDeclarationNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<TypeNode*>((yyvsp[0].ast)));

}
#line 1425 "syntax.tab.cpp"
    break;

  case 19: /* VarDeclarationNode: VarDeclarationNode Semi IdListNode Colon TypeNode  */
#line 136 "syntax.y"
                                                      {
    (yyval.ast) = new VarDeclarationNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<TypeNode*>((yyvsp[0].ast)), dynamic_cast<VarDeclarationNode*>((yyvsp[-4].ast)));
}
#line 1433 "syntax.tab.cpp"
    break;

  case 20: /* TypeNode: BasicTypeNode  */
#line 142 "syntax.y"
                  {
        (yyval.ast) = new TypeNode(dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)));
    }
#line 1441 "syntax.tab.cpp"
    break;

  case 21: /* TypeNode: Array Lbra PeriodNode Rbra Of BasicTypeNode  */
#line 145 "syntax.y"
                                                  {
        (yyval.ast) = new TypeNode(dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)), dynamic_cast<PeriodNode*>((yyvsp[-3].ast)));
    }
#line 1449 "syntax.tab.cpp"
    break;

  case 22: /* BasicTypeNode: Basictype  */
#line 151 "syntax.y"
              {
        if ((yyvsp[0].token)->property == "integer" || 
            (yyvsp[0].token)->property == "real" || 
            (yyvsp[0].token)->property == "boolean" || 
            (yyvsp[0].token)->property == "char") {
            FinalNode* id = new FinalNode(*(yyvsp[0].token));
            (yyval.ast) = new BasicTypeNode(id);
        } else {
            yyerror("Expected 'integer', 'real', 'boolean', or 'char' keyword");
            YYERROR; // 强制回溯，避免污染其他规则
        }
    }
#line 1466 "syntax.tab.cpp"
    break;

  case 23: /* PeriodNode: Number Dotdot Number  */
#line 164 "syntax.y"
                                 {
    if((yyvsp[-1].token)->property == "..") {
        FinalNode* id1 = new FinalNode(*(yyvsp[-2].token));
        FinalNode* id2 = new FinalNode(*(yyvsp[0].token));
        (yyval.ast) = new PeriodNode(id1, id2);
    }
    else {
        yyerror("Expected '..' operator");
        YYERROR;
    }
}
#line 1482 "syntax.tab.cpp"
    break;

  case 24: /* PeriodNode: Char_var Dotdot Char_var  */
#line 174 "syntax.y"
                            {
    if((yyvsp[-1].token)->property == "..") {
        FinalNode* id1 = new FinalNode(*(yyvsp[-2].token));
        FinalNode* id2 = new FinalNode(*(yyvsp[0].token));
        (yyval.ast) = new PeriodNode(id1,id2);
    }
    else {
        yyerror("Expected '..' operator");
        YYERROR;
    }
}
#line 1498 "syntax.tab.cpp"
    break;

  case 25: /* PeriodNode: PeriodNode Comma Number Dotdot Number  */
#line 184 "syntax.y"
                                          {
    if((yyvsp[-1].token)->property == ".." && (yyvsp[-3].token)->property == ",") {
        FinalNode* id1 = new FinalNode(*(yyvsp[-2].token));
        FinalNode* id2 = new FinalNode(*(yyvsp[0].token));
        (yyval.ast) = new PeriodNode(id1, id2, dynamic_cast<PeriodNode*>((yyvsp[-4].ast)));
    }
    else {
        yyerror("Expected '..' or ',' operator");
        YYERROR;
    }
}
#line 1514 "syntax.tab.cpp"
    break;

  case 26: /* PeriodNode: PeriodNode Comma Char_var Dotdot Char_var  */
#line 194 "syntax.y"
                                              {
    if((yyvsp[-1].token)->property == ".." && (yyvsp[-3].token)->property == ",") {
        FinalNode* id1 = new FinalNode(*(yyvsp[-2].token));
        FinalNode* id2 = new FinalNode(*(yyvsp[0].token));
        (yyval.ast) = new PeriodNode(id1, id2, dynamic_cast<PeriodNode*>((yyvsp[-4].ast)));
    }
    else {
        yyerror("Expected '..' or ',' operator");
        YYERROR;
    }
}
#line 1530 "syntax.tab.cpp"
    break;

  case 27: /* SubprogramDeclarationsNode: %empty  */
#line 207 "syntax.y"
                            {
    (yyval.ast) = new SubprogramDeclarationsNode();
}
#line 1538 "syntax.tab.cpp"
    break;

  case 28: /* SubprogramDeclarationsNode: SubprogramDeclarationsNode SubprogramNode Semi  */
#line 209 "syntax.y"
                                                   {
    (yyval.ast) = new SubprogramDeclarationsNode(dynamic_cast<SubprogramDeclarationsNode*>((yyvsp[-2].ast)), dynamic_cast<SubprogramNode*>((yyvsp[-1].ast)));
}
#line 1546 "syntax.tab.cpp"
    break;

  case 29: /* SubprogramNode: SubprogramHeadNode Semi SubprogramBodyNode  */
#line 213 "syntax.y"
                                                           {
    if((yyvsp[-1].token)->property == ";") {
        (yyval.ast) = new SubprogramNode(dynamic_cast<SubprogramHeadNode*>((yyvsp[-2].ast)), dynamic_cast<SubprogramBodyNode*>((yyvsp[0].ast)));
    }
    else {
        yyerror("Expected ';'");
        YYERROR;
    }
}
#line 1560 "syntax.tab.cpp"
    break;

  case 30: /* SubprogramHeadNode: Procedure Identifier FormalParameterNode  */
#line 223 "syntax.y"
                                                             {
    FinalNode* id = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new SubprogramHeadNode(id, dynamic_cast<FormalParameterNode*>((yyvsp[0].ast)));

}
#line 1570 "syntax.tab.cpp"
    break;

  case 31: /* SubprogramHeadNode: Function Identifier FormalParameterNode Colon BasicTypeNode  */
#line 227 "syntax.y"
                                                                {
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new SubprogramHeadNode(id, dynamic_cast<FormalParameterNode*>((yyvsp[-2].ast)), dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)));
}
#line 1579 "syntax.tab.cpp"
    break;

  case 32: /* FormalParameterNode: %empty  */
#line 232 "syntax.y"
                     {
    (yyval.ast) = new FormalParameterNode();
}
#line 1587 "syntax.tab.cpp"
    break;

  case 33: /* FormalParameterNode: Lparen ParameterListNode Rparen  */
#line 234 "syntax.y"
                                    {
    (yyval.ast) = new FormalParameterNode(dynamic_cast<ParameterListNode*>((yyvsp[-1].ast)));

}
#line 1596 "syntax.tab.cpp"
    break;

  case 34: /* ParameterListNode: ParameterNode  */
#line 239 "syntax.y"
                                 {
    (yyval.ast) = new ParameterListNode(dynamic_cast<ParameterNode*>((yyvsp[0].ast)));
}
#line 1604 "syntax.tab.cpp"
    break;

  case 35: /* ParameterListNode: ParameterListNode Semi ParameterNode  */
#line 241 "syntax.y"
                                         {
    (yyval.ast) = new ParameterListNode(dynamic_cast<ParameterNode*>((yyvsp[0].ast)), dynamic_cast<ParameterListNode*>((yyvsp[-2].ast)));
}
#line 1612 "syntax.tab.cpp"
    break;

  case 36: /* ParameterNode: VarParameterNode  */
#line 245 "syntax.y"
                                {
    (yyval.ast) = new ParameterNode(dynamic_cast<VarParameterNode*>((yyvsp[0].ast)));
}
#line 1620 "syntax.tab.cpp"
    break;

  case 37: /* ParameterNode: ValueParameterNode  */
#line 247 "syntax.y"
                       {
    (yyval.ast) = new ParameterNode(dynamic_cast<ValueParameterNode*>((yyvsp[0].ast)));
}
#line 1628 "syntax.tab.cpp"
    break;

  case 38: /* VarParameterNode: Var ValueParameterNode  */
#line 251 "syntax.y"
                                         {
    (yyval.ast) = new VarParameterNode(dynamic_cast<ValueParameterNode*>((yyvsp[0].ast)));
}
#line 1636 "syntax.tab.cpp"
    break;

  case 39: /* ValueParameterNode: IdListNode Colon BasicTypeNode  */
#line 255 "syntax.y"
                                                   {
    (yyval.ast) = new ValueParameterNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)));
}
#line 1644 "syntax.tab.cpp"
    break;

  case 40: /* SubprogramBodyNode: ConstDeclarationsNode VarDeclarationsNode CompoundStatementNode  */
#line 259 "syntax.y"
                                                                                    {
    (yyval.ast) = new SubprogramBodyNode(dynamic_cast<ConstDeclarationsNode*>((yyvsp[-2].ast)), dynamic_cast<VarDeclarationsNode*>((yyvsp[-1].ast)), dynamic_cast<CompoundStatementNode*>((yyvsp[0].ast)));
}
#line 1652 "syntax.tab.cpp"
    break;

  case 41: /* CompoundStatementNode: Begin StatementListNode End  */
#line 263 "syntax.y"
                                                   {
    (yyval.ast) = new CompoundStatementNode(dynamic_cast<StatementListNode*>((yyvsp[-1].ast)));
}
#line 1660 "syntax.tab.cpp"
    break;

  case 42: /* StatementListNode: StatementNode  */
#line 267 "syntax.y"
                                 {
    (yyval.ast) = new StatementListNode(dynamic_cast<StatementNode*>((yyvsp[0].ast)));
}
#line 1668 "syntax.tab.cpp"
    break;

  case 43: /* StatementListNode: StatementListNode Semi StatementNode  */
#line 269 "syntax.y"
                                         {
    (yyval.ast) = new StatementListNode(dynamic_cast<StatementNode*>((yyvsp[0].ast)), dynamic_cast<StatementListNode*>((yyvsp[-2].ast)));

}
#line 1677 "syntax.tab.cpp"
    break;

  case 44: /* StatementNode: %empty  */
#line 274 "syntax.y"
               {
    (yyval.ast) = new StatementNode();
}
#line 1685 "syntax.tab.cpp"
    break;

  case 45: /* StatementNode: VariableNode Assignop ExpressionNode  */
#line 276 "syntax.y"
                                         {
    if((yyvsp[-1].token)->property == ":="){
        (yyval.ast) = new StatementNode(dynamic_cast<VariableNode*>((yyvsp[-2].ast)), dynamic_cast<ExpressionNode*>((yyvsp[0].ast)));
    }
    else {
        yyerror("Expected ':=' operator");
        YYERROR;
    }
}
#line 1699 "syntax.tab.cpp"
    break;

  case 46: /* StatementNode: Identifier Assignop ExpressionNode  */
#line 284 "syntax.y"
                                       {
    if((yyvsp[-1].token)->property == ":="){
        FinalNode* id = new FinalNode(*(yyvsp[-2].token));
        (yyval.ast) = new StatementNode(id, dynamic_cast<ExpressionNode*>((yyvsp[0].ast)));
    }
    else {
        yyerror("Expected ':=' operator");
        YYERROR;
    }
}
#line 1714 "syntax.tab.cpp"
    break;

  case 47: /* StatementNode: ProcedureCallNode  */
#line 293 "syntax.y"
                      {
    (yyval.ast) = new StatementNode(dynamic_cast<ProcedureCallNode*>((yyvsp[0].ast)));
}
#line 1722 "syntax.tab.cpp"
    break;

  case 48: /* StatementNode: CompoundStatementNode  */
#line 295 "syntax.y"
                          {
    (yyval.ast) = new StatementNode(dynamic_cast<CompoundStatementNode*>((yyvsp[0].ast)));
}
#line 1730 "syntax.tab.cpp"
    break;

  case 49: /* StatementNode: If ExpressionNode Then StatementNode ElsePartNode  */
#line 297 "syntax.y"
                                                      {
    (yyval.ast) = new StatementNode(dynamic_cast<ExpressionNode*>((yyvsp[-3].ast)), dynamic_cast<StatementNode*>((yyvsp[-1].ast)), dynamic_cast<ElsePartNode*>((yyvsp[0].ast)));
}
#line 1738 "syntax.tab.cpp"
    break;

  case 50: /* StatementNode: For Identifier Assignop ExpressionNode To ExpressionNode Do StatementNode  */
#line 299 "syntax.y"
                                                                              {
    if((yyvsp[-5].token)->property == ":="){
        FinalNode* id = new FinalNode(*(yyvsp[-6].token));
        (yyval.ast) = new StatementNode(id, dynamic_cast<ExpressionNode*>((yyvsp[-4].ast)), dynamic_cast<ExpressionNode*>((yyvsp[-2].ast)), dynamic_cast<StatementNode*>((yyvsp[0].ast)));
    }
    else {
        yyerror("Expected ':=' operator");
        YYERROR;
    }
}
#line 1753 "syntax.tab.cpp"
    break;

  case 51: /* StatementNode: Read Lparen VariableListNode Rparen  */
#line 308 "syntax.y"
                                        {
    FinalNode* Re = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new StatementNode(Re, dynamic_cast<VariableListNode*>((yyvsp[-1].ast)));
}
#line 1762 "syntax.tab.cpp"
    break;

  case 52: /* StatementNode: Write Lparen ExpressionListNode Rparen  */
#line 311 "syntax.y"
                                           {
    FinalNode* Wr = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new StatementNode(Wr, dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 1771 "syntax.tab.cpp"
    break;

  case 53: /* VariableListNode: VariableNode  */
#line 316 "syntax.y"
                               {
    (yyval.ast) = new VariableListNode(dynamic_cast<VariableNode*>((yyvsp[0].ast)));
}
#line 1779 "syntax.tab.cpp"
    break;

  case 54: /* VariableListNode: VariableListNode Comma VariableNode  */
#line 318 "syntax.y"
                                        {
    (yyval.ast) = new VariableListNode(dynamic_cast<VariableNode*>((yyvsp[0].ast)), dynamic_cast<VariableListNode*>((yyvsp[-2].ast)));
}
#line 1787 "syntax.tab.cpp"
    break;

  case 55: /* VariableNode: Identifier IdVarpartNode  */
#line 322 "syntax.y"
                                       {
    FinalNode* id = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new VariableNode(id, dynamic_cast<IdVarpartNode*>((yyvsp[0].ast)));
}
#line 1796 "syntax.tab.cpp"
    break;

  case 56: /* IdVarpartNode: %empty  */
#line 327 "syntax.y"
               {
    (yyval.ast) = new IdVarpartNode();
}
#line 1804 "syntax.tab.cpp"
    break;

  case 57: /* IdVarpartNode: Lbra ExpressionListNode Rbra  */
#line 329 "syntax.y"
                                 {
    (yyval.ast) = new IdVarpartNode(dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 1812 "syntax.tab.cpp"
    break;

  case 58: /* ProcedureCallNode: Identifier  */
#line 333 "syntax.y"
                              {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ProcedureCallNode(id);
}
#line 1821 "syntax.tab.cpp"
    break;

  case 59: /* ProcedureCallNode: Identifier Lparen ExpressionListNode Rparen  */
#line 336 "syntax.y"
                                                {
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new ProcedureCallNode(id, dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 1830 "syntax.tab.cpp"
    break;

  case 60: /* ProcedureCallNode: Identifier Lparen Rparen  */
#line 339 "syntax.y"
                            {
    FinalNode* id = new FinalNode(*(yyvsp[-2].token));
    (yyval.ast) = new ProcedureCallNode(id); // 语法拓展：无参数过程调用支持 foo()
}
#line 1839 "syntax.tab.cpp"
    break;

  case 61: /* ElsePartNode: %empty  */
#line 344 "syntax.y"
               {
    (yyval.ast) = new ElsePartNode();
}
#line 1847 "syntax.tab.cpp"
    break;

  case 62: /* ElsePartNode: Else StatementNode  */
#line 346 "syntax.y"
                       {
    (yyval.ast) = new ElsePartNode(dynamic_cast<StatementNode*>((yyvsp[0].ast)));
}
#line 1855 "syntax.tab.cpp"
    break;

  case 63: /* ExpressionListNode: ExpressionNode  */
#line 350 "syntax.y"
                                   {
    (yyval.ast) = new ExpressionListNode(dynamic_cast<ExpressionNode*>((yyvsp[0].ast)));
}
#line 1863 "syntax.tab.cpp"
    break;

  case 64: /* ExpressionListNode: ExpressionListNode Comma ExpressionNode  */
#line 352 "syntax.y"
                                            {
    (yyval.ast) = new ExpressionListNode(dynamic_cast<ExpressionNode*>((yyvsp[0].ast)), dynamic_cast<ExpressionListNode*>((yyvsp[-2].ast)));
}
#line 1871 "syntax.tab.cpp"
    break;

  case 65: /* ExpressionNode: SimpleExpressionNode  */
#line 356 "syntax.y"
                                     {
    (yyval.ast) = new ExpressionNode(dynamic_cast<SimpleExpressionNode*>((yyvsp[0].ast)));
}
#line 1879 "syntax.tab.cpp"
    break;

  case 66: /* ExpressionNode: SimpleExpressionNode Relop SimpleExpressionNode  */
#line 358 "syntax.y"
                                                    {
    FinalNode* id = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new ExpressionNode(dynamic_cast<SimpleExpressionNode*>((yyvsp[-2].ast)), id, dynamic_cast<SimpleExpressionNode*>((yyvsp[0].ast)));
}
#line 1888 "syntax.tab.cpp"
    break;

  case 67: /* SimpleExpressionNode: TermNode  */
#line 363 "syntax.y"
                               {
    (yyval.ast) = new SimpleExpressionNode(dynamic_cast<TermNode*>((yyvsp[0].ast)));
}
#line 1896 "syntax.tab.cpp"
    break;

  case 68: /* SimpleExpressionNode: SimpleExpressionNode Addop TermNode  */
#line 365 "syntax.y"
                                        {
    FinalNode* op = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new SimpleExpressionNode(dynamic_cast<TermNode*>((yyvsp[0].ast)), dynamic_cast<SimpleExpressionNode*>((yyvsp[-2].ast)), op);
}
#line 1905 "syntax.tab.cpp"
    break;

  case 69: /* TermNode: FactorNode  */
#line 370 "syntax.y"
                     {
    (yyval.ast) = new TermNode(dynamic_cast<FactorNode*>((yyvsp[0].ast)));
}
#line 1913 "syntax.tab.cpp"
    break;

  case 70: /* TermNode: TermNode Mulop FactorNode  */
#line 372 "syntax.y"
                              {
    FinalNode* op = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new TermNode(dynamic_cast<FactorNode*>((yyvsp[0].ast)), dynamic_cast<TermNode*>((yyvsp[-2].ast)), op);
}
#line 1922 "syntax.tab.cpp"
    break;

  case 71: /* FactorNode: Number  */
#line 377 "syntax.y"
                   {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new FactorNode(id);
}
#line 1931 "syntax.tab.cpp"
    break;

  case 72: /* FactorNode: VariableNode  */
#line 380 "syntax.y"
                 {
    (yyval.ast) = new FactorNode(dynamic_cast<VariableNode*>((yyvsp[0].ast)));
}
#line 1939 "syntax.tab.cpp"
    break;

  case 73: /* FactorNode: Lparen ExpressionNode Rparen  */
#line 382 "syntax.y"
                                 {
    (yyval.ast) = new FactorNode(dynamic_cast<ExpressionNode*>((yyvsp[-1].ast)));
}
#line 1947 "syntax.tab.cpp"
    break;

  case 74: /* FactorNode: Identifier Lparen ExpressionListNode Rparen  */
#line 384 "syntax.y"
                                                {
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new FactorNode(id, dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 1956 "syntax.tab.cpp"
    break;

  case 75: /* FactorNode: Relop FactorNode  */
#line 387 "syntax.y"
                     {
    if((yyvsp[-1].token)->property == "not"){
        FinalNode* id = new FinalNode(*(yyvsp[-1].token));
        (yyval.ast) = new FactorNode(id, dynamic_cast<FactorNode*>((yyvsp[0].ast)));
    }
    else {
        yyerror("Expected 'not' keyword");
        YYERROR;
    }
}
#line 1971 "syntax.tab.cpp"
    break;

  case 76: /* FactorNode: Addop FactorNode  */
#line 396 "syntax.y"
                     {
    if((yyvsp[-1].token)->property == "-"){
        FinalNode* op = new FinalNode(*(yyvsp[-1].token));
        (yyval.ast) = new FactorNode(op,dynamic_cast<FactorNode*>((yyvsp[0].ast)));
    }
    else {
        yyerror("Expected '-'");
        YYERROR;
    }
}
#line 1986 "syntax.tab.cpp"
    break;

  case 77: /* FactorNode: Booltype  */
#line 405 "syntax.y"
             {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new FactorNode(id);
}
#line 1995 "syntax.tab.cpp"
    break;

  case 78: /* FactorNode: Identifier Lparen Rparen  */
#line 408 "syntax.y"
                            {
    FinalNode* id = new FinalNode(*(yyvsp[-2].token));
    IdVarpartNode* fake_idvar = new IdVarpartNode();
    VariableNode* fake_var = new VariableNode(id, fake_idvar);
    (yyval.ast) = new FactorNode(fake_var); // 测试用例21: 无参数函数 a := foo(); write(foo())
}
#line 2006 "syntax.tab.cpp"
    break;


#line 2010 "syntax.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 418 "syntax.y"


int yylex() {
    if (tokenIndex >= tokens.size()) return 0;
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
