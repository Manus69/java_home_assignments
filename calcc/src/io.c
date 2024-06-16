#include "io.h"

#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <unistd.h>

#define MSG_NAN "NaN"
#define FMT     "%.3f"
#define EPS     (1.0 / 1000)

void io_msg(int fd, const char * msg)
{
    dprintf(fd, "%s", msg);
}

int io_error(const char * msg)
{
    io_msg(STDERR_FILENO, msg);

    return 1;
}

void io_dbg_complex(int fd, const void * z)
{
    complex _z;

    _z = * (complex *) z;

    dprintf(fd, "(%.2f, %.2f)", creal(_z), creal(_z));
}

static void _ppdbl(int fd, double x)
{
    if (fabs(x) < __INT_MAX__ && fabs(x - (int) x) < EPS) return (void) dprintf(fd, "%d", (int) x);

    dprintf(fd, FMT, x);
}

void io_pprint_complex(int fd, const void * z)
{
    complex _z;
    double  re;
    double  im;

    _z = * (complex *) z;
    re = creal(_z);
    im = cimag(_z);

    if ((_z != _z) || (re != re) || (im != im)) return (void) dprintf(fd, MSG_NAN);
    if (! re && ! im)                           return (void) dprintf(fd, "0");

    if      (re && ! im) _ppdbl(fd, re);
    else if (! re && im)
    {
        _ppdbl(fd, im);
        dprintf(fd, "i");
    }
    else
    {
        _ppdbl(fd, re);

        if (im > 0) dprintf (fd, " + ");
        if (im < 0)
        {
            dprintf(fd, " - ");
            im = -im;
        }
        _ppdbl(fd, im);
        dprintf(fd, "i");
    }
}