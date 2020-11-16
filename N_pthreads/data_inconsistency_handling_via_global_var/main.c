#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#include "sum.h"


int main (int argc, char **argv){
	if(argc < 3){
		printf("Usage %s [number]\n", argv[0]);
		exit(-1);
	} else {
		char *pointer;
		errno = 0;
		long long argument = strtoll(argv[1], &pointer, 10);
		int no_threads = strtol(argv[2], &pointer, 10);
	// printf(no_threads);
		if (no_threads < 1 || no_threads >10){
			exit(-1);
		}
		if (*pointer != '\0'){
			
			exit(-1);
		} else {
			sum(argument, no_threads);
		}
		
	}
	
	return 0;
}
