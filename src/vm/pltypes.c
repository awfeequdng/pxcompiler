
#include "pylia.h"
#include "gc.h"
#include "newobj_internal.h"
pl_struct_type_t *pl_typename_type;
pl_struct_type_t *pl_sym_type;
pl_struct_type_t *pl_symbol_type;
pl_struct_type_t *pl_struct_kind;
pl_tuple_t *pl_tuple_type;

pl_struct_type_t *pl_new_uninitialized_struct_type(size_t nfields)
{
    return (pl_struct_type_t*)
        newobj((pl_type_t*)pl_struct_kind,
               NWORDS(sizeof(pl_struct_type_t) - sizeof(void*) +
                      (nfields-1)*sizeof(pl_fielddesc_t)));
}


void pl_init_types(void) {
   // create base objects
    pl_struct_kind = pl_new_uninitialized_struct_type(10);
    pl_struct_kind->type = (pl_type_t*)pl_struct_kind;

    pl_typename_type = pl_new_uninitialized_struct_type(4);
    pl_sym_type = pl_new_uninitialized_struct_type(0);
    pl_symbol_type = pl_sym_type;

    pl_tuple_type = pl_alloc_tuple(1);


}