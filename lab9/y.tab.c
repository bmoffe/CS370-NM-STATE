/* A Bison parser, made by GNU Bison 3.4.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lab9.y"


/*
 *			**** CALC ****
 *
 * This routine will function like a desk calculator
 * There are 26 integer registers, named 'a' thru 'z'
 *
 */

/* This calculator depends on a LEX description which outputs either VARIABLE or INTEGER.
   The return type via yylval is integer 

   When we need to make yylval more complicated, we need to define a pointer type for yylval 
   and to instruct YACC to use a new type so that we can pass back better values
 
   The registers are based on 0, so we substract 'a' from each single letter we get.

   based on context, we have YACC do the correct memmory look up or the storage depending
   on position

   Shaun Cooper
    January 2015

   Modified by: Brianna Moffett
   Changes made:
   	-fixed unary minus by removing first expr token from original statement (was "expr - expr",
         is now " - expr")
	-fixed parenthesis by including both open and close parenthesis characters in lex file rule
	-fixed multiplication by adding a new rule to y file: when the program finds a '*' token, it
         performs the multiplication arithmetic
	Changes made: (02.24.20)
	 -added symbol table implementation to calculator
	 -added rulesets for variables/IDs
	 -removed "#include lex.yy.c" from include statements
	 -included symbol table code in YACC file
	Changes made: (03.03.20)
	 -removed symbol table and calculator rules
	 -added rulesets for variables/IDs
	 -added CFG rules for Algol-C language definition
	Changes made: (04.01.20):
	 -added semantic actions for creating AST
	Changes made: (04.17.20):
	 -added type checking, usage checking, declaration checking, and insertion actions
	 -added an include for symtable.h
*/


	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "symtable.h"
#include "ast.h"
#include "emit.h"
int yylex(); /*prototype to get rid of warnings*/
int max(int x, int y);
static int mydebug=0;
extern int ln;
static int offset = 0;
static int goffset = 0;
static int maxoffset = 0;
int level = 0;
extern ASTnode *program;
enum OPERATORS mytype;
void yyerror (s)
  char * s;
  {  /* Called by yyparse on error */
     fprintf (stderr, "%s on line number %d\n", s, ln);
  }
int max(int x, int y){
	if (x < y){return y;}
	else{return x;}
}

#line 146 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING = 258,
    NUM = 259,
    INT = 260,
    VOID = 261,
    BOOLEAN = 262,
    IF = 263,
    ELSE = 264,
    THEN = 265,
    WHILE = 266,
    DO = 267,
    READ = 268,
    WRITE = 269,
    MYRETURN = 270,
    LE = 271,
    GE = 272,
    LT = 273,
    GT = 274,
    EQ = 275,
    NE = 276,
    ID = 277,
    TRUE = 278,
    FALSE = 279,
    AND = 280,
    OR = 281,
    MYBEGIN = 282,
    END = 283,
    NOT = 284
  };
#endif
/* Tokens.  */
#define STRING 258
#define NUM 259
#define INT 260
#define VOID 261
#define BOOLEAN 262
#define IF 263
#define ELSE 264
#define THEN 265
#define WHILE 266
#define DO 267
#define READ 268
#define WRITE 269
#define MYRETURN 270
#define LE 271
#define GE 272
#define LT 273
#define GT 274
#define EQ 275
#define NE 276
#define ID 277
#define TRUE 278
#define FALSE 279
#define AND 280
#define OR 281
#define MYBEGIN 282
#define END 283
#define NOT 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 80 "lab9.y"

	int val;
	char * str;
	char * label;
        ASTnode * node;
	enum OPERATORS operator;

#line 255 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   135

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

#define YYUNDEFTOK  2
#define YYMAXUTOK   284

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,    35,    39,    37,    33,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    30,
       2,    36,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    31,     2,    32,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    95,    95,    98,    99,   103,   104,   107,   115,   129,
     143,   154,   169,   171,   173,   177,   177,   200,   201,   204,
     205,   208,   222,   236,   236,   247,   248,   251,   252,   258,
     259,   260,   261,   262,   263,   264,   265,   268,   270,   274,
     278,   285,   290,   292,   296,   300,   302,   307,   319,   322,
     339,   357,   358,   372,   373,   374,   375,   376,   377,   380,
     381,   396,   397,   400,   401,   416,   417,   418,   419,   422,
     423,   426,   427,   428,   431,   434,   447,   466,   467,   470,
     477
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "NUM", "INT", "VOID",
  "BOOLEAN", "IF", "ELSE", "THEN", "WHILE", "DO", "READ", "WRITE",
  "MYRETURN", "LE", "GE", "LT", "GT", "EQ", "NE", "ID", "TRUE", "FALSE",
  "AND", "OR", "MYBEGIN", "END", "NOT", "';'", "'['", "']'", "','", "'('",
  "')'", "'='", "'+'", "'-'", "'*'", "'/'", "$accept", "program",
  "declist", "dec", "vardec", "varlist", "typespec", "fundec", "$@1",
  "params", "paramlist", "param", "compoundstmt", "$@2", "localdec",
  "statementlist", "statement", "expressionstmt", "selectionstmt",
  "iterationstmt", "returnstmt", "readstmt", "writestmt", "assignmentstmt",
  "expression", "variable", "simpleexpression", "relop",
  "additiveexpression", "addop", "term", "multop", "factor", "call",
  "args", "arglist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      59,    91,    93,    44,    40,    41,    61,    43,    45,    42,
      47
};
# endif

#define YYPACT_NINF -91

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-91)))

#define YYTABLE_NINF -18

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      88,   -91,   -91,   -91,    13,   -91,    88,   -91,     7,   -91,
     -91,   -91,    40,    -3,    34,    29,    91,   -91,    22,   -13,
     -91,    35,    77,    65,   -91,    68,    69,    72,   -91,    88,
      29,    73,    79,   -91,   -91,   -91,   -91,   -91,    88,    88,
      29,    26,   -91,   -91,    43,    43,    82,    -1,     2,   -22,
     -91,   -91,    43,   -91,    43,   -91,    80,    26,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,    81,    71,    70,     5,    36,
     -91,   -91,    99,   -91,    98,    83,    85,    86,    87,   -91,
      89,    43,    43,   -91,    78,   -91,   -91,   -91,    43,   -91,
     -91,   -91,   -91,   -91,   -91,    43,   -91,   -91,    43,   -91,
     -91,   -91,   -91,    43,    26,    26,   -91,   -91,   -91,   -91,
      90,    92,    93,   -91,   -91,    62,     5,    36,   -91,   103,
     -91,   -91,    43,   -91,   -91,    26,   -91,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,    14,     0,     2,     3,     5,     0,     6,
       1,     4,     8,     0,     0,     0,     0,     7,     0,     8,
      10,    13,     0,     0,    18,    19,     9,    21,    15,     0,
       0,     0,     0,    20,    11,    22,    23,    16,    25,    25,
       0,    27,    26,    70,     0,     0,     0,     0,     0,    49,
      73,    74,     0,    38,     0,    30,     0,    27,    29,    31,
      32,    34,    35,    36,    33,     0,    71,    48,    51,    59,
      63,    72,     0,    71,     0,    49,     0,     0,     0,    42,
       0,     0,    77,    75,     0,    24,    28,    37,     0,    53,
      56,    54,    55,    57,    58,     0,    61,    62,     0,    67,
      68,    65,    66,     0,     0,     0,    44,    46,    45,    43,
       0,    79,     0,    78,    69,     0,    52,    60,    64,    39,
      41,    50,     0,    76,    47,     0,    80,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,   112,   -91,    19,   -11,    30,   -91,   -91,   -91,
      94,   -91,    95,   -91,    96,    63,   -90,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -37,   -41,    33,   -91,    31,   -91,
      32,   -91,   -51,   -91,   -91,     9
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    13,     8,     9,    32,    23,
      24,    25,    55,    38,    41,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    73,    67,    95,    68,    98,
      69,   103,    70,    71,   112,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      66,    83,    77,    43,    20,    76,    43,    72,    74,    81,
      78,    80,    82,    10,   119,   120,    66,    84,    14,    34,
      15,    49,    50,    51,    49,    50,    51,    17,    52,    12,
      43,    52,    79,    54,    44,   127,    54,    45,    18,    46,
      47,    48,    96,    97,   110,   111,    22,    43,    49,    50,
      51,    19,   118,    36,    26,    52,    53,    39,    39,    22,
      54,    99,   100,    66,    66,    49,    50,    51,    40,    40,
     -17,    14,    52,    15,    16,   101,   102,    54,    89,    90,
      91,    92,    93,    94,    66,   111,    89,    90,    91,    92,
      93,    94,   124,     1,     2,     3,     1,    21,     3,    27,
      28,    29,    30,    31,    75,    35,    36,    88,    85,   104,
     105,    87,   125,   114,    81,   106,   107,   108,    11,   109,
      86,   115,   121,    33,     0,   122,   116,    37,   123,     0,
     117,   126,     0,     0,     0,    42
};

static const yytype_int8 yycheck[] =
{
      41,    52,     3,     4,    15,    46,     4,    44,    45,    31,
      47,    48,    34,     0,   104,   105,    57,    54,    31,    30,
      33,    22,    23,    24,    22,    23,    24,    30,    29,    22,
       4,    29,    30,    34,     8,   125,    34,    11,     4,    13,
      14,    15,    37,    38,    81,    82,    16,     4,    22,    23,
      24,    22,   103,    27,    32,    29,    30,    38,    39,    29,
      34,    25,    26,   104,   105,    22,    23,    24,    38,    39,
      35,    31,    29,    33,    34,    39,    40,    34,    16,    17,
      18,    19,    20,    21,   125,   122,    16,    17,    18,    19,
      20,    21,    30,     5,     6,     7,     5,     6,     7,    22,
      35,    33,    33,    31,    22,    32,    27,    36,    28,    10,
      12,    30,     9,    35,    31,    30,    30,    30,     6,    30,
      57,    88,    32,    29,    -1,    33,    95,    32,    35,    -1,
      98,   122,    -1,    -1,    -1,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,     7,    42,    43,    44,    45,    47,    48,
       0,    43,    22,    46,    31,    33,    34,    30,     4,    22,
      46,     6,    47,    50,    51,    52,    32,    22,    35,    33,
      33,    31,    49,    51,    46,    32,    27,    53,    54,    45,
      47,    55,    55,     4,     8,    11,    13,    14,    15,    22,
      23,    24,    29,    30,    34,    53,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    69,    71,
      73,    74,    65,    66,    65,    22,    66,     3,    65,    30,
      65,    31,    34,    73,    65,    28,    56,    30,    36,    16,
      17,    18,    19,    20,    21,    68,    37,    38,    70,    25,
      26,    39,    40,    72,    10,    12,    30,    30,    30,    30,
      65,    65,    75,    76,    35,    67,    69,    71,    73,    57,
      57,    32,    33,    35,    30,     9,    76,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    45,    46,    46,
      46,    46,    47,    47,    47,    49,    48,    50,    50,    51,
      51,    52,    52,    54,    53,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    59,
      59,    60,    61,    61,    62,    63,    63,    64,    65,    66,
      66,    67,    67,    68,    68,    68,    68,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    74,    75,    75,    76,
      76
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     0,     7,     1,     1,     1,
       3,     2,     4,     0,     5,     0,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     4,
       6,     4,     2,     3,     3,     3,     3,     4,     1,     1,
       4,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     4,     0,     1,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

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
  case 2:
#line 95 "lab9.y"
    {program = (yyvsp[0].node);}
#line 1447 "y.tab.c"
    break;

  case 3:
#line 98 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1453 "y.tab.c"
    break;

  case 4:
#line 99 "lab9.y"
    {(yyval.node) = (yyvsp[-1].node);
		       (yyvsp[-1].node) -> next = (yyvsp[0].node);}
#line 1460 "y.tab.c"
    break;

  case 5:
#line 103 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1466 "y.tab.c"
    break;

  case 6:
#line 104 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1472 "y.tab.c"
    break;

  case 7:
#line 107 "lab9.y"
    {(yyval.node) = (yyvsp[-1].node); /*when we find a varlist, we point to typespec, then loop through the varlist to set the type*/
					    ASTnode * p = (yyval.node);
				            while(p != NULL){
					      p -> operator = (yyvsp[-2].operator);
					      p -> symbol -> Type = (yyvsp[-2].operator);
					      p = p -> s1;}}
#line 1483 "y.tab.c"
    break;

  case 8:
#line 115 "lab9.y"
    {if (Search((yyvsp[0].str),level,0) != NULL){/*if the symbol is in the table, err; else, insert it*/
	 			yyerror((yyvsp[0].str));
				yyerror("symbol already in use");
				exit(1);
			     }
			     else{
	 		        (yyval.node) = ASTcreatenode(VARDEC); /*vars can be a single variable, and array, or either of those followed by a varlist*/
				(yyval.node)-> symbol = Insert((yyvsp[0].str), -1, 0, level, 1, offset, NULL);
				(yyval.node) -> name = (yyvsp[0].str);
				offset += 1;
				Display();}
                                (yyval.node) -> name = (yyvsp[0].str);
			     }
#line 1501 "y.tab.c"
    break;

  case 9:
#line 130 "lab9.y"
    {if (Search((yyvsp[-3].str), level, 0)){
					yyerror((yyvsp[-3].str));
					yyerror("symbol in use");
					exit(1);
				    }
				    else{
				     (yyval.node) = ASTcreatenode(VARDEC);
				     (yyval.node) -> symbol = Insert((yyvsp[-3].str), -1, 2, level, (yyvsp[-1].val), offset, NULL);
				     offset += (yyvsp[-1].val);
				     Display();}
			  	     (yyval.node) -> name = (yyvsp[-3].str);
			  	     (yyval.node) -> value = (yyvsp[-1].val);}
#line 1518 "y.tab.c"
    break;

  case 10:
#line 143 "lab9.y"
    {if(Search((yyvsp[-2].str), level, 0)){/*recursively checks for in use symbols, then inserts if current symbol is not in the table*/
				yyerror((yyvsp[-2].str));
				yyerror("symbol in use");
				exit(1);}
			   else{
				(yyval.node) = ASTcreatenode(VARDEC);
				(yyval.node) -> symbol = Insert((yyvsp[-2].str), -1, 0, level, 1, offset, NULL);
				offset += 1;
				Display();}
			   	(yyval.node) -> name = (yyvsp[-2].str);
			   	(yyval.node) -> s1 = (yyvsp[0].node);}
#line 1534 "y.tab.c"
    break;

  case 11:
#line 154 "lab9.y"
    {if (Search((yyvsp[-5].str), level, 0)){/*recursively checks for in use symbols, then inserts if current
symbol is not in the table*/
					yyerror((yyvsp[-5].str));
					yyerror("symbol in use");
					exit(1);}
				        else{
				       	     (yyval.node) = ASTcreatenode(VARDEC);
					     (yyval.node) -> symbol = Insert((yyvsp[-5].str), -1, 2, level, (yyvsp[-3].val), offset, NULL);
					     offset += (yyvsp[-3].val);
					     Display();}
				             (yyval.node) -> name = (yyvsp[-5].str);
				             (yyval.node) -> value = (yyvsp[-3].val);
				             (yyval.node) -> s1 = (yyvsp[0].node);}
#line 1552 "y.tab.c"
    break;

  case 12:
#line 169 "lab9.y"
    {(yyval.operator) = INTTYPE; /*integer type*/
	    }
#line 1559 "y.tab.c"
    break;

  case 13:
#line 171 "lab9.y"
    {(yyval.operator) = VOIDTYPE; /*void type*/
		   }
#line 1566 "y.tab.c"
    break;

  case 14:
#line 173 "lab9.y"
    {(yyval.operator) = BOOLTYPE; /*boolean type*/
		      }
#line 1573 "y.tab.c"
    break;

  case 15:
#line 177 "lab9.y"
    {if(Search((yyvsp[-3].str),level,0)){
	 					yyerror((yyvsp[-3].str));
						yyerror("duplicate");
						exit(1);
				      }
				      else{
					goffset = offset;
					offset = 2;
					maxoffset = offset;
				      }}
#line 1588 "y.tab.c"
    break;

  case 16:
#line 186 "lab9.y"
    {(yyval.node) = ASTcreatenode(FUNDEC);/*function delcaration*/
						     (yyval.node) -> operator = (yyvsp[-6].operator);/*this is typespec*/
						     (yyval.node) -> name = (yyvsp[-5].str); /*this is ID*/
						     (yyval.node) -> s1 = (yyvsp[-3].node); /*this is params*/
						     (yyval.node) -> s2 = (yyvsp[0].node);
						     maxoffset=max(offset,maxoffset);
						     (yyval.node) -> symbol = Insert((yyvsp[-5].str), (yyvsp[-6].operator), 1, level, 0, offset, (yyvsp[-3].node));
						     (yyval.node) -> symbol -> mysize=maxoffset;
						     (yyval.node) -> value = maxoffset;
						     offset -= Delete(1);
						     level = 0;
						     offset=goffset;}
#line 1605 "y.tab.c"
    break;

  case 17:
#line 200 "lab9.y"
    {(yyval.node) = NULL;}
#line 1611 "y.tab.c"
    break;

  case 18:
#line 201 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1617 "y.tab.c"
    break;

  case 19:
#line 204 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1623 "y.tab.c"
    break;

  case 20:
#line 205 "lab9.y"
    {(yyval.node) = (yyvsp[-2].node);
				 (yyval.node) -> next = (yyvsp[0].node);}
#line 1630 "y.tab.c"
    break;

  case 21:
#line 208 "lab9.y"
    {if (Search((yyvsp[0].str), level + 1, 0)){/*if the symbol is in the table, err, else, insert*/
				yyerror((yyvsp[0].str));
				yyerror("symbol in use");
				exit(1);}
				
			 (yyval.node) = ASTcreatenode(PARAM); /*param; when we het here, create PARAM node and set operator and name*/
			 (yyval.node) -> symbol = Insert((yyvsp[0].str), (yyvsp[-1].operator), 0, level + 1, 1, offset, 0);
			 offset += 1;
			 if(mydebug){Display();}
	  		 (yyval.node) -> operator = (yyvsp[-1].operator);
		         (yyval.node) -> semtype = (yyvsp[-1].operator);
			 (yyval.node) -> value = 0;
			 (yyval.node) -> name = (yyvsp[0].str);}
#line 1648 "y.tab.c"
    break;

  case 22:
#line 222 "lab9.y"
    {if(Search((yyvsp[-2].str), level + 1, 0)){/*if the symbol is in the table, err, else, insert*/
					yyerror((yyvsp[-2].str));
					yyerror("symbol in use");
					exit(1);}

				     (yyval.node) = ASTcreatenode(PARAM); /*array param; create PARAM node, set operator, name, and value*/
				     (yyval.node) -> symbol = Insert((yyvsp[-2].str), (yyvsp[-3].operator), 2, level + 1, 1, offset, 0);
			     	     offset += 1;
				     Display();
				     (yyval.node) -> semtype = (yyvsp[-3].operator);
				     (yyval.node) -> operator = (yyvsp[-3].operator);
				     (yyval.node) -> name = (yyvsp[-2].str);
				     (yyval.node) -> value = -1;}
#line 1666 "y.tab.c"
    break;

  case 23:
#line 236 "lab9.y"
    {level++; printf("Block level is %d\n", level);}
#line 1672 "y.tab.c"
    break;

  case 24:
#line 236 "lab9.y"
    {/*tracks block level for functions*/
	     						(yyval.node) = ASTcreatenode(BLOCK);
							(yyval.node) -> s1 = (yyvsp[-2].node);
							(yyval.node) -> s2 = (yyvsp[-1].node);
							Display();
							maxoffset=max(maxoffset,offset);
							offset -= Delete(level);
							level--;
						   }
#line 1686 "y.tab.c"
    break;

  case 25:
#line 247 "lab9.y"
    {(yyval.node) = NULL;}
#line 1692 "y.tab.c"
    break;

  case 26:
#line 248 "lab9.y"
    {(yyvsp[-1].node) -> next = (yyvsp[0].node); (yyval.node) = (yyvsp[-1].node);}
#line 1698 "y.tab.c"
    break;

  case 27:
#line 251 "lab9.y"
    {(yyval.node) = NULL;}
#line 1704 "y.tab.c"
    break;

  case 28:
#line 252 "lab9.y"
    {
						(yyvsp[-1].node) -> next = (yyvsp[0].node);
						(yyval.node) = (yyvsp[-1].node);
					}
#line 1713 "y.tab.c"
    break;

  case 29:
#line 258 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1719 "y.tab.c"
    break;

  case 30:
#line 259 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1725 "y.tab.c"
    break;

  case 31:
#line 260 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1731 "y.tab.c"
    break;

  case 32:
#line 261 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1737 "y.tab.c"
    break;

  case 33:
#line 262 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1743 "y.tab.c"
    break;

  case 34:
#line 263 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1749 "y.tab.c"
    break;

  case 35:
#line 264 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1755 "y.tab.c"
    break;

  case 36:
#line 265 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1761 "y.tab.c"
    break;

  case 37:
#line 268 "lab9.y"
    {(yyval.node) = ASTcreatenode(EXPRSTMT); /*create expression statement node, then point s1 to expression*/
	       			 (yyval.node) -> s1 = (yyvsp[-1].node);}
#line 1768 "y.tab.c"
    break;

  case 38:
#line 270 "lab9.y"
    { (yyval.node) = ASTcreatenode(EXPRSTMT); /*point s1 to null if there is no expression following*/
		      (yyval.node) -> s1 = NULL;}
#line 1775 "y.tab.c"
    break;

  case 39:
#line 274 "lab9.y"
    {(yyval.node) = ASTcreatenode(IFSTMT); /*if statement, with no else*/
	   				       (yyval.node) -> s1 = (yyvsp[-2].node);
					       (yyval.node) -> s2 = ASTcreatenode(IFELSE);
					       (yyval.node) -> s2 -> s1 = (yyvsp[0].node);}
#line 1784 "y.tab.c"
    break;

  case 40:
#line 278 "lab9.y"
    {(yyval.node) = ASTcreatenode(IFSTMT); /*if statement, with an else*/
							      (yyval.node) -> s1 = (yyvsp[-4].node);
							      (yyval.node) -> s2 = ASTcreatenode(IFELSE);
					 		      (yyval.node) -> s2 -> s1 = (yyvsp[-2].node);
							      (yyval.node) -> s2 -> s2 = (yyvsp[0].node);}
#line 1794 "y.tab.c"
    break;

  case 41:
#line 285 "lab9.y"
    {(yyval.node) = ASTcreatenode(WHILESTMT); /*while loop*/
	       					(yyval.node) -> s1 = (yyvsp[-2].node);
						(yyval.node) -> s2 = (yyvsp[0].node);}
#line 1802 "y.tab.c"
    break;

  case 42:
#line 290 "lab9.y"
    {(yyval.node) = ASTcreatenode(RETURNSTMT); /*return statement*/
	       		       (yyval.node) -> s1 = NULL;}
#line 1809 "y.tab.c"
    break;

  case 43:
#line 292 "lab9.y"
    {(yyval.node) = ASTcreatenode(RETURNSTMT);
					  (yyval.node) -> s1 = (yyvsp[-1].node);}
#line 1816 "y.tab.c"
    break;

  case 44:
#line 296 "lab9.y"
    {(yyval.node) = ASTcreatenode(READSTMT); /*read statement*/
	       			    (yyval.node) -> s1 = (yyvsp[-1].node);}
#line 1823 "y.tab.c"
    break;

  case 45:
#line 300 "lab9.y"
    {(yyval.node) = ASTcreatenode(WRITESTMT); /*write statement*/
	       			       (yyval.node) -> s1 = (yyvsp[-1].node);}
#line 1830 "y.tab.c"
    break;

  case 46:
#line 302 "lab9.y"
    {(yyval.node) = ASTcreatenode(WRITESTMT);
				  (yyval.node) -> name = (yyvsp[-1].str);
				  (yyval.node) -> label = genlabel();}
#line 1838 "y.tab.c"
    break;

  case 47:
#line 307 "lab9.y"
    {(yyval.node) = ASTcreatenode(ASSIGNSTMT); /*assignment; point s1 to variable, point s2 to simpleexpression*/
	       					    if ((yyvsp[-3].node) -> semtype != (yyvsp[-1].node) -> semtype){/*if types mismatch, err*/
							yyerror("type mismatch");
							exit(1);
					 	    }
	       					    (yyval.node) -> name = createtemp();
						    (yyval.node) -> symbol = Insert((yyval.node)->name, INTDEC, 0, level,1,offset, 0);
						    offset++; 
						    (yyval.node) -> s1 = (yyvsp[-3].node);
						    (yyval.node) -> s2 = (yyvsp[-1].node);}
#line 1853 "y.tab.c"
    break;

  case 48:
#line 319 "lab9.y"
    {(yyval.node)= (yyvsp[0].node);}
#line 1859 "y.tab.c"
    break;

  case 49:
#line 322 "lab9.y"
    {struct SymbTab * p; /*if we try to do math on a void variable or undeclared variable, err*/
	       	     p = Search((yyvsp[0].str), level, 1);
	       	     if (p == NULL || p ->mysize > 1 || p -> Type == VOIDTYPE){
			yyerror((yyvsp[0].str));
			yyerror("variable undeclared or variable cannot be used this way");
			exit(1);}
					if (p -> IsAFunc != 0){
						yyerror((yyvsp[0].str));
						yyerror("not an array");
						exit(1);
					}
			
	       	     	(yyval.node) = ASTcreatenode(IDENTIFIER); /*variable; create IDENTIFIER node, then set its name to ID, and point s1 to null since it has nothing following it*/ /*if we try to do math on a void variable or undeclared variable, or use a variable in the wrong manner, err*/
			(yyval.node) -> symbol = p;
			(yyval.node) -> semtype = p -> Type;
	       	     	(yyval.node) -> name = (yyvsp[0].str);
		     	(yyval.node) -> s1 = NULL;}
#line 1881 "y.tab.c"
    break;

  case 50:
#line 339 "lab9.y"
    {struct SymbTab * p; 
					p = Search((yyvsp[-3].str), level, 1);
					if (p == NULL){
						yyerror((yyvsp[-3].str));
						yyerror("variable undeclared");
						exit(1);}
					if (p -> IsAFunc != 2){
						yyerror((yyvsp[-3].str));
						yyerror("not an array");
						exit(1);
					}
					(yyval.node) = ASTcreatenode(IDENTIFIER); /*do the same as before, but point s1 to expression now*/
					(yyval.node) -> symbol = p;
					(yyval.node) -> semtype = p -> Type;
					(yyval.node) -> name = (yyvsp[-3].str);
					(yyval.node) -> s1 = (yyvsp[-1].node);}
#line 1902 "y.tab.c"
    break;

  case 51:
#line 357 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1908 "y.tab.c"
    break;

  case 52:
#line 358 "lab9.y"
    {(yyval.node) = ASTcreatenode(EXPR); /*create EXPRnode and point s1 to simpleexpression, operator to relop, and s2 to additiveexpression*/
					 if ((yyvsp[-2].node) -> semtype != (yyvsp[0].node) -> semtype){/*if types mismatch, err*/
						yyerror("type mismatch");
						exit(1);
					 }
					 (yyval.node) -> name = createtemp();
					 (yyval.node) -> symbol = Insert((yyval.node)->name,INTDEC,0,level,1,offset,0);
					 offset++;
					 (yyval.node) -> semtype = (yyvsp[-2].node) -> semtype;
					 (yyval.node) -> s1 = (yyvsp[-2].node);
					 (yyval.node) -> operator = (yyvsp[-1].operator);
					 (yyval.node) -> s2 = (yyvsp[0].node);}
#line 1925 "y.tab.c"
    break;

  case 53:
#line 372 "lab9.y"
    {(yyval.operator) = LESSTHANEQ;}
#line 1931 "y.tab.c"
    break;

  case 54:
#line 373 "lab9.y"
    {(yyval.operator) = LESSTHAN;}
#line 1937 "y.tab.c"
    break;

  case 55:
#line 374 "lab9.y"
    {(yyval.operator) = GREATERTHAN;}
#line 1943 "y.tab.c"
    break;

  case 56:
#line 375 "lab9.y"
    {(yyval.operator) = GREATERTHANEQ;}
#line 1949 "y.tab.c"
    break;

  case 57:
#line 376 "lab9.y"
    {(yyval.operator) = EQUAL;}
#line 1955 "y.tab.c"
    break;

  case 58:
#line 377 "lab9.y"
    {(yyval.operator) = NOTEQUAL;}
#line 1961 "y.tab.c"
    break;

  case 59:
#line 380 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1967 "y.tab.c"
    break;

  case 60:
#line 381 "lab9.y"
    {
					 if ((yyvsp[-2].node) -> semtype != (yyvsp[0].node) -> semtype){/*if types mismatch, err*/
						yyerror("type mismatch");
						exit(1);
					 }
						    (yyval.node) = ASTcreatenode(EXPR); /*create EXPR node and point s1 to additiveexpression, operator to addop, and s2 to term*/
						    (yyval.node) -> name = createtemp();
						    (yyval.node) -> symbol = Insert((yyval.node)->name, INTDEC,0,level,1,offset,0);
						    offset++;
						    (yyval.node) -> semtype = (yyvsp[-2].node) -> semtype;
		   				    (yyval.node) -> s1 = (yyvsp[-2].node);
						    (yyval.node) -> operator = (yyvsp[-1].operator);
						    (yyval.node) -> s2 = (yyvsp[0].node);}
#line 1985 "y.tab.c"
    break;

  case 61:
#line 396 "lab9.y"
    {(yyval.operator) = PLUS;}
#line 1991 "y.tab.c"
    break;

  case 62:
#line 397 "lab9.y"
    {(yyval.operator) = MINUS;}
#line 1997 "y.tab.c"
    break;

  case 63:
#line 400 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2003 "y.tab.c"
    break;

  case 64:
#line 401 "lab9.y"
    {
		     			if ((yyvsp[-2].node) -> semtype != (yyvsp[0].node) -> semtype){/*if types mismatch, err*/
						yyerror("type mismatch");
						exit(1);
					}
					(yyval.node) = ASTcreatenode(EXPR); /*create EXPR node, point s1 to term, operator to multop, and s2 to factor*/
				        (yyval.node) -> semtype = (yyvsp[-2].node) -> semtype;
					(yyval.node) -> s1 = (yyvsp[-2].node);
					(yyval.node) -> operator = (yyvsp[-1].operator);
					(yyval.node) -> s2 = (yyvsp[0].node);
					(yyval.node) -> name = createtemp();
					(yyval.node) -> symbol = Insert((yyval.node) -> name, INTTYPE, 0, level, 1, offset, 0);
					offset++;}
#line 2021 "y.tab.c"
    break;

  case 65:
#line 416 "lab9.y"
    {(yyval.operator) = MULTI;}
#line 2027 "y.tab.c"
    break;

  case 66:
#line 417 "lab9.y"
    {(yyval.operator) = DIV;}
#line 2033 "y.tab.c"
    break;

  case 67:
#line 418 "lab9.y"
    {(yyval.operator) = MYAND;}
#line 2039 "y.tab.c"
    break;

  case 68:
#line 419 "lab9.y"
    {(yyval.operator) = MYOR;}
#line 2045 "y.tab.c"
    break;

  case 69:
#line 422 "lab9.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 2051 "y.tab.c"
    break;

  case 70:
#line 423 "lab9.y"
    {(yyval.node) = ASTcreatenode(NUMBER); /*number*/
			  (yyval.node) -> semtype = INTTYPE;/*set semantic type to int*/
			  (yyval.node) -> value = (yyvsp[0].val);}
#line 2059 "y.tab.c"
    break;

  case 71:
#line 426 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2065 "y.tab.c"
    break;

  case 72:
#line 427 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2071 "y.tab.c"
    break;

  case 73:
#line 428 "lab9.y"
    {(yyval.node) = ASTcreatenode(NUMBER); /*true result of if-else statement; this is set to one*/
			  (yyval.node) -> semtype = BOOLTYPE;/*set semantic type to boolean*/
		           (yyval.node) -> value = 1;}
#line 2079 "y.tab.c"
    break;

  case 74:
#line 431 "lab9.y"
    {(yyval.node) = ASTcreatenode(NUMBER); /*false result of if-else statement; this is set to zero*/
			  (yyval.node) -> semtype = BOOLTYPE;/*set semantic type to boolean*/
		            (yyval.node) -> value = 0;}
#line 2087 "y.tab.c"
    break;

  case 75:
#line 434 "lab9.y"
    {
				 if ((yyvsp[0].node) -> semtype != BOOLTYPE){/*if types mismatch, err*/
					yyerror("type mismatch");
					exit(1);}

				 (yyval.node) = ASTcreatenode(EXPR); /*create EXPR node, point operator to your own NOT type (as not is a reserved word) and s1 to factor*/
				 (yyval.node) -> name = createtemp();
				 (yyval.node) -> symbol = Insert((yyval.node)->name,INTDEC,0,level,1,offset,0);
				 (yyval.node) -> operator = MYNOT;
				 (yyval.node) -> semtype = BOOLTYPE;
				 (yyval.node) -> s1 = (yyvsp[0].node);}
#line 2103 "y.tab.c"
    break;

  case 76:
#line 447 "lab9.y"
    {struct SymbTab * p;/*if function is undefined, err*/
					p = Search((yyvsp[-3].str),0,0);
		   		      if (p == NULL){
					yyerror((yyvsp[-3].str));
					yyerror("function name undefined");/*need to check if function*/
					exit(1);
				      }
				      if (p -> IsAFunc != 1){
					yyerror((yyvsp[-3].str));
					yyerror("not a function");/*need to check if function*/
					exit(1);
				      }
		   		      (yyval.node) = ASTcreatenode(CALL); /*function call; point name to ID, and s1 to args*/
		   		      (yyval.node) -> name = (yyvsp[-3].str);
				      (yyval.node) -> semtype = p -> Type;
				      (yyval.node) -> symbol = p;
				      (yyval.node) -> s1 = (yyvsp[-1].node);}
#line 2125 "y.tab.c"
    break;

  case 77:
#line 466 "lab9.y"
    {(yyval.node) = NULL;}
#line 2131 "y.tab.c"
    break;

  case 78:
#line 467 "lab9.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2137 "y.tab.c"
    break;

  case 79:
#line 470 "lab9.y"
    {(yyval.node) = ASTcreatenode(ARGSLIST); /*create ARGSLIST node, point s1 to expression and next of arglist to null*/
		   		 (yyval.node) -> name = createtemp();
				 (yyval.node) -> symbol = Insert((yyval.node) -> name, (yyvsp[0].node) -> semtype, 0, level, 1, offset, 0);/*insert args into symbol table*/
				 offset++;
		   		 (yyval.node) -> s1 = (yyvsp[0].node);
				 (yyval.node) -> semtype = (yyvsp[0].node) -> semtype;
				 (yyval.node) -> next = NULL;}
#line 2149 "y.tab.c"
    break;

  case 80:
#line 477 "lab9.y"
    {(yyval.node) = ASTcreatenode(ARGSLIST); /*do the same thing here, except now next should point to arglist*/
					     (yyval.node) -> name = createtemp();
					     (yyval.node) -> symbol = Insert((yyval.node) -> name, (yyvsp[-2].node) -> semtype, 0, level, 1, offset, 0);
				 	     (yyval.node) -> semtype = (yyvsp[-2].node) -> semtype;
					     offset++;
					     (yyval.node) -> s1 = (yyvsp[-2].node);
					     (yyval.node) -> next = (yyvsp[0].node);}
#line 2161 "y.tab.c"
    break;


#line 2165 "y.tab.c"

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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 485 "lab9.y"
	/* end of rules, start of program */
/*int max(int x, int y){
	if (x > y){return(x);}
	else{return(y);}
}*/

int main(int argc, char *argv[]) /*main; call ASTprint, feed it program and 0*/
{
  int i=0;
  char s[100];
  FILE * file;
  int foundit = 0;
  while (i < argc){
	if (strcmp(argv[i], "-d") == 0){
		mydebug = 1;
	 	i = i + 1;
	}
	else if(strcmp(argv[i], "-o") == 0){
		if (argc > i + 1){
			foundit = 1;
		}
		sprintf(s, "%s.asm",argv[i+1]);
		i = i+2;
	}
	else {i = i+1;}
  }
  if(foundit == 0){
	printf("must provide -o arg\n");
	exit(1);
  }
  file=fopen(s,"w");
  if (file == NULL){
	printf("cannot open %s\n",s);
	exit(1);
  }
  yyparse();
  fprintf(stderr, "The input has been syntactically checked.\n");
  ASTprint(program, 0);
  fprintf(file,"\n.data\n");
  emitstrings(file, program);
  fprintf(file, "NL:\t.asciiz\t\"\\n\"\n");
  fprintf(file,"\n.align 2\n");
  emitglobals(file, program);
  fprintf(file,"\n.text\n");
  printf("pls work\n");
  emitast(file, program);
  printf("pls work\n");
}
