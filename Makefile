CPPFLAGS = -DYES=1 -DNO=0 -DNEWLINE="'\n'" -g

OBJ = cc1.o cc2.o cc3.o cc4.o unix.o

all : smallcc

clean : ; rm -f smallcc $(OBJ)

smallcc : $(OBJ) vm.h ; $(CC) -g -o $@ $(OBJ) clib/getarg.c

vm.h : clib/vm.ASM ./clib/mkzero.pl ; (cd clib; ./mkzero.pl)

test: all ; sh v2; ./ossmb/o2bin.pl link.o

cc4.o: cc4.c vm.h
