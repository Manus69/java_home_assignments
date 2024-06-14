#ifndef INPUTCONTROLLER_H
#define INPUTCONTROLLER_H

typedef struct InputController InputController;

InputController *   InputController_new(char * buffer, int size);
char *              InputController_get_input(InputController * ic);
void                InputController_del(InputController * ic);

#endif