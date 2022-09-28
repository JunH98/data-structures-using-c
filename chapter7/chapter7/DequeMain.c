#include <stdio.h>
#include "Deque.h"

int main() {

	Deque dq;
	Data data;

	DequeInit(&dq);
	
	//1�� ������ �ֱ�
	DQAddFirst(&dq, 3);
	DQAddFirst(&dq, 2);
	DQAddFirst(&dq, 1);
	DQAddLast(&dq, 4);
	DQAddLast(&dq, 5);
	DQAddLast(&dq, 6);

	while (!DQIsEmpty(&dq))
		printf("%d ", DQRemoveFirst(&dq));

	printf("\n\n\n");
	//2�� ������ �ֱ�

	DQAddFirst(&dq, 3);
	DQAddFirst(&dq, 2);
	DQAddFirst(&dq, 1);
	DQAddLast(&dq, 4);
	DQAddLast(&dq, 5);
	DQAddLast(&dq, 6);

	while (!DQIsEmpty(&dq))
		printf("%d ", DQRemoveLast(&dq));

	return 0;
}