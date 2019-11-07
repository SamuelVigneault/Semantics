/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 59 "decaf.y" /* yacc.c:339  */

#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include "tokentype.h" 
#include "parsetree.h"

  /* we are building parse trees */
#define YYSTYPE ParseTree *

using namespace std;
 
 extern Token *myTok;
 extern int yylineno;
 int yylex();
 ParseTree *top;
 ParseTree *tempo;
 

#line 88 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_Void = 1,
    T_Int = 2,
    T_Double = 3,
    T_Bool = 4,
    T_String = 5,
    T_Class = 6,
    T_Interface = 7,
    T_Null = 8,
    T_This = 9,
    T_Extends = 10,
    T_Implements = 11,
    T_For = 12,
    T_While = 13,
    T_If = 14,
    T_Else = 15,
    T_Return = 16,
    T_Break = 17,
    T_New = 18,
    T_NewArray = 19,
    T_Print = 20,
    T_ReadInteger = 21,
    T_ReadLine = 22,
    T_Identifier = 23,
    T_TypeIdentifier = 24,
    T_IntConstant = 25,
    T_BoolConstant = 26,
    T_DoubleConstant = 27,
    T_StringConstant = 28,
    T_Plus = 29,
    T_Minus = 30,
    T_Times = 31,
    T_Div = 32,
    T_Mod = 33,
    T_Less = 34,
    T_LessEqual = 35,
    T_Greater = 36,
    T_GreaterEqual = 37,
    T_Assign = 38,
    T_Equal = 39,
    T_NotEqual = 40,
    T_And = 41,
    T_Or = 42,
    T_Not = 43,
    T_Semicolon = 44,
    T_Comma = 45,
    T_Dot = 46,
    T_LBracket = 47,
    T_RBracket = 48,
    T_LParen = 49,
    T_RParen = 50,
    T_LBrace = 51,
    T_RBrace = 52
  };
#endif
/* Tokens.  */
#define T_Void 1
#define T_Int 2
#define T_Double 3
#define T_Bool 4
#define T_String 5
#define T_Class 6
#define T_Interface 7
#define T_Null 8
#define T_This 9
#define T_Extends 10
#define T_Implements 11
#define T_For 12
#define T_While 13
#define T_If 14
#define T_Else 15
#define T_Return 16
#define T_Break 17
#define T_New 18
#define T_NewArray 19
#define T_Print 20
#define T_ReadInteger 21
#define T_ReadLine 22
#define T_Identifier 23
#define T_TypeIdentifier 24
#define T_IntConstant 25
#define T_BoolConstant 26
#define T_DoubleConstant 27
#define T_StringConstant 28
#define T_Plus 29
#define T_Minus 30
#define T_Times 31
#define T_Div 32
#define T_Mod 33
#define T_Less 34
#define T_LessEqual 35
#define T_Greater 36
#define T_GreaterEqual 37
#define T_Assign 38
#define T_Equal 39
#define T_NotEqual 40
#define T_And 41
#define T_Or 42
#define T_Not 43
#define T_Semicolon 44
#define T_Comma 45
#define T_Dot 46
#define T_LBracket 47
#define T_RBracket 48
#define T_LParen 49
#define T_RParen 50
#define T_LBrace 51
#define T_RBrace 52

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 247 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   405

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  94
/* YYNRULES -- Number of rules.  */
#define YYNRULES  177
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  284

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   257

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    87,    88,    90,    91,    92,    93,    97,
      99,   101,   102,   103,   104,   105,   106,   110,   111,   113,
     114,   116,   117,   119,   121,   122,   124,   125,   129,   131,
     132,   134,   135,   137,   138,   140,   141,   143,   144,   146,
     147,   151,   153,   154,   156,   157,   161,   162,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   174,   175,   177,
     179,   181,   183,   184,   185,   186,   188,   190,   194,   195,
     197,   199,   203,   205,   207,   208,   210,   211,   213,   215,
     217,   218,   220,   221,   223,   224,   226,   227,   229,   230,
     233,   234,   236,   237,   238,   239,   241,   242,   244,   245,
     246,   247,   248,   249,   250,   251,   253,   254,   256,   257,
     258,   259,   261,   262,   264,   265,   266,   267,   268,   269,
     271,   272,   273,   275,   276,   277,   279,   280,   281,   282,
     283,   284,   285,   287,   288,   290,   292,   293,   294,   296,
     297,   299,   301,   302,   303,   304,   305,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Int", "T_Double", "T_Bool",
  "T_String", "T_Class", "T_Interface", "T_Null", "T_This", "T_Extends",
  "T_Implements", "T_For", "T_While", "T_If", "T_Else", "T_Return",
  "T_Break", "T_New", "T_NewArray", "T_Print", "T_ReadInteger",
  "T_ReadLine", "T_Identifier", "T_TypeIdentifier", "T_IntConstant",
  "T_BoolConstant", "T_DoubleConstant", "T_StringConstant", "T_Plus",
  "T_Minus", "T_Times", "T_Div", "T_Mod", "T_Less", "T_LessEqual",
  "T_Greater", "T_GreaterEqual", "T_Assign", "T_Equal", "T_NotEqual",
  "T_And", "T_Or", "T_Not", "T_Semicolon", "T_Comma", "T_Dot",
  "T_LBracket", "T_RBracket", "T_LParen", "T_RParen", "T_LBrace",
  "T_RBrace", "$accept", "Program", "Decl", "Decl1", "VarDec", "Var",
  "Type", "FuncDec", "Formals", "Formals1", "StmtBlock", "VarDecSt",
  "StmtSt", "ClassDec", "Extend", "Implem", "Implem1", "Field1", "Field",
  "Idents", "InterfaceDec", "Interface", "Prototype", "Stmt", "Matched",
  "ReturnStmt", "PrintStmt", "BreakStmt", "ForStmt", "ForHeader",
  "WhileStmt", "WhileHeader", "Open", "MatchedIfStmt", "IfHeader",
  "ActualsPrint", "ActualsCall", "Actuals", "Actuals1", "Expr16", "Expr15",
  "Expr14", "Expr13", "Expr12", "Expr11", "Expr10", "Expr9", "Expr8",
  "Expr71", "Expr7", "Expr6", "Expr5", "Expr4", "Expr3", "Expr2", "Expr1",
  "Expr", "NewArrayType", "NewArrayHack", "LValue", "Call", "FieldA",
  "Constant", "Print", "Break", "Return", "Less", "LessEqual", "Greater",
  "GreaterEqual", "Assign", "Equal", "NotEqual", "And", "Or", "Plus",
  "Div", "Mult", "Mod", "Excla", "Negat", "Null", "This", "Void", "Int",
  "Double", "Bool", "String", "IntC", "DoubleC", "BoolC", "StringC",
  "Ident", "TIdent", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52
};
# endif

#define YYPACT_NINF -136

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-136)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      96,  -136,  -136,  -136,  -136,  -136,    25,   -10,  -136,    17,
      96,  -136,  -136,   -24,     4,  -136,  -136,  -136,    21,   -10,
    -136,  -136,  -136,  -136,  -136,  -136,    18,  -136,  -136,   -17,
    -136,  -136,  -136,    12,    23,  -136,     4,    46,   -10,    56,
      25,    97,  -136,  -136,   110,    61,  -136,    67,   110,  -136,
     -10,    84,    78,  -136,     4,    76,   118,   110,   110,   103,
    -136,  -136,   -10,  -136,   113,   110,   115,   116,   113,    37,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,   110,  -136,   181,  -136,  -136,   119,   120,   120,  -136,
    -136,   122,   123,  -136,   126,   127,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,   354,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,   226,  -136,   226,  -136,  -136,   226,  -136,   133,
    -136,   136,   136,   140,   140,    14,    14,    41,    41,    28,
      28,   108,   108,    72,  -136,   144,  -136,   134,  -136,   135,
     141,   296,   354,   354,  -136,  -136,  -136,  -136,  -136,  -136,
     134,   325,   354,  -136,  -136,   -10,   354,   137,   142,   155,
    -136,  -136,  -136,   171,  -136,  -136,   354,   354,  -136,   354,
     354,  -136,  -136,   354,   354,   354,   354,  -136,  -136,  -136,
    -136,   354,   354,   354,   354,   354,   354,   354,   354,  -136,
     354,   354,   354,   354,  -136,  -136,  -136,   354,   354,   354,
     354,   354,   354,   -10,   354,  -136,   354,   354,  -136,   354,
     147,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   354,   354,
     160,   170,   176,  -136,  -136,  -136,   226,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,  -136,  -136,   174,  -136,   173,   182,  -136,   -39,
    -136,   124,   263,  -136,  -136,    60,  -136,  -136,  -136,  -136,
     354,  -136,  -136,   178,  -136,   179,   184,   186,  -136,  -136,
    -136,  -136,  -136,  -136
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   167,   168,   169,   170,   171,     0,     0,   177,     0,
       2,     3,     5,     0,     0,     6,     7,     8,     0,     0,
      12,    13,    14,    15,    16,   176,    29,    39,    40,     0,
       1,     4,     9,     0,    10,    41,     0,     0,     0,     0,
       0,    31,    42,    11,    20,     0,    43,     0,    20,    30,
       0,     0,    32,    21,     0,     0,    19,    20,    20,     0,
      33,    35,     0,    10,     0,     0,     0,     0,     0,     0,
      34,    24,    17,    22,    44,    45,    18,    28,    37,    38,
      36,    26,    25,     0,   165,   166,     0,     0,     0,   149,
     148,     0,     0,   147,     0,     0,   172,   174,   173,   175,
     164,   163,    50,     0,    23,    48,    27,    47,    51,    52,
      53,    55,     0,    54,     0,    46,    56,     0,    49,     0,
      81,    83,    82,    86,    87,    90,    91,    96,    97,   107,
     106,   112,   113,   122,   125,   123,   124,   137,   126,     0,
       0,     0,     0,     0,   146,   127,   142,   143,   144,   145,
     136,     0,     0,    67,    71,     0,     0,     0,     0,     0,
      61,    66,    68,    47,    79,   158,     0,     0,   157,     0,
       0,   155,   156,     0,     0,     0,     0,   150,   151,   152,
     153,     0,     0,     0,     0,     0,     0,     0,     0,   159,
       0,     0,     0,     0,   161,   160,   162,     0,     0,     0,
       0,     0,     0,     0,     0,   154,     0,    74,   140,     0,
       0,    60,    57,    58,   121,   123,   120,   139,     0,     0,
       0,     0,     0,   132,   131,   128,     0,    84,    85,    88,
      89,    92,    93,    94,    95,    99,    98,   101,   100,   103,
     102,   105,   104,   108,   109,   110,   111,   115,   114,   116,
     118,   117,   119,   141,     0,    80,     0,    75,    76,     0,
      59,     0,     0,    78,   129,     0,    70,    69,   138,    73,
       0,    72,    65,     0,    64,     0,   133,     0,   134,   135,
      77,    63,    62,   130
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -136,  -136,  -136,   218,   -62,    75,     0,   183,   -37,  -136,
     -16,  -136,  -136,  -136,  -136,  -136,  -136,  -136,  -136,   199,
    -136,  -136,  -136,   -44,  -113,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,    31,  -136,  -136,  -136,    93,  -136,    50,   175,
    -135,   -98,  -136,  -136,   -85,  -136,    -8,  -136,   -86,  -136,
      33,  -136,   -33,  -136,  -104,  -136,  -136,  -136,  -136,   -80,
    -136,  -136,  -136,  -136,  -136,  -136,   138,   139,   148,   150,
    -136,   143,   149,   146,   158,   131,   130,   132,   153,  -136,
       1,  -136,  -136,   250,  -136,  -136,  -136,  -136,  -136,  -136,
    -136,  -136,    -5,     6
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    54,    15,    55,    56,
     105,    81,    83,    16,    41,    51,    52,    69,    80,    26,
      17,    18,    37,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   210,   208,   256,   257,   153,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   277,   278,   215,
     136,   137,   138,   139,   140,   141,   181,   182,   183,   184,
     206,   173,   174,   169,   166,   190,   197,   198,   199,   142,
     143,   144,   145,    19,    20,    21,    22,    23,   146,   147,
     148,   149,   150,    24
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      14,    27,    29,   135,   163,   159,   213,    78,   270,    34,
      14,    59,    28,   271,    39,    25,   219,    30,    36,    82,
      66,    67,    32,   135,     1,     2,     3,     4,     5,    25,
      40,    45,   135,    47,   135,    27,    42,   135,   214,   216,
       1,     2,     3,     4,     5,    60,    28,     8,    72,    63,
      25,     8,    76,    33,   220,   171,   172,    70,   222,   189,
     100,   135,    43,     8,     2,     3,     4,     5,   160,    14,
     161,   135,   135,   162,    44,    35,   135,   177,   178,   179,
     180,   227,   228,   261,   262,    25,     8,   231,   232,   233,
     234,    77,    46,   247,   248,   249,   250,   251,   252,     1,
       2,     3,     4,     5,     6,     7,   254,    48,   255,   258,
      50,   258,    57,   266,     2,     3,     4,     5,    58,    53,
     203,   204,     8,    53,   135,    62,   135,   135,    64,   135,
     191,   193,    53,    53,    84,    85,     8,    61,   135,   135,
      73,   194,   195,   196,    91,    92,   135,    94,    95,    25,
     221,    96,    97,    98,    99,    68,   100,   243,   244,   245,
     246,   229,   230,   273,   275,    65,    71,    74,    75,   101,
     151,   152,   280,   155,   156,   103,   272,   157,   158,   164,
     165,   135,   135,   168,   205,   207,   209,   211,   226,   223,
     135,    84,    85,   260,   224,    86,    87,    88,   253,    89,
      90,    91,    92,    93,    94,    95,    25,   225,    96,    97,
      98,    99,   263,   100,   235,   236,   237,   238,   239,   240,
     241,   242,   264,   265,   268,   269,   101,   102,    31,   270,
     281,   282,   103,    33,    71,   104,    84,    85,   283,    49,
      86,    87,    88,   217,    89,    90,    91,    92,    93,    94,
      95,    25,    79,    96,    97,    98,    99,   267,   100,   259,
     279,   192,   200,   154,   201,   276,   185,   186,    38,   175,
     170,   101,   102,    84,    85,   176,   187,   103,   188,    71,
     167,     0,     0,    91,    92,   202,    94,    95,    25,     0,
      96,    97,    98,    99,     0,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    84,    85,   101,     0,
       0,     0,     0,     0,   103,   274,    91,    92,     0,    94,
      95,    25,     0,    96,    97,    98,    99,     0,   100,     0,
       0,     0,     0,     0,     0,    84,    85,     0,     0,     0,
       0,   101,   212,     0,     0,    91,    92,   103,    94,    95,
      25,     0,    96,    97,    98,    99,     0,   100,     0,     0,
       0,     0,     0,     0,    84,    85,     0,     0,     0,     0,
     101,   218,     0,     0,    91,    92,   103,    94,    95,    25,
       0,    96,    97,    98,    99,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   101,
       0,     0,     0,     0,     0,   103
};

static const yytype_int16 yycheck[] =
{
       0,     6,     7,    83,   117,   103,   141,    69,    47,    14,
      10,    48,     6,    52,    19,    25,   151,     0,    18,    81,
      57,    58,    46,   103,     3,     4,     5,     6,     7,    25,
      12,    36,   112,    38,   114,    40,    53,   117,   142,   143,
       3,     4,     5,     6,     7,    50,    40,    26,    64,    54,
      25,    26,    68,    49,   152,    41,    42,    62,   156,    31,
      32,   141,    50,    26,     4,     5,     6,     7,   112,    69,
     114,   151,   152,   117,    51,    54,   156,    36,    37,    38,
      39,   166,   167,   218,   219,    25,    26,   173,   174,   175,
     176,    54,    46,   197,   198,   199,   200,   201,   202,     3,
       4,     5,     6,     7,     8,     9,   204,    51,   206,   207,
      13,   209,    51,   226,     4,     5,     6,     7,    51,    44,
      48,    49,    26,    48,   204,    47,   206,   207,    52,   209,
     129,   130,    57,    58,    10,    11,    26,    53,   218,   219,
      65,    33,    34,    35,    20,    21,   226,    23,    24,    25,
     155,    27,    28,    29,    30,    52,    32,   190,   191,   192,
     193,   169,   170,   261,   262,    47,    53,    52,    52,    45,
      51,    51,   270,    51,    51,    51,    52,    51,    51,    46,
      44,   261,   262,    43,    40,    51,    51,    46,    17,    52,
     270,    10,    11,    46,    52,    14,    15,    16,   203,    18,
      19,    20,    21,    22,    23,    24,    25,    52,    27,    28,
      29,    30,    52,    32,   181,   182,   183,   184,   185,   186,
     187,   188,    52,    47,    50,    52,    45,    46,    10,    47,
      52,    52,    51,    49,    53,    54,    10,    11,    52,    40,
      14,    15,    16,   150,    18,    19,    20,    21,    22,    23,
      24,    25,    69,    27,    28,    29,    30,   226,    32,   209,
     265,   130,   132,    88,   132,   265,   128,   128,    18,   126,
     124,    45,    46,    10,    11,   126,   128,    51,   128,    53,
     122,    -1,    -1,    20,    21,   132,    23,    24,    25,    -1,
      27,    28,    29,    30,    -1,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    10,    11,    45,    -1,
      -1,    -1,    -1,    -1,    51,    52,    20,    21,    -1,    23,
      24,    25,    -1,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    20,    21,    51,    23,    24,
      25,    -1,    27,    28,    29,    30,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    10,    11,    -1,    -1,    -1,    -1,
      45,    46,    -1,    -1,    20,    21,    51,    23,    24,    25,
      -1,    27,    28,    29,    30,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    26,    56,
      57,    58,    59,    60,    61,    62,    68,    75,    76,   138,
     139,   140,   141,   142,   148,    25,    74,   147,   148,   147,
       0,    58,    46,    49,   147,    54,    61,    77,   138,   147,
      12,    69,    53,    50,    51,   147,    46,   147,    51,    74,
      13,    70,    71,    60,    61,    63,    64,    51,    51,    63,
     147,    53,    47,   147,    52,    47,    63,    63,    52,    72,
     147,    53,    65,    60,    52,    52,    65,    54,    59,    62,
      73,    66,    59,    67,    10,    11,    14,    15,    16,    18,
      19,    20,    21,    22,    23,    24,    27,    28,    29,    30,
      32,    45,    46,    51,    54,    65,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   114,   115,   116,   117,   118,
     119,   120,   134,   135,   136,   137,   143,   144,   145,   146,
     147,    51,    51,    94,    94,    51,    51,    51,    51,    96,
      78,    78,    78,    79,    46,    44,   129,   129,    43,   128,
     128,    41,    42,   126,   127,   126,   127,    36,    37,    38,
      39,   121,   122,   123,   124,   121,   122,   123,   124,    31,
     130,   135,   130,   135,    33,    34,    35,   131,   132,   133,
     131,   132,   133,    48,    49,    40,   125,    51,    91,    51,
      90,    46,    46,    95,   109,   114,   109,    91,    46,    95,
      96,   147,    96,    52,    52,    52,    17,    99,    99,   101,
     101,   103,   103,   103,   103,   105,   105,   105,   105,   105,
     105,   105,   105,   107,   107,   107,   107,   109,   109,   109,
     109,   109,   109,   147,    96,    96,    92,    93,    96,    93,
      46,    95,    95,    52,    52,    47,    79,    87,    50,    52,
      47,    52,    52,    96,    52,    96,    61,   112,   113,   147,
      96,    52,    52,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    58,    58,    59,
      60,    61,    61,    61,    61,    61,    61,    62,    62,    63,
      63,    64,    64,    65,    66,    66,    67,    67,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    80,    80,    81,
      82,    83,    84,    84,    84,    84,    85,    86,    87,    87,
      88,    89,    90,    91,    92,    92,    93,    93,    94,    95,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   102,   102,   102,   102,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   105,   106,   106,
     106,   106,   107,   107,   108,   108,   108,   108,   108,   108,
     109,   109,   109,   110,   110,   110,   111,   111,   111,   111,
     111,   111,   111,   112,   112,   113,   114,   114,   114,   115,
     115,   116,   117,   117,   117,   117,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     2,
       2,     3,     1,     1,     1,     1,     1,     6,     6,     1,
       0,     1,     3,     4,     0,     2,     0,     2,     7,     0,
       2,     0,     1,     2,     3,     0,     2,     1,     1,     1,
       1,     2,     3,     3,     5,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       2,     2,     6,     6,     5,     5,     2,     2,     2,     4,
       4,     2,     3,     3,     0,     1,     1,     3,     3,     2,
       3,     1,     1,     1,     3,     3,     1,     1,     3,     3,
       1,     1,     3,     3,     3,     3,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     3,     3,
       3,     3,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     3,     4,
       6,     3,     3,     1,     1,     1,     1,     1,     4,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 85 "decaf.y" /* yacc.c:1646  */
    { top = (yyval) = (yyvsp[0]);}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 87 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("program", (yyvsp[0])); }
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 88 "decaf.y" /* yacc.c:1646  */
    {(yyvsp[-1])->addChild((yyvsp[0])); }
#line 1585 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 99 "decaf.y" /* yacc.c:1646  */
    {(yyval) = new ParseTree("variable", (yyvsp[-1]), (yyvsp[0])); }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 101 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("arraytype", (yyvsp[-2])); }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 102 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("primtype", (yyvsp[0])); }
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 103 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("primtype", (yyvsp[0])); }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 104 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("primtype", (yyvsp[0])); }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 105 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("primtype", (yyvsp[0])); }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 106 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("usertype", (yyvsp[0])); }
#line 1627 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 110 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("functiondecl", (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0])); }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 111 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("functiondecl", (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0])); }
#line 1639 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 114 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("formals"); }
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 116 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("formals", (yyvsp[0])); }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 117 "decaf.y" /* yacc.c:1646  */
    {(yyvsp[-2])->addChild((yyvsp[0])); }
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 119 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("stmtblock", (yyvsp[-2]), (yyvsp[-1])); }
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 121 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("vardecls"); }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 122 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-1])->addChild((yyvsp[0])); }
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 124 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("stmts"); }
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 125 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-1])->addChild((yyvsp[0])); }
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 129 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("class", (yyvsp[-5]), (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1])); }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 131 "decaf.y" /* yacc.c:1646  */
    { (yyval) = nullptr; }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 132 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("extends", (yyvsp[0])); }
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 134 "decaf.y" /* yacc.c:1646  */
    { (yyval) = nullptr; }
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 137 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("implements", (yyvsp[0])); }
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 138 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-2])->addChild((yyvsp[0])); }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 140 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("fields"); }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 141 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-1])->addChild((yyvsp[0])); }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 153 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("interface", (yyvsp[-1])); }
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 154 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-2])->addChild((yyvsp[-1])); }
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 156 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("prototype", (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1])); }
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 157 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("prototype", (yyvsp[-4]), (yyvsp[-3]), (yyvsp[-1])); }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 166 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("nullstmt"); }
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 174 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("return", (yyvsp[-1])); }
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 175 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("return", (yyvsp[-1]), (yyvsp[0])); }
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 177 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("print", (yyvsp[-2]), (yyvsp[-1])); }
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 179 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("break", (yyvsp[-1])); }
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 181 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-1])->addChild((yyvsp[0])); }
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 183 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("for", (yyvsp[-3]), (yyvsp[-2]), (yyvsp[-1])); }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 184 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("for", nullptr, (yyvsp[-2]), (yyvsp[-1])); }
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 185 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("for", (yyvsp[-2]), (yyvsp[-1]), nullptr); }
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 186 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("for", nullptr, (yyvsp[-1]), nullptr); }
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 188 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-1])->addChild((yyvsp[0])); }
#line 1825 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 190 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("while", (yyvsp[0])); }
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 194 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-1])->addChild((yyvsp[0])); }
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 195 "decaf.y" /* yacc.c:1646  */
    {(yyvsp[-3])->addChild((yyvsp[-2]), (yyvsp[0]));}
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 197 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-3])->addChild((yyvsp[-2]), (yyvsp[0])); }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 199 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("if", (yyvsp[0])); }
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 203 "decaf.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]); }
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 205 "decaf.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[-1]); }
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 207 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("actuals");  }
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 210 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("actuals", (yyvsp[0]));  }
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 211 "decaf.y" /* yacc.c:1646  */
    { (yyvsp[-2])->addChild((yyvsp[0])); }
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 213 "decaf.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 217 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 223 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 224 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 229 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 230 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 236 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 237 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1933 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 238 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 239 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 244 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 245 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 246 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 247 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 248 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 249 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 250 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 251 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 256 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 257 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 258 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 259 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 264 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 265 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 266 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2035 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 267 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2041 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 268 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 269 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("binop", (yyvsp[-2]), (yyvsp[-1]), (yyvsp[0])); }
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 271 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("uop", (yyvsp[-1]), (yyvsp[0])); }
#line 2059 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 272 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("uop", (yyvsp[-1]), (yyvsp[0])); }
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 281 "decaf.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 282 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("new", (yyvsp[-1])); }
#line 2077 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 283 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("newarray", (yyvsp[-3]), (yyvsp[-1])); }
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 284 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("readline"); }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 285 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("readinteger"); }
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 290 "decaf.y" /* yacc.c:1646  */
    { (yyval)  = new ParseTree("usertype", (yyvsp[0])); }
#line 2101 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 294 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("aref", (yyvsp[-3]), (yyvsp[-1])); }
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 296 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("call", (yyvsp[-1]), (yyvsp[0])); }
#line 2113 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 297 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("call", (yyvsp[-1]), (yyvsp[0])); }
#line 2119 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 299 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree("field_access", (yyvsp[-2]), (yyvsp[0])); }
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 309 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 310 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2137 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 311 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 312 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2149 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 313 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 314 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2161 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 315 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 316 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 317 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 318 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2185 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 319 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 320 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 321 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2203 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 322 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 323 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2215 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 324 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 325 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 326 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2233 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 327 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2239 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 328 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2245 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 329 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 330 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 331 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 332 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 333 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 334 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2281 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 335 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 336 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 337 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 338 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2305 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 339 "decaf.y" /* yacc.c:1646  */
    { (yyval) = new ParseTree(myTok); }
#line 2311 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2315 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 344 "decaf.y" /* yacc.c:1906  */


int yyerror(const char * s)
{
  fprintf(stderr, "%s\n", s);
  return 0;
}
