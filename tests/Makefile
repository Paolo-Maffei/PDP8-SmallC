
#
# A quick regression test
.SUFFIXES: .bin .c

ALL = addsub.bin muldiv.bin prefix.bin postfix.bin relop1.bin relop2.bin \
	shifts.bin
all: $(ALL)

clean: ; rm -f $(ALL)

.c.bin:
	../smallcc $< ../stubs.c
	../smal8 $(<:.c=.ASM)
	./link $(<:.c=.o)
	../ossmb/o2bin.pl link.o
	mv link.map $(@:.bin=.map)
	mv link.bin $@
