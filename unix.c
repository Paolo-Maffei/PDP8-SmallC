#include <stdlib.h>
#include <unistd.h>

void die(int err){
	exit(EXIT_FAILURE);
}

int iscons(int fd){
        return fd < 3; // VRS CYGWIN kludge
	return isatty(fd);
}

int avail(int abrt){
	return 16000; // dummy implementation
}

int poll(pause) int pause; { // VRS dummy implementation
  return 0;
}
