//����ָ�뷽ʽ��д���򣺴Ӽ�������N������10�����������ݣ����������飬Ҫ��N��
�������������һ������������������С�������һ����������
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Arr
{
	int *pBase;//��������ĵ�һ��Ԫ�ص�ַ
	int len;//����ĳ���
	int cnt;//��ЧԪ�ظ���
}ARR,*pARR;
void init_arr(pARR pArr,int lenght);//��ʼ��
bool is_empty(pARR pArr);//�ж�����Ϊ��
bool is_full(pARR pArr);//�Ƿ����
bool append_arr(pARR pArr,int val);//�����ֵ
void show_arr(pARR pArr);//����
void val_arr(pARR pArr);//���Сֵ�ĵ���
int main(void)
{
	ARR arr;
	int N;
	int val;
	printf("���������鳤��");
	scanf("%d",&N);
	init_arr(&arr,N);
	for(int i=1;i<N+1;i++)
	{
	printf("�������%d������",i);
	scanf("%d",&val);
	append_arr(&arr,val);
	}
	show_arr(&arr);
	printf("��Сֵ������\n");
	val_arr(&arr);
	show_arr(&arr);
	return 0;
}
//��ʼ������
void init_arr(pARR pArr,int lenght)
{
	pArr->pBase=(int*)malloc(sizeof(int)*lenght);
	if(NULL==pArr->pBase )
	{
		printf("�����ڴ�ʧ��");
		exit(-1);
	}
	else
	{
		pArr->len=lenght;
		pArr->cnt =0;
	}
	return;
}
//�ж������Ƿ�Ϊ��
bool is_empty(pARR pArr)
{
	if(0==pArr->cnt)
	{
		return true;

	}
	else
	{
		return false;
	}
}
//�ж������Ƿ����
bool is_full(pARR pArr)
{
	if(pArr->cnt==pArr->len )
	{
		return true;
	}
	else
	{
		return false;
	}
}
//�������
void show_arr(pARR pArr)
{
	if(is_empty(pArr))
	{
		printf("����Ϊ��\n");
	}
	else
	{
		for (int i=0;i<pArr->cnt ;i++)
		{
		printf("%d ",pArr->pBase[i]);
		}
		printf("\n");
	}
	return;
}
//�����Чֵ
bool append_arr(pARR pArr,int val)
{
	if(is_full(pArr))
	{
		return false;
	}
	else
	{
		pArr->pBase[pArr->cnt]=val;
		pArr->cnt ++;
			return true;
	}

}
//�����Сֵ����
void val_arr(pARR pArr)
{
	int max=0,min=9999;
	int val,cnt,a,b;

	for(int i=0;i<pArr->cnt;i++)
	{
		if(pArr->pBase [i]>max)
		{
			max=pArr->pBase [i];
			cnt=i;
		}
		if(pArr->pBase [i]<min)
		{
			min=pArr->pBase [i];
			a=i;
		}
	}
	//���ֵ����
	val=pArr->pBase[0];
	pArr->pBase[0]=max;
	pArr->pBase [cnt]=val;
	//��Сֵ����
	val=pArr->pBase[(pArr->len)-1];
	pArr->pBase[(pArr->len)-1]=min;
	pArr->pBase[a]=val;
	return;
}

