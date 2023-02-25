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
#line 1 "parser.y"

#include <iostream>
#include <memory>
#include <map>
#include "table.hh"

extern int get_line_number();
extern void* arvore;

void send_error_message (Node* node, int code);
int yylex(void);
void yyerror (const char *msg);

SymbolTableStack symbol_table_stack{};
std::vector<std::pair<TokenVal, Symbol>> var_global_list = {};
int array_size=0;


#line 90 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_PR_INT = 3,                  /* TK_PR_INT  */
  YYSYMBOL_TK_PR_FLOAT = 4,                /* TK_PR_FLOAT  */
  YYSYMBOL_TK_PR_BOOL = 5,                 /* TK_PR_BOOL  */
  YYSYMBOL_TK_PR_CHAR = 6,                 /* TK_PR_CHAR  */
  YYSYMBOL_TK_PR_IF = 7,                   /* TK_PR_IF  */
  YYSYMBOL_TK_PR_THEN = 8,                 /* TK_PR_THEN  */
  YYSYMBOL_TK_PR_ELSE = 9,                 /* TK_PR_ELSE  */
  YYSYMBOL_TK_PR_WHILE = 10,               /* TK_PR_WHILE  */
  YYSYMBOL_TK_PR_INPUT = 11,               /* TK_PR_INPUT  */
  YYSYMBOL_TK_PR_OUTPUT = 12,              /* TK_PR_OUTPUT  */
  YYSYMBOL_TK_PR_RETURN = 13,              /* TK_PR_RETURN  */
  YYSYMBOL_TK_PR_FOR = 14,                 /* TK_PR_FOR  */
  YYSYMBOL_TK_OC_LE = 15,                  /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 16,                  /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 17,                  /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 18,                  /* TK_OC_NE  */
  YYSYMBOL_TK_OC_AND = 19,                 /* TK_OC_AND  */
  YYSYMBOL_TK_OC_OR = 20,                  /* TK_OC_OR  */
  YYSYMBOL_TK_LIT_INT = 21,                /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_FLOAT = 22,              /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_LIT_FALSE = 23,              /* TK_LIT_FALSE  */
  YYSYMBOL_TK_LIT_TRUE = 24,               /* TK_LIT_TRUE  */
  YYSYMBOL_TK_LIT_CHAR = 25,               /* TK_LIT_CHAR  */
  YYSYMBOL_TK_IDENTIFICADOR = 26,          /* TK_IDENTIFICADOR  */
  YYSYMBOL_TK_ERRO = 27,                   /* TK_ERRO  */
  YYSYMBOL_28_ = 28,                       /* '!'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '<'  */
  YYSYMBOL_35_ = 35,                       /* '>'  */
  YYSYMBOL_36_ = 36,                       /* '='  */
  YYSYMBOL_37_ = 37,                       /* '^'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '['  */
  YYSYMBOL_41_ = 41,                       /* ']'  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_programa = 47,                  /* programa  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_lista_elem = 49,                /* lista_elem  */
  YYSYMBOL_elemento = 50,                  /* elemento  */
  YYSYMBOL_var_global = 51,                /* var_global  */
  YYSYMBOL_lista_id_var_global = 52,       /* lista_id_var_global  */
  YYSYMBOL_id_var_global = 53,             /* id_var_global  */
  YYSYMBOL_lista_dimensoes = 54,           /* lista_dimensoes  */
  YYSYMBOL_funcao = 55,                    /* funcao  */
  YYSYMBOL_56_2 = 56,                      /* $@2  */
  YYSYMBOL_lista_parametros = 57,          /* lista_parametros  */
  YYSYMBOL_parametro = 58,                 /* parametro  */
  YYSYMBOL_corpo_funcao = 59,              /* corpo_funcao  */
  YYSYMBOL_bloco_comandos = 60,            /* bloco_comandos  */
  YYSYMBOL_61_3 = 61,                      /* $@3  */
  YYSYMBOL_lista_comandos = 62,            /* lista_comandos  */
  YYSYMBOL_comando_simples = 63,           /* comando_simples  */
  YYSYMBOL_var_local = 64,                 /* var_local  */
  YYSYMBOL_lista_var_local_int = 65,       /* lista_var_local_int  */
  YYSYMBOL_var_local_int = 66,             /* var_local_int  */
  YYSYMBOL_67_4 = 67,                      /* $@4  */
  YYSYMBOL_lista_var_local_float = 68,     /* lista_var_local_float  */
  YYSYMBOL_var_local_float = 69,           /* var_local_float  */
  YYSYMBOL_70_5 = 70,                      /* $@5  */
  YYSYMBOL_lista_var_local_bool = 71,      /* lista_var_local_bool  */
  YYSYMBOL_var_local_bool = 72,            /* var_local_bool  */
  YYSYMBOL_73_6 = 73,                      /* $@6  */
  YYSYMBOL_lista_var_local_char = 74,      /* lista_var_local_char  */
  YYSYMBOL_var_local_char = 75,            /* var_local_char  */
  YYSYMBOL_76_7 = 76,                      /* $@7  */
  YYSYMBOL_atribuicao = 77,                /* atribuicao  */
  YYSYMBOL_identificador = 78,             /* identificador  */
  YYSYMBOL_lista_indices = 79,             /* lista_indices  */
  YYSYMBOL_cham_funcao = 80,               /* cham_funcao  */
  YYSYMBOL_81_8 = 81,                      /* $@8  */
  YYSYMBOL_lista_argumentos = 82,          /* lista_argumentos  */
  YYSYMBOL_op_retorno = 83,                /* op_retorno  */
  YYSYMBOL_con_fluxo = 84,                 /* con_fluxo  */
  YYSYMBOL_expressao_7 = 85,               /* expressao_7  */
  YYSYMBOL_expressao_6 = 86,               /* expressao_6  */
  YYSYMBOL_expressao_5 = 87,               /* expressao_5  */
  YYSYMBOL_expressao_4 = 88,               /* expressao_4  */
  YYSYMBOL_expressao_3 = 89,               /* expressao_3  */
  YYSYMBOL_expressao_2 = 90,               /* expressao_2  */
  YYSYMBOL_expressao_1 = 91,               /* expressao_1  */
  YYSYMBOL_operando = 92,                  /* operando  */
  YYSYMBOL_literal = 93,                   /* literal  */
  YYSYMBOL_tipo_primitivo = 94             /* tipo_primitivo  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  49
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,    28,     2,     2,     2,    32,     2,     2,
      42,    43,    30,    33,    39,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      34,    36,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    40,     2,    41,    37,     2,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   107,   107,   107,   109,   110,   119,   120,   123,   135,
     136,   138,   151,   167,   170,   175,   175,   189,   190,   191,
     193,   195,   198,   198,   200,   201,   209,   210,   211,   212,
     213,   214,   219,   220,   221,   222,   226,   227,   236,   246,
     263,   263,   283,   284,   293,   303,   320,   320,   341,   342,
     351,   361,   378,   378,   399,   400,   409,   418,   435,   435,
     457,   464,   472,   484,   485,   488,   488,   495,   496,   497,
     500,   504,   507,   516,   522,   523,   527,   528,   533,   534,
     537,   541,   542,   545,   548,   551,   556,   557,   560,   564,
     565,   568,   571,   575,   576,   577,   579,   582,   583,   584,
     587,   588,   589,   590,   591,   593,   594,   595,   596
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
  "\"end of file\"", "error", "\"invalid token\"", "TK_PR_INT",
  "TK_PR_FLOAT", "TK_PR_BOOL", "TK_PR_CHAR", "TK_PR_IF", "TK_PR_THEN",
  "TK_PR_ELSE", "TK_PR_WHILE", "TK_PR_INPUT", "TK_PR_OUTPUT",
  "TK_PR_RETURN", "TK_PR_FOR", "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ",
  "TK_OC_NE", "TK_OC_AND", "TK_OC_OR", "TK_LIT_INT", "TK_LIT_FLOAT",
  "TK_LIT_FALSE", "TK_LIT_TRUE", "TK_LIT_CHAR", "TK_IDENTIFICADOR",
  "TK_ERRO", "'!'", "'-'", "'*'", "'/'", "'%'", "'+'", "'<'", "'>'", "'='",
  "'^'", "';'", "','", "'['", "']'", "'('", "')'", "'{'", "'}'", "$accept",
  "programa", "$@1", "lista_elem", "elemento", "var_global",
  "lista_id_var_global", "id_var_global", "lista_dimensoes", "funcao",
  "$@2", "lista_parametros", "parametro", "corpo_funcao", "bloco_comandos",
  "$@3", "lista_comandos", "comando_simples", "var_local",
  "lista_var_local_int", "var_local_int", "$@4", "lista_var_local_float",
  "var_local_float", "$@5", "lista_var_local_bool", "var_local_bool",
  "$@6", "lista_var_local_char", "var_local_char", "$@7", "atribuicao",
  "identificador", "lista_indices", "cham_funcao", "$@8",
  "lista_argumentos", "op_retorno", "con_fluxo", "expressao_7",
  "expressao_6", "expressao_5", "expressao_4", "expressao_3",
  "expressao_2", "expressao_1", "operando", "literal", "tipo_primitivo", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-66)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -73,    26,    74,   -73,   -73,   -73,   -73,   -73,   -73,    74,
     -73,   -73,     8,   -73,    46,    61,   -73,    10,     0,   -73,
      32,   -73,    29,    74,    34,   -73,    69,   -73,    30,   -73,
      71,   -73,    74,    66,   -73,   -73,   -73,   -73,   -73,     3,
      79,    85,    86,    87,    72,    73,    39,    56,   -73,    75,
      78,   -73,   -73,    81,   -73,   -73,   -73,   103,   -73,    -7,
     104,   -73,    -3,   106,   -73,     2,   107,   -73,     4,    39,
      39,   -73,   -73,   -73,   -73,   -73,    39,    39,    39,   -73,
     -73,   105,   108,    84,     5,    42,    52,   -73,   -73,   -73,
      39,    82,   -73,     3,    39,   111,    79,   -73,   113,    85,
     -73,   115,    86,   -73,   116,    87,   -73,    -8,    -6,   -73,
     -73,    -5,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    35,   105,    39,   -73,   105,
      39,   -73,    39,   -73,    39,   -73,    39,   -73,   124,    66,
     -73,   108,    84,     5,     5,    42,    42,    42,    42,    52,
      52,   -73,   -73,   -73,    39,   -73,    80,     7,   105,   105,
     105,   105,    66,   -73,   105,   -73,    39,   125,   -73,    66,
     -73
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     1,   105,   106,   108,   107,     3,     4,
       6,     7,     0,     5,    11,     0,     9,     0,     0,     8,
       0,    13,     0,    17,    11,    10,     0,    12,     0,    18,
       0,    14,     0,     0,    20,    19,    22,    16,    21,    24,
      36,    42,    48,    54,     0,     0,     0,    61,    31,     0,
       0,    26,    27,     0,    30,    29,    28,    39,    32,    36,
      45,    33,    42,    51,    34,    48,    57,    35,    54,     0,
       0,   100,   101,   104,   103,   102,     0,     0,     0,    97,
      99,    70,    74,    76,    78,    81,    86,    89,    93,    98,
       0,     0,    23,    24,     0,     0,    36,    37,     0,    42,
      43,     0,    48,    49,     0,    54,    55,     0,     0,    96,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    67,    25,    60,
       0,    38,     0,    44,     0,    50,     0,    56,     0,     0,
      94,    75,    77,    79,    80,    84,    85,    82,    83,    88,
      87,    90,    91,    92,     0,    62,     0,    68,    41,    47,
      53,    59,     0,    73,    64,    66,    67,    71,    69,     0,
      72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,   -73,   126,   -73,   -73,   -73,   117,   -73,   -73,
     -73,   -73,   101,   -73,   -33,   -73,    45,   -73,   -73,   -48,
     -73,   -73,   -44,   -73,   -73,   -43,   -73,   -73,   -51,   -73,
     -73,   -73,   -37,   -73,   -36,   -73,   -27,   -73,   -73,   -45,
      28,    31,   -11,   -24,   -13,   -72,   -73,   -73,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     8,     9,    10,    15,    16,    22,    11,
      18,    28,    29,    37,    48,    39,    49,    50,    51,    58,
      59,    95,    61,    62,    98,    64,    65,   101,    67,    68,
     104,    52,    79,   125,    80,    91,   156,    55,    56,   157,
      82,    83,    84,    85,    86,    87,    88,    89,    12
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    81,    53,    54,   109,   110,    40,    41,    42,    43,
      44,    97,   112,    45,   112,   112,    46,   106,   100,    57,
     116,   117,   103,    60,   107,   108,     3,   112,    63,    47,
      66,    21,    96,   111,    14,   138,    99,   139,   140,   118,
     119,   102,    23,   105,    30,   126,   166,    36,   131,   129,
     151,   152,   153,    30,   137,   133,    53,    54,    24,   135,
      71,    72,    73,    74,    75,    47,    26,    76,    77,    32,
      27,   120,   154,    33,    17,   121,   155,     4,     5,     6,
       7,    78,   122,   123,   124,   158,    17,   159,   -15,   160,
      31,   161,   145,   146,   147,   148,    90,    34,   -65,    19,
      20,   114,   115,   143,   144,    57,   163,   149,   150,   164,
      36,    60,    63,    66,    69,    70,    93,    94,   -40,   -46,
      92,   -52,   -58,   165,   127,   112,   130,   113,   132,   167,
     134,   136,   162,    35,   169,    13,   170,    25,   128,   168,
     141,     0,     0,     0,   142
};

static const yytype_int16 yycheck[] =
{
      33,    46,    39,    39,    76,    77,     3,     4,     5,     6,
       7,    59,    20,    10,    20,    20,    13,    68,    62,    26,
      15,    16,    65,    26,    69,    70,     0,    20,    26,    26,
      26,    21,    39,    78,    26,    43,    39,    43,    43,    34,
      35,    39,    42,    39,    23,    90,    39,    44,    96,    94,
     122,   123,   124,    32,   105,    99,    93,    93,    26,   102,
      21,    22,    23,    24,    25,    26,    37,    28,    29,    39,
      41,    29,    37,    43,    40,    33,    41,     3,     4,     5,
       6,    42,    30,    31,    32,   130,    40,   132,    42,   134,
      21,   136,   116,   117,   118,   119,    40,    26,    42,    38,
      39,    17,    18,   114,   115,    26,   139,   120,   121,   154,
      44,    26,    26,    26,    42,    42,    38,    36,    15,    15,
      45,    15,    15,    43,    42,    20,    15,    19,    15,   162,
      15,    15,     8,    32,     9,     9,   169,    20,    93,   166,
     112,    -1,    -1,    -1,   113
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    48,     0,     3,     4,     5,     6,    49,    50,
      51,    55,    94,    49,    26,    52,    53,    40,    56,    38,
      39,    21,    54,    42,    26,    53,    37,    41,    57,    58,
      94,    21,    39,    43,    26,    58,    44,    59,    60,    61,
       3,     4,     5,     6,     7,    10,    13,    26,    60,    62,
      63,    64,    77,    78,    80,    83,    84,    26,    65,    66,
      26,    68,    69,    26,    71,    72,    26,    74,    75,    42,
      42,    21,    22,    23,    24,    25,    28,    29,    42,    78,
      80,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      40,    81,    45,    38,    36,    67,    39,    65,    70,    39,
      68,    73,    39,    71,    76,    39,    74,    85,    85,    91,
      91,    85,    20,    19,    17,    18,    15,    16,    34,    35,
      29,    33,    30,    31,    32,    79,    85,    42,    62,    85,
      15,    65,    15,    68,    15,    71,    15,    74,    43,    43,
      43,    86,    87,    88,    88,    89,    89,    89,    89,    90,
      90,    91,    91,    91,    37,    41,    82,    85,    85,    85,
      85,    85,     8,    60,    85,    43,    39,    60,    82,     9,
      60
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    48,    47,    49,    49,    50,    50,    51,    52,
      52,    53,    53,    54,    54,    56,    55,    57,    57,    57,
      58,    59,    61,    60,    62,    62,    63,    63,    63,    63,
      63,    63,    64,    64,    64,    64,    65,    65,    65,    66,
      67,    66,    68,    68,    68,    69,    70,    69,    71,    71,
      71,    72,    73,    72,    74,    74,    74,    75,    76,    75,
      77,    78,    78,    79,    79,    81,    80,    82,    82,    82,
      83,    84,    84,    84,    85,    85,    86,    86,    87,    87,
      87,    88,    88,    88,    88,    88,    89,    89,    89,    90,
      90,    90,    90,    91,    91,    91,    91,    92,    92,    92,
      93,    93,    93,    93,    93,    94,    94,    94,    94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     3,     1,
       3,     1,     4,     1,     3,     0,     7,     0,     1,     3,
       2,     1,     0,     4,     0,     3,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     0,     2,     3,     1,
       0,     4,     0,     2,     3,     1,     0,     4,     0,     2,
       3,     1,     0,     4,     0,     2,     3,     1,     0,     4,
       3,     1,     4,     1,     3,     0,     5,     0,     1,     3,
       2,     6,     8,     5,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
  case 2: /* $@1: %empty  */
#line 107 "parser.y"
          { symbol_table_stack.push_new(); }
#line 1564 "parser.tab.c"
    break;

  case 3: /* programa: $@1 lista_elem  */
#line 107 "parser.y"
                                                        {(yyval.valor_lexico) = (yyvsp[0].valor_lexico); arvore = (yyval.valor_lexico); symbol_table_stack.pop(); }
#line 1570 "parser.tab.c"
    break;

  case 4: /* lista_elem: %empty  */
#line 109 "parser.y"
                   {(yyval.valor_lexico) = nullptr;}
#line 1576 "parser.tab.c"
    break;

  case 5: /* lista_elem: elemento lista_elem  */
#line 110 "parser.y"
                                {
            if ((yyval.valor_lexico)!=nullptr) {
                (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); 
                (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
            } else {
                (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
            }
        }
#line 1589 "parser.tab.c"
    break;

  case 6: /* elemento: var_global  */
#line 119 "parser.y"
                     {(yyval.valor_lexico) = (yyvsp[0].valor_lexico); var_global_list.clear();}
#line 1595 "parser.tab.c"
    break;

  case 7: /* elemento: funcao  */
#line 120 "parser.y"
                 {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1601 "parser.tab.c"
    break;

  case 8: /* var_global: tipo_primitivo lista_id_var_global ';'  */
#line 123 "parser.y"
                                                   { (yyval.valor_lexico) = nullptr; 
                                                     // adiciona todas as variaveis de uma vez na tabela
                                                     for (auto pair : var_global_list) {
                                                        Symbol& s = pair.second;
                                                        s.type = (yyvsp[-2].valor_lexico)->get_node_type();
                                                        if (s.type == Type::CHARACTER && s.kind == Kind::ARRAY)
                                                            exit(ERR_CHAR_VECTOR);
                                                        s.size *= get_size_from_type((yyvsp[-2].valor_lexico)->get_node_type());
                                                        symbol_table_stack.emplace_top(pair);
                                                     }
                                                   }
#line 1617 "parser.tab.c"
    break;

  case 9: /* lista_id_var_global: id_var_global  */
#line 135 "parser.y"
                                   {(yyval.valor_lexico) = nullptr;}
#line 1623 "parser.tab.c"
    break;

  case 10: /* lista_id_var_global: lista_id_var_global ',' id_var_global  */
#line 136 "parser.y"
                                                           {(yyval.valor_lexico) = nullptr;}
#line 1629 "parser.tab.c"
    break;

  case 11: /* id_var_global: TK_IDENTIFICADOR  */
#line 138 "parser.y"
                                {   if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
                                        exit(ERR_DECLARED);
                                    }
                                        Symbol s{
                                        (yyvsp[0].valor_lexico)->get_line_no(),
                                        Kind::VARIABLE,
                                        Type::TYPE_ERROR,
                                        1,
                                        nullptr
                                    };
                                    var_global_list.push_back(std::make_pair((yyvsp[0].valor_lexico)->get_token_val(), s));
                                    (yyval.valor_lexico)=nullptr; delete (yyvsp[0].valor_lexico);
                                }
#line 1647 "parser.tab.c"
    break;

  case 12: /* id_var_global: TK_IDENTIFICADOR '[' lista_dimensoes ']'  */
#line 151 "parser.y"
                                                        { 
                                                          if (symbol_table_stack.is_declared((yyvsp[-3].valor_lexico)->get_token_val())) {
                                                              exit(ERR_DECLARED);
                                                          }
                                                          Symbol s{
                                                              (yyvsp[-3].valor_lexico)->get_line_no(),
                                                              Kind::ARRAY,
                                                              Type::TYPE_ERROR,
                                                              (size_t) array_size,
                                                              nullptr
                                                          };
                                                          var_global_list.push_back(std::make_pair((yyvsp[-3].valor_lexico)->get_token_val(), s));
                                                          array_size = 0;
                                                          (yyval.valor_lexico)=nullptr; delete (yyvsp[-3].valor_lexico);
                                                        }
#line 1667 "parser.tab.c"
    break;

  case 13: /* lista_dimensoes: TK_LIT_INT  */
#line 167 "parser.y"
                            { array_size = get<int>((yyvsp[0].valor_lexico)->get_token_val()); 
                              (yyval.valor_lexico)=nullptr; delete (yyvsp[0].valor_lexico);
                            }
#line 1675 "parser.tab.c"
    break;

  case 14: /* lista_dimensoes: lista_dimensoes '^' TK_LIT_INT  */
#line 170 "parser.y"
                                                { array_size *= get<int>((yyvsp[0].valor_lexico)->get_token_val()); 
                                                  (yyval.valor_lexico)=nullptr; delete (yyvsp[-1].valor_lexico); delete (yyvsp[0].valor_lexico);
                                                }
#line 1683 "parser.tab.c"
    break;

  case 15: /* $@2: %empty  */
#line 175 "parser.y"
                                        { if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
					                          send_error_message((yyvsp[0].valor_lexico), ERR_DECLARED);
                                              exit(ERR_DECLARED);
                                          }
                                            Symbol s{
                                                        (yyvsp[0].valor_lexico)->get_line_no(), 
                                                        Kind::FUNCTION, 
                                                        (yyvsp[-1].valor_lexico)->get_node_type(), 
                                                        get_size_from_type((yyvsp[-1].valor_lexico)->get_node_type()), 
                                                        (yyvsp[0].valor_lexico)
                                                    };
                                            symbol_table_stack.insert_top((yyvsp[0].valor_lexico)->get_token_val(), s);
                                        }
#line 1701 "parser.tab.c"
    break;

  case 16: /* funcao: tipo_primitivo TK_IDENTIFICADOR $@2 '(' lista_parametros ')' corpo_funcao  */
#line 187 "parser.y"
                                                                                { (yyval.valor_lexico) = (yyvsp[-5].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));}
#line 1707 "parser.tab.c"
    break;

  case 17: /* lista_parametros: %empty  */
#line 189 "parser.y"
                         {(yyval.valor_lexico) = nullptr;}
#line 1713 "parser.tab.c"
    break;

  case 18: /* lista_parametros: parametro  */
#line 190 "parser.y"
                            {(yyval.valor_lexico) = nullptr;}
#line 1719 "parser.tab.c"
    break;

  case 19: /* lista_parametros: lista_parametros ',' parametro  */
#line 191 "parser.y"
                                                 {(yyval.valor_lexico) = nullptr;}
#line 1725 "parser.tab.c"
    break;

  case 20: /* parametro: tipo_primitivo TK_IDENTIFICADOR  */
#line 193 "parser.y"
                                           {(yyval.valor_lexico)=nullptr; delete (yyvsp[0].valor_lexico);}
#line 1731 "parser.tab.c"
    break;

  case 21: /* corpo_funcao: bloco_comandos  */
#line 195 "parser.y"
                             {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1737 "parser.tab.c"
    break;

  case 22: /* $@3: %empty  */
#line 198 "parser.y"
                    { symbol_table_stack.push_new(); }
#line 1743 "parser.tab.c"
    break;

  case 23: /* bloco_comandos: '{' $@3 lista_comandos '}'  */
#line 198 "parser.y"
                                                                          {(yyval.valor_lexico) = (yyvsp[-1].valor_lexico); symbol_table_stack.pop(); }
#line 1749 "parser.tab.c"
    break;

  case 24: /* lista_comandos: %empty  */
#line 200 "parser.y"
                       {(yyval.valor_lexico) = nullptr;}
#line 1755 "parser.tab.c"
    break;

  case 25: /* lista_comandos: comando_simples ';' lista_comandos  */
#line 201 "parser.y"
                                                   {
                if ((yyvsp[-2].valor_lexico) != nullptr) {
                    (yyval.valor_lexico) = (yyvsp[-2].valor_lexico); 
                    (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                } else {
                    (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                }}
#line 1767 "parser.tab.c"
    break;

  case 26: /* comando_simples: var_local  */
#line 209 "parser.y"
                           {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1773 "parser.tab.c"
    break;

  case 27: /* comando_simples: atribuicao  */
#line 210 "parser.y"
                            {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1779 "parser.tab.c"
    break;

  case 28: /* comando_simples: con_fluxo  */
#line 211 "parser.y"
                           {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1785 "parser.tab.c"
    break;

  case 29: /* comando_simples: op_retorno  */
#line 212 "parser.y"
                            {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1791 "parser.tab.c"
    break;

  case 30: /* comando_simples: cham_funcao  */
#line 213 "parser.y"
                             {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1797 "parser.tab.c"
    break;

  case 31: /* comando_simples: bloco_comandos  */
#line 214 "parser.y"
                                {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1803 "parser.tab.c"
    break;

  case 32: /* var_local: TK_PR_INT lista_var_local_int  */
#line 219 "parser.y"
                                         {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1809 "parser.tab.c"
    break;

  case 33: /* var_local: TK_PR_FLOAT lista_var_local_float  */
#line 220 "parser.y"
                                             {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1815 "parser.tab.c"
    break;

  case 34: /* var_local: TK_PR_BOOL lista_var_local_bool  */
#line 221 "parser.y"
                                           {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1821 "parser.tab.c"
    break;

  case 35: /* var_local: TK_PR_CHAR lista_var_local_char  */
#line 222 "parser.y"
                                           {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1827 "parser.tab.c"
    break;

  case 36: /* lista_var_local_int: %empty  */
#line 226 "parser.y"
                            {(yyval.valor_lexico) = nullptr;}
#line 1833 "parser.tab.c"
    break;

  case 37: /* lista_var_local_int: var_local_int lista_var_local_int  */
#line 228 "parser.y"
                   {
                        if ((yyvsp[-1].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 1846 "parser.tab.c"
    break;

  case 38: /* lista_var_local_int: var_local_int ',' lista_var_local_int  */
#line 237 "parser.y"
                   {
                        if ((yyvsp[-2].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-2].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 1859 "parser.tab.c"
    break;

  case 39: /* var_local_int: TK_IDENTIFICADOR  */
#line 246 "parser.y"
                                { (yyval.valor_lexico) = nullptr;
                                    if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
                                        send_error_message((yyvsp[0].valor_lexico), ERR_DECLARED);
                                        delete (yyvsp[0].valor_lexico);
                                        exit(ERR_DECLARED);
                                    }
                                    /*Insere na tabela de simbolos e apaga nodo*/;
                                    Symbol s{
                                                (yyvsp[0].valor_lexico)->get_line_no(), 
                                                Kind::VARIABLE, 
                                                Type::INTEGER, 
                                                get_size_from_type(Type::INTEGER), 
                                                nullptr
                                            };
                                    symbol_table_stack.insert_top((yyvsp[0].valor_lexico)->get_token_val(), s);
                                    delete (yyvsp[0].valor_lexico);
                                  }
#line 1881 "parser.tab.c"
    break;

  case 40: /* $@4: %empty  */
#line 263 "parser.y"
                                { if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
             				            send_error_message((yyvsp[0].valor_lexico), ERR_DECLARED);
                                        delete (yyvsp[0].valor_lexico);
                                        exit(ERR_DECLARED);
                                  }}
#line 1891 "parser.tab.c"
    break;

  case 41: /* var_local_int: TK_IDENTIFICADOR $@4 TK_OC_LE expressao_7  */
#line 267 "parser.y"
                                                          { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-3].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                                                            (yyvsp[-3].valor_lexico)->set_node_type(Type::INTEGER);
                                                            int exit_code = get_char_err((yyvsp[-3].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type());
                                                            if (exit_code > 0) exit(exit_code);
                                                            Symbol s{
                                                                (yyvsp[-3].valor_lexico)->get_line_no(), 
                                                                Kind::VARIABLE, 
                                                                Type::INTEGER, 
                                                                get_size_from_type(Type::INTEGER), 
                                                                (yyvsp[-1].valor_lexico)
                                                            };
                                                            symbol_table_stack.insert_top((yyvsp[-3].valor_lexico)->get_token_val(), s);
                                                            (yyval.valor_lexico)->set_node_type(Type::INTEGER);
                                                          }
#line 1910 "parser.tab.c"
    break;

  case 42: /* lista_var_local_float: %empty  */
#line 283 "parser.y"
                              {(yyval.valor_lexico) = nullptr;}
#line 1916 "parser.tab.c"
    break;

  case 43: /* lista_var_local_float: var_local_float lista_var_local_float  */
#line 285 "parser.y"
                     {
                        if ((yyvsp[-1].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 1929 "parser.tab.c"
    break;

  case 44: /* lista_var_local_float: var_local_float ',' lista_var_local_float  */
#line 294 "parser.y"
                     {
                        if ((yyvsp[-2].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-2].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 1942 "parser.tab.c"
    break;

  case 45: /* var_local_float: TK_IDENTIFICADOR  */
#line 303 "parser.y"
                                  { (yyval.valor_lexico) = nullptr;
                                    if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
                                    	send_error_message((yyvsp[0].valor_lexico), ERR_DECLARED);
                                        delete (yyvsp[0].valor_lexico);
                                        exit(ERR_DECLARED);
                                    }
                                    /*Insere na tabela de simbolos e apaga nodo*/;
                                    Symbol s{
                                                (yyvsp[0].valor_lexico)->get_line_no(), 
                                                Kind::VARIABLE, 
                                                Type::FLOATING, 
                                                get_size_from_type(Type::FLOATING), 
                                                nullptr
                                            };
                                    symbol_table_stack.insert_top((yyvsp[0].valor_lexico)->get_token_val(), s);
                                    delete (yyvsp[0].valor_lexico);
                                  }
#line 1964 "parser.tab.c"
    break;

  case 46: /* $@5: %empty  */
#line 320 "parser.y"
                                  { if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
               				send_error_message((yyvsp[0].valor_lexico), ERR_DECLARED);
                                        delete (yyvsp[0].valor_lexico);
                                        exit(ERR_DECLARED);
                                    }}
#line 1974 "parser.tab.c"
    break;

  case 47: /* var_local_float: TK_IDENTIFICADOR $@5 TK_OC_LE expressao_7  */
#line 324 "parser.y"
                                                            { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-3].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                                                            // Verifica erro de conversão
                                                            (yyvsp[-3].valor_lexico)->set_node_type(Type::FLOATING);
                                                            int exit_code = get_char_err((yyvsp[-3].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type());
                                                            if (exit_code > 0) exit(exit_code);
                                                            Symbol s{
                                                                (yyvsp[-3].valor_lexico)->get_line_no(), 
                                                                Kind::VARIABLE, 
                                                                Type::FLOATING, 
                                                                get_size_from_type(Type::FLOATING), 
                                                                (yyvsp[-1].valor_lexico)
                                                            };
                                                            symbol_table_stack.insert_top((yyvsp[-3].valor_lexico)->get_token_val(), s);
                                                            (yyval.valor_lexico)->set_node_type(Type::FLOATING);
                                                          }
#line 1994 "parser.tab.c"
    break;

  case 48: /* lista_var_local_bool: %empty  */
#line 341 "parser.y"
                             {(yyval.valor_lexico) = nullptr;}
#line 2000 "parser.tab.c"
    break;

  case 49: /* lista_var_local_bool: var_local_bool lista_var_local_bool  */
#line 343 "parser.y"
                    {
                        if ((yyvsp[-1].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 2013 "parser.tab.c"
    break;

  case 50: /* lista_var_local_bool: var_local_bool ',' lista_var_local_bool  */
#line 352 "parser.y"
                    {
                        if ((yyvsp[-2].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-2].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 2026 "parser.tab.c"
    break;

  case 51: /* var_local_bool: TK_IDENTIFICADOR  */
#line 361 "parser.y"
                                 { (yyval.valor_lexico) = nullptr; 
                                   if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
                                   	send_error_message((yyvsp[0].valor_lexico), ERR_DECLARED);
                                        delete (yyvsp[0].valor_lexico);
                                        exit(ERR_DECLARED);
                                   }
                                   /*Insere na tabela de simbolos e apaga nodo*/;
                                   Symbol s{
                                            (yyvsp[0].valor_lexico)->get_line_no(), 
                                            Kind::VARIABLE, 
                                            Type::BOOLEAN, 
                                            get_size_from_type(Type::BOOLEAN), 
                                            nullptr
                                        };
                                   symbol_table_stack.insert_top((yyvsp[0].valor_lexico)->get_token_val(), s);
                                   delete (yyvsp[0].valor_lexico);
                                }
#line 2048 "parser.tab.c"
    break;

  case 52: /* $@6: %empty  */
#line 378 "parser.y"
                                 { if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
              			    send_error_message((yyvsp[0].valor_lexico), ERR_DECLARED);
                                    delete (yyvsp[0].valor_lexico);
                                    exit(ERR_DECLARED);
                                }}
#line 2058 "parser.tab.c"
    break;

  case 53: /* var_local_bool: TK_IDENTIFICADOR $@6 TK_OC_LE expressao_7  */
#line 382 "parser.y"
                                                        { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-3].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                                                          // Verifica erro de conversão
                                                          (yyvsp[-3].valor_lexico)->set_node_type(Type::BOOLEAN);
                                                          int exit_code = get_char_err((yyvsp[-3].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type());
                                                          if (exit_code > 0) exit(exit_code);
                                                          Symbol s{
                                                              (yyvsp[-3].valor_lexico)->get_line_no(), 
                                                              Kind::VARIABLE, 
                                                              Type::BOOLEAN, 
                                                              get_size_from_type(Type::BOOLEAN), 
                                                              (yyvsp[-1].valor_lexico)
                                                          };
                                                          symbol_table_stack.insert_top((yyvsp[-3].valor_lexico)->get_token_val(), s);
                                                          (yyval.valor_lexico)->set_node_type(Type::BOOLEAN);
                                                      }
#line 2078 "parser.tab.c"
    break;

  case 54: /* lista_var_local_char: %empty  */
#line 399 "parser.y"
                             {(yyval.valor_lexico) = nullptr;}
#line 2084 "parser.tab.c"
    break;

  case 55: /* lista_var_local_char: var_local_char lista_var_local_char  */
#line 401 "parser.y"
                    {
                        if ((yyvsp[-1].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 2097 "parser.tab.c"
    break;

  case 56: /* lista_var_local_char: var_local_char ',' lista_var_local_char  */
#line 410 "parser.y"
                    {
                        if ((yyvsp[-2].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-2].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 2110 "parser.tab.c"
    break;

  case 57: /* var_local_char: TK_IDENTIFICADOR  */
#line 418 "parser.y"
                                 {  if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
					send_error_message((yyvsp[0].valor_lexico), ERR_DECLARED);
                                        delete (yyvsp[0].valor_lexico);
                                        exit(ERR_DECLARED);
                                    }
                                    (yyval.valor_lexico) = nullptr; 
                                    /*Insere na tabela de simbolos e apaga nodo*/;
                                    Symbol s{
                                            (yyvsp[0].valor_lexico)->get_line_no(), 
                                            Kind::VARIABLE, 
                                            Type::CHARACTER, 
                                            get_size_from_type(Type::CHARACTER), 
                                            nullptr
                                        };
                                    symbol_table_stack.insert_top((yyvsp[0].valor_lexico)->get_token_val(), s);
                                    delete (yyvsp[0].valor_lexico);
                                 }
#line 2132 "parser.tab.c"
    break;

  case 58: /* $@7: %empty  */
#line 435 "parser.y"
                                 {
                if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
                    send_error_message((yyvsp[0].valor_lexico), ERR_DECLARED);
                    delete (yyvsp[0].valor_lexico);
                    exit(ERR_DECLARED);
                }}
#line 2143 "parser.tab.c"
    break;

  case 59: /* var_local_char: TK_IDENTIFICADOR $@7 TK_OC_LE expressao_7  */
#line 440 "parser.y"
                                        { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-3].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                                        // Verifica erro de conversão
                                        (yyvsp[-3].valor_lexico)->set_node_type(Type::CHARACTER);
                                        int exit_code = get_char_err((yyvsp[-3].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type());
                                        if (exit_code > 0) exit(exit_code);
                                        Symbol s{
                                            (yyvsp[-3].valor_lexico)->get_line_no(), 
                                            Kind::VARIABLE, 
                                            Type::CHARACTER, 
                                            get_size_from_type(Type::CHARACTER), 
                                            (yyvsp[-1].valor_lexico)
                                        };
                                        symbol_table_stack.insert_top((yyvsp[-3].valor_lexico)->get_token_val(), s);
              					        (yyval.valor_lexico)->set_node_type(Type::CHARACTER);
                                    }
#line 2163 "parser.tab.c"
    break;

  case 60: /* atribuicao: identificador '=' expressao_7  */
#line 457 "parser.y"
                                          { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico)); 
                              // verifica tipos
                              int exit_code = get_char_err((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type());
                              if (exit_code > 0) exit(exit_code);
                              (yyval.valor_lexico)->set_node_type((yyvsp[-2].valor_lexico)->get_node_type());
                            }
#line 2174 "parser.tab.c"
    break;

  case 61: /* identificador: TK_IDENTIFICADOR  */
#line 464 "parser.y"
                                { if (!symbol_table_stack.is_not_declared((yyvsp[0].valor_lexico)->get_token_val())) {
                                      exit(ERR_UNDECLARED);
                                  }
                                  (yyval.valor_lexico) = (yyvsp[0].valor_lexico); // Tem que ser var, se não é erro
                                  auto s = symbol_table_stack.get_first_symbol((yyvsp[0].valor_lexico)->get_token_val());
                                  if (s.kind != Kind::VARIABLE) exit(ERR_VARIABLE);
                                  (yyval.valor_lexico)->set_node_type(s.type);
                                }
#line 2187 "parser.tab.c"
    break;

  case 62: /* identificador: TK_IDENTIFICADOR '[' lista_indices ']'  */
#line 472 "parser.y"
                                                      { // Tem que ser Arranjo, se não é erro
                if (!symbol_table_stack.is_not_declared((yyvsp[-3].valor_lexico)->get_token_val())) {
                    exit(ERR_UNDECLARED);
                }
                auto s = symbol_table_stack.get_first_symbol((yyvsp[-3].valor_lexico)->get_token_val());
                if (s.kind != Kind::ARRAY) exit(ERR_ARRAY);
                (yyval.valor_lexico) = new Node((yyvsp[-3].valor_lexico)->get_line_no(), TokenType::COMPOSED_OPERATOR, TokenVal("[]"));
                (yyval.valor_lexico)->add_child((yyvsp[-3].valor_lexico));
                (yyval.valor_lexico)->add_child((yyvsp[-1].valor_lexico));
                (yyval.valor_lexico)->set_node_type(s.type);
             }
#line 2203 "parser.tab.c"
    break;

  case 63: /* lista_indices: expressao_7  */
#line 484 "parser.y"
                           {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 2209 "parser.tab.c"
    break;

  case 64: /* lista_indices: lista_indices '^' expressao_7  */
#line 485 "parser.y"
                                             {(yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico));}
#line 2215 "parser.tab.c"
    break;

  case 65: /* $@8: %empty  */
#line 488 "parser.y"
                              { // Tem que ser função, se não é erro
                                if (!symbol_table_stack.is_not_declared((yyvsp[0].valor_lexico)->get_token_val())) exit(ERR_UNDECLARED);
                                auto s = symbol_table_stack.get_first_symbol((yyvsp[0].valor_lexico)->get_token_val());
                                if (s.kind != Kind::FUNCTION) exit(ERR_FUNCTION);
                              }
#line 2225 "parser.tab.c"
    break;

  case 66: /* cham_funcao: TK_IDENTIFICADOR $@8 '(' lista_argumentos ')'  */
#line 493 "parser.y"
                                                  {(yyval.valor_lexico) = (yyvsp[-4].valor_lexico); (yyval.valor_lexico)->set_is_func_call(true); (yyval.valor_lexico)->add_child((yyvsp[-1].valor_lexico));}
#line 2231 "parser.tab.c"
    break;

  case 67: /* lista_argumentos: %empty  */
#line 495 "parser.y"
                         {(yyval.valor_lexico) = nullptr;}
#line 2237 "parser.tab.c"
    break;

  case 68: /* lista_argumentos: expressao_7  */
#line 496 "parser.y"
                              {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 2243 "parser.tab.c"
    break;

  case 69: /* lista_argumentos: expressao_7 ',' lista_argumentos  */
#line 497 "parser.y"
                                                   {(yyval.valor_lexico) = (yyvsp[-2].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));}
#line 2249 "parser.tab.c"
    break;

  case 70: /* op_retorno: TK_PR_RETURN expressao_7  */
#line 500 "parser.y"
                                     { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
				       (yyval.valor_lexico)->set_node_type((yyvsp[0].valor_lexico)->get_node_type());}
#line 2256 "parser.tab.c"
    break;

  case 71: /* con_fluxo: TK_PR_IF '(' expressao_7 ')' TK_PR_THEN bloco_comandos  */
#line 504 "parser.y"
                                                                  {(yyval.valor_lexico) = (yyvsp[-5].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-3].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
								   (yyval.valor_lexico)->set_node_type((yyvsp[-3].valor_lexico)->get_node_type());
								   if ((yyvsp[-3].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}}
#line 2264 "parser.tab.c"
    break;

  case 72: /* con_fluxo: TK_PR_IF '(' expressao_7 ')' TK_PR_THEN bloco_comandos TK_PR_ELSE bloco_comandos  */
#line 508 "parser.y"
         {
            (yyval.valor_lexico) = (yyvsp[-7].valor_lexico);
            (yyval.valor_lexico)->add_child((yyvsp[-5].valor_lexico));
            (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico));
            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
            (yyval.valor_lexico)->set_node_type((yyvsp[-5].valor_lexico)->get_node_type());
            if ((yyvsp[-5].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}
         }
#line 2277 "parser.tab.c"
    break;

  case 73: /* con_fluxo: TK_PR_WHILE '(' expressao_7 ')' bloco_comandos  */
#line 516 "parser.y"
                                                          {(yyval.valor_lexico) = (yyvsp[-4].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
         						   (yyval.valor_lexico)->set_node_type((yyvsp[-2].valor_lexico)->get_node_type());
         						   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}}
#line 2285 "parser.tab.c"
    break;

  case 74: /* expressao_7: expressao_6  */
#line 522 "parser.y"
                         { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2291 "parser.tab.c"
    break;

  case 75: /* expressao_7: expressao_7 TK_OC_OR expressao_6  */
#line 523 "parser.y"
                                              { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           					(yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           					if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}}
#line 2299 "parser.tab.c"
    break;

  case 76: /* expressao_6: expressao_5  */
#line 527 "parser.y"
                         { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2305 "parser.tab.c"
    break;

  case 77: /* expressao_6: expressao_6 TK_OC_AND expressao_5  */
#line 528 "parser.y"
                                               { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           					 (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           					 if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}}
#line 2313 "parser.tab.c"
    break;

  case 78: /* expressao_5: expressao_4  */
#line 533 "parser.y"
                         { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2319 "parser.tab.c"
    break;

  case 79: /* expressao_5: expressao_5 TK_OC_EQ expressao_4  */
#line 534 "parser.y"
                                              { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           					(yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           					if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2327 "parser.tab.c"
    break;

  case 80: /* expressao_5: expressao_5 TK_OC_NE expressao_4  */
#line 537 "parser.y"
                                              { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           					(yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           					if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2335 "parser.tab.c"
    break;

  case 81: /* expressao_4: expressao_3  */
#line 541 "parser.y"
                         { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2341 "parser.tab.c"
    break;

  case 82: /* expressao_4: expressao_4 '<' expressao_3  */
#line 542 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2349 "parser.tab.c"
    break;

  case 83: /* expressao_4: expressao_4 '>' expressao_3  */
#line 545 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2357 "parser.tab.c"
    break;

  case 84: /* expressao_4: expressao_4 TK_OC_LE expressao_3  */
#line 548 "parser.y"
                                              { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           					(yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           					if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2365 "parser.tab.c"
    break;

  case 85: /* expressao_4: expressao_4 TK_OC_GE expressao_3  */
#line 551 "parser.y"
                                              { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           					(yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           					if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2373 "parser.tab.c"
    break;

  case 86: /* expressao_3: expressao_2  */
#line 556 "parser.y"
                         { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2379 "parser.tab.c"
    break;

  case 87: /* expressao_3: expressao_3 '+' expressao_2  */
#line 557 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2387 "parser.tab.c"
    break;

  case 88: /* expressao_3: expressao_3 '-' expressao_2  */
#line 560 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2395 "parser.tab.c"
    break;

  case 89: /* expressao_2: expressao_1  */
#line 564 "parser.y"
                         { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2401 "parser.tab.c"
    break;

  case 90: /* expressao_2: expressao_2 '*' expressao_1  */
#line 565 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2409 "parser.tab.c"
    break;

  case 91: /* expressao_2: expressao_2 '/' expressao_1  */
#line 568 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2417 "parser.tab.c"
    break;

  case 92: /* expressao_2: expressao_2 '%' expressao_1  */
#line 571 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2425 "parser.tab.c"
    break;

  case 93: /* expressao_1: operando  */
#line 575 "parser.y"
                      { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2431 "parser.tab.c"
    break;

  case 94: /* expressao_1: '(' expressao_7 ')'  */
#line 576 "parser.y"
                                 { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); }
#line 2437 "parser.tab.c"
    break;

  case 95: /* expressao_1: '-' expressao_1  */
#line 577 "parser.y"
                             { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico)); (yyval.valor_lexico)->set_node_type((yyvsp[0].valor_lexico)->get_node_type());
           		       if ((yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2444 "parser.tab.c"
    break;

  case 96: /* expressao_1: '!' expressao_1  */
#line 579 "parser.y"
                             { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico)); (yyval.valor_lexico)->set_node_type((yyvsp[0].valor_lexico)->get_node_type());
           		       if ((yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}}
#line 2451 "parser.tab.c"
    break;

  case 97: /* operando: identificador  */
#line 582 "parser.y"
                        { (yyval.valor_lexico) = (yyvsp[0].valor_lexico);  (yyval.valor_lexico)->set_node_type((yyvsp[0].valor_lexico)->get_node_type()); }
#line 2457 "parser.tab.c"
    break;

  case 98: /* operando: literal  */
#line 583 "parser.y"
                  { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type((yyvsp[0].valor_lexico)->get_node_type()); }
#line 2463 "parser.tab.c"
    break;

  case 99: /* operando: cham_funcao  */
#line 584 "parser.y"
                      { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type((yyvsp[0].valor_lexico)->get_node_type()); }
#line 2469 "parser.tab.c"
    break;

  case 100: /* literal: TK_LIT_INT  */
#line 587 "parser.y"
                    { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::INTEGER); }
#line 2475 "parser.tab.c"
    break;

  case 101: /* literal: TK_LIT_FLOAT  */
#line 588 "parser.y"
                      { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::FLOATING); }
#line 2481 "parser.tab.c"
    break;

  case 102: /* literal: TK_LIT_CHAR  */
#line 589 "parser.y"
                     { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::CHARACTER); }
#line 2487 "parser.tab.c"
    break;

  case 103: /* literal: TK_LIT_TRUE  */
#line 590 "parser.y"
                     { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::BOOLEAN); }
#line 2493 "parser.tab.c"
    break;

  case 104: /* literal: TK_LIT_FALSE  */
#line 591 "parser.y"
                      { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::BOOLEAN); }
#line 2499 "parser.tab.c"
    break;

  case 105: /* tipo_primitivo: TK_PR_INT  */
#line 593 "parser.y"
                          { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::INTEGER); }
#line 2505 "parser.tab.c"
    break;

  case 106: /* tipo_primitivo: TK_PR_FLOAT  */
#line 594 "parser.y"
                            { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::FLOATING); }
#line 2511 "parser.tab.c"
    break;

  case 107: /* tipo_primitivo: TK_PR_CHAR  */
#line 595 "parser.y"
                           { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::CHARACTER); }
#line 2517 "parser.tab.c"
    break;

  case 108: /* tipo_primitivo: TK_PR_BOOL  */
#line 596 "parser.y"
                           { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::BOOLEAN); }
#line 2523 "parser.tab.c"
    break;


#line 2527 "parser.tab.c"

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

#line 600 "parser.y"

/* Declaração da função de erro */
void yyerror (const char *msg) {
    std::cerr << "line " << get_line_number() << ": " << msg << std::endl;
}

void send_error_message (Node* node, int code) {
    int line_no = node->get_line_no();
    std::string token_val = std::get<std::string>(node->get_token_val());
    std::cout << token_val << std::endl;
    std::string token_type = token_type_to_string(node->get_token_type());

    if (code == ERR_UNDECLARED) {
        std::cout << "[ERRO linha " << line_no
                  << "] Variável " << token_val << " não foi declarada." << std::endl;
    } else if (code == ERR_DECLARED) {
        // NOTE: daria pra pegar o numero da linha da declaração anterior acessando a tabela de simbolos
        std::cout << "[ERRO linha " << line_no
                  << "] Variável " << token_val << " foi declarada na linha X e não pode ser redeclarada." <<std::endl;
    } else if (code == ERR_VARIABLE) {
        std::cout << "[ERRO linha " << line_no
                  << "] Uso indevido da variável " << token_val << "." <<std::endl;
    } else if (code == ERR_ARRAY) {
        std::cout << "[ERRO linha " << line_no
                  << "] Uso indevido do arranjo " << token_val << "." <<std::endl;
    } else if (code == ERR_FUNCTION) {
        std::cout << "[ERRO linha " << line_no
                  << "] Uso indevido da função " << token_val << "." <<std::endl;
    } else if (code == ERR_CHAR_TO_INT) {
        std::cout << "[ERRO linha " << line_no
                  << "] Conversão char >> int não suportada." <<std::endl;
    } else if (code == ERR_CHAR_TO_FLOAT) {
        std::cout << "[ERRO linha " << line_no
                  << "] Conversão char >> float não suportada." <<std::endl;
    } else if (code == ERR_CHAR_TO_BOOL) {
        std::cout << "[ERRO linha " << line_no
                  << "] Conversão char >> bool não suportada." <<std::endl;
    } else if (code == ERR_CHAR_VECTOR) {
        std::cout << "[ERRO linha " << line_no
                  << "] Vetores de char não são suportados." <<std::endl;
    } else if (code == ERR_X_TO_CHAR) {
        std::cout << "[ERRO linha " << line_no
                  << "] Conversão " << token_type << " >> char não suportada." << std::endl;
    }
}
