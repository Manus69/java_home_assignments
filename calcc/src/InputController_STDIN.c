#include "InputController.h"

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

struct InputController
{
    char *  buffer;
    int     size;
};

InputController * InputController_new(char * buffer, int size)
{
    InputController * ic;

    if ((ic = malloc(sizeof(* ic))))
    {
        ic->buffer = buffer;
        ic->size = size;

        return ic;
    }

    return NULL;
}

char * InputController_get_input(InputController * ic)
{
    memset(ic->buffer, 0, ic->size);

    return fgets(ic->buffer, ic->size, stdin);
}

void InputController_del(InputController * ic)
{
    free(ic);
}