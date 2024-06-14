#ifndef OPS_H
#define OPS_H

#include <stdbool.h>

typedef bool (* op_unary)(void *, const void *);
typedef bool (* op_binary)(void *, const void *, const void *);

#endif