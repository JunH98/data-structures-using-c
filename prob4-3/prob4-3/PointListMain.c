#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"
#include "Point.h"

int WhoIsPrecede(int d1, int d2) {
	if (d1 < d2)
		return 0;	//정렬순서상 d1이 앞선다
	else
		return 1;	//정렬순서상 d2가 앞서거나 같다
}

int main(void)
{
	List list;
	Point compPos;
	Point * ppos;

	ListInit(&list);

	SetSortRule(&list, WhoIsPrecede);

	/*** 4개의 데이터 저장 ***/

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 4, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 5, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);


	/*** 저장된 데이터의 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	

	

	/*** xpos가 2인 모든 데이터 삭제 ***/
	//compPos.xpos=2;
	//compPos.ypos=0;

	//if(LFirst(&list, &ppos))
	//{
	//	if(PointComp(ppos, &compPos)==1)
	//	{
	//		ppos=LRemove(&list);
	//		free(ppos);
	//	}
	//	
	//	while(LNext(&list, &ppos)) 
	//	{
	//		if(PointComp(ppos, &compPos)==1)
	//		{
	//			ppos=LRemove(&list);
	//			free(ppos);
	//		}
	//	}
	//}

	/*** 삭제 후 남은 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);
	}
	printf("\n");

	return 0;
}