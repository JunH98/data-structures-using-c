#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

int main(void)
{
	Node * head = NULL;    // NULL ������ �ʱ�ȭ
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	/**** �����͸� �Է� �޴� ���� ****/

	head = (Node*)malloc(sizeof(Node));
	tail = head;
	while(1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;

		/*** ����� �߰����� ***/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	/**** �Է� ���� �������� ��°��� ****/
	printf("�Է� ���� �������� ��ü���! \n");
	if(tail == NULL) 
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}
	else 
	{
		cur = head; 
		
		while(cur->next != NULL)    // �� ��° ������ ������ ���
		{
			cur = cur->next;
			printf("%d  ", cur->data);
		}
	}
	printf("\n\n");

	/**** �޸��� �������� ****/
	if(tail == NULL) 
	{
		return 0;    // ������ ��尡 �������� �ʴ´�.
	}
	else 
	{
		Node * delNode = head;
		Node * delNextNode = head->next;
		
		while(delNextNode != NULL)    // �� ��° ������ ��� ���� ���� �ݺ���
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);    // �� ��° ������ ��� ����
		}
	}

	return 0;
}