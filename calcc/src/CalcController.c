#include "ICalcController.h"
#include "CalcController.h"
#include "Calc.h"

#include <stdlib.h>

CalcController * CalcController_new(int item_size, const FieldOps * ops)
{
    CalcController *    cc;
    Calc                calc;

    if (! Calc_init(& calc, item_size))     return NULL;
    if (! (cc = calloc(1, sizeof(* cc))))   return NULL;

    cc->calc = calc;
    cc->ops = ops;

    return cc;
}

bool CalcController_load(CalcController * cc, const void * item)
{
    if (! Calc_reg_loaded(& cc->calc, REG_LHS))             return Calc_load(& cc->calc, REG_LHS, item);
    if (! Calc_reg_loaded(& cc->calc, REG_RHS) && cc->bop)  return Calc_load(& cc->calc, REG_RHS, item);

    return false;
}

bool CalcController_reset(CalcController * cc)
{
    cc->bop = NULL;
    cc->uop = NULL;

    return Calc_reset(& cc->calc);
}

bool CalcController_op_ready(const CalcController * cc)
{
    return cc->uop || cc->bop;
}

bool CalcController_computation_ready(const CalcController * cc)
{
    return  (cc->uop && Calc_reg_loaded(& cc->calc, REG_LHS)) ||
            (cc->bop && Calc_reg_loaded(& cc->calc, REG_LHS) && Calc_reg_loaded(& cc->calc, REG_RHS));
}

static bool _set_uop(CalcController * cc, CMD cmd)
{
    if (cmd == CMD_INV) cc->uop = cc->ops->invm;
    else return false;

    return true;
}

static bool _set_bop(CalcController * cc, CMD cmd)
{
    if      (cmd == CMD_ADD)    cc->bop = cc->ops->add;
    else if (cmd == CMD_MULT)   cc->bop = cc->ops->mult;
    else if (cmd == CMD_SUBT)   cc->bop = cc->ops->subt;
    else if (cmd == CMD_DIV)    cc->bop = cc->ops->div;
    else return false;

    return true;
}

bool CalcController_process_cmd(CalcController * cc, CMD cmd)
{
    if (cmd == CMD_UNKNOWN)                     return false;
    if (cmd == CMD_C)                           return CalcController_reset(cc);
    if (CalcController_op_ready(cc))            return false;
    if (! Calc_reg_loaded(& cc->calc, REG_LHS)) return false;
    if (CMD_is_biary(cmd))                      return _set_bop(cc, cmd);
    if (CMD_is_unary(cmd))                      return _set_uop(cc, cmd);

    return false;
}

bool CalcController_compute(CalcController * cc, void * dst)
{
    if (CalcController_computation_ready(cc))
    {
        if      (cc->uop) Calc_op_unary(& cc->calc, cc->uop);
        else if (cc->bop) Calc_op_bin(& cc->calc, cc->bop);

        cc->ops->id(dst, Calc_reg(& cc->calc, REG_LHS));
        
        cc->bop = NULL;
        cc->uop = NULL;

        return true;
    }

    return false;
}

void CalcController_del(CalcController * cc)
{
    free(cc);
}