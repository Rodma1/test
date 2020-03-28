//①用指针方式编写程序：从键盘输入N（比如10）个整形数据，并存入数组，要求将N个
数中最大的数与第一个数交换；将其中最小的数最后一个数交换。
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct Arr
{
	int *pBase;//储存数组的第一个元素地址
	int len;//数组的长度
	int cnt;//有效元素个数
}ARR,*pARR;
void init_arr(pARR pArr,int lenght);//初始化
bool is_empty(pARR pArr);//判断数组为空
bool is_full(pARR pArr);//是否溢出
bool append_arr(pARR pArr,int val);//添加数值
void show_arr(pARR pArr);//遍历
void val_arr(pARR pArr);//最大小值的调换
int main(void)
{
	ARR arr;
	int N;
	int val;
	printf("请输入数组长度");
	scanf("%d",&N);
	init_arr(&arr,N);
	for(int i=1;i<N+1;i++)
	{
	printf("请输入第%d个数：",i);
	scanf("%d",&val);
	append_arr(&arr,val);
	}
	show_arr(&arr);
	printf("大小值调换后\n");
	val_arr(&arr);
	show_arr(&arr);
	return 0;
}
//初始化数组
void init_arr(pARR pArr,int lenght)
{
	pArr->pBase=(int*)malloc(sizeof(int)*lenght);
	if(NULL==pArr->pBase )
	{
		printf("分配内存失败");
		exit(-1);
	}
	else
	{
		pArr->len=lenght;
		pArr->cnt =0;
	}
	return;
}
//判断数组是否为空
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
//判断数组是否溢出
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
//遍历输出
void show_arr(pARR pArr)
{
	if(is_empty(pArr))
	{
		printf("数组为空\n");
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
//添加有效值
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
//最大最小值调换
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
	//最大值调换
	val=pArr->pBase[0];
	pArr->pBase[0]=max;
	pArr->pBase [cnt]=val;
	//最小值调换
	val=pArr->pBase[(pArr->len)-1];
	pArr->pBase[(pArr->len)-1]=min;
	pArr->pBase[a]=val;
	return;
}

