#pragma once

#include "pylia.h"
#include "dtypes.h"

#define BVOFFS 2
#define GC_PAGE_SZ (1536*sizeof(void*))     //bytes


typedef struct _gcpage_t {
    char data[GC_PAGE_SZ];
    union {
        struct _gcpage_t *next;
        char _pad[8];
    };
} gcpage_t;

typedef struct _gcval_t {
    union {
        struct _gcval_t *next;
        uptrint_t flags;
        uptrint_t data0;    // overlapped
        uptrint_t marked:1;
    };
} gcval_t;

typedef struct _pool_t {
    size_t osize;
    gcpage_t *pages;
    gcval_t *freelist;
} pool_t;

typedef struct _bigval_t {
    struct _bigval_t *next;
    size_t sz;
    union {
        uptrint_t flags;
        uptrint_t marked:1;
        char _data[1];
    };
} bigval_t;

#define gc_marked(o)  (((gcval_t*)(o))->marked)
#define gc_setmark(o) (((gcval_t*)(o))->marked=1)
#define gc_val_buf(o) ((gcval_t*)(((void**)(o))-1))
#define gc_setmark_buf(o) gc_setmark(gc_val_buf(o))




typedef struct _pl_gcframe_t {
    size_t nroots;
    struct _pl_gcframe_t *prev;
    // actual roots go here
} pl_gcframe_t;

// NOTE: it is the caller's responsibility to make sure arguments are
// rooted. foo(f(), g()) will not work, and foo can't do anything about it,
// so the caller must do
// pl_value_t *x=NULL, *y=NULL; PL_GC_PUSH(&x, &y);
// x = f(); y = g(); foo(x, y)

extern pl_gcframe_t *pl_pgcstack;

#define PL_GC_PUSH(...)                                                   \
  void *__gc_stkf[] = {(void*)((VA_NARG(__VA_ARGS__)<<1)|1), pl_pgcstack, \
                       __VA_ARGS__};                                      \
  pl_pgcstack = (pl_gcframe_t*)__gc_stkf;

#define PL_GC_PUSHARGS(rts_var,n)                               \
  rts_var = ((pl_value_t**)alloca(((n)+2)*sizeof(pl_value_t*)))+2;    \
  ((void**)rts_var)[-2] = (void*)(((size_t)n)<<1);              \
  ((void**)rts_var)[-1] = pl_pgcstack;                          \
  pl_pgcstack = (pl_gcframe_t*)&(((void**)rts_var)[-2])

#define PL_GC_POP() (pl_pgcstack = pl_pgcstack->prev)

void pl_gc_init(void);
void pl_gc_setmark(pl_value_t *v);
void pl_gc_enable(void);
void pl_gc_disable(void);
int pl_gc_is_enabled(void);
void pl_gc_ephemeral_on(void);
void pl_gc_ephemeral_off(void);
void pl_gc_collect(void);
void pl_gc_preserve(pl_value_t *v);
void pl_gc_unpreserve(void);
int pl_gc_n_preserved_values(void);
void pl_gc_add_finalizer(pl_value_t *v, pl_function_t *f);
pl_weakref_t *pl_gc_new_weakref(pl_value_t *value);
pl_mallocptr_t *pl_gc_acquire_buffer(void *b, size_t sz);
pl_mallocptr_t *pl_gc_managed_malloc(size_t sz);
void *alloc_2w(void);
void *alloc_3w(void);
void *alloc_4w(void);


void *allocb(size_t sz);
void *allocobj(size_t sz);
