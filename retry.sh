set -e
make
(cd clib; sh cclib.sh)
./smallcc hello.c
./smallcc clib/vm.c hello.c clib/fprintf.c clib/csyslib.c clib/strlen.c clib/itoa.c clib/is.c clib/fputc.c clib/itoab.c clib/atoi.c clib/iscons.c clib/avail.c clib/exit.c clib/isatty.c clib/auxbuf.c clib/pad.c clib/reverse.c clib/itou.c clib/fclose.c clib/fputs.c clib/left.c clib/malloc.c
mv clib/vm.asm hello.pal
./smallcc clib/vm.c
./palx hello.pal
