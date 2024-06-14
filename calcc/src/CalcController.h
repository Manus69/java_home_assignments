#ifndef CALC_CONTROLLER_H
#define CALC_CONTROLLER_H

#include "FieldOps.h"
#include "CMD.h"

typedef struct CalcController CalcController;

CalcController *    CalcController_new(int item_size, const FieldOps * ops);
bool                CalcController_apply(CalcController * cc, CMD cmd, void * dst);
void                CalcController_del(CalcController * cc);

#endif