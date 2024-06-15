#ifndef ICALC_CONTROLLER_H
#define ICALC_CONTROLLER_H

#include "IFieldOps.h"
#include "CMD.h"

typedef struct CalcController CalcController;

CalcController *    CalcController_new(int item_size, const FieldOps * ops);
bool                CalcController_load(CalcController * cc, const void * item);
bool                CalcController_process_cmd(CalcController * cc, CMD cmd);
bool                CalcController_computation_ready(const CalcController * cc);
bool                CalcController_compute(CalcController * cc, void * dst);
void                CalcController_del(CalcController * cc);

#endif