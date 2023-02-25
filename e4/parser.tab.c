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
#include "table.hh"
extern int get_line_number();
extern void* arvore;
int yylex(void);
void yyerror (const char *msg);
SymbolTableStack symbol_table_stack{};

#line 82 "parser.tab.c"

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
  YYSYMBOL_lista_parametros = 56,          /* lista_parametros  */
  YYSYMBOL_parametro = 57,                 /* parametro  */
  YYSYMBOL_corpo_funcao = 58,              /* corpo_funcao  */
  YYSYMBOL_bloco_comandos = 59,            /* bloco_comandos  */
  YYSYMBOL_60_2 = 60,                      /* $@2  */
  YYSYMBOL_lista_comandos = 61,            /* lista_comandos  */
  YYSYMBOL_comando_simples = 62,           /* comando_simples  */
  YYSYMBOL_var_local = 63,                 /* var_local  */
  YYSYMBOL_lista_var_local_int = 64,       /* lista_var_local_int  */
  YYSYMBOL_var_local_int = 65,             /* var_local_int  */
  YYSYMBOL_66_3 = 66,                      /* $@3  */
  YYSYMBOL_lista_var_local_float = 67,     /* lista_var_local_float  */
  YYSYMBOL_var_local_float = 68,           /* var_local_float  */
  YYSYMBOL_69_4 = 69,                      /* $@4  */
  YYSYMBOL_lista_var_local_bool = 70,      /* lista_var_local_bool  */
  YYSYMBOL_var_local_bool = 71,            /* var_local_bool  */
  YYSYMBOL_72_5 = 72,                      /* $@5  */
  YYSYMBOL_lista_var_local_char = 73,      /* lista_var_local_char  */
  YYSYMBOL_var_local_char = 74,            /* var_local_char  */
  YYSYMBOL_75_6 = 75,                      /* $@6  */
  YYSYMBOL_atribuicao = 76,                /* atribuicao  */
  YYSYMBOL_77_7 = 77,                      /* $@7  */
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
#define YYLAST   142

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
       0,    99,    99,    99,   101,   102,   111,   112,   115,   117,
     118,   120,   121,   123,   124,   127,   132,   133,   134,   136,
     138,   141,   141,   143,   144,   152,   153,   154,   155,   156,
     157,   162,   163,   164,   165,   169,   170,   179,   189,   205,
     205,   224,   225,   234,   244,   260,   260,   280,   281,   290,
     300,   316,   316,   336,   337,   346,   355,   371,   371,   392,
     392,   400,   401,   407,   408,   411,   411,   414,   415,   416,
     419,   423,   426,   435,   441,   442,   446,   447,   452,   453,
     456,   460,   461,   464,   467,   470,   475,   476,   479,   483,
     484,   487,   490,   494,   495,   496,   498,   501,   502,   503,
     506,   507,   508,   509,   510,   512,   513,   514,   515
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
  "lista_parametros", "parametro", "corpo_funcao", "bloco_comandos", "$@2",
  "lista_comandos", "comando_simples", "var_local", "lista_var_local_int",
  "var_local_int", "$@3", "lista_var_local_float", "var_local_float",
  "$@4", "lista_var_local_bool", "var_local_bool", "$@5",
  "lista_var_local_char", "var_local_char", "$@6", "atribuicao", "$@7",
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

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-66)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -72,    46,    89,   -72,   -72,   -72,   -72,   -72,   -72,    89,
     -72,   -72,    27,   -72,   -14,    -4,   -72,    50,    89,   -72,
      49,   -72,   -10,    29,   -72,    60,    48,   -72,    69,   -72,
      89,    62,   -72,   -72,   -72,   -72,   -72,   -72,     3,    82,
      84,    85,    86,    71,    72,    37,    36,   -72,    70,    78,
     -72,   -72,   -72,   -72,   -72,   -72,   102,   -72,    -3,   103,
     -72,     4,   104,   -72,    38,   105,   -72,    41,    37,    37,
     -72,   -72,   -72,   -72,   -72,    37,    37,    37,   -72,   -72,
     101,   106,    83,     5,    40,    51,   -72,   -72,   -72,    37,
      80,   -72,     3,    87,   109,    82,   -72,   111,    84,   -72,
     112,    85,   -72,   113,    86,   -72,    -6,    -5,   -72,   -72,
      -1,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    33,   101,    37,   -72,    37,    37,
     -72,    37,   -72,    37,   -72,    37,   -72,   121,    62,   -72,
     106,    83,     5,     5,    40,    40,    40,    40,    51,    51,
     -72,   -72,   -72,    37,   -72,    90,     2,   101,   101,   101,
     101,   101,    62,   -72,   101,   -72,    37,   123,   -72,    62,
     -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     4,     1,   105,   106,   108,   107,     3,     4,
       6,     7,     0,     5,    11,     0,     9,     0,    16,     8,
       0,    13,     0,     0,    17,     0,    11,    10,     0,    12,
       0,     0,    19,    14,    18,    21,    15,    20,    23,    35,
      41,    47,    53,     0,     0,     0,    61,    30,     0,     0,
      25,    26,    59,    29,    28,    27,    38,    31,    35,    44,
      32,    41,    50,    33,    47,    56,    34,    53,     0,     0,
     100,   101,   104,   103,   102,     0,     0,     0,    97,    99,
      70,    74,    76,    78,    81,    86,    89,    93,    98,     0,
       0,    22,    23,     0,     0,    35,    36,     0,    41,    42,
       0,    47,    48,     0,    53,    54,     0,     0,    96,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    67,    24,     0,     0,
      37,     0,    43,     0,    49,     0,    55,     0,     0,    94,
      75,    77,    79,    80,    84,    85,    82,    83,    88,    87,
      90,    91,    92,     0,    62,     0,    68,    60,    40,    46,
      52,    58,     0,    73,    64,    66,    67,    71,    69,     0,
      72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,   -72,   125,   -72,   -72,   -72,   110,   -72,   -72,
     -72,   107,   -72,   -31,   -72,    43,   -72,   -72,   -47,   -72,
     -72,   -49,   -72,   -72,   -46,   -72,   -72,   -50,   -72,   -72,
     -72,   -72,   -36,   -72,   -35,   -72,   -30,   -72,   -72,   -44,
      28,    30,   -11,   -19,   -15,   -71,   -72,   -72,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     8,     9,    10,    15,    16,    22,    11,
      23,    24,    36,    47,    38,    48,    49,    50,    57,    58,
      94,    60,    61,    97,    63,    64,   100,    66,    67,   103,
      51,    93,    78,   124,    79,    90,   155,    54,    55,   156,
      81,    82,    83,    84,    85,    86,    87,    88,    12
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,    80,    52,    53,   108,   109,    39,    40,    41,    42,
      43,    96,    99,    44,   111,   111,    45,   105,   102,   111,
     115,   116,   111,    56,   106,   107,    17,    28,    18,    46,
      59,    29,    25,   110,    19,    20,    95,   137,   138,   117,
     118,   166,   139,    98,    25,   125,     3,    35,   130,   132,
     150,   151,   152,    14,   136,   134,    52,    53,    70,    71,
      72,    73,    74,    46,    62,    75,    76,    65,    30,   119,
     153,    21,    31,   120,   154,    26,    89,   101,   -65,    77,
     104,   121,   122,   123,   157,   158,    32,   159,    17,   160,
      33,   161,     4,     5,     6,     7,   144,   145,   146,   147,
     113,   114,   142,   143,   148,   149,    35,   163,    56,   164,
      59,    62,    65,    68,    69,    91,    92,   -39,   -45,   -51,
     -57,   111,   126,   128,   129,   112,   131,   133,   135,   162,
      27,   167,   169,   165,    13,   127,   168,    34,   170,   140,
       0,     0,   141
};

static const yytype_int16 yycheck[] =
{
      31,    45,    38,    38,    75,    76,     3,     4,     5,     6,
       7,    58,    61,    10,    20,    20,    13,    67,    64,    20,
      15,    16,    20,    26,    68,    69,    40,    37,    42,    26,
      26,    41,    18,    77,    38,    39,    39,    43,    43,    34,
      35,    39,    43,    39,    30,    89,     0,    44,    95,    98,
     121,   122,   123,    26,   104,   101,    92,    92,    21,    22,
      23,    24,    25,    26,    26,    28,    29,    26,    39,    29,
      37,    21,    43,    33,    41,    26,    40,    39,    42,    42,
      39,    30,    31,    32,   128,   129,    26,   131,    40,   133,
      21,   135,     3,     4,     5,     6,   115,   116,   117,   118,
      17,    18,   113,   114,   119,   120,    44,   138,    26,   153,
      26,    26,    26,    42,    42,    45,    38,    15,    15,    15,
      15,    20,    42,    36,    15,    19,    15,    15,    15,     8,
      20,   162,     9,    43,     9,    92,   166,    30,   169,   111,
      -1,    -1,   112
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    48,     0,     3,     4,     5,     6,    49,    50,
      51,    55,    94,    49,    26,    52,    53,    40,    42,    38,
      39,    21,    54,    56,    57,    94,    26,    53,    37,    41,
      39,    43,    26,    21,    57,    44,    58,    59,    60,     3,
       4,     5,     6,     7,    10,    13,    26,    59,    61,    62,
      63,    76,    78,    80,    83,    84,    26,    64,    65,    26,
      67,    68,    26,    70,    71,    26,    73,    74,    42,    42,
      21,    22,    23,    24,    25,    28,    29,    42,    78,    80,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    40,
      81,    45,    38,    77,    66,    39,    64,    69,    39,    67,
      72,    39,    70,    75,    39,    73,    85,    85,    91,    91,
      85,    20,    19,    17,    18,    15,    16,    34,    35,    29,
      33,    30,    31,    32,    79,    85,    42,    61,    36,    15,
      64,    15,    67,    15,    70,    15,    73,    43,    43,    43,
      86,    87,    88,    88,    89,    89,    89,    89,    90,    90,
      91,    91,    91,    37,    41,    82,    85,    85,    85,    85,
      85,    85,     8,    59,    85,    43,    39,    59,    82,     9,
      59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    48,    47,    49,    49,    50,    50,    51,    52,
      52,    53,    53,    54,    54,    55,    56,    56,    56,    57,
      58,    60,    59,    61,    61,    62,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    64,    64,    64,    65,    66,
      65,    67,    67,    67,    68,    69,    68,    70,    70,    70,
      71,    72,    71,    73,    73,    73,    74,    75,    74,    77,
      76,    78,    78,    79,    79,    81,    80,    82,    82,    82,
      83,    84,    84,    84,    85,    85,    86,    86,    87,    87,
      87,    88,    88,    88,    88,    88,    89,    89,    89,    90,
      90,    90,    90,    91,    91,    91,    91,    92,    92,    92,
      93,    93,    93,    93,    93,    94,    94,    94,    94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     3,     1,
       3,     1,     4,     1,     3,     6,     0,     1,     3,     2,
       1,     0,     4,     0,     3,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     0,     2,     3,     1,     0,
       4,     0,     2,     3,     1,     0,     4,     0,     2,     3,
       1,     0,     4,     0,     2,     3,     1,     0,     4,     0,
       4,     1,     4,     1,     3,     0,     5,     0,     1,     3,
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
#line 99 "parser.y"
          { symbol_table_stack.push_new(); }
#line 1556 "parser.tab.c"
    break;

  case 3: /* programa: $@1 lista_elem  */
#line 99 "parser.y"
                                                        {(yyval.valor_lexico) = (yyvsp[0].valor_lexico); arvore = (yyval.valor_lexico); symbol_table_stack.pop(); }
#line 1562 "parser.tab.c"
    break;

  case 4: /* lista_elem: %empty  */
#line 101 "parser.y"
                   {(yyval.valor_lexico) = nullptr;}
#line 1568 "parser.tab.c"
    break;

  case 5: /* lista_elem: elemento lista_elem  */
#line 102 "parser.y"
                                {
            if ((yyval.valor_lexico)!=nullptr) {
                (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); 
                (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
            } else {
                (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
            }
        }
#line 1581 "parser.tab.c"
    break;

  case 6: /* elemento: var_global  */
#line 111 "parser.y"
                     {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1587 "parser.tab.c"
    break;

  case 7: /* elemento: funcao  */
#line 112 "parser.y"
                 {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1593 "parser.tab.c"
    break;

  case 8: /* var_global: tipo_primitivo lista_id_var_global ';'  */
#line 115 "parser.y"
                                                   {(yyval.valor_lexico) = nullptr;}
#line 1599 "parser.tab.c"
    break;

  case 9: /* lista_id_var_global: id_var_global  */
#line 117 "parser.y"
                                   {(yyval.valor_lexico) = nullptr;}
#line 1605 "parser.tab.c"
    break;

  case 10: /* lista_id_var_global: lista_id_var_global ',' id_var_global  */
#line 118 "parser.y"
                                                           {(yyval.valor_lexico) = nullptr;}
#line 1611 "parser.tab.c"
    break;

  case 11: /* id_var_global: TK_IDENTIFICADOR  */
#line 120 "parser.y"
                                {(yyval.valor_lexico)=nullptr; delete (yyvsp[0].valor_lexico);}
#line 1617 "parser.tab.c"
    break;

  case 12: /* id_var_global: TK_IDENTIFICADOR '[' lista_dimensoes ']'  */
#line 121 "parser.y"
                                                        {(yyval.valor_lexico)=nullptr; delete (yyvsp[-3].valor_lexico);}
#line 1623 "parser.tab.c"
    break;

  case 13: /* lista_dimensoes: TK_LIT_INT  */
#line 123 "parser.y"
                            {(yyval.valor_lexico)=nullptr; delete (yyvsp[0].valor_lexico);}
#line 1629 "parser.tab.c"
    break;

  case 14: /* lista_dimensoes: lista_dimensoes '^' TK_LIT_INT  */
#line 124 "parser.y"
                                                {(yyval.valor_lexico)=nullptr; delete (yyvsp[-1].valor_lexico); delete (yyvsp[0].valor_lexico);}
#line 1635 "parser.tab.c"
    break;

  case 15: /* funcao: tipo_primitivo TK_IDENTIFICADOR '(' lista_parametros ')' corpo_funcao  */
#line 127 "parser.y"
                                                                              {
    (yyval.valor_lexico) = (yyvsp[-4].valor_lexico); 
    (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
    }
#line 1644 "parser.tab.c"
    break;

  case 16: /* lista_parametros: %empty  */
#line 132 "parser.y"
                         {(yyval.valor_lexico) = nullptr;}
#line 1650 "parser.tab.c"
    break;

  case 17: /* lista_parametros: parametro  */
#line 133 "parser.y"
                            {(yyval.valor_lexico) = nullptr;}
#line 1656 "parser.tab.c"
    break;

  case 18: /* lista_parametros: lista_parametros ',' parametro  */
#line 134 "parser.y"
                                                 {(yyval.valor_lexico) = nullptr;}
#line 1662 "parser.tab.c"
    break;

  case 19: /* parametro: tipo_primitivo TK_IDENTIFICADOR  */
#line 136 "parser.y"
                                           {(yyval.valor_lexico)=nullptr; delete (yyvsp[0].valor_lexico);}
#line 1668 "parser.tab.c"
    break;

  case 20: /* corpo_funcao: bloco_comandos  */
#line 138 "parser.y"
                             {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1674 "parser.tab.c"
    break;

  case 21: /* $@2: %empty  */
#line 141 "parser.y"
                    { symbol_table_stack.push_new(); }
#line 1680 "parser.tab.c"
    break;

  case 22: /* bloco_comandos: '{' $@2 lista_comandos '}'  */
#line 141 "parser.y"
                                                                          {(yyval.valor_lexico) = (yyvsp[-1].valor_lexico); symbol_table_stack.pop(); }
#line 1686 "parser.tab.c"
    break;

  case 23: /* lista_comandos: %empty  */
#line 143 "parser.y"
                       {(yyval.valor_lexico) = nullptr;}
#line 1692 "parser.tab.c"
    break;

  case 24: /* lista_comandos: comando_simples ';' lista_comandos  */
#line 144 "parser.y"
                                                   {
                if ((yyvsp[-2].valor_lexico) != nullptr) {
                    (yyval.valor_lexico) = (yyvsp[-2].valor_lexico); 
                    (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                } else {
                    (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                }}
#line 1704 "parser.tab.c"
    break;

  case 25: /* comando_simples: var_local  */
#line 152 "parser.y"
                           {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1710 "parser.tab.c"
    break;

  case 26: /* comando_simples: atribuicao  */
#line 153 "parser.y"
                            {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1716 "parser.tab.c"
    break;

  case 27: /* comando_simples: con_fluxo  */
#line 154 "parser.y"
                           {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1722 "parser.tab.c"
    break;

  case 28: /* comando_simples: op_retorno  */
#line 155 "parser.y"
                            {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1728 "parser.tab.c"
    break;

  case 29: /* comando_simples: cham_funcao  */
#line 156 "parser.y"
                             {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1734 "parser.tab.c"
    break;

  case 30: /* comando_simples: bloco_comandos  */
#line 157 "parser.y"
                                {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1740 "parser.tab.c"
    break;

  case 31: /* var_local: TK_PR_INT lista_var_local_int  */
#line 162 "parser.y"
                                         {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1746 "parser.tab.c"
    break;

  case 32: /* var_local: TK_PR_FLOAT lista_var_local_float  */
#line 163 "parser.y"
                                             {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1752 "parser.tab.c"
    break;

  case 33: /* var_local: TK_PR_BOOL lista_var_local_bool  */
#line 164 "parser.y"
                                           {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1758 "parser.tab.c"
    break;

  case 34: /* var_local: TK_PR_CHAR lista_var_local_char  */
#line 165 "parser.y"
                                           {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 1764 "parser.tab.c"
    break;

  case 35: /* lista_var_local_int: %empty  */
#line 169 "parser.y"
                            {(yyval.valor_lexico) = nullptr;}
#line 1770 "parser.tab.c"
    break;

  case 36: /* lista_var_local_int: var_local_int lista_var_local_int  */
#line 171 "parser.y"
                   {
                        if ((yyvsp[-1].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 1783 "parser.tab.c"
    break;

  case 37: /* lista_var_local_int: var_local_int ',' lista_var_local_int  */
#line 180 "parser.y"
                   {
                        if ((yyvsp[-2].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-2].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 1796 "parser.tab.c"
    break;

  case 38: /* var_local_int: TK_IDENTIFICADOR  */
#line 189 "parser.y"
                                { (yyval.valor_lexico) = nullptr;
                                    if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
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
#line 1817 "parser.tab.c"
    break;

  case 39: /* $@3: %empty  */
#line 205 "parser.y"
                                { if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
                                        delete (yyvsp[0].valor_lexico);
                                        exit(ERR_DECLARED);
                                  }}
#line 1826 "parser.tab.c"
    break;

  case 40: /* var_local_int: TK_IDENTIFICADOR $@3 TK_OC_LE expressao_7  */
#line 208 "parser.y"
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
#line 1845 "parser.tab.c"
    break;

  case 41: /* lista_var_local_float: %empty  */
#line 224 "parser.y"
                              {(yyval.valor_lexico) = nullptr;}
#line 1851 "parser.tab.c"
    break;

  case 42: /* lista_var_local_float: var_local_float lista_var_local_float  */
#line 226 "parser.y"
                     {
                        if ((yyvsp[-1].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 1864 "parser.tab.c"
    break;

  case 43: /* lista_var_local_float: var_local_float ',' lista_var_local_float  */
#line 235 "parser.y"
                     {
                        if ((yyvsp[-2].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-2].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 1877 "parser.tab.c"
    break;

  case 44: /* var_local_float: TK_IDENTIFICADOR  */
#line 244 "parser.y"
                                  { (yyval.valor_lexico) = nullptr;
                                    if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
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
#line 1898 "parser.tab.c"
    break;

  case 45: /* $@4: %empty  */
#line 260 "parser.y"
                                  { if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
                                        delete (yyvsp[0].valor_lexico);
                                        exit(ERR_DECLARED);
                                    }}
#line 1907 "parser.tab.c"
    break;

  case 46: /* var_local_float: TK_IDENTIFICADOR $@4 TK_OC_LE expressao_7  */
#line 263 "parser.y"
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
#line 1927 "parser.tab.c"
    break;

  case 47: /* lista_var_local_bool: %empty  */
#line 280 "parser.y"
                             {(yyval.valor_lexico) = nullptr;}
#line 1933 "parser.tab.c"
    break;

  case 48: /* lista_var_local_bool: var_local_bool lista_var_local_bool  */
#line 282 "parser.y"
                    {
                        if ((yyvsp[-1].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 1946 "parser.tab.c"
    break;

  case 49: /* lista_var_local_bool: var_local_bool ',' lista_var_local_bool  */
#line 291 "parser.y"
                    {
                        if ((yyvsp[-2].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-2].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 1959 "parser.tab.c"
    break;

  case 50: /* var_local_bool: TK_IDENTIFICADOR  */
#line 300 "parser.y"
                                 { (yyval.valor_lexico) = nullptr; 
                                   if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
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
#line 1980 "parser.tab.c"
    break;

  case 51: /* $@5: %empty  */
#line 316 "parser.y"
                                 { if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
                                    delete (yyvsp[0].valor_lexico);
                                    exit(ERR_DECLARED);
                                }}
#line 1989 "parser.tab.c"
    break;

  case 52: /* var_local_bool: TK_IDENTIFICADOR $@5 TK_OC_LE expressao_7  */
#line 319 "parser.y"
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
#line 2009 "parser.tab.c"
    break;

  case 53: /* lista_var_local_char: %empty  */
#line 336 "parser.y"
                             {(yyval.valor_lexico) = nullptr;}
#line 2015 "parser.tab.c"
    break;

  case 54: /* lista_var_local_char: var_local_char lista_var_local_char  */
#line 338 "parser.y"
                    {
                        if ((yyvsp[-1].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 2028 "parser.tab.c"
    break;

  case 55: /* lista_var_local_char: var_local_char ',' lista_var_local_char  */
#line 347 "parser.y"
                    {
                        if ((yyvsp[-2].valor_lexico) != nullptr) {
                            (yyval.valor_lexico) = (yyvsp[-2].valor_lexico); 
                            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
                        } else {
                            (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
                        }
                    }
#line 2041 "parser.tab.c"
    break;

  case 56: /* var_local_char: TK_IDENTIFICADOR  */
#line 355 "parser.y"
                                 {  if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
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
#line 2062 "parser.tab.c"
    break;

  case 57: /* $@6: %empty  */
#line 371 "parser.y"
                                 {
                if (symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) {
                    delete (yyvsp[0].valor_lexico);
                    exit(ERR_DECLARED);
                }}
#line 2072 "parser.tab.c"
    break;

  case 58: /* var_local_char: TK_IDENTIFICADOR $@6 TK_OC_LE expressao_7  */
#line 375 "parser.y"
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
#line 2092 "parser.tab.c"
    break;

  case 59: /* $@7: %empty  */
#line 392 "parser.y"
                          { if (!symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) exit(ERR_UNDECLARED); }
#line 2098 "parser.tab.c"
    break;

  case 60: /* atribuicao: identificador $@7 '=' expressao_7  */
#line 393 "parser.y"
                            { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-3].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico)); 
                              // verifica tipos
                              int exit_code = get_char_err((yyvsp[-3].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type());
                              if (exit_code > 0) exit(exit_code);
                              (yyval.valor_lexico)->set_node_type((yyvsp[-3].valor_lexico)->get_node_type());
                            }
#line 2109 "parser.tab.c"
    break;

  case 61: /* identificador: TK_IDENTIFICADOR  */
#line 400 "parser.y"
                                {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 2115 "parser.tab.c"
    break;

  case 62: /* identificador: TK_IDENTIFICADOR '[' lista_indices ']'  */
#line 401 "parser.y"
                                                      {
                (yyval.valor_lexico) = new Node((yyvsp[-3].valor_lexico)->get_line_no(), TokenType::COMPOSED_OPERATOR, TokenVal("[]"));
                (yyval.valor_lexico)->add_child((yyvsp[-3].valor_lexico));
                (yyval.valor_lexico)->add_child((yyvsp[-1].valor_lexico));
             }
#line 2125 "parser.tab.c"
    break;

  case 63: /* lista_indices: expressao_7  */
#line 407 "parser.y"
                           {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 2131 "parser.tab.c"
    break;

  case 64: /* lista_indices: lista_indices '^' expressao_7  */
#line 408 "parser.y"
                                             {(yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico));}
#line 2137 "parser.tab.c"
    break;

  case 65: /* $@8: %empty  */
#line 411 "parser.y"
                              {if (!symbol_table_stack.is_declared((yyvsp[0].valor_lexico)->get_token_val())) exit(ERR_UNDECLARED);}
#line 2143 "parser.tab.c"
    break;

  case 66: /* cham_funcao: TK_IDENTIFICADOR $@8 '(' lista_argumentos ')'  */
#line 412 "parser.y"
                                                  {(yyval.valor_lexico) = (yyvsp[-4].valor_lexico); (yyval.valor_lexico)->set_is_func_call(true); (yyval.valor_lexico)->add_child((yyvsp[-1].valor_lexico));}
#line 2149 "parser.tab.c"
    break;

  case 67: /* lista_argumentos: %empty  */
#line 414 "parser.y"
                         {(yyval.valor_lexico) = nullptr;}
#line 2155 "parser.tab.c"
    break;

  case 68: /* lista_argumentos: expressao_7  */
#line 415 "parser.y"
                              {(yyval.valor_lexico) = (yyvsp[0].valor_lexico);}
#line 2161 "parser.tab.c"
    break;

  case 69: /* lista_argumentos: expressao_7 ',' lista_argumentos  */
#line 416 "parser.y"
                                                   {(yyval.valor_lexico) = (yyvsp[-2].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));}
#line 2167 "parser.tab.c"
    break;

  case 70: /* op_retorno: TK_PR_RETURN expressao_7  */
#line 419 "parser.y"
                                     { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
				       (yyval.valor_lexico)->set_node_type((yyvsp[0].valor_lexico)->get_node_type());}
#line 2174 "parser.tab.c"
    break;

  case 71: /* con_fluxo: TK_PR_IF '(' expressao_7 ')' TK_PR_THEN bloco_comandos  */
#line 423 "parser.y"
                                                                  {(yyval.valor_lexico) = (yyvsp[-5].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-3].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
								   (yyval.valor_lexico)->set_node_type((yyvsp[-3].valor_lexico)->get_node_type());
								   if ((yyvsp[-3].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}}
#line 2182 "parser.tab.c"
    break;

  case 72: /* con_fluxo: TK_PR_IF '(' expressao_7 ')' TK_PR_THEN bloco_comandos TK_PR_ELSE bloco_comandos  */
#line 427 "parser.y"
         {
            (yyval.valor_lexico) = (yyvsp[-7].valor_lexico);
            (yyval.valor_lexico)->add_child((yyvsp[-5].valor_lexico));
            (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico));
            (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
            (yyval.valor_lexico)->set_node_type((yyvsp[-5].valor_lexico)->get_node_type());
            if ((yyvsp[-5].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}
         }
#line 2195 "parser.tab.c"
    break;

  case 73: /* con_fluxo: TK_PR_WHILE '(' expressao_7 ')' bloco_comandos  */
#line 435 "parser.y"
                                                          {(yyval.valor_lexico) = (yyvsp[-4].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
         						   (yyval.valor_lexico)->set_node_type((yyvsp[-2].valor_lexico)->get_node_type());
         						   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}}
#line 2203 "parser.tab.c"
    break;

  case 74: /* expressao_7: expressao_6  */
#line 441 "parser.y"
                         { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2209 "parser.tab.c"
    break;

  case 75: /* expressao_7: expressao_7 TK_OC_OR expressao_6  */
#line 442 "parser.y"
                                              { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           					(yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           					if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}}
#line 2217 "parser.tab.c"
    break;

  case 76: /* expressao_6: expressao_5  */
#line 446 "parser.y"
                         { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2223 "parser.tab.c"
    break;

  case 77: /* expressao_6: expressao_6 TK_OC_AND expressao_5  */
#line 447 "parser.y"
                                               { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           					 (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           					 if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}}
#line 2231 "parser.tab.c"
    break;

  case 78: /* expressao_5: expressao_4  */
#line 452 "parser.y"
                         { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2237 "parser.tab.c"
    break;

  case 79: /* expressao_5: expressao_5 TK_OC_EQ expressao_4  */
#line 453 "parser.y"
                                              { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           					(yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           					if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2245 "parser.tab.c"
    break;

  case 80: /* expressao_5: expressao_5 TK_OC_NE expressao_4  */
#line 456 "parser.y"
                                              { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           					(yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           					if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2253 "parser.tab.c"
    break;

  case 81: /* expressao_4: expressao_3  */
#line 460 "parser.y"
                         { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2259 "parser.tab.c"
    break;

  case 82: /* expressao_4: expressao_4 '<' expressao_3  */
#line 461 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2267 "parser.tab.c"
    break;

  case 83: /* expressao_4: expressao_4 '>' expressao_3  */
#line 464 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2275 "parser.tab.c"
    break;

  case 84: /* expressao_4: expressao_4 TK_OC_LE expressao_3  */
#line 467 "parser.y"
                                              { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           					(yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           					if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2283 "parser.tab.c"
    break;

  case 85: /* expressao_4: expressao_4 TK_OC_GE expressao_3  */
#line 470 "parser.y"
                                              { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           					(yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           					if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2291 "parser.tab.c"
    break;

  case 86: /* expressao_3: expressao_2  */
#line 475 "parser.y"
                         { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2297 "parser.tab.c"
    break;

  case 87: /* expressao_3: expressao_3 '+' expressao_2  */
#line 476 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2305 "parser.tab.c"
    break;

  case 88: /* expressao_3: expressao_3 '-' expressao_2  */
#line 479 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2313 "parser.tab.c"
    break;

  case 89: /* expressao_2: expressao_1  */
#line 483 "parser.y"
                         { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2319 "parser.tab.c"
    break;

  case 90: /* expressao_2: expressao_2 '*' expressao_1  */
#line 484 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2327 "parser.tab.c"
    break;

  case 91: /* expressao_2: expressao_2 '/' expressao_1  */
#line 487 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2335 "parser.tab.c"
    break;

  case 92: /* expressao_2: expressao_2 '%' expressao_1  */
#line 490 "parser.y"
                                         { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[-2].valor_lexico)); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico));
           				   (yyval.valor_lexico)->set_node_type(type_infer((yyvsp[-2].valor_lexico)->get_node_type(), (yyvsp[0].valor_lexico)->get_node_type()));
           				   if ((yyvsp[-2].valor_lexico)->get_node_type() == Type::CHARACTER || (yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2343 "parser.tab.c"
    break;

  case 93: /* expressao_1: operando  */
#line 494 "parser.y"
                      { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); }
#line 2349 "parser.tab.c"
    break;

  case 94: /* expressao_1: '(' expressao_7 ')'  */
#line 495 "parser.y"
                                 { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); }
#line 2355 "parser.tab.c"
    break;

  case 95: /* expressao_1: '-' expressao_1  */
#line 496 "parser.y"
                             { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico)); (yyval.valor_lexico)->set_node_type((yyvsp[0].valor_lexico)->get_node_type());
           		       if ((yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_INT);}}
#line 2362 "parser.tab.c"
    break;

  case 96: /* expressao_1: '!' expressao_1  */
#line 498 "parser.y"
                             { (yyval.valor_lexico) = (yyvsp[-1].valor_lexico); (yyval.valor_lexico)->add_child((yyvsp[0].valor_lexico)); (yyval.valor_lexico)->set_node_type((yyvsp[0].valor_lexico)->get_node_type());
           		       if ((yyvsp[0].valor_lexico)->get_node_type() == Type::CHARACTER) {exit(ERR_CHAR_TO_BOOL);}}
#line 2369 "parser.tab.c"
    break;

  case 97: /* operando: identificador  */
#line 501 "parser.y"
                        { (yyval.valor_lexico) = (yyvsp[0].valor_lexico);  (yyval.valor_lexico)->set_node_type((yyvsp[0].valor_lexico)->get_node_type()); }
#line 2375 "parser.tab.c"
    break;

  case 98: /* operando: literal  */
#line 502 "parser.y"
                  { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type((yyvsp[0].valor_lexico)->get_node_type()); }
#line 2381 "parser.tab.c"
    break;

  case 99: /* operando: cham_funcao  */
#line 503 "parser.y"
                      { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type((yyvsp[0].valor_lexico)->get_node_type()); }
#line 2387 "parser.tab.c"
    break;

  case 100: /* literal: TK_LIT_INT  */
#line 506 "parser.y"
                    { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::INTEGER); }
#line 2393 "parser.tab.c"
    break;

  case 101: /* literal: TK_LIT_FLOAT  */
#line 507 "parser.y"
                      { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::FLOATING); }
#line 2399 "parser.tab.c"
    break;

  case 102: /* literal: TK_LIT_CHAR  */
#line 508 "parser.y"
                     { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::CHARACTER); }
#line 2405 "parser.tab.c"
    break;

  case 103: /* literal: TK_LIT_TRUE  */
#line 509 "parser.y"
                     { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::BOOLEAN); }
#line 2411 "parser.tab.c"
    break;

  case 104: /* literal: TK_LIT_FALSE  */
#line 510 "parser.y"
                      { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::BOOLEAN); }
#line 2417 "parser.tab.c"
    break;

  case 105: /* tipo_primitivo: TK_PR_INT  */
#line 512 "parser.y"
                          { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::INTEGER); }
#line 2423 "parser.tab.c"
    break;

  case 106: /* tipo_primitivo: TK_PR_FLOAT  */
#line 513 "parser.y"
                            { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::FLOATING); }
#line 2429 "parser.tab.c"
    break;

  case 107: /* tipo_primitivo: TK_PR_CHAR  */
#line 514 "parser.y"
                           { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::CHARACTER); }
#line 2435 "parser.tab.c"
    break;

  case 108: /* tipo_primitivo: TK_PR_BOOL  */
#line 515 "parser.y"
                           { (yyval.valor_lexico) = (yyvsp[0].valor_lexico); (yyval.valor_lexico)->set_node_type(Type::BOOLEAN); }
#line 2441 "parser.tab.c"
    break;


#line 2445 "parser.tab.c"

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

#line 519 "parser.y"

/* Declaração da função de erro */
void yyerror (const char *msg) {
    std::cerr << "line " << get_line_number() << ": " << msg << std::endl;
}

