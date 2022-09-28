#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

typedef struct __node {
	int data;
	struct __node* next;
}Node;

int main() {

	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	//input data

	while (1) {
		printf("input num: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		//add node
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			newNode->next = head;

		head = newNode;
	}
	printf("\n");

	//입력받은 데이터의 출력과정

	printf("print all data \n");
	if (head == NULL)
		printf("NULL\n");
	else {
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL) {
			cur = cur->next;
			printf("%d ", cur->data);
		}

		printf("\n\n");
		
		//free memory
		if (head == NULL) {
			return 0;
		}
		else {
			Node* delNode = head;
			Node* delNextNode = head->next;

			printf("delete %d\n", head->data);
			free(delNode);
			
			while (delNextNode != NULL) {
				delNode = delNextNode;
				delNextNode = delNextNode->next;

				printf("delete %d\n", delNode->data);
				free(delNode);
			}
		}
	}

	return 0;
}