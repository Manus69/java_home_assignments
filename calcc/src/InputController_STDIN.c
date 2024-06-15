#include "IInputController.h"
#include "InputController.h"

#ifndef TEST

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

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
    char *  cstr;
    int     len;

    memset(ic->buffer, 0, ic->size);

    cstr = fgets(ic->buffer, ic->size, stdin);
    len = strlen(cstr);

    if (len && cstr[len - 1] == '\n') cstr[len - 1] = '\0';

    return cstr;
}

void InputController_del(InputController * ic)
{
    free(ic);
}

#endif