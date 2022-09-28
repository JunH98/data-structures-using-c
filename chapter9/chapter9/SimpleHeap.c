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
////�ΰ��� �ڽ� ��� �� ���� �켱������ �ڽ� ��� �ε��� �� ��ȯ
//int GetHiPriChildIDX(Heap* ph, int idx) {
//	// �ڽĳ�� ����
//	if (GetLChildIDX(idx) > ph->numOfData)
//		return 0;
//	// �ڽĳ�尡 �ϳ�
//	else if (GetLChildIDX(idx) == ph->numOfData)
//		return GetLChildIDX(idx);
//
//	//�ڽĳ�尡 �� �� ����
//	else {
//		//������ �ڽĳ���� �켱������ �� ����
//		if (ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
//			return GetRChildIDX(idx);
//		// ���� ... �� ����
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
//	if (d1 < d2)			//d1�� �߿䵵�� ����
//		return 1;
//	else if (d1 > d2)		//d2�� �߿䵵�� ����
//		return -1;
//	else
//		return 0;
//}
