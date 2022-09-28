#include <stdio.h>
#include "DBDLinkedList.h"

int main() {
	//list 생성및 초기화
	List list;
	int data;
	ListInit(&list);

	// save 8 lists
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	LInsert(&list, 7);
	LInsert(&list, 8);

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		//move right and check data
		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n\n");
	}

	if (LFirst(&list, &data)) {
			if (data % 2 == 0) 
				LRemove(&list);
		while (LNext(&list, &data)) {
			if (data % 2 == 0) 
				LRemove(&list);
		}
	}

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		//move right and check data
		while (LNext(&list, &data))
			printf("%d ", data);

		printf("\n\n");
	}
	return 0;
}