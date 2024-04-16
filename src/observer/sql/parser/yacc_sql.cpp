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
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "common/time/date.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg, bool flag = false)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  error_sql_node->error.flag = flag;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}

AggrFuncType get_aggr_func_type(char *func_name)
{
  int len = strlen(func_name);
  for (int i = 0; i < len; i++) {
    func_name[i] = tolower(func_name[i]);
  }
  if (0 == strcmp(func_name, "max")) {
    return AggrFuncType::AGG_MAX;
  } else if (0 == strcmp(func_name, "min")) {
    return AggrFuncType::AGG_MIN;
  } else if (0 == strcmp(func_name, "sum")) {
    return AggrFuncType::AGG_SUM;
  } else if (0 == strcmp(func_name, "avg")) {
    return AggrFuncType::AGG_AVG;
  } else if (0 == strcmp(func_name, "count")) {
    return AggrFuncType::AGG_COUNT;
  } 
  return AggrFuncType::AGGR_FUNC_TYPE_NUM;
}


#line 137 "yacc_sql.cpp"

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

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_TABLES = 7,                     /* TABLES  */
  YYSYMBOL_INDEX = 8,                      /* INDEX  */
  YYSYMBOL_CALC = 9,                       /* CALC  */
  YYSYMBOL_SELECT = 10,                    /* SELECT  */
  YYSYMBOL_DESC = 11,                      /* DESC  */
  YYSYMBOL_SHOW = 12,                      /* SHOW  */
  YYSYMBOL_SYNC = 13,                      /* SYNC  */
  YYSYMBOL_INSERT = 14,                    /* INSERT  */
  YYSYMBOL_DELETE = 15,                    /* DELETE  */
  YYSYMBOL_UPDATE = 16,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 17,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 18,                    /* RBRACE  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 20,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 21,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 22,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 23,                     /* INT_T  */
  YYSYMBOL_STRING_T = 24,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 25,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 26,                    /* DATE_T  */
  YYSYMBOL_TEXT_T = 27,                    /* TEXT_T  */
  YYSYMBOL_HELP = 28,                      /* HELP  */
  YYSYMBOL_EXIT = 29,                      /* EXIT  */
  YYSYMBOL_DOT = 30,                       /* DOT  */
  YYSYMBOL_INTO = 31,                      /* INTO  */
  YYSYMBOL_VALUES = 32,                    /* VALUES  */
  YYSYMBOL_FROM = 33,                      /* FROM  */
  YYSYMBOL_WHERE = 34,                     /* WHERE  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_SET = 37,                       /* SET  */
  YYSYMBOL_ON = 38,                        /* ON  */
  YYSYMBOL_LOAD = 39,                      /* LOAD  */
  YYSYMBOL_DATA = 40,                      /* DATA  */
  YYSYMBOL_INFILE = 41,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 42,                   /* EXPLAIN  */
  YYSYMBOL_IS = 43,                        /* IS  */
  YYSYMBOL_NULL_T = 44,                    /* NULL_T  */
  YYSYMBOL_INNER = 45,                     /* INNER  */
  YYSYMBOL_JOIN = 46,                      /* JOIN  */
  YYSYMBOL_AS = 47,                        /* AS  */
  YYSYMBOL_IN = 48,                        /* IN  */
  YYSYMBOL_EXISTS = 49,                    /* EXISTS  */
  YYSYMBOL_EQ = 50,                        /* EQ  */
  YYSYMBOL_LT = 51,                        /* LT  */
  YYSYMBOL_GT = 52,                        /* GT  */
  YYSYMBOL_LE = 53,                        /* LE  */
  YYSYMBOL_GE = 54,                        /* GE  */
  YYSYMBOL_NE = 55,                        /* NE  */
  YYSYMBOL_NOT = 56,                       /* NOT  */
  YYSYMBOL_LIKE = 57,                      /* LIKE  */
  YYSYMBOL_UNIQUE = 58,                    /* UNIQUE  */
  YYSYMBOL_AGGR_MAX = 59,                  /* AGGR_MAX  */
  YYSYMBOL_AGGR_MIN = 60,                  /* AGGR_MIN  */
  YYSYMBOL_AGGR_SUM = 61,                  /* AGGR_SUM  */
  YYSYMBOL_AGGR_AVG = 62,                  /* AGGR_AVG  */
  YYSYMBOL_AGGR_COUNT = 63,                /* AGGR_COUNT  */
  YYSYMBOL_LENGTH = 64,                    /* LENGTH  */
  YYSYMBOL_ROUND = 65,                     /* ROUND  */
  YYSYMBOL_DATE_FORMAT = 66,               /* DATE_FORMAT  */
  YYSYMBOL_ORDER = 67,                     /* ORDER  */
  YYSYMBOL_GROUP = 68,                     /* GROUP  */
  YYSYMBOL_BY = 69,                        /* BY  */
  YYSYMBOL_ASC = 70,                       /* ASC  */
  YYSYMBOL_HAVING = 71,                    /* HAVING  */
  YYSYMBOL_NUMBER = 72,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 73,                     /* FLOAT  */
  YYSYMBOL_ID = 74,                        /* ID  */
  YYSYMBOL_SSS = 75,                       /* SSS  */
  YYSYMBOL_DATE_STR = 76,                  /* DATE_STR  */
  YYSYMBOL_77_ = 77,                       /* '+'  */
  YYSYMBOL_78_ = 78,                       /* '-'  */
  YYSYMBOL_79_ = 79,                       /* '*'  */
  YYSYMBOL_80_ = 80,                       /* '/'  */
  YYSYMBOL_UMINUS = 81,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 82,                  /* $accept  */
  YYSYMBOL_commands = 83,                  /* commands  */
  YYSYMBOL_command_wrapper = 84,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 85,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 86,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 87,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 88,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 89,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 90,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 91,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 92,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 93,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 94,         /* create_index_stmt  */
  YYSYMBOL_unique_option = 95,             /* unique_option  */
  YYSYMBOL_idx_col_list = 96,              /* idx_col_list  */
  YYSYMBOL_drop_index_stmt = 97,           /* drop_index_stmt  */
  YYSYMBOL_show_index_stmt = 98,           /* show_index_stmt  */
  YYSYMBOL_create_table_stmt = 99,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 100,            /* attr_def_list  */
  YYSYMBOL_attr_def = 101,                 /* attr_def  */
  YYSYMBOL_null_option = 102,              /* null_option  */
  YYSYMBOL_as_option = 103,                /* as_option  */
  YYSYMBOL_number = 104,                   /* number  */
  YYSYMBOL_type = 105,                     /* type  */
  YYSYMBOL_insert_stmt = 106,              /* insert_stmt  */
  YYSYMBOL_insert_col_list = 107,          /* insert_col_list  */
  YYSYMBOL_insert_value_list = 108,        /* insert_value_list  */
  YYSYMBOL_insert_value = 109,             /* insert_value  */
  YYSYMBOL_value_list = 110,               /* value_list  */
  YYSYMBOL_value = 111,                    /* value  */
  YYSYMBOL_delete_stmt = 112,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 113,              /* update_stmt  */
  YYSYMBOL_update_kv_list = 114,           /* update_kv_list  */
  YYSYMBOL_update_kv = 115,                /* update_kv  */
  YYSYMBOL_from_list = 116,                /* from_list  */
  YYSYMBOL_alias = 117,                    /* alias  */
  YYSYMBOL_from_node = 118,                /* from_node  */
  YYSYMBOL_join_list = 119,                /* join_list  */
  YYSYMBOL_sub_query_expr = 120,           /* sub_query_expr  */
  YYSYMBOL_select_stmt = 121,              /* select_stmt  */
  YYSYMBOL_calc_stmt = 122,                /* calc_stmt  */
  YYSYMBOL_expression_list = 123,          /* expression_list  */
  YYSYMBOL_expression = 124,               /* expression  */
  YYSYMBOL_aggr_func_expr = 125,           /* aggr_func_expr  */
  YYSYMBOL_sys_func_type = 126,            /* sys_func_type  */
  YYSYMBOL_func_expr = 127,                /* func_expr  */
  YYSYMBOL_rel_attr = 128,                 /* rel_attr  */
  YYSYMBOL_where = 129,                    /* where  */
  YYSYMBOL_is_null_comp = 130,             /* is_null_comp  */
  YYSYMBOL_condition = 131,                /* condition  */
  YYSYMBOL_sort_unit = 132,                /* sort_unit  */
  YYSYMBOL_sort_list = 133,                /* sort_list  */
  YYSYMBOL_opt_order_by = 134,             /* opt_order_by  */
  YYSYMBOL_opt_group_by = 135,             /* opt_group_by  */
  YYSYMBOL_opt_having = 136,               /* opt_having  */
  YYSYMBOL_comp_op = 137,                  /* comp_op  */
  YYSYMBOL_exists_op = 138,                /* exists_op  */
  YYSYMBOL_load_data_stmt = 139,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 140,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 141,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 142             /* opt_semicolon  */
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
typedef yytype_int16 yy_state_t;

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   265

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  258

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   332


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    79,    77,     2,    78,     2,    80,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    81
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   253,   253,   261,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   285,   291,   296,   302,   308,   314,
     320,   327,   333,   341,   363,   366,   372,   375,   388,   399,
     408,   424,   440,   451,   454,   467,   476,   488,   491,   495,
     502,   505,   512,   515,   516,   517,   518,   519,   522,   543,
     546,   560,   563,   576,   596,   599,   615,   619,   623,   639,
     644,   651,   663,   686,   689,   702,   712,   715,   727,   730,
     733,   738,   754,   757,   775,   783,   792,   829,   839,   848,
     863,   866,   869,   872,   875,   884,   887,   892,   897,   900,
     903,   909,   929,   932,   935,   941,   951,   956,   963,   968,
     974,   983,   986,   992,   996,  1003,  1007,  1014,  1021,  1025,
    1032,  1039,  1046,  1054,  1061,  1069,  1072,  1079,  1082,  1089,
    1092,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,
    1108,  1112,  1113,  1117,  1130,  1138,  1148,  1149
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
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "TABLES", "INDEX", "CALC", "SELECT", "DESC", "SHOW",
  "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA",
  "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "TEXT_T", "HELP", "EXIT", "DOT", "INTO", "VALUES",
  "FROM", "WHERE", "AND", "OR", "SET", "ON", "LOAD", "DATA", "INFILE",
  "EXPLAIN", "IS", "NULL_T", "INNER", "JOIN", "AS", "IN", "EXISTS", "EQ",
  "LT", "GT", "LE", "GE", "NE", "NOT", "LIKE", "UNIQUE", "AGGR_MAX",
  "AGGR_MIN", "AGGR_SUM", "AGGR_AVG", "AGGR_COUNT", "LENGTH", "ROUND",
  "DATE_FORMAT", "ORDER", "GROUP", "BY", "ASC", "HAVING", "NUMBER",
  "FLOAT", "ID", "SSS", "DATE_STR", "'+'", "'-'", "'*'", "'/'", "UMINUS",
  "$accept", "commands", "command_wrapper", "exit_stmt", "help_stmt",
  "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "desc_table_stmt",
  "create_index_stmt", "unique_option", "idx_col_list", "drop_index_stmt",
  "show_index_stmt", "create_table_stmt", "attr_def_list", "attr_def",
  "null_option", "as_option", "number", "type", "insert_stmt",
  "insert_col_list", "insert_value_list", "insert_value", "value_list",
  "value", "delete_stmt", "update_stmt", "update_kv_list", "update_kv",
  "from_list", "alias", "from_node", "join_list", "sub_query_expr",
  "select_stmt", "calc_stmt", "expression_list", "expression",
  "aggr_func_expr", "sys_func_type", "func_expr", "rel_attr", "where",
  "is_null_comp", "condition", "sort_unit", "sort_list", "opt_order_by",
  "opt_group_by", "opt_having", "comp_op", "exists_op", "load_data_stmt",
  "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-192)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-51)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     183,     0,    16,    88,    88,   -43,    47,  -192,    11,    15,
     -13,  -192,  -192,  -192,  -192,  -192,   -11,    51,   183,    94,
     100,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,    44,  -192,   111,    46,    48,     1,  -192,  -192,
    -192,  -192,  -192,  -192,    -3,  -192,  -192,    88,    93,  -192,
    -192,  -192,   -27,  -192,   107,  -192,  -192,    92,  -192,  -192,
     101,    52,    53,    96,    85,    98,  -192,  -192,  -192,  -192,
      -7,    67,  -192,   102,   124,   125,    88,    18,  -192,    70,
      81,  -192,    88,    88,    88,    88,   137,    88,    84,    91,
     140,   134,    95,   -16,    97,   104,  -192,   149,   133,   105,
    -192,  -192,    -9,  -192,  -192,  -192,  -192,    19,    19,  -192,
    -192,    88,   156,   -39,   157,  -192,   106,   143,    72,  -192,
     131,   163,  -192,   152,    83,   165,  -192,   112,  -192,  -192,
    -192,  -192,   144,    84,   134,   166,   184,  -192,   153,   176,
      66,    88,    88,    95,   134,   200,  -192,  -192,  -192,  -192,
    -192,   -10,   104,   189,   191,   164,  -192,   157,   141,   139,
     196,    88,   197,  -192,   -23,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,   -31,  -192,  -192,    88,    72,    72,    34,    34,
     163,  -192,   160,   145,  -192,   171,  -192,   165,     2,   161,
     162,  -192,   154,   147,   166,  -192,     4,   184,  -192,  -192,
     193,  -192,  -192,    34,  -192,   203,  -192,  -192,  -192,   221,
    -192,  -192,   149,   166,   -39,    88,    72,   173,  -192,    88,
     223,   197,  -192,   -15,  -192,   224,   205,  -192,    66,   175,
    -192,     4,  -192,  -192,  -192,  -192,    72,    88,  -192,   -20,
       8,   226,  -192,  -192,  -192,  -192,    88,  -192
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    34,     0,     0,     0,     0,     0,    26,     0,     0,
       0,    27,    28,    29,    25,    24,     0,     0,     0,     0,
     146,    23,    22,    15,    16,    17,    18,     9,    10,    11,
      12,    13,    14,     8,     5,     7,     6,     4,     3,    19,
      20,    21,     0,    35,     0,     0,     0,     0,    70,   102,
     103,   104,    66,    67,   106,    69,    68,     0,   110,    96,
     100,    87,    78,    98,     0,    99,    97,    85,    32,    31,
       0,     0,     0,     0,     0,     0,   144,     1,   147,     2,
      50,     0,    30,     0,     0,     0,     0,     0,    95,     0,
       0,    79,     0,     0,     0,     0,    88,     0,     0,     0,
      59,   111,     0,     0,     0,     0,    51,     0,     0,     0,
      84,    94,     0,   107,   109,   108,    80,    90,    91,    92,
      93,     0,     0,    78,    76,    39,     0,     0,     0,    71,
       0,    73,   145,     0,     0,    43,    42,     0,    38,   101,
      89,   105,    82,     0,   111,    36,     0,   141,     0,     0,
     112,     0,     0,     0,   111,     0,    53,    54,    55,    56,
      57,    47,     0,     0,     0,     0,    81,    76,   127,     0,
       0,     0,    61,   142,     0,   139,   131,   132,   133,   134,
     135,   136,     0,   137,   116,     0,     0,     0,   117,    75,
      73,    72,     0,     0,    48,     0,    46,    43,    40,     0,
       0,    77,     0,   129,    36,    60,    64,     0,    58,   113,
       0,   140,   138,   115,   118,   119,    74,   143,    52,     0,
      49,    44,     0,    36,    78,     0,     0,   125,    37,     0,
       0,    61,   114,    47,    41,     0,     0,   128,   130,     0,
      86,    64,    63,    62,    45,    33,     0,     0,    65,    82,
     120,   123,   126,    83,   121,   122,     0,   124
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,  -192,   228,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -191,  -192,  -192,  -192,    50,    86,
      17,    54,  -192,  -192,  -192,  -192,    20,    42,    21,   155,
    -192,  -192,    69,   108,    90,  -120,   117,    14,  -192,   -45,
    -192,    -4,   -56,  -192,  -192,  -192,  -192,   -54,  -192,  -182,
    -192,     9,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
    -192
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    44,   170,    31,    32,    33,   163,   135,
     196,   107,   219,   161,    34,   127,   208,   172,   230,    59,
      35,    36,   154,   131,   144,    96,   124,   166,    60,    37,
      38,    61,    62,    63,    64,    65,    66,   129,   184,   150,
     251,   252,   240,   203,   227,   185,   151,    39,    40,    41,
      79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    88,    84,   142,   214,   215,    42,   193,    90,   139,
     105,     4,   -50,   228,    86,   186,   187,   211,    47,   254,
      90,   209,    45,   229,    46,   165,   212,    87,    48,   194,
     112,    68,   235,   210,   194,    91,   117,   118,   119,   120,
     106,   195,    71,    85,   238,    48,   195,    91,    72,   106,
      92,    93,    94,    95,    69,    70,    52,    53,    43,    55,
      56,    73,   136,    74,   249,    49,    50,    51,    92,    93,
      94,    95,   149,    52,    53,    54,    55,    56,   255,    57,
      58,    92,    93,    94,    95,    92,    93,    94,    95,    47,
     168,    75,   113,   122,    77,   188,   189,   114,    94,    95,
     191,   186,   187,    78,   236,    47,   156,   157,   158,   159,
     160,    92,    93,    94,    95,   206,    48,   140,    80,    81,
      82,   147,    83,    89,    97,    98,   100,   101,   148,   213,
     149,   149,    48,   102,    99,   103,    49,    50,    51,   104,
     109,   108,   110,   111,    52,    53,    54,    55,    56,   115,
      57,    58,    49,    50,    51,   116,   121,   126,   123,     4,
      52,    53,    54,    55,    56,   125,    57,    58,   128,   130,
     149,   137,   133,   241,   141,   146,   143,   234,   134,   138,
     145,   152,   153,   155,   162,   169,   164,     1,     2,   165,
     149,   250,     3,     4,     5,     6,     7,     8,     9,    10,
     250,   171,   173,    11,    12,    13,   192,   198,   199,   202,
     200,    14,    15,   204,   205,   220,   207,   218,   226,   174,
      16,   237,    17,   225,   175,    18,   176,   177,   178,   179,
     180,   181,   182,   183,   217,   223,   224,   232,   186,   233,
     239,   242,   245,   246,   247,   256,    76,   221,   197,   231,
     244,   243,   222,    92,    93,    94,    95,   201,   132,   216,
     167,   190,   248,   253,     0,   257
};

static const yytype_int16 yycheck[] =
{
       4,    57,    47,   123,   186,   187,     6,    17,    47,    18,
      17,    10,    10,   204,    17,    35,    36,    48,    17,    11,
      47,    44,     6,    19,     8,    45,    57,    30,    44,    44,
      86,    74,   223,    56,    44,    74,    92,    93,    94,    95,
      47,    56,    31,    47,   226,    44,    56,    74,    33,    47,
      77,    78,    79,    80,     7,     8,    72,    73,    58,    75,
      76,    74,   107,    74,   246,    64,    65,    66,    77,    78,
      79,    80,   128,    72,    73,    74,    75,    76,    70,    78,
      79,    77,    78,    79,    80,    77,    78,    79,    80,    17,
     144,    40,    74,    97,     0,   151,   152,    79,    79,    80,
     154,    35,    36,     3,   224,    17,    23,    24,    25,    26,
      27,    77,    78,    79,    80,   171,    44,   121,    74,     8,
      74,    49,    74,    30,    17,    33,    74,    74,    56,   185,
     186,   187,    44,    37,    33,    50,    64,    65,    66,    41,
      38,    74,    18,    18,    72,    73,    74,    75,    76,    79,
      78,    79,    64,    65,    66,    74,    19,    17,    74,    10,
      72,    73,    74,    75,    76,    74,    78,    79,    34,    74,
     226,    38,    75,   229,    18,    32,    19,   222,    74,    74,
      74,    50,    19,    31,    19,    19,    74,     4,     5,    45,
     246,   247,     9,    10,    11,    12,    13,    14,    15,    16,
     256,    17,    49,    20,    21,    22,     6,    18,    17,    68,
      46,    28,    29,    74,    18,    44,    19,    72,    71,    43,
      37,   225,    39,    69,    48,    42,    50,    51,    52,    53,
      54,    55,    56,    57,    74,    74,    74,    44,    35,    18,
      67,    18,    18,    38,    69,    19,    18,   197,   162,   207,
     233,   231,   198,    77,    78,    79,    80,   167,   103,   190,
     143,   153,   241,   249,    -1,   256
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     9,    10,    11,    12,    13,    14,    15,
      16,    20,    21,    22,    28,    29,    37,    39,    42,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    97,    98,    99,   106,   112,   113,   121,   122,   139,
     140,   141,     6,    58,    95,     6,     8,    17,    44,    64,
      65,    66,    72,    73,    74,    75,    76,    78,    79,   111,
     120,   123,   124,   125,   126,   127,   128,   123,    74,     7,
       8,    31,    33,    74,    74,    40,    84,     0,     3,   142,
      74,     8,    74,    74,   121,   123,    17,    30,   124,    30,
      47,    74,    77,    78,    79,    80,   117,    17,    33,    33,
      74,    74,    37,    50,    41,    17,    47,   103,    74,    38,
      18,    18,   124,    74,    79,    79,    74,   124,   124,   124,
     124,    19,   123,    74,   118,    74,    17,   107,    34,   129,
      74,   115,   111,    75,    74,   101,   121,    38,    74,    18,
     123,    18,   117,    19,   116,    74,    32,    49,    56,   124,
     131,   138,    50,    19,   114,    31,    23,    24,    25,    26,
      27,   105,    19,   100,    74,    45,   119,   118,   129,    19,
      96,    17,   109,    49,    43,    48,    50,    51,    52,    53,
      54,    55,    56,    57,   130,   137,    35,    36,   124,   124,
     115,   129,     6,    17,    44,    56,   102,   101,    18,    17,
      46,   116,    68,   135,    74,    18,   124,    19,   108,    44,
      56,    48,    57,   124,   131,   131,   114,    74,    72,   104,
      44,   100,   103,    74,    74,    69,    71,   136,    96,    19,
     110,   109,    44,    18,   121,    96,   117,   123,   131,    67,
     134,   124,    18,   108,   102,    18,    38,    69,   110,   131,
     124,   132,   133,   119,    11,    70,    19,   133
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    95,    96,    96,    97,    98,
      99,    99,    99,   100,   100,   101,   101,   102,   102,   102,
     103,   103,   104,   105,   105,   105,   105,   105,   106,   107,
     107,   108,   108,   109,   110,   110,   111,   111,   111,   111,
     111,   112,   113,   114,   114,   115,   116,   116,   117,   117,
     117,   118,   119,   119,   120,   121,   121,   122,   123,   123,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     124,   125,   126,   126,   126,   127,   128,   128,   128,   128,
     128,   129,   129,   130,   130,   131,   131,   131,   131,   131,
     132,   132,   132,   133,   133,   134,   134,   135,   135,   136,
     136,   137,   137,   137,   137,   137,   137,   137,   137,   137,
     137,   138,   138,   139,   140,   141,   142,   142
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     2,    10,     0,     1,     0,     3,     5,     4,
       7,     9,     5,     0,     3,     6,     3,     0,     1,     2,
       0,     1,     1,     1,     1,     1,     1,     1,     7,     0,
       4,     0,     3,     4,     0,     3,     1,     1,     1,     1,
       1,     4,     6,     0,     3,     3,     0,     3,     0,     1,
       2,     3,     0,     7,     3,     2,     9,     2,     2,     4,
       3,     3,     3,     3,     3,     2,     1,     1,     1,     1,
       1,     4,     1,     1,     1,     4,     1,     3,     3,     3,
       1,     0,     2,     2,     3,     3,     2,     2,     3,     3,
       1,     2,     2,     1,     3,     0,     3,     0,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     2,     7,     2,     4,     0,     1
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
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
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
  YYLTYPE *yylloc;
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (sql_string);
  YY_USE (sql_result);
  YY_USE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, scanner);
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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 254 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1868 "yacc_sql.cpp"
    break;

  case 24: /* exit_stmt: EXIT  */
#line 285 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1877 "yacc_sql.cpp"
    break;

  case 25: /* help_stmt: HELP  */
#line 291 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1885 "yacc_sql.cpp"
    break;

  case 26: /* sync_stmt: SYNC  */
#line 296 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1893 "yacc_sql.cpp"
    break;

  case 27: /* begin_stmt: TRX_BEGIN  */
#line 302 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1901 "yacc_sql.cpp"
    break;

  case 28: /* commit_stmt: TRX_COMMIT  */
#line 308 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1909 "yacc_sql.cpp"
    break;

  case 29: /* rollback_stmt: TRX_ROLLBACK  */
#line 314 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1917 "yacc_sql.cpp"
    break;

  case 30: /* drop_table_stmt: DROP TABLE ID  */
#line 320 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1927 "yacc_sql.cpp"
    break;

  case 31: /* show_tables_stmt: SHOW TABLES  */
#line 327 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1935 "yacc_sql.cpp"
    break;

  case 32: /* desc_table_stmt: DESC ID  */
#line 333 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1945 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE unique_option INDEX ID ON ID LBRACE ID idx_col_list RBRACE  */
#line 342 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.unique = (yyvsp[-8].boolean);
      create_index.index_name = (yyvsp[-6].string);
      create_index.relation_name = (yyvsp[-4].string);
      
      std::vector<std::string> *idx_cols = (yyvsp[-1].relation_list);
      if (nullptr != idx_cols) {
        create_index.attr_names.swap(*idx_cols);
        delete (yyvsp[-1].relation_list);
      }
      create_index.attr_names.emplace_back((yyvsp[-2].string));
      std::reverse(create_index.attr_names.begin(), create_index.attr_names.end());
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));
      free((yyvsp[-2].string));
    }
#line 1968 "yacc_sql.cpp"
    break;

  case 34: /* unique_option: %empty  */
#line 363 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 1976 "yacc_sql.cpp"
    break;

  case 35: /* unique_option: UNIQUE  */
#line 367 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 1984 "yacc_sql.cpp"
    break;

  case 36: /* idx_col_list: %empty  */
#line 372 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 1992 "yacc_sql.cpp"
    break;

  case 37: /* idx_col_list: COMMA ID idx_col_list  */
#line 376 "yacc_sql.y"
    {
      if ((yyvsp[0].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[0].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }
      (yyval.relation_list)->emplace_back((yyvsp[-1].string));
      free((yyvsp[-1].string));
    }
#line 2006 "yacc_sql.cpp"
    break;

  case 38: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 389 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2018 "yacc_sql.cpp"
    break;

  case 39: /* show_index_stmt: SHOW INDEX FROM ID  */
#line 400 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_INDEX);
      (yyval.sql_node)->show_index.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2028 "yacc_sql.cpp"
    break;

  case 40: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 409 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-4].string);
      free((yyvsp[-4].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-1].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-2].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-2].attr_info);
    }
#line 2048 "yacc_sql.cpp"
    break;

  case 41: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE as_option select_stmt  */
#line 425 "yacc_sql.y"
    {
      (yyval.sql_node) = (yyvsp[0].sql_node);
      (yyval.sql_node)->flag = SCF_CREATE_TABLE;
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-6].string);
      free((yyvsp[-6].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-3].attr_infos);
      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-4].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      delete (yyvsp[-4].attr_info);
    }
#line 2068 "yacc_sql.cpp"
    break;

  case 42: /* create_table_stmt: CREATE TABLE ID as_option select_stmt  */
#line 441 "yacc_sql.y"
    {
      (yyval.sql_node) = (yyvsp[0].sql_node);
      (yyval.sql_node)->flag = SCF_CREATE_TABLE;
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-2].string);
      free((yyvsp[-2].string));
    }
#line 2080 "yacc_sql.cpp"
    break;

  case 43: /* attr_def_list: %empty  */
#line 451 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2088 "yacc_sql.cpp"
    break;

  case 44: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 455 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2102 "yacc_sql.cpp"
    break;

  case 45: /* attr_def: ID type LBRACE number RBRACE null_option  */
#line 468 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->nullable = (yyvsp[0].boolean);
      free((yyvsp[-5].string));
    }
#line 2115 "yacc_sql.cpp"
    break;

  case 46: /* attr_def: ID type null_option  */
#line 477 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
      (yyval.attr_info)->name = (yyvsp[-2].string);
      (yyval.attr_info)->length = 4;
      (yyval.attr_info)->nullable = (yyvsp[0].boolean);
      free((yyvsp[-2].string));
    }
#line 2128 "yacc_sql.cpp"
    break;

  case 47: /* null_option: %empty  */
#line 488 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2136 "yacc_sql.cpp"
    break;

  case 48: /* null_option: NULL_T  */
#line 492 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2144 "yacc_sql.cpp"
    break;

  case 49: /* null_option: NOT NULL_T  */
#line 496 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2152 "yacc_sql.cpp"
    break;

  case 50: /* as_option: %empty  */
#line 502 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2160 "yacc_sql.cpp"
    break;

  case 51: /* as_option: AS  */
#line 506 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2168 "yacc_sql.cpp"
    break;

  case 52: /* number: NUMBER  */
#line 512 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2174 "yacc_sql.cpp"
    break;

  case 53: /* type: INT_T  */
#line 515 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2180 "yacc_sql.cpp"
    break;

  case 54: /* type: STRING_T  */
#line 516 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2186 "yacc_sql.cpp"
    break;

  case 55: /* type: FLOAT_T  */
#line 517 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2192 "yacc_sql.cpp"
    break;

  case 56: /* type: DATE_T  */
#line 518 "yacc_sql.y"
               { (yyval.number)=DATES;}
#line 2198 "yacc_sql.cpp"
    break;

  case 57: /* type: TEXT_T  */
#line 519 "yacc_sql.y"
               { (yyval.number)=TEXTS; }
#line 2204 "yacc_sql.cpp"
    break;

  case 58: /* insert_stmt: INSERT INTO ID insert_col_list VALUES insert_value insert_value_list  */
#line 523 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-4].string);
      if ((yyvsp[0].insert_value_list) != nullptr) {
        (yyval.sql_node)->insertion.values.swap(*(yyvsp[0].insert_value_list));
        delete (yyvsp[0].insert_value_list);
      }
      (yyval.sql_node)->insertion.values.emplace_back(*(yyvsp[-1].value_list));
      std::reverse((yyval.sql_node)->insertion.values.begin(), (yyval.sql_node)->insertion.values.end());
      if (nullptr != (yyvsp[-3].relation_list)) {
        (yyval.sql_node)->insertion.attrs_name.swap(*(yyvsp[-3].relation_list));
        std::reverse((yyval.sql_node)->insertion.attrs_name.begin(), (yyval.sql_node)->insertion.attrs_name.end());
        delete (yyvsp[-3].relation_list);
      }
      delete (yyvsp[-1].value_list);
      free((yyvsp[-4].string));
    }
#line 2226 "yacc_sql.cpp"
    break;

  case 59: /* insert_col_list: %empty  */
#line 543 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 2234 "yacc_sql.cpp"
    break;

  case 60: /* insert_col_list: LBRACE ID idx_col_list RBRACE  */
#line 547 "yacc_sql.y"
    {
      if ((yyvsp[-1].relation_list) != nullptr) {
        (yyval.relation_list) = (yyvsp[-1].relation_list);
      } else {
        (yyval.relation_list) = new std::vector<std::string>;
      }
      (yyval.relation_list)->emplace_back((yyvsp[-2].string));
      free((yyvsp[-2].string));      
    }
#line 2248 "yacc_sql.cpp"
    break;

  case 61: /* insert_value_list: %empty  */
#line 560 "yacc_sql.y"
    {
      (yyval.insert_value_list) = nullptr;
    }
#line 2256 "yacc_sql.cpp"
    break;

  case 62: /* insert_value_list: COMMA insert_value insert_value_list  */
#line 564 "yacc_sql.y"
    {
      if ((yyvsp[0].insert_value_list) != nullptr) {
        (yyval.insert_value_list) = (yyvsp[0].insert_value_list);
      } else {
        (yyval.insert_value_list) = new std::vector<std::vector<Value>>;
      }
      (yyval.insert_value_list)->emplace_back(*(yyvsp[-1].value_list));
      delete (yyvsp[-1].value_list);
    }
#line 2270 "yacc_sql.cpp"
    break;

  case 63: /* insert_value: LBRACE expression value_list RBRACE  */
#line 577 "yacc_sql.y"
    {
      Value tmp;
      if(!exp2value((yyvsp[-2].expression), tmp)) {
        yyerror(&(yyloc), sql_string, sql_result, scanner, "error");
        YYERROR;
      }
      if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[-1].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(tmp);
      std::reverse((yyval.value_list)->begin(), (yyval.value_list)->end());
      delete (yyvsp[-2].expression);
    }
#line 2290 "yacc_sql.cpp"
    break;

  case 64: /* value_list: %empty  */
#line 596 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2298 "yacc_sql.cpp"
    break;

  case 65: /* value_list: COMMA expression value_list  */
#line 599 "yacc_sql.y"
                                   { 
      Value tmp;
      if(!exp2value((yyvsp[-1].expression),tmp)) {
        yyerror(&(yyloc), sql_string, sql_result, scanner, "error");
        YYERROR;
      }
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(tmp);
      delete (yyvsp[-1].expression);
    }
#line 2317 "yacc_sql.cpp"
    break;

  case 66: /* value: NUMBER  */
#line 615 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]); // useless
    }
#line 2326 "yacc_sql.cpp"
    break;

  case 67: /* value: FLOAT  */
#line 619 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]); // useless
    }
#line 2335 "yacc_sql.cpp"
    break;

  case 68: /* value: DATE_STR  */
#line 623 "yacc_sql.y"
              {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      std::string str(tmp);
      Value * value = new Value();
      int date;
      if(string_to_date(str,date) < 0) {
        yyerror(&(yyloc),sql_string,sql_result,scanner,"date invaid",true);
        YYERROR;
      }
      else
      {
        value->set_date(date);
      }
      (yyval.value) = value;
      free(tmp);
    }
#line 2356 "yacc_sql.cpp"
    break;

  case 69: /* value: SSS  */
#line 639 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp);
      free(tmp);
    }
#line 2366 "yacc_sql.cpp"
    break;

  case 70: /* value: NULL_T  */
#line 644 "yacc_sql.y"
             {
      (yyval.value) = new Value();
      (yyval.value)->set_null();
    }
#line 2375 "yacc_sql.cpp"
    break;

  case 71: /* delete_stmt: DELETE FROM ID where  */
#line 652 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      (yyval.sql_node)->deletion.conditions = nullptr;
      if ((yyvsp[0].expression) != nullptr) {
        (yyval.sql_node)->deletion.conditions = (yyvsp[0].expression);
      }
      free((yyvsp[-1].string));
    }
#line 2389 "yacc_sql.cpp"
    break;

  case 72: /* update_stmt: UPDATE ID SET update_kv update_kv_list where  */
#line 664 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-4].string);
      (yyval.sql_node)->update.attribute_names.emplace_back((yyvsp[-2].update_kv)->attr_name);
      (yyval.sql_node)->update.values.emplace_back((yyvsp[-2].update_kv)->value);
      if (nullptr != (yyvsp[-1].update_kv_list)) {
        for (UpdateKV kv : *(yyvsp[-1].update_kv_list)) {
          (yyval.sql_node)->update.attribute_names.emplace_back(kv.attr_name);
          (yyval.sql_node)->update.values.emplace_back(kv.value);
        }
        delete (yyvsp[-1].update_kv_list);
      }
      (yyval.sql_node)->update.conditions = nullptr;
      if ((yyvsp[0].expression) != nullptr) {
        (yyval.sql_node)->update.conditions = (yyvsp[0].expression);
      }
      free((yyvsp[-4].string));
      delete (yyvsp[-2].update_kv);
    }
#line 2413 "yacc_sql.cpp"
    break;

  case 73: /* update_kv_list: %empty  */
#line 686 "yacc_sql.y"
    {
      (yyval.update_kv_list) = nullptr;
    }
#line 2421 "yacc_sql.cpp"
    break;

  case 74: /* update_kv_list: COMMA update_kv update_kv_list  */
#line 690 "yacc_sql.y"
    {
      if ((yyvsp[0].update_kv_list) != nullptr) {
        (yyval.update_kv_list) = (yyvsp[0].update_kv_list);
      } else {
        (yyval.update_kv_list) = new std::vector<UpdateKV>;
      }
      (yyval.update_kv_list)->emplace_back(*(yyvsp[-1].update_kv));
      delete (yyvsp[-1].update_kv);
    }
#line 2435 "yacc_sql.cpp"
    break;

  case 75: /* update_kv: ID EQ expression  */
#line 703 "yacc_sql.y"
    {
      (yyval.update_kv) = new UpdateKV;
      (yyval.update_kv)->attr_name = (yyvsp[-2].string);
      (yyval.update_kv)->value = (yyvsp[0].expression);
      free((yyvsp[-2].string));
    }
#line 2446 "yacc_sql.cpp"
    break;

  case 76: /* from_list: %empty  */
#line 712 "yacc_sql.y"
                {
      (yyval.inner_joins_list) = nullptr;
    }
#line 2454 "yacc_sql.cpp"
    break;

  case 77: /* from_list: COMMA from_node from_list  */
#line 715 "yacc_sql.y"
                                {
      if (nullptr != (yyvsp[0].inner_joins_list)) {
        (yyval.inner_joins_list) = (yyvsp[0].inner_joins_list);
      } else {
        (yyval.inner_joins_list) = new std::vector<InnerJoinSqlNode>;
      }
      (yyval.inner_joins_list)->emplace_back(*(yyvsp[-1].inner_joins));
      delete (yyvsp[-1].inner_joins);
    }
#line 2468 "yacc_sql.cpp"
    break;

  case 78: /* alias: %empty  */
#line 727 "yacc_sql.y"
                {
      (yyval.string) = nullptr;
    }
#line 2476 "yacc_sql.cpp"
    break;

  case 79: /* alias: ID  */
#line 730 "yacc_sql.y"
         {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2484 "yacc_sql.cpp"
    break;

  case 80: /* alias: AS ID  */
#line 733 "yacc_sql.y"
            {
      (yyval.string) = (yyvsp[0].string);
    }
#line 2492 "yacc_sql.cpp"
    break;

  case 81: /* from_node: ID alias join_list  */
#line 738 "yacc_sql.y"
                       {
      if (nullptr != (yyvsp[0].inner_joins)) {
        (yyval.inner_joins) = (yyvsp[0].inner_joins);
      } else {
        (yyval.inner_joins) = new InnerJoinSqlNode;
      }
      (yyval.inner_joins)->base_relation.first = (yyvsp[-2].string);
      (yyval.inner_joins)->base_relation.second = nullptr == (yyvsp[-1].string) ? "" : std::string((yyvsp[-1].string));
      std::reverse((yyval.inner_joins)->join_relations.begin(), (yyval.inner_joins)->join_relations.end());
      std::reverse((yyval.inner_joins)->conditions.begin(), (yyval.inner_joins)->conditions.end());
      free((yyvsp[-2].string));
      free((yyvsp[-1].string));
    }
#line 2510 "yacc_sql.cpp"
    break;

  case 82: /* join_list: %empty  */
#line 754 "yacc_sql.y"
                {
      (yyval.inner_joins) = nullptr;
    }
#line 2518 "yacc_sql.cpp"
    break;

  case 83: /* join_list: INNER JOIN ID alias ON condition join_list  */
#line 757 "yacc_sql.y"
                                                 {
      if (nullptr != (yyvsp[0].inner_joins)) {
        (yyval.inner_joins) = (yyvsp[0].inner_joins);
      } else {
        (yyval.inner_joins) = new InnerJoinSqlNode;
      }
      std::string temp = "";
      if (nullptr != (yyvsp[-3].string)) {
        temp = (yyvsp[-3].string);
      }
      (yyval.inner_joins)->join_relations.emplace_back((yyvsp[-4].string), temp);
      (yyval.inner_joins)->conditions.emplace_back((yyvsp[-1].expression));
      free((yyvsp[-4].string));
      free((yyvsp[-3].string));
    }
#line 2538 "yacc_sql.cpp"
    break;

  case 84: /* sub_query_expr: LBRACE select_stmt RBRACE  */
#line 776 "yacc_sql.y"
    {
      (yyval.expression) = new SubQueryExpr((yyvsp[-1].sql_node)->selection); // 子查询中所有的 Expression 都交给 SubQueryExpr 来管理了
      delete (yyvsp[-1].sql_node);
    }
#line 2547 "yacc_sql.cpp"
    break;

  case 85: /* select_stmt: SELECT expression_list  */
#line 784 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[0].expression_list) != nullptr) {
        std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
        (yyval.sql_node)->selection.project_exprs.swap(*(yyvsp[0].expression_list));
        delete (yyvsp[0].expression_list);
      }
    }
#line 2560 "yacc_sql.cpp"
    break;

  case 86: /* select_stmt: SELECT expression_list FROM from_node from_list where opt_group_by opt_having opt_order_by  */
#line 793 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
      if ((yyvsp[-7].expression_list) != nullptr) {
        std::reverse((yyvsp[-7].expression_list)->begin(), (yyvsp[-7].expression_list)->end());
        (yyval.sql_node)->selection.project_exprs.swap(*(yyvsp[-7].expression_list));
        delete (yyvsp[-7].expression_list);
      }
      if ((yyvsp[-4].inner_joins_list) != nullptr) {
        (yyval.sql_node)->selection.relations.swap(*(yyvsp[-4].inner_joins_list));
        delete (yyvsp[-4].inner_joins_list);
      }
      (yyval.sql_node)->selection.relations.push_back(*(yyvsp[-5].inner_joins));
      std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());

      (yyval.sql_node)->selection.conditions = nullptr;
      if ((yyvsp[-3].expression) != nullptr) {
        (yyval.sql_node)->selection.conditions = (yyvsp[-3].expression);
      }
      if ((yyvsp[-2].expression_list) != nullptr) {
        (yyval.sql_node)->selection.groupby_exprs.swap(*(yyvsp[-2].expression_list));
        delete (yyvsp[-2].expression_list);
        std::reverse((yyval.sql_node)->selection.groupby_exprs.begin(), (yyval.sql_node)->selection.groupby_exprs.end());
      }
      (yyval.sql_node)->selection.having_conditions = nullptr;
      if ((yyvsp[-1].expression) != nullptr) {
        (yyval.sql_node)->selection.having_conditions = (yyvsp[-1].expression);
      }

      if ((yyvsp[0].orderby_unit_list) != nullptr) {
        (yyval.sql_node)->selection.orderbys.swap(*(yyvsp[0].orderby_unit_list));
        delete (yyvsp[0].orderby_unit_list);
      }
      delete (yyvsp[-5].inner_joins);
    }
#line 2599 "yacc_sql.cpp"
    break;

  case 87: /* calc_stmt: CALC expression_list  */
#line 830 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression_list)->begin(), (yyvsp[0].expression_list)->end());
      (yyval.sql_node)->calc.expressions.swap(*(yyvsp[0].expression_list));
      delete (yyvsp[0].expression_list);
    }
#line 2610 "yacc_sql.cpp"
    break;

  case 88: /* expression_list: expression alias  */
#line 840 "yacc_sql.y"
    {
      (yyval.expression_list) = new std::vector<Expression*>;
      if (nullptr != (yyvsp[0].string)) {
        (yyvsp[-1].expression)->set_alias((yyvsp[0].string));
      }
      (yyval.expression_list)->emplace_back((yyvsp[-1].expression));
      free((yyvsp[0].string));
    }
#line 2623 "yacc_sql.cpp"
    break;

  case 89: /* expression_list: expression alias COMMA expression_list  */
#line 849 "yacc_sql.y"
    {
      if ((yyvsp[0].expression_list) != nullptr) {
        (yyval.expression_list) = (yyvsp[0].expression_list);
      } else {
        (yyval.expression_list) = new std::vector<Expression *>;
      }
      if (nullptr != (yyvsp[-2].string)) {
        (yyvsp[-3].expression)->set_alias((yyvsp[-2].string));
      }
      (yyval.expression_list)->emplace_back((yyvsp[-3].expression));
      free((yyvsp[-2].string));
    }
#line 2640 "yacc_sql.cpp"
    break;

  case 90: /* expression: expression '+' expression  */
#line 863 "yacc_sql.y"
                              {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2648 "yacc_sql.cpp"
    break;

  case 91: /* expression: expression '-' expression  */
#line 866 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2656 "yacc_sql.cpp"
    break;

  case 92: /* expression: expression '*' expression  */
#line 869 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2664 "yacc_sql.cpp"
    break;

  case 93: /* expression: expression '/' expression  */
#line 872 "yacc_sql.y"
                                {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression), (yyvsp[0].expression), sql_string, &(yyloc));
    }
#line 2672 "yacc_sql.cpp"
    break;

  case 94: /* expression: LBRACE expression_list RBRACE  */
#line 875 "yacc_sql.y"
                                    {
      if ((yyvsp[-1].expression_list)->size() == 1) {
        (yyval.expression) = (yyvsp[-1].expression_list)->front();
      } else {
        (yyval.expression) = new ExprListExpr(std::move(*(yyvsp[-1].expression_list)));
      }
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[-1].expression_list);
    }
#line 2686 "yacc_sql.cpp"
    break;

  case 95: /* expression: '-' expression  */
#line 884 "yacc_sql.y"
                                  {
      (yyval.expression) = create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression), nullptr, sql_string, &(yyloc));
    }
#line 2694 "yacc_sql.cpp"
    break;

  case 96: /* expression: value  */
#line 887 "yacc_sql.y"
            {
      (yyval.expression) = new ValueExpr(*(yyvsp[0].value));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].value);
    }
#line 2704 "yacc_sql.cpp"
    break;

  case 97: /* expression: rel_attr  */
#line 892 "yacc_sql.y"
               {
      (yyval.expression) = new FieldExpr((yyvsp[0].rel_attr)->relation_name, (yyvsp[0].rel_attr)->attribute_name);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[0].rel_attr);
    }
#line 2714 "yacc_sql.cpp"
    break;

  case 98: /* expression: aggr_func_expr  */
#line 897 "yacc_sql.y"
                     {
      (yyval.expression) = (yyvsp[0].expression); // AggrFuncExpr
    }
#line 2722 "yacc_sql.cpp"
    break;

  case 99: /* expression: func_expr  */
#line 900 "yacc_sql.y"
                {
      (yyval.expression) = (yyvsp[0].expression); // SysFuncExpr
    }
#line 2730 "yacc_sql.cpp"
    break;

  case 100: /* expression: sub_query_expr  */
#line 903 "yacc_sql.y"
                     {
      (yyval.expression) = (yyvsp[0].expression); // SubQueryExpr
    }
#line 2738 "yacc_sql.cpp"
    break;

  case 101: /* aggr_func_expr: ID LBRACE expression RBRACE  */
#line 910 "yacc_sql.y"
    {
      Expression* rhs = (yyvsp[-1].expression);
      if ((yyvsp[-1].expression)->type() == ExprType::FIELD) {
        FieldExpr* field_expr = static_cast<FieldExpr*>((yyvsp[-1].expression));
        if (field_expr->get_field_name() == "*") {
          if(get_aggr_func_type((yyvsp[-3].string)) != AggrFuncType::AGG_COUNT) {
            delete (yyvsp[-1].expression);
            yyerror(&(yyloc), sql_string, sql_result, scanner, "only support count(*)");
            YYERROR;
          }
          rhs = new ValueExpr(Value(1));
          delete (yyvsp[-1].expression);
        }
      }
      (yyval.expression) = new AggrFuncExpr(get_aggr_func_type((yyvsp[-3].string)), rhs);
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
    }
#line 2760 "yacc_sql.cpp"
    break;

  case 102: /* sys_func_type: LENGTH  */
#line 929 "yacc_sql.y"
           {
      (yyval.number) = SysFuncType::SYS_FUNC_LENGTH;
    }
#line 2768 "yacc_sql.cpp"
    break;

  case 103: /* sys_func_type: ROUND  */
#line 932 "yacc_sql.y"
            {
      (yyval.number) = SysFuncType::SYS_FUNC_ROUND;
    }
#line 2776 "yacc_sql.cpp"
    break;

  case 104: /* sys_func_type: DATE_FORMAT  */
#line 935 "yacc_sql.y"
                  {
      (yyval.number) = SysFuncType::SYS_FUNC_DATE_FORMAT;
    }
#line 2784 "yacc_sql.cpp"
    break;

  case 105: /* func_expr: sys_func_type LBRACE expression_list RBRACE  */
#line 942 "yacc_sql.y"
    {
      std::reverse((yyvsp[-1].expression_list)->begin(),(yyvsp[-1].expression_list)->end());
      (yyval.expression) = new SysFuncExpr((SysFuncType)(yyvsp[-3].number),*(yyvsp[-1].expression_list));
      (yyval.expression)->set_name(token_name(sql_string, &(yyloc)));
      delete (yyvsp[-1].expression_list);
    }
#line 2795 "yacc_sql.cpp"
    break;

  case 106: /* rel_attr: ID  */
#line 951 "yacc_sql.y"
       {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 2805 "yacc_sql.cpp"
    break;

  case 107: /* rel_attr: ID DOT ID  */
#line 956 "yacc_sql.y"
                {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2817 "yacc_sql.cpp"
    break;

  case 108: /* rel_attr: '*' DOT '*'  */
#line 963 "yacc_sql.y"
                  {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = "*";
      (yyval.rel_attr)->attribute_name = "*";
    }
#line 2827 "yacc_sql.cpp"
    break;

  case 109: /* rel_attr: ID DOT '*'  */
#line 968 "yacc_sql.y"
                 {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-2].string);
      (yyval.rel_attr)->attribute_name = "*";
      free((yyvsp[-2].string));
    }
#line 2838 "yacc_sql.cpp"
    break;

  case 110: /* rel_attr: '*'  */
#line 974 "yacc_sql.y"
          {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = "*";
      (yyval.rel_attr)->attribute_name = "*";
    }
#line 2848 "yacc_sql.cpp"
    break;

  case 111: /* where: %empty  */
#line 983 "yacc_sql.y"
    {
      (yyval.expression) = nullptr;
    }
#line 2856 "yacc_sql.cpp"
    break;

  case 112: /* where: WHERE condition  */
#line 986 "yacc_sql.y"
                      {
      (yyval.expression) = (yyvsp[0].expression);  
    }
#line 2864 "yacc_sql.cpp"
    break;

  case 113: /* is_null_comp: IS NULL_T  */
#line 993 "yacc_sql.y"
    {
      (yyval.boolean) = true;
    }
#line 2872 "yacc_sql.cpp"
    break;

  case 114: /* is_null_comp: IS NOT NULL_T  */
#line 997 "yacc_sql.y"
    {
      (yyval.boolean) = false;
    }
#line 2880 "yacc_sql.cpp"
    break;

  case 115: /* condition: expression comp_op expression  */
#line 1004 "yacc_sql.y"
    {
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp), (yyvsp[-2].expression), (yyvsp[0].expression));
    }
#line 2888 "yacc_sql.cpp"
    break;

  case 116: /* condition: expression is_null_comp  */
#line 1008 "yacc_sql.y"
    {
      Value val;
      val.set_null();
      ValueExpr *value_expr = new ValueExpr(val);
      (yyval.expression) = new ComparisonExpr((yyvsp[0].boolean) ? IS_NULL : IS_NOT_NULL, (yyvsp[-1].expression), value_expr);
    }
#line 2899 "yacc_sql.cpp"
    break;

  case 117: /* condition: exists_op expression  */
#line 1015 "yacc_sql.y"
    {
      Value val;
      val.set_null();
      ValueExpr *value_expr = new ValueExpr(val);
      (yyval.expression) = new ComparisonExpr((yyvsp[-1].comp), value_expr, (yyvsp[0].expression));
    }
#line 2910 "yacc_sql.cpp"
    break;

  case 118: /* condition: condition AND condition  */
#line 1022 "yacc_sql.y"
    {
      (yyval.expression) = new ConjunctionExpr(ConjunctionExpr::Type::AND, (yyvsp[-2].expression), (yyvsp[0].expression));
    }
#line 2918 "yacc_sql.cpp"
    break;

  case 119: /* condition: condition OR condition  */
#line 1026 "yacc_sql.y"
    {
      (yyval.expression) = new ConjunctionExpr(ConjunctionExpr::Type::OR, (yyvsp[-2].expression), (yyvsp[0].expression));
    }
#line 2926 "yacc_sql.cpp"
    break;

  case 120: /* sort_unit: expression  */
#line 1033 "yacc_sql.y"
        {
    (yyval.orderby_unit) = new OrderBySqlNode();//默认是升序
    (yyval.orderby_unit)->expr = (yyvsp[0].expression);
    (yyval.orderby_unit)->is_asc = true;
	}
#line 2936 "yacc_sql.cpp"
    break;

  case 121: /* sort_unit: expression DESC  */
#line 1040 "yacc_sql.y"
        {
    (yyval.orderby_unit) = new OrderBySqlNode();
    (yyval.orderby_unit)->expr = (yyvsp[-1].expression);
    (yyval.orderby_unit)->is_asc = false;
	}
#line 2946 "yacc_sql.cpp"
    break;

  case 122: /* sort_unit: expression ASC  */
#line 1047 "yacc_sql.y"
        {
    (yyval.orderby_unit) = new OrderBySqlNode();//默认是升序
    (yyval.orderby_unit)->expr = (yyvsp[-1].expression);
    (yyval.orderby_unit)->is_asc = true;
	}
#line 2956 "yacc_sql.cpp"
    break;

  case 123: /* sort_list: sort_unit  */
#line 1055 "yacc_sql.y"
        {
    (yyval.orderby_unit_list) = new std::vector<OrderBySqlNode>;
    (yyval.orderby_unit_list)->emplace_back(*(yyvsp[0].orderby_unit));
    delete (yyvsp[0].orderby_unit);
	}
#line 2966 "yacc_sql.cpp"
    break;

  case 124: /* sort_list: sort_unit COMMA sort_list  */
#line 1062 "yacc_sql.y"
        {
    (yyvsp[0].orderby_unit_list)->emplace_back(*(yyvsp[-2].orderby_unit));
    (yyval.orderby_unit_list) = (yyvsp[0].orderby_unit_list);
    delete (yyvsp[-2].orderby_unit);
	}
#line 2976 "yacc_sql.cpp"
    break;

  case 125: /* opt_order_by: %empty  */
#line 1069 "yacc_sql.y"
                    {
   (yyval.orderby_unit_list) = nullptr;
  }
#line 2984 "yacc_sql.cpp"
    break;

  case 126: /* opt_order_by: ORDER BY sort_list  */
#line 1073 "yacc_sql.y"
        {
      (yyval.orderby_unit_list) = (yyvsp[0].orderby_unit_list);
      std::reverse((yyval.orderby_unit_list)->begin(),(yyval.orderby_unit_list)->end());
	}
#line 2993 "yacc_sql.cpp"
    break;

  case 127: /* opt_group_by: %empty  */
#line 1079 "yacc_sql.y"
                    {
   (yyval.expression_list) = nullptr;
  }
#line 3001 "yacc_sql.cpp"
    break;

  case 128: /* opt_group_by: GROUP BY expression_list  */
#line 1083 "yacc_sql.y"
        {
      (yyval.expression_list) = (yyvsp[0].expression_list);
      std::reverse((yyval.expression_list)->begin(),(yyval.expression_list)->end());
	}
#line 3010 "yacc_sql.cpp"
    break;

  case 129: /* opt_having: %empty  */
#line 1089 "yacc_sql.y"
              {
   (yyval.expression) = nullptr;
  }
#line 3018 "yacc_sql.cpp"
    break;

  case 130: /* opt_having: HAVING condition  */
#line 1093 "yacc_sql.y"
        {
      (yyval.expression) = (yyvsp[0].expression);
	}
#line 3026 "yacc_sql.cpp"
    break;

  case 131: /* comp_op: EQ  */
#line 1099 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3032 "yacc_sql.cpp"
    break;

  case 132: /* comp_op: LT  */
#line 1100 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3038 "yacc_sql.cpp"
    break;

  case 133: /* comp_op: GT  */
#line 1101 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3044 "yacc_sql.cpp"
    break;

  case 134: /* comp_op: LE  */
#line 1102 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3050 "yacc_sql.cpp"
    break;

  case 135: /* comp_op: GE  */
#line 1103 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3056 "yacc_sql.cpp"
    break;

  case 136: /* comp_op: NE  */
#line 1104 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3062 "yacc_sql.cpp"
    break;

  case 137: /* comp_op: LIKE  */
#line 1105 "yacc_sql.y"
           { (yyval.comp) = LIKE_OP;}
#line 3068 "yacc_sql.cpp"
    break;

  case 138: /* comp_op: NOT LIKE  */
#line 1106 "yacc_sql.y"
               {(yyval.comp) = NOT_LIKE_OP;}
#line 3074 "yacc_sql.cpp"
    break;

  case 139: /* comp_op: IN  */
#line 1107 "yacc_sql.y"
         { (yyval.comp) = IN_OP; }
#line 3080 "yacc_sql.cpp"
    break;

  case 140: /* comp_op: NOT IN  */
#line 1108 "yacc_sql.y"
             { (yyval.comp) = NOT_IN_OP; }
#line 3086 "yacc_sql.cpp"
    break;

  case 141: /* exists_op: EXISTS  */
#line 1112 "yacc_sql.y"
           { (yyval.comp) = EXISTS_OP; }
#line 3092 "yacc_sql.cpp"
    break;

  case 142: /* exists_op: NOT EXISTS  */
#line 1113 "yacc_sql.y"
                 { (yyval.comp) = NOT_EXISTS_OP; }
#line 3098 "yacc_sql.cpp"
    break;

  case 143: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1118 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3112 "yacc_sql.cpp"
    break;

  case 144: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1131 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3121 "yacc_sql.cpp"
    break;

  case 145: /* set_variable_stmt: SET ID EQ value  */
#line 1139 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3133 "yacc_sql.cpp"
    break;


#line 3137 "yacc_sql.cpp"

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
  *++yylsp = yyloc;

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
          = {yyssp, yytoken, &yylloc};
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
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
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

#line 1151 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
