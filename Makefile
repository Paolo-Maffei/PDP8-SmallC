CPPFLAGS = -DYES=1 -DNO=0 -DNEWLINE="'\n'" -g

OBJ = cc1.o cc2.o cc3.o cc4.o unix.o clib/getarg.o

all : smallcc

clean : ; rm -f smallcc $(OBJ)

smallcc : $(OBJ) ; $(CC) -g -o $@ $^

cc4.o: cc4.c vm.h
