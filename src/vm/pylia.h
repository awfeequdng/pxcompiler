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

typedef struct _pl_sym_t {
    PL_STRUCT_TYPE
    struct _pl_sym_t *left;
    struct _pl_sym_t *right;
    uptrint_t hash;    // precomputed hash value
    union {
        char name[1];
        void *_pad;    // ensure field aligned to pointer size
    };
} pl_sym_t;

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


// how much space we're willing to waste if an array outgrows its
// original object
#define ARRAY_INLINE_NBYTES (2048*sizeof(void*))

/*
  array data is allocated in two ways: either inline in the array object,
  (in _space), or with malloc with data owner pointing to a pl_mallocptr_t.
  data owner can also point to another array, if the original data was
  allocated inline.
*/
typedef struct {
    PL_STRUCT_TYPE
    void *data;
    size_t length;

    unsigned short ndims:14;
    unsigned short ptrarray:1;  // representation is pointer array
    unsigned short ismalloc:1;  // data owner is a pl_mallocptr_t
    uint16_t elsize;
    uint32_t offset;  // for 1-d only. does not need to get big.

    size_t nrows;
    union {
        // 1d
        size_t maxsize;
        // Nd
        size_t ncols;
    };
    // other dim sizes go here for ndims > 2

    union {
        char _space[1];
        void *_pad;
    };
} pl_array_t;


typedef pl_value_t *(*pl_fptr_t)(pl_value_t*, pl_value_t**, uint32_t);


typedef struct {
    PL_STRUCT_TYPE
    size_t length;
    pl_value_t *data[1];
} pl_tuple_t;

typedef struct _pl_lambda_info_t {
    PL_STRUCT_TYPE
    // this holds the static data for a function:
    // a syntax tree, static parameters, and (if it has been compiled)
    // a function pointer.
    // this is the stuff that's shared among different instantiations
    // (different environments) of a closure.
    pl_value_t *ast;
    // sparams is a tuple (symbol, value, symbol, value, ...)
    pl_tuple_t *sparams;
    pl_value_t *tfunc;
    pl_sym_t *name;  // for error reporting
    pl_array_t *roots;  // pointers in generated code
    pl_tuple_t *specTypes;  // argument types this is specialized for
    // a slower-but-works version of this function as a fallback
    struct _pl_function_t *unspecialized;
    // array of all lambda infos with code generated from this one
    pl_array_t *specializations;
    struct _pl_module_t *module;
    struct _pl_lambda_info_t *def;  // original this is specialized from
    pl_value_t *capt;  // captured var info
    pl_sym_t *file;
    int32_t line;
    int8_t inferred;

    // hidden fields:
    // flag telling if inference is running on this function
    // used to avoid infinite recursion
    int8_t inInference : 1;
    int8_t inCompile : 1;
    pl_fptr_t fptr;        // jlcall entry point
    void *functionObject;  // jlcall llvm Function
    void *cFunctionObject; // c callable llvm Function
} pl_lambda_info_t;

#define PL_FUNC_FIELDS                          \
    pl_fptr_t fptr;                             \
    pl_value_t *env;                            \
    pl_lambda_info_t *linfo;


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

#define pl_field_offset(st,i) (((pl_struct_type_t*)st)->fields[i].offset)
#define pl_field_size(st,i)   (((pl_struct_type_t*)st)->fields[i].size)

typedef struct {
    PL_STRUCT_TYPE
    pl_sym_t *name;
    pl_value_t *lb;   // lower bound
    pl_value_t *ub;   // upper bound
    uptrint_t bound;  // part of a constraint environment
} pl_tvar_t;

typedef struct {
    PL_STRUCT_TYPE
    PL_FUNC_FIELDS
} pl_function_t;


static inline
pl_value_t *pl_apply(pl_function_t *f, pl_value_t **args, uint32_t nargs)
{
    return f->fptr((pl_value_t*)f, args, nargs);
}


pl_tuple_t *pl_tuple2(void *a, void *b);

#define pl_tupleref(t,i) (((pl_value_t**)(t))[2+(i)])
#define pl_tupleset(t,i,x) ((((pl_value_t**)(t))[2+(i)])=(pl_value_t*)(x))
#define pl_t0(t) pl_tupleref(t,0)
#define pl_t1(t) pl_tupleref(t,1)

#define pl_tuple_len(t)   (((pl_tuple_t*)(t))->length)
#define pl_tuple_set_len_unsafe(t,n) (((pl_tuple_t*)(t))->length=(n))

typedef struct _pl_module_t {
    PL_STRUCT_TYPE
    pl_sym_t *name;
    struct _pl_module_t *parent;
    htable_t bindings;
    arraylist_t usings; // modules with all bindings potentially imported
} pl_module_t;

typedef struct {
    PL_STRUCT_TYPE
    pl_sym_t *name;
    struct _pl_module_t *module;

    // if this is the name of a parametric type, this field points to the
    // original type.
    // a type alias, for example, might make a type constructor that is
    // not the original.
    pl_value_t *primary;
    pl_value_t *cache;
} pl_typename_t;

typedef struct {
    PL_STRUCT_TYPE
    pl_tuple_t *types;
} pl_uniontype_t;

typedef struct _pl_tag_type_t {
    PL_STRUCT_TYPE
    PL_FUNC_FIELDS
    pl_typename_t *name;
    struct _pl_tag_type_t *super;
    pl_tuple_t *parameters;
} pl_tag_type_t;

// alloc.c
extern pl_sym_t *call_sym;    extern pl_sym_t *dots_sym;
extern pl_sym_t *call1_sym;   extern pl_sym_t *module_sym;
extern pl_sym_t *export_sym;  extern pl_sym_t *import_sym;
extern pl_sym_t *importall_sym; extern pl_sym_t *toplevel_sym;
extern pl_sym_t *quote_sym;   extern pl_sym_t *amp_sym;
extern pl_sym_t *top_sym;     extern pl_sym_t *colons_sym;
extern pl_sym_t *line_sym;    extern pl_sym_t *continue_sym;
// head symbols for each expression type
extern pl_sym_t *goto_sym;    extern pl_sym_t *goto_ifnot_sym;
extern pl_sym_t *label_sym;   extern pl_sym_t *return_sym;
extern pl_sym_t *lambda_sym;  extern pl_sym_t *assign_sym;
extern pl_sym_t *null_sym;    extern pl_sym_t *body_sym;
extern pl_sym_t *macro_sym;   extern pl_sym_t *method_sym;
extern pl_sym_t *enter_sym;   extern pl_sym_t *leave_sym;
extern pl_sym_t *exc_sym;     extern pl_sym_t *error_sym;
extern pl_sym_t *static_typeof_sym;
extern pl_sym_t *new_sym;     extern pl_sym_t *using_sym;
extern pl_sym_t *const_sym;   extern pl_sym_t *thunk_sym;
extern pl_sym_t *anonymous_sym;  extern pl_sym_t *underscore_sym;
extern pl_sym_t *abstracttype_sym; extern pl_sym_t *bitstype_sym;
extern pl_sym_t *compositetype_sym; extern pl_sym_t *type_goto_sym;
extern pl_sym_t *global_sym; extern pl_sym_t *tuple_sym;

pl_tuple_t *pl_alloc_tuple(size_t n);
pl_tag_type_t *pl_new_tagtype(pl_value_t *name, pl_tag_type_t *super,
                              pl_tuple_t *parameters);
pl_sym_t *pl_symbol(const char *str);

extern pl_value_t *pl_true;
extern pl_value_t *pl_false;


extern pl_struct_type_t *pl_function_type;
extern pl_struct_type_t *pl_bits_kind;

extern pl_value_t *pl_memory_exception;

// pltypes.c
extern pl_struct_type_t *pl_typename_type;
extern pl_struct_type_t *pl_sym_type;
extern pl_struct_type_t *pl_symbol_type;
extern pl_tuple_t *pl_tuple_type;

extern pl_struct_type_t *pl_union_kind;
extern pl_struct_type_t *pl_tag_kind;
extern pl_struct_type_t *pl_tag_type_type;
extern pl_struct_type_t *pl_struct_kind;
extern pl_struct_type_t *pl_bits_kind;


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


#define pl_typeof(v) (((pl_value_t*)(v))->type)
#define pl_typeis(v,t) (pl_typeof(v)==(pl_type_t*)(t))



#define pl_is_null(v)        (((pl_value_t*)(v)) == ((pl_value_t*)pl_null))
#define pl_is_tuple(v)       pl_typeis(v,pl_tuple_type)
#define pl_is_tag_type(v)    pl_typeis(v,pl_tag_kind)
// #define pl_is_some_tag_type(v) (pl_is_tag_type(v)||pl_is_struct_type(v)||pl_is_bits_type(v))
#define pl_is_bits_type(v)   pl_typeis(v,pl_bits_kind)
// #define pl_bitstype_nbits(t) (((pl_bits_type_t*)t)->nbits)
#define pl_is_struct_type(v) pl_typeis(v,pl_struct_kind)
// #define pl_is_union_type(v)  pl_typeis(v,pl_union_kind)
// #define pl_is_typevar(v)     pl_typeis(v,pl_tvar_type)
// #define pl_is_typector(v)    pl_typeis(v,pl_typector_type)
// #define pl_is_TypeConstructor(v)    pl_typeis(v,pl_typector_type)
#define pl_is_typename(v)    pl_typeis(v,pl_typename_type)
#define pl_is_int32(v)       pl_typeis(v,pl_int32_type)
#define pl_is_int64(v)       pl_typeis(v,pl_int64_type)
#define pl_is_uint32(v)      pl_typeis(v,pl_uint32_type)
#define pl_is_uint64(v)      pl_typeis(v,pl_uint64_type)
#define pl_is_float32(v)     pl_typeis(v,pl_float32_type)
#define pl_is_float64(v)     pl_typeis(v,pl_float64_type)
// #define pl_is_bool(v)        pl_typeis(v,pl_bool_type)
// #define pl_is_symbol(v)      pl_typeis(v,pl_sym_type)
// #define pl_is_expr(v)        pl_typeis(v,pl_expr_type)
// #define pl_is_symbolnode(v)  pl_typeis(v,pl_symbolnode_type)
// #define pl_is_getfieldnode(v)  pl_typeis(v,pl_getfieldnode_type)
// #define pl_is_labelnode(v)   pl_typeis(v,pl_labelnode_type)
// #define pl_is_gotonode(v)    pl_typeis(v,pl_gotonode_type)
// #define pl_is_quotenode(v)   pl_typeis(v,pl_quotenode_type)
// #define pl_is_topnode(v)     pl_typeis(v,pl_topnode_type)
// #define pl_is_linenode(v)    pl_typeis(v,pl_linenumbernode_type)
// #define pl_is_lambda_info(v) pl_typeis(v,pl_lambda_info_type)
#define pl_is_module(v)      pl_typeis(v,pl_module_type)
// #define pl_is_mtable(v)      pl_typeis(v,pl_methtable_type)
#define pl_is_task(v)        pl_typeis(v,pl_task_type)
#define pl_is_func(v)        (pl_typeis(v,pl_function_type) || pl_is_struct_type(v))
#define pl_is_function(v)    pl_is_func(v)
// #define pl_is_ascii_string(v) pl_typeis(v,pl_ascii_string_type)
// #define pl_is_utf8_string(v) pl_typeis(v,pl_utf8_string_type)
// #define pl_is_byte_string(v) (pl_is_ascii_string(v) || pl_is_utf8_string(v))
// #define pl_is_cpointer(v)    pl_is_cpointer_type(pl_typeof(v))
// #define pl_is_pointer(v)     pl_is_cpointer_type(pl_typeof(v))
// #define pl_is_gf(f)          (((pl_function_t*)(f))->fptr==pl_apply_generic)


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


// modules
extern DLLEXPORT pl_module_t *pl_main_module;
extern DLLEXPORT pl_module_t *pl_core_module;
extern DLLEXPORT pl_module_t *pl_base_module;
extern DLLEXPORT pl_module_t *pl_current_module;

