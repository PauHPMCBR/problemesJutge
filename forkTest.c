#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>


void main (int argc, char *argv[]) {
// int id1,ret;
// char buffer[128];
// id1 = getpid(); /* getpid devuelve el pid del proceso que la ejecuta */
// ret = fork();
// id1 = getpid();
// sprintf(buffer,"Valor de id1: %d; valor de ret: %d", id1, ret);
// write(1,buffer,strlen(buffer));

	char buffer[256];
	sprintf(buffer, "Este es el ejemplo número %d\n", 1);
	write(1, buffer, strlen(buffer));

}
