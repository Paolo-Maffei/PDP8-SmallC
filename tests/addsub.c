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

addc(c1, c2, r, rs)
char c1, c2, r;
char *rs;
{
    assert(c1+c2 == r, rs);
}

addi(i1, i2, r, rs)
int i1, i2, r;
char *rs;
{
    assert(i1+i2 == r, rs);
}

addcp(cp, i, r, rs)
char *cp, r;
int i;
char *rs;
{
    assert(cp+i == r, rs);
}

addip(ip, i, r, rs)
int *ip, r;
int i;
char *rs;
{
    assert(ip+i == r, rs);
}

subc(c1, c2, r, rs)
char c1, c2, r;
char *rs;
{
    assert(c1-c2 == r, rs);
}

subi(i1, i2, r, rs)
int i1, i2, r;
char *rs;
{
    assert(i1-i2 == r, rs);
}

subcp(cp, i, r, rs)
char *cp, r;
int i;
char *rs;
{
    assert(cp-i == r, rs);
}

subip(ip, i, r, rs)
int *ip, r;
int i;
char *rs;
{
    assert(ip-i == r, rs);
}

char ca[2], *cp, c;
int  ia[2], *ip, i;

main()
{
    errors = 0;

    addc( 0, 0,  0+0,   "0+0");
    addc( 1, 1,  1+1,   "1+1");
    addc( 2, 2,  2+2,   "2+2");
    addc(-2, -2, -2+-2, "-2+-2");

    addi( 0, 0,  0+0,   "0+0");
    addi( 1, 1,  1+1,   "1+1");
    addi( 2, 2,  2+2,   "2+2");
    addi(-2, -2, -2+-2, "-2+-2");

    addcp(ca,    1, ca+1, "cp+1");
    addcp(ca+1, -1, ca,   "cp-1");

    addip(ia,    1, ia+1, "ip+1");
    addip(ia+1, -1, ia,   "ip-1");

    subc( 0, 0,  0-0,   "0-0");
    subc( 1, 1,  1-1,   "1-1");
    subc( 2, 2,  2-2,   "2-2");
    subc(-2, -2, -2-(-2), "-2--2");

    subi( 0, 0,  0-0,   "0-0");
    subi( 1, 1,  1-1,   "1-1");
    subi( 2, 2,  2-2,   "2-2");
    subi(-2, -2, -2-(-2), "-2--2");

    subcp(ca,   -1, ca+1, "cp-(-1)1");
    subcp(ca+1,  1, ca,   "cp-1");

    subip(ia,   -1, ia+1, "ip-(-1)");
    subip(ia+1,  1, ia,   "ip-1");

    fprintf(stderr, "%d errors\n", errors);
    return errors;
}
