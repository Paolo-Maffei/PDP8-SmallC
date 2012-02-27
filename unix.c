#include <stdlib.h>
#include <unistd.h>

void die(int err){
	exit(EXIT_FAILURE);
}

int iscons(int fd){
	return isatty(fd);
}

int avail(int abrt){
	return 16000; // dummy implementation
}
