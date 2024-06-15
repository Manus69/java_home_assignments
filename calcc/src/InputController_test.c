#include "InputController.h"
#include "IInputController.h"
#include <stdlib.h>

#ifdef TEST

#define RUN 1

#if RUN == 0
static const char * _input[] =
{
    "1.0 + i",
    "+",
    "1",
    "-",
    "2 + i",
    NULL,
};
#endif

#if RUN == 1
static const char * _input[] =
{
    "1 + 1",
    "+",
    "0",
    NULL
};
#endif

static InputController _ic = (InputController) {};

InputController * InputController_new(char * buffer, int size)
{
    (void) buffer;
    (void) size;

    return & _ic;
}

char * InputController_get_input(InputController * ic)
{
    (void) ic;

    static int idx = 0;

    return (char *) _input[idx ++];
}

void InputController_del(InputController * ic)
{
    (void) ic;
}

#endif