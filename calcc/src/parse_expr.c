#include <complex.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool        _remove_space(const char * restrict cstr, char * buff, int max_len);
static int  _expr(complex * z, const char * cstr);
static int  _term(complex * z, const char * cstr);

// E : T (bop T)?+
// T : val | ( E ) | uop T
// val : re | re i
// bop : + | - | * | /
// uop : -

// E : T ( + | - T)+?
// T : F ( * | / F)+?
// F : base (^ F)?
// base : val | ( E ) | - T

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

    if (* cstr == 'i')
    {
        * z = I;
        return 1;
    }

    if ((len = _re(z, cstr)) <= 0) return len;
    if (cstr[len] == 'i')
    {
        * z *= I;
        len ++;
    }

    return len;
}

static int _base(complex * z, const char * cstr)
{
    int len;

    if (* cstr == '(')
    {
        if ((len = _expr(z, cstr + 1)) <= 0) return len;
        if (cstr[len + 1] != ')') return -1;

        return len + 2;
    }

    if (* cstr == '-')
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
    
    if (* cstr == '^')
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
    while (* cstr == '*' || * cstr == '/')
    {
        len_rhs = _factor(& rhs, cstr + 1);
        if (len_rhs <= 0) return len_rhs;

        if (* cstr == '*') lhs *= rhs;
        if (* cstr == '/') lhs /= rhs;

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

    while (* cstr == '+' || * cstr == '-')
    {
        len_rhs = _term(& rhs, cstr + 1);
        if (len_rhs <= 0) return len_rhs;

        if (* cstr == '+') lhs += rhs;
        if (* cstr == '-') lhs -= rhs;

        len_lhs += len_rhs + 1;
        cstr += len_rhs + 1;
    }

    * z = lhs;

    return len_lhs;
}

#define BUFF_SIZE (1 << 6)
bool parse_expr(complex * z, const char * cstr)
{
    char    buff[BUFF_SIZE] = {};
    int     len;

    if (! _remove_space(cstr, buff, BUFF_SIZE)) return false;

    len = _expr(z, buff);

    return len > 0;
}
