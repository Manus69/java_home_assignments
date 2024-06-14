#include "im_ops.h"

#include <complex.h>

bool im_id(void * dst, const void * x)
{
    * (complex *) dst = * (complex *) x;

    return true;
}

bool im_inva(void * dst, const void * x)
{
    * (complex *) dst = - (* (complex *) x);

    return true;
}

bool im_invm(void * dst, const void * x)
{
    if (* (complex *) x == 0) return false;

    * (complex *) dst = 1 / (* (complex *) x);

    return true;
}

bool im_add(void * dst, const void * x, const void * y)
{
    * (complex *) dst = * (complex *) x + * (complex *) y;

    return true;
}

bool im_mult(void * dst, const void * x, const void * y)
{
    * (complex *) dst = * (complex *) x * (* (complex *) y);

    return true;
}

bool im_subt(void * dst, const void * x, const void * y)
{
    * (complex *) dst = * (complex *) x - * (complex *) y;

    return true;
}

bool im_div(void * dst, const void * x, const void * y)
{
    if (* (complex *) y == 0) return false;

    * (complex *) dst = * (complex *) x / (* (complex *) y);

    return true;
}

const FieldOps im_ops = 
{
    .id = im_id,
    .inva = im_inva,
    .invm = im_invm,
    .add = im_add,
    .mult = im_mult,
    .subt = im_subt,
    .div = im_subt,
};
