
#include <stdio.h>
#include <stdlib.h>
#include "sum.h"
#include <pthread.h>
#include <stdint.h>

long long int calculated_sum = 0;
int range_for_thread;
int thread_no = 0;
struct args
{
	long long limit;
};
int total_threads;
int balance_factor = 0;

void *sum_thread(void *vargp)
{
	int this_thread = thread_no++;
	int start_range = this_thread * range_for_thread + 1;
	int end_range = this_thread * range_for_thread + range_for_thread + 1;
	long long nth_sum = 0;

	if (this_thread == total_threads - 1)
	{
		end_range = end_range + balance_factor;
	}

	
	for (long long i = start_range; i < end_range; i++)
	{
		nth_sum = nth_sum + i;
	}
	calculated_sum = calculated_sum + nth_sum;
	printf("       sum(): Thread #%ld returned with sum of %lld\n", pthread_self(),nth_sum );
	return NULL;
}
void sum(long long limit, int n)
{
	total_threads = n;
	pthread_t *thread;
	thread = (pthread_t *)malloc(n * sizeof(pthread_t));
	struct args *t = (struct args *)malloc(sizeof(struct args));
	t->limit = limit;
	long long altered_limit = limit;
	long unsigned int retVal;


	for (int i = 0; i < 10; i++)
	{
		if (altered_limit % n != 0)
		{
			altered_limit = altered_limit - 1;
		}
		else
		{
			balance_factor = i;
			range_for_thread = (int)altered_limit / n;
			break;
		}
	}

	

	printf("sum(): Written by \"Mehdi on Nov/16/20\" for Lab 6\n");
	printf("sum(): Argument received %lld and %d\n", limit, n);

	for (int i = 0; i < n; i++)
	{

		int startR = i * range_for_thread + 1;
		retVal = pthread_create(&thread[i], NULL, &sum_thread, (void *)t);
		printf("       sum(): Creating Thread #%ld to sum numbers starting from %d\n",thread[i],startR);

		if (retVal != 0)
		{
			printf("pthread_create failed in %d_th pass\n", i);
			exit(EXIT_FAILURE);
		}
	}
	for (int i = 0; i < n; i++)
	{
		pthread_join(thread[i], NULL);
		;
	}

	
	printf("sum(): Total sum is %lli.\n", calculated_sum);
	return;
}
