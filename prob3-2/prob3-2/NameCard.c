#include <stdio.h>
#include <string.h>
#include "NameCard.h"
#pragma warning(disable:4996)




NameCard* MakeNameCard(char* name, char* phone) {
	NameCard* newCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(newCard->name, name);
	strcpy(newCard->phone, phone);

	return newCard;
}

void ShowNameCardInfo(NameCard* pcard) {
	printf("name: %s\n", pcard->name);
	printf("phone: %s\n", pcard->phone);
}

int NameCompare(NameCard* pacard, char* name) {
	return strcmp(pacard->name, name);
}

void ChangePhoneNum(NameCard* pacard, char* phone) {
	strncpy(pacard->phone, phone, PHONE_LEN);
}
