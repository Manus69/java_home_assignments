#ifndef CALC_H
#define CALC_H

#include <stdbool.h>

#include "ops.h"

#define MAX_ITEM_SIZE (1 << 5)

enum REG
{
    REG_LHS,
    REG_RHS,
    REG_RSLT,
    REG_COUNT,
};

typedef struct Calc Calc;

struct Calc
{
    __attribute__((aligned(__BIGGEST_ALIGNMENT__)))
    unsigned char   regs[REG_COUNT * MAX_ITEM_SIZE];
    int             item_size;
    bool            reg_state[REG_COUNT];
};

bool Calc_reset(Calc * calc);
bool Calc_init(Calc * calc, int item_size);
bool Calc_reg_loaded(const Calc * calc, int idx);
void Calc_set_reg_state(Calc * calc, int idx, bool val);
void * Calc_reg(const Calc * calc, int idx);
void Calc_load(Calc * calc, int idx, const void * item);
bool Calc_op_bin(Calc * calc, op_binary op);
bool Calc_op_unary(Calc * calc, op_unary op);

#endif