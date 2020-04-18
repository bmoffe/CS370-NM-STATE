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
#line 1 "lab7.y"


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
int yylex(); /*prototype to get rid of warnings*/

extern int mydebug;
extern int ln;
static int offset = 0;
static int goffset = 0;
int level = 0;
extern ASTnode *program;
enum OPERATORS mytype;
void yyerror (s)
  char * s;
  {  /* Called by yyparse on error */
     fprintf (stderr, "%s on line number %d\n", s, ln);
  }



#line 142 "y.tab.c"

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
    NUM = 258,
    INT = 259,
    VOID = 260,
    BOOLEAN = 261,
    IF = 262,
    ELSE = 263,
    THEN = 264,
    WHILE = 265,
    DO = 266,
    READ = 267,
    WRITE = 268,
    MYRETURN = 269,
    LE = 270,
    GE = 271,
    LT = 272,
    GT = 273,
    EQ = 274,
    NE = 275,
    ID = 276,
    TRUE = 277,
    FALSE = 278,
    AND = 279,
    OR = 280,
    MYBEGIN = 281,
    END = 282,
    NOT = 283
  };
#endif
/* Tokens.  */
#define NUM 258
#define INT 259
#define VOID 260
#define BOOLEAN 261
#define IF 262
#define ELSE 263
#define THEN 264
#define WHILE 265
#define DO 266
#define READ 267
#define WRITE 268
#define MYRETURN 269
#define LE 270
#define GE 271
#define LT 272
#define GT 273
#define EQ 274
#define NE 275
#define ID 276
#define TRUE 277
#define FALSE 278
#define AND 279
#define OR 280
#define MYBEGIN 281
#define END 282
#define NOT 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 76 "lab7.y"

	int val;
	char * str;
        ASTnode * node;
	enum OPERATORS operator;

#line 248 "y.tab.c"

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
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  126

#define YYUNDEFTOK  2
#define YYMAXUTOK   283

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
      33,    34,    38,    36,    32,    37,     2,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    93,    94,    98,    99,   102,   110,   124,
     138,   149,   164,   166,   168,   172,   172,   192,   193,   196,
     197,   200,   214,   228,   228,   238,   239,   242,   243,   249,
     250,   251,   252,   253,   254,   255,   256,   259,   261,   265,
     269,   276,   281,   283,   287,   291,   295,   305,   308,   324,
     341,   342,   353,   354,   355,   356,   357,   358,   361,   362,
     374,   375,   378,   379,   393,   394,   395,   396,   399,   400,
     403,   404,   405,   408,   411,   422,   441,   442,   445,   452
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "INT", "VOID", "BOOLEAN", "IF",
  "ELSE", "THEN", "WHILE", "DO", "READ", "WRITE", "MYRETURN", "LE", "GE",
  "LT", "GT", "EQ", "NE", "ID", "TRUE", "FALSE", "AND", "OR", "MYBEGIN",
  "END", "NOT", "';'", "'['", "']'", "','", "'('", "')'", "'='", "'+'",
  "'-'", "'*'", "'/'", "$accept", "program", "declist", "dec", "vardec",
  "varlist", "typespec", "fundec", "$@1", "params", "paramlist", "param",
  "compoundstmt", "$@2", "localdec", "statementlist", "statement",
  "expressionstmt", "selectionstmt", "iterationstmt", "returnstmt",
  "readstmt", "writestmt", "assignmentstmt", "expression", "variable",
  "simpleexpression", "relop", "additiveexpression", "addop", "term",
  "multop", "factor", "call", "args", "arglist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    59,
      91,    93,    44,    40,    41,    61,    43,    45,    42,    47
};
# endif

#define YYPACT_NINF -101

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-101)))

#define YYTABLE_NINF -18

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      62,  -101,  -101,  -101,     2,  -101,    62,  -101,     8,  -101,
    -101,  -101,    27,   -20,    24,    40,    67,  -101,    33,   -12,
    -101,    57,    71,    59,  -101,    63,    64,    68,  -101,    62,
      40,    66,    73,  -101,  -101,  -101,  -101,  -101,    62,    62,
      40,    12,  -101,  -101,     9,     9,    79,     9,    25,     6,
    -101,  -101,     9,  -101,     9,  -101,    74,    12,  -101,  -101,
    -101,  -101,  -101,  -101,  -101,    65,    70,    69,   -23,    31,
    -101,  -101,    93,  -101,    92,    76,    75,    78,  -101,    80,
       9,     9,  -101,    77,  -101,  -101,  -101,     9,  -101,  -101,
    -101,  -101,  -101,  -101,     9,  -101,  -101,     9,  -101,  -101,
    -101,  -101,     9,    12,    12,  -101,  -101,  -101,    81,    82,
      83,  -101,  -101,    61,   -23,    31,  -101,   100,  -101,  -101,
       9,  -101,  -101,    12,  -101,  -101
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
       0,    27,    26,    69,     0,     0,     0,     0,     0,    48,
      72,    73,     0,    38,     0,    30,     0,    27,    29,    31,
      32,    34,    35,    36,    33,     0,    70,    47,    50,    58,
      62,    71,     0,    70,     0,    48,     0,     0,    42,     0,
       0,    76,    74,     0,    24,    28,    37,     0,    52,    55,
      53,    54,    56,    57,     0,    60,    61,     0,    66,    67,
      64,    65,     0,     0,     0,    44,    45,    43,     0,    78,
       0,    77,    68,     0,    51,    59,    63,    39,    41,    49,
       0,    75,    46,     0,    79,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -101,  -101,   104,  -101,    11,    -9,    36,  -101,  -101,  -101,
      84,  -101,    86,  -101,    85,    58,  -100,  -101,  -101,  -101,
    -101,  -101,  -101,  -101,   -37,   -41,    29,  -101,    26,  -101,
      22,  -101,   -51,  -101,  -101,     1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    13,     8,     9,    32,    23,
      24,    25,    55,    38,    41,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    73,    67,    94,    68,    97,
      69,   102,    70,    71,   110,   111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      66,    82,    10,   117,   118,    76,    20,    72,    74,    17,
      77,    79,    43,    95,    96,    43,    66,    83,    14,    44,
      15,    34,    45,   125,    46,    47,    48,    18,    43,    12,
      49,    50,    51,    49,    50,    51,    80,    52,    36,    81,
      52,    53,    54,   108,   109,    54,    49,    50,    51,    39,
      39,   116,    22,    52,    78,    98,    99,    14,    54,    15,
      16,    19,    66,    66,    26,    22,     1,     2,     3,   100,
     101,     1,    21,     3,    40,    40,    88,    89,    90,    91,
      92,    93,    66,   109,    88,    89,    90,    91,    92,    93,
     122,   -17,    27,    28,    86,    29,    30,    35,    31,    36,
      75,    84,   103,   104,   105,    87,    80,   106,   123,   107,
      11,   112,   119,    33,   120,    85,   113,   121,    37,   115,
     114,   124,     0,     0,    42
};

static const yytype_int8 yycheck[] =
{
      41,    52,     0,   103,   104,    46,    15,    44,    45,    29,
      47,    48,     3,    36,    37,     3,    57,    54,    30,     7,
      32,    30,    10,   123,    12,    13,    14,     3,     3,    21,
      21,    22,    23,    21,    22,    23,    30,    28,    26,    33,
      28,    29,    33,    80,    81,    33,    21,    22,    23,    38,
      39,   102,    16,    28,    29,    24,    25,    30,    33,    32,
      33,    21,   103,   104,    31,    29,     4,     5,     6,    38,
      39,     4,     5,     6,    38,    39,    15,    16,    17,    18,
      19,    20,   123,   120,    15,    16,    17,    18,    19,    20,
      29,    34,    21,    34,    29,    32,    32,    31,    30,    26,
      21,    27,     9,    11,    29,    35,    30,    29,     8,    29,
       6,    34,    31,    29,    32,    57,    87,    34,    32,    97,
      94,   120,    -1,    -1,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,    41,    42,    43,    44,    46,    47,
       0,    42,    21,    45,    30,    32,    33,    29,     3,    21,
      45,     5,    46,    49,    50,    51,    31,    21,    34,    32,
      32,    30,    48,    50,    45,    31,    26,    52,    53,    44,
      46,    54,    54,     3,     7,    10,    12,    13,    14,    21,
      22,    23,    28,    29,    33,    52,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    68,    70,
      72,    73,    64,    65,    64,    21,    65,    64,    29,    64,
      30,    33,    72,    64,    27,    55,    29,    35,    15,    16,
      17,    18,    19,    20,    67,    36,    37,    69,    24,    25,
      38,    39,    71,     9,    11,    29,    29,    29,    64,    64,
      74,    75,    34,    66,    68,    70,    72,    56,    56,    31,
      32,    34,    29,     8,    75,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    44,    45,    45,
      45,    45,    46,    46,    46,    48,    47,    49,    49,    50,
      50,    51,    51,    53,    52,    54,    54,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    57,    57,    58,
      58,    59,    60,    60,    61,    62,    63,    64,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    67,    68,    68,
      69,    69,    70,    70,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    73,    74,    74,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     1,     0,     7,     1,     1,     1,
       3,     2,     4,     0,     5,     0,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     4,
       6,     4,     2,     3,     3,     3,     4,     1,     1,     4,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     2,     4,     0,     1,     1,     3
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
#line 90 "lab7.y"
    {program = (yyvsp[0].node);}
#line 1433 "y.tab.c"
    break;

  case 3:
#line 93 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1439 "y.tab.c"
    break;

  case 4:
#line 94 "lab7.y"
    {(yyval.node) = (yyvsp[-1].node);
		       (yyvsp[-1].node) -> next = (yyvsp[0].node);}
#line 1446 "y.tab.c"
    break;

  case 5:
#line 98 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1452 "y.tab.c"
    break;

  case 6:
#line 99 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1458 "y.tab.c"
    break;

  case 7:
#line 102 "lab7.y"
    {(yyval.node) = (yyvsp[-1].node); /*when we find a varlist, we point to typespec, then loop through the varlist to set the type*/
					    ASTnode * p = (yyval.node);
				            while(p != NULL){
					      p -> operator = (yyvsp[-2].operator);
					      p -> symbol -> Type = (yyvsp[-2].operator);
					      p = p -> s1;}}
#line 1469 "y.tab.c"
    break;

  case 8:
#line 110 "lab7.y"
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
#line 1487 "y.tab.c"
    break;

  case 9:
#line 125 "lab7.y"
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
#line 1504 "y.tab.c"
    break;

  case 10:
#line 138 "lab7.y"
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
#line 1520 "y.tab.c"
    break;

  case 11:
#line 149 "lab7.y"
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
#line 1538 "y.tab.c"
    break;

  case 12:
#line 164 "lab7.y"
    {(yyval.operator) = INTTYPE; /*integer type*/
	    }
#line 1545 "y.tab.c"
    break;

  case 13:
#line 166 "lab7.y"
    {(yyval.operator) = VOIDTYPE; /*void type*/
		   }
#line 1552 "y.tab.c"
    break;

  case 14:
#line 168 "lab7.y"
    {(yyval.operator) = BOOLTYPE; /*boolean type*/
		      }
#line 1559 "y.tab.c"
    break;

  case 15:
#line 172 "lab7.y"
    {if(Search((yyvsp[-3].str), level, 0)){/*if the function is already defined, err; else, insert*/
	                                yyerror((yyvsp[-3].str));
                                yyerror("symbol in use");
                                exit(1);
                            }
                            else{
                                Insert((yyvsp[-3].str), (yyvsp[-4].operator), 1, level, 0, offset, (yyvsp[-1].node));
				Display();
                                goffset = offset;
                                offset = 0;
                            }}
#line 1575 "y.tab.c"
    break;

  case 16:
#line 182 "lab7.y"
    {(yyval.node) = ASTcreatenode(FUNDEC);/*function delcaration*/
						     (yyval.node) -> operator = (yyvsp[-6].operator);/*this is typespec*/
						     (yyval.node) -> name = (yyvsp[-5].str); /*this is ID*/
						     (yyval.node) -> s1 = (yyvsp[-3].node); /*this is params*/
						     (yyval.node) -> s2 = (yyvsp[0].node);
						     offset -= Delete(1);
						     level = 0;
						     offset = goffset;}
#line 1588 "y.tab.c"
    break;

  case 17:
#line 192 "lab7.y"
    {(yyval.node) = NULL;}
#line 1594 "y.tab.c"
    break;

  case 18:
#line 193 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1600 "y.tab.c"
    break;

  case 19:
#line 196 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1606 "y.tab.c"
    break;

  case 20:
#line 197 "lab7.y"
    {(yyval.node) = (yyvsp[-2].node);
				 (yyval.node) -> next = (yyvsp[0].node);}
#line 1613 "y.tab.c"
    break;

  case 21:
#line 200 "lab7.y"
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
#line 1631 "y.tab.c"
    break;

  case 22:
#line 214 "lab7.y"
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
#line 1649 "y.tab.c"
    break;

  case 23:
#line 228 "lab7.y"
    {level++; printf("Block level is %d\n", level);}
#line 1655 "y.tab.c"
    break;

  case 24:
#line 228 "lab7.y"
    {/*tracks block level for functions*/
	     						(yyval.node) = ASTcreatenode(BLOCK);
							(yyval.node) -> s1 = (yyvsp[-2].node);
							(yyval.node) -> s2 = (yyvsp[-1].node);
							Display();
							offset -= Delete(level);
							level--;
						   }
#line 1668 "y.tab.c"
    break;

  case 25:
#line 238 "lab7.y"
    {(yyval.node) = NULL;}
#line 1674 "y.tab.c"
    break;

  case 26:
#line 239 "lab7.y"
    {(yyvsp[-1].node) -> next = (yyvsp[0].node); (yyval.node) = (yyvsp[-1].node);}
#line 1680 "y.tab.c"
    break;

  case 27:
#line 242 "lab7.y"
    {(yyval.node) = NULL;}
#line 1686 "y.tab.c"
    break;

  case 28:
#line 243 "lab7.y"
    {
						(yyvsp[-1].node) -> next = (yyvsp[0].node);
						(yyval.node) = (yyvsp[-1].node);
					}
#line 1695 "y.tab.c"
    break;

  case 29:
#line 249 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1701 "y.tab.c"
    break;

  case 30:
#line 250 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1707 "y.tab.c"
    break;

  case 31:
#line 251 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1713 "y.tab.c"
    break;

  case 32:
#line 252 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1719 "y.tab.c"
    break;

  case 33:
#line 253 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1725 "y.tab.c"
    break;

  case 34:
#line 254 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1731 "y.tab.c"
    break;

  case 35:
#line 255 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1737 "y.tab.c"
    break;

  case 36:
#line 256 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1743 "y.tab.c"
    break;

  case 37:
#line 259 "lab7.y"
    {(yyval.node) = ASTcreatenode(EXPRSTMT); /*create expression statement node, then point s1 to expression*/
	       			 (yyval.node) -> s1 = (yyvsp[-1].node);}
#line 1750 "y.tab.c"
    break;

  case 38:
#line 261 "lab7.y"
    { (yyval.node) = ASTcreatenode(EXPRSTMT); /*point s1 to null if there is no expression following*/
		      (yyval.node) -> s1 = NULL;}
#line 1757 "y.tab.c"
    break;

  case 39:
#line 265 "lab7.y"
    {(yyval.node) = ASTcreatenode(IFSTMT); /*if statement, with no else*/
	   				       (yyval.node) -> s1 = (yyvsp[-2].node);
					       (yyval.node) -> s2 = ASTcreatenode(IFELSE);
					       (yyval.node) -> s2 -> s1 = (yyvsp[0].node);}
#line 1766 "y.tab.c"
    break;

  case 40:
#line 269 "lab7.y"
    {(yyval.node) = ASTcreatenode(IFSTMT); /*if statement, with an else*/
							      (yyval.node) -> s1 = (yyvsp[-4].node);
							      (yyval.node) -> s2 = ASTcreatenode(IFELSE);
					 		      (yyval.node) -> s2 -> s1 = (yyvsp[-2].node);
							      (yyval.node) -> s2 -> s2 = (yyvsp[0].node);}
#line 1776 "y.tab.c"
    break;

  case 41:
#line 276 "lab7.y"
    {(yyval.node) = ASTcreatenode(WHILESTMT); /*while loop*/
	       					(yyval.node) -> s1 = (yyvsp[-2].node);
						(yyval.node) -> s2 = (yyvsp[0].node);}
#line 1784 "y.tab.c"
    break;

  case 42:
#line 281 "lab7.y"
    {(yyval.node) = ASTcreatenode(RETURNSTMT); /*return statement*/
	       		       (yyval.node) -> s1 = NULL;}
#line 1791 "y.tab.c"
    break;

  case 43:
#line 283 "lab7.y"
    {(yyval.node) = ASTcreatenode(RETURNSTMT);
					  (yyval.node) -> s1 = (yyvsp[-1].node);}
#line 1798 "y.tab.c"
    break;

  case 44:
#line 287 "lab7.y"
    {(yyval.node) = ASTcreatenode(READSTMT); /*read statement*/
	       			    (yyval.node) -> s1 = (yyvsp[-1].node);}
#line 1805 "y.tab.c"
    break;

  case 45:
#line 291 "lab7.y"
    {(yyval.node) = ASTcreatenode(WRITESTMT); /*write statement*/
	       			       (yyval.node) -> s1 = (yyvsp[-1].node);}
#line 1812 "y.tab.c"
    break;

  case 46:
#line 295 "lab7.y"
    {(yyval.node) = ASTcreatenode(ASSIGNSTMT); /*assignment; point s1 to variable, point s2 to simpleexpression*/
	       					    if ((yyvsp[-3].node) -> semtype != (yyvsp[-1].node) -> semtype){/*if types mismatch, err*/
							yyerror("type mismatch");
							exit(1);
					 	    }
	       					    
						    (yyval.node) -> s1 = (yyvsp[-3].node);
						    (yyval.node) -> s2 = (yyvsp[-1].node);}
#line 1825 "y.tab.c"
    break;

  case 47:
#line 305 "lab7.y"
    {(yyval.node)= (yyvsp[0].node);}
#line 1831 "y.tab.c"
    break;

  case 48:
#line 308 "lab7.y"
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
			(yyval.node) -> semtype = p -> Type;
	       	     	(yyval.node) -> name = (yyvsp[0].str);
		     	(yyval.node) -> s1 = NULL;}
#line 1852 "y.tab.c"
    break;

  case 49:
#line 324 "lab7.y"
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
					(yyval.node) -> semtype = p -> Type;
					(yyval.node) -> name = (yyvsp[-3].str);
					(yyval.node) -> s1 = (yyvsp[-1].node);}
#line 1872 "y.tab.c"
    break;

  case 50:
#line 341 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1878 "y.tab.c"
    break;

  case 51:
#line 342 "lab7.y"
    {(yyval.node) = ASTcreatenode(EXPR); /*create EXPRnode and point s1 to simpleexpression, operator to relop, and s2 to additiveexpression*/
					 if ((yyvsp[-2].node) -> semtype != (yyvsp[0].node) -> semtype){/*if types mismatch, err*/
						yyerror("type mismatch");
						exit(1);
					 }
					 (yyval.node) -> semtype = (yyvsp[-2].node) -> semtype;
					 (yyval.node) -> s1 = (yyvsp[-2].node);
					 (yyval.node) -> operator = (yyvsp[-1].operator);
					 (yyval.node) -> s2 = (yyvsp[0].node);}
#line 1892 "y.tab.c"
    break;

  case 52:
#line 353 "lab7.y"
    {(yyval.operator) = LESSTHANEQ;}
#line 1898 "y.tab.c"
    break;

  case 53:
#line 354 "lab7.y"
    {(yyval.operator) = LESSTHAN;}
#line 1904 "y.tab.c"
    break;

  case 54:
#line 355 "lab7.y"
    {(yyval.operator) = GREATERTHAN;}
#line 1910 "y.tab.c"
    break;

  case 55:
#line 356 "lab7.y"
    {(yyval.operator) = GREATERTHANEQ;}
#line 1916 "y.tab.c"
    break;

  case 56:
#line 357 "lab7.y"
    {(yyval.operator) = EQUAL;}
#line 1922 "y.tab.c"
    break;

  case 57:
#line 358 "lab7.y"
    {(yyval.operator) = NOTEQUAL;}
#line 1928 "y.tab.c"
    break;

  case 58:
#line 361 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1934 "y.tab.c"
    break;

  case 59:
#line 362 "lab7.y"
    {
					 if ((yyvsp[-2].node) -> semtype != (yyvsp[0].node) -> semtype){/*if types mismatch, err*/
						yyerror("type mismatch");
						exit(1);
					 }
						    (yyval.node) = ASTcreatenode(EXPR); /*create EXPR node and point s1 to additiveexpression, operator to addop, and s2 to term*/
						    (yyval.node) -> semtype = (yyvsp[-2].node) -> semtype;
		   				    (yyval.node) -> s1 = (yyvsp[-2].node);
						    (yyval.node) -> operator = (yyvsp[-1].operator);
						    (yyval.node) -> s2 = (yyvsp[0].node);}
#line 1949 "y.tab.c"
    break;

  case 60:
#line 374 "lab7.y"
    {(yyval.operator) = PLUS;}
#line 1955 "y.tab.c"
    break;

  case 61:
#line 375 "lab7.y"
    {(yyval.operator) = MINUS;}
#line 1961 "y.tab.c"
    break;

  case 62:
#line 378 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1967 "y.tab.c"
    break;

  case 63:
#line 379 "lab7.y"
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
					(yyval.node) -> symbol = Insert((yyval.node) -> name, INTTYPE, 0, level, 1, offset, 0);}
#line 1984 "y.tab.c"
    break;

  case 64:
#line 393 "lab7.y"
    {(yyval.operator) = MULTI;}
#line 1990 "y.tab.c"
    break;

  case 65:
#line 394 "lab7.y"
    {(yyval.operator) = DIV;}
#line 1996 "y.tab.c"
    break;

  case 66:
#line 395 "lab7.y"
    {(yyval.operator) = MYAND;}
#line 2002 "y.tab.c"
    break;

  case 67:
#line 396 "lab7.y"
    {(yyval.operator) = MYOR;}
#line 2008 "y.tab.c"
    break;

  case 68:
#line 399 "lab7.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 2014 "y.tab.c"
    break;

  case 69:
#line 400 "lab7.y"
    {(yyval.node) = ASTcreatenode(NUMBER); /*number*/
			  (yyval.node) -> semtype = INTTYPE;/*set semantic type to int*/
			  (yyval.node) -> value = (yyvsp[0].val);}
#line 2022 "y.tab.c"
    break;

  case 70:
#line 403 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2028 "y.tab.c"
    break;

  case 71:
#line 404 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2034 "y.tab.c"
    break;

  case 72:
#line 405 "lab7.y"
    {(yyval.node) = ASTcreatenode(NUMBER); /*true result of if-else statement; this is set to one*/
			  (yyval.node) -> semtype = BOOLTYPE;/*set semantic type to boolean*/
		           (yyval.node) -> value = 1;}
#line 2042 "y.tab.c"
    break;

  case 73:
#line 408 "lab7.y"
    {(yyval.node) = ASTcreatenode(NUMBER); /*false result of if-else statement; this is set to zero*/
			  (yyval.node) -> semtype = BOOLTYPE;/*set semantic type to boolean*/
		            (yyval.node) -> value = 0;}
#line 2050 "y.tab.c"
    break;

  case 74:
#line 411 "lab7.y"
    {
				 if ((yyvsp[0].node) -> semtype != BOOLTYPE){/*if types mismatch, err*/
					yyerror("type mismatch");
					exit(1);}

				 (yyval.node) = ASTcreatenode(EXPR); /*create EXPR node, point operator to your own NOT type (as not is a reserved word) and s1 to factor*/
				 (yyval.node) -> operator = MYNOT;
				 (yyval.node) -> semtype = BOOLTYPE;
				 (yyval.node) -> s1 = (yyvsp[0].node);}
#line 2064 "y.tab.c"
    break;

  case 75:
#line 422 "lab7.y"
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
#line 2086 "y.tab.c"
    break;

  case 76:
#line 441 "lab7.y"
    {(yyval.node) = NULL;}
#line 2092 "y.tab.c"
    break;

  case 77:
#line 442 "lab7.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2098 "y.tab.c"
    break;

  case 78:
#line 445 "lab7.y"
    {(yyval.node) = ASTcreatenode(ARGSLIST); /*create ARGSLIST node, point s1 to expression and next of arglist to null*/
		   		 (yyval.node) -> name = createtemp();
				 (yyval.node) -> symbol = Insert((yyval.node) -> name, (yyvsp[0].node) -> semtype, 0, level, 1, offset, 0);/*insert args into symbol table*/
				 offset++;
		   		 (yyval.node) -> s1 = (yyvsp[0].node);
				 (yyval.node) -> semtype = (yyvsp[0].node) -> semtype;
				 (yyval.node) -> next = NULL;}
#line 2110 "y.tab.c"
    break;

  case 79:
#line 452 "lab7.y"
    {(yyval.node) = ASTcreatenode(ARGSLIST); /*do the same thing here, except now next should point to arglist*/
					     (yyval.node) -> name = createtemp();
					     (yyval.node) -> symbol = Insert((yyval.node) -> name, (yyvsp[-2].node) -> semtype, 0, level, 1, offset, 0);
				 	     (yyval.node) -> semtype = (yyvsp[-2].node) -> semtype;
					     offset++;
					     (yyval.node) -> s1 = (yyvsp[-2].node);
					     (yyval.node) -> next = (yyvsp[0].node);}
#line 2122 "y.tab.c"
    break;


#line 2126 "y.tab.c"

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
#line 460 "lab7.y"
	/* end of rules, start of program */

int main(int argv, char *arg[]) /*main; call ASTprint, feed it program and 0*/
{ 
  yyparse();
  fprintf(stderr, "The input has been syntactically checked.\n");
  ASTprint(program, 0);
}
