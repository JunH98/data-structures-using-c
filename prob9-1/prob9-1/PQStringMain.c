#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(char* ch1, char* ch2)
{
	return strlen(ch2) - strlen(ch1);
}

int main(void)
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, "this is 1st string");
	PEnqueue(&pq, "this is 2nd string___");
	PEnqueue(&pq, "this is 3rd string______");
	PEnqueue(&pq, "this is 4th string_________");
	PEnqueue(&pq, "this is 5th string____________");
	PEnqueue(&pq, "this is 6th string_________________");

	printf("%s \n", PDequeue(&pq));

	while(!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));

	return 0;
}
