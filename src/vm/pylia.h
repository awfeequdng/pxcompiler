#pragma once

#include <stddef.h>
#include <dtypes.h>

#include "htable.h"
#include "arraylist.h"

#define PL_STRUCT_TYPE \
    struct _pl_type_t *type;

typedef struct _pl_value_t {
    PL_STRUCT_TYPE
} pl_value_t;

// pseudo-object to track managed malloc pointers
// currently only referenced from an array's data owner field
typedef struct _pl_mallocptr_t {
    struct _pl_mallocptr_t *next;
    size_t sz;
    void *ptr;
} pl_mallocptr_t;

typedef struct {
    PL_STRUCT_TYPE
    pl_value_t *value;
} pl_weakref_t;

typedef struct _pl_type_t {
    PL_STRUCT_TYPE
} pl_type_t;

typedef struct {
    PL_STRUCT_TYPE
} pl_bits_type_t;


typedef pl_value_t *(*pl_fptr_t)(pl_value_t*, pl_value_t**, uint32_t);

#define PL_FUNC_FIELDS                          \
    pl_fptr_t fptr;                             \
    pl_value_t *env;


typedef struct {
    uint16_t offset;   // offset relative to data start, excluding type tag
    uint16_t size:15;
    uint16_t isptr:1;
} pl_fielddesc_t;

typedef struct {
    PL_STRUCT_TYPE
    PL_FUNC_FIELDS
    uint32_t size;
    pl_fielddesc_t fields[1];
} pl_struct_type_t;


typedef struct {
    PL_STRUCT_TYPE
    PL_FUNC_FIELDS
} pl_function_t;


static inline
pl_value_t *pl_apply(pl_function_t *f, pl_value_t **args, uint32_t nargs)
{
    return f->fptr((pl_value_t*)f, args, nargs);
}


typedef struct {
    PL_STRUCT_TYPE
    size_t length;
    pl_value_t *data[1];
} pl_tuple_t;
pl_tuple_t *pl_tuple2(void *a, void *b);

#define pl_tupleref(t,i) (((pl_value_t**)(t))[2+(i)])
#define pl_tupleset(t,i,x) ((((pl_value_t**)(t))[2+(i)])=(pl_value_t*)(x))
#define pl_t0(t) pl_tupleref(t,0)
#define pl_t1(t) pl_tupleref(t,1)

#define pl_tuple_len(t)   (((pl_tuple_t*)(t))->length)
#define pl_tuple_set_len_unsafe(t,n) (((pl_tuple_t*)(t))->length=(n))

// alloc.c
pl_tuple_t *pl_alloc_tuple(size_t n);

extern pl_value_t *pl_true;
extern pl_value_t *pl_false;


extern pl_struct_type_t *pl_function_type;
extern pl_struct_type_t *pl_bits_kind;

extern pl_value_t *pl_memory_exception;

// pltypes.c
extern pl_struct_type_t *pl_typename_type;
extern pl_struct_type_t *pl_sym_type;
extern pl_struct_type_t *pl_symbol_type;
extern pl_struct_type_t *pl_struct_kind;
extern pl_tuple_t *pl_tuple_type;
extern pl_bits_type_t *pl_bool_type;
extern pl_bits_type_t *pl_char_type;
extern pl_bits_type_t *pl_int8_type;
extern pl_bits_type_t *pl_uint8_type;
extern pl_bits_type_t *pl_int16_type;
extern pl_bits_type_t *pl_uint16_type;
extern pl_bits_type_t *pl_int32_type;
extern pl_bits_type_t *pl_uint32_type;
extern pl_bits_type_t *pl_int64_type;
extern pl_bits_type_t *pl_uint64_type;
extern pl_bits_type_t *pl_float32_type;
extern pl_bits_type_t *pl_float64_type;
extern pl_struct_type_t *pl_weakref_type;
extern pl_value_t *pl_nothing;
extern pl_tuple_t *pl_null;


#define pl_is_struct_type(v) pl_typeis(v,pl_struct_kind)

#define pl_typeof(v) (((pl_value_t*)(v))->type)
#define pl_typeis(v,t) (pl_typeof(v)==(pl_type_t*)(t))
#define pl_is_func(v)        (pl_typeis(v,pl_function_type) || pl_is_struct_type(v))
#define pl_is_function(v)    pl_is_func(v)
#define pl_is_tuple(v)       pl_typeis(v,pl_tuple_type)



#define PL_TRY

#define PL_CATCH

void pl_throw(pl_value_t *e);
void pylia_init();
void pl_init_types(void);

int pl_cpu_cores(void);

void pl_gc_init(void);


#ifdef __LP64__
#define NWORDS(sz) (((sz)+7)>>3)
#else
#define NWORDS(sz) (((sz)+3)>>2)
#endif
