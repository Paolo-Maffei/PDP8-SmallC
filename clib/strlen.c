/*
** return length of string s (fast version)
*/
strlen(s) char *s; {
    s; /* Get s into AX */
#asm
    TAD _AX
    DCA _BX
    DCA _AX
L,  TAD I _BX
    SZA
    ISZ _AX
    SNA CLA
    JMP I __rets
    JMS I __jmpm
    L
#endasm
}

