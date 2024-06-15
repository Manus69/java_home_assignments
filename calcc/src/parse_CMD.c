#include "parse_CMD.h"

#include <string.h>

static const char * _CMD_table[] =
{
    "Q",
    "C",
    "+",
    "*",
    "-",
    "/",
    "inv",
};

bool parse_CMD(CMD * cmd, const char * cstr)
{
    for (int k = 0; k < CMD_UNKNOWN; k ++)
    {
        if (strcmp(_CMD_table[k], cstr) == 0)
        {
            * cmd = k;

            return true;
        }
    }

    return false;
}