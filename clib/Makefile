OBJ = abs.o atoi.o atoib.o auxbuf.o avail.o bseek.o btell.o calloc.o \
	clearerr.o cseek.o ctell.o dtoi.o fclose.o \
	feof.o ferror.o fgets.o fopen.o fprintf.o fputs.o \
	fread.o freopen.o fscanf.o fwrite.o getarg.o getchar.o is.o \
	isascii.o itoa.o itoab.o itod.o itoo.o itou.o \
	itox.o left.o lexcmp.o malloc.o otoi.o pad.o poll.o putchar.o puts.o \
	reverse.o rewind.o sign.o strcat.o strchr.o strcmp.o \
	strcpy.o strlen.o strncat.o strncmp.o strncpy.o strrchr.o toascii.o \
	tolower.o toupper.o ungetc.o utoi.o xtoi.o vm.o
BROKEN = csyslib.o exit.o fgetc.o fputc.o free.o isatty.o iscons.o rename.o \
	unlink.o usr.o 

.SUFFIX: .ASM

DIR: $(OBJ)
	./mkDIR.pl >$@

vm.o:: vm.ASM
	../smal8 $<

.c.o:
	../smallcc $<
	../smal8 $(<:.c=.ASM)

$(OBJ):: ../smallcc ../smal8
