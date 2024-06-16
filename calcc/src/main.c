
#include "IInputController.h"
#include "IProgram.h"
#include "io.h"
#include "parse_expr.h"

#include <unistd.h>

#ifndef TEST
#define MSG_INSTC "Critical alloc falure"
#define BUFF_SIZE (1 << 6)

int main()
{
    char                buffer[BUFF_SIZE];
    Program *           program;
    InputController *   ic;
    int                 status;
    Logger              logger;

    logger = Logger_init(STDOUT_FILENO, io_msg, io_pprint_complex);

    if (! (ic = InputController_new(buffer, BUFF_SIZE)))        return io_error(MSG_INSTC);
    if (! (program = Program_start(ic, parse_expr, logger)))    return io_error(MSG_INSTC);

    status = Program_run(program);

    InputController_del(ic);
    Program_stop(program);

    return status;
}

#endif

#ifdef TEST
#include "parse_expr_test.h"

int main()
{
    parse_expr_test(STDOUT_FILENO, io_pprint_complex);
}

#endif