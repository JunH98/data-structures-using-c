#ifndef __BINARY_TREE2_H__
#define __BINARY_TREE2_H__

typedef int BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeBTreeNode(void);//이진트리노드를 생성하여 주소값 반환
BTData GetData(BTreeNode* bt);//노드에 저장된 데이터 반환
void SetData(BTreeNode* bt, BTData data);//노드에 데이터를 저장

BTreeNode* GetLeftSubTree(BTreeNode* bt);	//왼쪽서브트리의 주소값 반환
BTreeNode* GetRightSubTree(BTreeNode* bt);	//오른쪽서브트리의 주소값 반환

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);//왼쪽 서브트리 연결
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);	//오른쪽 서브트리 연결


typedef void(*VisitFuncPtr)(BTData data);

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

#endif