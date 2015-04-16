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

lefti(c1, c2, r, rs)
int c1, c2, r;
char *rs;
{
    assert(c1<<c2 == r, rs);
}

righti(i1, i2, r, rs)
int i1, i2, r;
char *rs;
{
    assert(i1>>i2 == r, rs);
}

rightu(i1, i2, r, rs)
unsigned i1, i2, r;
char *rs;
{
    assert(i1>>i2 == r, rs);
}

char ca[2], *cp, c;
int  ia[2], *ip, i;

main()
{
    errors = 0;

    lefti( 02113, 0,  02113<<0,   "02113<<0");
    lefti( 02113, 1,  02113<<1,   "02113<<1");
    lefti( 02113, 7,  02113<<7,   "02113<<7");
    lefti( 02113, 11, 02113<<11,  "02113<<11");
    lefti( 02113, 12, 02113<<12,  "02113<<12");
    lefti( 05665, 0,  05665<<0,   "05665<<0");
    lefti( 05665, 1,  05665<<1,   "05665<<1");
    lefti( 05665, 7,  05665<<7,   "05665<<7");
    lefti( 05665, 11, 05665<<11,  "05665<<11");
    lefti( 05665, 12, 05665<<12,  "05665<<12");

    righti( 02113, 0,  02113>>0,   "02113>>0");
    righti( 02113, 1,  02113>>1,   "02113>>1");
    righti( 02113, 7,  02113>>7,   "02113>>7");
    righti( 02113, 11, 02113>>11,  "02113>>11");
    righti( 02113, 12, 02113>>12,  "02113>>12");
    righti( 05665, 0,  05665>>0,   "05665>>0");
    righti( 05665, 1,  05665>>1,   "05665>>1");
    righti( 05665, 7,  05665>>7,   "05665>>7");
    righti( 05665, 11, 05665>>11,  "05665>>11");
    righti( 05665, 12, 05665>>12,  "05665>>12");

    rightu( 02113, 0,  02113>>0,   "02113>>0");
    rightu( 02113, 1,  02113>>1,   "02113>>1");
    rightu( 02113, 7,  02113>>7,   "02113>>7");
    rightu( 02113, 11, 02113>>11,  "02113>>11");
    rightu( 02113, 12, 02113>>12,  "02113>>12");
    rightu( 05665, 0,  05665>>0,   "05665>>0");
    rightu( 05665, 1,  05665>>1,   "05665>>1");
    rightu( 05665, 7,  05665>>7,   "05665>>7");
    rightu( 05665, 11, 05665>>11,  "05665>>11");
    rightu( 05665, 12, 05665>>12,  "05665>>12");

    fprintf(stderr, "%d errors\n", errors);
    return errors;
}
