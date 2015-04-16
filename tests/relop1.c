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

    lti( -1, 1, -1<1, "-1<1");
    lti( 0,  0,  0<0, "0<0");
    lti( 1, -1, 1<-1, "1<-1");
    lti( 1,  3,  1<3, "1<3");
    lti( 2,  2,  2<2, "2<2");
    lti( 3,  1,  3<1, "3<1");
    lti( -1, -3, -1<-3, "-1<-3");
    lti( -2, -2, -2<-2, "-2<-2");
    lti( -3, -1, -3<-1, "-3<-1");
    lti( -2048, -2049, -2048<-2049, "-2048<-2049");
    lti( -2048, -2048, -2048<-2048, "-2048<-2048");
    lti( -2048, -2047, -2048<-2047, "-2048<-2047");

    lei( -1, 1, -1<=1, "-1<=1");
    lei( 0,  0,  0<=0, "0<=0");
    lei( 1, -1, 1<=-1, "1<=-1");
    lei( 1,  3,  1<=3, "1<=3");
    lei( 2,  2,  2<=2, "2<=2");
    lei( 3,  1,  3<=1, "3<=1");
    lei( -1, -3, -1<=-3, "-1<=-3");
    lei( -2, -2, -2<=-2, "-2<=-2");
    lei( -3, -1, -3<=-1, "-3<=-1");
    lei( -2048, -2049, -2048<=-2049, "-2048<=-2049");
    lei( -2048, -2048, -2048<=-2048, "-2048<=-2048");
    lei( -2048, -2047, -2048<=-2047, "-2048<=-2047");

    fprintf(stderr, "%d errors\n", errors);
    return errors;
}
