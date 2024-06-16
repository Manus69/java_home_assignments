#ifndef IPROGRAM_H
#define IPROGRAM_H

#include "Logger.h"
#include "IInputController.h"

#include <stdbool.h>

typedef struct Program Program;

Program *   Program_start(InputController * ic, bool (* parsef)(void *, const char *), Logger logger);
int         Program_run(Program * program);
void        Program_stop(Program * program);


#endif