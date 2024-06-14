#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

#include "Calc.h"
#include "im_ops.h"
#include "parse_im.h"
#include "parse_CMD.h"
#include "InputController.h"
#include "CalcController.h"

int error(const char * cstr)
{
    fprintf(stderr, "%s\n", cstr);

    return 1;
}

void dbg_complex(complex * x)
{
    printf("%.2f %.2f\n", creal(* x), cimag(* x));
}

void _parse_test()
{
    complex x;

    if (parse_im(& x, "+1.1")) dbg_complex(& x);
    if (parse_im(& x, " -1")) dbg_complex(& x);
    if (parse_im(& x, " ")) dbg_complex(& x);
    if (parse_im(& x, "3i")) dbg_complex(& x);
    if (parse_im(& x, " -3.14 -17.9i")) dbg_complex(& x);
    if (parse_im(& x, "1 + i")) dbg_complex(& x);
}

void _calc_test()
{
    Calc calc;

    Calc_init(& calc, sizeof(complex));
    complex x;
    complex z0 = -1 + I;
    complex z1 = -1;

    dbg_complex(& z0);
    dbg_complex(& z1);

    // x = z0 * z1;
    // im_mult(& x, & z0, & z1);
    // dbg_complex(& x);
    Calc_load(& calc, 0, & z0);
    Calc_load(& calc, 1, & z1);

    Calc_op_bin(& calc, im_mult);
    x = * (complex *) Calc_reg(& calc, 0);

    dbg_complex(& x);
    // printf("%f %f\n", creal(x), cimag(x));
    // printf("%f\n", creal(z0));
    // printf("%f", creal(z1));
}

#define MSG_ERR_INST    "Instantiation error"
#define MSG_ERR_INPUTC  "Critical input error"
#define MSG_ERR_INPUT   "Invalid input"
#define MSG_ERR_OP      "Op failed"
#define MSG_HELP        "Fuck you"
#define BUFF_SIZE       (1 << 6)

static int _run(InputController * ic, CalcController * cc)
{
    char *  cstr;
    CMD     cmd;
    complex z;

    while (true)
    {
        if (! (cstr = InputController_get_input(ic))) return error(MSG_ERR_INPUTC);

        cmd = parse_CMD(cstr);
        if (cmd == CMD_UNKNOWN) error(MSG_ERR_INPUT);
    }

    return 0;
}


int main()
{
    char                buff[BUFF_SIZE];
    InputController *   ic;
    CalcController *    cc;
    int                 status;

    if (! (ic = InputController_new(buff, BUFF_SIZE)))          return error(MSG_ERR_INST);
    if (! (cc = CalcController_new(sizeof(complex), & im_ops))) return error(MSG_ERR_INST);

    status = _run(ic, cc);

    InputController_del(ic);
    CalcController_del(cc);

    return status;
}