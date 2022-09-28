//#include "SimpleHeap.h"
//
//void HeapInit(Heap* ph) {
//	ph->numOfData = 0;
//}
//int HIsEmpty(Heap* ph) {
//	if (ph->numOfData == 0)
//		return TRUE;
//	else
//		return FALSE;
//}
//
//int GetParentIDX(int idx) {
//	return idx / 2;
//}
//
//int GetLChildIDX(int idx) {
//	return idx * 2;
//}
//
//int GetRChildIDX(int idx) {
//	return idx * 2+1;
//}
////두개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
//int GetHiPriChildIDX(Heap* ph, int idx) {
//	// 자식노드 없음
//	if (GetLChildIDX(idx) > ph->numOfData)
//		return 0;
//	// 자식노드가 하나
//	else if (GetLChildIDX(idx) == ph->numOfData)
//		return GetLChildIDX(idx);
//
//	//자식노드가 둘 다 존재
//	else {
//		//오른쪽 자식노드의 우선순위가 더 높다
//		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
//			return GetRChildIDX(idx);
//		// 왼쪽 ... 더 높다
//		else
//			return GetLChildIDX(idx);
//	}
//
//}
//void HInsert(Heap* ph, HData data, Priority pr) {
//	int idx = ph->numOfData+1;
//	HeapElem nelem = { pr, data };
//
//	while (idx != 1) {
//		if (pr < (ph->heapArr[GetParentIDX(idx)].pr)) {
//			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
//			idx = GetParentIDX(idx);
//		}
//
//		else
//			break;
//	}
//
//	ph->heapArr[idx] = nelem;
//	ph->numOfData += 1;
//}
//HData HDelete(Heap* ph) {
//	HData retData = (ph->heapArr[1]).data;
//	HeapElem lastElem = ph->heapArr[ph->numOfData];
//
//	int parentIdx = 1;
//	int childIdx;
//
//	while (childIdx = GetHiPriChildIDX(ph, parentIdx)) {
//		if (lastElem.pr <= ph->heapArr[childIdx].pr)
//			break;
//		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
//		parentIdx = childIdx;
//	}
//
//	ph->heapArr[parentIdx] = lastElem;
//	ph->numOfData -= 1;
//	return retData;
//}
//
//int PriorityComp(HData d1, HData d2) {
//	if (d1 < d2)			//d1의 중요도가 높다
//		return 1;
//	else if (d1 > d2)		//d2의 중요도가 높다
//		return -1;
//	else
//		return 0;
//}
