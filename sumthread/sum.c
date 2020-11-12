
#include <stdio.h>
#include <stdlib.h>
#include "sum.h"
#include <pthread.h>
#include <stdint.h>

long long int calculated_sum = 0;

void *sum_thread(void* vargp)
{
	int argument = (uintptr_t)(int *)vargp;

	// char str[256];
	// sprintf(str, "%d", &argument);
	// printf("%d\n", argument);

	for (long long i = 1; i <= argument; i++)
	{
		calculated_sum = calculated_sum + i;
	}
	return NULL;
}
void sum(long long limit)
{
	pthread_t thread_id;
	pthread_create(&thread_id, NULL, &sum_thread, (void *)limit);
	pthread_join(thread_id, NULL);
	printf("sum(): Written by \"Sana Qadir on 05/11/2020\" for Lab 5\n");
	printf("sum(): argument received %lld\n", limit);
	printf("sum(): %lli returned\n", calculated_sum);
	return;
}
