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
#line 1 "task.y"
	
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include "task.h"
	FILE *fp, *fp1;
	FILE *fp_read;
	struct Typetable *Thead = NULL, *Ttail = NULL;	//points to the head and tail of Typetable list
	struct Typetable *DeclType = NULL;	//points to the Typetable entry for the current type
	struct Typetable *PDeclType = NULL; //points to the Typetable entry of current parameter type
	struct Typetable *FuncType = NULL;	//return type of a function

	char* TypeInfo = NULL;	//for keeping types which are not yet declared(for eg same type or undeclared)

	struct Fieldlist *Fhead = NULL, *Ftail = NULL;	//points to the head/tail of field list of a type/class
	struct Classtable *Chead = NULL,*Ctail = NULL;	//points to the head/tail of class table list
	struct Classtable* class = NULL;
	struct Classtable* DeclClass = NULL;
	struct Memberfunclist *Mfhead = NULL, *Mftail = NULL;  //points to head/tail of func list of class	
	int class_idx = 0;	//to keep track of class indices
	int final_installation = 0;

	#include "task.c"
	extern FILE* yyin;
	int yylex(void); 

#line 97 "y.tab.c"

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
    INITIALIZE = 298,
    SENTINEL = 299,
    CLASS = 300,
    ENDCLASS = 301,
    SELF = 302,
    NEW = 303,
    DELETE = 304,
    EXTENDS = 305
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
#define SENTINEL 299
#define CLASS 300
#define ENDCLASS 301
#define SELF 302
#define NEW 303
#define DELETE 304
#define EXTENDS 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 29 "task.y"

	struct tnode* node;

#line 244 "y.tab.c"

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
#define YYLAST   619

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  324

#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      54,    55,     2,     2,    56,     2,    59,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    46,    46,    47,    48,    49,    50,    51,    52,    57,
      60,    61,    64,    67,    68,    71,    76,    77,    78,    92,
      93,    96,    97,   100,   114,   120,   121,   124,   130,   131,
     134,   154,   176,   177,   184,   189,   194,   207,   208,   209,
     222,   226,   229,   230,   233,   236,   237,   240,   241,   252,
     265,   283,   284,   285,   296,   297,   300,   348,   395,   396,
     399,   404,   406,   408,   411,   412,   415,   418,   419,   426,
     460,   465,   475,   476,   483,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   500,   506,   515,   522,   528,
     534,   563,   583,   587,   592,   607,   614,   628,   638,   644,
     651,   657,   663,   671,   684,   705,   737,   769,   800,   816,
     821,   826,   831,   836,   841,   846,   851,   856,   861,   866,
     871,   872,   873,   880,   881,   882,   883,   884,   886,   900,
     905,   909
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
  "ALLOC", "FREE", "INITIALIZE", "SENTINEL", "CLASS", "ENDCLASS", "SELF",
  "NEW", "DELETE", "EXTENDS", "'{'", "'}'", "';'", "'('", "')'", "','",
  "'['", "']'", "'.'", "$accept", "Program", "TypeDefBlock", "TypeDefList",
  "TypeDef", "FieldDeclList", "FieldDecl", "TypeName", "ClassDefBlock",
  "ClassDefList", "ClassDef", "Cname", "CFieldlists", "CField",
  "CMethodDecls", "MethodDecl", "CMethodDefns", "Type", "ParamType",
  "GDeclBlock", "GDeclList", "GDecl", "GidList", "Gid", "ReturnType",
  "FDefBlock", "FDef", "ParamList", "Param", "LDeclBlock", "LDeclList",
  "LDecl", "IDList", "MainBlock", "Body", "SLIST", "RetStmt", "stmt",
  "asgStmt", "inputStmt", "outputStmt", "IfStmt", "WhileStmt",
  "DoWhileStmt", "RepeatStmt", "FIELD", "FieldFunction", "expr", "ArgList", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   123,   125,    59,    40,    41,    44,    91,    93,    46
};
# endif

#define YYPACT_NINF -166

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-166)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -32,    -3,     8,    36,    19,   163,    30,     2,  -166,  -166,
      24,  -166,    39,  -166,   108,   133,    88,    80,  -166,   140,
    -166,  -166,  -166,  -166,    92,    88,  -166,  -166,    80,    96,
      80,  -166,  -166,  -166,  -166,  -166,  -166,   101,   270,  -166,
      73,    80,  -166,  -166,  -166,  -166,    10,  -166,   137,   155,
      80,  -166,    99,  -166,  -166,   121,   124,  -166,  -166,  -166,
     105,  -166,  -166,  -166,   113,   155,  -166,   168,  -166,    21,
      23,   176,  -166,   101,   160,  -166,  -166,   282,  -166,   170,
     159,  -166,  -166,  -166,   172,   215,    -9,  -166,  -166,    89,
     181,  -166,   241,   260,  -166,   235,   156,  -166,   241,  -166,
     222,   284,  -166,  -166,   462,   257,  -166,    60,  -166,   223,
      31,   257,   241,  -166,  -166,   267,   494,  -166,   476,   237,
    -166,  -166,   244,   164,   250,   257,  -166,   132,  -166,  -166,
     249,   256,    -2,   258,   262,   271,   273,   274,   277,   118,
     281,   288,   285,   476,   307,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,    -1,  -166,  -166,   283,  -166,   291,  -166,
     343,    -6,   118,    77,   118,   344,   118,   557,   118,  -166,
    -166,   557,  -166,    25,  -166,  -166,   300,   118,   308,  -166,
     386,     1,   313,   360,   371,  -166,  -166,    82,   362,  -166,
    -166,  -166,    78,    12,   290,   335,   336,   401,   174,  -166,
     305,   228,   322,   252,   118,   118,   377,   385,   337,   392,
     118,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,  -166,    18,    79,   347,  -166,  -166,   353,   367,   416,
    -166,   355,   118,   370,   383,   382,   408,  -166,   427,   430,
     421,   423,   425,   590,   166,   189,   409,   413,  -166,   419,
     226,   226,   505,   505,   505,   569,   569,   569,   569,   569,
     569,   424,   426,  -166,   407,   464,  -166,  -166,   209,  -166,
    -166,   428,   436,   118,   557,   438,   557,   439,  -166,   118,
    -166,   118,   118,   118,  -166,  -166,   444,   443,   446,  -166,
     451,   431,   452,   118,   508,   118,   590,   175,   201,   245,
    -166,   459,   460,  -166,  -166,   557,   463,   354,   471,   369,
    -166,  -166,  -166,  -166,  -166,   533,  -166,   472,  -166,   473,
     474,  -166,  -166,  -166
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      20,     0,     0,     0,    20,     0,     0,     0,    11,    24,
       0,    22,     0,     1,     0,     0,     0,     0,     8,     0,
       9,    10,    19,    21,     0,    51,    52,    53,     0,     0,
       0,    55,     6,    41,    34,    35,    36,     0,     0,    43,
       0,     0,     7,    16,    17,    18,     0,    14,     0,     0,
       0,     5,     0,    54,     4,    47,     0,    46,    40,    42,
       0,     3,    12,    13,     0,     0,    26,     0,     2,     0,
       0,     0,    44,     0,     0,    15,    25,     0,    29,     0,
       0,    37,    38,    39,     0,     0,     0,    59,    50,     0,
       0,    45,    63,     0,    28,     0,     0,    27,    63,    60,
       0,     0,    49,    48,     0,     0,    51,     0,    33,     0,
       0,     0,    63,    58,    62,     0,     0,    65,     0,     0,
      23,    32,     0,     0,     0,     0,    68,     0,    61,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,    75,    76,    77,    78,
      79,    80,    81,     0,    69,    31,     0,    57,     0,    66,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
      83,     0,   126,   121,   127,   125,     0,     0,   123,   124,
       0,     0,     0,     0,     0,    73,    71,     0,     0,    30,
      56,    67,     0,     0,     0,     0,     0,     0,     0,   103,
       0,     0,     0,     0,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,     0,     0,     0,   105,    70,     0,     0,     0,
     104,     0,     0,     0,     0,     0,     0,    85,     0,     0,
       0,     0,     0,   130,     0,     0,   103,   105,   120,   104,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   119,
     118,     0,     0,    84,     0,     0,    87,    94,     0,    96,
      97,     0,     0,     0,     0,     0,     0,     0,   128,     0,
     122,   131,   131,   131,    92,    93,     0,     0,     0,    88,
       0,     0,     0,     0,     0,     0,   129,     0,     0,     0,
      89,     0,     0,    90,    86,     0,     0,     0,     0,     0,
     107,   106,   108,    91,    95,     0,    98,     0,   100,     0,
       0,   101,   102,    99
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,  -166,   498,  -166,   434,  -166,   511,  -166,
     507,  -166,  -166,   470,  -166,   467,  -166,   -44,  -166,   522,
    -166,   499,  -166,   475,  -166,     0,   -27,   -66,   448,   -86,
    -166,   441,  -166,   129,   -91,  -165,   411,  -142,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -118,  -166,  -112,   -87
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     7,     8,    46,    47,    48,     5,    10,
      11,    12,    65,    66,    77,    78,   107,    37,    85,    17,
      38,    39,    56,    57,    29,    30,    31,    86,    87,   105,
     116,   117,   127,    18,   119,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   178,   179,   243,   244
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     153,   185,   201,    53,    89,    67,   203,     1,   192,   163,
     187,     6,   111,     2,    53,   222,     6,    41,    43,    44,
     124,    79,     9,    53,    45,   153,   125,   180,    50,    81,
      82,    81,    82,    95,   158,    83,    13,    83,     9,    81,
      82,   142,    20,   193,   123,    83,   100,   101,   142,   153,
     194,   197,   198,   153,   200,   164,   202,   165,   188,   185,
     115,   185,    62,   223,     2,   208,   108,   233,   106,    26,
      22,   188,   115,   261,    27,   229,    84,   165,    88,   204,
     121,    19,   205,   153,   206,   153,   122,   172,    25,    26,
      24,   173,   172,   245,    27,    40,   173,    49,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   292,
      52,   294,   120,    15,   174,    55,    25,    26,   195,   174,
     268,   175,    27,   227,   176,   196,   175,    60,   172,   176,
     228,   177,   173,   231,   262,   232,   177,   165,   188,    33,
     315,    34,    35,    32,   102,   101,    42,    36,    43,    44,
     185,    64,   185,    69,    45,   174,   153,    51,   153,    54,
      74,   291,   175,    34,    35,   176,    75,   296,    15,    36,
      61,    16,   177,   185,   153,    70,   153,    72,    71,    68,
      73,   307,    80,   309,    96,   159,    90,   153,   160,   210,
     211,   212,   213,   214,   297,   298,   299,   153,   215,   216,
     217,   218,   219,   220,   210,   211,   212,   213,   214,    97,
     110,    92,    97,   215,   216,   217,   218,   219,   220,   156,
     101,   278,   279,    98,   210,   211,   212,   213,   214,    99,
     310,   279,   238,   215,   216,   217,   218,   219,   220,   103,
     130,   131,   132,   212,   213,   214,   104,   280,   133,   109,
     215,   216,   217,   218,   219,   220,   311,   279,   134,   135,
     118,   136,   137,   138,   130,   131,   132,   288,   106,    26,
     140,   141,   133,   112,    27,   142,    58,   110,    34,    35,
     240,   126,   134,   135,    36,   136,   137,   138,    93,   154,
      34,    35,    81,    82,   140,   141,    36,   155,    83,   142,
     312,   279,   157,   161,   242,   210,   211,   212,   213,   214,
     162,   186,   166,   167,   215,   216,   217,   218,   219,   220,
     210,   211,   212,   213,   214,   168,   169,   170,   171,   215,
     216,   217,   218,   219,   220,   181,   189,   210,   211,   212,
     213,   214,   182,   190,   183,   234,   215,   216,   217,   218,
     219,   220,   210,   211,   212,   213,   214,   191,   199,   207,
     239,   215,   216,   217,   218,   219,   220,   209,   224,   210,
     211,   212,   213,   214,   225,   226,   230,   241,   215,   216,
     217,   218,   219,   220,   210,   211,   212,   213,   214,   235,
     236,   246,   248,   215,   216,   217,   218,   219,   220,   247,
     263,   210,   211,   212,   213,   214,   249,   264,   267,   317,
     215,   216,   217,   218,   219,   220,   210,   211,   212,   213,
     214,   265,   272,   269,   319,   215,   216,   217,   218,   219,
     220,   210,   211,   212,   213,   214,   270,   271,   273,   221,
     215,   216,   217,   218,   219,   220,   210,   211,   212,   213,
     214,   274,   275,   276,   237,   215,   216,   217,   218,   219,
     220,   277,   286,   281,   130,   131,   132,   282,   114,   266,
      34,    35,   133,   283,   305,   306,    36,   284,   287,   285,
      63,   289,   134,   135,   304,   136,   137,   138,   130,   131,
     132,   290,   293,   295,   140,   141,   133,   300,   301,   142,
     128,   302,    34,    35,   303,    21,   134,   135,    36,   136,
     137,   138,   313,   314,   139,    14,   316,    23,   140,   141,
     130,   131,   132,   142,   318,   321,   322,   323,   133,   215,
     216,   217,   218,   219,   220,    76,    28,    59,   134,   135,
     308,   136,   137,   138,    94,   130,   131,   132,    91,   113,
     140,   141,     0,   133,   184,   142,   320,   129,     0,     0,
       0,     0,     0,   134,   135,     0,   136,   137,   138,   130,
     131,   132,     0,     0,     0,   140,   141,   133,     0,     0,
     142,     0,     0,     0,     0,     0,     0,   134,   135,     0,
     136,   137,   138,    -1,    -1,    -1,    -1,    -1,    -1,   140,
     141,     0,     0,     0,   142,   210,   211,   212,   213,   214,
       0,     0,     0,     0,   215,   216,   217,   218,   219,   220
};

static const yytype_int16 yycheck[] =
{
     118,   143,   167,    30,    70,    49,   171,    39,    14,    11,
      11,    14,    98,    45,    41,    14,    14,    17,     8,     9,
     111,    65,    14,    50,    14,   143,   112,   139,    28,     8,
       9,     8,     9,    77,   125,    14,     0,    14,    14,     8,
       9,    47,    40,   161,   110,    14,    55,    56,    47,   167,
     162,   163,   164,   171,   166,    57,   168,    59,    59,   201,
     104,   203,    52,   181,    45,   177,    93,    55,     8,     9,
      46,    59,   116,    55,    14,   187,    55,    59,    55,    54,
     107,    51,    57,   201,    59,   203,    55,    10,     8,     9,
      51,    14,    10,   205,    14,     7,    14,     5,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   274,
      14,   276,    52,     5,    37,    14,     8,     9,    41,    37,
     232,    44,    14,    41,    47,    48,    44,    54,    10,    47,
      48,    54,    14,    55,    55,    57,    54,    59,    59,     6,
     305,     8,     9,    14,    55,    56,    17,    14,     8,     9,
     292,    14,   294,    54,    14,    37,   274,    28,   276,    30,
      55,   273,    44,     8,     9,    47,    53,   279,     5,    14,
      41,     8,    54,   315,   292,    54,   294,    53,    57,    50,
      56,   293,    14,   295,    14,    53,    10,   305,    56,    15,
      16,    17,    18,    19,   281,   282,   283,   315,    24,    25,
      26,    27,    28,    29,    15,    16,    17,    18,    19,    53,
      54,    51,    53,    24,    25,    26,    27,    28,    29,    55,
      56,    55,    56,    51,    15,    16,    17,    18,    19,    14,
      55,    56,    58,    24,    25,    26,    27,    28,    29,    58,
      12,    13,    14,    17,    18,    19,     5,    58,    20,    14,
      24,    25,    26,    27,    28,    29,    55,    56,    30,    31,
       3,    33,    34,    35,    12,    13,    14,    58,     8,     9,
      42,    43,    20,    51,    14,    47,     6,    54,     8,     9,
      52,    14,    30,    31,    14,    33,    34,    35,     6,    52,
       8,     9,     8,     9,    42,    43,    14,    53,    14,    47,
      55,    56,    52,    54,    52,    15,    16,    17,    18,    19,
      54,     4,    54,    51,    24,    25,    26,    27,    28,    29,
      15,    16,    17,    18,    19,    54,    53,    53,    51,    24,
      25,    26,    27,    28,    29,    54,    53,    15,    16,    17,
      18,    19,    54,    52,    59,    55,    24,    25,    26,    27,
      28,    29,    15,    16,    17,    18,    19,    14,    14,    59,
      55,    24,    25,    26,    27,    28,    29,    59,    55,    15,
      16,    17,    18,    19,    14,     4,    14,    55,    24,    25,
      26,    27,    28,    29,    15,    16,    17,    18,    19,    54,
      54,    14,    55,    24,    25,    26,    27,    28,    29,    14,
      53,    15,    16,    17,    18,    19,    14,    54,    53,    55,
      24,    25,    26,    27,    28,    29,    15,    16,    17,    18,
      19,    54,    14,    53,    55,    24,    25,    26,    27,    28,
      29,    15,    16,    17,    18,    19,    53,    55,    11,    53,
      24,    25,    26,    27,    28,    29,    15,    16,    17,    18,
      19,    21,    31,    30,    53,    24,    25,    26,    27,    28,
      29,    36,    55,    54,    12,    13,    14,    54,     6,    53,
       8,     9,    20,    54,    22,    23,    14,    53,    14,    53,
      46,    53,    30,    31,    53,    33,    34,    35,    12,    13,
      14,    55,    54,    54,    42,    43,    20,    53,    55,    47,
       6,    55,     8,     9,    53,     7,    30,    31,    14,    33,
      34,    35,    53,    53,    38,     4,    53,    10,    42,    43,
      12,    13,    14,    47,    53,    53,    53,    53,    20,    24,
      25,    26,    27,    28,    29,    65,    14,    38,    30,    31,
      32,    33,    34,    35,    77,    12,    13,    14,    73,   101,
      42,    43,    -1,    20,   143,    47,    23,   116,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,    12,
      13,    14,    -1,    -1,    -1,    42,    43,    20,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    35,    24,    25,    26,    27,    28,    29,    42,
      43,    -1,    -1,    -1,    47,    15,    16,    17,    18,    19,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,    45,    61,    62,    68,    14,    63,    64,    14,
      69,    70,    71,     0,    68,     5,     8,    79,    93,    51,
      40,    64,    46,    70,    51,     8,     9,    14,    79,    84,
      85,    86,    93,     6,     8,     9,    14,    77,    80,    81,
       7,    85,    93,     8,     9,    14,    65,    66,    67,     5,
      85,    93,    14,    86,    93,    14,    82,    83,     6,    81,
      54,    93,    52,    66,    14,    72,    73,    77,    93,    54,
      54,    57,    53,    56,    55,    53,    73,    74,    75,    77,
      14,     8,     9,    14,    55,    78,    87,    88,    55,    87,
      10,    83,    51,     6,    75,    77,    14,    53,    51,    14,
      55,    56,    55,    58,     5,    89,     8,    76,    86,    14,
      54,    89,    51,    88,     6,    77,    90,    91,     3,    94,
      52,    86,    55,    87,    94,    89,    14,    92,     6,    91,
      12,    13,    14,    20,    30,    31,    33,    34,    35,    38,
      42,    43,    47,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,    52,    53,    55,    52,    94,    53,
      56,    54,    54,    11,    57,    59,    54,    51,    54,    53,
      53,    51,    10,    14,    37,    44,    47,    54,   105,   106,
     107,    54,    54,    59,    96,    97,     4,    11,    59,    53,
      52,    14,    14,   105,   107,    41,    48,   107,   107,    14,
     107,    95,   107,    95,    54,    57,    59,    59,   107,    59,
      15,    16,    17,    18,    19,    24,    25,    26,    27,    28,
      29,    53,    14,   105,    55,    14,     4,    41,    48,   107,
      14,    55,    57,    55,    55,    54,    54,    53,    58,    55,
      52,    55,    52,   107,   108,   107,    14,    14,    55,    14,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,    55,    55,    53,    54,    54,    53,    53,   107,    53,
      53,    55,    14,    11,    21,    31,    30,    36,    55,    56,
      58,    54,    54,    54,    53,    53,    55,    14,    58,    53,
      55,   107,    95,    54,    95,    54,   107,   108,   108,   108,
      53,    55,    55,    53,    53,    22,    23,   107,    32,   107,
      55,    55,    55,    53,    53,    95,    53,    55,    53,    55,
      23,    53,    53,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    61,    61,    61,    62,
      63,    63,    64,    65,    65,    66,    67,    67,    67,    68,
      68,    69,    69,    70,    71,    72,    72,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    77,    78,    78,    78,
      79,    79,    80,    80,    81,    82,    82,    83,    83,    83,
      83,    84,    84,    84,    85,    85,    86,    86,    87,    87,
      88,    89,    89,    89,    90,    90,    91,    92,    92,    93,
      94,    94,    95,    95,    96,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    99,    99,    99,   100,   101,   101,
     102,   103,   104,   105,   105,   105,   106,   106,   106,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   108,
     108,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     4,     3,     3,     2,     3,
       2,     1,     4,     2,     1,     3,     1,     1,     1,     3,
       0,     2,     1,     8,     1,     2,     1,     3,     2,     1,
       6,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     2,     1,     3,     3,     1,     1,     4,     4,
       3,     1,     1,     1,     2,     1,     9,     8,     3,     1,
       2,     3,     2,     0,     2,     1,     3,     3,     1,     8,
       4,     3,     1,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     4,     4,     7,     4,     6,     6,
       7,     7,     5,     5,     5,     8,     5,     5,     8,    10,
       8,     9,     9,     3,     3,     3,     6,     6,     6,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     4,     1,     1,     1,     1,     1,     4,     3,
       1,     0
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
  case 9:
#line 57 "task.y"
    {}
#line 1614 "y.tab.c"
    break;

  case 12:
#line 64 "task.y"
    {TInstall((yyvsp[-3].node)->varname,0,Fhead);}
#line 1620 "y.tab.c"
    break;

  case 15:
#line 71 "task.y"
    {
								FieldInstall(DeclType,(yyvsp[-1].node)->varname);
							}
#line 1628 "y.tab.c"
    break;

  case 16:
#line 76 "task.y"
    {DeclType = TLookup("int");}
#line 1634 "y.tab.c"
    break;

  case 17:
#line 77 "task.y"
    {DeclType = TLookup("string");}
#line 1640 "y.tab.c"
    break;

  case 18:
#line 78 "task.y"
    {
					DeclType = TLookup((yyvsp[0].node)->varname);

					if(DeclType == NULL)	//type maybe undeclared or of the same type as the current user-defined type
					{
						DeclType = TLookup("dummy");
						TypeInfo = malloc(sizeof((yyvsp[0].node)->varname));
						strcpy(TypeInfo,(yyvsp[0].node)->varname);
					}
				}
#line 1655 "y.tab.c"
    break;

  case 19:
#line 92 "task.y"
    {}
#line 1661 "y.tab.c"
    break;

  case 20:
#line 93 "task.y"
    {}
#line 1667 "y.tab.c"
    break;

  case 23:
#line 100 "task.y"
    {
																				//set the function list and fieldlist
																				if(!final_installation)
																				{
																					final_installation = 1;
																					CInstallFinal();
																				}

																				class = NULL;
																				Fhead = Ftail = NULL;
																			    Mfhead = Mftail = NULL;    
																			}
#line 1684 "y.tab.c"
    break;

  case 24:
#line 114 "task.y"
    {
				final_installation = 0;
				class = CInstall((yyvsp[0].node)->varname,NULL);
			}
#line 1693 "y.tab.c"
    break;

  case 27:
#line 124 "task.y"
    {
							//field of a class can be any primitive type,user-defined type or class type
							Class_FieldInstall((yyvsp[-1].node)->varname,DeclType,DeclClass);
						}
#line 1702 "y.tab.c"
    break;

  case 30:
#line 134 "task.y"
    {
													//return type of a function cannot be of class-type
													if(DeclClass != NULL)
													{
														printf("Error: Type of func %s is a class\n",(yyvsp[-4].node)->varname);
														yyerror("");
														exit(1);
													}

													if(DeclType == NULL)
													{
														printf("Error: Type of func %s is invalid\n",(yyvsp[-4].node)->varname);
														yyerror("");
														exit(1);
													}
													
													Class_MethodInstall((yyvsp[-4].node)->varname,DeclType,head);	
													clearParamList();		
												}
#line 1726 "y.tab.c"
    break;

  case 31:
#line 154 "task.y"
    {
													//return type of a function cannot be of class-type
													if(DeclClass != NULL)
													{
														printf("Error: Type of func %s is a class\n",(yyvsp[-3].node)->varname);
														yyerror("");
														exit(1);
													}

													if(DeclType == NULL)
													{
														printf("Error: Type of func %s is invalid\n",(yyvsp[-3].node)->varname);
														yyerror("");
														exit(1);
													}

													Class_MethodInstall((yyvsp[-3].node)->varname,DeclType,head);
													clearParamList();			
												}
#line 1750 "y.tab.c"
    break;

  case 34:
#line 184 "task.y"
    {
				DeclType = TLookup("int");
				DeclClass = NULL;
			}
#line 1759 "y.tab.c"
    break;

  case 35:
#line 189 "task.y"
    {
				DeclType = TLookup("string");
				DeclClass = NULL;
			}
#line 1768 "y.tab.c"
    break;

  case 36:
#line 194 "task.y"
    {
				DeclType = TLookup((yyvsp[0].node)->varname);
				DeclClass = CLookup((yyvsp[0].node)->varname);

				if(DeclType == NULL && DeclClass == NULL)
				{
					printf("%s type does not exist\n",(yyvsp[0].node)->varname);
					yyerror("");
					exit(1);
				}
			}
#line 1784 "y.tab.c"
    break;

  case 37:
#line 207 "task.y"
    {PDeclType = TLookup("int");}
#line 1790 "y.tab.c"
    break;

  case 38:
#line 208 "task.y"
    {PDeclType = TLookup("string");}
#line 1796 "y.tab.c"
    break;

  case 39:
#line 209 "task.y"
    {
					PDeclType = TLookup((yyvsp[0].node)->varname);
					if(!PDeclType)
					{
						printf("%s type not declared\n",(yyvsp[0].node)->varname);
						exit(1);
					}
				}
#line 1809 "y.tab.c"
    break;

  case 40:
#line 222 "task.y"
    {	
										GenerateHeader();
										PrintSymbolTable();
									}
#line 1818 "y.tab.c"
    break;

  case 47:
#line 240 "task.y"
    {GInstall((yyvsp[0].node)->varname,DeclType,DeclClass,0,1);}
#line 1824 "y.tab.c"
    break;

  case 48:
#line 241 "task.y"
    {
								if(DeclClass)
								{
									printf("Error : array of class not allowed\n");
									yyerror("");
									exit(1);
								}
								
								GInstall((yyvsp[-3].node)->varname,DeclType,DeclClass,1,(yyvsp[-1].node)->val);
							}
#line 1839 "y.tab.c"
    break;

  case 49:
#line 252 "task.y"
    {
								if(DeclClass)
								{
									printf("Error : class return type not allowed\n");
									yyerror("");
									exit(1);
								}	

								GInstall((yyvsp[-3].node)->varname,DeclType,DeclClass,2,1);
							  	InsertParamList((yyvsp[-3].node)->varname);
							  	clearParamList();	
							}
#line 1856 "y.tab.c"
    break;

  case 50:
#line 265 "task.y"
    {	
								if(DeclClass)
								{
									printf("Error : class return type not allowed\n");
									yyerror("");
									exit(1);
								}

								GInstall((yyvsp[-2].node)->varname,DeclType,DeclClass,2,1);
								InsertParamList((yyvsp[-2].node)->varname);
								clearParamList();   
						   	}
#line 1873 "y.tab.c"
    break;

  case 51:
#line 283 "task.y"
    {FuncType = TLookup("int");}
#line 1879 "y.tab.c"
    break;

  case 52:
#line 284 "task.y"
    {FuncType = TLookup("string");}
#line 1885 "y.tab.c"
    break;

  case 53:
#line 285 "task.y"
    {
						FuncType = TLookup((yyvsp[0].node)->varname);
						if(!FuncType)
						{
							printf("%s type not declared\n",(yyvsp[0].node)->varname);
							yyerror("");
							exit(1);
						}
					}
#line 1899 "y.tab.c"
    break;

  case 56:
#line 301 "task.y"
    {
			if(class)
			{
				if(!final_installation)
				{
					final_installation = 1;
					CInstallFinal();
				}

				ClassCheckFunction((yyvsp[-7].node)->varname,FuncType);
				InsertSelfToParam();
				ClassFunctionSetup((yyvsp[-7].node)->varname);

				MainCodeGen((yyvsp[-1].node));

				ClassFunctionPopLocal();
				
				fprintf(fp,"MOV BP,[SP]\n");
				fprintf(fp,"SUB SP,1\n");
				fprintf(fp,"RET\n");
				clearParamList();
				clearLSTList();
			}

			else
			{
				checkID((yyvsp[-7].node)->varname);
				CheckIfFunction((yyvsp[-7].node)->varname);
				CheckReturnType((yyvsp[-7].node)->varname,FuncType);
				CheckReturnVal((yyvsp[-1].node)->right,(yyvsp[-7].node)->ttype);
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
		}
#line 1950 "y.tab.c"
    break;

  case 57:
#line 349 "task.y"
    { 
			if(class)
			{
				if(!final_installation)
				{
					final_installation = 1;
					CInstallFinal();
				}
				ClassCheckFunction((yyvsp[-6].node)->varname,FuncType);
				InsertSelfToParam();
				ClassFunctionSetup((yyvsp[-6].node)->varname);

				MainCodeGen((yyvsp[-1].node));

				ClassFunctionPopLocal();
				
				fprintf(fp,"MOV BP,[SP]\n");
				fprintf(fp,"SUB SP,1\n");
				fprintf(fp,"RET\n");
				clearParamList();
				clearLSTList();
			}
			else
			{
				checkID((yyvsp[-6].node)->varname);
				CheckIfFunction((yyvsp[-6].node)->varname);
				CheckReturnType((yyvsp[-6].node)->varname,FuncType);
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
		}
#line 1999 "y.tab.c"
    break;

  case 60:
#line 399 "task.y"
    {
							InsertParam((yyvsp[0].node)->varname,PDeclType);
						}
#line 2007 "y.tab.c"
    break;

  case 67:
#line 418 "task.y"
    {InsertLocalSymbol((yyvsp[0].node)->varname,DeclType);}
#line 2013 "y.tab.c"
    break;

  case 68:
#line 419 "task.y"
    {InsertLocalSymbol((yyvsp[0].node)->varname,DeclType);}
#line 2019 "y.tab.c"
    break;

  case 69:
#line 426 "task.y"
    {

			CheckReturnVal((yyvsp[-1].node)->right,TLookup("int"));
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
#line 2052 "y.tab.c"
    break;

  case 70:
#line 461 "task.y"
    {
			(yyval.node) = createTree(0,NULL,connector_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),(yyvsp[-1].node),NULL);
		}
#line 2060 "y.tab.c"
    break;

  case 71:
#line 466 "task.y"
    {
			(yyval.node) = createTree(0,NULL,connector_node,TLookup("void"),NULL,NULL,NULL,(yyvsp[-1].node),NULL);
		}
#line 2068 "y.tab.c"
    break;

  case 72:
#line 475 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2074 "y.tab.c"
    break;

  case 73:
#line 476 "task.y"
    {(yyval.node) = createTree(0,NULL,connector_node,TLookup("void"),NULL,NULL,(yyvsp[-1].node),(yyvsp[0].node),NULL);}
#line 2080 "y.tab.c"
    break;

  case 74:
#line 483 "task.y"
    {(yyval.node) = createTree(0,NULL,return_node,(yyvsp[-1].node)->ttype,NULL,NULL,(yyvsp[-1].node),NULL,NULL);}
#line 2086 "y.tab.c"
    break;

  case 75:
#line 488 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2092 "y.tab.c"
    break;

  case 76:
#line 489 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2098 "y.tab.c"
    break;

  case 77:
#line 490 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2104 "y.tab.c"
    break;

  case 78:
#line 491 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2110 "y.tab.c"
    break;

  case 79:
#line 492 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2116 "y.tab.c"
    break;

  case 80:
#line 493 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2122 "y.tab.c"
    break;

  case 81:
#line 494 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2128 "y.tab.c"
    break;

  case 82:
#line 495 "task.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 2134 "y.tab.c"
    break;

  case 83:
#line 496 "task.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 2140 "y.tab.c"
    break;

  case 84:
#line 497 "task.y"
    {(yyval.node) = (yyvsp[-3].node);}
#line 2146 "y.tab.c"
    break;

  case 85:
#line 500 "task.y"
    {		
											checkID((yyvsp[-3].node)->varname);    
											AssignCheckType((yyvsp[-3].node),(yyvsp[-1].node));
											(yyval.node) = createTree(0,NULL,assign_node,TLookup("void"),NULL,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
										}
#line 2156 "y.tab.c"
    break;

  case 86:
#line 507 "task.y"
    {
											checkID((yyvsp[-6].node)->varname);
											CheckIfArray((yyvsp[-6].node)->varname);
											CheckIntType((yyvsp[-4].node));
											AssignCheckType((yyvsp[-6].node),(yyvsp[-1].node));
											(yyval.node) = createTree(0,NULL,assignArray_node,TLookup("void"),NULL,NULL,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-1].node));
										}
#line 2168 "y.tab.c"
    break;

  case 87:
#line 515 "task.y"
    {		
											//checkID($1->varname);    
											//AssignCheckType($1,$3);
											(yyval.node) = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
										}
#line 2178 "y.tab.c"
    break;

  case 88:
#line 522 "task.y"
    {
											struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);

											(yyval.node) = createTree(0,NULL,assign_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),tmp,NULL);
										}
#line 2188 "y.tab.c"
    break;

  case 89:
#line 528 "task.y"
    {
												struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);

												(yyval.node) = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),tmp,NULL);
											}
#line 2198 "y.tab.c"
    break;

  case 90:
#line 534 "task.y"
    {
												struct Classtable *ctmp = CLookup((yyvsp[-2].node)->varname);
												if(!ctmp)
												{
													printf("Error:Class %s does not exist\n",(yyvsp[-2].node)->varname);
													yyerror("");
													exit(1);
												}

												struct Gsymbol *tmp = GLookup((yyvsp[-6].node)->varname);
												if(!tmp)
												{
													printf("Error: variable %s not declared\n",(yyvsp[-6].node)->varname);
													yyerror("");
													exit(1);
												}

												if(!tmp->ctype)
												{
													printf("Error:Wrong assignment\n");
													yyerror("");
													exit(1);
												}	

												struct tnode* tmp2 = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);
												(yyval.node) = createTree(0,NULL,assign_node,TLookup("void"),NULL,NULL,(yyvsp[-6].node),tmp2,(yyvsp[-2].node));
										
											}
#line 2231 "y.tab.c"
    break;

  case 91:
#line 563 "task.y"
    {
												struct Classtable *ctmp = CLookup((yyvsp[-2].node)->varname);
												if(!ctmp)
												{
													printf("Error:Class %s does not exist\n",(yyvsp[-2].node)->varname);
													yyerror("");
													exit(1);
												}

												if(!(yyvsp[-6].node)->ctype)
												{
													printf("Error:Wrong assignment\n");
													yyerror("");
													exit(1);	
												}

												struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);
												(yyval.node) = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,NULL,(yyvsp[-6].node),tmp,(yyvsp[-2].node));
											}
#line 2255 "y.tab.c"
    break;

  case 92:
#line 583 "task.y"
    {
											(yyval.node) = createTree(0,NULL,free_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),NULL,NULL);
										}
#line 2263 "y.tab.c"
    break;

  case 93:
#line 587 "task.y"
    {
											(yyval.node) = createTree(0,NULL,free_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),NULL,NULL);
										}
#line 2271 "y.tab.c"
    break;

  case 94:
#line 593 "task.y"
    {
									checkID((yyvsp[-2].node)->varname);
									MatchType((yyvsp[-2].node),var_node);
									if((yyvsp[-2].node)->ttype == TLookup("int") || (yyvsp[-2].node)->ttype == TLookup("string"))
									{
										(yyval.node) = createTree(0,NULL,read_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),NULL,NULL);
									}
									else
									{
										yyerror("Error : cannot be read\n");
										exit(1);
									}
								}
#line 2289 "y.tab.c"
    break;

  case 95:
#line 608 "task.y"
    {	
									checkID((yyvsp[-5].node)->varname);
									CheckIfArray((yyvsp[-5].node)->varname);
									CheckIntType((yyvsp[-3].node));
									(yyval.node) = createTree(0,NULL,readArray_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),(yyvsp[-3].node),NULL);
								}
#line 2300 "y.tab.c"
    break;

  case 96:
#line 615 "task.y"
    {
									if((yyvsp[-2].node)->ttype == TLookup("int") || (yyvsp[-2].node)->ttype == TLookup("string"))
									{
										(yyval.node) = createTree(0,NULL,read_field_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),NULL,NULL);
									}
									else
									{
										yyerror("Error : cannot be read\n");
										exit(1);
									}
								}
#line 2316 "y.tab.c"
    break;

  case 97:
#line 629 "task.y"
    {
							if((yyvsp[-2].node)->ttype != TLookup("int") && (yyvsp[-2].node)->ttype != TLookup("string"))
							{
								printf("Incorrect type in write\n");
								exit(1);
							}
							(yyval.node) = createTree(0,NULL,write_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),NULL,NULL);
						}
#line 2329 "y.tab.c"
    break;

  case 98:
#line 639 "task.y"
    {
							CheckBoolType((yyvsp[-5].node));
							(yyval.node) = createTree(0,NULL,if_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),(yyvsp[-2].node),NULL);
						}
#line 2338 "y.tab.c"
    break;

  case 99:
#line 645 "task.y"
    {
							CheckBoolType((yyvsp[-7].node));
							(yyval.node) = createTree(0,NULL,ifElse_node,TLookup("void"),NULL,NULL,(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node));
						}
#line 2347 "y.tab.c"
    break;

  case 100:
#line 652 "task.y"
    {	
							CheckBoolType((yyvsp[-5].node));
							(yyval.node) = createTree(0,NULL,while_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),(yyvsp[-2].node),NULL);
						}
#line 2356 "y.tab.c"
    break;

  case 101:
#line 658 "task.y"
    {
							CheckBoolType((yyvsp[-2].node));
							(yyval.node) = createTree(0,NULL,Dowhile_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),(yyvsp[-6].node),NULL);
						}
#line 2365 "y.tab.c"
    break;

  case 102:
#line 664 "task.y"
    {			
							CheckBoolType((yyvsp[-2].node));
							(yyval.node) = createTree(0,NULL,repeat_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),(yyvsp[-6].node),NULL);
						}
#line 2374 "y.tab.c"
    break;

  case 103:
#line 671 "task.y"
    {
							checkID((yyvsp[-2].node)->varname);
							struct Fieldlist* tmp = FLookup((yyvsp[-2].node)->ttype,(yyvsp[0].node)->varname);
							if(!tmp)
							{
								printf("Error : %s does not belongs to %s\n",(yyvsp[0].node)->varname,(yyvsp[-2].node)->ttype->name);
								yyerror("");
								exit(1);
							}
							
							(yyval.node) = createTree(0,NULL,field_node,tmp->type,NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2391 "y.tab.c"
    break;

  case 104:
#line 684 "task.y"
    {
								struct Fieldlist* tmp = FLookup((yyvsp[-2].node)->ttype,(yyvsp[0].node)->varname);
								if(!tmp)
								{
									printf("Error : %s does not belongs to %s\n",(yyvsp[0].node)->varname,(yyvsp[-2].node)->ttype->name);
									yyerror("");
									exit(1);
								}

								struct tnode* tmp_new = createTree(0,NULL,field_node,TLookup("void"),NULL,NULL,NULL,(yyvsp[0].node),NULL);	
								struct tnode* tmp1 = (yyvsp[-2].node);
								while(tmp1 -> mid)
								{
									tmp1 = tmp1 -> mid;	
								} 
								tmp1 -> mid = tmp_new;
								tmp1 -> ttype = tmp -> type;

								(yyval.node) = (yyvsp[-2].node);
							}
#line 2416 "y.tab.c"
    break;

  case 105:
#line 705 "task.y"
    {
								if(!class)
								{
									printf("Self is not defined\n");
									yyerror("");
									exit(1);
								}

								//check if ID is a field of the class or not
								struct Fieldlist* curr = Fhead;
								while(curr)
								{
									if(!strcmp(curr->name,(yyvsp[0].node)->varname))
									{
										break;
									}
									curr = curr -> next;
								}

								if(curr == NULL)
								{
									printf("Error: %s is not a field of %s\n",(yyvsp[0].node)->varname,class->name);
									yyerror("");
									exit(1);
								}

								(yyvsp[-2].node) -> ctype = class;	
								(yyval.node) = createTree(0,NULL,field_node,curr->type,curr->ctype,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);

							}
#line 2451 "y.tab.c"
    break;

  case 106:
#line 737 "task.y"
    {
												if(!class)
												{
													printf("Error: Self is not defined\n");
													yyerror("");
													exit(1);
												}

												struct Memberfunclist *idx = Mfhead;
												while(idx)
												{
													if(!strcmp(idx->name,(yyvsp[-3].node)->varname))
													{
														break;
													}
													idx = idx -> next;
												}

												if(!idx)
												{
													printf("Error: Undefined function %s\n",(yyvsp[-3].node)->varname);
													yyerror("");
													exit(1);
												}

												CheckInformalParamList(idx->paramlist,(yyvsp[-1].node));
												
												(yyvsp[-5].node) -> ctype = class;
												(yyval.node) = createTree(0,NULL,field_function_node,idx->type,NULL,idx->name,(yyvsp[-5].node),(yyvsp[-3].node),NULL);
												(yyval.node) -> Arglist = (yyvsp[-1].node);
											}
#line 2487 "y.tab.c"
    break;

  case 107:
#line 769 "task.y"
    {
													struct Gsymbol *tmp = GLookup((yyvsp[-5].node)->varname);
													if(!tmp)
													{
														printf("Error:Variable %s is undeclared\n",(yyvsp[-5].node)->varname);
														yyerror("");
														exit(1);
													}

													if(!tmp->ctype)
													{
														printf("Error: %s is not a class variable\n",(yyvsp[-5].node)->varname);
														yyerror("");
														exit(1);
													}

													struct Memberfunclist* tmp2 = MLookup(tmp->ctype,(yyvsp[-3].node)->varname);
													if(!tmp2)
													{
														printf("Error:%s function not delcared\n",(yyvsp[-3].node)->varname);
														yyerror("");
														exit(1);
													}

													CheckInformalParamList(tmp2->paramlist,(yyvsp[-1].node));
													
													(yyvsp[-5].node)->ctype = tmp -> ctype;
													(yyval.node) = createTree(0,NULL,field_function_node,tmp2->type,NULL,tmp2->name,(yyvsp[-5].node),(yyvsp[-3].node),NULL);
													(yyval.node) -> Arglist = (yyvsp[-1].node);
												}
#line 2522 "y.tab.c"
    break;

  case 108:
#line 800 "task.y"
    {
														struct Memberfunclist *tmp = MLookup((yyvsp[-5].node)->ctype,(yyvsp[-3].node)->varname); 
														if(!tmp)
														{
															printf("Error:Invalid function call\n");
															yyerror("");
															exit(1);
														}

														CheckInformalParamList(tmp->paramlist,(yyvsp[-1].node));

														(yyval.node) = createTree(0,NULL,field_function_node,tmp->type,NULL,tmp->name,(yyvsp[-5].node),(yyvsp[-3].node),NULL);
														(yyval.node) -> Arglist = (yyvsp[-1].node);
													}
#line 2541 "y.tab.c"
    break;

  case 109:
#line 816 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,plus_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2550 "y.tab.c"
    break;

  case 110:
#line 821 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,minus_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2559 "y.tab.c"
    break;

  case 111:
#line 826 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,mul_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2568 "y.tab.c"
    break;

  case 112:
#line 831 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,div_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2577 "y.tab.c"
    break;

  case 113:
#line 836 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,mod_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2586 "y.tab.c"
    break;

  case 114:
#line 841 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,lt_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2595 "y.tab.c"
    break;

  case 115:
#line 846 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,gt_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2604 "y.tab.c"
    break;

  case 116:
#line 851 "task.y"
    {
							CheckCompType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,eq_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2613 "y.tab.c"
    break;

  case 117:
#line 856 "task.y"
    {
							CheckCompType((yyvsp[-2].node),(yyvsp[0].node));
						   	(yyval.node) = createTree(0,NULL,neq_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2622 "y.tab.c"
    break;

  case 118:
#line 861 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,lte_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2631 "y.tab.c"
    break;

  case 119:
#line 866 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,gte_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2640 "y.tab.c"
    break;

  case 120:
#line 871 "task.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 2646 "y.tab.c"
    break;

  case 121:
#line 872 "task.y"
    {checkID((yyvsp[0].node)->varname); (yyval.node) = (yyvsp[0].node);}
#line 2652 "y.tab.c"
    break;

  case 122:
#line 873 "task.y"
    {
							checkID((yyvsp[-3].node)->varname); 
							CheckIfArray((yyvsp[-3].node)->varname);
							CheckIntType((yyvsp[-1].node));
							(yyval.node) = createTree(0,NULL,array_node,(yyvsp[-3].node)->ttype,NULL,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
						}
#line 2663 "y.tab.c"
    break;

  case 123:
#line 880 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2669 "y.tab.c"
    break;

  case 124:
#line 881 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2675 "y.tab.c"
    break;

  case 125:
#line 882 "task.y"
    {(yyval.node) = createTree(0,NULL,null_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);}
#line 2681 "y.tab.c"
    break;

  case 126:
#line 883 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2687 "y.tab.c"
    break;

  case 127:
#line 884 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2693 "y.tab.c"
    break;

  case 128:
#line 887 "task.y"
    {
									checkID((yyvsp[-3].node)->varname);
									CheckIfFunction((yyvsp[-3].node)->varname);
									struct Gsymbol* idx = GLookup((yyvsp[-3].node)->varname);

						   			(yyval.node) = createTree(0,NULL,function_node,idx->type,NULL,idx->name,(yyvsp[-3].node),(yyvsp[-1].node),NULL);

						   			CheckInformalParamList(idx -> ParamList,(yyvsp[-1].node));

									(yyval.node) -> Arglist = (yyvsp[-1].node);
								}
#line 2709 "y.tab.c"
    break;

  case 129:
#line 901 "task.y"
    {
									(yyval.node) = createTree(0,NULL,arg_node,TLookup("void"),NULL,NULL,(yyvsp[0].node),(yyvsp[-2].node),NULL);
								}
#line 2717 "y.tab.c"
    break;

  case 130:
#line 905 "task.y"
    {
									(yyval.node) = createTree(0,NULL,arg_node,TLookup("void"),NULL,NULL,(yyvsp[0].node),NULL,NULL);
								}
#line 2725 "y.tab.c"
    break;

  case 131:
#line 909 "task.y"
    {
									(yyval.node) = NULL;
								}
#line 2733 "y.tab.c"
    break;


#line 2737 "y.tab.c"

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
#line 914 "task.y"


void yyerror(char *S)
{		
	printf("Line number : %d\n%s",line,S);
}

int main(int argc,char* argv[])
{	

	line = 1;
	bind = 4096;

   	fp = fopen("/home/shrey/xsm_expl/progs/stage7_data_encapsulation/tmp.xsm","w");
	fp1 = fopen("input.xsm","w");
   	fp_read = fopen(argv[1],"r");
  	yyin = fp_read;

	InitTypeTable();
   	yyparse();

   	return 0;
}
