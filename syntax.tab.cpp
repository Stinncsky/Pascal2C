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
#line 1 "syntax_err.y"

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

#line 94 "syntax.tab.cpp"

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
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUM = 4,                        /* NUM  */
  YYSYMBOL_STR_V = 5,                      /* STR_V  */
  YYSYMBOL_CHAR_V = 6,                     /* CHAR_V  */
  YYSYMBOL_PROGRAM = 7,                    /* PROGRAM  */
  YYSYMBOL_CONST = 8,                      /* CONST  */
  YYSYMBOL_VAR = 9,                        /* VAR  */
  YYSYMBOL_ARRAY = 10,                     /* ARRAY  */
  YYSYMBOL_OF = 11,                        /* OF  */
  YYSYMBOL_TYPE = 12,                      /* TYPE  */
  YYSYMBOL_PROCEDURE = 13,                 /* PROCEDURE  */
  YYSYMBOL_FUNCTION = 14,                  /* FUNCTION  */
  YYSYMBOL_BEGIN = 15,                     /* BEGIN  */
  YYSYMBOL_END = 16,                       /* END  */
  YYSYMBOL_IF = 17,                        /* IF  */
  YYSYMBOL_THEN = 18,                      /* THEN  */
  YYSYMBOL_FOR = 19,                       /* FOR  */
  YYSYMBOL_TO = 20,                        /* TO  */
  YYSYMBOL_DO = 21,                        /* DO  */
  YYSYMBOL_READ = 22,                      /* READ  */
  YYSYMBOL_WRITE = 23,                     /* WRITE  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_BOOL = 25,                      /* BOOL  */
  YYSYMBOL_NOTOP = 26,                     /* NOTOP  */
  YYSYMBOL_MULOP = 27,                     /* MULOP  */
  YYSYMBOL_ADDOP = 28,                     /* ADDOP  */
  YYSYMBOL_RELOP = 29,                     /* RELOP  */
  YYSYMBOL_ASSIGNOP = 30,                  /* ASSIGNOP  */
  YYSYMBOL_DOTDOT = 31,                    /* DOTDOT  */
  YYSYMBOL_SEMI = 32,                      /* SEMI  */
  YYSYMBOL_DOT = 33,                       /* DOT  */
  YYSYMBOL_LPAREN = 34,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 35,                    /* RPAREN  */
  YYSYMBOL_LBRA = 36,                      /* LBRA  */
  YYSYMBOL_RBRA = 37,                      /* RBRA  */
  YYSYMBOL_COLON = 38,                     /* COLON  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_Null = 40,                      /* Null  */
  YYSYMBOL_WHILE = 41,                     /* WHILE  */
  YYSYMBOL_BREAK = 42,                     /* BREAK  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_ProgramStructNode = 44,         /* ProgramStructNode  */
  YYSYMBOL_ProgramHeadNode = 45,           /* ProgramHeadNode  */
  YYSYMBOL_ProgramBodyNode = 46,           /* ProgramBodyNode  */
  YYSYMBOL_IdListNode = 47,                /* IdListNode  */
  YYSYMBOL_ConstDeclarationsNode = 48,     /* ConstDeclarationsNode  */
  YYSYMBOL_ConstDeclarationNode = 49,      /* ConstDeclarationNode  */
  YYSYMBOL_ConstValueNode = 50,            /* ConstValueNode  */
  YYSYMBOL_VarDeclarationsNode = 51,       /* VarDeclarationsNode  */
  YYSYMBOL_VarDeclarationNode = 52,        /* VarDeclarationNode  */
  YYSYMBOL_TypeNode = 53,                  /* TypeNode  */
  YYSYMBOL_BasicTypeNode = 54,             /* BasicTypeNode  */
  YYSYMBOL_PeriodNode = 55,                /* PeriodNode  */
  YYSYMBOL_SubprogramDeclarationsNode = 56, /* SubprogramDeclarationsNode  */
  YYSYMBOL_SubprogramNode = 57,            /* SubprogramNode  */
  YYSYMBOL_SubprogramHeadNode = 58,        /* SubprogramHeadNode  */
  YYSYMBOL_FormalParameterNode = 59,       /* FormalParameterNode  */
  YYSYMBOL_ParameterListNode = 60,         /* ParameterListNode  */
  YYSYMBOL_ParameterNode = 61,             /* ParameterNode  */
  YYSYMBOL_VarParameterNode = 62,          /* VarParameterNode  */
  YYSYMBOL_ValueParameterNode = 63,        /* ValueParameterNode  */
  YYSYMBOL_SubprogramBodyNode = 64,        /* SubprogramBodyNode  */
  YYSYMBOL_CompoundStatementNode = 65,     /* CompoundStatementNode  */
  YYSYMBOL_StatementListNode = 66,         /* StatementListNode  */
  YYSYMBOL_StatementNode = 67,             /* StatementNode  */
  YYSYMBOL_VariableListNode = 68,          /* VariableListNode  */
  YYSYMBOL_VariableNode = 69,              /* VariableNode  */
  YYSYMBOL_IdVarpartNode = 70,             /* IdVarpartNode  */
  YYSYMBOL_ProcedureCallNode = 71,         /* ProcedureCallNode  */
  YYSYMBOL_ElsePartNode = 72,              /* ElsePartNode  */
  YYSYMBOL_ExpressionListNode = 73,        /* ExpressionListNode  */
  YYSYMBOL_ExpressionNode = 74,            /* ExpressionNode  */
  YYSYMBOL_SimpleExpressionNode = 75,      /* SimpleExpressionNode  */
  YYSYMBOL_TermNode = 76,                  /* TermNode  */
  YYSYMBOL_FactorNode = 77                 /* FactorNode  */
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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   292

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  126
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  275

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    49,    49,    51,    57,    62,    65,    68,    75,    82,
      85,    89,    95,   105,   107,   109,   116,   126,   136,   143,
     153,   156,   159,   165,   167,   169,   175,   178,   180,   184,
     188,   196,   199,   201,   204,   207,   210,   217,   231,   241,
     251,   261,   271,   277,   283,   289,   298,   300,   302,   308,
     316,   322,   326,   329,   332,   335,   338,   341,   347,   349,
     351,   355,   357,   359,   365,   367,   371,   373,   379,   381,
     387,   391,   393,   399,   401,   405,   407,   415,   424,   426,
     428,   430,   439,   444,   449,   454,   459,   462,   467,   472,
     475,   480,   485,   487,   491,   496,   498,   502,   507,   509,
     511,   517,   520,   523,   528,   531,   538,   540,   544,   546,
     550,   552,   557,   559,   564,   566,   571,   574,   576,   578,
     582,   585,   590,   599,   608,   611,   616
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUM", "STR_V",
  "CHAR_V", "PROGRAM", "CONST", "VAR", "ARRAY", "OF", "TYPE", "PROCEDURE",
  "FUNCTION", "BEGIN", "END", "IF", "THEN", "FOR", "TO", "DO", "READ",
  "WRITE", "ELSE", "BOOL", "NOTOP", "MULOP", "ADDOP", "RELOP", "ASSIGNOP",
  "DOTDOT", "SEMI", "DOT", "LPAREN", "RPAREN", "LBRA", "RBRA", "COLON",
  "COMMA", "Null", "WHILE", "BREAK", "$accept", "ProgramStructNode",
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

#define YYPACT_NINF (-134)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     160,  -134,   216,    24,     0,  -134,    84,  -134,   134,   136,
     161,   165,   166,   174,   102,   178,  -134,   166,  -134,  -134,
       9,   153,   215,   230,  -134,    25,   106,   184,   235,  -134,
     224,  -134,  -134,  -134,   236,  -134,   221,   226,   181,   182,
     166,   166,   250,   225,   228,    19,   111,   113,  -134,  -134,
    -134,  -134,  -134,   153,   153,   218,    85,  -134,  -134,  -134,
    -134,    30,    34,   222,   222,   222,   222,   222,   -11,   138,
     229,    89,    90,   138,  -134,  -134,   100,  -134,   227,  -134,
    -134,  -134,   136,   136,  -134,  -134,   200,   200,   200,   182,
     181,   182,   101,   220,  -134,  -134,   223,    81,   138,   105,
     138,  -134,   201,  -134,  -134,   138,   138,   138,  -134,   241,
     214,   233,  -134,   232,     3,   260,   260,   138,   138,   104,
    -134,  -134,    19,   138,   165,  -134,  -134,   234,   237,   238,
     197,   202,    39,  -134,  -134,  -134,   166,   166,  -134,    36,
      15,  -134,  -134,  -134,   252,   252,   252,   252,  -134,  -134,
    -134,    17,  -134,    42,   145,  -134,  -134,    87,    19,   138,
     138,   138,   138,   138,   138,   231,   112,  -134,    45,   170,
      48,    19,    19,  -134,  -134,   251,   266,   116,   265,   261,
     206,   262,   263,    16,  -134,  -134,   183,   252,   199,   199,
    -134,  -134,  -134,  -134,  -134,  -134,  -134,   138,  -134,  -134,
    -134,  -134,    50,  -134,  -134,   253,   233,   247,  -134,   256,
     258,    91,  -134,   260,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,  -134,  -134,  -134,  -134,  -134,   252,   248,   249,   254,
     252,   252,   252,   252,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,    19,  -134,   138,   138,   138,   138,  -134,  -134,   277,
     186,   276,  -134,  -134,  -134,  -134,  -134,   267,   268,   269,
     114,  -134,  -134,  -134,  -134,    19,    19,    19,    19,    19,
    -134,  -134,  -134,  -134,  -134
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,    13,     7,     5,     1,     0,    13,
       0,    23,     0,     0,     0,     0,     4,     0,    46,     9,
       0,     0,    15,    14,     2,     0,     0,     0,     0,     6,
       0,    20,    22,    21,     0,    16,     0,     0,     0,     0,
      25,    24,     0,     0,     0,    75,     0,     0,     8,    11,
      12,    10,    19,     0,     0,     0,     0,    37,    28,    31,
      26,     0,     0,    58,    58,    58,    58,    58,   101,     0,
       0,     0,     0,     0,    94,    79,     0,    73,     0,    78,
      48,    47,    13,    13,    18,    17,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    51,     0,     0,     0,     0,
       0,    97,    98,   116,   124,     0,     0,     0,   117,     0,
     110,   112,   114,     0,     0,     0,     0,     0,     0,     0,
      72,    71,    75,     0,    23,    50,    49,     0,     0,     0,
       0,     0,     0,    29,    30,    27,     0,     0,    60,     0,
       0,    61,    64,    65,     0,     0,     0,     0,    77,   105,
     104,     0,   108,     0,     0,   122,   123,     0,    75,     0,
       0,     0,     0,     0,     0,    98,     0,    95,     0,     0,
       0,    75,    75,    74,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    66,     0,     0,     0,     0,
      59,    55,    56,    57,    52,   103,   102,     0,   100,    99,
     126,   125,     0,   119,   118,   106,   113,   111,   115,     0,
       0,     0,    87,     0,    88,    86,    90,    91,    89,    93,
      92,    70,    42,    43,    38,    39,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    68,    63,    62,   109,   121,
     120,    75,    80,     0,     0,     0,     0,    96,    33,     0,
       0,     0,    34,    35,    36,    32,   107,     0,     0,     0,
       0,    44,    45,    40,    41,    75,    75,    75,    75,    75,
      82,    83,    84,    85,    81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,   274,   148,   -54,  -134,   191,   162,  -134,
     -24,  -133,   159,  -134,  -134,  -134,   149,  -134,    60,  -134,
     115,   204,   -25,  -134,  -113,   168,   -45,  -134,  -134,  -134,
     -97,   -68,   131,   133,   -99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    10,   139,    11,    14,    35,    18,    26,
      58,    59,   130,    27,    46,    47,    93,   140,   141,   142,
     143,   125,    75,    76,    77,   166,   108,   101,    79,   242,
     151,   152,   110,   111,   112
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,   109,    48,   153,   163,   119,   155,   156,     8,   173,
      28,   191,   192,   193,   194,    60,   188,   232,   195,    98,
     169,   170,    68,    99,     7,   100,    38,   233,   124,   124,
     148,    28,     9,   164,    45,    90,    69,   186,    70,   157,
     182,    71,    72,   198,    29,   205,   214,   189,    30,   217,
     190,   239,   196,   234,   235,   174,   197,   202,   219,   220,
      73,    74,   208,    39,    30,   133,   134,   135,    89,    30,
     167,   167,    91,    30,   187,    30,   183,    78,   180,   199,
     215,   197,   146,   218,   213,   240,    87,   197,   203,   197,
     115,   117,   245,   248,   209,   210,   211,   252,   253,   254,
     255,   120,   136,    22,    19,   171,   149,    40,   102,   103,
     137,   246,    80,    78,    82,   268,   121,   223,    12,   147,
     224,    88,   204,   116,   118,   172,    78,    78,   256,   238,
     104,   105,   122,   106,    23,   269,   138,    13,    41,   107,
     150,   102,   103,    81,     8,    83,   200,   212,   102,   103,
     221,   213,   270,   271,   272,   273,   274,    31,    32,    33,
      20,     1,    16,   104,   105,    25,   106,     2,   247,    19,
     104,   105,   107,   106,    17,   257,   258,   259,   260,   107,
     201,    34,    55,    55,    49,    42,    49,   262,    61,    62,
     263,    56,    56,    57,    57,    57,    78,    43,    44,    45,
     136,   127,    19,    21,   128,   216,   129,   227,   137,   197,
     228,    24,   229,    94,    95,    96,    97,     5,    36,     6,
      78,    78,    78,    78,    78,    50,    64,    51,    65,    66,
     113,    67,   114,    37,   179,   154,   180,   100,    49,   181,
      52,   180,   159,   160,    84,    85,   131,   132,   236,   237,
      53,   184,   185,    63,    86,    54,    92,   123,   144,   158,
     161,   145,   162,   165,    57,   176,    45,   100,   177,   178,
     222,   225,   226,   230,   231,   159,   243,   241,   244,   249,
     250,   261,   264,    15,   168,   251,   175,   126,   265,   266,
     267,   207,   206
};

static const yytype_int16 yycheck[] =
{
      45,    69,    27,   100,     1,    73,   105,   106,     8,   122,
       1,   144,   145,   146,   147,    39,     1,     1,     1,    30,
     117,   118,     3,    34,     0,    36,     1,    11,    82,    83,
      98,     1,    32,    30,    15,     1,    17,     1,    19,   107,
       1,    22,    23,     1,    35,   158,     1,    32,    39,     1,
      35,     1,    35,   186,   187,   123,    39,   154,   171,   172,
      41,    42,   161,    38,    39,    89,    90,    91,    38,    39,
     115,   116,    38,    39,    38,    39,    37,   122,    39,    37,
      35,    39,     1,    35,    39,    35,     1,    39,     1,    39,
       1,     1,     1,   226,   162,   163,   164,   230,   231,   232,
     233,     1,     1,     1,     3,     1,     1,     1,     3,     4,
       9,    20,     1,   158,     1,     1,    16,     1,    34,    38,
       4,    36,    35,    34,    34,    21,   171,   172,   241,   197,
      25,    26,    32,    28,    32,    21,    35,     3,    32,    34,
      35,     3,     4,    32,     8,    32,     1,    35,     3,     4,
     175,    39,   265,   266,   267,   268,   269,     4,     5,     6,
      12,     1,     1,    25,    26,    17,    28,     7,   213,     3,
      25,    26,    34,    28,     9,   243,   244,   245,   246,    34,
      35,    28,     1,     1,     3,     1,     3,     1,    40,    41,
       4,    10,    10,    12,    12,    12,   241,    13,    14,    15,
       1,     1,     3,    29,     4,    35,     6,     1,     9,    39,
       4,    33,     6,    64,    65,    66,    67,     1,     3,     3,
     265,   266,   267,   268,   269,     1,     1,     3,     3,     1,
       1,     3,     3,     3,    37,    34,    39,    36,     3,    37,
       4,    39,    28,    29,    53,    54,    87,    88,   188,   189,
      29,   136,   137,     3,    36,    29,    34,    30,    38,    18,
      27,    38,    30,     3,    12,    31,    15,    36,    31,    31,
       4,     6,    11,    11,    11,    28,    20,    24,    20,    31,
      31,     4,     6,     9,   116,    31,   124,    83,    21,    21,
      21,   160,   159
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     7,    44,    45,     1,     3,     0,     8,    32,
      46,    48,    34,     3,    49,    46,     1,     9,    51,     3,
      47,    29,     1,    32,    33,    47,    52,    56,     1,    35,
      39,     4,     5,     6,    28,    50,     3,     3,     1,    38,
       1,    32,     1,    13,    14,    15,    57,    58,    65,     3,
       1,     3,     4,    29,    29,     1,    10,    12,    53,    54,
      53,    47,    47,     3,     1,     3,     1,     3,     3,    17,
      19,    22,    23,    41,    42,    65,    66,    67,    69,    71,
       1,    32,     1,    32,    50,    50,    36,     1,    36,    38,
       1,    38,    34,    59,    59,    59,    59,    59,    30,    34,
      36,    70,     3,     4,    25,    26,    28,    34,    69,    74,
      75,    76,    77,     1,     3,     1,    34,     1,    34,    74,
       1,    16,    32,    30,    48,    64,    64,     1,     4,     6,
      55,    55,    55,    53,    53,    53,     1,     9,    35,    47,
      60,    61,    62,    63,    38,    38,     1,    38,    74,     1,
      35,    73,    74,    73,    34,    77,    77,    74,    18,    28,
      29,    27,    30,     1,    30,     3,    68,    69,    68,    73,
      73,     1,    21,    67,    74,    51,    31,    31,    31,    37,
      39,    37,     1,    37,    63,    63,     1,    38,     1,    32,
      35,    54,    54,    54,    54,     1,    35,    39,     1,    37,
       1,    35,    73,     1,    35,    67,    76,    75,    77,    74,
      74,    74,    35,    39,     1,    35,    35,     1,    35,    67,
      67,    65,     4,     1,     4,     6,    11,     1,     4,     6,
      11,    11,     1,    11,    54,    54,    61,    61,    74,     1,
      35,    24,    72,    20,    20,     1,    20,    69,    54,    31,
      31,    31,    54,    54,    54,    54,    67,    74,    74,    74,
      74,     4,     1,     4,     6,    21,    21,    21,     1,    21,
      67,    67,    67,    67,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    44,    45,    45,    45,    46,    47,
      47,    47,    47,    48,    48,    48,    49,    49,    49,    50,
      50,    50,    50,    51,    51,    51,    52,    52,    52,    52,
      52,    53,    53,    53,    53,    53,    53,    54,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    60,    60,    60,    61,    61,    62,    62,    63,    63,
      64,    65,    65,    66,    66,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    70,    70,
      70,    71,    71,    71,    71,    71,    72,    72,    73,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     3,     2,     5,     2,     4,     1,
       3,     3,     3,     0,     3,     3,     3,     5,     5,     2,
       1,     1,     1,     0,     3,     3,     3,     5,     3,     5,
       5,     1,     6,     6,     6,     6,     6,     1,     3,     3,
       5,     5,     3,     3,     5,     5,     0,     3,     3,     3,
       3,     3,     5,     3,     3,     5,     5,     5,     0,     3,
       2,     1,     3,     3,     1,     1,     2,     2,     3,     3,
       3,     3,     3,     1,     3,     0,     3,     3,     1,     1,
       5,     8,     8,     8,     8,     8,     4,     4,     4,     4,
       4,     4,     4,     4,     1,     1,     3,     2,     0,     3,
       3,     1,     4,     4,     3,     3,     0,     2,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     3,     3,
       4,     4,     2,     2,     1,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = Tk_YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == Tk_YYEMPTY)                                        \
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
   Use Tk_YYerror or Tk_YYUNDEF. */
#define YYERRCODE Tk_YYUNDEF


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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = Tk_YYEMPTY; /* Cause a token to be read.  */

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
  if (yychar == Tk_YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= Tk_YYEOF)
    {
      yychar = Tk_YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == Tk_YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = Tk_YYUNDEF;
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
  yychar = Tk_YYEMPTY;
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
  case 2: /* ProgramStructNode: ProgramHeadNode SEMI ProgramBodyNode DOT  */
#line 49 "syntax_err.y"
                                                            {
    syntax->tree = new ProgramStructNode(dynamic_cast<ProgramHeadNode*>((yyvsp[-3].ast)), dynamic_cast<ProgramBodyNode*>((yyvsp[-1].ast)));
}
#line 1615 "syntax.tab.cpp"
    break;

  case 3: /* ProgramStructNode: error  */
#line 51 "syntax_err.y"
          {
    yyerror("Unrecoverable errors occurred");
    while(yychar != Tk_YYEOF) {
        yychar = yylex();
    }
    (yyval.ast) = nullptr; 
}
#line 1627 "syntax.tab.cpp"
    break;

  case 4: /* ProgramStructNode: ProgramHeadNode ProgramBodyNode error  */
#line 57 "syntax_err.y"
                                          {
    syntax->tree = new ProgramStructNode(dynamic_cast<ProgramHeadNode*>((yyvsp[-2].ast)), dynamic_cast<ProgramBodyNode*>((yyvsp[-1].ast)));
    yyerror("Expected '.' at the end of the program");
}
#line 1636 "syntax.tab.cpp"
    break;

  case 5: /* ProgramHeadNode: PROGRAM ID  */
#line 62 "syntax_err.y"
                            {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ProgramHeadNode(id);
}
#line 1645 "syntax.tab.cpp"
    break;

  case 6: /* ProgramHeadNode: PROGRAM ID LPAREN IdListNode RPAREN  */
#line 65 "syntax_err.y"
                                        {
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new ProgramHeadNode(id, dynamic_cast<IdListNode*>((yyvsp[-1].ast)));
}
#line 1654 "syntax.tab.cpp"
    break;

  case 7: /* ProgramHeadNode: PROGRAM error  */
#line 68 "syntax_err.y"
                  {
    yyerror("Expected program name after 'program' keyword");
    FinalNode* id = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new ProgramHeadNode(id);
    yyerrok;
}
#line 1665 "syntax.tab.cpp"
    break;

  case 8: /* ProgramBodyNode: ConstDeclarationsNode VarDeclarationsNode SubprogramDeclarationsNode CompoundStatementNode  */
#line 75 "syntax_err.y"
                                                                                                            {
    (yyval.ast) = new ProgramBodyNode(dynamic_cast<ConstDeclarationsNode*>((yyvsp[-3].ast)),
    dynamic_cast<VarDeclarationsNode*>((yyvsp[-2].ast)),
    dynamic_cast<SubprogramDeclarationsNode*>((yyvsp[-1].ast)),
    dynamic_cast<CompoundStatementNode*>((yyvsp[0].ast)));
}
#line 1676 "syntax.tab.cpp"
    break;

  case 9: /* IdListNode: ID  */
#line 82 "syntax_err.y"
               {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new IdListNode(id);
}
#line 1685 "syntax.tab.cpp"
    break;

  case 10: /* IdListNode: IdListNode COMMA ID  */
#line 85 "syntax_err.y"
                        {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    IdListNode* idList = dynamic_cast<IdListNode*>((yyvsp[-2].ast));
    (yyval.ast) = new IdListNode(id, idList);
}
#line 1695 "syntax.tab.cpp"
    break;

  case 11: /* IdListNode: IdListNode error ID  */
#line 89 "syntax_err.y"
                        {
    yyerror_at("Expected ',' after IdListNode", (yyvsp[0].token)->line, (yyvsp[0].token)->column, (yyvsp[0].token));
    yyerrok;
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    IdListNode* idList = dynamic_cast<IdListNode*>((yyvsp[-2].ast));
    (yyval.ast) = new IdListNode(id, idList);
}
#line 1707 "syntax.tab.cpp"
    break;

  case 12: /* IdListNode: IdListNode COMMA error  */
#line 95 "syntax_err.y"
                           {
    yyerror("Expected ID after ','");
    yyerrok;
    FinalNode* id = new FinalNode(*(yyvsp[-1].token));
    IdListNode* idList = dynamic_cast<IdListNode*>((yyvsp[-2].ast));
    (yyval.ast) = new IdListNode(id, idList);
}
#line 1719 "syntax.tab.cpp"
    break;

  case 13: /* ConstDeclarationsNode: %empty  */
#line 105 "syntax_err.y"
    {
        (yyval.ast) = new ConstDeclarationsNode();
    }
#line 1727 "syntax.tab.cpp"
    break;

  case 14: /* ConstDeclarationsNode: CONST ConstDeclarationNode SEMI  */
#line 107 "syntax_err.y"
                                        {
        (yyval.ast) = new ConstDeclarationsNode(dynamic_cast<ConstDeclarationNode*>((yyvsp[-1].ast)));
    }
#line 1735 "syntax.tab.cpp"
    break;

  case 15: /* ConstDeclarationsNode: CONST ConstDeclarationNode error  */
#line 109 "syntax_err.y"
                                        {
        yyerror("Except ';' after ConstDeclarationsNode");
        yyerrok;
        (yyval.ast) = new ConstDeclarationsNode(); 
    }
#line 1745 "syntax.tab.cpp"
    break;

  case 16: /* ConstDeclarationNode: ID RELOP ConstValueNode  */
#line 116 "syntax_err.y"
                                              {
    if((yyvsp[-1].token)->property == "=") {
        FinalNode* id = new FinalNode(*(yyvsp[-2].token));
        (yyval.ast) = new ConstDeclarationNode(id, dynamic_cast<ConstValueNode*>((yyvsp[0].ast)));
    }
    else {
        yyerror_at("Expected '='", (yyvsp[-1].token)->line, (yyvsp[-1].token)->column + 1, (yyvsp[-1].token));
        YYERROR;
        yyerrok;
    }
}
#line 1761 "syntax.tab.cpp"
    break;

  case 17: /* ConstDeclarationNode: ConstDeclarationNode SEMI ID RELOP ConstValueNode  */
#line 126 "syntax_err.y"
                                                      {
    if((yyvsp[-1].token)->property == "=") {
        FinalNode* id = new FinalNode(*(yyvsp[-2].token));
        (yyval.ast) = new ConstDeclarationNode(id, dynamic_cast<ConstValueNode*>((yyvsp[0].ast)), dynamic_cast<ConstDeclarationNode*>((yyvsp[-4].ast)));
    }
    else {
        yyerror("Expected '='");
        YYERROR;
        yyerrok;
    }
}
#line 1777 "syntax.tab.cpp"
    break;

  case 18: /* ConstDeclarationNode: ConstDeclarationNode error ID RELOP ConstValueNode  */
#line 136 "syntax_err.y"
                                                       {
    yyerror_at("Expected ';' after ConstDeclarationNode", (yyvsp[-2].token)->line, (yyvsp[-2].token)->column, (yyvsp[-2].token));
    yyerrok;
    FinalNode* id = new FinalNode(*(yyvsp[-2].token));
    (yyval.ast) = new ConstDeclarationNode(id, dynamic_cast<ConstValueNode*>((yyvsp[0].ast)), dynamic_cast<ConstDeclarationNode*>((yyvsp[-4].ast)));
}
#line 1788 "syntax.tab.cpp"
    break;

  case 19: /* ConstValueNode: ADDOP NUM  */
#line 143 "syntax_err.y"
                          {
    if((yyvsp[-1].token)->property == "+" || (yyvsp[-1].token)->property == "-") {
        FinalNode* op = new FinalNode(*(yyvsp[-1].token));
        FinalNode* num = new FinalNode(*(yyvsp[0].token));
        (yyval.ast) = new ConstValueNode(op,num);
    } else {
        yyerror_at("Expected '+' or '-'", (yyvsp[-1].token)->line, (yyvsp[-1].token)->column, (yyvsp[-1].token));
        YYERROR;
        yyerrok;
    }
}
#line 1804 "syntax.tab.cpp"
    break;

  case 20: /* ConstValueNode: NUM  */
#line 153 "syntax_err.y"
        {
    FinalNode* num = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ConstValueNode(num);
}
#line 1813 "syntax.tab.cpp"
    break;

  case 21: /* ConstValueNode: CHAR_V  */
#line 156 "syntax_err.y"
           {
    FinalNode* num = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ConstValueNode(num);
}
#line 1822 "syntax.tab.cpp"
    break;

  case 22: /* ConstValueNode: STR_V  */
#line 159 "syntax_err.y"
          {
    FinalNode* num = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ConstValueNode(num);
}
#line 1831 "syntax.tab.cpp"
    break;

  case 23: /* VarDeclarationsNode: %empty  */
#line 165 "syntax_err.y"
                     {
    (yyval.ast) = new VarDeclarationsNode();
}
#line 1839 "syntax.tab.cpp"
    break;

  case 24: /* VarDeclarationsNode: VAR VarDeclarationNode SEMI  */
#line 167 "syntax_err.y"
                                {
    (yyval.ast) = new VarDeclarationsNode(dynamic_cast<VarDeclarationNode*>((yyvsp[-1].ast)));
}
#line 1847 "syntax.tab.cpp"
    break;

  case 25: /* VarDeclarationsNode: VAR VarDeclarationNode error  */
#line 169 "syntax_err.y"
                                 {
    yyerror("Expected ';' after VarDeclarationsNode");
    yyerrok;
    (yyval.ast) = new VarDeclarationsNode();
}
#line 1857 "syntax.tab.cpp"
    break;

  case 26: /* VarDeclarationNode: IdListNode COLON TypeNode  */
#line 175 "syntax_err.y"
                                              {
    (yyval.ast) = new VarDeclarationNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<TypeNode*>((yyvsp[0].ast)));

}
#line 1866 "syntax.tab.cpp"
    break;

  case 27: /* VarDeclarationNode: VarDeclarationNode SEMI IdListNode COLON TypeNode  */
#line 178 "syntax_err.y"
                                                      {
    (yyval.ast) = new VarDeclarationNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<TypeNode*>((yyvsp[0].ast)), dynamic_cast<VarDeclarationNode*>((yyvsp[-4].ast)));
}
#line 1874 "syntax.tab.cpp"
    break;

  case 28: /* VarDeclarationNode: IdListNode error TypeNode  */
#line 180 "syntax_err.y"
                              {
    yyerror("Expected ':' after IdListNode");
    yyerrok;
    (yyval.ast) = new VarDeclarationNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<TypeNode*>((yyvsp[0].ast)));
}
#line 1884 "syntax.tab.cpp"
    break;

  case 29: /* VarDeclarationNode: VarDeclarationNode error IdListNode COLON TypeNode  */
#line 184 "syntax_err.y"
                                                       {
    yyerror("Expected ';' after VarDeclarationNode");
    yyerrok;
    (yyval.ast) = new VarDeclarationNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<TypeNode*>((yyvsp[0].ast)), dynamic_cast<VarDeclarationNode*>((yyvsp[-4].ast)));
}
#line 1894 "syntax.tab.cpp"
    break;

  case 30: /* VarDeclarationNode: VarDeclarationNode SEMI IdListNode error TypeNode  */
#line 188 "syntax_err.y"
                                                      {
    yyerror("Expected ':' after IdListNode");
    yyerrok;
    (yyval.ast) = new VarDeclarationNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<TypeNode*>((yyvsp[0].ast)), dynamic_cast<VarDeclarationNode*>((yyvsp[-4].ast)));
}
#line 1904 "syntax.tab.cpp"
    break;

  case 31: /* TypeNode: BasicTypeNode  */
#line 196 "syntax_err.y"
                  {
        (yyval.ast) = new TypeNode(dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)));
    }
#line 1912 "syntax.tab.cpp"
    break;

  case 32: /* TypeNode: ARRAY LBRA PeriodNode RBRA OF BasicTypeNode  */
#line 199 "syntax_err.y"
                                                  {
        (yyval.ast) = new TypeNode(dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)), dynamic_cast<PeriodNode*>((yyvsp[-3].ast)));
    }
#line 1920 "syntax.tab.cpp"
    break;

  case 33: /* TypeNode: error LBRA PeriodNode RBRA OF BasicTypeNode  */
#line 201 "syntax_err.y"
                                                    {
        yyerror_at("Expected 'array' keyword", (yyvsp[-4].token)->line, (yyvsp[-4].token)->column, (yyvsp[-4].token));
        yyerrok;
    }
#line 1929 "syntax.tab.cpp"
    break;

  case 34: /* TypeNode: ARRAY error PeriodNode RBRA OF BasicTypeNode  */
#line 204 "syntax_err.y"
                                                     {
        yyerror_at("Expected '['", (yyvsp[-2].token)->line, (yyvsp[-2].token)->column, (yyvsp[-2].token));
        yyerrok;
    }
#line 1938 "syntax.tab.cpp"
    break;

  case 35: /* TypeNode: ARRAY LBRA PeriodNode error OF BasicTypeNode  */
#line 207 "syntax_err.y"
                                                     {
        yyerror_at("Expected ']'", (yyvsp[-1].token)->line, (yyvsp[-1].token)->column, (yyvsp[-1].token));
        yyerrok;
    }
#line 1947 "syntax.tab.cpp"
    break;

  case 36: /* TypeNode: ARRAY LBRA PeriodNode RBRA error BasicTypeNode  */
#line 210 "syntax_err.y"
                                                       {
        yyerror("Expected 'of'");
        yyerrok;
    }
#line 1956 "syntax.tab.cpp"
    break;

  case 37: /* BasicTypeNode: TYPE  */
#line 217 "syntax_err.y"
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
            yyerrok;
        }
    }
#line 1974 "syntax.tab.cpp"
    break;

  case 38: /* PeriodNode: NUM DOTDOT NUM  */
#line 231 "syntax_err.y"
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
#line 1990 "syntax.tab.cpp"
    break;

  case 39: /* PeriodNode: CHAR_V DOTDOT CHAR_V  */
#line 241 "syntax_err.y"
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
#line 2006 "syntax.tab.cpp"
    break;

  case 40: /* PeriodNode: PeriodNode COMMA NUM DOTDOT NUM  */
#line 251 "syntax_err.y"
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
#line 2022 "syntax.tab.cpp"
    break;

  case 41: /* PeriodNode: PeriodNode COMMA CHAR_V DOTDOT CHAR_V  */
#line 261 "syntax_err.y"
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
#line 2038 "syntax.tab.cpp"
    break;

  case 42: /* PeriodNode: error DOTDOT NUM  */
#line 271 "syntax_err.y"
                     {
    yyerror_at("Expected 'num' before '..' operator", (yyvsp[-1].token)->line, (yyvsp[-1].token)->column, (yyvsp[-1].token));
    yyerrok;
    FinalNode* id1 = new FinalNode(*(yyvsp[0].token));
    FinalNode* id2 = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new PeriodNode(id1, id2);
}
#line 2050 "syntax.tab.cpp"
    break;

  case 43: /* PeriodNode: NUM DOTDOT error  */
#line 277 "syntax_err.y"
                     {
    yyerror("Expected 'num' after '..' operator");
    yyerrok;
    FinalNode* id1 = new FinalNode(*(yyvsp[-2].token));
    FinalNode* id2 = new FinalNode(*(yyvsp[-2].token));
    (yyval.ast) = new PeriodNode(id1, id2);
}
#line 2062 "syntax.tab.cpp"
    break;

  case 44: /* PeriodNode: PeriodNode COMMA error DOTDOT NUM  */
#line 283 "syntax_err.y"
                                      {
    yyerror_at("Expected 'num' after ',' operator", (yyvsp[-1].token)->line, (yyvsp[-1].token)->column, (yyvsp[-1].token));
    yyerrok;
    FinalNode* id1 = new FinalNode(*(yyvsp[0].token));
    FinalNode* id2 = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new PeriodNode(id1, id2, dynamic_cast<PeriodNode*>((yyvsp[-4].ast))); 
}
#line 2074 "syntax.tab.cpp"
    break;

  case 45: /* PeriodNode: PeriodNode COMMA NUM DOTDOT error  */
#line 289 "syntax_err.y"
                                      {
    yyerror("Expected 'num' after '..' operator");
    yyerrok;
    FinalNode* id1 = new FinalNode(*(yyvsp[-2].token));
    FinalNode* id2 = new FinalNode(*(yyvsp[-2].token));
    (yyval.ast) = new PeriodNode(id1, id2, dynamic_cast<PeriodNode*>((yyvsp[-4].ast))); 
}
#line 2086 "syntax.tab.cpp"
    break;

  case 46: /* SubprogramDeclarationsNode: %empty  */
#line 298 "syntax_err.y"
                            {
    (yyval.ast) = new SubprogramDeclarationsNode();
}
#line 2094 "syntax.tab.cpp"
    break;

  case 47: /* SubprogramDeclarationsNode: SubprogramDeclarationsNode SubprogramNode SEMI  */
#line 300 "syntax_err.y"
                                                   {
    (yyval.ast) = new SubprogramDeclarationsNode(dynamic_cast<SubprogramDeclarationsNode*>((yyvsp[-2].ast)), dynamic_cast<SubprogramNode*>((yyvsp[-1].ast)));
}
#line 2102 "syntax.tab.cpp"
    break;

  case 48: /* SubprogramDeclarationsNode: SubprogramDeclarationsNode SubprogramNode error  */
#line 302 "syntax_err.y"
                                                    {
    yyerror("Expected ';' after SubprogramDeclarationsNode");
    yyerrok;
    (yyval.ast) = new SubprogramDeclarationsNode(dynamic_cast<SubprogramDeclarationsNode*>((yyvsp[-2].ast)), dynamic_cast<SubprogramNode*>((yyvsp[-1].ast)));
}
#line 2112 "syntax.tab.cpp"
    break;

  case 49: /* SubprogramNode: SubprogramHeadNode SEMI SubprogramBodyNode  */
#line 308 "syntax_err.y"
                                                           {
    if((yyvsp[-1].token)->property == ";") {
        (yyval.ast) = new SubprogramNode(dynamic_cast<SubprogramHeadNode*>((yyvsp[-2].ast)), dynamic_cast<SubprogramBodyNode*>((yyvsp[0].ast)));
    }
    else {
        yyerror("Expected ';'");
        YYERROR;
    }
}
#line 2126 "syntax.tab.cpp"
    break;

  case 50: /* SubprogramNode: SubprogramHeadNode error SubprogramBodyNode  */
#line 316 "syntax_err.y"
                                                {
    yyerror("Expected ';' after SubprogramHeadNode");
    yyerrok;
    (yyval.ast) = new SubprogramNode(dynamic_cast<SubprogramHeadNode*>((yyvsp[-2].ast)), dynamic_cast<SubprogramBodyNode*>((yyvsp[0].ast)));
}
#line 2136 "syntax.tab.cpp"
    break;

  case 51: /* SubprogramHeadNode: PROCEDURE ID FormalParameterNode  */
#line 322 "syntax_err.y"
                                                     {
    FinalNode* id = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new SubprogramHeadNode(id, dynamic_cast<FormalParameterNode*>((yyvsp[0].ast)));

}
#line 2146 "syntax.tab.cpp"
    break;

  case 52: /* SubprogramHeadNode: FUNCTION ID FormalParameterNode COLON BasicTypeNode  */
#line 326 "syntax_err.y"
                                                        {
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new SubprogramHeadNode(id, dynamic_cast<FormalParameterNode*>((yyvsp[-2].ast)), dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)));
}
#line 2155 "syntax.tab.cpp"
    break;

  case 53: /* SubprogramHeadNode: error ID FormalParameterNode  */
#line 329 "syntax_err.y"
                                 {
    yyerror_at("Expected 'procedure' before ID", (yyvsp[-1].token)->line, (yyvsp[-1].token)->column, (yyvsp[-1].token));
    yyerrok;
}
#line 2164 "syntax.tab.cpp"
    break;

  case 54: /* SubprogramHeadNode: PROCEDURE error FormalParameterNode  */
#line 332 "syntax_err.y"
                                        {
    yyerror("Expected 'ID' after 'procedure' keyword");
    yyerrok;
}
#line 2173 "syntax.tab.cpp"
    break;

  case 55: /* SubprogramHeadNode: error ID FormalParameterNode COLON BasicTypeNode  */
#line 335 "syntax_err.y"
                                                     {
    yyerror_at("Expected 'procedure' before ID", (yyvsp[-3].token)->line, (yyvsp[-3].token)->column, (yyvsp[-3].token));
    yyerrok;
}
#line 2182 "syntax.tab.cpp"
    break;

  case 56: /* SubprogramHeadNode: FUNCTION error FormalParameterNode COLON BasicTypeNode  */
#line 338 "syntax_err.y"
                                                           {
    yyerror("Expected 'ID' after 'function' keyword");
    yyerrok;
}
#line 2191 "syntax.tab.cpp"
    break;

  case 57: /* SubprogramHeadNode: FUNCTION ID FormalParameterNode error BasicTypeNode  */
#line 341 "syntax_err.y"
                                                        {
    yyerror("Expected ':' after 'function' keyword");
    yyerrok;
}
#line 2200 "syntax.tab.cpp"
    break;

  case 58: /* FormalParameterNode: %empty  */
#line 347 "syntax_err.y"
                     {
    (yyval.ast) = new FormalParameterNode();
}
#line 2208 "syntax.tab.cpp"
    break;

  case 59: /* FormalParameterNode: LPAREN ParameterListNode RPAREN  */
#line 349 "syntax_err.y"
                                    {
    (yyval.ast) = new FormalParameterNode(dynamic_cast<ParameterListNode*>((yyvsp[-1].ast)));
}
#line 2216 "syntax.tab.cpp"
    break;

  case 60: /* FormalParameterNode: LPAREN RPAREN  */
#line 351 "syntax_err.y"
                  {
    (yyval.ast) = new FormalParameterNode();
}
#line 2224 "syntax.tab.cpp"
    break;

  case 61: /* ParameterListNode: ParameterNode  */
#line 355 "syntax_err.y"
                                 {
    (yyval.ast) = new ParameterListNode(dynamic_cast<ParameterNode*>((yyvsp[0].ast)));
}
#line 2232 "syntax.tab.cpp"
    break;

  case 62: /* ParameterListNode: ParameterListNode SEMI ParameterNode  */
#line 357 "syntax_err.y"
                                         {
    (yyval.ast) = new ParameterListNode(dynamic_cast<ParameterNode*>((yyvsp[0].ast)), dynamic_cast<ParameterListNode*>((yyvsp[-2].ast)));
}
#line 2240 "syntax.tab.cpp"
    break;

  case 63: /* ParameterListNode: ParameterListNode error ParameterNode  */
#line 359 "syntax_err.y"
                                          {
    yyerror("Expected ';' after ParameterListNode");
    yyerrok;
    (yyval.ast) = new ParameterListNode(dynamic_cast<ParameterNode*>((yyvsp[0].ast)), dynamic_cast<ParameterListNode*>((yyvsp[-2].ast)));
}
#line 2250 "syntax.tab.cpp"
    break;

  case 64: /* ParameterNode: VarParameterNode  */
#line 365 "syntax_err.y"
                                {
    (yyval.ast) = new ParameterNode(dynamic_cast<VarParameterNode*>((yyvsp[0].ast)));
}
#line 2258 "syntax.tab.cpp"
    break;

  case 65: /* ParameterNode: ValueParameterNode  */
#line 367 "syntax_err.y"
                       {
    (yyval.ast) = new ParameterNode(dynamic_cast<ValueParameterNode*>((yyvsp[0].ast)));
}
#line 2266 "syntax.tab.cpp"
    break;

  case 66: /* VarParameterNode: VAR ValueParameterNode  */
#line 371 "syntax_err.y"
                                         {
    (yyval.ast) = new VarParameterNode(dynamic_cast<ValueParameterNode*>((yyvsp[0].ast)));
}
#line 2274 "syntax.tab.cpp"
    break;

  case 67: /* VarParameterNode: error ValueParameterNode  */
#line 373 "syntax_err.y"
                             {
    yyerror("Expected 'var' before ValueParameterNode");
    yyerrok;
    (yyval.ast) = new VarParameterNode(dynamic_cast<ValueParameterNode*>((yyvsp[0].ast)));
}
#line 2284 "syntax.tab.cpp"
    break;

  case 68: /* ValueParameterNode: IdListNode COLON BasicTypeNode  */
#line 379 "syntax_err.y"
                                                   {
    (yyval.ast) = new ValueParameterNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)));
}
#line 2292 "syntax.tab.cpp"
    break;

  case 69: /* ValueParameterNode: IdListNode error BasicTypeNode  */
#line 381 "syntax_err.y"
                                   {
    yyerror("Expected ':' after IdListNode");
    yyerrok;
    (yyval.ast) = new ValueParameterNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)));
}
#line 2302 "syntax.tab.cpp"
    break;

  case 70: /* SubprogramBodyNode: ConstDeclarationsNode VarDeclarationsNode CompoundStatementNode  */
#line 387 "syntax_err.y"
                                                                                    {
    (yyval.ast) = new SubprogramBodyNode(dynamic_cast<ConstDeclarationsNode*>((yyvsp[-2].ast)), dynamic_cast<VarDeclarationsNode*>((yyvsp[-1].ast)), dynamic_cast<CompoundStatementNode*>((yyvsp[0].ast)));
}
#line 2310 "syntax.tab.cpp"
    break;

  case 71: /* CompoundStatementNode: BEGIN StatementListNode END  */
#line 391 "syntax_err.y"
                                                   {
    (yyval.ast) = new CompoundStatementNode(dynamic_cast<StatementListNode*>((yyvsp[-1].ast)));
}
#line 2318 "syntax.tab.cpp"
    break;

  case 72: /* CompoundStatementNode: BEGIN StatementListNode error  */
#line 393 "syntax_err.y"
                                  {
    yyerror("Expected 'end' after statement list");
    yyerrok;
    (yyval.ast) = new CompoundStatementNode(dynamic_cast<StatementListNode*>((yyvsp[-1].ast)));
}
#line 2328 "syntax.tab.cpp"
    break;

  case 73: /* StatementListNode: StatementNode  */
#line 399 "syntax_err.y"
                                 {
    (yyval.ast) = new StatementListNode(dynamic_cast<StatementNode*>((yyvsp[0].ast)));
}
#line 2336 "syntax.tab.cpp"
    break;

  case 74: /* StatementListNode: StatementListNode SEMI StatementNode  */
#line 401 "syntax_err.y"
                                         {
    (yyval.ast) = new StatementListNode(dynamic_cast<StatementNode*>((yyvsp[0].ast)), dynamic_cast<StatementListNode*>((yyvsp[-2].ast)));
}
#line 2344 "syntax.tab.cpp"
    break;

  case 75: /* StatementNode: %empty  */
#line 405 "syntax_err.y"
               {
    (yyval.ast) = new StatementNode();
}
#line 2352 "syntax.tab.cpp"
    break;

  case 76: /* StatementNode: VariableNode ASSIGNOP ExpressionNode  */
#line 407 "syntax_err.y"
                                         {
    if((yyvsp[-1].token)->property == ":="){
        (yyval.ast) = new StatementNode(dynamic_cast<VariableNode*>((yyvsp[-2].ast)), dynamic_cast<ExpressionNode*>((yyvsp[0].ast)));
    }
    else {
        yyerror("Expected ':=' operator");
        YYERROR;
    }
}
#line 2366 "syntax.tab.cpp"
    break;

  case 77: /* StatementNode: ID ASSIGNOP ExpressionNode  */
#line 415 "syntax_err.y"
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
#line 2381 "syntax.tab.cpp"
    break;

  case 78: /* StatementNode: ProcedureCallNode  */
#line 424 "syntax_err.y"
                      {
    (yyval.ast) = new StatementNode(dynamic_cast<ProcedureCallNode*>((yyvsp[0].ast)));
}
#line 2389 "syntax.tab.cpp"
    break;

  case 79: /* StatementNode: CompoundStatementNode  */
#line 426 "syntax_err.y"
                          {
    (yyval.ast) = new StatementNode(dynamic_cast<CompoundStatementNode*>((yyvsp[0].ast)));
}
#line 2397 "syntax.tab.cpp"
    break;

  case 80: /* StatementNode: IF ExpressionNode THEN StatementNode ElsePartNode  */
#line 428 "syntax_err.y"
                                                      {
    (yyval.ast) = new StatementNode(dynamic_cast<ExpressionNode*>((yyvsp[-3].ast)), dynamic_cast<StatementNode*>((yyvsp[-1].ast)), dynamic_cast<ElsePartNode*>((yyvsp[0].ast)));
}
#line 2405 "syntax.tab.cpp"
    break;

  case 81: /* StatementNode: FOR ID ASSIGNOP ExpressionNode TO ExpressionNode DO StatementNode  */
#line 430 "syntax_err.y"
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
#line 2420 "syntax.tab.cpp"
    break;

  case 82: /* StatementNode: FOR error ASSIGNOP ExpressionNode TO ExpressionNode DO StatementNode  */
#line 439 "syntax_err.y"
                                                                         {
    yyerror("Expected 'ID' after 'for' keyword");
    yyerrok;
    FinalNode* id = new FinalNode(Token("errId", TokenType::Identifier));
    (yyval.ast) = new StatementNode(id, dynamic_cast<ExpressionNode*>((yyvsp[-4].ast)), dynamic_cast<ExpressionNode*>((yyvsp[-2].ast)), dynamic_cast<StatementNode*>((yyvsp[0].ast)));
}
#line 2431 "syntax.tab.cpp"
    break;

  case 83: /* StatementNode: FOR ID error ExpressionNode TO ExpressionNode DO StatementNode  */
#line 444 "syntax_err.y"
                                                                   {
    yyerror("Expected ':=' operator after 'ID'");
    yyerrok;
    FinalNode* id = new FinalNode(*(yyvsp[-6].token));
    (yyval.ast) = new StatementNode(id, dynamic_cast<ExpressionNode*>((yyvsp[-4].ast)), dynamic_cast<ExpressionNode*>((yyvsp[-2].ast)), dynamic_cast<StatementNode*>((yyvsp[0].ast)));
}
#line 2442 "syntax.tab.cpp"
    break;

  case 84: /* StatementNode: FOR ID ASSIGNOP ExpressionNode error ExpressionNode DO StatementNode  */
#line 449 "syntax_err.y"
                                                                         {
    yyerror("Expected 'to' after 'ExpressionNode'");
    yyerrok;
    FinalNode* id = new FinalNode(*(yyvsp[-6].token));
    (yyval.ast) = new StatementNode(id, dynamic_cast<ExpressionNode*>((yyvsp[-4].ast)), dynamic_cast<ExpressionNode*>((yyvsp[-2].ast)), dynamic_cast<StatementNode*>((yyvsp[0].ast)));
}
#line 2453 "syntax.tab.cpp"
    break;

  case 85: /* StatementNode: FOR ID ASSIGNOP ExpressionNode TO ExpressionNode error StatementNode  */
#line 454 "syntax_err.y"
                                                                         {
    yyerror("Expected 'do' after 'ExpressionNode'");
    yyerrok;
    FinalNode* id = new FinalNode(*(yyvsp[-6].token));
    (yyval.ast) = new StatementNode(id, dynamic_cast<ExpressionNode*>((yyvsp[-4].ast)), dynamic_cast<ExpressionNode*>((yyvsp[-2].ast)), dynamic_cast<StatementNode*>((yyvsp[0].ast)));
}
#line 2464 "syntax.tab.cpp"
    break;

  case 86: /* StatementNode: READ LPAREN VariableListNode RPAREN  */
#line 459 "syntax_err.y"
                                        {
    FinalNode* Re = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new StatementNode(Re, dynamic_cast<VariableListNode*>((yyvsp[-1].ast)));
}
#line 2473 "syntax.tab.cpp"
    break;

  case 87: /* StatementNode: READ error VariableListNode RPAREN  */
#line 462 "syntax_err.y"
                                       {
    yyerror("Expected '(' after 'read' keyword");
    yyerrok;
    FinalNode* Re = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new StatementNode(Re, dynamic_cast<VariableListNode*>((yyvsp[-1].ast)));
}
#line 2484 "syntax.tab.cpp"
    break;

  case 88: /* StatementNode: READ LPAREN VariableListNode error  */
#line 467 "syntax_err.y"
                                       {
    yyerror("Expected ')' after 'read' keyword");
    yyerrok;
    FinalNode* Re = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new StatementNode(Re, dynamic_cast<VariableListNode*>((yyvsp[-1].ast)));
}
#line 2495 "syntax.tab.cpp"
    break;

  case 89: /* StatementNode: WRITE LPAREN ExpressionListNode RPAREN  */
#line 472 "syntax_err.y"
                                           {
    FinalNode* Wr = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new StatementNode(Wr, dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 2504 "syntax.tab.cpp"
    break;

  case 90: /* StatementNode: WRITE error ExpressionListNode RPAREN  */
#line 475 "syntax_err.y"
                                          {
    yyerror("Expected '(' after 'write' keyword");
    yyerrok;
    FinalNode* Wr = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new StatementNode(Wr, dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 2515 "syntax.tab.cpp"
    break;

  case 91: /* StatementNode: WRITE LPAREN ExpressionListNode error  */
#line 480 "syntax_err.y"
                                          {
    yyerror("Expected ')' after 'write' keyword");
    yyerrok;
    FinalNode* Wr = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new StatementNode(Wr, dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 2526 "syntax.tab.cpp"
    break;

  case 92: /* StatementNode: WHILE ExpressionNode DO StatementNode  */
#line 485 "syntax_err.y"
                                         { // while语句拓展
    (yyval.ast) = new StatementNode(dynamic_cast<ExpressionNode*>((yyvsp[-2].ast)), dynamic_cast<StatementNode*>((yyvsp[0].ast)));
}
#line 2534 "syntax.tab.cpp"
    break;

  case 93: /* StatementNode: WHILE ExpressionNode error StatementNode  */
#line 487 "syntax_err.y"
                                             {
    yyerror("Expected 'do' after 'ExpressionNode'");
    yyerrok;
    (yyval.ast) = new StatementNode(dynamic_cast<ExpressionNode*>((yyvsp[-2].ast)), dynamic_cast<StatementNode*>((yyvsp[0].ast)));
}
#line 2544 "syntax.tab.cpp"
    break;

  case 94: /* StatementNode: BREAK  */
#line 491 "syntax_err.y"
         { // break拓展
    FinalNode* bk = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new StatementNode(bk);
}
#line 2553 "syntax.tab.cpp"
    break;

  case 95: /* VariableListNode: VariableNode  */
#line 496 "syntax_err.y"
                               {
    (yyval.ast) = new VariableListNode(dynamic_cast<VariableNode*>((yyvsp[0].ast)));
}
#line 2561 "syntax.tab.cpp"
    break;

  case 96: /* VariableListNode: VariableListNode COMMA VariableNode  */
#line 498 "syntax_err.y"
                                        {
    (yyval.ast) = new VariableListNode(dynamic_cast<VariableNode*>((yyvsp[0].ast)), dynamic_cast<VariableListNode*>((yyvsp[-2].ast)));
}
#line 2569 "syntax.tab.cpp"
    break;

  case 97: /* VariableNode: ID IdVarpartNode  */
#line 502 "syntax_err.y"
                               {
    FinalNode* id = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new VariableNode(id, dynamic_cast<IdVarpartNode*>((yyvsp[0].ast)));
}
#line 2578 "syntax.tab.cpp"
    break;

  case 98: /* IdVarpartNode: %empty  */
#line 507 "syntax_err.y"
               {
    (yyval.ast) = new IdVarpartNode();
}
#line 2586 "syntax.tab.cpp"
    break;

  case 99: /* IdVarpartNode: LBRA ExpressionListNode RBRA  */
#line 509 "syntax_err.y"
                                 {
    (yyval.ast) = new IdVarpartNode(dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 2594 "syntax.tab.cpp"
    break;

  case 100: /* IdVarpartNode: LBRA ExpressionListNode error  */
#line 511 "syntax_err.y"
                                  {
    yyerror("Expected ']' after '[' operator");
    yyerrok;
    (yyval.ast) = new IdVarpartNode(dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 2604 "syntax.tab.cpp"
    break;

  case 101: /* ProcedureCallNode: ID  */
#line 517 "syntax_err.y"
                      {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ProcedureCallNode(id);
}
#line 2613 "syntax.tab.cpp"
    break;

  case 102: /* ProcedureCallNode: ID LPAREN ExpressionListNode RPAREN  */
#line 520 "syntax_err.y"
                                        {
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new ProcedureCallNode(id, dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 2622 "syntax.tab.cpp"
    break;

  case 103: /* ProcedureCallNode: ID LPAREN ExpressionListNode error  */
#line 523 "syntax_err.y"
                                       {
    yyerror("Expected ')' after 'ExpressionListNode'");
    yyerrok;
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new ProcedureCallNode(id, dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 2633 "syntax.tab.cpp"
    break;

  case 104: /* ProcedureCallNode: ID LPAREN RPAREN  */
#line 528 "syntax_err.y"
                    {
    FinalNode* id = new FinalNode(*(yyvsp[-2].token));
    (yyval.ast) = new ProcedureCallNode(id); // 语法拓展：无参数过程调用支持 foo()
}
#line 2642 "syntax.tab.cpp"
    break;

  case 105: /* ProcedureCallNode: ID LPAREN error  */
#line 531 "syntax_err.y"
                    {
    yyerror("Expected ')' after '(' operator");
    yyerrok;
    FinalNode* id = new FinalNode(*(yyvsp[-2].token));
    (yyval.ast) = new ProcedureCallNode(id); // 语法拓展：无参数过程调用支持 foo()
}
#line 2653 "syntax.tab.cpp"
    break;

  case 106: /* ElsePartNode: %empty  */
#line 538 "syntax_err.y"
               {
    (yyval.ast) = new ElsePartNode();
}
#line 2661 "syntax.tab.cpp"
    break;

  case 107: /* ElsePartNode: ELSE StatementNode  */
#line 540 "syntax_err.y"
                       {
    (yyval.ast) = new ElsePartNode(dynamic_cast<StatementNode*>((yyvsp[0].ast)));
}
#line 2669 "syntax.tab.cpp"
    break;

  case 108: /* ExpressionListNode: ExpressionNode  */
#line 544 "syntax_err.y"
                                   {
    (yyval.ast) = new ExpressionListNode(dynamic_cast<ExpressionNode*>((yyvsp[0].ast)));
}
#line 2677 "syntax.tab.cpp"
    break;

  case 109: /* ExpressionListNode: ExpressionListNode COMMA ExpressionNode  */
#line 546 "syntax_err.y"
                                            {
    (yyval.ast) = new ExpressionListNode(dynamic_cast<ExpressionNode*>((yyvsp[0].ast)), dynamic_cast<ExpressionListNode*>((yyvsp[-2].ast)));
}
#line 2685 "syntax.tab.cpp"
    break;

  case 110: /* ExpressionNode: SimpleExpressionNode  */
#line 550 "syntax_err.y"
                                     {
    (yyval.ast) = new ExpressionNode(dynamic_cast<SimpleExpressionNode*>((yyvsp[0].ast)));
}
#line 2693 "syntax.tab.cpp"
    break;

  case 111: /* ExpressionNode: SimpleExpressionNode RELOP SimpleExpressionNode  */
#line 552 "syntax_err.y"
                                                    {
    FinalNode* id = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new ExpressionNode(dynamic_cast<SimpleExpressionNode*>((yyvsp[-2].ast)), id, dynamic_cast<SimpleExpressionNode*>((yyvsp[0].ast)));
}
#line 2702 "syntax.tab.cpp"
    break;

  case 112: /* SimpleExpressionNode: TermNode  */
#line 557 "syntax_err.y"
                               {
    (yyval.ast) = new SimpleExpressionNode(dynamic_cast<TermNode*>((yyvsp[0].ast)));
}
#line 2710 "syntax.tab.cpp"
    break;

  case 113: /* SimpleExpressionNode: SimpleExpressionNode ADDOP TermNode  */
#line 559 "syntax_err.y"
                                        {
    FinalNode* op = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new SimpleExpressionNode(dynamic_cast<TermNode*>((yyvsp[0].ast)), dynamic_cast<SimpleExpressionNode*>((yyvsp[-2].ast)), op);
}
#line 2719 "syntax.tab.cpp"
    break;

  case 114: /* TermNode: FactorNode  */
#line 564 "syntax_err.y"
                     {
    (yyval.ast) = new TermNode(dynamic_cast<FactorNode*>((yyvsp[0].ast)));
}
#line 2727 "syntax.tab.cpp"
    break;

  case 115: /* TermNode: TermNode MULOP FactorNode  */
#line 566 "syntax_err.y"
                              {
    FinalNode* op = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new TermNode(dynamic_cast<FactorNode*>((yyvsp[0].ast)), dynamic_cast<TermNode*>((yyvsp[-2].ast)), op);
}
#line 2736 "syntax.tab.cpp"
    break;

  case 116: /* FactorNode: NUM  */
#line 571 "syntax_err.y"
                {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new FactorNode(id);
}
#line 2745 "syntax.tab.cpp"
    break;

  case 117: /* FactorNode: VariableNode  */
#line 574 "syntax_err.y"
                 {
    (yyval.ast) = new FactorNode(dynamic_cast<VariableNode*>((yyvsp[0].ast)));
}
#line 2753 "syntax.tab.cpp"
    break;

  case 118: /* FactorNode: LPAREN ExpressionNode RPAREN  */
#line 576 "syntax_err.y"
                                 {
    (yyval.ast) = new FactorNode(dynamic_cast<ExpressionNode*>((yyvsp[-1].ast)));
}
#line 2761 "syntax.tab.cpp"
    break;

  case 119: /* FactorNode: LPAREN ExpressionNode error  */
#line 578 "syntax_err.y"
                                {
    yyerror("Expected ')' after '(' operator");
    yyerrok;
    (yyval.ast) = new FactorNode(dynamic_cast<ExpressionNode*>((yyvsp[-1].ast)));
}
#line 2771 "syntax.tab.cpp"
    break;

  case 120: /* FactorNode: ID LPAREN ExpressionListNode RPAREN  */
#line 582 "syntax_err.y"
                                        {
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new FactorNode(id, dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 2780 "syntax.tab.cpp"
    break;

  case 121: /* FactorNode: ID LPAREN ExpressionListNode error  */
#line 585 "syntax_err.y"
                                       {
    yyerror("Expected ')' after '(' operator");
    yyerrok;
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new FactorNode(id, dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 2791 "syntax.tab.cpp"
    break;

  case 122: /* FactorNode: NOTOP FactorNode  */
#line 590 "syntax_err.y"
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
#line 2806 "syntax.tab.cpp"
    break;

  case 123: /* FactorNode: ADDOP FactorNode  */
#line 599 "syntax_err.y"
                     {
    if((yyvsp[-1].token)->property == "-" || (yyvsp[-1].token)->property == "+"){
        FinalNode* op = new FinalNode(*(yyvsp[-1].token));
        (yyval.ast) = new FactorNode(op,dynamic_cast<FactorNode*>((yyvsp[0].ast)));
    }
    else {
        yyerror("Expected '-' or '+'");
        YYERROR;
    }
}
#line 2821 "syntax.tab.cpp"
    break;

  case 124: /* FactorNode: BOOL  */
#line 608 "syntax_err.y"
         {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new FactorNode(id);
}
#line 2830 "syntax.tab.cpp"
    break;

  case 125: /* FactorNode: ID LPAREN RPAREN  */
#line 611 "syntax_err.y"
                    {
    FinalNode* id = new FinalNode(*(yyvsp[-2].token));
    IdVarpartNode* fake_idvar = new IdVarpartNode();
    VariableNode* fake_var = new VariableNode(id, fake_idvar);
    (yyval.ast) = new FactorNode(fake_var); // 测试用例21: 无参数函数 a := foo(); write(foo())
}
#line 2841 "syntax.tab.cpp"
    break;

  case 126: /* FactorNode: ID LPAREN error  */
#line 616 "syntax_err.y"
                    {
    yyerror("Expected ')' after '(' operator");
    yyerrok;
    FinalNode* id = new FinalNode(*(yyvsp[-2].token));
    IdVarpartNode* fake_idvar = new IdVarpartNode();
    VariableNode* fake_var = new VariableNode(id, fake_idvar);
    (yyval.ast) = new FactorNode(fake_var); // 测试用例21: 无参数函数 a := foo(); write(foo())
}
#line 2854 "syntax.tab.cpp"
    break;


#line 2858 "syntax.tab.cpp"

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
  yytoken = yychar == Tk_YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= Tk_YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == Tk_YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = Tk_YYEMPTY;
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
  if (yychar != Tk_YYEMPTY)
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 628 "syntax_err.y"


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
