#ifndef PROGRAM_H
#define PROGRAM_H

#include "IInputController.h"
#include "Logger.h"

#include <stdbool.h>

struct Program
{
    InputController *   ic;
    Logger              logger;
    bool                (* parse)(void *, const char *);
};

#endif