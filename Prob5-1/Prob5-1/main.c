#include <stdio.h>
#include <string.h>
#include "CLinkedList.h"

#pragma warning(disable:4996)

Data* WhoIsDuty(List* plist, char* name, int day);

int main() {
	//원형 연결 리스트 생성 및 초기화
	List list;
	Employee* pemp;
	ListInit(&list);


	pemp = (Employee*)malloc(sizeof(Employee));
	strcpy(pemp->name, "aaa");
	pemp->empNum = 101;
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	strcpy(pemp->name, "bbb");
	pemp->empNum = 102;
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	strcpy(pemp->name, "ccc");
	pemp->empNum = 103;
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	strcpy(pemp->name, "ddd");
	pemp->empNum = 104;
	LInsert(&list, pemp);

	pemp = WhoIsDuty(&list, "bbb", 3);
	printf("%s\n%d\n", pemp->name, pemp->empNum);

	return 0;
}

Data* WhoIsDuty(List* plist, char* name, int day) {
	int i, num;
	Employee *ret;

	num = LCount(plist);

	//find name;

	LFirst(plist, &ret);

	if (strcmp(ret->name, name) != 0) {
		for (i = 0; i < num - 1; i++) {
			LNext(plist, &ret);

			if (strcmp(ret->name, name) == 0)
				break;
		}
		if (i >= num - 1)
			return NULL;
	}

	for (i = 0; i < day; i++) {
		LNext(plist, &ret);
	}

	return ret;
}