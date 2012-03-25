#include "stdio.h"
#include "clib.h"
/*
** Close all open files and exit to DOS. 
** Entry: ec = exit code.
*/
exit(ec) int ec; {
  int fd;  char str[4];
  ec &= 255;
  if(ec) {
    left(itou(ec, str, 4));
    fputs("Exit Code: ", stderr);
    fputs(str, stderr);
    fputs("\n", stderr);
    }
/*
  for(fd = 0; fd < MAXFILES; ++fd) fclose(fd);
*/
#asm
        JMS I __getw1m  / Get first entry of the resident
        #7647           / device driver table
        JMS I __sub1n   / Is SYS: at 07607?
        #7607
        JMS I __eq10f
        halt
        JMS I __getw1n  / Get a pointer to 7600
        7600
        CIF CDF 0       / Branch to 07600 to exit
        JMP I _AX
halt,   HLT
        JMS I __jmpm
        halt

        GLOBAL _abort
_abort, JMS I __jmpm
        _exit
#endasm
  }

