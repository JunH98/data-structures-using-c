#include <stdio.h>
#include <string.h>
#include "NameCard.h"
#include "ArrayList.h"
#pragma warning(disable:4996)

int main() {

	List list;
	NameCard* ncard;
	ListInit(&list);

	// 3명의 전화번호를 리스트에 저장

	ncard = MakeNameCard("aaa", "11111111");
	LInsert(&list, ncard);
	ncard = MakeNameCard("bbb", "22222222");
	LInsert(&list, ncard);
	ncard = MakeNameCard("ccc", "33333333");
	LInsert(&list, ncard);



	//특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 출력한다


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

	//특정이름을 대상으로 탐색을 진행하여, 그사람의 전화번호를 변경한다

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

	//특정이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 삭제한다
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

	//끝으로 남아있는 모든 사람의 전화번호 정보를 출력한다

	if (LFirst(&list, &ncard)) {
			ShowNameCardInfo(ncard);
			while (LNext(&list, &ncard)) {
					ShowNameCardInfo(ncard);
			}
	}
	return 0;
}