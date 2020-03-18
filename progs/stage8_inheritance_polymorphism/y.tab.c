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
	FILE *fp, *fp1, *fp2;
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
#define YYLAST   627

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  135
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  336

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
      95,    98,    99,   102,   117,   133,   138,   148,   149,   152,
     158,   159,   162,   182,   204,   205,   212,   217,   222,   235,
     236,   237,   250,   254,   257,   258,   261,   264,   265,   268,
     279,   290,   303,   321,   322,   323,   334,   335,   338,   386,
     433,   434,   437,   442,   444,   446,   449,   450,   453,   456,
     457,   464,   498,   503,   513,   514,   521,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   538,   544,   553,
     559,   573,   579,   608,   628,   638,   648,   658,   669,   684,
     691,   705,   715,   721,   728,   734,   740,   748,   761,   782,
     814,   846,   877,   893,   898,   903,   908,   913,   918,   923,
     928,   933,   938,   943,   948,   949,   955,   962,   963,   964,
     965,   966,   968,   982,   987,   991
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

#define YYPACT_NINF -172

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-172)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      49,     4,     9,    47,    21,    82,    25,     6,  -172,    46,
      -7,  -172,    58,  -172,   175,   154,   110,   122,  -172,   268,
    -172,  -172,   105,  -172,  -172,   127,   110,  -172,  -172,   122,
     120,   122,  -172,  -172,  -172,  -172,  -172,  -172,   131,   221,
    -172,    84,   122,  -172,  -172,  -172,  -172,    26,  -172,   142,
    -172,   462,   122,  -172,   104,  -172,  -172,   136,   161,  -172,
    -172,  -172,   114,  -172,  -172,  -172,   118,   462,  -172,   225,
    -172,   171,  -172,     8,    22,   218,  -172,   131,   200,  -172,
    -172,   254,   476,  -172,   244,   162,  -172,  -172,  -172,   214,
     259,   239,  -172,  -172,   241,   229,  -172,   304,   476,  -172,
      59,  -172,   258,  -172,    24,   304,  -172,   277,   486,  -172,
    -172,   266,   340,    72,  -172,  -172,   305,   255,   340,   304,
    -172,  -172,   345,   441,  -172,   468,   308,  -172,  -172,   320,
     322,   340,  -172,   188,  -172,  -172,   329,   330,     2,   336,
     324,   337,   339,   352,   355,   100,   366,   367,   348,   368,
     468,   432,  -172,  -172,  -172,  -172,  -172,  -172,  -172,  -172,
      -3,  -172,  -172,  -172,   383,  -172,   423,   -10,   100,    79,
     100,   437,   100,   549,   100,  -172,  -172,   549,  -172,   227,
    -172,  -172,   387,   100,   393,  -172,   370,    -4,   399,   455,
      -2,   485,  -172,  -172,    81,   458,  -172,  -172,   181,    53,
     274,   438,   442,   385,   124,  -172,   289,   212,   306,   236,
     100,   100,   483,   490,   321,   491,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,  -172,   132,   198,
     454,  -172,   404,   406,  -172,   464,   465,   400,  -172,   456,
     100,   463,   474,   453,   514,  -172,   518,   515,   509,   511,
     508,   584,   264,   179,   492,   496,  -172,   498,   148,   148,
     497,   497,   497,   561,   561,   561,   561,   561,   561,   501,
     504,  -172,   512,   513,   516,   537,  -172,  -172,   194,  -172,
    -172,   517,   520,   100,   549,   499,   549,   510,  -172,   100,
    -172,   100,   100,   100,  -172,  -172,  -172,  -172,   523,   522,
     526,  -172,   540,   415,   444,   100,   500,   100,   584,   271,
     286,   296,  -172,   541,   542,  -172,  -172,   549,   544,   338,
     551,   353,  -172,  -172,  -172,  -172,  -172,   525,  -172,   552,
    -172,   553,   554,  -172,  -172,  -172
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      20,     0,     0,     0,    20,     0,     0,     0,    11,    25,
       0,    22,     0,     1,     0,     0,     0,     0,     8,     0,
       9,    10,     0,    19,    21,     0,    53,    54,    55,     0,
       0,     0,    57,     6,    43,    36,    37,    38,     0,     0,
      45,     0,     0,     7,    16,    17,    18,     0,    14,     0,
      26,     0,     0,     5,     0,    56,     4,    49,     0,    48,
      42,    44,     0,     3,    12,    13,     0,     0,    28,     0,
      31,     0,     2,     0,     0,     0,    46,     0,     0,    15,
      27,     0,     0,    30,     0,     0,    39,    40,    41,     0,
       0,     0,    61,    52,     0,     0,    47,    65,     0,    53,
       0,    35,     0,    29,     0,    65,    62,     0,     0,    51,
      50,     0,     0,     0,    24,    34,     0,     0,     0,    65,
      60,    64,     0,     0,    67,     0,     0,    23,    33,     0,
       0,     0,    70,     0,    63,    66,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    77,    78,    79,    80,    81,    82,    83,
       0,    71,    32,    59,     0,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,     0,   130,   125,
     131,   129,     0,     0,   127,   128,     0,     0,     0,     0,
       0,     0,    75,    73,     0,     0,    58,    69,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
     135,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,   109,     0,     0,    72,     0,     0,     0,   108,     0,
       0,     0,     0,     0,     0,    87,     0,     0,     0,     0,
       0,   134,     0,     0,   107,   109,   124,   108,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   123,   122,     0,
       0,    86,     0,     0,     0,     0,    89,    98,     0,   100,
     101,     0,     0,     0,     0,     0,     0,     0,   132,     0,
     126,   135,   135,   135,    94,    95,    96,    97,     0,     0,
       0,    90,     0,     0,     0,     0,     0,     0,   133,     0,
       0,     0,    91,     0,     0,    92,    88,     0,     0,     0,
       0,     0,   111,   110,   112,    93,    99,     0,   102,     0,
     104,     0,     0,   105,   106,   103
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -172,  -172,  -172,  -172,   566,  -172,   531,  -172,   610,  -172,
     605,  -172,  -172,   550,   555,   -60,   521,   -40,  -172,   602,
    -172,   579,  -172,   543,  -172,    40,   -28,   -30,   519,  -100,
    -172,   502,  -172,   431,  -103,  -171,   471,  -149,  -172,  -172,
    -172,  -172,  -172,  -172,  -172,  -125,  -172,  -119,   -92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     7,     8,    47,    48,    49,     5,    10,
      11,    12,    67,    68,    69,    70,   100,    38,    90,    17,
      39,    40,    58,    59,    30,    31,    32,    91,    92,   112,
     123,   124,   133,    18,   126,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   184,   185,   251,   252
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     160,   192,   207,    55,   198,   118,   209,     9,   194,    83,
     228,    71,   232,   169,    55,   130,    86,    87,     6,   131,
       6,    83,    88,     9,    55,   160,   186,    71,   164,    84,
      86,    87,    86,    87,    44,    45,    88,   148,    88,    23,
      46,    84,   199,   148,    94,   148,    20,    13,   160,   200,
     203,   204,   160,   206,   101,   208,   195,    42,   192,   170,
     192,   171,   229,    89,   214,   233,     2,    99,    27,    52,
     101,   122,   115,    28,   117,   237,    19,    93,    64,   116,
      99,    27,   160,   122,   160,   115,    28,    15,     1,   178,
      16,   178,   253,   179,     2,   179,    22,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   241,    25,
     178,   114,   195,   304,   179,   306,   180,    41,   180,    50,
     201,   278,   235,   181,   127,   181,   182,   202,   182,   236,
      26,    27,    51,   183,    54,   183,    28,   180,    62,   216,
     217,   218,   219,   220,   181,    57,   327,   182,   221,   222,
     223,   224,   225,   226,   183,   192,    66,   192,    73,   160,
      34,   160,    35,    36,   303,   218,   219,   220,    37,    78,
     308,    79,   221,   222,   223,   224,   225,   226,   192,   160,
      15,   160,   246,    26,    27,    85,   319,   269,   321,    28,
      74,   171,   160,    75,   216,   217,   218,   219,   220,   309,
     310,   311,   160,   221,   222,   223,   224,   225,   226,   216,
     217,   218,   219,   220,    76,   103,   104,    77,   221,   222,
     223,   224,   225,   226,   136,   137,   138,    60,    95,    35,
      36,    82,   139,    35,    36,    37,   239,   290,   240,    37,
     171,   165,   140,   141,   166,   142,   143,   144,   136,   137,
     138,    97,   300,   270,   146,   147,   139,   195,   102,   148,
      98,   149,    35,    36,   248,   105,   140,   141,    37,   142,
     143,   144,   121,   106,    35,    36,    44,    45,   146,   147,
      37,   210,    46,   148,   211,   149,   212,   110,   250,   216,
     217,   218,   219,   220,   107,   108,   109,   108,   221,   222,
     223,   224,   225,   226,   216,   217,   218,   219,   220,   111,
     129,   108,   104,   221,   222,   223,   224,   225,   226,   288,
     289,   216,   217,   218,   219,   220,   322,   289,   119,   242,
     221,   222,   223,   224,   225,   226,   216,   217,   218,   219,
     220,   323,   289,   125,   247,   221,   222,   223,   224,   225,
     226,   324,   289,   216,   217,   218,   219,   220,   128,   132,
     161,   249,   221,   222,   223,   224,   225,   226,   216,   217,
     218,   219,   220,   162,   163,   173,   256,   221,   222,   223,
     224,   225,   226,   167,   168,   216,   217,   218,   219,   220,
     172,   174,   175,   329,   221,   222,   223,   224,   225,   226,
     216,   217,   218,   219,   220,   176,   177,   189,   331,   221,
     222,   223,   224,   225,   226,   216,   217,   218,   219,   220,
     187,   188,   190,   227,   221,   222,   223,   224,   225,   226,
     216,   217,   218,   219,   220,   196,   193,   197,   245,   221,
     222,   223,   224,   225,   226,    33,   213,   134,    43,    35,
      36,   205,   215,   276,   230,    37,   136,   137,   138,   272,
      53,   273,    56,   171,   139,   195,   317,   318,   316,   231,
      35,    36,   238,    63,   140,   141,    37,   142,   143,   144,
     136,   137,   138,    72,    99,    27,   146,   147,   139,   234,
      28,   148,   243,   149,    86,    87,   244,   254,   140,   141,
      88,   142,   143,   144,   255,   257,   145,   271,   281,   277,
     146,   147,   136,   137,   138,   148,   279,   149,   274,   275,
     139,   221,   222,   223,   224,   225,   226,   280,   282,   283,
     140,   141,   320,   142,   143,   144,   284,   136,   137,   138,
     285,   286,   146,   147,   287,   139,   291,   148,   332,   149,
     292,   299,   293,   305,   294,   140,   141,   295,   142,   143,
     144,   136,   137,   138,   307,   296,   297,   146,   147,   139,
     301,   298,   148,    21,   149,   302,   312,   313,    65,   140,
     141,   314,   142,   143,   144,    -1,    -1,    -1,    -1,    -1,
      -1,   146,   147,   315,   325,   326,   148,   328,   149,   216,
     217,   218,   219,   220,   330,   333,   334,   335,   221,   222,
     223,   224,   225,   226,    14,    24,    29,    80,    61,   113,
      96,   191,    81,     0,     0,   135,     0,   120
};

static const yytype_int16 yycheck[] =
{
     125,   150,   173,    31,    14,   105,   177,    14,    11,    69,
      14,    51,    14,    11,    42,   118,     8,     9,    14,   119,
      14,    81,    14,    14,    52,   150,   145,    67,   131,    69,
       8,     9,     8,     9,     8,     9,    14,    47,    14,    46,
      14,    81,   167,    47,    74,    47,    40,     0,   173,   168,
     169,   170,   177,   172,    82,   174,    59,    17,   207,    57,
     209,    59,   187,    55,   183,   190,    45,     8,     9,    29,
      98,   111,   100,    14,   104,   194,    51,    55,    52,    55,
       8,     9,   207,   123,   209,   113,    14,     5,    39,    10,
       8,    10,   211,    14,    45,    14,    50,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,    55,    51,
      10,    52,    59,   284,    14,   286,    37,     7,    37,    14,
      41,   240,    41,    44,    52,    44,    47,    48,    47,    48,
       8,     9,     5,    54,    14,    54,    14,    37,    54,    15,
      16,    17,    18,    19,    44,    14,   317,    47,    24,    25,
      26,    27,    28,    29,    54,   304,    14,   306,    54,   284,
       6,   286,     8,     9,   283,    17,    18,    19,    14,    55,
     289,    53,    24,    25,    26,    27,    28,    29,   327,   304,
       5,   306,    58,     8,     9,    14,   305,    55,   307,    14,
      54,    59,   317,    57,    15,    16,    17,    18,    19,   291,
     292,   293,   327,    24,    25,    26,    27,    28,    29,    15,
      16,    17,    18,    19,    53,    53,    54,    56,    24,    25,
      26,    27,    28,    29,    12,    13,    14,     6,    10,     8,
       9,     6,    20,     8,     9,    14,    55,    58,    57,    14,
      59,    53,    30,    31,    56,    33,    34,    35,    12,    13,
      14,    51,    58,    55,    42,    43,    20,    59,    14,    47,
       6,    49,     8,     9,    52,    51,    30,    31,    14,    33,
      34,    35,     6,    14,     8,     9,     8,     9,    42,    43,
      14,    54,    14,    47,    57,    49,    59,    58,    52,    15,
      16,    17,    18,    19,    55,    56,    55,    56,    24,    25,
      26,    27,    28,    29,    15,    16,    17,    18,    19,     5,
      55,    56,    54,    24,    25,    26,    27,    28,    29,    55,
      56,    15,    16,    17,    18,    19,    55,    56,    51,    55,
      24,    25,    26,    27,    28,    29,    15,    16,    17,    18,
      19,    55,    56,     3,    55,    24,    25,    26,    27,    28,
      29,    55,    56,    15,    16,    17,    18,    19,    53,    14,
      52,    55,    24,    25,    26,    27,    28,    29,    15,    16,
      17,    18,    19,    53,    52,    51,    55,    24,    25,    26,
      27,    28,    29,    54,    54,    15,    16,    17,    18,    19,
      54,    54,    53,    55,    24,    25,    26,    27,    28,    29,
      15,    16,    17,    18,    19,    53,    51,    59,    55,    24,
      25,    26,    27,    28,    29,    15,    16,    17,    18,    19,
      54,    54,    54,    53,    24,    25,    26,    27,    28,    29,
      15,    16,    17,    18,    19,    52,     4,    14,    53,    24,
      25,    26,    27,    28,    29,    14,    59,     6,    17,     8,
       9,    14,    59,    53,    55,    14,    12,    13,    14,    55,
      29,    55,    31,    59,    20,    59,    22,    23,    53,    14,
       8,     9,    14,    42,    30,    31,    14,    33,    34,    35,
      12,    13,    14,    52,     8,     9,    42,    43,    20,     4,
      14,    47,    54,    49,     8,     9,    54,    14,    30,    31,
      14,    33,    34,    35,    14,    14,    38,    53,    55,    53,
      42,    43,    12,    13,    14,    47,    53,    49,    54,    54,
      20,    24,    25,    26,    27,    28,    29,    53,    14,    11,
      30,    31,    32,    33,    34,    35,    21,    12,    13,    14,
      31,    30,    42,    43,    36,    20,    54,    47,    23,    49,
      54,    14,    54,    54,    53,    30,    31,    53,    33,    34,
      35,    12,    13,    14,    54,    53,    53,    42,    43,    20,
      53,    55,    47,     7,    49,    55,    53,    55,    47,    30,
      31,    55,    33,    34,    35,    24,    25,    26,    27,    28,
      29,    42,    43,    53,    53,    53,    47,    53,    49,    15,
      16,    17,    18,    19,    53,    53,    53,    53,    24,    25,
      26,    27,    28,    29,     4,    10,    14,    67,    39,    98,
      77,   150,    67,    -1,    -1,   123,    -1,   108
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
       6,    81,    54,    93,    52,    66,    14,    72,    73,    74,
      75,    77,    93,    54,    54,    57,    53,    56,    55,    53,
      73,    74,     6,    75,    77,    14,     8,     9,    14,    55,
      78,    87,    88,    55,    87,    10,    83,    51,     6,     8,
      76,    86,    14,    53,    54,    51,    14,    55,    56,    55,
      58,     5,    89,    76,    52,    86,    55,    87,    89,    51,
      88,     6,    77,    90,    91,     3,    94,    52,    53,    55,
      94,    89,    14,    92,     6,    91,    12,    13,    14,    20,
      30,    31,    33,    34,    35,    38,    42,    43,    47,    49,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,    52,    53,    52,    94,    53,    56,    54,    54,    11,
      57,    59,    54,    51,    54,    53,    53,    51,    10,    14,
      37,    44,    47,    54,   105,   106,   107,    54,    54,    59,
      54,    96,    97,     4,    11,    59,    52,    14,    14,   105,
     107,    41,    48,   107,   107,    14,   107,    95,   107,    95,
      54,    57,    59,    59,   107,    59,    15,    16,    17,    18,
      19,    24,    25,    26,    27,    28,    29,    53,    14,   105,
      55,    14,    14,   105,     4,    41,    48,   107,    14,    55,
      57,    55,    55,    54,    54,    53,    58,    55,    52,    55,
      52,   107,   108,   107,    14,    14,    55,    14,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,    55,
      55,    53,    55,    55,    54,    54,    53,    53,   107,    53,
      53,    55,    14,    11,    21,    31,    30,    36,    55,    56,
      58,    54,    54,    54,    53,    53,    53,    53,    55,    14,
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
      68,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      74,    74,    75,    75,    76,    76,    77,    77,    77,    78,
      78,    78,    79,    79,    80,    80,    81,    82,    82,    83,
      83,    83,    83,    84,    84,    84,    85,    85,    86,    86,
      87,    87,    88,    89,    89,    89,    90,    90,    91,    92,
      92,    93,    94,    94,    95,    95,    96,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    99,    99,
      99,   100,   101,   101,   102,   103,   104,   105,   105,   105,
     106,   106,   106,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   108,   108,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     4,     3,     3,     2,     3,
       2,     1,     4,     2,     1,     3,     1,     1,     1,     3,
       0,     2,     1,     8,     7,     1,     3,     2,     1,     3,
       2,     1,     6,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     2,     1,     3,     3,     1,     1,
       4,     4,     3,     1,     1,     1,     2,     1,     9,     8,
       3,     1,     2,     3,     2,     0,     2,     1,     3,     3,
       1,     8,     4,     3,     1,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     4,     4,     7,     4,
       6,     6,     7,     7,     5,     5,     5,     5,     5,     8,
       5,     5,     8,    10,     8,     9,     9,     3,     3,     3,
       6,     6,     6,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     4,     1,     1,     1,
       1,     1,     4,     3,     1,     0
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
#line 1620 "y.tab.c"
    break;

  case 12:
#line 65 "task.y"
    {TInstall((yyvsp[-3].node)->varname,0,Fhead);}
#line 1626 "y.tab.c"
    break;

  case 15:
#line 72 "task.y"
    {
								FieldInstall(DeclType,(yyvsp[-1].node)->varname);
							}
#line 1634 "y.tab.c"
    break;

  case 16:
#line 77 "task.y"
    {DeclType = TLookup("int");}
#line 1640 "y.tab.c"
    break;

  case 17:
#line 78 "task.y"
    {DeclType = TLookup("string");}
#line 1646 "y.tab.c"
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
#line 1661 "y.tab.c"
    break;

  case 19:
#line 93 "task.y"
    {}
#line 1667 "y.tab.c"
    break;

  case 20:
#line 95 "task.y"
    {}
#line 1673 "y.tab.c"
    break;

  case 23:
#line 102 "task.y"
    {
																				//set the function list and fieldlist
																				if(!final_installation)
																				{
																					final_installation = 1;
																					CInstallFinal();
																				}

																				class = NULL;
																				inheritance = 0;
																				Fhead = Ftail = NULL;
																			    Mfhead = Mftail = NULL;
																				bind += 8;    
																			}
#line 1692 "y.tab.c"
    break;

  case 24:
#line 117 "task.y"
    {
																				//set the function list and fieldlist
																				if(!final_installation)
																				{
																					final_installation = 1;
																					CInstallFinal();
																				}

																				class = NULL;
																				inheritance = 0;
																				Fhead = Ftail = NULL;
																			    Mfhead = Mftail = NULL;
																				bind += 8;    
																			}
#line 1711 "y.tab.c"
    break;

  case 25:
#line 133 "task.y"
    {
				final_installation = 0;
				class = CInstall((yyvsp[0].node)->varname,NULL);
			}
#line 1720 "y.tab.c"
    break;

  case 26:
#line 138 "task.y"
    {
							inheritance = 1;
							final_installation = 0;
							class = CInstall((yyvsp[-2].node)->varname,(yyvsp[0].node)->varname);

							InheritMemberFields((yyvsp[0].node)->varname);
							InheritFunctions((yyvsp[0].node)->varname);
						}
#line 1733 "y.tab.c"
    break;

  case 29:
#line 152 "task.y"
    {
							//field of a class can be any primitive type,user-defined type or class type
							Class_FieldInstall((yyvsp[-1].node)->varname,DeclType,DeclClass);
						}
#line 1742 "y.tab.c"
    break;

  case 32:
#line 162 "task.y"
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
#line 1766 "y.tab.c"
    break;

  case 33:
#line 182 "task.y"
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
#line 1790 "y.tab.c"
    break;

  case 36:
#line 212 "task.y"
    {
				DeclType = TLookup("int");
				DeclClass = NULL;
			}
#line 1799 "y.tab.c"
    break;

  case 37:
#line 217 "task.y"
    {
				DeclType = TLookup("string");
				DeclClass = NULL;
			}
#line 1808 "y.tab.c"
    break;

  case 38:
#line 222 "task.y"
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
#line 1824 "y.tab.c"
    break;

  case 39:
#line 235 "task.y"
    {PDeclType = TLookup("int");}
#line 1830 "y.tab.c"
    break;

  case 40:
#line 236 "task.y"
    {PDeclType = TLookup("string");}
#line 1836 "y.tab.c"
    break;

  case 41:
#line 237 "task.y"
    {
					PDeclType = TLookup((yyvsp[0].node)->varname);
					if(!PDeclType)
					{
						printf("%s type not declared\n",(yyvsp[0].node)->varname);
						exit(1);
					}
				}
#line 1849 "y.tab.c"
    break;

  case 42:
#line 250 "task.y"
    {	
										GenerateHeader();
										PrintSymbolTable();
									}
#line 1858 "y.tab.c"
    break;

  case 49:
#line 268 "task.y"
    {
								if(!DeclClass)	//non-class variable
								{
									GInstall((yyvsp[0].node)->varname,DeclType,DeclClass,0,1);
								}
								else	//class variable
								{
									GInstall((yyvsp[0].node)->varname,DeclType,DeclClass,0,2);
								}
							}
#line 1873 "y.tab.c"
    break;

  case 50:
#line 279 "task.y"
    {
								if(DeclClass)
								{
									printf("Error : array of class not allowed\n");
									yyerror("");
									exit(1);
								}
								
								GInstall((yyvsp[-3].node)->varname,DeclType,DeclClass,1,(yyvsp[-1].node)->val);
							}
#line 1888 "y.tab.c"
    break;

  case 51:
#line 290 "task.y"
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
#line 1905 "y.tab.c"
    break;

  case 52:
#line 303 "task.y"
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
#line 1922 "y.tab.c"
    break;

  case 53:
#line 321 "task.y"
    {FuncType = TLookup("int");}
#line 1928 "y.tab.c"
    break;

  case 54:
#line 322 "task.y"
    {FuncType = TLookup("string");}
#line 1934 "y.tab.c"
    break;

  case 55:
#line 323 "task.y"
    {
						FuncType = TLookup((yyvsp[0].node)->varname);
						if(!FuncType)
						{
							printf("%s type not declared\n",(yyvsp[0].node)->varname);
							yyerror("");
							exit(1);
						}
					}
#line 1948 "y.tab.c"
    break;

  case 58:
#line 339 "task.y"
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
#line 1999 "y.tab.c"
    break;

  case 59:
#line 387 "task.y"
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
#line 2048 "y.tab.c"
    break;

  case 62:
#line 437 "task.y"
    {
							InsertParam((yyvsp[0].node)->varname,PDeclType);
						}
#line 2056 "y.tab.c"
    break;

  case 69:
#line 456 "task.y"
    {InsertLocalSymbol((yyvsp[0].node)->varname,DeclType);}
#line 2062 "y.tab.c"
    break;

  case 70:
#line 457 "task.y"
    {InsertLocalSymbol((yyvsp[0].node)->varname,DeclType);}
#line 2068 "y.tab.c"
    break;

  case 71:
#line 464 "task.y"
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
#line 2101 "y.tab.c"
    break;

  case 72:
#line 499 "task.y"
    {
			(yyval.node) = createTree(0,NULL,connector_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),(yyvsp[-1].node),NULL);
		}
#line 2109 "y.tab.c"
    break;

  case 73:
#line 504 "task.y"
    {
			(yyval.node) = createTree(0,NULL,connector_node,TLookup("void"),NULL,NULL,NULL,(yyvsp[-1].node),NULL);
		}
#line 2117 "y.tab.c"
    break;

  case 74:
#line 513 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2123 "y.tab.c"
    break;

  case 75:
#line 514 "task.y"
    {(yyval.node) = createTree(0,NULL,connector_node,TLookup("void"),NULL,NULL,(yyvsp[-1].node),(yyvsp[0].node),NULL);}
#line 2129 "y.tab.c"
    break;

  case 76:
#line 521 "task.y"
    {(yyval.node) = createTree(0,NULL,return_node,(yyvsp[-1].node)->ttype,NULL,NULL,(yyvsp[-1].node),NULL,NULL);}
#line 2135 "y.tab.c"
    break;

  case 77:
#line 526 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2141 "y.tab.c"
    break;

  case 78:
#line 527 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2147 "y.tab.c"
    break;

  case 79:
#line 528 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2153 "y.tab.c"
    break;

  case 80:
#line 529 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2159 "y.tab.c"
    break;

  case 81:
#line 530 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2165 "y.tab.c"
    break;

  case 82:
#line 531 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2171 "y.tab.c"
    break;

  case 83:
#line 532 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2177 "y.tab.c"
    break;

  case 84:
#line 533 "task.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 2183 "y.tab.c"
    break;

  case 85:
#line 534 "task.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 2189 "y.tab.c"
    break;

  case 86:
#line 535 "task.y"
    {(yyval.node) = (yyvsp[-3].node);}
#line 2195 "y.tab.c"
    break;

  case 87:
#line 538 "task.y"
    {		
											checkID((yyvsp[-3].node)->varname);    
											AssignCheckType((yyvsp[-3].node),(yyvsp[-1].node));
											(yyval.node) = createTree(0,NULL,assign_node,TLookup("void"),NULL,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
										}
#line 2205 "y.tab.c"
    break;

  case 88:
#line 545 "task.y"
    {
											checkID((yyvsp[-6].node)->varname);
											CheckIfArray((yyvsp[-6].node)->varname);
											CheckIntType((yyvsp[-4].node));
											AssignCheckType((yyvsp[-6].node),(yyvsp[-1].node));
											(yyval.node) = createTree(0,NULL,assignArray_node,TLookup("void"),NULL,NULL,(yyvsp[-6].node),(yyvsp[-4].node),(yyvsp[-1].node));
										}
#line 2217 "y.tab.c"
    break;

  case 89:
#line 553 "task.y"
    {
											AssignCheckType((yyvsp[-3].node),(yyvsp[-1].node));		
											(yyval.node) = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
										}
#line 2226 "y.tab.c"
    break;

  case 90:
#line 559 "task.y"
    {
											checkID((yyvsp[-5].node)->varname);
											//type of ID should not be int,string
											if((yyvsp[-5].node)->ttype == TLookup("string") || (yyvsp[-5].node)->ttype == TLookup("int"))
											{
												printf("Error: %s is not a user-defined type\n",(yyvsp[-5].node)->varname);
												yyerror("");
												exit(1);
											}

											struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);
											(yyval.node) = createTree(0,NULL,assign_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),tmp,NULL);
										}
#line 2244 "y.tab.c"
    break;

  case 91:
#line 573 "task.y"
    {
												struct tnode* tmp = createTree(0,NULL,alloc_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);

												(yyval.node) = createTree(0,NULL,assign_field_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),tmp,NULL);
											}
#line 2254 "y.tab.c"
    break;

  case 92:
#line 579 "task.y"
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
#line 2287 "y.tab.c"
    break;

  case 93:
#line 608 "task.y"
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
#line 2311 "y.tab.c"
    break;

  case 94:
#line 628 "task.y"
    {
											if(!(yyvsp[-2].node)->ctype)
											{
												printf("Error:%s is not a class variable\n",(yyvsp[-2].node)->varname);
												yyerror("");
												exit(1);
											}
											(yyval.node) = createTree(0,NULL,free_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),NULL,NULL);
										}
#line 2325 "y.tab.c"
    break;

  case 95:
#line 638 "task.y"
    {
											if(!(yyvsp[-2].node)->ctype)
											{
												printf("Error: not a class variable\n");
												yyerror("");
												exit(1);
											}
											(yyval.node) = createTree(0,NULL,free_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),NULL,NULL);
										}
#line 2339 "y.tab.c"
    break;

  case 96:
#line 648 "task.y"
    {
											if(!(yyvsp[-2].node)->ctype)
											{
												printf("Error:%s is not a class variable\n",(yyvsp[-2].node)->varname);
												yyerror("");
												exit(1);
											}
											(yyval.node) = createTree(0,NULL,free_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),NULL,NULL);
										}
#line 2353 "y.tab.c"
    break;

  case 97:
#line 658 "task.y"
    {
											if(!(yyvsp[-2].node)->ctype)
											{
												printf("Error: not a class variable\n");
												yyerror("");
												exit(1);
											}
											(yyval.node) = createTree(0,NULL,free_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),NULL,NULL);
										}
#line 2367 "y.tab.c"
    break;

  case 98:
#line 670 "task.y"
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
#line 2385 "y.tab.c"
    break;

  case 99:
#line 685 "task.y"
    {	
									checkID((yyvsp[-5].node)->varname);
									CheckIfArray((yyvsp[-5].node)->varname);
									CheckIntType((yyvsp[-3].node));
									(yyval.node) = createTree(0,NULL,readArray_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),(yyvsp[-3].node),NULL);
								}
#line 2396 "y.tab.c"
    break;

  case 100:
#line 692 "task.y"
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
#line 2412 "y.tab.c"
    break;

  case 101:
#line 706 "task.y"
    {
							if((yyvsp[-2].node)->ttype != TLookup("int") && (yyvsp[-2].node)->ttype != TLookup("string"))
							{
								printf("Incorrect type in write\n");
								exit(1);
							}
							(yyval.node) = createTree(0,NULL,write_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),NULL,NULL);
						}
#line 2425 "y.tab.c"
    break;

  case 102:
#line 716 "task.y"
    {
							CheckBoolType((yyvsp[-5].node));
							(yyval.node) = createTree(0,NULL,if_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),(yyvsp[-2].node),NULL);
						}
#line 2434 "y.tab.c"
    break;

  case 103:
#line 722 "task.y"
    {
							CheckBoolType((yyvsp[-7].node));
							(yyval.node) = createTree(0,NULL,ifElse_node,TLookup("void"),NULL,NULL,(yyvsp[-7].node),(yyvsp[-4].node),(yyvsp[-2].node));
						}
#line 2443 "y.tab.c"
    break;

  case 104:
#line 729 "task.y"
    {	
							CheckBoolType((yyvsp[-5].node));
							(yyval.node) = createTree(0,NULL,while_node,TLookup("void"),NULL,NULL,(yyvsp[-5].node),(yyvsp[-2].node),NULL);
						}
#line 2452 "y.tab.c"
    break;

  case 105:
#line 735 "task.y"
    {
							CheckBoolType((yyvsp[-2].node));
							(yyval.node) = createTree(0,NULL,Dowhile_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),(yyvsp[-6].node),NULL);
						}
#line 2461 "y.tab.c"
    break;

  case 106:
#line 741 "task.y"
    {			
							CheckBoolType((yyvsp[-2].node));
							(yyval.node) = createTree(0,NULL,repeat_node,TLookup("void"),NULL,NULL,(yyvsp[-2].node),(yyvsp[-6].node),NULL);
						}
#line 2470 "y.tab.c"
    break;

  case 107:
#line 748 "task.y"
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
#line 2487 "y.tab.c"
    break;

  case 108:
#line 761 "task.y"
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
#line 2512 "y.tab.c"
    break;

  case 109:
#line 782 "task.y"
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
#line 2547 "y.tab.c"
    break;

  case 110:
#line 814 "task.y"
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
#line 2583 "y.tab.c"
    break;

  case 111:
#line 846 "task.y"
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
#line 2618 "y.tab.c"
    break;

  case 112:
#line 877 "task.y"
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
#line 2637 "y.tab.c"
    break;

  case 113:
#line 893 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,plus_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2646 "y.tab.c"
    break;

  case 114:
#line 898 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,minus_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2655 "y.tab.c"
    break;

  case 115:
#line 903 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,mul_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2664 "y.tab.c"
    break;

  case 116:
#line 908 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,div_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2673 "y.tab.c"
    break;

  case 117:
#line 913 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,mod_node,TLookup("int"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2682 "y.tab.c"
    break;

  case 118:
#line 918 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,lt_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2691 "y.tab.c"
    break;

  case 119:
#line 923 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,gt_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2700 "y.tab.c"
    break;

  case 120:
#line 928 "task.y"
    {
							CheckCompType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,eq_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2709 "y.tab.c"
    break;

  case 121:
#line 933 "task.y"
    {
							CheckCompType((yyvsp[-2].node),(yyvsp[0].node));
						   	(yyval.node) = createTree(0,NULL,neq_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2718 "y.tab.c"
    break;

  case 122:
#line 938 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,lte_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2727 "y.tab.c"
    break;

  case 123:
#line 943 "task.y"
    {
							CheckType((yyvsp[-2].node),(yyvsp[0].node));
							(yyval.node) = createTree(0,NULL,gte_node,TLookup("bool"),NULL,NULL,(yyvsp[-2].node),(yyvsp[0].node),NULL);
						}
#line 2736 "y.tab.c"
    break;

  case 124:
#line 948 "task.y"
    {(yyval.node) = (yyvsp[-1].node);}
#line 2742 "y.tab.c"
    break;

  case 125:
#line 949 "task.y"
    {
							checkID((yyvsp[0].node)->varname);

							(yyval.node) = (yyvsp[0].node);
						}
#line 2752 "y.tab.c"
    break;

  case 126:
#line 955 "task.y"
    {
							checkID((yyvsp[-3].node)->varname); 
							CheckIfArray((yyvsp[-3].node)->varname);
							CheckIntType((yyvsp[-1].node));
							(yyval.node) = createTree(0,NULL,array_node,(yyvsp[-3].node)->ttype,NULL,NULL,(yyvsp[-3].node),(yyvsp[-1].node),NULL);
						}
#line 2763 "y.tab.c"
    break;

  case 127:
#line 962 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2769 "y.tab.c"
    break;

  case 128:
#line 963 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2775 "y.tab.c"
    break;

  case 129:
#line 964 "task.y"
    {(yyval.node) = createTree(0,NULL,null_node,TLookup("dummy"),NULL,NULL,NULL,NULL,NULL);}
#line 2781 "y.tab.c"
    break;

  case 130:
#line 965 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2787 "y.tab.c"
    break;

  case 131:
#line 966 "task.y"
    {(yyval.node) = (yyvsp[0].node);}
#line 2793 "y.tab.c"
    break;

  case 132:
#line 969 "task.y"
    {
									checkID((yyvsp[-3].node)->varname);
									CheckIfFunction((yyvsp[-3].node)->varname);
									struct Gsymbol* idx = GLookup((yyvsp[-3].node)->varname);

						   			(yyval.node) = createTree(0,NULL,function_node,idx->type,NULL,idx->name,(yyvsp[-3].node),(yyvsp[-1].node),NULL);

						   			CheckInformalParamList(idx -> ParamList,(yyvsp[-1].node));

									(yyval.node) -> Arglist = (yyvsp[-1].node);
								}
#line 2809 "y.tab.c"
    break;

  case 133:
#line 983 "task.y"
    {
									(yyval.node) = createTree(0,NULL,arg_node,TLookup("void"),NULL,NULL,(yyvsp[0].node),(yyvsp[-2].node),NULL);
								}
#line 2817 "y.tab.c"
    break;

  case 134:
#line 987 "task.y"
    {
									(yyval.node) = createTree(0,NULL,arg_node,TLookup("void"),NULL,NULL,(yyvsp[0].node),NULL,NULL);
								}
#line 2825 "y.tab.c"
    break;

  case 135:
#line 991 "task.y"
    {
									(yyval.node) = NULL;
								}
#line 2833 "y.tab.c"
    break;


#line 2837 "y.tab.c"

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
#line 996 "task.y"


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
	fp2 = fopen("tmp2.xsm","w");
   	fp_read = fopen(argv[1],"r");
  	yyin = fp_read;

	InitTypeTable();
   	yyparse();

   	return 0;
}
