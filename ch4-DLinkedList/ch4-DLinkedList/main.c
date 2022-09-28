#include <stdio.h>
#include "DLinkedList.h"

int main() {
	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	printf("present num of data: %d\n", LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);

		while (LNext(&list, &data))
		printf("%d ", data);
	}
	printf("\n\n");

	if (LFirst(&list, &data)) {
		if (data == 22)
			LRemove(&list);

		while (LNext(&list, &data)) {
			if (data == 22)
				LRemove(&list);
		}
	}

	printf("present num of data : %d\n",LCount(&list));

	if (LFirst(&list, &data)) {
		printf("%d ", data);

			while(LNext(&list, &data))
				printf("%d ",data);
	}

	printf("\n\n");
}