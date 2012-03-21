ALL = smal8
CFLAGS = -g

# Run a quick regression test on the assembler.
all: $(ALL) hello.bin
	cp smal8 ..
	cp link.sh ../link

hello.o: hello.a smal8
	./smal8 -D hello.a

hello.bin: hello.o
	../ossmb/o2bin.pl hello.o

clean: ; rm *.lst *.o *.d *.bin *.map
