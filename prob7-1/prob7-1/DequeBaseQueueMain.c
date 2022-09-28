#include <stdio.h>
#include "Deque.h"
#include "DequeBaseQueue.h"


int main() {

	Queue queue;			//���Լ���
	QueueInit(&queue);

	Enqueue(&queue, 1);
	Enqueue(&queue, 2);
	Enqueue(&queue, 3);
	Enqueue(&queue, 4);
	Enqueue(&queue, 5);

	while (!QIsEmpty(&queue)) {
		printf("%d ", Dequeue(&queue));
	}
	
	return 0;
}