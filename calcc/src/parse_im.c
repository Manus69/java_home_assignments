#include <complex.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE (1 << 7)

bool _remove_space(const char * restrict cstr, char * buff, int max_len)
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

static bool _parse_tail(complex * dst, const char * cstr)
{
    char * ptr;
    double im;

    if (strcmp(cstr, "+i") == 0)
    {
        * dst += I;
        return true;
    }
    if (strcmp(cstr, "-i") == 0)
    {
        * dst -= I;
        return true;
    }

    im = strtod(cstr, & ptr);
    
    if (cstr == ptr) return false;
    if (* ptr != 'i') return false;

    * dst += im * I;

    return true;
}

bool parse_im(complex * dst, const char * cstr)
{
    char    buff[BUFF_SIZE] = {};
    char *  ptr;
    double  re;

    if (! _remove_space(cstr, buff, BUFF_SIZE)) return false;

    cstr = buff;
    re = strtod(cstr, & ptr);

    if (cstr == ptr) return false;
    if (! * ptr)
    {
        * dst = re;
        return true;
    }
    if (* ptr == 'i')
    {
        * dst = re * I;
        return true;
    }

    * dst = re;

    return _parse_tail(dst, cstr);
}