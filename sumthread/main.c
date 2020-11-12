#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#include "sum.h"


int main (int argc, char **argv){
	if(argc < 2){
		printf("Usage %s [number]\n", argv[0]);
		exit(-1);
	} else {
		
		char *pointer;
		errno = 0;
		long long argument = strtoll(argv[1], &pointer, 10);
		
		if (*pointer != '\0'){
			
			exit(-1);
		} else {
			sum(argument);
		}
		
		
	}
	
	return 0;
}
