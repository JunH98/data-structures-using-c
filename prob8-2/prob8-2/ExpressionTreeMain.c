#include <stdio.h>
#include "ExpressionTree.h"

int main() {
	char exp[] = "3+2*7";
	BTreeNode* eTree = MakeExpTree(exp);

	//printf("전위 표기법의 수식: ");
	//ShowPrefixTypeExp(eTree);
	//printf("\n");

	//printf("중위 표기법의...:");
	//ShowInfixTypeExp(eTree);
	//printf("\n");

	//printf("후위 표기법의...:");
	//ShowPostfixTypeExp(eTree);
	//printf("\n");

	ShowInfixTypeExp(eTree);
	

	printf("result: %d \n", EvaluateExpTree);

	return 0;
}
