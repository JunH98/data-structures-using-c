#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphDFS.h"
#include "ArrayBaseStack.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2);

// 그래프의 초기화
void GraphInit(ALGraph * pg, int nv)
{
	int i;	

	pg->adjList = (List*)malloc(sizeof(List)*nv);
	pg->numV = nv;
	pg->numE = 0;     // 초기의 간선 수는 0개

	for(i=0; i<nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede); 
	}

	//정점의 수를 길이로 하여 배열을 할당
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);

	//배열의 모든요소를 0으로 초기화
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);

}

// 그래프 리소스의 해제
void GraphDestroy(ALGraph * pg)
{
	if(pg->adjList != NULL)
		free(pg->adjList);
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

// 간선의 추가
void AddEdge(ALGraph * pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

// 유틸리티 함수: 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph * pg)
{
	int i;
	int vx;

	for(i=0; i<pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);
		
		if(LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);
			
			while(LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2)
{
	if(data1 < data2)
		return 0;
	else
		return 1;
}

int VisitVertex(ALGraph* pg, int visitV) {
	if (pg->visitInfo[visitV] == 0) {			//방문하지 않았음
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);
		return TRUE;
	}
	return FALSE;
}

void DFShowGraphVertex(ALGraph* pg, int startV) {
	
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);		//시작정점 방문
	SPush(&stack, visitV);			//시작 정점 push

	// visitV에 담김 정점과 연결된 정점의 방문을 시도
	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		//visitV와 연결된 정점의 정보가 nextV에 담긴상태에서 진행
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE) {
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else {
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
				if (VisitVertex(pg, nextV) == TRUE) {
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE) {
			if (SIsEmpty(&stack) == TRUE)
				break;
			else
				visitV = SPop(&stack);
		}
	}

	// 이후의 탐색을 위하여 탐색 정보 초기화
	memset(pg->visitInfo, 0, sizeof(int)*pg->numV);
}
