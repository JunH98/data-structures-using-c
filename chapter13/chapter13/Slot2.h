#ifndef __SLOT2_H__
#define __SLOT2_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

//enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _slot
{
	Key key;
	Value val;
	//enum SlotStatus status;
}Slot;

// Slot�� �����ؼ��� ������ �Լ��� �������� �ʴ´�.
#endif