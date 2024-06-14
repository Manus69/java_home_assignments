#include "CalcController.h"
#include "Calc.h"

#include <stdlib.h>

struct CalcController
{
    Calc                calc;
    const FieldOps *    ops;
};

CalcController * CalcController_new(int item_size, const FieldOps * ops)
{
    CalcController *    cc;
    Calc                calc;

    if (! Calc_init(& calc, item_size)) return NULL;
    if (! (cc = malloc(sizeof(* cc))))  return NULL;

    cc->calc = calc;
    cc->ops = ops;

    return cc;
}

void CalcController_load(CalcController * cc, const void * src)
{
    
}

bool CalcController_apply(CalcController * cc, CMD cmd, void * dst)
{
    if (cmd == CMD_UNKNOWN) return false;
    if (cmd == CMD_C)       return Calc_reset(& cc->calc);
    if (cmd == CMD_INV)     return Calc_op_unary(& cc->calc, cc->ops->invm);
    if (cmd == CMD_ADD)     return Calc_op_bin(& cc->calc, cc->ops->add);
    if (cmd == CMD_MULT)    return Calc_op_bin(& cc->calc, cc->ops->mult);
    if (cmd == CMD_SUBT)    return Calc_op_bin(& cc->calc, cc->ops->subt);
    if (cmd == CMD_DIV)     return Calc_op_bin(& cc->calc, cc->ops->div);

    return false;
}

void CalcController_del(CalcController * cc)
{
    free(cc);
}