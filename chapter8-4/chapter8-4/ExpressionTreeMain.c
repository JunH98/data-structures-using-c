#include <stdio.h>
#include "ExpressionTree.h"

int main() {
	char exp[] = "12+7*";
	BTreeNode* eTree = MakeExpTree(exp);

	printf("���� ǥ����� ����: ");
	ShowPrefixTypeExp(eTree);
	printf("\n");

	printf("���� ǥ�����...:");
	ShowInfixTypeExp(eTree);
	printf("\n");

	printf("���� ǥ�����...:");
	ShowPostfixTypeExp(eTree);
	printf("\n");

	printf("result: %d \n", EvaluateExpTree);

	return 0;
}