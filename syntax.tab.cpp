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
#line 1 "syntax1.y"

    #include "./header/syntax.hh"
    #include "./header/token.hh"
    #include "./header/AST.hh"
    #include "./AST.cc"
    #include <cstdio>
    #include <cstdlib>
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

#line 96 "syntax.tab.cpp"

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
#define YYLAST   251

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  240

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
       0,    50,    50,    52,    58,    63,    66,    69,    76,    83,
      86,    90,    96,   106,   108,   110,   117,   127,   137,   144,
     154,   157,   160,   166,   168,   170,   176,   179,   181,   185,
     189,   197,   200,   202,   205,   208,   211,   218,   232,   242,
     252,   262,   272,   278,   284,   290,   299,   301,   303,   309,
     317,   323,   327,   330,   333,   336,   339,   342,   348,   350,
     352,   356,   358,   360,   366,   368,   372,   374,   380,   382,
     388,   392,   394,   400,   402,   406,   408,   416,   425,   427,
     429,   431,   440,   443,   446,   448,   453,   455,   459,   464,
     466,   470,   473,   476,   481,   483,   487,   489,   493,   495,
     500,   502,   507,   509,   514,   517,   519,   521,   524,   533,
     542,   545
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

#define YYPACT_NINF (-136)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     106,  -136,   113,    31,    80,  -136,    36,  -136,    42,    85,
      99,   120,   105,   133,    78,   163,  -136,   105,  -136,  -136,
      11,   127,   143,   188,  -136,    19,    79,   125,   196,  -136,
     182,  -136,  -136,  -136,   203,  -136,   179,   180,   146,    24,
     105,   105,   207,   183,   186,    18,    83,    91,  -136,  -136,
    -136,  -136,  -136,   127,   127,   175,    13,  -136,  -136,  -136,
    -136,    26,    28,   178,   178,   178,   178,   178,   114,    69,
     210,   181,   184,    69,  -136,  -136,    16,  -136,   187,  -136,
    -136,  -136,    85,    85,  -136,  -136,   160,   160,   160,    24,
     146,    24,    82,   176,  -136,  -136,   185,    23,    69,   102,
      69,  -136,   154,  -136,  -136,    69,    69,    69,  -136,   198,
      58,   192,  -136,   190,   218,    69,   201,  -136,  -136,    18,
      69,   120,  -136,  -136,   193,   194,   195,   155,   158,    14,
    -136,  -136,  -136,   105,   105,  -136,    43,    67,  -136,  -136,
    -136,   215,   215,   215,   215,  -136,  -136,   -17,  -136,   161,
     117,  -136,  -136,   197,    18,    69,    69,    69,    69,   199,
     -16,  -136,   134,    18,  -136,  -136,   213,   225,   159,   224,
     220,   166,   222,   223,    15,  -136,  -136,    86,   215,   156,
     156,  -136,  -136,  -136,  -136,  -136,  -136,    69,  -136,  -136,
     139,  -136,   212,   192,   209,  -136,   219,  -136,   218,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,   215,   211,   214,   216,
     215,   215,   215,   215,  -136,  -136,  -136,  -136,  -136,  -136,
      18,  -136,    69,  -136,  -136,   234,   167,   235,  -136,  -136,
    -136,  -136,  -136,   227,  -136,  -136,  -136,  -136,    18,  -136
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
      26,     0,     0,    58,    58,    58,    58,    58,    91,     0,
       0,     0,     0,     0,    85,    79,     0,    73,     0,    78,
      48,    47,    13,    13,    18,    17,     0,     0,     0,     0,
       0,     0,     0,    53,    54,    51,     0,     0,     0,     0,
       0,    88,    89,   104,   110,     0,     0,     0,   105,     0,
      98,   100,   102,     0,     0,     0,     0,    72,    71,    75,
       0,    23,    50,    49,     0,     0,     0,     0,     0,     0,
      29,    30,    27,     0,     0,    60,     0,     0,    61,    64,
      65,     0,     0,     0,     0,    77,    93,     0,    96,     0,
       0,   108,   109,     0,    75,     0,     0,     0,     0,    89,
       0,    86,     0,    75,    74,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    67,    66,     0,     0,     0,
       0,    59,    55,    56,    57,    52,    92,     0,    90,   111,
       0,   106,    94,   101,    99,   103,     0,    82,     0,    83,
      84,    70,    42,    43,    38,    39,     0,     0,     0,     0,
       0,     0,     0,     0,    69,    68,    63,    62,    97,   107,
      75,    80,     0,    87,    33,     0,     0,     0,    34,    35,
      36,    32,    95,     0,    44,    45,    40,    41,    75,    81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,   231,    84,    52,  -136,   123,   122,  -136,
     -35,  -135,   116,  -136,  -136,  -136,   115,  -136,    22,  -136,
      72,   168,   -25,  -136,  -116,  -136,   -45,  -136,  -136,  -136,
     -87,   -68,    88,    94,   -95
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    10,   136,    11,    14,    35,    18,    26,
      58,    59,   127,    27,    46,    47,    93,   137,   138,   139,
     140,   122,    75,    76,    77,   160,   108,   101,    79,   221,
     147,   148,   110,   111,   112
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      78,   109,    48,   164,    60,   116,   182,   183,   184,   185,
     151,   152,    28,   149,    87,   173,   212,   117,   186,   197,
      38,    68,   187,   198,   143,    55,   213,    28,   162,    90,
     145,     7,   118,    45,    56,    69,    57,    70,   192,   153,
      71,    72,   214,   215,   177,    13,    29,   200,   119,    88,
      30,   174,   165,   171,   130,   131,   132,    39,    30,    73,
      74,   144,   195,   190,    89,    30,    91,    30,   179,   161,
      12,   224,   102,   103,    78,   228,   229,   230,   231,    22,
      40,   178,    30,   133,    80,    19,   155,   156,     8,    49,
     196,   134,    82,     8,   104,   105,    20,   106,    57,   180,
      16,    25,   181,   107,   232,   102,   103,     1,    19,    78,
      23,    41,     9,     2,     5,    81,     6,   135,    78,   218,
     102,   103,   239,    83,    61,    62,    42,   104,   105,    17,
     106,    31,    32,    33,   121,   121,   107,   146,    43,    44,
      45,   201,   104,   105,    98,   106,    36,    55,    99,    49,
     100,   107,   189,   223,   233,    34,    56,   133,    57,    19,
     203,   124,    21,   204,   125,   134,   126,   207,   235,   199,
     208,   236,   209,   187,   219,    78,    84,    85,   187,    94,
      95,    96,    97,    50,    64,    51,    65,    66,   150,    67,
     100,    37,   170,    78,   171,   172,    24,   171,   188,    49,
     187,   216,   217,   128,   129,   175,   176,    52,    53,    54,
      63,    86,    92,   113,   141,   114,   154,   120,   115,   157,
     158,   159,   163,   142,   167,   168,   169,    57,    45,   202,
     205,   206,   191,   210,   211,   100,   220,   155,   234,   222,
      15,   237,   225,   166,   194,   226,     0,   227,   238,   193,
       0,   123
};

static const yytype_int16 yycheck[] =
{
      45,    69,    27,   119,    39,    73,   141,   142,   143,   144,
     105,   106,     1,   100,     1,     1,     1,     1,    35,    35,
       1,     3,    39,    39,     1,     1,    11,     1,   115,     1,
      98,     0,    16,    15,    10,    17,    12,    19,   154,   107,
      22,    23,   177,   178,     1,     3,    35,   163,    32,    36,
      39,    37,   120,    39,    89,    90,    91,    38,    39,    41,
      42,    38,   157,   150,    38,    39,    38,    39,     1,   114,
      34,   206,     3,     4,   119,   210,   211,   212,   213,     1,
       1,    38,    39,     1,     1,     3,    28,    29,     8,     3,
     158,     9,     1,     8,    25,    26,    12,    28,    12,    32,
       1,    17,    35,    34,   220,     3,     4,     1,     3,   154,
      32,    32,    32,     7,     1,    32,     3,    35,   163,   187,
       3,     4,   238,    32,    40,    41,     1,    25,    26,     9,
      28,     4,     5,     6,    82,    83,    34,    35,    13,    14,
      15,   166,    25,    26,    30,    28,     3,     1,    34,     3,
      36,    34,    35,   198,   222,    28,    10,     1,    12,     3,
       1,     1,    29,     4,     4,     9,     6,     1,     1,    35,
       4,     4,     6,    39,    35,   220,    53,    54,    39,    64,
      65,    66,    67,     1,     1,     3,     3,     1,    34,     3,
      36,     3,    37,   238,    39,    37,    33,    39,    37,     3,
      39,   179,   180,    87,    88,   133,   134,     4,    29,    29,
       3,    36,    34,     3,    38,    34,    18,    30,    34,    27,
      30,     3,    21,    38,    31,    31,    31,    12,    15,     4,
       6,    11,    35,    11,    11,    36,    24,    28,     4,    20,
       9,     6,    31,   121,   156,    31,    -1,    31,    21,   155,
      -1,    83
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
      75,    76,    77,     3,    34,    34,    74,     1,    16,    32,
      30,    48,    64,    64,     1,     4,     6,    55,    55,    55,
      53,    53,    53,     1,     9,    35,    47,    60,    61,    62,
      63,    38,    38,     1,    38,    74,    35,    73,    74,    73,
      34,    77,    77,    74,    18,    28,    29,    27,    30,     3,
      68,    69,    73,    21,    67,    74,    51,    31,    31,    31,
      37,    39,    37,     1,    37,    63,    63,     1,    38,     1,
      32,    35,    54,    54,    54,    54,    35,    39,    37,    35,
      73,    35,    67,    76,    75,    77,    74,    35,    39,    35,
      67,    65,     4,     1,     4,     6,    11,     1,     4,     6,
      11,    11,     1,    11,    54,    54,    61,    61,    74,    35,
      24,    72,    20,    69,    54,    31,    31,    31,    54,    54,
      54,    54,    67,    74,     4,     1,     4,     6,    21,    67
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
      67,    67,    67,    67,    67,    67,    68,    68,    69,    70,
      70,    71,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    77,    77,    77,    77,
      77,    77
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
       5,     8,     4,     4,     4,     1,     1,     3,     2,     0,
       3,     1,     4,     3,     0,     2,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     3,     4,     2,     2,
       1,     3
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
  case 2: /* ProgramStructNode: ProgramHeadNode SEMI ProgramBodyNode DOT  */
#line 50 "syntax1.y"
                                                            {
    syntax->tree = new ProgramStructNode(dynamic_cast<ProgramHeadNode*>((yyvsp[-3].ast)), dynamic_cast<ProgramBodyNode*>((yyvsp[-1].ast)));
}
#line 1594 "syntax.tab.cpp"
    break;

  case 3: /* ProgramStructNode: error  */
#line 52 "syntax1.y"
          {
    yyerror("Unrecoverable errors occurred");
    while(yychar != YYEOF) {
        yychar = yylex();
    }
    (yyval.ast) = nullptr; 
}
#line 1606 "syntax.tab.cpp"
    break;

  case 4: /* ProgramStructNode: ProgramHeadNode ProgramBodyNode error  */
#line 58 "syntax1.y"
                                          {
    syntax->tree = new ProgramStructNode(dynamic_cast<ProgramHeadNode*>((yyvsp[-2].ast)), dynamic_cast<ProgramBodyNode*>((yyvsp[-1].ast)));
    yyerror("Expected '.' at the end of the program");
}
#line 1615 "syntax.tab.cpp"
    break;

  case 5: /* ProgramHeadNode: PROGRAM ID  */
#line 63 "syntax1.y"
                            {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ProgramHeadNode(id);
}
#line 1624 "syntax.tab.cpp"
    break;

  case 6: /* ProgramHeadNode: PROGRAM ID LPAREN IdListNode RPAREN  */
#line 66 "syntax1.y"
                                        {
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new ProgramHeadNode(id, dynamic_cast<IdListNode*>((yyvsp[-1].ast)));
}
#line 1633 "syntax.tab.cpp"
    break;

  case 7: /* ProgramHeadNode: PROGRAM error  */
#line 69 "syntax1.y"
                  {
    yyerror("Expected program name after 'program' keyword");
    FinalNode* id = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new ProgramHeadNode(id);
    yyerrok;
}
#line 1644 "syntax.tab.cpp"
    break;

  case 8: /* ProgramBodyNode: ConstDeclarationsNode VarDeclarationsNode SubprogramDeclarationsNode CompoundStatementNode  */
#line 76 "syntax1.y"
                                                                                                            {
    (yyval.ast) = new ProgramBodyNode(dynamic_cast<ConstDeclarationsNode*>((yyvsp[-3].ast)),
    dynamic_cast<VarDeclarationsNode*>((yyvsp[-2].ast)),
    dynamic_cast<SubprogramDeclarationsNode*>((yyvsp[-1].ast)),
    dynamic_cast<CompoundStatementNode*>((yyvsp[0].ast)));
}
#line 1655 "syntax.tab.cpp"
    break;

  case 9: /* IdListNode: ID  */
#line 83 "syntax1.y"
               {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new IdListNode(id);
}
#line 1664 "syntax.tab.cpp"
    break;

  case 10: /* IdListNode: IdListNode COMMA ID  */
#line 86 "syntax1.y"
                        {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    IdListNode* idList = dynamic_cast<IdListNode*>((yyvsp[-2].ast));
    (yyval.ast) = new IdListNode(id, idList);
}
#line 1674 "syntax.tab.cpp"
    break;

  case 11: /* IdListNode: IdListNode error ID  */
#line 90 "syntax1.y"
                        {
    yyerror_at("Expected ',' after IdListNode", (yyvsp[0].token)->line, (yyvsp[0].token)->column, (yyvsp[0].token));
    yyerrok;
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    IdListNode* idList = dynamic_cast<IdListNode*>((yyvsp[-2].ast));
    (yyval.ast) = new IdListNode(id, idList);
}
#line 1686 "syntax.tab.cpp"
    break;

  case 12: /* IdListNode: IdListNode COMMA error  */
#line 96 "syntax1.y"
                           {
    yyerror("Expected ID after ','");
    yyerrok;
    FinalNode* id = new FinalNode(*(yyvsp[-1].token));
    IdListNode* idList = dynamic_cast<IdListNode*>((yyvsp[-2].ast));
    (yyval.ast) = new IdListNode(id, idList);
}
#line 1698 "syntax.tab.cpp"
    break;

  case 13: /* ConstDeclarationsNode: %empty  */
#line 106 "syntax1.y"
    {
        (yyval.ast) = new ConstDeclarationsNode();
    }
#line 1706 "syntax.tab.cpp"
    break;

  case 14: /* ConstDeclarationsNode: CONST ConstDeclarationNode SEMI  */
#line 108 "syntax1.y"
                                        {
        (yyval.ast) = new ConstDeclarationsNode(dynamic_cast<ConstDeclarationNode*>((yyvsp[-1].ast)));
    }
#line 1714 "syntax.tab.cpp"
    break;

  case 15: /* ConstDeclarationsNode: CONST ConstDeclarationNode error  */
#line 110 "syntax1.y"
                                        {
        yyerror("Except ';' after ConstDeclarationsNode");
        yyerrok;
        (yyval.ast) = new ConstDeclarationsNode(); 
    }
#line 1724 "syntax.tab.cpp"
    break;

  case 16: /* ConstDeclarationNode: ID RELOP ConstValueNode  */
#line 117 "syntax1.y"
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
#line 1740 "syntax.tab.cpp"
    break;

  case 17: /* ConstDeclarationNode: ConstDeclarationNode SEMI ID RELOP ConstValueNode  */
#line 127 "syntax1.y"
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
#line 1756 "syntax.tab.cpp"
    break;

  case 18: /* ConstDeclarationNode: ConstDeclarationNode error ID RELOP ConstValueNode  */
#line 137 "syntax1.y"
                                                       {
    yyerror_at("Expected ';' after ConstDeclarationNode", (yyvsp[-2].token)->line, (yyvsp[-2].token)->column, (yyvsp[-2].token));
    yyerrok;
    FinalNode* id = new FinalNode(*(yyvsp[-2].token));
    (yyval.ast) = new ConstDeclarationNode(id, dynamic_cast<ConstValueNode*>((yyvsp[0].ast)), dynamic_cast<ConstDeclarationNode*>((yyvsp[-4].ast)));
}
#line 1767 "syntax.tab.cpp"
    break;

  case 19: /* ConstValueNode: ADDOP NUM  */
#line 144 "syntax1.y"
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
#line 1783 "syntax.tab.cpp"
    break;

  case 20: /* ConstValueNode: NUM  */
#line 154 "syntax1.y"
        {
    FinalNode* num = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ConstValueNode(num);
}
#line 1792 "syntax.tab.cpp"
    break;

  case 21: /* ConstValueNode: CHAR_V  */
#line 157 "syntax1.y"
           {
    FinalNode* num = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ConstValueNode(num);
}
#line 1801 "syntax.tab.cpp"
    break;

  case 22: /* ConstValueNode: STR_V  */
#line 160 "syntax1.y"
          {
    FinalNode* num = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ConstValueNode(num);
}
#line 1810 "syntax.tab.cpp"
    break;

  case 23: /* VarDeclarationsNode: %empty  */
#line 166 "syntax1.y"
                     {
    (yyval.ast) = new VarDeclarationsNode();
}
#line 1818 "syntax.tab.cpp"
    break;

  case 24: /* VarDeclarationsNode: VAR VarDeclarationNode SEMI  */
#line 168 "syntax1.y"
                                {
    (yyval.ast) = new VarDeclarationsNode(dynamic_cast<VarDeclarationNode*>((yyvsp[-1].ast)));
}
#line 1826 "syntax.tab.cpp"
    break;

  case 25: /* VarDeclarationsNode: VAR VarDeclarationNode error  */
#line 170 "syntax1.y"
                                 {
    yyerror("Expected ';' after VarDeclarationsNode");
    yyerrok;
    (yyval.ast) = new VarDeclarationsNode();
}
#line 1836 "syntax.tab.cpp"
    break;

  case 26: /* VarDeclarationNode: IdListNode COLON TypeNode  */
#line 176 "syntax1.y"
                                              {
    (yyval.ast) = new VarDeclarationNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<TypeNode*>((yyvsp[0].ast)));

}
#line 1845 "syntax.tab.cpp"
    break;

  case 27: /* VarDeclarationNode: VarDeclarationNode SEMI IdListNode COLON TypeNode  */
#line 179 "syntax1.y"
                                                      {
    (yyval.ast) = new VarDeclarationNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<TypeNode*>((yyvsp[0].ast)), dynamic_cast<VarDeclarationNode*>((yyvsp[-4].ast)));
}
#line 1853 "syntax.tab.cpp"
    break;

  case 28: /* VarDeclarationNode: IdListNode error TypeNode  */
#line 181 "syntax1.y"
                              {
    yyerror("Expected ':' after IdListNode");
    yyerrok;
    (yyval.ast) = new VarDeclarationNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<TypeNode*>((yyvsp[0].ast)));
}
#line 1863 "syntax.tab.cpp"
    break;

  case 29: /* VarDeclarationNode: VarDeclarationNode error IdListNode COLON TypeNode  */
#line 185 "syntax1.y"
                                                       {
    yyerror("Expected ';' after VarDeclarationNode");
    yyerrok;
    (yyval.ast) = new VarDeclarationNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<TypeNode*>((yyvsp[0].ast)), dynamic_cast<VarDeclarationNode*>((yyvsp[-4].ast)));
}
#line 1873 "syntax.tab.cpp"
    break;

  case 30: /* VarDeclarationNode: VarDeclarationNode SEMI IdListNode error TypeNode  */
#line 189 "syntax1.y"
                                                      {
    yyerror("Expected ':' after IdListNode");
    yyerrok;
    (yyval.ast) = new VarDeclarationNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<TypeNode*>((yyvsp[0].ast)), dynamic_cast<VarDeclarationNode*>((yyvsp[-4].ast)));
}
#line 1883 "syntax.tab.cpp"
    break;

  case 31: /* TypeNode: BasicTypeNode  */
#line 197 "syntax1.y"
                  {
        (yyval.ast) = new TypeNode(dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)));
    }
#line 1891 "syntax.tab.cpp"
    break;

  case 32: /* TypeNode: ARRAY LBRA PeriodNode RBRA OF BasicTypeNode  */
#line 200 "syntax1.y"
                                                  {
        (yyval.ast) = new TypeNode(dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)), dynamic_cast<PeriodNode*>((yyvsp[-3].ast)));
    }
#line 1899 "syntax.tab.cpp"
    break;

  case 33: /* TypeNode: error LBRA PeriodNode RBRA OF BasicTypeNode  */
#line 202 "syntax1.y"
                                                    {
        yyerror_at("Expected 'array' keyword", (yyvsp[-4].token)->line, (yyvsp[-4].token)->column, (yyvsp[-4].token));
        yyerrok;
    }
#line 1908 "syntax.tab.cpp"
    break;

  case 34: /* TypeNode: ARRAY error PeriodNode RBRA OF BasicTypeNode  */
#line 205 "syntax1.y"
                                                     {
        yyerror_at("Expected '['", (yyvsp[-2].token)->line, (yyvsp[-2].token)->column, (yyvsp[-2].token));
        yyerrok;
    }
#line 1917 "syntax.tab.cpp"
    break;

  case 35: /* TypeNode: ARRAY LBRA PeriodNode error OF BasicTypeNode  */
#line 208 "syntax1.y"
                                                     {
        yyerror_at("Expected ']'", (yyvsp[-1].token)->line, (yyvsp[-1].token)->column, (yyvsp[-1].token));
        yyerrok;
    }
#line 1926 "syntax.tab.cpp"
    break;

  case 36: /* TypeNode: ARRAY LBRA PeriodNode RBRA error BasicTypeNode  */
#line 211 "syntax1.y"
                                                       {
        yyerror("Expected 'of'");
        yyerrok;
    }
#line 1935 "syntax.tab.cpp"
    break;

  case 37: /* BasicTypeNode: TYPE  */
#line 218 "syntax1.y"
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
#line 1953 "syntax.tab.cpp"
    break;

  case 38: /* PeriodNode: NUM DOTDOT NUM  */
#line 232 "syntax1.y"
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
#line 1969 "syntax.tab.cpp"
    break;

  case 39: /* PeriodNode: CHAR_V DOTDOT CHAR_V  */
#line 242 "syntax1.y"
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
#line 1985 "syntax.tab.cpp"
    break;

  case 40: /* PeriodNode: PeriodNode COMMA NUM DOTDOT NUM  */
#line 252 "syntax1.y"
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
#line 2001 "syntax.tab.cpp"
    break;

  case 41: /* PeriodNode: PeriodNode COMMA CHAR_V DOTDOT CHAR_V  */
#line 262 "syntax1.y"
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
#line 2017 "syntax.tab.cpp"
    break;

  case 42: /* PeriodNode: error DOTDOT NUM  */
#line 272 "syntax1.y"
                     {
    yyerror_at("Expected 'num' before '..' operator", (yyvsp[-1].token)->line, (yyvsp[-1].token)->column, (yyvsp[-1].token));
    yyerrok;
    FinalNode* id1 = new FinalNode(*(yyvsp[0].token));
    FinalNode* id2 = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new PeriodNode(id1, id2);
}
#line 2029 "syntax.tab.cpp"
    break;

  case 43: /* PeriodNode: NUM DOTDOT error  */
#line 278 "syntax1.y"
                     {
    yyerror("Expected 'num' after '..' operator");
    yyerrok;
    FinalNode* id1 = new FinalNode(*(yyvsp[-2].token));
    FinalNode* id2 = new FinalNode(*(yyvsp[-2].token));
    (yyval.ast) = new PeriodNode(id1, id2);
}
#line 2041 "syntax.tab.cpp"
    break;

  case 44: /* PeriodNode: PeriodNode COMMA error DOTDOT NUM  */
#line 284 "syntax1.y"
                                      {
    yyerror_at("Expected 'num' after ',' operator", (yyvsp[-1].token)->line, (yyvsp[-1].token)->column, (yyvsp[-1].token));
    yyerrok;
    FinalNode* id1 = new FinalNode(*(yyvsp[0].token));
    FinalNode* id2 = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new PeriodNode(id1, id2, dynamic_cast<PeriodNode*>((yyvsp[-4].ast))); 
}
#line 2053 "syntax.tab.cpp"
    break;

  case 45: /* PeriodNode: PeriodNode COMMA NUM DOTDOT error  */
#line 290 "syntax1.y"
                                      {
    yyerror("Expected 'num' after '..' operator");
    yyerrok;
    FinalNode* id1 = new FinalNode(*(yyvsp[-2].token));
    FinalNode* id2 = new FinalNode(*(yyvsp[-2].token));
    (yyval.ast) = new PeriodNode(id1, id2, dynamic_cast<PeriodNode*>((yyvsp[-4].ast))); 
}
#line 2065 "syntax.tab.cpp"
    break;

  case 46: /* SubprogramDeclarationsNode: %empty  */
#line 299 "syntax1.y"
                            {
    (yyval.ast) = new SubprogramDeclarationsNode();
}
#line 2073 "syntax.tab.cpp"
    break;

  case 47: /* SubprogramDeclarationsNode: SubprogramDeclarationsNode SubprogramNode SEMI  */
#line 301 "syntax1.y"
                                                   {
    (yyval.ast) = new SubprogramDeclarationsNode(dynamic_cast<SubprogramDeclarationsNode*>((yyvsp[-2].ast)), dynamic_cast<SubprogramNode*>((yyvsp[-1].ast)));
}
#line 2081 "syntax.tab.cpp"
    break;

  case 48: /* SubprogramDeclarationsNode: SubprogramDeclarationsNode SubprogramNode error  */
#line 303 "syntax1.y"
                                                    {
    yyerror("Expected ';' after SubprogramDeclarationsNode");
    yyerrok;
    (yyval.ast) = new SubprogramDeclarationsNode(dynamic_cast<SubprogramDeclarationsNode*>((yyvsp[-2].ast)), dynamic_cast<SubprogramNode*>((yyvsp[-1].ast)));
}
#line 2091 "syntax.tab.cpp"
    break;

  case 49: /* SubprogramNode: SubprogramHeadNode SEMI SubprogramBodyNode  */
#line 309 "syntax1.y"
                                                           {
    if((yyvsp[-1].token)->property == ";") {
        (yyval.ast) = new SubprogramNode(dynamic_cast<SubprogramHeadNode*>((yyvsp[-2].ast)), dynamic_cast<SubprogramBodyNode*>((yyvsp[0].ast)));
    }
    else {
        yyerror("Expected ';'");
        YYERROR;
    }
}
#line 2105 "syntax.tab.cpp"
    break;

  case 50: /* SubprogramNode: SubprogramHeadNode error SubprogramBodyNode  */
#line 317 "syntax1.y"
                                                {
    yyerror("Expected ';' after SubprogramHeadNode");
    yyerrok;
    (yyval.ast) = new SubprogramNode(dynamic_cast<SubprogramHeadNode*>((yyvsp[-2].ast)), dynamic_cast<SubprogramBodyNode*>((yyvsp[0].ast)));
}
#line 2115 "syntax.tab.cpp"
    break;

  case 51: /* SubprogramHeadNode: PROCEDURE ID FormalParameterNode  */
#line 323 "syntax1.y"
                                                     {
    FinalNode* id = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new SubprogramHeadNode(id, dynamic_cast<FormalParameterNode*>((yyvsp[0].ast)));

}
#line 2125 "syntax.tab.cpp"
    break;

  case 52: /* SubprogramHeadNode: FUNCTION ID FormalParameterNode COLON BasicTypeNode  */
#line 327 "syntax1.y"
                                                        {
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new SubprogramHeadNode(id, dynamic_cast<FormalParameterNode*>((yyvsp[-2].ast)), dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)));
}
#line 2134 "syntax.tab.cpp"
    break;

  case 53: /* SubprogramHeadNode: error ID FormalParameterNode  */
#line 330 "syntax1.y"
                                 {
    yyerror_at("Expected 'procedure' before ID", (yyvsp[-1].token)->line, (yyvsp[-1].token)->column, (yyvsp[-1].token));
    yyerrok;
}
#line 2143 "syntax.tab.cpp"
    break;

  case 54: /* SubprogramHeadNode: PROCEDURE error FormalParameterNode  */
#line 333 "syntax1.y"
                                        {
    yyerror("Expected 'ID' after 'procedure' keyword");
    yyerrok;
}
#line 2152 "syntax.tab.cpp"
    break;

  case 55: /* SubprogramHeadNode: error ID FormalParameterNode COLON BasicTypeNode  */
#line 336 "syntax1.y"
                                                     {
    yyerror_at("Expected 'procedure' before ID", (yyvsp[-3].token)->line, (yyvsp[-3].token)->column, (yyvsp[-3].token));
    yyerrok;
}
#line 2161 "syntax.tab.cpp"
    break;

  case 56: /* SubprogramHeadNode: FUNCTION error FormalParameterNode COLON BasicTypeNode  */
#line 339 "syntax1.y"
                                                           {
    yyerror("Expected 'ID' after 'function' keyword");
    yyerrok;
}
#line 2170 "syntax.tab.cpp"
    break;

  case 57: /* SubprogramHeadNode: FUNCTION ID FormalParameterNode error BasicTypeNode  */
#line 342 "syntax1.y"
                                                        {
    yyerror("Expected ':' after 'function' keyword");
    yyerrok;
}
#line 2179 "syntax.tab.cpp"
    break;

  case 58: /* FormalParameterNode: %empty  */
#line 348 "syntax1.y"
                     {
    (yyval.ast) = new FormalParameterNode();
}
#line 2187 "syntax.tab.cpp"
    break;

  case 59: /* FormalParameterNode: LPAREN ParameterListNode RPAREN  */
#line 350 "syntax1.y"
                                    {
    (yyval.ast) = new FormalParameterNode(dynamic_cast<ParameterListNode*>((yyvsp[-1].ast)));
}
#line 2195 "syntax.tab.cpp"
    break;

  case 60: /* FormalParameterNode: LPAREN RPAREN  */
#line 352 "syntax1.y"
                  {
    (yyval.ast) = new FormalParameterNode();
}
#line 2203 "syntax.tab.cpp"
    break;

  case 61: /* ParameterListNode: ParameterNode  */
#line 356 "syntax1.y"
                                 {
    (yyval.ast) = new ParameterListNode(dynamic_cast<ParameterNode*>((yyvsp[0].ast)));
}
#line 2211 "syntax.tab.cpp"
    break;

  case 62: /* ParameterListNode: ParameterListNode SEMI ParameterNode  */
#line 358 "syntax1.y"
                                         {
    (yyval.ast) = new ParameterListNode(dynamic_cast<ParameterNode*>((yyvsp[0].ast)), dynamic_cast<ParameterListNode*>((yyvsp[-2].ast)));
}
#line 2219 "syntax.tab.cpp"
    break;

  case 63: /* ParameterListNode: ParameterListNode error ParameterNode  */
#line 360 "syntax1.y"
                                          {
    yyerror("Expected ';' after ParameterListNode");
    yyerrok;
    (yyval.ast) = new ParameterListNode(dynamic_cast<ParameterNode*>((yyvsp[0].ast)), dynamic_cast<ParameterListNode*>((yyvsp[-2].ast)));
}
#line 2229 "syntax.tab.cpp"
    break;

  case 64: /* ParameterNode: VarParameterNode  */
#line 366 "syntax1.y"
                                {
    (yyval.ast) = new ParameterNode(dynamic_cast<VarParameterNode*>((yyvsp[0].ast)));
}
#line 2237 "syntax.tab.cpp"
    break;

  case 65: /* ParameterNode: ValueParameterNode  */
#line 368 "syntax1.y"
                       {
    (yyval.ast) = new ParameterNode(dynamic_cast<ValueParameterNode*>((yyvsp[0].ast)));
}
#line 2245 "syntax.tab.cpp"
    break;

  case 66: /* VarParameterNode: VAR ValueParameterNode  */
#line 372 "syntax1.y"
                                         {
    (yyval.ast) = new VarParameterNode(dynamic_cast<ValueParameterNode*>((yyvsp[0].ast)));
}
#line 2253 "syntax.tab.cpp"
    break;

  case 67: /* VarParameterNode: error ValueParameterNode  */
#line 374 "syntax1.y"
                             {
    yyerror("Expected 'var' before ValueParameterNode");
    yyerrok;
    (yyval.ast) = new VarParameterNode(dynamic_cast<ValueParameterNode*>((yyvsp[0].ast)));
}
#line 2263 "syntax.tab.cpp"
    break;

  case 68: /* ValueParameterNode: IdListNode COLON BasicTypeNode  */
#line 380 "syntax1.y"
                                                   {
    (yyval.ast) = new ValueParameterNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)));
}
#line 2271 "syntax.tab.cpp"
    break;

  case 69: /* ValueParameterNode: IdListNode error BasicTypeNode  */
#line 382 "syntax1.y"
                                   {
    yyerror("Expected ':' after IdListNode");
    yyerrok;
    (yyval.ast) = new ValueParameterNode(dynamic_cast<IdListNode*>((yyvsp[-2].ast)), dynamic_cast<BasicTypeNode*>((yyvsp[0].ast)));
}
#line 2281 "syntax.tab.cpp"
    break;

  case 70: /* SubprogramBodyNode: ConstDeclarationsNode VarDeclarationsNode CompoundStatementNode  */
#line 388 "syntax1.y"
                                                                                    {
    (yyval.ast) = new SubprogramBodyNode(dynamic_cast<ConstDeclarationsNode*>((yyvsp[-2].ast)), dynamic_cast<VarDeclarationsNode*>((yyvsp[-1].ast)), dynamic_cast<CompoundStatementNode*>((yyvsp[0].ast)));
}
#line 2289 "syntax.tab.cpp"
    break;

  case 71: /* CompoundStatementNode: BEGIN StatementListNode END  */
#line 392 "syntax1.y"
                                                   {
    (yyval.ast) = new CompoundStatementNode(dynamic_cast<StatementListNode*>((yyvsp[-1].ast)));
}
#line 2297 "syntax.tab.cpp"
    break;

  case 72: /* CompoundStatementNode: BEGIN StatementListNode error  */
#line 394 "syntax1.y"
                                  {
    yyerror("Expected 'end' after statement list");
    yyerrok;
    (yyval.ast) = new CompoundStatementNode(dynamic_cast<StatementListNode*>((yyvsp[-1].ast)));
}
#line 2307 "syntax.tab.cpp"
    break;

  case 73: /* StatementListNode: StatementNode  */
#line 400 "syntax1.y"
                                 {
    (yyval.ast) = new StatementListNode(dynamic_cast<StatementNode*>((yyvsp[0].ast)));
}
#line 2315 "syntax.tab.cpp"
    break;

  case 74: /* StatementListNode: StatementListNode SEMI StatementNode  */
#line 402 "syntax1.y"
                                         {
    (yyval.ast) = new StatementListNode(dynamic_cast<StatementNode*>((yyvsp[0].ast)), dynamic_cast<StatementListNode*>((yyvsp[-2].ast)));
}
#line 2323 "syntax.tab.cpp"
    break;

  case 75: /* StatementNode: %empty  */
#line 406 "syntax1.y"
               {
    (yyval.ast) = new StatementNode();
}
#line 2331 "syntax.tab.cpp"
    break;

  case 76: /* StatementNode: VariableNode ASSIGNOP ExpressionNode  */
#line 408 "syntax1.y"
                                         {
    if((yyvsp[-1].token)->property == ":="){
        (yyval.ast) = new StatementNode(dynamic_cast<VariableNode*>((yyvsp[-2].ast)), dynamic_cast<ExpressionNode*>((yyvsp[0].ast)));
    }
    else {
        yyerror("Expected ':=' operator");
        YYERROR;
    }
}
#line 2345 "syntax.tab.cpp"
    break;

  case 77: /* StatementNode: ID ASSIGNOP ExpressionNode  */
#line 416 "syntax1.y"
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
#line 2360 "syntax.tab.cpp"
    break;

  case 78: /* StatementNode: ProcedureCallNode  */
#line 425 "syntax1.y"
                      {
    (yyval.ast) = new StatementNode(dynamic_cast<ProcedureCallNode*>((yyvsp[0].ast)));
}
#line 2368 "syntax.tab.cpp"
    break;

  case 79: /* StatementNode: CompoundStatementNode  */
#line 427 "syntax1.y"
                          {
    (yyval.ast) = new StatementNode(dynamic_cast<CompoundStatementNode*>((yyvsp[0].ast)));
}
#line 2376 "syntax.tab.cpp"
    break;

  case 80: /* StatementNode: IF ExpressionNode THEN StatementNode ElsePartNode  */
#line 429 "syntax1.y"
                                                      {
    (yyval.ast) = new StatementNode(dynamic_cast<ExpressionNode*>((yyvsp[-3].ast)), dynamic_cast<StatementNode*>((yyvsp[-1].ast)), dynamic_cast<ElsePartNode*>((yyvsp[0].ast)));
}
#line 2384 "syntax.tab.cpp"
    break;

  case 81: /* StatementNode: FOR ID ASSIGNOP ExpressionNode TO ExpressionNode DO StatementNode  */
#line 431 "syntax1.y"
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
#line 2399 "syntax.tab.cpp"
    break;

  case 82: /* StatementNode: READ LPAREN VariableListNode RPAREN  */
#line 440 "syntax1.y"
                                        {
    FinalNode* Re = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new StatementNode(Re, dynamic_cast<VariableListNode*>((yyvsp[-1].ast)));
}
#line 2408 "syntax.tab.cpp"
    break;

  case 83: /* StatementNode: WRITE LPAREN ExpressionListNode RPAREN  */
#line 443 "syntax1.y"
                                           {
    FinalNode* Wr = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new StatementNode(Wr, dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 2417 "syntax.tab.cpp"
    break;

  case 84: /* StatementNode: WHILE ExpressionNode DO StatementNode  */
#line 446 "syntax1.y"
                                         { // while语句拓展
    (yyval.ast) = new StatementNode(dynamic_cast<ExpressionNode*>((yyvsp[-2].ast)), dynamic_cast<StatementNode*>((yyvsp[0].ast)));
}
#line 2425 "syntax.tab.cpp"
    break;

  case 85: /* StatementNode: BREAK  */
#line 448 "syntax1.y"
         { // break拓展
    FinalNode* bk = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new StatementNode(bk);
}
#line 2434 "syntax.tab.cpp"
    break;

  case 86: /* VariableListNode: VariableNode  */
#line 453 "syntax1.y"
                               {
    (yyval.ast) = new VariableListNode(dynamic_cast<VariableNode*>((yyvsp[0].ast)));
}
#line 2442 "syntax.tab.cpp"
    break;

  case 87: /* VariableListNode: VariableListNode COMMA VariableNode  */
#line 455 "syntax1.y"
                                        {
    (yyval.ast) = new VariableListNode(dynamic_cast<VariableNode*>((yyvsp[0].ast)), dynamic_cast<VariableListNode*>((yyvsp[-2].ast)));
}
#line 2450 "syntax.tab.cpp"
    break;

  case 88: /* VariableNode: ID IdVarpartNode  */
#line 459 "syntax1.y"
                               {
    FinalNode* id = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new VariableNode(id, dynamic_cast<IdVarpartNode*>((yyvsp[0].ast)));
}
#line 2459 "syntax.tab.cpp"
    break;

  case 89: /* IdVarpartNode: %empty  */
#line 464 "syntax1.y"
               {
    (yyval.ast) = new IdVarpartNode();
}
#line 2467 "syntax.tab.cpp"
    break;

  case 90: /* IdVarpartNode: LBRA ExpressionListNode RBRA  */
#line 466 "syntax1.y"
                                 {
    (yyval.ast) = new IdVarpartNode(dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 2475 "syntax.tab.cpp"
    break;

  case 91: /* ProcedureCallNode: ID  */
#line 470 "syntax1.y"
                      {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new ProcedureCallNode(id);
}
#line 2484 "syntax.tab.cpp"
    break;

  case 92: /* ProcedureCallNode: ID LPAREN ExpressionListNode RPAREN  */
#line 473 "syntax1.y"
                                        {
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new ProcedureCallNode(id, dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 2493 "syntax.tab.cpp"
    break;

  case 93: /* ProcedureCallNode: ID LPAREN RPAREN  */
#line 476 "syntax1.y"
                    {
    FinalNode* id = new FinalNode(*(yyvsp[-2].token));
    (yyval.ast) = new ProcedureCallNode(id); // 语法拓展：无参数过程调用支持 foo()
}
#line 2502 "syntax.tab.cpp"
    break;

  case 94: /* ElsePartNode: %empty  */
#line 481 "syntax1.y"
               {
    (yyval.ast) = new ElsePartNode();
}
#line 2510 "syntax.tab.cpp"
    break;

  case 95: /* ElsePartNode: ELSE StatementNode  */
#line 483 "syntax1.y"
                       {
    (yyval.ast) = new ElsePartNode(dynamic_cast<StatementNode*>((yyvsp[0].ast)));
}
#line 2518 "syntax.tab.cpp"
    break;

  case 96: /* ExpressionListNode: ExpressionNode  */
#line 487 "syntax1.y"
                                   {
    (yyval.ast) = new ExpressionListNode(dynamic_cast<ExpressionNode*>((yyvsp[0].ast)));
}
#line 2526 "syntax.tab.cpp"
    break;

  case 97: /* ExpressionListNode: ExpressionListNode COMMA ExpressionNode  */
#line 489 "syntax1.y"
                                            {
    (yyval.ast) = new ExpressionListNode(dynamic_cast<ExpressionNode*>((yyvsp[0].ast)), dynamic_cast<ExpressionListNode*>((yyvsp[-2].ast)));
}
#line 2534 "syntax.tab.cpp"
    break;

  case 98: /* ExpressionNode: SimpleExpressionNode  */
#line 493 "syntax1.y"
                                     {
    (yyval.ast) = new ExpressionNode(dynamic_cast<SimpleExpressionNode*>((yyvsp[0].ast)));
}
#line 2542 "syntax.tab.cpp"
    break;

  case 99: /* ExpressionNode: SimpleExpressionNode RELOP SimpleExpressionNode  */
#line 495 "syntax1.y"
                                                    {
    FinalNode* id = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new ExpressionNode(dynamic_cast<SimpleExpressionNode*>((yyvsp[-2].ast)), id, dynamic_cast<SimpleExpressionNode*>((yyvsp[0].ast)));
}
#line 2551 "syntax.tab.cpp"
    break;

  case 100: /* SimpleExpressionNode: TermNode  */
#line 500 "syntax1.y"
                               {
    (yyval.ast) = new SimpleExpressionNode(dynamic_cast<TermNode*>((yyvsp[0].ast)));
}
#line 2559 "syntax.tab.cpp"
    break;

  case 101: /* SimpleExpressionNode: SimpleExpressionNode ADDOP TermNode  */
#line 502 "syntax1.y"
                                        {
    FinalNode* op = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new SimpleExpressionNode(dynamic_cast<TermNode*>((yyvsp[0].ast)), dynamic_cast<SimpleExpressionNode*>((yyvsp[-2].ast)), op);
}
#line 2568 "syntax.tab.cpp"
    break;

  case 102: /* TermNode: FactorNode  */
#line 507 "syntax1.y"
                     {
    (yyval.ast) = new TermNode(dynamic_cast<FactorNode*>((yyvsp[0].ast)));
}
#line 2576 "syntax.tab.cpp"
    break;

  case 103: /* TermNode: TermNode MULOP FactorNode  */
#line 509 "syntax1.y"
                              {
    FinalNode* op = new FinalNode(*(yyvsp[-1].token));
    (yyval.ast) = new TermNode(dynamic_cast<FactorNode*>((yyvsp[0].ast)), dynamic_cast<TermNode*>((yyvsp[-2].ast)), op);
}
#line 2585 "syntax.tab.cpp"
    break;

  case 104: /* FactorNode: NUM  */
#line 514 "syntax1.y"
                {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new FactorNode(id);
}
#line 2594 "syntax.tab.cpp"
    break;

  case 105: /* FactorNode: VariableNode  */
#line 517 "syntax1.y"
                 {
    (yyval.ast) = new FactorNode(dynamic_cast<VariableNode*>((yyvsp[0].ast)));
}
#line 2602 "syntax.tab.cpp"
    break;

  case 106: /* FactorNode: LPAREN ExpressionNode RPAREN  */
#line 519 "syntax1.y"
                                 {
    (yyval.ast) = new FactorNode(dynamic_cast<ExpressionNode*>((yyvsp[-1].ast)));
}
#line 2610 "syntax.tab.cpp"
    break;

  case 107: /* FactorNode: ID LPAREN ExpressionListNode RPAREN  */
#line 521 "syntax1.y"
                                        {
    FinalNode* id = new FinalNode(*(yyvsp[-3].token));
    (yyval.ast) = new FactorNode(id, dynamic_cast<ExpressionListNode*>((yyvsp[-1].ast)));
}
#line 2619 "syntax.tab.cpp"
    break;

  case 108: /* FactorNode: NOTOP FactorNode  */
#line 524 "syntax1.y"
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
#line 2634 "syntax.tab.cpp"
    break;

  case 109: /* FactorNode: ADDOP FactorNode  */
#line 533 "syntax1.y"
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
#line 2649 "syntax.tab.cpp"
    break;

  case 110: /* FactorNode: BOOL  */
#line 542 "syntax1.y"
         {
    FinalNode* id = new FinalNode(*(yyvsp[0].token));
    (yyval.ast) = new FactorNode(id);
}
#line 2658 "syntax.tab.cpp"
    break;

  case 111: /* FactorNode: ID LPAREN RPAREN  */
#line 545 "syntax1.y"
                    {
    FinalNode* id = new FinalNode(*(yyvsp[-2].token));
    IdVarpartNode* fake_idvar = new IdVarpartNode();
    VariableNode* fake_var = new VariableNode(id, fake_idvar);
    (yyval.ast) = new FactorNode(fake_var); // 测试用例21: 无参数函数 a := foo(); write(foo())
}
#line 2669 "syntax.tab.cpp"
    break;


#line 2673 "syntax.tab.cpp"

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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 555 "syntax1.y"


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
