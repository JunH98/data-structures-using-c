#ifndef __AL_GRAPH_BPS__
#define __AL_GRAPH_BPS__

#include "DLinkedList.h"

enum { A,B,C,D,E,F,G,H,I,J };

typedef struct _ual{
	int numV;
	int numE;
	List* adjList;
	int* visitInfo;
}ALGraph;

void GraphInit(ALGraph* pg, int nv);

void GraphDestory(ALGraph* pg);

void AddEdge(ALGraph* pg, int fromV, int toV);

void ShowGraphEdgeInfo(ALGraph* pg);

void BFShowGraphVertex(ALGraph* pg, int startV);

#endif // !__AL_GRAPH_BPS__
