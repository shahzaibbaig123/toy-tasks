#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#include "sum.h"


int main (int argc, char **argv){
	int n;
	printf("Enter the number for threads you want to create between 1 to 100 \n");
   scanf("%d",&n);

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
			sum(argument,n);
		}
		
		
	}
	
	return 0;
}
