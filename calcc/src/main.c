
#include "IInputController.h"
#include "ICalcController.h"
#include "im_ops.h"
#include "parse_CMD.h"
#include "parse_im.h"

#include <stdio.h>
#include <complex.h>

#define MSG_ERR_INST    "Instantiation error"
#define MSG_ERR_INPUTC  "Critical input error"
#define MSG_ERR_INPUT   "Invalid input"
#define MSG_ERR_OP      "Op failed"
#define MSG_ERR_CMD     "Unexpected command"
#define MSG_ERR_CMDE    "Command expected"
#define MSG_HELP        "Fuck you"
#define BUFF_SIZE       (1 << 6)

static int _error(const char * cstr)
{
    fprintf(stderr, "%s\n", cstr);

    return 1;
}

void dbg_complex(complex * x)
{
    printf("(%.2f , %.2fi)\n", creal(* x), cimag(* x));
}

static int _run(InputController * ic, CalcController * cc)
{
    char *  cstr;
    CMD     cmd;
    complex z;

    while (true)
    {
        if (! (cstr = InputController_get_input(ic))) return _error(MSG_ERR_INPUTC);

        if (parse_CMD(& cmd, cstr))
        {
            if (cmd == CMD_QUIT) return 0;
            if (! CalcController_process_cmd(cc, cmd)) _error(MSG_ERR_CMD);
        }
        else if (parse_im(& z, cstr))
        {
            if (! CalcController_load(cc, & z)) _error(MSG_ERR_CMDE);
        }
        else
        {
            _error(MSG_HELP);
            continue;
        }

        if (CalcController_computation_ready(cc))
        {
            CalcController_compute(cc, & z);
            dbg_complex(& z);
        }
    }
}

static const char * _ins[] =
{
    "(1/2i - 2/4i) ^ (2 ^ 3)",
    "1/2i - 1/(2i)",
    "i ^ i + 1",
    "(1 + i) ^ (i - i)/ 2",
    "(1 + i) ^ ((10i - 2 *5i)/ 2)",
    "(((((i)))))",
    "((i + (-i)))",
    "1 + 2 * i - 1",
    "-2*(-2) - i",
    "",
    "Eat a dick + 1",
    "i + cock",
    NULL
};

bool parse_expr(complex * z, const char * cstr);

static inline void _test_parse_expr()
{
    complex z;

    for (int k = 0; ; k ++)
    {
        if (! _ins[k]) break;

        printf("<< %s\n", _ins[k]);
        printf(">> ");
        if (parse_expr(& z, _ins[k]))
        {
            dbg_complex(& z);
            printf("\n");
        }
        else printf("Parsing failed\n\n");

    }
}

int main()
{
    _test_parse_expr();
}

// int main()
// {
//     char                buff[BUFF_SIZE];
//     InputController *   ic;
//     CalcController *    cc;
//     int                 status;

//     if (! (ic = InputController_new(buff, BUFF_SIZE)))          return _error(MSG_ERR_INST);
//     if (! (cc = CalcController_new(sizeof(complex), & im_ops))) return _error(MSG_ERR_INST);

//     status = _run(ic, cc);

//     InputController_del(ic);
//     CalcController_del(cc);

//     return status;
// }
