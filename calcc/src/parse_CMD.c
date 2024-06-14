#include "parse_CMD.h"

#include <string.h>

static const char * _CMD_table[] =
{
    "Q""\n",
    "C""\n",
    "+""\n",
    "*""\n",
    "-""\n",
    "/""\n",
    "inv""\n",
};

CMD CMD_parse(const char * cstr)
{
    for (int k = 0; k < CMD_UNKNOWN; k ++)
    {
        if (strcmp(_CMD_table[k], cstr) == 0) return k;
    }

    return CMD_UNKNOWN;
}