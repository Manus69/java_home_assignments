#ifndef IFIELDOPS_H
#define IFIELDOPS_H

#include <stdbool.h>

typedef bool (* op_unary)(void *, const void *);
typedef bool (* op_binary)(void *, const void *, const void *);

typedef struct FieldOps FieldOps;

struct FieldOps
{
    bool (* id)(void *, const void *);
    bool (* inva)(void *, const void *);
    bool (* invm)(void *, const void *);
    bool (* add)(void *, const void *, const void *);
    bool (* mult)(void *, const void *, const void *);
    bool (* subt)(void *, const void *, const void *);
    bool (* div)(void *, const void *, const void *);
};

#endif