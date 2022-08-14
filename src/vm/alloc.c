#include "pylia.h"
#include "newobj_internal.h"

#include <stdarg.h>

pl_tuple_t *pl_tuple(size_t n, ...)
{
    va_list args;
    size_t i;
    if (n == 0) return pl_null;
    va_start(args, n);
    pl_tuple_t *jv = (pl_tuple_t*)newobj((pl_type_t*)pl_tuple_type, n+1);
    pl_tuple_set_len_unsafe(jv, n);
    for(i=0; i < n; i++) {
        pl_tupleset(jv, i, va_arg(args, pl_value_t*));
    }
    va_end(args);
    return jv;
}

pl_tuple_t *pl_tuple1(void *a)
{
    pl_tuple_t *t = (pl_tuple_t*)alloc_3w();
    t->type = (pl_type_t*)pl_tuple_type;
    pl_tuple_set_len_unsafe(t, 1);
    pl_tupleset(t, 0, a);
    return t;
}

pl_tuple_t *pl_tuple2(void *a, void *b)
{
    pl_tuple_t *t = (pl_tuple_t*)alloc_4w();
    t->type = (pl_type_t*)pl_tuple_type;
    pl_tuple_set_len_unsafe(t, 2);
    pl_tupleset(t, 0, a);
    pl_tupleset(t, 1, b);
    return t;
}

pl_tuple_t *pl_alloc_tuple_uninit(size_t n)
{
    if (n == 0) return pl_null;
    pl_tuple_t *pv = (pl_tuple_t*)newobj((pl_type_t*)pl_tuple_type, n+1);
    pl_tuple_set_len_unsafe(pv, n);
    return pv;
}

pl_tuple_t *pl_alloc_tuple(size_t n)
{
    if (n == 0) return pl_null;
    pl_tuple_t *pv = pl_alloc_tuple_uninit(n);
    size_t i;
    for(i=0; i < n; i++) {
        pl_tupleset(pv, i, NULL);
    }
    return pv;
}

pl_tuple_t *pl_tuple_append(pl_tuple_t *a, pl_tuple_t *b)
{
    pl_tuple_t *c = pl_alloc_tuple_uninit(pl_tuple_len(a) + pl_tuple_len(b));
    size_t i=0, j;
    for(j=0; j < pl_tuple_len(a); j++) {
        pl_tupleset(c, i, pl_tupleref(a,j));
        i++;
    }
    for(j=0; j < pl_tuple_len(b); j++) {
        pl_tupleset(c, i, pl_tupleref(b,j));
        i++;
    }
    return c;
}

pl_tuple_t *pl_tuple_fill(size_t n, pl_value_t *v)
{
    if (n==0) return pl_null;
    pl_tuple_t *tup = pl_alloc_tuple_uninit(n);
    size_t i;
    for(i=0; i < n; i++) {
        pl_tupleset(tup, i, v);
    }
    return tup;
}


void pl_unmark_symbols(void) {
    // unmark_symbols_(symtab);
}