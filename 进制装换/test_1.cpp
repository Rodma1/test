#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//1.初始化 2入栈 3.出栈 4.遍历 5.while循环输出
typedef struct Node
{
	int data;//数据域
	struct Node *pNext;//指针域
}NODE,*PNODE;
typedef struct Stack
{
	PNODE pTop;//头节点
	PNODE pBottom;//尾节点
}STACK,*PSTACK;

void InitCreat(PSTACK pHead);//初始化
void Push(PSTACK pHead, int val);//入栈
void traverset(PSTACK pHead);//遍历
void pop(PSTACK pHead, int *val);//出栈
bool empty(PSTACK pHead);//判断是否为空
void clear(PSTACK pHead);//清空栈
void Input_list();//输出
int main(void)
{
	Input_list();//输出
		return 0;
}
//初始化
void InitCreat(PSTACK pHead)
{

	pHead->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead->pTop)
	{
		printf("分配内存失败");
		exit(-1);
	}
	pHead->pBottom= pHead->pTop;//不能颠倒，记住
	pHead->pTop->pNext = NULL;
}
//入栈
void Push(PSTACK pHead,int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("分配内存失败");
		exit(-1);
	}
	pNew->data = val;
	pNew->pNext = pHead->pTop;
	pHead->pTop  = pNew;

}
//出栈
//将获得的值存入到地址val中，以便于一个个输出
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
//遍历
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
//清空结点
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
//调用函数输出
void Input_list()
{
	STACK S;//定义一个普通变量  注：为什么不能定义PSTACK S。答：普通变量前不能加*
	int val;
	InitCreat(&S);//PSTACK pHead=STACK &S 指针变量能存放内存地址
	scanf_s("%d", &val);
	//十进制转为八进制
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
		printf("出栈成功，出栈的元素时:%d\n",val);
	}
	clear(&S);//输出
}
