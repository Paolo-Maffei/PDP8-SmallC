CPPFLAGS = -DYES=1 -DNO=0 -DNEWLINE="'\n'" -g

OBJ = cc1.o cc2.o cc3.o cc4.o unix.o

all : smaldir smallcc

smaldir: ; cd smal; make

clibdir: ; cd clib; make

clean : ; cd smal; make clean; rm -f smallcc $(OBJ)

smallcc : $(OBJ) vm.h ; $(CC) -g -o $@ $(OBJ) clib/getarg.c

vm.h : clib/vm.ASM ./clib/mkzero.pl ; (cd clib; ./mkzero.pl)

#
# A quick regression test
test: all
	cd clib; make
	./smallcc hello.c stubs.c
	./smal8 hello.ASM
	./link hello.o
	./ossmb/o2bin.pl link.o

cc4.o: cc4.c vm.h
