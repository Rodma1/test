//д���벽�裺1.��ʼ��init 2.�ж����empty 3.�ж��Ƿ����full 4.���show 5.׷��append 6.����insert 7.ɾ��delete 8.����inversion 9.����short
#include<stdio.h>
#include<malloc.h>//����malloc()��
#include<stdlib.h>//����exit()��
struct Arr
{
	int *pBase;//��������ĵ�һ��Ԫ�ص�ַ
	int len;//�����������ɵ����Ԫ�ظ���
	int cnt;//��ǰ�������ЧԪ�ظ���
};
void init_arr(struct Arr *pArr,int length);//��ʼ��
void show_arr(struct Arr *pArr);//���ֵ
void inversion_arr(struct Arr * pArr);//����
void sort_arr(struct Arr * pArr);//����
bool append_arr(struct Arr *pArr,int val);//׷�ӵ�Ԫ��
bool is_empty(struct Arr *pArr);//�������ͣ��ж����
bool is_full(struct Arr *pArr);
bool insert_arr(struct Arr *pArr,int pos,int val);//����
bool delet_arr(struct Arr *pArr,int pos,int *pVal);
int main(void)
{
	struct Arr arr;//����һ���ṹ
	int val;
    init_arr(&arr,6);//��ʼ������
	show_arr(&arr);//�������
	append_arr(&arr, 1);
	append_arr(&arr, 10);
	append_arr(&arr, -3);
	append_arr(&arr, 6);
	append_arr(&arr, 88);
	//append_arr(&arr, 11);
	show_arr(&arr);
	insert_arr(&arr,3,4);
	show_arr(&arr);
	//delet_arr(&arr,3, &val);
	if ( delet_arr(&arr, 3, &val) )
	{
		printf("ɾ���ɹ�!\n");
		printf("ɾ����Ԫ����: %d\n", val);
	}
	else
	{
		printf("ɾ��ʧ��!\n");
	}
	show_arr(&arr);
	inversion_arr(&arr);
	printf("����֮�������������:\n");
	show_arr(&arr);
	sort_arr(&arr);
	printf("���������������:\n");
	show_arr(&arr);
	return 0;
}
void init_arr(struct Arr *pArr,int length){
	pArr->pBase=(int*)malloc(sizeof(int)*length);//�õ�pBase�ķ����ڴ�ռ�
	if(NULL==pArr->pBase){
		printf("��̬�����ڴ�ʧ��\n");
		exit(-1);//��ֹ��������
	}else{
		pArr->len=length;
		pArr->cnt=0;
	}
	return;
}
bool is_empty(struct Arr *pArr){//�ж��Ƿ�Ϊ0
	if(0==pArr->cnt){
		return true;
	}else{
		return false;
	}
}
bool is_full(struct Arr *pArr){
	if(pArr->cnt==pArr->len){
		return true;
	}else{
		return false;
	}
}
void show_arr(struct Arr *pArr){
	if(is_empty(pArr)){//ע�⣺����д&pArr����Ϊ�Ѿ�����ַ&arr��ֵ����pArr
		printf("����Ϊ��\n");
	}
	else{
		for(int i=0;i<pArr->cnt;i++){
			printf("%d  ", pArr->pBase[i]); //int *
		}
		printf("\n");
	}
}
bool append_arr(struct Arr *pArr,int val){//val��ʾ�����ֵ
	if(is_full(pArr)){
		return false;
	}else{
		pArr->pBase[pArr->cnt]=val;
		(pArr->cnt)++;
		return true;
	}
}
bool insert_arr(struct Arr *pArr,int pos,int val){//posֵ����Ҫ�����λ�ã�����˵pos=3����ô���ǲ��뵽pArr->pBase[2];
	if(is_full(pArr)) return false;
	else if(pos<1||pos>pArr->cnt+1) return false;
	else{
	for(int i=pArr->cnt-1;i>=pos-1;i--){//ע�ⲻҪ©�����ڣ��У�p[3]=p[2];
		pArr->pBase[i+1]=pArr->pBase[i];//��Ϊcnt��ʾ��ЧԪ�ظ�����i+1��ָ�������������
	}
	pArr->pBase[pos-1]=val;
	(pArr->cnt)++;
	return true;
	}
}
bool delet_arr(struct Arr *pArr,int pos,int * pVal){
	if(is_empty(pArr)) return false;
	if(pos<1||pos>pArr->cnt) return false;
	*pVal=pArr->pBase[pos-1];//�ѵȴ�ɾ����Ԫ�ظ�ֵ�����β�*pValָ����������val
	for(int i=pos-1;i<pArr->cnt;i++){
		pArr->pBase[i]=pArr->pBase[i+1];
	}
	pArr->cnt--;
	return true;
}
void inversion_arr(struct Arr * pArr)
{
	int i = 0;
	int j = pArr->cnt-1;
	int t;

	while (i < j)
	{
		t = pArr->pBase[i];//�ǣ�t=a,a=b,b=t������
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
	return;
}

void sort_arr(struct Arr * pArr)
{
	int i, j, t;

	for (i=0; i<pArr->cnt; ++i)
	{
		for (j=i+1; j<pArr->cnt; ++j)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
}

