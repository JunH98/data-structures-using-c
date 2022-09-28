#include <stdio.h>
#include "ListBaseQueue.h"


void QueueInit(Queue* pq) {
	pq->front = NULL;
	pq->rear = NULL;
}
int QIsEmpty(Queue* pq) {
	if (pq->front == NULL)
		return TRUE;
	return FALSE;
}

void EnQueue(Queue* pq, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if (QIsEmpty(pq)) {
		pq->front = newNode;
		pq->rear = newNode;
	}

	else {
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}
Data DeQueue(Queue* pq) {
	Node* delNode;
	Data delData;

	if (QIsEmpty(pq)) {
		printf("queue is empty");
		exit(-1);
	}

	delNode = pq->front;
	delData = delNode->data;

	pq->front = pq->front->next;
	free(delNode);

	return delData;
}
Data QPeek(Queue* pq) {
	if (QIsEmpty(pq)) {
		printf("queue is empty");
		exit(-1);
	}

	return pq->front->data;
}
