ALL = smal8 ../smal8 ../link
CFLAGS = -g

# Run a quick regression test on the assembler.
all: $(ALL) hello.bin

../smal8: smal8
	cp smal8 ..

../link: link.sh
	cp link.sh ../link

hello.o: hello.a smal8
	./smal8 -D hello.a

hello.bin: hello.o
	../ossmb/o2bin.pl hello.o

clean: ; rm -f x$(ALL) *.lst *.o *.d *.bin *.map
