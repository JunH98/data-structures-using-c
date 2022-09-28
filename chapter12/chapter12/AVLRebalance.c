#include <stdio.h>
#include "AVLRebalance.h"

//LL회전
BTreeNode* RotateLL(BTreeNode* bst) {
	BTreeNode* pNode;		//parent node
	BTreeNode* cNode;		//child node

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
	ChangeRightSubTree(cNode, pNode);

	return cNode;
}
//RR회전
BTreeNode* RotateRR(BTreeNode* bst) {
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
	ChangeLeftSubTree(cNode, pNode);

	return cNode;
}

//RL회전
BTreeNode* RotateRL(BTreeNode* bst) {
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetRightSubTree(pNode);

	ChangeRightSubTree(pNode, RotateLL(cNode));
	return RotateRR(cNode);
}

//LR회전
BTreeNode* RotateLR(BTreeNode* bst) {
	BTreeNode* pNode;
	BTreeNode* cNode;

	pNode = bst;
	cNode = GetLeftSubTree(pNode);

	ChangeLeftSubTree(pNode, RotateRR(cNode));
	return RotateLL(pNode);
}


int GetHeight(BTreeNode* bst) {
	int leftH;		//left height
	int rightH;		//right height

	if (bst == NULL)
		return 0;

	leftH = GetHeight(GetLeftSubTree(bst));
	rightH = GetHeight(GetRightSubTree(bst));

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;
}

int GetHeightDiff(BTreeNode* bst) {
	int lsh;		//left sub tree height
	int rsh;		//right sub tree height

	if (bst == NULL)
		return 0;

	lsh = GetHeight(GetLeftSubTree(bst));
	rsh = GetHeight(GetRightSubTree(bst));

	return lsh - rsh;		//균형 인수 결과 리턴
}

BTreeNode* Rebalance(BTreeNode** pRoot) {
	int hDiff = GetHeightDiff(*pRoot);		//균형인수계산

	if (hDiff > 1) {
		if (GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}

	if (hDiff < -1) {
		if (GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}

	return *pRoot;
}