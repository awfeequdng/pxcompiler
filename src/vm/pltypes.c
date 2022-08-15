
#include "pylia.h"
#include "gc.h"
#include "newobj_internal.h"

pl_tag_type_t *pl_any_type;
pl_tag_type_t *pl_type_type;
pl_struct_type_t *pl_typename_type;
pl_struct_type_t *pl_sym_type;
pl_struct_type_t *pl_symbol_type;
pl_tuple_t *pl_tuple_type;

pl_struct_type_t *pl_union_kind;
pl_struct_type_t *pl_tag_kind;
pl_struct_type_t *pl_tag_type_type;
pl_struct_type_t *pl_struct_kind;
pl_struct_type_t *pl_bits_kind;


pl_bits_type_t *pl_bool_type;
pl_bits_type_t *pl_char_type;
pl_bits_type_t *pl_int8_type;
pl_bits_type_t *pl_uint8_type;
pl_bits_type_t *pl_int16_type;
pl_bits_type_t *pl_uint16_type;
pl_bits_type_t *pl_int32_type;
pl_bits_type_t *pl_uint32_type;
pl_bits_type_t *pl_int64_type;
pl_bits_type_t *pl_uint64_type;
pl_bits_type_t *pl_float32_type;
pl_bits_type_t *pl_float64_type;
pl_struct_type_t *pl_weakref_type;

pl_value_t *pl_nothing;
pl_tuple_t *pl_null;


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
    pl_tuple_type->type = (pl_type_t*)pl_tuple_type;

    pl_null = (pl_tuple_t*)newobj((pl_type_t*)pl_tuple_type, 1);
    pl_tuple_set_len_unsafe(pl_null, 0);
    pl_nothing = (pl_value_t*)pl_null;


    pl_tag_kind = pl_new_uninitialized_struct_type(6);
    pl_tag_type_type = pl_tag_kind;

    pl_any_type = pl_new_tagtype((pl_value_t*)pl_symbol("Any"), NULL, pl_null);


    call_sym = pl_symbol("call");
    call1_sym = pl_symbol("call1");
    quote_sym = pl_symbol("quote");
    top_sym = pl_symbol("top");
    dots_sym = pl_symbol("Vararg");
    line_sym = pl_symbol("line");
    continue_sym = pl_symbol("continue");
    error_sym = pl_symbol("error");
    goto_sym = pl_symbol("goto");
    goto_ifnot_sym = pl_symbol("gotoifnot");
    label_sym = pl_symbol("label");
    return_sym = pl_symbol("return");
    lambda_sym = pl_symbol("lambda");
    macro_sym = pl_symbol("macro");
    module_sym = pl_symbol("module");
    export_sym = pl_symbol("export");
    import_sym = pl_symbol("import");
    using_sym = pl_symbol("using");
    importall_sym = pl_symbol("importall");
    assign_sym = pl_symbol("=");
    null_sym = pl_symbol("null");
    body_sym = pl_symbol("body");
    colons_sym = pl_symbol("::");
    method_sym = pl_symbol("method");
    exc_sym = pl_symbol("the_exception");
    enter_sym = pl_symbol("enter");
    leave_sym = pl_symbol("leave");
    static_typeof_sym = pl_symbol("static_typeof");
    new_sym = pl_symbol("new");
    const_sym = pl_symbol("const");
    global_sym = pl_symbol("global");
    thunk_sym = pl_symbol("thunk");
    anonymous_sym = pl_symbol("anonymous");
    underscore_sym = pl_symbol("_");
    amp_sym = pl_symbol("&");
    abstracttype_sym = pl_symbol("abstract_type");
    bitstype_sym = pl_symbol("bits_type");
    compositetype_sym = pl_symbol("composite_type");
    type_goto_sym = pl_symbol("type_goto");
    toplevel_sym = pl_symbol("toplevel");
    tuple_sym = pl_symbol("tuple");
}