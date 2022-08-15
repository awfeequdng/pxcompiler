#include "pylia.h"
#include "newobj_internal.h"

#include "utils.h"

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>


pl_sym_t *call_sym;    pl_sym_t *dots_sym;
pl_sym_t *call1_sym;   pl_sym_t *module_sym;
pl_sym_t *export_sym;  pl_sym_t *import_sym;
pl_sym_t *importall_sym; pl_sym_t *toplevel_sym;
pl_sym_t *quote_sym;   pl_sym_t *amp_sym;
pl_sym_t *top_sym;     pl_sym_t *colons_sym;
pl_sym_t *line_sym;    pl_sym_t *continue_sym;
// head symbols for each expression type
pl_sym_t *goto_sym;    pl_sym_t *goto_ifnot_sym;
pl_sym_t *label_sym;   pl_sym_t *return_sym;
pl_sym_t *lambda_sym;  pl_sym_t *assign_sym;
pl_sym_t *null_sym;    pl_sym_t *body_sym;
pl_sym_t *macro_sym;   pl_sym_t *method_sym;
pl_sym_t *enter_sym;   pl_sym_t *leave_sym;
pl_sym_t *exc_sym;     pl_sym_t *error_sym;
pl_sym_t *static_typeof_sym;
pl_sym_t *new_sym;     pl_sym_t *using_sym;
pl_sym_t *const_sym;   pl_sym_t *thunk_sym;
pl_sym_t *anonymous_sym;  pl_sym_t *underscore_sym;
pl_sym_t *abstracttype_sym; pl_sym_t *bitstype_sym;
pl_sym_t *compositetype_sym; pl_sym_t *type_goto_sym;
pl_sym_t *global_sym; pl_sym_t *tuple_sym;

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



// symbols --------------------------------------------------------------------

static pl_sym_t *symtab = NULL;

extern int64_t memhash(const char* buf, size_t n);
static pl_sym_t *mk_symbol(const char *str)
{
    pl_sym_t *sym;
    size_t len = strlen(str);

    sym = (pl_sym_t*)malloc((sizeof(pl_sym_t)-sizeof(void*)+len+1+7)&-8);
    sym->type = (pl_type_t*)pl_sym_type;
    sym->left = sym->right = NULL;
#ifdef __LP64__
    sym->hash = memhash(str, len)^0xAAAAAAAAAAAAAAAAL;
#else
    sym->hash = memhash32(str, len)^0xAAAAAAAA;
#endif
    strcpy(&sym->name[0], str);
    return sym;
}

static void unmark_symbols_(pl_sym_t *root)
{
    while (root != NULL) {
        root->type = (pl_type_t*)(((uptrint_t)root->type)&~1UL);
        unmark_symbols_(root->left);
        root = root->right;
    }
}

void pl_unmark_symbols(void) {
    unmark_symbols_(symtab);
}

static pl_sym_t **symtab_lookup(pl_sym_t **ptree, const char *str)
{
    int x;

    while(*ptree != NULL) {
        x = strcmp(str, (*ptree)->name);
        if (x == 0)
            return ptree;
        if (x < 0)
            ptree = &(*ptree)->left;
        else
            ptree = &(*ptree)->right;
    }
    return ptree;
}

pl_sym_t *pl_symbol(const char *str) {
    pl_sym_t **pnode;
    pnode = symtab_lookup(&symtab, str);
    if (*pnode == NULL) {
        *pnode = mk_symbol(str);
    }
    return *pnode;
}


DLLEXPORT pl_sym_t *pl_symbol_n(const char *str, int32_t len)
{
    char name[len+1];
    memcpy(name, str, len);
    name[len] = '\0';
    return pl_symbol(name);
}

DLLEXPORT pl_sym_t *pl_get_root_symbol() { return symtab; }


static uint32_t gs_ctr = 0;  // TODO: per-thread
uint32_t pl_get_gs_ctr(void) { return gs_ctr; }
void pl_set_gs_ctr(uint32_t ctr) { gs_ctr = ctr; }

DLLEXPORT pl_sym_t *pl_gensym(void)
{
    static char name[16];
    char *n;
    n = uint2str(&name[2], sizeof(name)-2, gs_ctr, 10);
    *(--n) = '#'; *(--n) = '#';
    gs_ctr++;
    return pl_symbol(n);
}

DLLEXPORT pl_sym_t *pl_tagged_gensym(const char* str, int32_t len)
{
    static char gs_name[14];
    char name[sizeof(gs_name)+len+3];
    char *n;
    name[0] = '#'; name[1] = '#'; name[2+len] = '#';
    memcpy(name+2, str, len);
    n = uint2str(gs_name, sizeof(gs_name), gs_ctr, 10);
    memcpy(name+3+len, n, sizeof(gs_name)-(n-gs_name));
    gs_ctr++;
    return pl_symbol(name);
}

// allocating types -----------------------------------------------------------

pl_typename_t *pl_new_typename(pl_sym_t *name)
{
    pl_typename_t *tn=(pl_typename_t*)newobj((pl_type_t*)pl_typename_type, 4);
    tn->name = name;
    tn->module = pl_current_module;
    tn->primary = NULL;
    tn->cache = (pl_value_t*)pl_null;
    return tn;
}


pl_tag_type_t *pl_new_tagtype(pl_value_t *name, pl_tag_type_t *super,
                              pl_tuple_t *parameters)
{
    pl_typename_t *tn=NULL;
    PL_GC_PUSH(&tn);

    if (pl_is_typename(name))
        tn = (pl_typename_t*)name;
    else
        tn = pl_new_typename((pl_sym_t*)name);
    pl_tag_type_t *t = (pl_tag_type_t*)newobj((pl_type_t*)pl_tag_kind,
                                              TAG_TYPE_NW);
    t->name = tn;
    t->super = super;
    t->parameters = parameters;
    t->fptr = NULL;
    t->env = NULL;
    t->linfo = NULL;
    if (t->name->primary == NULL)
        t->name->primary = (pl_value_t*)t;
    PL_GC_POP();
    return t;
}
