#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphKruskal.h"
#include "ArrayBaseStack.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2);
int PQWeightComp(Edge d1, Edge d2) {
	return d1.weight - d2.weight;
}

void RemoveEdge(ALGraph* pg, int fromV, int toV);
void RemoveWayEdge(ALGraph* pg, int fromV, int toV) ;
void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight) ;

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

	PQueueInit(&(pg->pqueue), PQWeightComp);

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
void AddEdge(ALGraph * pg, int fromV, int toV, int weight)
{
	Edge edge = { fromV, toV, weight };

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;

	//간선의 가중치 정보를 우선순위 큐에 저장
	PEnqueue(&(pg->pqueue), edge);
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

void ConKruskalMST(ALGraph* pg) {
	Edge recvEdge[20];
	Edge edge;
	int eidx = 0;
	int i;

	// mst를 형성할 때까지 아래의 while 반복
	while (pg->numE + 1 > pg->numV) {
		// 우선순위 큐에서 가중치가 가장높은 간선의 정보를 dequeue
		edge = PDequeue(&(pg->pqueue));
		// 꺼넨 간선을 그래프에서 삭제한다
		RemoveEdge(pg, edge.v1, edge.v2);

		
		if (!IsConnVertex(pg, edge.v1, edge.v2)) {		//간선을 삭제 후 두 정점을 연결하는 간선의 유무를 확인
			//남은 연결되는 간선이 없다면 그래프에서 삭제한 간선을 복구한다
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			// 간선의 정보를 별도로 저장한다 (우선순위 큐로 돌아가지 않는다)
			recvEdge[eidx++] = edge;
		}
	}
	//우선순위 큐에서 삭제된 간선의 정보 복구
	for (i = 0; i < eidx; i++)
		PEnqueue(&(pg->pqueue), recvEdge[i]);
}

void ShowGraphEdgeWeightInfo(ALGraph* pg) {			//간선의 가중치 정보 출력
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while (!PQIsEmpty(&copyPQ)) {
		edge = PDequeue(&copyPQ);
		printf("(%c-%c), w:%d \n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}
}

void RemoveEdge(ALGraph* pg, int fromV, int toV) {
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
}

void RemoveWayEdge(ALGraph* pg, int fromV, int toV) {
	int edge;

	if (LFirst(&pg->adjList[fromV], &edge)) {
		if (edge == toV) {
			LRemove(&(pg->adjList[fromV]));
			return;
		}

		while (LNext(&(pg->adjList[fromV]), &edge)) {
			if (edge == toV) {
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}

void RecoverEdge(ALGraph* pg, int fromV, int toV, int weight) {
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}

int IsConnVertex(ALGraph* pg, int v1, int v2) {
	Stack stack;
	int visitV = v1;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE) {
		int visitFlag = FALSE;

		if (nextV == v2) {
			//함수가 반환하기 전에 초기화 진행
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}

		if (VisitVertex(pg, nextV) == TRUE) {
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}

		else {
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE) {
				// 정점을 돌아다니는중 목표를 찾으면 TRUE를 반환
				if (nextV == v2) {
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return TRUE;
				}

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
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return FALSE;
}