/*
 * C operator tests.
*/
#include "../clib/stdio.h"

int errors;

assert(e, s)
int e;
char *s;
{   if (e) return;
    fprintf(stderr, "Failed: %s\n", s);
    errors++;
}

lti(i1, i2, r, rs)
int i1, i2, r;
char *rs;
{
    assert((i1<i2) == r, rs);
    assert((i2>i1) == r, rs);
}

ltu(i1, i2, r, rs)
unsigned i1, i2, r;
char *rs;
{
    assert((i1<i2) == r, rs);
    assert((i2>i1) == r, rs);
}

lei(i1, i2, r, rs)
int i1, i2, r;
char *rs;
{
    assert((i1<=i2) == r, rs);
    assert((i2>=i1) == r, rs);
}

leu(i1, i2, r, rs)
unsigned i1, i2, r;
char *rs;
{
    assert((i1<=i2) == r, rs);
    assert((i2>=i1) == r, rs);
}

main()
{
    errors = 0;

    ltu( 4095, 1, 4095<1, "4095<1u");
    ltu( 0,  0,  0<0, "0<0u");
    ltu( 1, 4095, 1<4095, "1<4095u");
    ltu( 1,  3,  1<3, "1<3u");
    ltu( 2,  2,  2<2, "2<2u");
    ltu( 3,  1,  3<1, "3<1u");
    ltu( 4095, 4093, 4095<4093, "4095<4093u");
    ltu( 4094, 4094, 4094<4094, "4094<4094u");
    ltu( 4093, 4095, 4093<4095, "4093<4095u");
    ltu( -2048, -2049, -2048<-2049, "-2048<-2049u");
    ltu( -2048, -2048, -2048<-2048, "-2048<-2048u");
    ltu( -2048, -2047, -2048<-2047, "-2048<-2047u");

    leu( 4095, 1, 4095<=1, "4095<=1u");
    leu( 0,  0,  0<=0, "0<=0u");
    leu( 1, 4095, 1<=4095, "1<=4095u");
    leu( 1,  3,  1<=3, "1<=3u");
    leu( 2,  2,  2<=2, "2<=2u");
    leu( 3,  1,  3<=1, "3<=1u");
    leu( 4095, 4093, 4095<=4093, "4095<=4093u");
    leu( 4094, 4094, 4094<=4094, "4094<=4094u");
    leu( 4093, 4095, 4093<=4095, "4093<=4095u");
    leu( -2048, -2049, -2048<=-2049, "-2048<=-2049u");
    leu( -2048, -2048, -2048<=-2048, "-2048<=-2048u");
    leu( -2048, -2047, -2048<=-2047, "-2048<=-2047u");

    fprintf(stderr, "%d errors\n", errors);
    return errors;
}
