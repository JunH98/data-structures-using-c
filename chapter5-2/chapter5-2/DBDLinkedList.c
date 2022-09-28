#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List* plist) {

	//��� ���� ����
	Node* dummyHead = (Node*)malloc(sizeof(Node));

	//���� ���� ����
	Node* dummyTail = (Node*)malloc(sizeof(Node));

	//��� ���� ����
	dummyHead->prev = NULL;
	dummyHead->next = dummyTail;
	plist->head = dummyHead;

	//���� ���� ����
	dummyTail->next = NULL;
	dummyTail->prev= dummyHead;
	plist->tail= dummyTail;

	plist->numOfData = 0;

}
void LInsert(List* plist, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	// ��忡 �����Ͱ� ���ٸ�
	if (plist->tail->prev->prev == NULL) {
		newNode->prev = plist->head;
		plist->head->next = newNode;
	}
	else {
		newNode->prev = plist->tail->prev;
		plist->tail->prev->next = newNode;
	}

	newNode->next = plist->tail;
	plist->tail->prev = newNode;

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata) {
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head->next;
	*pdata = plist->cur->data;

	return TRUE;
}
int LNext(List* plist, Data* pdata) {
	if (plist->cur->next->next == NULL)
		return FALSE;

	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}
int LPrevious(List* plist, Data* pdata) {
	if (plist->cur->prev->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;

	return TRUE;
}

Data LRemove(List * plist)
{
	Node * rpos = plist->cur;
	Data rdata = rpos->data;

	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;
	plist->cur = plist->cur->prev;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist) {
	return plist->numOfData; 
}

