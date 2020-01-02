#ifndef __COMPILE_H__
#define __COMPILE_H__

#include "common.h"
#include "eval.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Parses the input expression and binds variables. */
/* Returns NULL on error. */
te_expr *te_compile(const char *expression, const te_variable *variables, int var_count, int *error);

#ifdef __cplusplus
}
#endif

#endif
