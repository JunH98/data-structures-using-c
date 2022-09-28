#include <stdio.h>
#include <string.h>
#include "NameCard.h"
#include "ArrayList.h"
#pragma warning(disable:4996)

int main() {

	List list;
	NameCard* ncard;
	ListInit(&list);

	// 3���� ��ȭ��ȣ�� ����Ʈ�� ����

	ncard = MakeNameCard("aaa", "11111111");
	LInsert(&list, ncard);
	ncard = MakeNameCard("bbb", "22222222");
	LInsert(&list, ncard);
	ncard = MakeNameCard("ccc", "33333333");
	LInsert(&list, ncard);



	//Ư�� �̸��� ������� Ž���� �����Ͽ�, �� ����� ������ ����Ѵ�


	if (LFirst(&list, &ncard)) {
		if (NameCompare(ncard,"ccc") == 0) {
			ShowNameCardInfo(ncard);
		}
		else {
			while (LNext(&list, &ncard)) {
				if (NameCompare(ncard, "ccc") == 0) {
					ShowNameCardInfo(ncard);
					break;
				}
			}
		}
	}

	//Ư���̸��� ������� Ž���� �����Ͽ�, �׻���� ��ȭ��ȣ�� �����Ѵ�

	if (LFirst(&list, &ncard)) {
		if (NameCompare(ncard, "ccc") == 0) {
			ChangePhoneNum(ncard, "12345678");
					ShowNameCardInfo(ncard);
		}
		else {
			while (LNext(&list, &ncard)) {
				if (NameCompare(ncard, "ccc") == 0) {
					ChangePhoneNum(ncard, "12345678");
					ShowNameCardInfo(ncard);
					break;
				}
			}
		}
	}

	//Ư���̸��� ������� Ž���� �����Ͽ�, �� ����� ������ �����Ѵ�
	if (LFirst(&list, &ncard)) {
		if (NameCompare(ncard, "bbb") == 0) {
			ncard = LRemove(&list);
			free(ncard);
		}
		else {
			while (LNext(&list, &ncard)) {
				if (NameCompare(ncard, "bbb") == 0) {
					ncard = LRemove(&list);
					free(ncard);
					break;
				}
			}
		}
	}

	//������ �����ִ� ��� ����� ��ȭ��ȣ ������ ����Ѵ�

	if (LFirst(&list, &ncard)) {
			ShowNameCardInfo(ncard);
			while (LNext(&list, &ncard)) {
					ShowNameCardInfo(ncard);
			}
	}
	return 0;
}