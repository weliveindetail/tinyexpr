#ifndef __COMPILE_H__
#define __COMPILE_H__

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Evaluates the expression. */
double te_eval(const te_expr *n);

/* Parses the input expression and binds variables. */
/* Returns NULL on error. */
te_expr *te_compile(const char *expression, const te_variable *variables, int var_count, int *error);

#ifdef __cplusplus
}
#endif

#endif
