#include "Calc.h"

#include <string.h>

bool Calc_reset(Calc * calc)
{
    int item_size;

    item_size = calc->item_size;
    memset(calc, 0, sizeof(* calc));

    calc->item_size = item_size;
    
    return true;
}

bool Calc_init(Calc * calc, int item_size)
{
    if (item_size > MAX_ITEM_SIZE) return false;

    memset(calc, 0, sizeof(Calc));
    calc->item_size = item_size;

    return true;
}

bool Calc_reg_loaded(const Calc * calc, int idx)
{
    return calc->reg_state[idx];
}

void Calc_set_reg_state(Calc * calc, int idx, bool val)
{
    calc->reg_state[idx] = val;
}

void * Calc_reg(const Calc * calc, int idx)
{
    return (void *) calc->regs + idx * calc->item_size;
}

bool Calc_load(Calc * calc, int idx, const void * item)
{
    memcpy(Calc_reg(calc, idx), item, calc->item_size);
    Calc_set_reg_state(calc, idx, true);

    return true;
}

bool Calc_op_bin(Calc * calc, op_binary op)
{
    if (Calc_reg_loaded(calc, REG_LHS) && Calc_reg_loaded(calc, REG_RHS))
    {
        if (op(Calc_reg(calc, REG_LHS), Calc_reg(calc, REG_LHS), Calc_reg(calc, REG_RHS)))
        {
            Calc_set_reg_state(calc, REG_RHS, false);

            return true;
        }
    }

    return false;
}

bool Calc_op_unary(Calc * calc, op_unary op)
{
    if (Calc_reg_loaded(calc, REG_LHS) && ! Calc_reg_loaded(calc, REG_RHS))
    {
        return op(Calc_reg(calc, REG_LHS), Calc_reg(calc, REG_LHS));
    }

    return false;
}
