#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <string.h>

#include "Calc.h"
#include "im_ops.h"
#include "parse_im.h"
#include "parse_CMD.h"
#include "InputController.h"

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
#define MSG_ERR_INPUT   "Input error"
#define MSG_HELP        "Fuck you"
#define BUFF_SIZE       (1 << 6)

int main()
{
    InputController *   ic;
    char                buff[BUFF_SIZE];
    char *              cstr;
    complex             z;
    CMD                 cmd;

    if (! (ic = InputController_new(buff, BUFF_SIZE))) return error(MSG_ERR_INST);

    while (true)
    {
        if (! (cstr = InputController_get_input(ic))) return error(MSG_ERR_INPUT);

        printf("'%s', %d\n", cstr, strlen(cstr));

        cmd = parse_CMD(cstr);
        if (cmd == CMD_QUIT) break;

        
        if (parse_im(& z, cstr)) dbg_complex(& z);
    }

    InputController_del(ic);
    return 0;
}