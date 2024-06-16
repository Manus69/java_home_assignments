#include "IProgram.h"
#include "Program.h"
#include "io.h"

#include <stdlib.h>
#include <complex.h>
#include <string.h>

#define QUIT_STR        "Q"
#define MSG_ERR_INST    "Instantiation error"
#define MSG_ERR_INPUTC  "Critical input error"
#define MSG_ERR_INPUT   "Invalid input"
#define MSG_HELP        "Enter an expression to evaluate or '" QUIT_STR "' to quit"

static int _error(const Program * pr, const char * msg)
{
    Logger_log_msg(& pr->logger, msg);

    return 1;
}

Program * Program_start(InputController * ic, bool (* parsef)(void *, const char *), Logger logger)
{
    Program * pr;

    if (! (pr = calloc(1, sizeof(* pr)))) return NULL;

    pr->ic = ic;
    pr->logger = logger;
    pr->parse = parsef;
    
    return pr;
}

int Program_run(Program * program)
{
    char *  cstr;
    complex z;

    while (true)
    {
        Logger_log_msg(& program->logger, "<< ");

        if (! (cstr = InputController_get_input(program->ic)))  return _error(program, MSG_ERR_INPUTC);
        if (strcmp(cstr, QUIT_STR) == 0)                        return 0;

        Logger_log_msg(& program->logger, ">> ");
        if (program->parse(& z, cstr))
        {
            Logger_log_val(& program->logger, & z);
        }
        else
        {
            Logger_log_msg(& program->logger, MSG_ERR_INPUT);
            Logger_log_msg(& program->logger, MSG_HELP);
        }
    }
}

void Program_stop(Program * program)
{
    free(program);
}
