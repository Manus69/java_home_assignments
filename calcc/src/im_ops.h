#ifndef IM_OPS_H
#define IM_OPS_H

#include "IFieldOps.h"

bool im_id(void * dst, const void * x);
bool im_inva(void * dst, const void * x);
bool im_invm(void * dst, const void * x);
bool im_add(void * dst, const void * x, const void * y);
bool im_mult(void * dst, const void * x, const void * y);
bool im_subt(void * dst, const void * x, const void * y);
bool im_div(void * dst, const void * x, const void * y);

extern const FieldOps im_ops;

#endif