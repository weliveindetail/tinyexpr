#ifndef __FREE_H__
#define __FREE_H__

#include "common.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Frees the expression. */
/* This is safe to call on NULL pointers. */
void te_free(te_expr *n);

void te_free_parameters(te_expr *n);

#ifdef __cplusplus
}
#endif

#endif
