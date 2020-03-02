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
	struct Typetable *Thead = NULL, *Ttail = NULL;	//points to the head and tail of Typetable list
	struct Typetable *DeclType = NULL;	//points to the Typetable entry for the current type
	struct Typetable *PDeclType = NULL; //points to the Typetable entry of current parameter type

	char* TypeInfo = NULL;	//for keeping types which are not yet declared(for eg same type or undeclared)

	struct Fieldlist *Fhead = NULL, *Ftail = NULL;	//points to the head and tail of field list of a type

	#include "task1.c"
	extern FILE* yyin;
	int yylex(void); 

#line 90 "y.tab.c"

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
    RETURN = 293,
    TYPE = 294,
    ENDTYPE = 295,
    ALLOC = 296,
    FREE = 297,
    INITIALIZE = 298
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
#define TYPE 294
#define ENDTYPE 295
#define ALLOC 296
#define FREE 297
#define INITIALIZE 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "task1.y"

	struct tnode* node;

#line 223 "y.tab.c"

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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   573

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  250

#define YYUNDEFTOK  2
#define YYMAXUTOK   298

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
      50,    51,     2,     2,    47,     2,    52,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    39,    39,    40,    41,    46,    49,    50,    53,    56,
      57,    60,    65,    66,    67,    82,    83,    84,    95,    96,
      97,   110,   114,   117,   118,   121,   124,   125,   128,   129,
     130,   136,   145,   146,   149,   170,   192,   193,   196,   201,
     202,   205,   206,   209,   212,   213,   220,   254,   259,   269,
     270,   277,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   294,   300,   309,   316,   322,   328,   332,   337,
     345,   352,   366,   375,   381,   388,   394,   400,   408,   419,
     441,   446,   451,   456,   461,   466,   471,   476,   481,   486,
     491,   496,   497,   498,   505,   507,   508,   509,   521,   535,
     540
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
  "CONTINUE", "REPEAT", "UNTIL", "STRING", "RETURN", "TYPE", "ENDTYPE",
  "ALLOC", "FREE", "INITIALIZE", "'{'", "'}'", "';'", "','", "'['", "']'",
  "'('", "')'", "'.'", "$accept", "Program", "TypeDefBlock", "TypeDefList",
  "TypeDef", "FieldDeclList", "FieldDecl", "TypeName", "Type", "ParamType",
  "GDeclBlock", "GDeclList", "GDecl", "GidList", "Gid", "FDefBlock",
  "FDef", "ParamList", "Param", "LDeclBlock", "LDeclList", "LDecl",
  "IDList", "MainBlock", "Body", "SLIST", "RetStmt", "stmt", "asgStmt",
  "inputStmt", "outputStmt", "IfStmt", "WhileStmt", "DoWhileStmt",
  "RepeatStmt", "FIELD", "expr", "ArgList", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   123,   125,    59,    44,    91,    93,
      40,    41,    46
};
# endif

#define YYPACT_NINF -118

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-118)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,    21,    17,    23,    32,    34,    52,  -118,  -118,  -118,
    -118,  -118,    62,   103,  -118,    50,    38,    19,  -118,  -118,
      14,  -118,   -31,   107,  -118,  -118,  -118,    56,   116,  -118,
    -118,    96,   127,  -118,   122,     0,  -118,    62,    79,  -118,
    -118,  -118,    -4,  -118,    99,    88,    17,  -118,  -118,    91,
    -118,  -118,  -118,  -118,   132,    69,  -118,  -118,   158,  -118,
    -118,   141,     4,  -118,  -118,   135,  -118,   113,   152,  -118,
     144,   100,  -118,  -118,   186,   120,  -118,   373,   157,   158,
     159,  -118,   115,  -118,  -118,   167,   168,    15,   182,   171,
     183,   184,   199,   203,    58,   198,   212,   373,   256,  -118,
    -118,  -118,  -118,  -118,  -118,  -118,  -118,     5,  -118,   152,
     158,  -118,   249,   261,    58,    64,    58,   263,    58,   523,
      58,  -118,  -118,   523,  -118,    46,  -118,    58,   226,   402,
     271,   235,   283,  -118,  -118,    65,   274,   257,   152,  -118,
      18,   119,   150,   251,   417,   240,  -118,   165,   301,   180,
     325,    58,    11,   195,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,  -118,   121,   134,   265,  -118,
     253,   440,  -118,  -118,   267,    58,   273,   276,   287,   269,
    -118,   318,   319,   310,   312,   317,   255,  -118,   544,   109,
    -118,   299,   299,   266,   266,   266,   323,   323,   323,   323,
     323,   323,   308,   311,  -118,   313,  -118,  -118,   281,  -118,
    -118,  -118,   320,    58,   523,   315,   523,   324,  -118,    58,
    -118,  -118,  -118,   327,   326,  -118,   455,   349,    58,   475,
      58,   544,  -118,   329,  -118,   523,   330,   210,   332,   225,
    -118,   499,  -118,   335,  -118,   342,   343,  -118,  -118,  -118
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     4,    22,    15,
      16,    17,     0,     0,    24,     0,     0,     0,     7,     1,
       0,     3,    28,     0,    27,    21,    23,     0,     0,     5,
       6,     0,     0,    33,     0,     0,    25,     0,     0,    12,
      13,    14,     0,    10,     0,     0,    15,    32,     2,     0,
      18,    19,    20,    31,     0,     0,    37,    26,     0,     8,
       9,     0,     0,    29,    38,     0,    30,     0,     0,    11,
       0,     0,    36,    40,     0,     0,    42,     0,     0,     0,
       0,    45,     0,    39,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
      52,    53,    54,    55,    56,    57,    58,     0,    46,     0,
       0,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    59,    60,     0,    95,    92,    96,     0,    94,     0,
       0,     0,     0,    50,    48,     0,     0,     0,     0,    44,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,     0,    47,
       0,     0,    79,    35,     0,     0,     0,     0,     0,     0,
      62,     0,     0,     0,     0,     0,     0,    97,   100,     0,
      91,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      90,    89,     0,     0,    61,     0,    64,    34,     0,    69,
      71,    72,     0,     0,     0,     0,     0,     0,    93,     0,
      98,    67,    68,     0,     0,    65,     0,     0,     0,     0,
       0,    99,    66,     0,    63,     0,     0,     0,     0,     0,
      70,     0,    73,     0,    75,     0,     0,    76,    77,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,  -118,  -118,   377,  -118,   348,  -118,   -17,  -118,
     390,  -118,   383,  -118,   360,  -118,   366,   337,   336,   -72,
    -118,   334,  -118,    71,   -98,  -117,   303,   -96,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,   -77,   -71,  -118
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,     5,    17,    18,    42,    43,    44,    12,    54,
       6,    13,    14,    23,    24,    32,    33,    55,    56,    68,
      75,    76,    82,     7,    78,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   128,   129,   189
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     107,   133,   148,    31,    39,    40,   150,   109,    50,    51,
      41,   137,    50,    51,    52,    31,   135,    34,    52,    35,
     107,   124,     9,    10,    15,   125,   115,     8,    11,     9,
      10,     1,    19,    16,     2,    11,   141,    16,   138,     1,
     174,    59,   107,   142,   144,   145,   107,   147,   126,   149,
      74,    53,   133,   167,   133,    70,   153,   136,    74,    29,
       2,   127,   187,   116,   171,     3,   175,   117,   124,   176,
     117,   107,   125,   107,   124,   124,    22,    21,   125,   125,
     186,   188,    28,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   151,   126,   152,   227,   117,   229,
      27,   126,   126,    48,   208,   143,   170,    38,   127,    25,
      45,     9,    10,    61,   127,   127,    65,    11,   241,    73,
      66,     9,    10,    58,    39,    40,    83,    11,     9,    10,
      41,   133,    49,   133,    11,    46,    10,   107,    62,   107,
      63,    11,   226,    50,    51,   133,    64,    65,   231,    52,
     107,    80,   107,    36,    37,    77,   219,   237,   107,   239,
     220,   111,   112,    67,   107,   154,   155,   156,   157,   158,
     177,   136,   202,   117,   159,   160,   161,   162,   163,   164,
     154,   155,   156,   157,   158,   203,   136,    69,    79,   159,
     160,   161,   162,   163,   164,   154,   155,   156,   157,   158,
      81,   178,   108,   110,   159,   160,   161,   162,   163,   164,
     154,   155,   156,   157,   158,   119,   182,   113,   114,   159,
     160,   161,   162,   163,   164,   154,   155,   156,   157,   158,
     121,   184,   118,   120,   159,   160,   161,   162,   163,   164,
     154,   155,   156,   157,   158,   122,   190,   123,   130,   159,
     160,   161,   162,   163,   164,   154,   155,   156,   157,   158,
     134,   243,   131,   139,   159,   160,   161,   162,   163,   164,
     154,   155,   156,   157,   158,   140,   245,   146,   136,   159,
     160,   161,   162,   163,   164,   166,   168,   169,   172,   181,
     159,   160,   161,   162,   163,   164,   154,   155,   156,   157,
     158,   179,   173,   205,   218,   159,   160,   161,   162,   163,
     164,   204,   207,    85,    86,    87,   156,   157,   158,   209,
     212,    88,   210,   159,   160,   161,   162,   163,   164,   213,
     224,    89,    90,   211,    91,    92,    93,    85,    86,    87,
     214,   215,   216,    95,    96,    88,   183,    -1,    -1,    -1,
      -1,    -1,    -1,   217,   221,    89,    90,   222,    91,    92,
      93,    85,    86,    87,   223,   228,   225,    95,    96,    88,
     185,   235,   236,   232,   230,   240,   242,   233,   244,    89,
      90,   247,    91,    92,    93,    85,    86,    87,   248,   249,
      60,    95,    96,    88,    30,    20,    26,    57,    47,    71,
     132,    72,     0,    89,    90,     0,    91,    92,    93,    84,
       0,    94,     0,     0,     0,    95,    96,   154,   155,   156,
     157,   158,     0,     0,     0,     0,   159,   160,   161,   162,
     163,   164,   154,   155,   156,   157,   158,     0,     0,     0,
       0,   159,   160,   161,   162,   163,   164,     0,   165,     0,
       0,     0,     0,     0,     0,   154,   155,   156,   157,   158,
       0,     0,     0,   180,   159,   160,   161,   162,   163,   164,
     154,   155,   156,   157,   158,     0,     0,     0,     0,   159,
     160,   161,   162,   163,   164,     0,   206,    85,    86,    87,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
       0,   234,     0,     0,     0,    89,    90,   238,    91,    92,
      93,    85,    86,    87,     0,     0,     0,    95,    96,    88,
       0,     0,   246,     0,     0,     0,     0,     0,     0,    89,
      90,     0,    91,    92,    93,    85,    86,    87,     0,     0,
       0,    95,    96,    88,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,     0,    91,    92,    93,   154,
     155,   156,   157,   158,     0,    95,    96,     0,   159,   160,
     161,   162,   163,   164
};

static const yytype_int16 yycheck[] =
{
      77,    97,   119,    20,     8,     9,   123,    79,     8,     9,
      14,   109,     8,     9,    14,    32,    11,    48,    14,    50,
      97,    10,     8,     9,     7,    14,    11,     6,    14,     8,
       9,     5,     0,    14,     8,    14,   113,    14,   110,     5,
     138,    45,   119,   114,   115,   116,   123,   118,    37,   120,
      67,    51,   148,   130,   150,    51,   127,    52,    75,    40,
       8,    50,    51,    48,   135,    39,    48,    52,    10,    51,
      52,   148,    14,   150,    10,    10,    14,     6,    14,    14,
     151,   152,    44,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,    48,    37,    50,   214,    52,   216,
      50,    37,    37,    32,   175,    41,    41,    51,    50,     6,
      14,     8,     9,    14,    50,    50,    47,    14,   235,     6,
      51,     8,     9,    44,     8,     9,     6,    14,     8,     9,
      14,   227,    10,   229,    14,     8,     9,   214,    50,   216,
      49,    14,   213,     8,     9,   241,    14,    47,   219,    14,
     227,    51,   229,    46,    47,     3,    47,   228,   235,   230,
      51,    46,    47,     5,   241,    15,    16,    17,    18,    19,
      51,    52,    51,    52,    24,    25,    26,    27,    28,    29,
      15,    16,    17,    18,    19,    51,    52,    46,    44,    24,
      25,    26,    27,    28,    29,    15,    16,    17,    18,    19,
      14,    51,    45,    44,    24,    25,    26,    27,    28,    29,
      15,    16,    17,    18,    19,    44,    51,    50,    50,    24,
      25,    26,    27,    28,    29,    15,    16,    17,    18,    19,
      46,    51,    50,    50,    24,    25,    26,    27,    28,    29,
      15,    16,    17,    18,    19,    46,    51,    44,    50,    24,
      25,    26,    27,    28,    29,    15,    16,    17,    18,    19,
       4,    51,    50,    14,    24,    25,    26,    27,    28,    29,
      15,    16,    17,    18,    19,    14,    51,    14,    52,    24,
      25,    26,    27,    28,    29,    14,    51,     4,    14,    49,
      24,    25,    26,    27,    28,    29,    15,    16,    17,    18,
      19,    50,    45,    50,    49,    24,    25,    26,    27,    28,
      29,    46,    45,    12,    13,    14,    17,    18,    19,    46,
      51,    20,    46,    24,    25,    26,    27,    28,    29,    11,
      49,    30,    31,    46,    33,    34,    35,    12,    13,    14,
      21,    31,    30,    42,    43,    20,    45,    24,    25,    26,
      27,    28,    29,    36,    46,    30,    31,    46,    33,    34,
      35,    12,    13,    14,    51,    50,    46,    42,    43,    20,
      45,    22,    23,    46,    50,    46,    46,    51,    46,    30,
      31,    46,    33,    34,    35,    12,    13,    14,    46,    46,
      42,    42,    43,    20,    17,     5,    13,    37,    32,    62,
      97,    65,    -1,    30,    31,    -1,    33,    34,    35,    75,
      -1,    38,    -1,    -1,    -1,    42,    43,    15,    16,    17,
      18,    19,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      28,    29,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    46,    24,    25,    26,    27,    28,    29,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    -1,    46,    12,    13,    14,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    12,    13,    14,    -1,    -1,    -1,    42,    43,    20,
      -1,    -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    33,    34,    35,    12,    13,    14,    -1,    -1,
      -1,    42,    43,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,    15,
      16,    17,    18,    19,    -1,    42,    43,    -1,    24,    25,
      26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     8,    39,    54,    55,    63,    76,     6,     8,
       9,    14,    61,    64,    65,     7,    14,    56,    57,     0,
      63,    76,    14,    66,    67,     6,    65,    50,    44,    40,
      57,    61,    68,    69,    48,    50,    46,    47,    51,     8,
       9,    14,    58,    59,    60,    14,     8,    69,    76,    10,
       8,     9,    14,    51,    62,    70,    71,    67,    44,    45,
      59,    14,    50,    49,    14,    47,    51,     5,    72,    46,
      51,    70,    71,     6,    61,    73,    74,     3,    77,    44,
      51,    14,    75,     6,    74,    12,    13,    14,    20,    30,
      31,    33,    34,    35,    38,    42,    43,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    45,    72,
      44,    46,    47,    50,    50,    11,    48,    52,    50,    44,
      50,    46,    46,    44,    10,    14,    37,    50,    88,    89,
      50,    50,    79,    80,     4,    11,    52,    77,    72,    14,
      14,    88,    89,    41,    89,    89,    14,    89,    78,    89,
      78,    48,    50,    89,    15,    16,    17,    18,    19,    24,
      25,    26,    27,    28,    29,    46,    14,    88,    51,     4,
      41,    89,    14,    45,    77,    48,    51,    51,    51,    50,
      46,    49,    51,    45,    51,    45,    89,    51,    89,    90,
      51,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    51,    51,    46,    50,    46,    45,    89,    46,
      46,    46,    51,    11,    21,    31,    30,    36,    49,    47,
      51,    46,    46,    51,    49,    46,    89,    78,    50,    78,
      50,    89,    46,    51,    46,    22,    23,    89,    32,    89,
      46,    78,    46,    51,    46,    51,    23,    46,    46,    46
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    56,    56,    57,    58,
      58,    59,    60,    60,    60,    61,    61,    61,    62,    62,
      62,    63,    63,    64,    64,    65,    66,    66,    67,    67,
      67,    67,    68,    68,    69,    69,    70,    70,    71,    72,
      72,    73,    73,    74,    75,    75,    76,    77,    77,    78,
      78,    79,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    81,    81,    81,    81,    81,    82,
      82,    82,    83,    84,    84,    85,    86,    87,    88,    88,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    90,
      90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     1,     3,     2,     1,     4,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     1,     3,     3,     1,     1,     4,
       4,     3,     2,     1,     9,     8,     3,     1,     2,     3,
       2,     2,     1,     3,     3,     1,     8,     4,     3,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     4,     4,     7,     4,     6,     6,     5,     5,     5,
       8,     5,     5,     8,    10,     8,     9,     9,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     4,     1,     1,     1,     3,     4,     3,
       1
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
#line 46 "task1.y"
    {PrintTypetable();}
#line 1546 "y.tab.c"
    break;

  case 8:
#line 53 "task1.y"
    {TInstall((yyvsp[-3].node)->varname,0,Fhead);}
#line 1552 "y.tab.c"
    break;

  case 11:
#line 60 "task1.y"
    {
								FieldInstall(DeclType,(yyvsp[-1].node)->varname);
							}
#line 1560 "y.tab.c"
    break;

  case 12:
#line 65 "task1.y"
    {DeclType = TLookup("int");}
#line 1566 "y.tab.c"
    break;

  case 13:
#line 66 "task1.y"
    {DeclType = TLookup("string");}
#line 1572 "y.tab.c"
    break;

  case 14:
#line 67 "task1.y"
    {
					DeclType = TLookup((yyvsp[0].node)->varname);

					if(DeclType == NULL)	//type maybe undeclared or of the same type as the current user-defined type
					{
						DeclType = TLookup("dummy");
						TypeInfo = malloc(sizeof((yyvsp[0].node)->varname));
						strcpy(TypeInfo,(yyvsp[0].node)->varname);
					}
				}
#line 1587 "y.tab.c"
    break;

  case 15:
#line 82 "task1.y"
    {DeclType = TLookup("int");}
#line 1593 "y.tab.c"
    break;

  case 16:
#line 83 "task1.y"
    {DeclType = TLookup("string");}
#line 1599 "y.tab.c"
    break;

  case 17:
#line 84 "task1.y"
    {
				DeclType = TLookup((yyvsp[0].node)->varname);

				if(DeclType == NULL)
				{
					printf("%s type does not exist\n",(yyvsp[0].node)->varname);
					exit(1);
				}
			}
#line 1613 "y.tab.c"
    break;

  case 18:
#line 95 "task1.y"
    {PDeclType = TLookup("int");}
#line 1619 "y.tab.c"
    break;

  case 19:
#line 96 "task1.y"
    {PDeclType = TLookup("string");}
#line 1625 "y.tab.c"
    break;

  case 20:
#line 97 "task1.y"
    {
					PDeclType = TLookup((yyvsp[0].node)->varname);
					if(!PDeclType)
					{
						printf("%s type not declared\n",(yyvsp[0].node)->varname);
						exit(1);
					}
				}
#line 1638 "y.tab.c"
    break;

  case 21:
#line 110 "task1.y"
    {	
										GenerateHeader();
										PrintSymbolTable();
									}
#line 1647 "y.tab.c"
    break;

  case 28:
#line 128 "task1.y"
    {Install((yyvsp[0].node)->varname,DeclType,0,1);}
#line 1653 "y.tab.c"
    break;

  case 29:
#line 129 "task1.y"
    {Install((yyvsp[-3].node)->varname,DeclType,1,(yyvsp[-1].node)->val);}
#line 1659 "y.tab.c"
    break;

  case 30:
#line 130 "task1.y"
    {
								Install((yyvsp[-3].node)->varname,DeclType,2,1);
							  	InsertParamList((yyvsp[-3].node)->varname);
							  	clearParamList();	
							}
#line 1669 "y.tab.c"
    break;

  case 31:
#line 136 "task1.y"
    {	
								Install((yyvsp[-2].node)->varname,DeclType,2,1);
								InsertParamList((yyvsp[-2].node)->varname);
								clearParamList();   
						   	}
#line 1679 "y.tab.c"
    break;

  case 34:
#line 150 "task1.y"
    {
			CheckIfFunction((yyvsp[-7].node)->varname);
			CheckReturnType((yyvsp[-7].node)->varname,DeclType);
			CheckReturnVal((yyvsp[-1].node)->right,DeclType);
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
#line 1703 "y.tab.c"
    break;

  case 35:
#line 171 "task1.y"
    { 
			CheckIfFunction((yyvsp[-6].node)->varname);
			CheckReturnType((yyvsp[-6].node)->varname,DeclType);
			CheckReturnVal((yyvsp[-1].node)->right,DeclType);
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
#line 1727 "y.tab.c"
    break;

  case 38:
#line 196 "task1.y"
    {
							InsertParam((yyvsp[0].node)->varname,PDeclType);
						}
#line 1735 "y.tab.c"
    break;

  case 44:
#line 212 "task1.y"
    {InsertLocalSymbol((yyvsp[0].node)->varname,DeclType);}
#line 1741 "y.tab.c"
    break;

  case 45:
#line 213 "task1.y"
    {InsertLocalSymbol((yyvsp[0].node)->varname,DeclType);}
#line 1747 "y.tab.c"
    break;

  case 46:
#line 220 "task1.y"
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
#line 1780 "y.tab.c"
    break;

  case 47:
#line 255 "task1.y"
    {
			(yyval.node) = createTree(0,NULL,connector_node,TLookup("void"),NULL,(yyvsp[-2].node),(yyvsp[-1].node),NULL);
		}
#line 1788 "y.tab.c"
    break;

  case 48:
#line 260 "task1.y"
    {
			(yyval.node) = createTree(0,NULL,connector_node,TLookup("void"),NULL,(yyvsp[-1].node),NULL,NULL);
		}
#line 1796 "y.tab.c"
    break;

  case 49:
#line 269 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1802 "y.tab.c"
    break;

  case 50:
#line 270 "task1.y"
    {(yyval.node) = createTree(0,NULL,connector_node,TLookup("void"),NULL,(yyvsp[-1].node),(yyvsp[0].node),NULL);}
#line 1808 "y.tab.c"
    break;

  case 51:
#line 277 "task1.y"
    {(yyval.node) = createTree(0,NULL,return_node,(yyvsp[-1].node)->ttype,NULL,(yyvsp[-1].node),NULL,NULL);}
#line 1814 "y.tab.c"
    break;

  case 52:
#line 282 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1820 "y.tab.c"
    break;

  case 53:
#line 283 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1826 "y.tab.c"
    break;

  case 54:
#line 284 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1832 "y.tab.c"
    break;

  case 55:
#line 285 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1838 "y.tab.c"
    break;

  case 56:
#line 286 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1844 "y.tab.c"
    break;

  case 57:
#line 287 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1850 "y.tab.c"
    break;

  case 58:
#line 288 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 1856 "y.tab.c"
    break;

  case 59:
#line 289 "task1.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 1862 "y.tab.c"
    break;

  case 60:
#line 290 "task1.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 1868 "y.tab.c"
    break;

  case 61:
#line 291 "task1.y"
    {(yyval.node) = (yyvsp[-3].node);}
#line 1874 "y.tab.c"
    break;

  case 62:
#line 294 "task1.y"
    {		
											checkID((yyvsp[-3].node)->varname);    
											AssignCheckType((yyvsp[-3].node),(yyvsp[-1].node));
											(yyval.node) = createTree(0,NULL,assign_node,TLookup("void"),NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
										}
#line 1884 "y.tab.c"
    break;

  case 63:
#line 301 "task1.y"
    {
											checkID((yyvsp[-6].node)->varname);
											CheckIfArray((yyvsp[-6].node)->varname);
											CheckIntType((yyvsp[-4].node));
											AssignCheckType((yyvsp[-6].node),(yyvsp[-1].node));
											(yyval.node) = createTree(0,NULL,assignArray_node,TLookup("void"),NULL,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-1].node));
										}
#line 1896 "y.tab.c"
    break;

  case 64:
#line 309 "task1.y"
    {		
											//checkID($1->varname);    
											//AssignCheckType($1,$3);
											(yyval.node) = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
										}
#line 1906 "y.tab.c"
    break;

  case 65:
#line 316 "task1.y"
    {
											struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL);

											(yyval.node) = createTree(0,NULL,assign_node,TLookup("void"),NULL,(yyvsp[-5].node),tmp,NULL);
										}
#line 1916 "y.tab.c"
    break;

  case 66:
#line 322 "task1.y"
    {
												struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL);

												(yyval.node) = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,(yyvsp[-5].node),tmp,NULL);
											}
#line 1926 "y.tab.c"
    break;

  case 67:
#line 328 "task1.y"
    {
											(yyval.node) = createTree(0,NULL,free_node,TLookup("void"),NULL,(yyvsp[-2].node),NULL,NULL);
										}
#line 1934 "y.tab.c"
    break;

  case 68:
#line 332 "task1.y"
    {
											(yyval.node) = createTree(0,NULL,free_node,TLookup("void"),NULL,(yyvsp[-2].node),NULL,NULL);
										}
#line 1942 "y.tab.c"
    break;

  case 69:
#line 338 "task1.y"
    {
									checkID((yyvsp[-2].node)->varname);
									MatchType((yyvsp[-2].node),var_node);

									(yyval.node) = createTree(0,NULL,read_node,TLookup("void"),NULL,(yyvsp[-2].node),NULL,NULL);
								}
#line 1953 "y.tab.c"
    break;

  case 70:
#line 346 "task1.y"
    {	
									checkID((yyvsp[-5].node)->varname);
									CheckIfArray((yyvsp[-5].node)->varname);
									CheckIntType((yyvsp[-3].node));
									(yyval.node) = createTree(0,NULL,readArray_node,TLookup("void"),NULL,(yyvsp[-5].node),(yyvsp[-3].node),NULL);
								}
#line 1964 "y.tab.c"
    break;

  case 71:
#line 353 "task1.y"
    {
									if((yyvsp[-2].node)->ttype == TLookup("int") || (yyvsp[-2].node)->ttype == TLookup("string"))
									{
										(yyval.node) = createTree(0,NULL,read_field_node,TLookup("void"),NULL,(yyvsp[-2].node),NULL,NULL);
									}
									else
									{
										yyerror("Error : cannot be read\n");
										exit(1);
									}
								}
#line 1980 "y.tab.c"
    break;

  case 72:
#line 367 "task1.y"
    {
							if((yyvsp[-2].node)->ttype != TLookup("int") && (yyvsp[-2].node)->ttype != TLookup("string"))
							{
								printf("Incorrect type in write\n");
							}
							(yyval.node) = createTree(0,NULL,write_node,TLookup("void"),NULL,(yyvsp[-2].node),NULL,NULL);
						}
#line 1992 "y.tab.c"
    break;

  case 73:
#line 376 "task1.y"
    {
							CheckBoolType((yyvsp[-5].node));
							(yyval.node) = createTree(0,NULL,if_node,TLookup("void"),NULL,(yyvsp[-5].node),(yyvsp[-2].node),NULL);
						}
#line 2001 "y.tab.c"
    break;

  case 74:
#line 382 "task1.y"
    {
							CheckBoolType((yyvsp[-7].node));
							(yyval.node) = createTree(0,NULL,ifElse_node,TLookup("void"),NULL,(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node));
						}
#line 2010 "y.tab.c"
    break;

  case 75:
#line 389 "task1.y"
    {	
							CheckBoolType((yyvsp[-5].node));
							(yyval.node) = createTree(0,NULL,while_node,TLookup("void"),NULL,(yyvsp[-5].node),(yyvsp[-2].node),NULL);
						}
#line 2019 "y.tab.c"
    break;

  case 76:
#line 395 "task1.y"
    {
							CheckBoolType((yyvsp[-2].node));
							(yyval.node) = createTree(0,NULL,Dowhile_node,TLookup("void"),NULL,(yyvsp[-2].node),(yyvsp[-6].node),NULL);
						}
#line 2028 "y.tab.c"
    break;

  case 77:
#line 401 "task1.y"
    {			
							CheckBoolType((yyvsp[-2].node));
							(yyval.node) = createTree(0,NULL,repeat_node,TLookup("void"),NULL,(yyvsp[-2].node),(yyvsp[-6].node),NULL);
						}
#line 2037 "y.tab.c"
    break;

  case 78:
#line 408 "task1.y"
    {
							struct Fieldlist* tmp = FLookup((yyvsp[-2].node)->ttype,(yyvsp[0].node)->varname);
							if(!tmp)
							{
								printf("Error : %s does not belongs to %s\n",(yyvsp[0].node)->varname,(yyvsp[-2].node)->ttype->name);
								exit(1);
							}

							(yyval.node) = createTree(0,NULL,field_node,tmp->type,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2052 "y.tab.c"
    break;

  case 79:
#line 419 "task1.y"
    {
								struct Fieldlist* tmp = FLookup((yyvsp[-2].node)->ttype,(yyvsp[0].node)->varname);
								if(!tmp)
								{
									printf("Error : %s does not belongs to %s\n",(yyvsp[0].node)->varname,(yyvsp[-2].node)->ttype->name);
									exit(1);
								}

								struct tnode* tmp_new = createTree(0,NULL,field_node,TLookup("void"),NULL,NULL,(yyvsp[0].node),NULL);	
								struct tnode* tmp1 = (yyvsp[-2].node);
								while(tmp1 -> mid)
								{
									tmp1 = tmp1 -> mid;	
								} 
								tmp1 -> mid = tmp_new;
								tmp1 -> ttype = tmp -> type;

								(yyval.node) = (yyvsp[-2].node);
							}
#line 2076 "y.tab.c"
    break;

  case 80:
#line 441 "task1.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,plus_node,TLookup("int"),NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2085 "y.tab.c"
    break;

  case 81:
#line 446 "task1.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,minus_node,TLookup("int"),NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2094 "y.tab.c"
    break;

  case 82:
#line 451 "task1.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,mul_node,TLookup("int"),NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2103 "y.tab.c"
    break;

  case 83:
#line 456 "task1.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,div_node,TLookup("int"),NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2112 "y.tab.c"
    break;

  case 84:
#line 461 "task1.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,mod_node,TLookup("int"),NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2121 "y.tab.c"
    break;

  case 85:
#line 466 "task1.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,lt_node,TLookup("bool"),NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2130 "y.tab.c"
    break;

  case 86:
#line 471 "task1.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,gt_node,TLookup("bool"),NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2139 "y.tab.c"
    break;

  case 87:
#line 476 "task1.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,eq_node,TLookup("bool"),NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2148 "y.tab.c"
    break;

  case 88:
#line 481 "task1.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
						   	(yyval.node) = createTree(0,NULL,neq_node,TLookup("bool"),NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2157 "y.tab.c"
    break;

  case 89:
#line 486 "task1.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,lte_node,TLookup("bool"),NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2166 "y.tab.c"
    break;

  case 90:
#line 491 "task1.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,gte_node,TLookup("bool"),NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2175 "y.tab.c"
    break;

  case 91:
#line 496 "task1.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 2181 "y.tab.c"
    break;

  case 92:
#line 497 "task1.y"
    {checkID((yyvsp[0].node)->varname); (yyval.node) = (yyvsp[0].node);}
#line 2187 "y.tab.c"
    break;

  case 93:
#line 498 "task1.y"
    {
							checkID((yyvsp[-3].node)->varname); 
							CheckIfArray((yyvsp[-3].node)->varname);
							CheckIntType((yyvsp[-1].node));
							(yyval.node) = createTree(0,NULL,array_node,(yyvsp[-3].node)->ttype,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
						}
#line 2198 "y.tab.c"
    break;

  case 94:
#line 505 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2204 "y.tab.c"
    break;

  case 95:
#line 507 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2210 "y.tab.c"
    break;

  case 96:
#line 508 "task1.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2216 "y.tab.c"
    break;

  case 97:
#line 509 "task1.y"
    {	
								checkID((yyvsp[-2].node)->varname);
								CheckIfFunction((yyvsp[-2].node)->varname);
								struct Gsymbol* idx = Lookup2((yyvsp[-2].node)->varname);

								(yyval.node) = createTree(0,NULL,function_node,idx->type,idx->name,(yyvsp[-2].node),NULL,NULL);

						   		CheckInformalParamList((yyval.node));
									
								(yyval.node) -> Arglist = NULL;	
							}
#line 2232 "y.tab.c"
    break;

  case 98:
#line 522 "task1.y"
    {
									checkID((yyvsp[-3].node)->varname);
									CheckIfFunction((yyvsp[-3].node)->varname);
									struct Gsymbol* idx = Lookup2((yyvsp[-3].node)->varname);

						   			(yyval.node) = createTree(0,NULL,function_node,idx->type,idx->name,(yyvsp[-3].node),(yyvsp[-1].node),NULL);

						   			CheckInformalParamList((yyval.node));

									(yyval.node) -> Arglist = (yyvsp[-1].node);
								}
#line 2248 "y.tab.c"
    break;

  case 99:
#line 536 "task1.y"
    {
									(yyval.node) = createTree(0,NULL,arg_node,-1,NULL,(yyvsp[0].node),(yyvsp[-2].node),NULL);
								}
#line 2256 "y.tab.c"
    break;

  case 100:
#line 540 "task1.y"
    {
									(yyval.node) = createTree(0,NULL,arg_node,-1,NULL,(yyvsp[0].node),NULL,NULL);
								}
#line 2264 "y.tab.c"
    break;


#line 2268 "y.tab.c"

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
#line 545 "task1.y"


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

   	fp = fopen("/home/shrey/xsm_expl/progs/stage6/input.xsm","w");
   	fp_read = fopen("input.txt","r");
  	yyin = fp_read;

	InitTypeTable();
   	yyparse();

   	return 0;
}
