CCARGC() {
#asm
        TAD _CX
        DCA _AX
#endasm
}

fputc(ch, fp) char ch; int *fp; {
        ch;
#asm
        TAD _AX
        TLS
        TSF
        JMP .-1
        CLA
#endasm
} 
