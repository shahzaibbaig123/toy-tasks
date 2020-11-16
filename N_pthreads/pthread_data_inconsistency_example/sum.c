
#include <stdio.h>
#include <stdlib.h>
#include "sum.h"
#include <pthread.h>
#include <stdint.h>

long long int calculated_sum = 0;

struct args {
    long long limit;
};

void *sum_thread(void* vargp)
{
	struct args *pars = vargp;
	int argument = (uintptr_t)(int *)pars->limit;


	for (long long i = 1; i <= argument; i++)
	{
		calculated_sum = calculated_sum + i;
	}

	printf("Calculated Sum - %lld, Thread ID - %ld\n",calculated_sum, pthread_self());
	return NULL;
}
void sum(long long limit, int n)
{	pthread_t *thread;
	thread = (pthread_t *) malloc (n*sizeof(pthread_t));

	struct args *t = (struct args *)malloc(sizeof(struct args));

	t->limit = limit;
	// pthread_t thread_id;

   int i;
   long unsigned int retVal;
   for (i=0;i<n;i++){
       retVal=pthread_create(&thread[i], NULL, &sum_thread, (void *)t);;
       if(retVal!=0){
           printf("pthread_create failed in %d_th pass\n",i);
           exit(EXIT_FAILURE);        
       }
   }
      for (i=0;i<n;i++){
       pthread_join(thread[i], NULL);;

   }

	printf("sum(): Written by \"Mehdi on x/x/x\" for Lab 6\n");
	printf("sum(): argument received %lld\n", limit);
	printf("sum(): %lli returned\n", calculated_sum);
	return;
}
