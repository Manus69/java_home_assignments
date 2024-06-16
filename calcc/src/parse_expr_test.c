#include "parse_expr_test.h"
#include "parse_expr.h"

#include <stdlib.h>
#include <stdio.h>

static const char * _ins[] =
{
    "9.9 + 0.9",
    "-1-1-1",
    "-1-(1-1)",
    "(1/2i - 2/4i) ^ (2 ^ 3)",
    "1/2i - 1/(2i)",
    "1.1 * 2.23 - 3(i - i)",
    "i ^ i + 1",
    "(1 + i) ^ (i - i)/ 2",
    "(1 + i) ^ ((10i - 2 *5i)/ 2)",
    "(((((i)))))",
    "((i + (-i)))",
    "1 + 2 * i - 1",
    "-2*(-2) - i",
    "0i + 0i",
    "((-1)",
    "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
    "1/0",
    "999999999999999999.999999999999999 + 0.1",
    "",
    " + 1 +",
    "i suck",
    "int main(){}",
    NULL
};

void parse_expr_test(int fd, void (* dbg)(int fd, const void *))
{
    complex z;

    for (int k = 0; ; k ++)
    {
        if (! _ins[k]) break;

        dprintf(fd, "<< %s\n", _ins[k]);
        dprintf(fd, ">> ");
        
        if (parse_expr(& z, _ins[k]))
        {
            dbg(fd, & z);
            dprintf(fd, "\n");
        }
        else dprintf(fd, "Parsing failed\n");

    }
}