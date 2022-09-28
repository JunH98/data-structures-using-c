#include <stdio.h>
#include "BinarySearchTree.h"

int BinarySearchTreeMain() {
	BTreeNode* bstRoot;
	BTreeNode* sNode;		//search node;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 9);
	BSTInsert(&bstRoot, 1);
	BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 8);
	BSTInsert(&bstRoot, 3);
	BSTInsert(&bstRoot, 5);

	//Å½»ö 
	sNode = BSTSearch(bstRoot, 1);
	if (sNode == NULL)
		printf("search failed\n");
	else
		printf("searched key value: %d \n", BSTGetNodeData(sNode));

	//Å½»ö 
	sNode = BSTSearch(bstRoot, 4);
	if (sNode == NULL)
		printf("search failed\n");
	else
		printf("searched key value: %d \n", BSTGetNodeData(sNode));

	//Å½»ö 
	sNode = BSTSearch(bstRoot, 6);
	if (sNode == NULL)
		printf("search failed\n");
	else
		printf("searched key value: %d \n", BSTGetNodeData(sNode));

	//Å½»ö 
	sNode = BSTSearch(bstRoot, 7);
	if (sNode == NULL)
		printf("search failed\n");
	else
		printf("searched key value: %d \n", BSTGetNodeData(sNode));

	return 0;
}