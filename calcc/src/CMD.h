#ifndef CMD_H
#define CMD_H

#include <stdbool.h>

typedef enum CMD CMD;

enum CMD
{
    CMD_QUIT,
    CMD_C,
    CMD_ADD,
    CMD_MULT,
    CMD_SUBT,
    CMD_DIV,
    CMD_INV,
    CMD_UNKNOWN,
};

static inline bool CMD_is_biary(CMD cmd)
{
    return  cmd == CMD_ADD ||
            cmd == CMD_SUBT ||
            cmd == CMD_MULT ||
            cmd == CMD_DIV;
}

static inline bool CMD_is_unary(CMD cmd)
{
    return  cmd == CMD_INV;
}

#endif