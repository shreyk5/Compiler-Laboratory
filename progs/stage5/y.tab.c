/* A Bison parser, made by GNU Bison 3.4.1.  */

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
#define YYBISON_VERSION "3.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "task1.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include "task1.h"
    FILE *fp;
   	FILE *fp_read;
    
    #include "task1.c"
    extern FILE* yyin;
    int yylex(void); 

#line 83 "y.tab.c"

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
    START = 258,
    END = 259,
    DECL = 260,
    ENDDECL = 261,
    MAIN = 262,
    INT = 263,
    STR = 264,
    NUM = 265,
    ASSIGN = 266,
    READ = 267,
    WRITE = 268,
    ID = 269,
    PLUS = 270,
    MINUS = 271,
    MUL = 272,
    DIV = 273,
    MOD = 274,
    IF = 275,
    THEN = 276,
    ELSE = 277,
    ENDIF = 278,
    LT = 279,
    GT = 280,
    EQ = 281,
    NEQ = 282,
    GTE = 283,
    LTE = 284,
    DO = 285,
    WHILE = 286,
    ENDWHILE = 287,
    BREAK = 288,
    CONTINUE = 289,
    REPEAT = 290,
    UNTIL = 291,
    STRING = 292,
    RETURN = 293
  };
#endif
/* Tokens.  */
#define START 258
#define END 259
#define DECL 260
#define ENDDECL 261
#define MAIN 262
#define INT 263
#define STR 264
#define NUM 265
#define ASSIGN 266
#define READ 267
#define WRITE 268
#define ID 269
#define PLUS 270
#define MINUS 271
#define MUL 272
#define DIV 273
#define MOD 274
#define IF 275
#define THEN 276
#define ELSE 277
#define ENDIF 278
#define LT 279
#define GT 280
#define EQ 281
#define NEQ 282
#define GTE 283
#define LTE 284
#define DO 285
#define WHILE 286
#define ENDWHILE 287
#define BREAK 288
#define CONTINUE 289
#define REPEAT 290
#define UNTIL 291
#define STRING 292
#define RETURN 293

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "task1.y"

    struct tnode* node;

#line 206 "y.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   489

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      43,    44,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    32,    32,    33,    34,    41,    42,    45,    46,    52,
      54,    57,    58,    61,    64,    65,    68,    69,    70,    76,
      85,    86,    89,   110,   132,   133,   136,   141,   142,   145,
     146,   149,   152,   153,   160,   195,   200,   210,   211,   218,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   234,
     239,   248,   254,   261,   271,   275,   280,   284,   288,   293,
     296,   299,   302,   305,   308,   311,   314,   317,   320,   323,
     326,   327,   328,   334,   335,   336,   348,   362,   367
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "START", "END", "DECL", "ENDDECL",
  "MAIN", "INT", "STR", "NUM", "ASSIGN", "READ", "WRITE", "ID", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "IF", "THEN", "ELSE", "ENDIF", "LT", "GT",
  "EQ", "NEQ", "GTE", "LTE", "DO", "WHILE", "ENDWHILE", "BREAK",
  "CONTINUE", "REPEAT", "UNTIL", "STRING", "RETURN", "';'", "','", "'['",
  "']'", "'('", "')'", "'{'", "'}'", "$accept", "Program", "Type",
  "ParamType", "GDeclBlock", "GDeclList", "GDecl", "GidList", "Gid",
  "FDefBlock", "FDef", "ParamList", "Param", "LDeclBlock", "LDeclList",
  "LDecl", "IDList", "MainBlock", "Body", "SLIST", "RetStmt", "stmt",
  "asgStmt", "inputStmt", "outputStmt", "IfStmt", "WhileStmt",
  "DoWhileStmt", "RepeatStmt", "expr", "ArgList", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,    59,
      44,    91,    93,    40,    41,   123,   125
};
# endif

#define YYPACT_NINF -96

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-96)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      23,    71,     4,    17,    24,   -96,   -96,   -96,   -96,    12,
      86,   -96,    18,   -96,     4,    34,    24,   -96,   -96,    29,
       5,   -96,   -96,   -96,    22,    35,   -96,   -96,    83,    -6,
     -96,    12,    53,    -2,    58,   -96,   -96,   -96,    94,   -31,
     -96,   -96,   114,    84,   -28,   -96,   -96,    56,   -96,   149,
     127,   114,    88,   -96,   -96,   130,   159,   -96,   317,   100,
     127,   114,   -96,    78,   -96,   -96,   102,   105,    -7,   123,
     111,   126,   131,   137,   132,   106,   317,   174,   -96,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   -96,   140,   127,   -96,
     173,   175,   106,   106,   106,   106,   439,   106,   -96,   -96,
     439,   -96,    62,   -96,   106,   341,   184,   -96,   -96,   -96,
     144,   -96,    -4,   135,   357,   261,   156,    76,   177,   101,
     106,    25,   198,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   -96,   -96,   -96,   106,   152,   158,
     -96,   187,   178,   176,   179,   172,   280,   -96,   460,   -15,
     -96,    57,    57,    99,    99,    99,   113,   113,   113,   113,
     113,   113,   299,   -96,   -96,   106,   439,   167,   439,   168,
     -96,   106,   -96,   185,   373,   391,   106,   403,   106,   460,
     180,   -96,   439,   181,   219,   189,   240,   -96,   427,   -96,
     191,   -96,   192,   193,   -96,   -96,   -96
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,    10,     5,     6,     0,
       0,    12,     0,     1,     5,     0,     0,    21,     3,    16,
       0,    15,     9,    11,     0,     0,    20,     2,     0,     0,
      13,     0,     0,     0,     0,     7,     8,    19,     0,     0,
      25,    14,     0,     0,     0,    17,    26,     0,    18,     0,
       0,     0,     0,    24,    28,     0,     0,    30,     0,     0,
       0,     0,    33,     0,    27,    29,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,    40,
      41,    42,    43,    44,    45,    46,    34,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,    47,    48,
       0,    73,    71,    74,     0,     0,     0,    38,    36,    23,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    35,    22,     0,     0,     0,
      49,     0,     0,     0,     0,     0,     0,    75,    78,     0,
      70,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      69,    68,     0,    51,    53,     0,     0,     0,     0,     0,
      72,     0,    76,     0,     0,     0,     0,     0,     0,    77,
       0,    50,     0,     0,     0,     0,     0,    52,     0,    54,
       0,    56,     0,     0,    57,    58,    55
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -96,   -96,    11,   -96,   -96,   -96,   202,   -96,   208,   -96,
     217,   207,   171,   -37,   -96,   194,   -96,     6,   -52,   -95,
     165,   -76,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -74,
     -96
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     9,    38,     4,    10,    11,    20,    21,    16,
      17,    39,    40,    50,    56,    57,    63,     5,    59,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   105,
     149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     107,   117,    35,    36,    93,   119,    35,    36,    87,    47,
      18,    12,    47,    48,    60,    15,    52,    13,   113,   114,
     115,   116,    27,   118,    88,   171,    19,    15,     1,   172,
     122,     2,    14,     8,    94,   101,   110,   137,    37,   102,
     138,   107,    43,   107,    30,    31,   146,   148,    25,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
      55,    24,   103,   162,    35,    36,    32,    55,   104,   147,
      28,   175,    29,   177,   125,   126,   127,     6,    33,     7,
       8,   128,   129,   130,   131,   132,   133,   188,    66,    67,
      68,   174,    22,    34,     7,     8,    69,   179,    42,   107,
      45,   107,   184,   120,   186,   121,    70,    71,    46,    72,
      73,    74,   107,    66,    67,    68,   101,    89,    90,    49,
     102,    69,   143,   128,   129,   130,   131,   132,   133,    51,
      58,    70,    71,    61,    72,    73,    74,    -1,    -1,    -1,
      -1,    -1,    -1,   103,    62,    91,    86,   145,    92,   104,
     123,   124,   125,   126,   127,    54,    96,     7,     8,   128,
     129,   130,   131,   132,   133,    64,    95,     7,     8,    97,
      98,   123,   124,   125,   126,   127,    99,   100,   108,   139,
     128,   129,   130,   131,   132,   133,   109,   111,   135,   112,
     136,   163,   123,   124,   125,   126,   127,   164,   165,   166,
     142,   128,   129,   130,   131,   132,   133,   167,   169,   168,
     176,   178,    23,   123,   124,   125,   126,   127,    53,   187,
     189,   144,   128,   129,   130,   131,   132,   133,   191,   180,
     194,   195,   196,    26,   123,   124,   125,   126,   127,    41,
      44,   106,   150,   128,   129,   130,   131,   132,   133,     0,
      65,     0,     0,     0,     0,   123,   124,   125,   126,   127,
       0,     0,     0,   190,   128,   129,   130,   131,   132,   133,
       0,     0,     0,     0,     0,     0,   123,   124,   125,   126,
     127,     0,     0,     0,   192,   128,   129,   130,   131,   132,
     133,     0,     0,     0,     0,   123,   124,   125,   126,   127,
       0,     0,     0,   141,   128,   129,   130,   131,   132,   133,
       0,     0,     0,     0,   123,   124,   125,   126,   127,     0,
       0,     0,   170,   128,   129,   130,   131,   132,   133,    66,
      67,    68,     0,     0,     0,     0,     0,    69,     0,     0,
       0,   173,     0,     0,     0,     0,     0,    70,    71,     0,
      72,    73,    74,     0,     0,    75,   123,   124,   125,   126,
     127,     0,     0,     0,     0,   128,   129,   130,   131,   132,
     133,     0,   123,   124,   125,   126,   127,     0,     0,     0,
     134,   128,   129,   130,   131,   132,   133,     0,   123,   124,
     125,   126,   127,     0,     0,     0,   140,   128,   129,   130,
     131,   132,   133,    66,    67,    68,     0,     0,     0,     0,
       0,    69,   181,   182,   183,    66,    67,    68,     0,     0,
       0,    70,    71,    69,    72,    73,    74,     0,     0,     0,
       0,     0,     0,    70,    71,   185,    72,    73,    74,    66,
      67,    68,     0,     0,     0,     0,     0,    69,     0,     0,
     193,    66,    67,    68,     0,     0,     0,    70,    71,    69,
      72,    73,    74,     0,     0,     0,     0,     0,     0,    70,
      71,     0,    72,    73,    74,   123,   124,   125,   126,   127,
       0,     0,     0,     0,   128,   129,   130,   131,   132,   133
};

static const yytype_int16 yycheck[] =
{
      76,    96,     8,     9,    11,   100,     8,     9,    60,    40,
       4,     7,    40,    44,    51,     4,    44,     0,    92,    93,
      94,    95,    16,    97,    61,    40,    14,    16,     5,    44,
     104,     8,     8,     9,    41,    10,    88,    41,    44,    14,
      44,   117,    44,   119,    39,    40,   120,   121,    14,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
      49,    43,    37,   137,     8,     9,    44,    56,    43,    44,
      41,   166,    43,   168,    17,    18,    19,     6,    43,     8,
       9,    24,    25,    26,    27,    28,    29,   182,    12,    13,
      14,   165,     6,    10,     8,     9,    20,   171,    45,   175,
      42,   177,   176,    41,   178,    43,    30,    31,    14,    33,
      34,    35,   188,    12,    13,    14,    10,    39,    40,     5,
      14,    20,    46,    24,    25,    26,    27,    28,    29,    45,
       3,    30,    31,    45,    33,    34,    35,    24,    25,    26,
      27,    28,    29,    37,    14,    43,    46,    46,    43,    43,
      15,    16,    17,    18,    19,     6,    45,     8,     9,    24,
      25,    26,    27,    28,    29,     6,    43,     8,     9,    43,
      39,    15,    16,    17,    18,    19,    39,    45,     4,    44,
      24,    25,    26,    27,    28,    29,    46,    14,     4,    14,
      46,    39,    15,    16,    17,    18,    19,    39,    11,    21,
      44,    24,    25,    26,    27,    28,    29,    31,    36,    30,
      43,    43,    10,    15,    16,    17,    18,    19,    47,    39,
      39,    44,    24,    25,    26,    27,    28,    29,    39,    44,
      39,    39,    39,    16,    15,    16,    17,    18,    19,    31,
      33,    76,    44,    24,    25,    26,    27,    28,    29,    -1,
      56,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    44,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    44,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    42,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    -1,
      -1,    -1,    42,    24,    25,    26,    27,    28,    29,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    35,    -1,    -1,    38,    15,    16,    17,    18,
      19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
      29,    -1,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      39,    24,    25,    26,    27,    28,    29,    -1,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    39,    24,    25,    26,
      27,    28,    29,    12,    13,    14,    -1,    -1,    -1,    -1,
      -1,    20,    39,    22,    23,    12,    13,    14,    -1,    -1,
      -1,    30,    31,    20,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    12,
      13,    14,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      23,    12,    13,    14,    -1,    -1,    -1,    30,    31,    20,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    33,    34,    35,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     8,    48,    51,    64,     6,     8,     9,    49,
      52,    53,     7,     0,     8,    49,    56,    57,    64,    14,
      54,    55,     6,    53,    43,    14,    57,    64,    41,    43,
      39,    40,    44,    43,    10,     8,     9,    44,    50,    58,
      59,    55,    45,    44,    58,    42,    14,    40,    44,     5,
      60,    45,    44,    59,     6,    49,    61,    62,     3,    65,
      60,    45,    14,    63,     6,    62,    12,    13,    14,    20,
      30,    31,    33,    34,    35,    38,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    46,    65,    60,    39,
      40,    43,    43,    11,    41,    43,    45,    43,    39,    39,
      45,    10,    14,    37,    43,    76,    67,    68,     4,    46,
      65,    14,    14,    76,    76,    76,    76,    66,    76,    66,
      41,    43,    76,    15,    16,    17,    18,    19,    24,    25,
      26,    27,    28,    29,    39,     4,    46,    41,    44,    44,
      39,    42,    44,    46,    44,    46,    76,    44,    76,    77,
      44,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    39,    39,    11,    21,    31,    30,    36,
      42,    40,    44,    42,    76,    66,    43,    66,    43,    76,
      44,    39,    22,    23,    76,    32,    76,    39,    66,    39,
      44,    39,    44,    23,    39,    39,    39
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    48,    49,    49,    50,    50,    51,
      51,    52,    52,    53,    54,    54,    55,    55,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    60,    60,    61,
      61,    62,    63,    63,    64,    65,    65,    66,    66,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    70,    70,    71,    72,    72,    73,    74,    75,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     1,     1,     1,     1,     3,
       2,     2,     1,     3,     3,     1,     1,     4,     4,     3,
       2,     1,     9,     8,     3,     1,     2,     3,     2,     2,
       1,     3,     3,     1,     8,     4,     3,     1,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     4,
       7,     5,     8,     5,     8,    10,     8,     9,     9,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     4,     1,     1,     3,     4,     3,     1
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
  YYUSE (yytype);
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
  case 5:
#line 41 "task1.y"
    {variable_type = int_type;}
#line 1484 "y.tab.c"
    break;

  case 6:
#line 42 "task1.y"
    {variable_type = str_type;}
#line 1490 "y.tab.c"
    break;

  case 7:
#line 45 "task1.y"
    {p_variable_type = int_type;}
#line 1496 "y.tab.c"
    break;

  case 8:
#line 46 "task1.y"
    {p_variable_type = str_type;}
#line 1502 "y.tab.c"
    break;

  case 9:
#line 52 "task1.y"
    {GenerateHeader();
                                    PrintSymbolTable();}
#line 1509 "y.tab.c"
    break;

  case 16:
#line 68 "task1.y"
    {Install((yyvsp[0].node)->varname,variable_type,0,1);}
#line 1515 "y.tab.c"
    break;

  case 17:
#line 69 "task1.y"
    {Install((yyvsp[-3].node)->varname,variable_type,1,(yyvsp[-1].node)->val);}
#line 1521 "y.tab.c"
    break;

  case 18:
#line 70 "task1.y"
    {
								Install((yyvsp[-3].node)->varname,variable_type,2,1);
                                InsertParamList((yyvsp[-3].node)->varname);
                                clearParamList();	
							}
#line 1531 "y.tab.c"
    break;

  case 19:
#line 76 "task1.y"
    {
                                Install((yyvsp[-2].node)->varname,variable_type,2,1);
                                InsertParamList((yyvsp[-2].node)->varname);
                                clearParamList();   
                            }
#line 1541 "y.tab.c"
    break;

  case 22:
#line 90 "task1.y"
    {
			CheckIfFunction((yyvsp[-7].node)->varname);
			CheckReturnType((yyvsp[-7].node)->varname,variable_type);
            CheckReturnVal((yyvsp[-1].node)->right,variable_type);
			CheckParamList((yyvsp[-7].node)->varname);
			InsertLST((yyvsp[-7].node)->varname);
			
            ActRecordSetup((yyvsp[-7].node) -> varname);

			MainCodeGen((yyvsp[-1].node));

			PopLocalVariables((yyvsp[-7].node)->varname);

			fprintf(fp,"MOV BP,[SP]\n");
			fprintf(fp,"SUB SP,1\n");
			fprintf(fp,"RET\n");
			clearParamList();
            clearLSTList();	
		}
#line 1565 "y.tab.c"
    break;

  case 23:
#line 111 "task1.y"
    { 
            CheckIfFunction((yyvsp[-6].node)->varname);
            CheckReturnType((yyvsp[-6].node)->varname,variable_type);
            CheckReturnVal((yyvsp[-1].node)->right,variable_type);
            CheckParamList((yyvsp[-6].node)->varname);
            InsertLST((yyvsp[-6].node)->varname);
            
            ActRecordSetup((yyvsp[-6].node) -> varname);

            MainCodeGen((yyvsp[-1].node));

            PopLocalVariables((yyvsp[-6].node)->varname);

            fprintf(fp,"MOV BP,[SP]\n");
            fprintf(fp,"SUB SP,1\n");
            fprintf(fp,"RET\n");
            clearParamList();
            clearLSTList(); 
        }
#line 1589 "y.tab.c"
    break;

  case 26:
#line 136 "task1.y"
    {
						  InsertParam((yyvsp[0].node)->varname,p_variable_type);
					    }
#line 1597 "y.tab.c"
    break;

  case 32:
#line 152 "task1.y"
    {InsertLocalSymbol((yyvsp[0].node)->varname,variable_type);}
#line 1603 "y.tab.c"
    break;

  case 33:
#line 153 "task1.y"
    {InsertLocalSymbol((yyvsp[0].node)->varname,variable_type);}
#line 1609 "y.tab.c"
    break;

  case 34:
#line 160 "task1.y"
    {
            
            CheckReturnVal((yyvsp[-1].node)->right,int_type);
            fprintf(fp,"MAIN: ");   //label for the function
            fprintf(fp,"PUSH BP\n");
            fprintf(fp,"MOV BP,SP\n");
                    
            //now push local variables(contained in LocalSymbols)
            struct Lsymbol* curr = head2;
            
            int local_vars = 0;
            while(curr != NULL)
            {
                local_vars++;
                curr = curr -> next;
            }   

            fprintf(fp,"ADD SP,%d\n",local_vars);
            
            MainCodeGen((yyvsp[-1].node));

            fprintf(fp,"SUB SP,%d\n",local_vars);

            fprintf(fp,"MOV BP,[SP]\n");
            fprintf(fp,"SUB SP,1\n");
            fprintf(fp,"RET\n");
            clearParamList();

}
#line 1643 "y.tab.c"
    break;

  case 35:
#line 196 "task1.y"
    {
            (yyval.node) = createTree(0,NULL,connector_node,-1,NULL,(yyvsp[-2].node),(yyvsp[-1].node),NULL);
        }
#line 1651 "y.tab.c"
    break;

  case 36:
#line 201 "task1.y"
    {
            (yyval.node) = createTree(0,NULL,connector_node,-1,NULL,(yyvsp[-1].node),NULL,NULL);
        }
#line 1659 "y.tab.c"
    break;

  case 37:
#line 210 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1665 "y.tab.c"
    break;

  case 38:
#line 211 "task1.y"
    {(yyval.node) = createTree(0,NULL,connector_node,-1,NULL,(yyvsp[-1].node),(yyvsp[0].node),NULL);}
#line 1671 "y.tab.c"
    break;

  case 39:
#line 218 "task1.y"
    {(yyval.node) = createTree(0,NULL,return_node,(yyvsp[-1].node)->ttype,NULL,(yyvsp[-1].node),NULL,NULL);}
#line 1677 "y.tab.c"
    break;

  case 40:
#line 223 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1683 "y.tab.c"
    break;

  case 41:
#line 224 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1689 "y.tab.c"
    break;

  case 42:
#line 225 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1695 "y.tab.c"
    break;

  case 43:
#line 226 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1701 "y.tab.c"
    break;

  case 44:
#line 227 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1707 "y.tab.c"
    break;

  case 45:
#line 228 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1713 "y.tab.c"
    break;

  case 46:
#line 229 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1719 "y.tab.c"
    break;

  case 47:
#line 230 "task1.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 1725 "y.tab.c"
    break;

  case 48:
#line 231 "task1.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 1731 "y.tab.c"
    break;

  case 49:
#line 234 "task1.y"
    {
                                    checkID((yyvsp[-3].node)->varname);    
									AssignCheckType((yyvsp[-3].node),(yyvsp[-1].node));
									(yyval.node) = createTree(0,NULL,assign_node,(yyvsp[-3].node)->ttype,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);}
#line 1740 "y.tab.c"
    break;

  case 50:
#line 240 "task1.y"
    {
                                    checkID((yyvsp[-6].node)->varname);
                                    CheckIfArray((yyvsp[-6].node)->varname);
                                    CheckIntType((yyvsp[-4].node));
                                    AssignCheckType((yyvsp[-6].node),(yyvsp[-1].node));
                                    (yyval.node) = createTree(0,NULL,assignArray_node,(yyvsp[-6].node)->ttype,NULL,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-1].node));}
#line 1751 "y.tab.c"
    break;

  case 51:
#line 248 "task1.y"
    {
        checkID((yyvsp[-2].node)->varname);
        MatchType((yyvsp[-2].node),var_node);

        (yyval.node) = createTree(0,NULL,read_node,-1,NULL,(yyvsp[-2].node),NULL,NULL);}
#line 1761 "y.tab.c"
    break;

  case 52:
#line 254 "task1.y"
    {
        checkID((yyvsp[-5].node)->varname);
        CheckIfArray((yyvsp[-5].node)->varname);
        CheckIntType((yyvsp[-3].node));
        (yyval.node) = createTree(0,NULL,readArray_node,-1,NULL,(yyvsp[-5].node),(yyvsp[-3].node),NULL);}
#line 1771 "y.tab.c"
    break;

  case 53:
#line 261 "task1.y"
    {

if((yyvsp[-2].node)->ttype != int_type && (yyvsp[-2].node)->ttype != str_type)
{
    printf("Incorrect type in write\n");
}
(yyval.node) = createTree(0,NULL,write_node,-1,NULL,(yyvsp[-2].node),NULL,NULL);

}
#line 1785 "y.tab.c"
    break;

  case 54:
#line 271 "task1.y"
    {
CheckBoolType((yyvsp[-5].node));
(yyval.node) = createTree(0,NULL,if_node,-1,NULL,(yyvsp[-5].node),(yyvsp[-2].node),NULL);}
#line 1793 "y.tab.c"
    break;

  case 55:
#line 275 "task1.y"
    {
        CheckBoolType((yyvsp[-7].node));
        (yyval.node) = createTree(0,NULL,ifElse_node,-1,NULL,(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node));}
#line 1801 "y.tab.c"
    break;

  case 56:
#line 280 "task1.y"
    {
CheckBoolType((yyvsp[-5].node));
(yyval.node) = createTree(0,NULL,while_node,-1,NULL,(yyvsp[-5].node),(yyvsp[-2].node),NULL);}
#line 1809 "y.tab.c"
    break;

  case 57:
#line 284 "task1.y"
    {
CheckBoolType((yyvsp[-2].node));
(yyval.node) = createTree(0,NULL,Dowhile_node,-1,NULL,(yyvsp[-2].node),(yyvsp[-6].node),NULL);}
#line 1817 "y.tab.c"
    break;

  case 58:
#line 288 "task1.y"
    {
CheckBoolType((yyvsp[-2].node));
(yyval.node) = createTree(0,NULL,repeat_node,-1,NULL,(yyvsp[-2].node),(yyvsp[-6].node),NULL);}
#line 1825 "y.tab.c"
    break;

  case 59:
#line 293 "task1.y"
    {CheckType((yyvsp[-2].node),(yyvsp[0].node));
						(yyval.node) = createTree(0,NULL,plus_node,int_type,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1832 "y.tab.c"
    break;

  case 60:
#line 296 "task1.y"
    {CheckType((yyvsp[-2].node),(yyvsp[0].node));
    					(yyval.node) = createTree(0,NULL,minus_node,int_type,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1839 "y.tab.c"
    break;

  case 61:
#line 299 "task1.y"
    {CheckType((yyvsp[-2].node),(yyvsp[0].node));
    					(yyval.node) = createTree(0,NULL,mul_node,int_type,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1846 "y.tab.c"
    break;

  case 62:
#line 302 "task1.y"
    {CheckType((yyvsp[-2].node),(yyvsp[0].node));
    					(yyval.node) = createTree(0,NULL,div_node,int_type,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1853 "y.tab.c"
    break;

  case 63:
#line 305 "task1.y"
    {CheckType((yyvsp[-2].node),(yyvsp[0].node));
                        (yyval.node) = createTree(0,NULL,mod_node,int_type,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1860 "y.tab.c"
    break;

  case 64:
#line 308 "task1.y"
    {CheckType((yyvsp[-2].node),(yyvsp[0].node));
                                (yyval.node) = createTree(0,NULL,lt_node,bool_type,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1867 "y.tab.c"
    break;

  case 65:
#line 311 "task1.y"
    {CheckType((yyvsp[-2].node),(yyvsp[0].node));
                                (yyval.node) = createTree(0,NULL,gt_node,bool_type,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1874 "y.tab.c"
    break;

  case 66:
#line 314 "task1.y"
    {CheckType((yyvsp[-2].node),(yyvsp[0].node));
                                (yyval.node) = createTree(0,NULL,eq_node,bool_type,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1881 "y.tab.c"
    break;

  case 67:
#line 317 "task1.y"
    {CheckType((yyvsp[-2].node),(yyvsp[0].node));
                                (yyval.node) = createTree(0,NULL,neq_node,bool_type,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1888 "y.tab.c"
    break;

  case 68:
#line 320 "task1.y"
    {CheckType((yyvsp[-2].node),(yyvsp[0].node));
                                (yyval.node) = createTree(0,NULL,lte_node,bool_type,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1895 "y.tab.c"
    break;

  case 69:
#line 323 "task1.y"
    {CheckType((yyvsp[-2].node),(yyvsp[0].node));
                                (yyval.node) = createTree(0,NULL,gte_node,bool_type,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);}
#line 1902 "y.tab.c"
    break;

  case 70:
#line 326 "task1.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 1908 "y.tab.c"
    break;

  case 71:
#line 327 "task1.y"
    {checkID((yyvsp[0].node)->varname); (yyval.node) = (yyvsp[0].node);}
#line 1914 "y.tab.c"
    break;

  case 72:
#line 328 "task1.y"
    {checkID((yyvsp[-3].node)->varname); 

    CheckIfArray((yyvsp[-3].node)->varname);
    CheckIntType((yyvsp[-1].node));
    (yyval.node) = createTree(                                       0,NULL,array_node,(yyvsp[-3].node)->ttype,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);}
#line 1924 "y.tab.c"
    break;

  case 73:
#line 334 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1930 "y.tab.c"
    break;

  case 74:
#line 335 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1936 "y.tab.c"
    break;

  case 75:
#line 336 "task1.y"
    {
    							checkID((yyvsp[-2].node)->varname);
    							CheckIfFunction((yyvsp[-2].node)->varname);
    							struct Gsymbol* idx = Lookup2((yyvsp[-2].node)->varname);

    							(yyval.node) = createTree(0,NULL,function_node,idx->type,idx->name,(yyvsp[-2].node),NULL,NULL);

                                CheckInformalParamList((yyval.node),NULL);
                                    
    							(yyval.node) -> Arglist = NULL;	
    						}
#line 1952 "y.tab.c"
    break;

  case 76:
#line 348 "task1.y"
    {
    							checkID((yyvsp[-3].node)->varname);
    							CheckIfFunction((yyvsp[-3].node)->varname);
    							struct Gsymbol* idx = Lookup2((yyvsp[-3].node)->varname);

                                (yyval.node) = createTree(0,NULL,function_node,idx->type,idx->name,(yyvsp[-3].node),(yyvsp[-1].node),NULL);

                                CheckInformalParamList((yyval.node),(yyvsp[-1].node));
                                

    							(yyval.node) -> Arglist = (yyvsp[-1].node);
    						}
#line 1969 "y.tab.c"
    break;

  case 77:
#line 363 "task1.y"
    {
						(yyval.node) = createTree(0,NULL,arg_node,-1,NULL,(yyvsp[0].node),(yyvsp[-2].node),NULL);
					}
#line 1977 "y.tab.c"
    break;

  case 78:
#line 367 "task1.y"
    {
						(yyval.node) = createTree(0,NULL,arg_node,-1,NULL,(yyvsp[0].node),NULL,NULL);
					}
#line 1985 "y.tab.c"
    break;


#line 1989 "y.tab.c"

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
#line 372 "task1.y"


void yyerror(char *S)
{
    printf("Line number : %d\n%s",line,S);
}

int main(int argc,char* argv[])
{
	line = 1;
    variable_type = -1; 
    p_variable_type = -1;
    bind = 4096;

    fp = fopen("/home/shrey/xsm_expl/progs/stage5/input.xsm","w");
    fp_read = fopen(argv[1],"r");
    yyin = fp_read;

    yyparse();

    return 0;
}
