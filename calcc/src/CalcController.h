#ifndef CALCCONTROLLER_H
#define CALCCONTROLLER_H

#include "Calc.h"
#include "IFieldOps.h"

struct CalcController
{
    Calc                calc;
    const FieldOps *    ops;
    op_unary            uop;
    op_binary           bop;
};

#endif