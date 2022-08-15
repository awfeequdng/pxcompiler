#pragma once
#include "gc.h"
static inline pl_value_t *newobj(pl_type_t *type, size_t nfields)
{
    pl_value_t *jv = (pl_value_t*)allocobj((1+nfields) * sizeof(void*));
    jv->type = type;
    return jv;
}

static inline pl_value_t *newstruct(pl_struct_type_t *type)
{
    pl_value_t *pv = (pl_value_t*)allocobj(sizeof(void*) + type->size);
    pv->type = (pl_type_t*)type;
    return pv;
}

#define TAG_TYPE_NW (NWORDS(sizeof(pl_tag_type_t))-1)
#define BITS_TYPE_NW (NWORDS(sizeof(pl_bits_type_t))-1)
