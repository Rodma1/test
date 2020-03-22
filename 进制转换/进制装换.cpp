#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//1.��ʼ�� 2��ջ 3.��ջ 4.���� 5.whileѭ�����
typedef struct Node
{
	int data;//������
	struct Node *pNext;//ָ����
}NODE,*PNODE;
typedef struct Stack
{
	PNODE pTop;//ͷ�ڵ�
	PNODE pBottom;//β�ڵ�
}STACK,*PSTACK;

void InitCreat(PSTACK pHead);//��ʼ��
void Push(PSTACK pHead, int val);//��ջ
void traverset(PSTACK pHead);//����
void pop(PSTACK pHead, int *val);//��ջ
bool empty(PSTACK pHead);//�ж��Ƿ�Ϊ��
void clear(PSTACK pHead);//���ջ
void Input_list();//���
int main(void)
{
	Input_list();//���
		return 0;
}
//��ʼ��
void InitCreat(PSTACK pHead)
{

	pHead->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead->pTop)
	{
		printf("�����ڴ�ʧ��");
		exit(-1);
	}
	pHead->pBottom= pHead->pTop;//���ܵߵ�����ס
	pHead->pTop->pNext = NULL;
}
//��ջ
void Push(PSTACK pHead,int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("�����ڴ�ʧ��");
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = pHead->pTop;
	pHead->pTop  = pNew;

}
//��ջ
//����õ�ֵ���뵽��ַval�У��Ա���һ�������
void pop(PSTACK pHead, int *val)
{
	PNODE p = pHead->pTop;
	if (empty(pHead))
	{
		return;
	}
	else
	{
		*val= p->data;
		pHead->pTop = p->pNext;
		free(p);
		p = NULL;
		return;
	}
}
//����
void traverset(PSTACK pHead)
{
	PNODE p = pHead->pTop ;
	while (p != pHead->pBottom)
	{
		printf("%d", p->data);
		p = p->pNext;
	}
}
bool empty(PSTACK pHead)
{
	if (pHead->pTop == pHead->pBottom)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//��ս��
void clear(PSTACK pHead)
{
	if (empty(pHead))
	{
		return;
	}
	else
	{
		PNODE p = pHead->pTop;
		PNODE q = NULL;
		while (p != pHead->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pHead->pTop = pHead->pBottom;
	}
}
//���ú������
void Input_list()
{
	STACK S;//����һ����ͨ����  ע��Ϊʲô���ܶ���PSTACK S������ͨ����ǰ���ܼ�*
	int val;
	InitCreat(&S);//PSTACK pHead=STACK &S ָ������ܴ���ڴ��ַ
	scanf_s("%d", &val);
	//ʮ����תΪ�˽���
	while (val)
	{
		Push(&S, val%8);
		val = val / 8;
	}
	traverset(&S);
	printf("\n");
	while(!empty(&S))
	{
		pop(&S,&val);
		printf("��ջ�ɹ�����ջ��Ԫ��ʱ:%d\n",val);
	}
	clear(&S);//���
}
