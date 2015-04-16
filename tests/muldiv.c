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

muli(i1, i2, r, rs)
int i1, i2, r;
char *rs;
{
    assert(i1*i2 == r, rs);
}

mulu(i1, i2, r, rs)
unsigned i1, i2, r;
char *rs;
{
    assert(i1*i2 == r, rs);
}

divi(i1, i2, r, rs)
int i1, i2, r;
char *rs;
{
    assert(i1/i2 == r, rs);
}

divu(i1, i2, r, rs)
unsigned i1, i2, r;
char *rs;
{
    assert(i1/i2 == r, rs);
}

modi(i1, i2, r, rs)
int i1, i2, r;
char *rs;
{
    assert(i1%i2 == r, rs);
}

modu(i1, i2, r, rs)
unsigned i1, i2, r;
char *rs;
{
    assert(i1%i2 == r, rs);
}

char ca[2], *cp, c;
int  ia[2], *ip, i;

main()
{
    errors = 0;

    muli( 1, 10, 1*10, "1*10");
    muli( 0, 0,  0*0,  "0*0");
    muli( 1, 1,  1*1,  "1*1");
    muli( 2, 2,  2*2,  "2*2");
    muli(-2, -2, -2*(-2), "-2*-2");
    muli(-2, 2,  -2*2, "-2*2");

    /*
     * Small-C implements unsigned multiply differently,
     * so we test it here.  In actuality, it can be shown 
     * that signed vs unsigned multiply need differ in 
     * implementation only when the size of the result
     * is larger than the size of the operands.
    */
    mulu( 1, 10, 1*10, "1*10u");
    mulu( 0, 0,  0*0,  "0*0u");
    mulu( 1, 1,  1*1,  "1*1u");
    mulu( 2, 2,  2*2,  "2*2u");
    mulu(-2, -2, -2*(-2), "-2*-2u");
    mulu(-2, 2,  -2*2, "-2*2u");

    divi( 10, 1, 10/1, "10/1");
    divi( 2047, 2, 2047/2, "2047/2");
    divi( 04000, 2, 04000/2, "04000/2");
    divi( 04000, 02000, 04000/02000, "04000/02000");
    divi( 02000, 04000, 02000/04000, "02000/04000");
    divi( 04000, 04000, 04000/04000, "04000/04000");
    divi( 07777, 10, -1/10, "07777/10");

    divu( 10, 1, 10/1, "10/1");
    divu( 2047, 2, 2047/2, "2047/2u");
    divu( 04000, 2, 04000/2, "04000/2u");
    divu( 04000, 02000, 04000/02000, "04000/02000u");
    divu( 02000, 04000, 02000/04000, "02000/04000u");
    divu( 04000, 04000, 04000/04000, "04000/04000u");
    divu( 07777, 10, 07777/10, "07777/10u");

    modi( 10, 1, 10%1, "10%1");
    modi( 2047, 2, 2047%2, "2047%2");
    modi( 04000, 2, 04000%2, "04000%2");
    modi( 04000, 02000, 04000%02000, "04000%02000");
    modi( 02000, 04000, 02000%04000, "02000%04000");
    modi( 04000, 04000, 04000%04000, "04000%04000");
    modi( 07777, 10, -1%10, "07777%10");

    modu( 10, 1, 10%1, "10%1");
    modu( 2047, 2, 2047%2, "2047%2u");
    modu( 04000, 2, 04000%2, "04000%2u");
    modu( 04000, 02000, 04000%02000, "04000%02000u");
    modu( 02000, 04000, 02000%04000, "02000%04000u");
    modu( 04000, 04000, 04000%04000, "04000%04000u");
    modu( 07777, 10, 07777%10, "07777%10u");

    fprintf(stderr, "%d errors\n", errors);
    return errors;
}
