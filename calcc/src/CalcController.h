#ifndef CALC_CONTROLLER_H
#define CALC_CONTROLLER_H

#include "FieldOps.h"
#include "CMD.h"

typedef struct CalcController CalcController;

CalcController *    CalcController_new(int item_size, const FieldOps * ops);
void                CalcController_load(CalcController * cc, const void * item);
bool                CalcController_compute(CalcController * cc, void * dst);
void                CalcController_del(CalcController * cc);

#endif