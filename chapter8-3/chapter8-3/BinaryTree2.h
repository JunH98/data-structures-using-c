#ifndef __BINARY_TREE2_H__
#define __BINARY_TREE2_H__

typedef int BTData;

typedef struct _bTreeNode {
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeBTreeNode(void);//����Ʈ����带 �����Ͽ� �ּҰ� ��ȯ
BTData GetData(BTreeNode* bt);//��忡 ����� ������ ��ȯ
void SetData(BTreeNode* bt, BTData data);//��忡 �����͸� ����

BTreeNode* GetLeftSubTree(BTreeNode* bt);	//���ʼ���Ʈ���� �ּҰ� ��ȯ
BTreeNode* GetRightSubTree(BTreeNode* bt);	//�����ʼ���Ʈ���� �ּҰ� ��ȯ

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);//���� ����Ʈ�� ����
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);	//������ ����Ʈ�� ����


typedef void(*VisitFuncPtr)(BTData data);

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);

#endif