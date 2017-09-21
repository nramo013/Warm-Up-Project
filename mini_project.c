#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int SharedVariable = 0; //initiate shared variable

void *SimpleThread(void *threadid)
{

	long tid; //set tid to long integer
	tid = (long)threadid; //assign tid to threadid
	int val; //initiate local integer variable val

	val = SharedVariable; //assign current value of shared variable to val
	printf("thread #%ld sees value %d\n", tid, val);
	SharedVariable = val +1; //increment val
	pthread_exit(NULL); //exit thread

} //thread returns string with thread id and variable value

int main ()
{

	int i; //initiate local variable i
	pthread_t tid; //initiate thread tid

	for (i=0; i<5; i++) //create loop to run 5 times for 5 threads
		pthread_create(&tid, NULL, *SimpleThread, (void *)i);

	pthread_exit (NULL);//exit thread
	return 0;

}