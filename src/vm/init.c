#include "pylia.h"

// #if defined(__linux__)
// #define _GNU_SOURCE 1
// #include <sched.h>   // for setting CPU affinity
// #endif

pl_value_t *pl_true;
pl_value_t *pl_false;

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

pl_struct_type_t *pl_function_type;
pl_struct_type_t *pl_bits_kind;


pl_value_t *pl_memory_exception;

void pylia_init() {

// #if defined(__linux__)
//     int ncores = pl_cpu_cores();
//     if (ncores > 1) {
//         cpu_set_t cpumask;
//         CPU_ZERO(&cpumask);
//         for(int i=0; i < ncores; i++) {
//             CPU_SET(i, &cpumask);
//         }
//         sched_setaffinity(0, sizeof(cpu_set_t), &cpumask);
//     }
// #endif
    // init gc
    pl_gc_init();
    pl_init_types();
}