//#include <stdio.h>
//#include "BinaryTree2.h"
//#include "BinarySearchTree.h"
//
//void BSTMakeAndInit(BTreeNode** pRoot) {
//	*pRoot = NULL;
//}
//
//BSTData BSTGetNodeData(BTreeNode* bst) {
//	return GetData(bst);
//}
//
//void BSTInsert(BTreeNode** pRoot, BSTData data) {
//	BTreeNode* pNode = NULL;		//parent node
//	BTreeNode* cNode = *pRoot;		//current node
//	BTreeNode* nNode = NULL;		//new node
//
//	while (cNode != NULL) {
//		if (data == GetData(cNode))
//			return;
//
//	pNode = cNode;
//
//	if (GetData(cNode) > data)
//		cNode = GetLeftSubTree(cNode);
//	else
//		cNode = GetRightSubTree(cNode);
//	}
//
//	//pNode의 자식노드로 추가할 새 노드의 생성
//	nNode = MakeBTreeNode();
//	SetData(nNode, data);
//
//	if (pNode != NULL) {			//nNode is not rootNode
//		if (data < GetData(pNode))
//			return MakeLeftSubTree(pNode, nNode);
//		else
//			return MakeRightSubTree(pNode, nNode);
//	}
//
//	else							//nNode is rootNode;
//		*pRoot = nNode;
//}
//BTreeNode* BSTSearch(BTreeNode* bst, BSTData target) {
//	BTreeNode* cNode = bst;
//	BSTData cd;
//
//	while (cNode != NULL) {
//		cd = GetData(cNode);
//
//		if (target == cd)
//			return cNode;
//		else if (target < cd)
//			cNode = GetLeftSubTree(cNode);
//		else
//			cNode = GetRightSubTree(cNode);
//	}
//	return NULL;		//search failed
//}