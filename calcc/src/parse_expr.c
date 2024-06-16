#include <complex.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

enum SYMBOL
{
    EYE =       'i',
    MINUS =     '-',
    PLUS =      '+',
    MULT =      '*',
    DIV =       '/',
    HAT =       '^',
    PARENO =    '(',
    PARENC =    ')',
};

static int  _expr(complex * z, const char * cstr);
static int  _term(complex * z, const char * cstr);

static bool _remove_space(const char * restrict cstr, char * restrict buff, int max_len)
{
    int k;

    k = 0;
    while (* cstr && k < max_len)
    {
        if (* cstr != ' ') buff[k ++] = * cstr;

        cstr ++;
    }

    if (k == max_len) return false;

    return true;
}

static int _re(complex * z, const char * cstr)
{
    double val;
    char * ptr;

    val = strtod(cstr, & ptr);
    if (cstr == ptr) return 0;

    * z = val;
    return ptr - cstr;
} 

static int _val(complex * z, const char * cstr)
{
    int len;

    if (* cstr == EYE)
    {
        * z = I;
        return 1;
    }

    if ((len = _re(z, cstr)) <= 0) return len;
    if (cstr[len] == EYE)
    {
        * z *= I;
        len ++;
    }

    return len;
}

static int _base(complex * z, const char * cstr)
{
    int len;

    if (* cstr == PARENO)
    {
        if ((len = _expr(z, cstr + 1)) <= 0) return len;
        if (cstr[len + 1] != PARENC) return -1;

        return len + 2;
    }

    if (* cstr == MINUS)
    {
        if ((len = _term(z, cstr + 1)) <= 0) return len;

        * z = - * z;

        return len + 1;
    }

    return _val(z, cstr);
}

static int _factor(complex * z, const char * cstr)
{
    complex base, power;
    int     len_lhs, len_rhs;

    if ((len_lhs = _base(& base, cstr)) <= 0) return len_lhs;
    cstr += len_lhs;

    if (* cstr == HAT)
    {
        if ((len_rhs = _factor(& power, cstr + 1)) <= 0) return len_rhs;
        * z = cpow(base, power);

        return len_lhs + len_rhs + 1;
    }

    * z = base;

    return len_lhs;
}

static int _term(complex * z, const char * cstr)
{
    complex lhs, rhs;
    int     len_lhs, len_rhs;

    if ((len_lhs = _factor(& lhs, cstr)) <= 0) return len_lhs;

    cstr += len_lhs;
    while (* cstr == MULT || * cstr == DIV)
    {
        len_rhs = _factor(& rhs, cstr + 1);
        if (len_rhs <= 0) return len_rhs;

        if (* cstr == MULT) lhs *= rhs;
        if (* cstr == DIV) lhs /= rhs;

        len_lhs += len_rhs + 1;
        cstr += len_rhs + 1;
    }

    * z = lhs;

    return len_lhs;
}

static int _expr(complex * z, const char * cstr)
{
    complex lhs, rhs;
    int     len_lhs, len_rhs;

    if ((len_lhs = _term(& lhs, cstr)) <= 0) return len_lhs;
    cstr += len_lhs;

    if (! * cstr)
    {
        * z = lhs;
        return len_lhs;
    }

    while (* cstr == PLUS || * cstr == MINUS)
    {
        len_rhs = _term(& rhs, cstr + 1);
        if (len_rhs <= 0) return len_rhs;

        if (* cstr == PLUS) lhs += rhs;
        if (* cstr == MINUS) lhs -= rhs;

        len_lhs += len_rhs + 1;
        cstr += len_rhs + 1;
    }

    * z = lhs;

    return len_lhs;
}

// Grammar
// E : T ( + | - T)?+
// T : F ( * | / F)?+
// F : base (^ F)?
// base : val | ( E ) | -T

#define BUFF_SIZE (1 << 6)

bool parse_expr(void * number, const char * cstr)
{
    char    buff[BUFF_SIZE] = {};
    int     len;

    if (! _remove_space(cstr, buff, BUFF_SIZE)) return false;

    if ((len = _expr(number, buff)) > 0) return ! buff[len];

    return false;
}
