#include <stdlib.h>
#include <stdio.h>

#include "pylia.h"
#include "gc.h"

pl_gcframe_t *pl_pgcstack = NULL;

// record backtrace and raise an error
void pl_throw(pl_value_t *e)
{
    printf("throw %p\n", e);
    exit(-1);
}