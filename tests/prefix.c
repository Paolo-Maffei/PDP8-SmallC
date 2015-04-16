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

lnot(i, r, rs)
int i, r;
char *rs;
{
    assert(!i == r, rs);
}

bnot(i, r, rs)
int i, r;
char *rs;
{
    assert(~i == r, rs);
}

uminus(i, r, rs)
int i, r;
char *rs;
{
    assert(-i == r, rs);
}

decc(c, r, rs)
char c, r;
char *rs;
{
    assert(c == --r, rs);
}

deci(i, r, rs)
int i, r;
char *rs;
{
    assert(i == --r, rs);
}

deccp(cp, r, rs)
char *cp, *r;
char *rs;
{
    assert(cp == --r, rs);
}

decip(ip, r, rs)
int *ip, *r;
char *rs;
{
    assert(ip == --r, rs);
}

incc(c, r, rs)
char c, r;
char *rs;
{
    assert(++c == r, rs);
}

inci(i, r, rs)
int i, r;
char *rs;
{
    assert(++i == r, rs);
}

inccp(cp, r, rs)
char *cp, *r;
char *rs;
{
    assert(++cp == r, rs);
}

incip(ip, r, rs)
int *ip, *r;
char *rs;
{
    assert(++ip == r, rs);
}

starcp(cp, r, rs)
char *cp, r;
char *rs;
{
    assert(*cp == r, rs);
}

starip(ip, r, rs)
char *ip, r;
char *rs;
{
    assert(*ip == r, rs);
}

char ca[2], *cp, c;
int  ia[2], *ip, i;

main()
{
    errors = 0;

    lnot( 0, !0,  "!0");
    lnot( 1, !1,  "!1");
    lnot( 2, !2,  "!2");
    lnot(-2, !-2, "!-2");

    bnot( 0,    ~0,     "~0");
    bnot( 1,    ~1,     "~1");
    bnot( 2,    ~2,     "~2");
    bnot(0x555, ~0x555, "~0x555");
    bnot(0xAAA, ~0xAAA, "~0xAAA");
    bnot(-2,    ~-2,    "~-2");

    uminus( 0,    -0,     "-0");
    uminus( 1,    -1,     "-1");
    uminus( 2,    -2,     "-2");
    uminus(0x555, -0x555, "-0x555");
    uminus(0xAAA, -0xAAA, "-0xAAA");
    uminus(-2,    -(-2),  "--2");

    incc(-1, 0, "++c (-1)");
    incc( 0, 1, "++c (0)");
    incc( 1, 2, "++c (1)");

    inci(-1, 0, "++i (-1)");
    inci( 0, 1, "++i (0)");
    inci( 1, 2, "++i (1)");

    inccp(ca, ca+1, "++cp");

    incip(ia, ia+1, "++ip");

    decc(-1, 0, "--c (-1)");
    decc( 0, 1, "--c (0)");
    decc( 1, 2, "--c (1)");

    deci(-1, 0, "--i (-1)");
    deci( 0, 1, "--i (0)");
    deci( 1, 2, "--i (1)");

    deccp(ca, ca+1, "--p (char)");
    deccp(ca, &ca[1], "&c[]");

    decip(ia, ia+1, "--p (int)");
    decip(ia, &ia[1], "&i[]");

    ca[0] = 0x1A; ca[1] = 0x1B;
    starcp(ca, ca[0], "*cp (0)");
    starcp(ca+1, ca[1], "*cp (1)");

    ia[0] = 0x2A; ia[1] = 0x2B;
    starip(ca, ca[0], "*cp (0)");
    starip(ca+1, ca[1], "*cp (1)");

    assert(sizeof c  == 1,       "sizeof(char)");
    assert(sizeof ca == 2,       "sizeof(carray)");
    assert(sizeof i  == SIZEI,   "sizeof(int)");
    assert(sizeof ia == 2*SIZEI, "sizeof(iarray)");
    assert(sizeof cp == SIZEP,   "sizeof(ip)");
    assert(sizeof ip == SIZEP,   "sizeof(ip)");

    fprintf(stderr, "%d errors\n", errors);
    return errors;
}
