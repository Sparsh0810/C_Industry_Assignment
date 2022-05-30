//Write a multithreading program, where threads runs same shared global variable of the process between them. 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t tid1, tid2;		//variables to store thread id

int globalVar = 10;		//global variable declared


//increase globalVar by 15
void* global_increase(void *arg)
{
	printf("1st thread in execution\n");
	globalVar += 15;
	printf("after increment : %d\n\n", globalVar);
	
	return NULL;
}


//decrease globalVar by 5
void* global_decrease(void *arg)
{
	printf("2nd thread in execution\n");
	globalVar -= 5;
	printf("after decrement : %d\n", globalVar);
	
	return NULL;
}


int main(void)
{
	pthread_create(&tid1, NULL, global_increase, NULL);
	pthread_create(&tid2, NULL, global_decrease, NULL);
	
	//executing threads
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	
	//returning to parent process
	printf("\nExecuting parent process\n");
	
	return 0;
}

//use this to compile------- "gcc pthread.c -o pthrd -l pthread"	