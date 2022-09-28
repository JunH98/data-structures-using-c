#include <stdio.h>
#include "ListBaseQueue.h"

int ListBaseQueueMain() {

	Queue q;
	QueueInit(&q);

	//input data;
	EnQueue(&q, 1);
	EnQueue(&q, 3);
	EnQueue(&q, 2);
	EnQueue(&q, 5);
	EnQueue(&q, 4);

	while (!QIsEmpty(&q)) {
		printf("%d ", DeQueue(&q));
	}

	return 0;
}