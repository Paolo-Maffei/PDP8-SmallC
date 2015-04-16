/*
 * C operator tests.
*/
#include "../clib/stdio.h"

#define SIZEI 1   /* sizeof(int) */
#define SIZEP 1   /* sizeof(pointer) */

int errors;

assert(e, s)
int e;
char *s;
{   if (e) return;
    fprintf(stderr, "Failed: %s\n", s);
    errors++;
}

cdec(c, r, rs)
char c, r;
char *rs;
{
    assert(r-- == c+1, rs);
    assert(c == r, rs);
}

idec(i, r, rs)
int i, r;
char *rs;
{
    assert(r-- == i+1, rs);
    assert(i == r, rs);
}

cpdec(cp, r, rs)
char *cp, *r;
char *rs;
{
    assert(r-- == cp+1, rs);
    assert(cp == r, rs);
}

ipdec(ip, r, rs)
int *ip, *r;
char *rs;
{
    assert(r-- == ip+1, rs);
    assert(ip == r, rs);
}

cinc(c, r, rs)
char c, r;
char *rs;
{
    assert(c++ == r-1, rs);
    assert(c == r, rs);
}

iinc(i, r, rs)
int i, r;
char *rs;
{
    assert(i++ == r-1, rs);
    assert(i == r, rs);
}

cpinc(cp, r, rs)
char *cp, *r;
char *rs;
{
    assert(cp++ == r-1, rs);
    assert(cp == r, rs);
}

ipinc(ip, r, rs)
int *ip, *r;
char *rs;
{
    assert(ip++ == r-1, rs);
    assert(ip == r, rs);
}

char ca[2], *cp, c;
int  ia[2], *ip, i;

main()
{
    errors = 0;

    cinc(-1, 0, "c++ (-1)");
    cinc( 0, 1, "c++ (0)");
    cinc( 1, 2, "c++ (1)");

    iinc(-1, 0, "i++ (-1)");
    iinc( 0, 1, "i++ (0)");
    iinc( 1, 2, "i++ (1)");

    cpinc(ca, ca+1, "cp++");

    ipinc(ia, ia+1, "ip++");

    cdec(-1, 0, "c-- (-1)");
    cdec( 0, 1, "c-- (0)");
    cdec( 1, 2, "c-- (1)");

    idec(-1, 0, "i-- (-1)");
    idec( 0, 1, "i-- (0)");
    idec( 1, 2, "i-- (1)");

    cpdec(ca, ca+1, "p-- (char)");
    cpdec(ca, &ca[1], "&c[]");

    ipdec(ia, ia+1, "p-- (int)");
    ipdec(ia, &ia[1], "&i[]");

    assert(sizeof c  == 1,       "sizeof(char)");
    assert(sizeof ca == 2,       "sizeof(carray)");
    assert(sizeof i  == SIZEI,   "sizeof(int)");
    assert(sizeof ia == 2*SIZEI, "sizeof(iarray)");
    assert(sizeof cp == SIZEP,   "sizeof(ip)");
    assert(sizeof ip == SIZEP,   "sizeof(ip)");

    fprintf(stderr, "%d errors\n", errors);
    return errors;
}
