#ifndef FIELD_OPS_H
#define FIELD_OPS_H

#include <stdbool.h>

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