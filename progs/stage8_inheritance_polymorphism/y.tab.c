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
	int inheritance = 0;

	#include "task.c"
	extern FILE* yyin;
	int yylex(void); 

#line 98 "y.tab.c"

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
#line 30 "task.y"

	struct tnode* node;

#line 245 "y.tab.c"

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
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  326

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
       0,    47,    47,    48,    49,    50,    51,    52,    53,    58,
      61,    62,    65,    68,    69,    72,    77,    78,    79,    93,
      94,    97,    98,   101,   115,   120,   130,   131,   134,   140,
     141,   144,   164,   186,   187,   194,   199,   204,   217,   218,
     219,   232,   236,   239,   240,   243,   246,   247,   250,   251,
     262,   275,   293,   294,   295,   306,   307,   310,   358,   405,
     406,   409,   414,   416,   418,   421,   422,   425,   428,   429,
     436,   470,   475,   485,   486,   493,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   510,   516,   525,   532,
     538,   544,   573,   593,   597,   602,   617,   624,   638,   648,
     654,   661,   667,   673,   681,   694,   715,   747,   779,   810,
     826,   831,   836,   841,   846,   851,   856,   861,   866,   871,
     876,   881,   882,   883,   890,   891,   892,   893,   894,   896,
     910,   915,   919
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

#define YYPACT_NINF -168

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-168)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -26,   -10,    -3,    28,   -25,    72,    -6,     2,  -168,    29,
      20,  -168,    19,  -168,    81,   129,   120,   108,  -168,   125,
    -168,  -168,    74,  -168,  -168,   136,   120,  -168,  -168,   108,
     130,   108,  -168,  -168,  -168,  -168,  -168,  -168,   139,   140,
    -168,   106,   108,  -168,  -168,  -168,  -168,    30,  -168,   152,
    -168,   155,   108,  -168,   114,  -168,  -168,    40,    57,  -168,
    -168,  -168,   122,  -168,  -168,  -168,   132,   155,  -168,   206,
    -168,     9,    21,   178,  -168,   139,   171,  -168,  -168,   270,
    -168,   217,   186,  -168,  -168,  -168,   195,   235,   154,  -168,
    -168,   156,   202,  -168,   268,   170,  -168,   263,   176,  -168,
     268,  -168,   230,   260,  -168,  -168,   282,   286,  -168,    32,
    -168,   256,    23,   286,   268,  -168,  -168,   297,   462,  -168,
     476,   261,  -168,  -168,   259,   201,   273,   286,  -168,    59,
    -168,  -168,   272,   274,    -2,   281,   276,   288,   283,   291,
     292,   118,   303,   304,   300,   476,   363,  -168,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,    -1,  -168,  -168,   315,  -168,
     323,  -168,   360,     1,   118,    77,   118,   362,   118,   557,
     118,  -168,  -168,   557,  -168,    14,  -168,  -168,   330,   118,
     331,  -168,   386,    22,   336,   385,   396,  -168,  -168,    82,
     392,  -168,  -168,  -168,   164,    92,   290,   353,   367,   401,
     174,  -168,   305,   228,   322,   252,   118,   118,   394,   408,
     337,   409,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,  -168,   116,   127,   383,  -168,  -168,   384,
     397,   416,  -168,   399,   118,   400,   410,   382,   447,  -168,
     451,   446,   442,   448,   441,   590,   237,   189,   425,   426,
    -168,   427,   226,   226,   505,   505,   505,   569,   569,   569,
     569,   569,   569,   438,   439,  -168,   443,   479,  -168,  -168,
     209,  -168,  -168,   444,   445,   118,   557,   449,   557,   450,
    -168,   118,  -168,   118,   118,   118,  -168,  -168,   455,   457,
     458,  -168,   463,   431,   452,   118,   508,   118,   590,   242,
     245,   247,  -168,   464,   471,  -168,  -168,   557,   472,   354,
     473,   369,  -168,  -168,  -168,  -168,  -168,   533,  -168,   474,
    -168,   482,   483,  -168,  -168,  -168
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      20,     0,     0,     0,    20,     0,     0,     0,    11,    24,
       0,    22,     0,     1,     0,     0,     0,     0,     8,     0,
       9,    10,     0,    19,    21,     0,    52,    53,    54,     0,
       0,     0,    56,     6,    42,    35,    36,    37,     0,     0,
      44,     0,     0,     7,    16,    17,    18,     0,    14,     0,
      25,     0,     0,     5,     0,    55,     4,    48,     0,    47,
      41,    43,     0,     3,    12,    13,     0,     0,    27,     0,
       2,     0,     0,     0,    45,     0,     0,    15,    26,     0,
      30,     0,     0,    38,    39,    40,     0,     0,     0,    60,
      51,     0,     0,    46,    64,     0,    29,     0,     0,    28,
      64,    61,     0,     0,    50,    49,     0,     0,    52,     0,
      34,     0,     0,     0,    64,    59,    63,     0,     0,    66,
       0,     0,    23,    33,     0,     0,     0,     0,    69,     0,
      62,    65,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    76,    77,
      78,    79,    80,    81,    82,     0,    70,    32,     0,    58,
       0,    67,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,    84,     0,   127,   122,   128,   126,     0,     0,
     124,   125,     0,     0,     0,     0,     0,    74,    72,     0,
       0,    31,    57,    68,     0,     0,     0,     0,     0,     0,
       0,   104,     0,     0,     0,     0,   132,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,     0,     0,     0,   106,    71,     0,
       0,     0,   105,     0,     0,     0,     0,     0,     0,    86,
       0,     0,     0,     0,     0,   131,     0,     0,   104,   106,
     121,   105,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   120,   119,     0,     0,    85,     0,     0,    88,    95,
       0,    97,    98,     0,     0,     0,     0,     0,     0,     0,
     129,     0,   123,   132,   132,   132,    93,    94,     0,     0,
       0,    89,     0,     0,     0,     0,     0,     0,   130,     0,
       0,     0,    90,     0,     0,    91,    87,     0,     0,     0,
       0,     0,   108,   107,   109,    92,    96,     0,    99,     0,
     101,     0,     0,   102,   103,   100
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -168,  -168,  -168,  -168,   494,  -168,   468,  -168,   498,  -168,
     495,  -168,  -168,   470,  -168,   465,  -168,   -46,  -168,   534,
    -168,   510,  -168,   477,  -168,    45,   -28,   -65,   454,   -92,
    -168,   436,  -168,   128,  -101,  -167,   413,  -144,  -168,  -168,
    -168,  -168,  -168,  -168,  -168,  -120,  -168,  -114,   -89
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     7,     8,    47,    48,    49,     5,    10,
      11,    12,    67,    68,    79,    80,   109,    38,    87,    17,
      39,    40,    58,    59,    30,    31,    32,    88,    89,   107,
     118,   119,   129,    18,   121,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   180,   181,   245,   246
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     155,   187,   203,    55,     6,    69,   205,    91,   113,   165,
     189,     9,   126,     1,    55,   194,     6,    83,    84,     2,
       2,    81,   127,    85,    55,   155,   160,   182,    13,    83,
      84,    83,    84,    97,     9,    85,   224,    85,    44,    45,
     108,    27,    20,   195,    46,    19,    28,   125,   144,   155,
     196,   199,   200,   155,   202,   166,   204,   167,   190,   187,
     117,   187,    42,   225,    86,   210,    23,   110,   206,   144,
      25,   207,   117,   208,    52,   231,    90,    15,   124,    22,
      16,   123,    64,   155,   122,   155,    15,   174,    50,    26,
      27,   175,   174,   247,    72,    28,   175,    73,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   294,
      74,   296,   161,    75,   176,   162,    26,    27,   197,   176,
     270,   177,    28,   229,   178,   198,   177,    41,   174,   178,
     230,   179,   175,    44,    45,    34,   179,    35,    36,    46,
     317,    51,    33,    37,    54,    43,    60,   235,    35,    36,
     187,   190,   187,    57,    37,   176,   155,    53,   155,    56,
      62,   293,   177,    35,    36,   178,    66,   298,    71,    37,
      63,   263,   179,   187,   155,   167,   155,    76,   108,    27,
      70,   309,   264,   311,    28,    77,   190,   155,    92,   212,
     213,   214,   215,   216,   299,   300,   301,   155,   217,   218,
     219,   220,   221,   222,   212,   213,   214,   215,   216,   102,
     103,   104,   103,   217,   218,   219,   220,   221,   222,   233,
      82,   234,    94,   167,   212,   213,   214,   215,   216,    99,
     112,    98,   240,   217,   218,   219,   220,   221,   222,    99,
     132,   133,   134,   214,   215,   216,   100,   282,   135,   101,
     217,   218,   219,   220,   221,   222,   158,   103,   136,   137,
     105,   138,   139,   140,   132,   133,   134,   290,    83,    84,
     142,   143,   135,   106,    85,   144,    95,   111,    35,    36,
     242,   114,   136,   137,    37,   138,   139,   140,   116,   120,
      35,    36,   280,   281,   142,   143,    37,   312,   281,   144,
     313,   281,   314,   281,   244,   212,   213,   214,   215,   216,
     112,   128,   157,   156,   217,   218,   219,   220,   221,   222,
     212,   213,   214,   215,   216,   159,   163,   169,   164,   217,
     218,   219,   220,   221,   222,   168,   171,   212,   213,   214,
     215,   216,   170,   173,   172,   236,   217,   218,   219,   220,
     221,   222,   212,   213,   214,   215,   216,   183,   184,   185,
     241,   217,   218,   219,   220,   221,   222,   188,   191,   212,
     213,   214,   215,   216,   193,   192,   201,   243,   217,   218,
     219,   220,   221,   222,   212,   213,   214,   215,   216,   209,
     211,   226,   250,   217,   218,   219,   220,   221,   222,   227,
     228,   212,   213,   214,   215,   216,   232,   237,   248,   319,
     217,   218,   219,   220,   221,   222,   212,   213,   214,   215,
     216,   238,   249,   251,   321,   217,   218,   219,   220,   221,
     222,   212,   213,   214,   215,   216,   265,   273,   266,   223,
     217,   218,   219,   220,   221,   222,   212,   213,   214,   215,
     216,   267,   269,   271,   239,   217,   218,   219,   220,   221,
     222,   274,   275,   272,   132,   133,   134,   276,   130,   268,
      35,    36,   135,   277,   307,   308,    37,   279,   278,   283,
     284,   285,   136,   137,   306,   138,   139,   140,   132,   133,
     134,   286,   287,   289,   142,   143,   135,   291,   288,   144,
     292,    21,    14,   295,   297,    24,   136,   137,   302,   138,
     139,   140,   303,   304,   141,    65,   305,   315,   142,   143,
     132,   133,   134,   144,   316,   318,   320,   323,   135,   217,
     218,   219,   220,   221,   222,   324,   325,    78,   136,   137,
     310,   138,   139,   140,    96,   132,   133,   134,    29,    61,
     142,   143,    93,   135,   131,   144,   322,   115,   186,     0,
       0,     0,     0,   136,   137,     0,   138,   139,   140,   132,
     133,   134,     0,     0,     0,   142,   143,   135,     0,     0,
     144,     0,     0,     0,     0,     0,     0,   136,   137,     0,
     138,   139,   140,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     143,     0,     0,     0,   144,   212,   213,   214,   215,   216,
       0,     0,     0,     0,   217,   218,   219,   220,   221,   222
};

static const yytype_int16 yycheck[] =
{
     120,   145,   169,    31,    14,    51,   173,    72,   100,    11,
      11,    14,   113,    39,    42,    14,    14,     8,     9,    45,
      45,    67,   114,    14,    52,   145,   127,   141,     0,     8,
       9,     8,     9,    79,    14,    14,    14,    14,     8,     9,
       8,     9,    40,   163,    14,    51,    14,   112,    47,   169,
     164,   165,   166,   173,   168,    57,   170,    59,    59,   203,
     106,   205,    17,   183,    55,   179,    46,    95,    54,    47,
      51,    57,   118,    59,    29,   189,    55,     5,    55,    50,
       8,   109,    52,   203,    52,   205,     5,    10,    14,     8,
       9,    14,    10,   207,    54,    14,    14,    57,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   276,
      53,   278,    53,    56,    37,    56,     8,     9,    41,    37,
     234,    44,    14,    41,    47,    48,    44,     7,    10,    47,
      48,    54,    14,     8,     9,     6,    54,     8,     9,    14,
     307,     5,    14,    14,    14,    17,     6,    55,     8,     9,
     294,    59,   296,    14,    14,    37,   276,    29,   278,    31,
      54,   275,    44,     8,     9,    47,    14,   281,    54,    14,
      42,    55,    54,   317,   294,    59,   296,    55,     8,     9,
      52,   295,    55,   297,    14,    53,    59,   307,    10,    15,
      16,    17,    18,    19,   283,   284,   285,   317,    24,    25,
      26,    27,    28,    29,    15,    16,    17,    18,    19,    55,
      56,    55,    56,    24,    25,    26,    27,    28,    29,    55,
      14,    57,    51,    59,    15,    16,    17,    18,    19,    53,
      54,    14,    58,    24,    25,    26,    27,    28,    29,    53,
      12,    13,    14,    17,    18,    19,    51,    58,    20,    14,
      24,    25,    26,    27,    28,    29,    55,    56,    30,    31,
      58,    33,    34,    35,    12,    13,    14,    58,     8,     9,
      42,    43,    20,     5,    14,    47,     6,    14,     8,     9,
      52,    51,    30,    31,    14,    33,    34,    35,     6,     3,
       8,     9,    55,    56,    42,    43,    14,    55,    56,    47,
      55,    56,    55,    56,    52,    15,    16,    17,    18,    19,
      54,    14,    53,    52,    24,    25,    26,    27,    28,    29,
      15,    16,    17,    18,    19,    52,    54,    51,    54,    24,
      25,    26,    27,    28,    29,    54,    53,    15,    16,    17,
      18,    19,    54,    51,    53,    55,    24,    25,    26,    27,
      28,    29,    15,    16,    17,    18,    19,    54,    54,    59,
      55,    24,    25,    26,    27,    28,    29,     4,    53,    15,
      16,    17,    18,    19,    14,    52,    14,    55,    24,    25,
      26,    27,    28,    29,    15,    16,    17,    18,    19,    59,
      59,    55,    55,    24,    25,    26,    27,    28,    29,    14,
       4,    15,    16,    17,    18,    19,    14,    54,    14,    55,
      24,    25,    26,    27,    28,    29,    15,    16,    17,    18,
      19,    54,    14,    14,    55,    24,    25,    26,    27,    28,
      29,    15,    16,    17,    18,    19,    53,    55,    54,    53,
      24,    25,    26,    27,    28,    29,    15,    16,    17,    18,
      19,    54,    53,    53,    53,    24,    25,    26,    27,    28,
      29,    14,    11,    53,    12,    13,    14,    21,     6,    53,
       8,     9,    20,    31,    22,    23,    14,    36,    30,    54,
      54,    54,    30,    31,    53,    33,    34,    35,    12,    13,
      14,    53,    53,    14,    42,    43,    20,    53,    55,    47,
      55,     7,     4,    54,    54,    10,    30,    31,    53,    33,
      34,    35,    55,    55,    38,    47,    53,    53,    42,    43,
      12,    13,    14,    47,    53,    53,    53,    53,    20,    24,
      25,    26,    27,    28,    29,    53,    53,    67,    30,    31,
      32,    33,    34,    35,    79,    12,    13,    14,    14,    39,
      42,    43,    75,    20,   118,    47,    23,   103,   145,    -1,
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
      40,    64,    50,    46,    70,    51,     8,     9,    14,    79,
      84,    85,    86,    93,     6,     8,     9,    14,    77,    80,
      81,     7,    85,    93,     8,     9,    14,    65,    66,    67,
      14,     5,    85,    93,    14,    86,    93,    14,    82,    83,
       6,    81,    54,    93,    52,    66,    14,    72,    73,    77,
      93,    54,    54,    57,    53,    56,    55,    53,    73,    74,
      75,    77,    14,     8,     9,    14,    55,    78,    87,    88,
      55,    87,    10,    83,    51,     6,    75,    77,    14,    53,
      51,    14,    55,    56,    55,    58,     5,    89,     8,    76,
      86,    14,    54,    89,    51,    88,     6,    77,    90,    91,
       3,    94,    52,    86,    55,    87,    94,    89,    14,    92,
       6,    91,    12,    13,    14,    20,    30,    31,    33,    34,
      35,    38,    42,    43,    47,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    52,    53,    55,    52,
      94,    53,    56,    54,    54,    11,    57,    59,    54,    51,
      54,    53,    53,    51,    10,    14,    37,    44,    47,    54,
     105,   106,   107,    54,    54,    59,    96,    97,     4,    11,
      59,    53,    52,    14,    14,   105,   107,    41,    48,   107,
     107,    14,   107,    95,   107,    95,    54,    57,    59,    59,
     107,    59,    15,    16,    17,    18,    19,    24,    25,    26,
      27,    28,    29,    53,    14,   105,    55,    14,     4,    41,
      48,   107,    14,    55,    57,    55,    55,    54,    54,    53,
      58,    55,    52,    55,    52,   107,   108,   107,    14,    14,
      55,    14,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,    55,    55,    53,    54,    54,    53,    53,
     107,    53,    53,    55,    14,    11,    21,    31,    30,    36,
      55,    56,    58,    54,    54,    54,    53,    53,    55,    14,
      58,    53,    55,   107,    95,    54,    95,    54,   107,   108,
     108,   108,    53,    55,    55,    53,    53,    22,    23,   107,
      32,   107,    55,    55,    55,    53,    53,    95,    53,    55,
      53,    55,    23,    53,    53,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    61,    61,    61,    61,    61,    61,    62,
      63,    63,    64,    65,    65,    66,    67,    67,    67,    68,
      68,    69,    69,    70,    71,    71,    72,    72,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    78,    78,
      78,    79,    79,    80,    80,    81,    82,    82,    83,    83,
      83,    83,    84,    84,    84,    85,    85,    86,    86,    87,
      87,    88,    89,    89,    89,    90,    90,    91,    92,    92,
      93,    94,    94,    95,    95,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    99,    99,    99,   100,   101,
     101,   102,   103,   104,   105,   105,   105,   106,   106,   106,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     108,   108,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     4,     3,     3,     2,     3,
       2,     1,     4,     2,     1,     3,     1,     1,     1,     3,
       0,     2,     1,     8,     1,     3,     2,     1,     3,     2,
       1,     6,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     1,     3,     3,     1,     1,     4,
       4,     3,     1,     1,     1,     2,     1,     9,     8,     3,
       1,     2,     3,     2,     0,     2,     1,     3,     3,     1,
       8,     4,     3,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     4,     4,     7,     4,     6,
       6,     7,     7,     5,     5,     5,     8,     5,     5,     8,
      10,     8,     9,     9,     3,     3,     3,     6,     6,     6,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     4,     1,     1,     1,     1,     1,     4,
       3,     1,     0
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
#line 58 "task.y"
    {}
#line 1615 "y.tab.c"
    break;

  case 12:
#line 65 "task.y"
    {TInstall((yyvsp[-3].node)->varname,0,Fhead);}
#line 1621 "y.tab.c"
    break;

  case 15:
#line 72 "task.y"
    {
								FieldInstall(DeclType,(yyvsp[-1].node)->varname);
							}
#line 1629 "y.tab.c"
    break;

  case 16:
#line 77 "task.y"
    {DeclType = TLookup("int");}
#line 1635 "y.tab.c"
    break;

  case 17:
#line 78 "task.y"
    {DeclType = TLookup("string");}
#line 1641 "y.tab.c"
    break;

  case 18:
#line 79 "task.y"
    {
					DeclType = TLookup((yyvsp[0].node)->varname);

					if(DeclType == NULL)	//type maybe undeclared or of the same type as the current user-defined type
					{
						DeclType = TLookup("dummy");
						TypeInfo = malloc(sizeof((yyvsp[0].node)->varname));
						strcpy(TypeInfo,(yyvsp[0].node)->varname);
					}
				}
#line 1656 "y.tab.c"
    break;

  case 19:
#line 93 "task.y"
    {}
#line 1662 "y.tab.c"
    break;

  case 20:
#line 94 "task.y"
    {}
#line 1668 "y.tab.c"
    break;

  case 23:
#line 101 "task.y"
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
#line 1685 "y.tab.c"
    break;

  case 24:
#line 115 "task.y"
    {
				final_installation = 0;
				class = CInstall((yyvsp[0].node)->varname,NULL);
			}
#line 1694 "y.tab.c"
    break;

  case 25:
#line 120 "task.y"
    {
							inheritance = 1;
							final_installation = 0;
							class = CInstall((yyvsp[-2].node)->varname,(yyvsp[0].node)->varname);

							InheritMemberFields((yyvsp[0].node)->varname);
							InheritFunctions((yyvsp[0].node)->varname);
						}
#line 1707 "y.tab.c"
    break;

  case 28:
#line 134 "task.y"
    {
							//field of a class can be any primitive type,user-defined type or class type
							Class_FieldInstall((yyvsp[-1].node)->varname,DeclType,DeclClass);
						}
#line 1716 "y.tab.c"
    break;

  case 31:
#line 144 "task.y"
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
#line 1740 "y.tab.c"
    break;

  case 32:
#line 164 "task.y"
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
#line 1764 "y.tab.c"
    break;

  case 35:
#line 194 "task.y"
    {
				DeclType = TLookup("int");
				DeclClass = NULL;
			}
#line 1773 "y.tab.c"
    break;

  case 36:
#line 199 "task.y"
    {
				DeclType = TLookup("string");
				DeclClass = NULL;
			}
#line 1782 "y.tab.c"
    break;

  case 37:
#line 204 "task.y"
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
#line 1798 "y.tab.c"
    break;

  case 38:
#line 217 "task.y"
    {PDeclType = TLookup("int");}
#line 1804 "y.tab.c"
    break;

  case 39:
#line 218 "task.y"
    {PDeclType = TLookup("string");}
#line 1810 "y.tab.c"
    break;

  case 40:
#line 219 "task.y"
    {
					PDeclType = TLookup((yyvsp[0].node)->varname);
					if(!PDeclType)
					{
						printf("%s type not declared\n",(yyvsp[0].node)->varname);
						exit(1);
					}
				}
#line 1823 "y.tab.c"
    break;

  case 41:
#line 232 "task.y"
    {	
										GenerateHeader();
										PrintSymbolTable();
									}
#line 1832 "y.tab.c"
    break;

  case 48:
#line 250 "task.y"
    {GInstall((yyvsp[0].node)->varname,DeclType,DeclClass,0,1);}
#line 1838 "y.tab.c"
    break;

  case 49:
#line 251 "task.y"
    {
								if(DeclClass)
								{
									printf("Error : array of class not allowed\n");
									yyerror("");
									exit(1);
								}
								
								GInstall((yyvsp[-3].node)->varname,DeclType,DeclClass,1,(yyvsp[-1].node)->val);
							}
#line 1853 "y.tab.c"
    break;

  case 50:
#line 262 "task.y"
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
#line 1870 "y.tab.c"
    break;

  case 51:
#line 275 "task.y"
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
#line 1887 "y.tab.c"
    break;

  case 52:
#line 293 "task.y"
    {FuncType = TLookup("int");}
#line 1893 "y.tab.c"
    break;

  case 53:
#line 294 "task.y"
    {FuncType = TLookup("string");}
#line 1899 "y.tab.c"
    break;

  case 54:
#line 295 "task.y"
    {
						FuncType = TLookup((yyvsp[0].node)->varname);
						if(!FuncType)
						{
							printf("%s type not declared\n",(yyvsp[0].node)->varname);
							yyerror("");
							exit(1);
						}
					}
#line 1913 "y.tab.c"
    break;

  case 57:
#line 311 "task.y"
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
#line 1964 "y.tab.c"
    break;

  case 58:
#line 359 "task.y"
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
#line 2013 "y.tab.c"
    break;

  case 61:
#line 409 "task.y"
    {
							InsertParam((yyvsp[0].node)->varname,PDeclType);
						}
#line 2021 "y.tab.c"
    break;

  case 68:
#line 428 "task.y"
    {InsertLocalSymbol((yyvsp[0].node)->varname,DeclType);}
#line 2027 "y.tab.c"
    break;

  case 69:
#line 429 "task.y"
    {InsertLocalSymbol((yyvsp[0].node)->varname,DeclType);}
#line 2033 "y.tab.c"
    break;

  case 70:
#line 436 "task.y"
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
#line 2066 "y.tab.c"
    break;

  case 71:
#line 471 "task.y"
    {
			(yyval.node) = createTree(0,NULL,connector_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),(yyvsp[-1].node),NULL);
		}
#line 2074 "y.tab.c"
    break;

  case 72:
#line 476 "task.y"
    {
			(yyval.node) = createTree(0,NULL,connector_node,TLookup("void"),NULL,NULL,NULL,(yyvsp[-1].node),NULL);
		}
#line 2082 "y.tab.c"
    break;

  case 73:
#line 485 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2088 "y.tab.c"
    break;

  case 74:
#line 486 "task.y"
    {(yyval.node) = createTree(0,NULL,connector_node,TLookup("void"),NULL,NULL,(yyvsp[-1].node),(yyvsp[0].node),NULL);}
#line 2094 "y.tab.c"
    break;

  case 75:
#line 493 "task.y"
    {(yyval.node) = createTree(0,NULL,return_node,(yyvsp[-1].node)->ttype,NULL,NULL,(yyvsp[-1].node),NULL,NULL);}
#line 2100 "y.tab.c"
    break;

  case 76:
#line 498 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2106 "y.tab.c"
    break;

  case 77:
#line 499 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2112 "y.tab.c"
    break;

  case 78:
#line 500 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2118 "y.tab.c"
    break;

  case 79:
#line 501 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2124 "y.tab.c"
    break;

  case 80:
#line 502 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2130 "y.tab.c"
    break;

  case 81:
#line 503 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2136 "y.tab.c"
    break;

  case 82:
#line 504 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2142 "y.tab.c"
    break;

  case 83:
#line 505 "task.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 2148 "y.tab.c"
    break;

  case 84:
#line 506 "task.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 2154 "y.tab.c"
    break;

  case 85:
#line 507 "task.y"
    {(yyval.node) = (yyvsp[-3].node);}
#line 2160 "y.tab.c"
    break;

  case 86:
#line 510 "task.y"
    {		
											checkID((yyvsp[-3].node)->varname);    
											AssignCheckType((yyvsp[-3].node),(yyvsp[-1].node));
											(yyval.node) = createTree(0,NULL,assign_node,TLookup("void"),NULL,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
										}
#line 2170 "y.tab.c"
    break;

  case 87:
#line 517 "task.y"
    {
											checkID((yyvsp[-6].node)->varname);
											CheckIfArray((yyvsp[-6].node)->varname);
											CheckIntType((yyvsp[-4].node));
											AssignCheckType((yyvsp[-6].node),(yyvsp[-1].node));
											(yyval.node) = createTree(0,NULL,assignArray_node,TLookup("void"),NULL,NULL,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-1].node));
										}
#line 2182 "y.tab.c"
    break;

  case 88:
#line 525 "task.y"
    {		
											//checkID($1->varname);    
											//AssignCheckType($1,$3);
											(yyval.node) = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
										}
#line 2192 "y.tab.c"
    break;

  case 89:
#line 532 "task.y"
    {
											struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);

											(yyval.node) = createTree(0,NULL,assign_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),tmp,NULL);
										}
#line 2202 "y.tab.c"
    break;

  case 90:
#line 538 "task.y"
    {
												struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);

												(yyval.node) = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),tmp,NULL);
											}
#line 2212 "y.tab.c"
    break;

  case 91:
#line 544 "task.y"
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
#line 2245 "y.tab.c"
    break;

  case 92:
#line 573 "task.y"
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
#line 2269 "y.tab.c"
    break;

  case 93:
#line 593 "task.y"
    {
											(yyval.node) = createTree(0,NULL,free_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),NULL,NULL);
										}
#line 2277 "y.tab.c"
    break;

  case 94:
#line 597 "task.y"
    {
											(yyval.node) = createTree(0,NULL,free_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),NULL,NULL);
										}
#line 2285 "y.tab.c"
    break;

  case 95:
#line 603 "task.y"
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
#line 2303 "y.tab.c"
    break;

  case 96:
#line 618 "task.y"
    {	
									checkID((yyvsp[-5].node)->varname);
									CheckIfArray((yyvsp[-5].node)->varname);
									CheckIntType((yyvsp[-3].node));
									(yyval.node) = createTree(0,NULL,readArray_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),(yyvsp[-3].node),NULL);
								}
#line 2314 "y.tab.c"
    break;

  case 97:
#line 625 "task.y"
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
#line 2330 "y.tab.c"
    break;

  case 98:
#line 639 "task.y"
    {
							if((yyvsp[-2].node)->ttype != TLookup("int") && (yyvsp[-2].node)->ttype != TLookup("string"))
							{
								printf("Incorrect type in write\n");
								exit(1);
							}
							(yyval.node) = createTree(0,NULL,write_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),NULL,NULL);
						}
#line 2343 "y.tab.c"
    break;

  case 99:
#line 649 "task.y"
    {
							CheckBoolType((yyvsp[-5].node));
							(yyval.node) = createTree(0,NULL,if_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),(yyvsp[-2].node),NULL);
						}
#line 2352 "y.tab.c"
    break;

  case 100:
#line 655 "task.y"
    {
							CheckBoolType((yyvsp[-7].node));
							(yyval.node) = createTree(0,NULL,ifElse_node,TLookup("void"),NULL,NULL,(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node));
						}
#line 2361 "y.tab.c"
    break;

  case 101:
#line 662 "task.y"
    {	
							CheckBoolType((yyvsp[-5].node));
							(yyval.node) = createTree(0,NULL,while_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),(yyvsp[-2].node),NULL);
						}
#line 2370 "y.tab.c"
    break;

  case 102:
#line 668 "task.y"
    {
							CheckBoolType((yyvsp[-2].node));
							(yyval.node) = createTree(0,NULL,Dowhile_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),(yyvsp[-6].node),NULL);
						}
#line 2379 "y.tab.c"
    break;

  case 103:
#line 674 "task.y"
    {			
							CheckBoolType((yyvsp[-2].node));
							(yyval.node) = createTree(0,NULL,repeat_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),(yyvsp[-6].node),NULL);
						}
#line 2388 "y.tab.c"
    break;

  case 104:
#line 681 "task.y"
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
#line 2405 "y.tab.c"
    break;

  case 105:
#line 694 "task.y"
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
#line 2430 "y.tab.c"
    break;

  case 106:
#line 715 "task.y"
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
#line 2465 "y.tab.c"
    break;

  case 107:
#line 747 "task.y"
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
#line 2501 "y.tab.c"
    break;

  case 108:
#line 779 "task.y"
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
#line 2536 "y.tab.c"
    break;

  case 109:
#line 810 "task.y"
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
#line 2555 "y.tab.c"
    break;

  case 110:
#line 826 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,plus_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2564 "y.tab.c"
    break;

  case 111:
#line 831 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,minus_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2573 "y.tab.c"
    break;

  case 112:
#line 836 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,mul_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2582 "y.tab.c"
    break;

  case 113:
#line 841 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,div_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2591 "y.tab.c"
    break;

  case 114:
#line 846 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,mod_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2600 "y.tab.c"
    break;

  case 115:
#line 851 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,lt_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2609 "y.tab.c"
    break;

  case 116:
#line 856 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,gt_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2618 "y.tab.c"
    break;

  case 117:
#line 861 "task.y"
    {
							CheckCompType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,eq_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2627 "y.tab.c"
    break;

  case 118:
#line 866 "task.y"
    {
							CheckCompType((yyvsp[-2].node),(yyvsp[0].node));
						   	(yyval.node) = createTree(0,NULL,neq_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2636 "y.tab.c"
    break;

  case 119:
#line 871 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,lte_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2645 "y.tab.c"
    break;

  case 120:
#line 876 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,gte_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2654 "y.tab.c"
    break;

  case 121:
#line 881 "task.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 2660 "y.tab.c"
    break;

  case 122:
#line 882 "task.y"
    {checkID((yyvsp[0].node)->varname); (yyval.node) = (yyvsp[0].node);}
#line 2666 "y.tab.c"
    break;

  case 123:
#line 883 "task.y"
    {
							checkID((yyvsp[-3].node)->varname); 
							CheckIfArray((yyvsp[-3].node)->varname);
							CheckIntType((yyvsp[-1].node));
							(yyval.node) = createTree(0,NULL,array_node,(yyvsp[-3].node)->ttype,NULL,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
						}
#line 2677 "y.tab.c"
    break;

  case 124:
#line 890 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2683 "y.tab.c"
    break;

  case 125:
#line 891 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2689 "y.tab.c"
    break;

  case 126:
#line 892 "task.y"
    {(yyval.node) = createTree(0,NULL,null_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);}
#line 2695 "y.tab.c"
    break;

  case 127:
#line 893 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2701 "y.tab.c"
    break;

  case 128:
#line 894 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2707 "y.tab.c"
    break;

  case 129:
#line 897 "task.y"
    {
									checkID((yyvsp[-3].node)->varname);
									CheckIfFunction((yyvsp[-3].node)->varname);
									struct Gsymbol* idx = GLookup((yyvsp[-3].node)->varname);

						   			(yyval.node) = createTree(0,NULL,function_node,idx->type,NULL,idx->name,(yyvsp[-3].node),(yyvsp[-1].node),NULL);

						   			CheckInformalParamList(idx -> ParamList,(yyvsp[-1].node));

									(yyval.node) -> Arglist = (yyvsp[-1].node);
								}
#line 2723 "y.tab.c"
    break;

  case 130:
#line 911 "task.y"
    {
									(yyval.node) = createTree(0,NULL,arg_node,TLookup("void"),NULL,NULL,(yyvsp[0].node),(yyvsp[-2].node),NULL);
								}
#line 2731 "y.tab.c"
    break;

  case 131:
#line 915 "task.y"
    {
									(yyval.node) = createTree(0,NULL,arg_node,TLookup("void"),NULL,NULL,(yyvsp[0].node),NULL,NULL);
								}
#line 2739 "y.tab.c"
    break;

  case 132:
#line 919 "task.y"
    {
									(yyval.node) = NULL;
								}
#line 2747 "y.tab.c"
    break;


#line 2751 "y.tab.c"

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
#line 924 "task.y"


void yyerror(char *S)
{		
	printf("Line number : %d\n%s",line,S);
}

int main(int argc,char* argv[])
{	

	line = 1;
	bind = 4096;

   	fp = fopen("/home/shrey/xsm_expl/progs/stage8_inheritance_polymorphism/tmp.xsm","w");
	fp1 = fopen("input.xsm","w");
   	fp_read = fopen(argv[1],"r");
  	yyin = fp_read;

	InitTypeTable();
   	yyparse();

   	return 0;
}
