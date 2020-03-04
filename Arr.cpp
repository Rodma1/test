//写代码步骤：1.初始化init 2.判断真假empty 3.判断是否溢出full 4.输出show 5.追加append 6.插入insert 7.删除delete 8.倒置inversion 9.排序short
#include<stdio.h>
#include<malloc.h>//包含malloc()类
#include<stdlib.h>//包含exit()类
struct Arr
{
	int *pBase;//储存数组的第一个元素地址
	int len;//数组所能容纳的最大元素个数
	int cnt;//当前数组的有效元素个数
};
void init_arr(struct Arr *pArr,int length);//初始化
void show_arr(struct Arr *pArr);//输出值
void inversion_arr(struct Arr * pArr);//倒序
void sort_arr(struct Arr * pArr);//排序
bool append_arr(struct Arr *pArr,int val);//追加的元素
bool is_empty(struct Arr *pArr);//布尔类型，判断真假
bool is_full(struct Arr *pArr);
bool insert_arr(struct Arr *pArr,int pos,int val);//插入
bool delet_arr(struct Arr *pArr,int pos,int *pVal);
int main(void)
{
	struct Arr arr;//定义一个结构
	int val;
    init_arr(&arr,6);//初始化变量
	show_arr(&arr);//输出变量
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
		printf("删除成功!\n");
		printf("删除的元素是: %d\n", val);
	}
	else
	{
		printf("删除失败!\n");
	}
	show_arr(&arr);
	inversion_arr(&arr);
	printf("倒置之后的数组内容是:\n");
	show_arr(&arr);
	sort_arr(&arr);
	printf("排序后数组内容是:\n");
	show_arr(&arr);
	return 0;
}
void init_arr(struct Arr *pArr,int length){
	pArr->pBase=(int*)malloc(sizeof(int)*length);//得到pBase的分配内存空间
	if(NULL==pArr->pBase){
		printf("动态分配内存失败\n");
		exit(-1);//终止程序运行
	}else{
		pArr->len=length;
		pArr->cnt=0;
	}
	return;
}
bool is_empty(struct Arr *pArr){//判断是否为0
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
	if(is_empty(pArr)){//注意：不能写&pArr，因为已经将地址&arr赋值给了pArr
		printf("数组为空\n");
	}
	else{
		for(int i=0;i<pArr->cnt;i++){
			printf("%d  ", pArr->pBase[i]); //int *
		}
		printf("\n");
	}
}
bool append_arr(struct Arr *pArr,int val){//val表示输入的值
	if(is_full(pArr)){
		return false;
	}else{
		pArr->pBase[pArr->cnt]=val;
		(pArr->cnt)++;
		return true;
	}
}
bool insert_arr(struct Arr *pArr,int pos,int val){//pos值得是要插入的位置，不如说pos=3，那么就是插入到pArr->pBase[2];
	if(is_full(pArr)) return false;
	else if(pos<1||pos>pArr->cnt+1) return false;
	else{
	for(int i=pArr->cnt-1;i>=pos-1;i--){//注意不要漏掉等于，列：p[3]=p[2];
		pArr->pBase[i+1]=pArr->pBase[i];//因为cnt表示有效元素个数，i+1是指向第六个空数组
	}
	pArr->pBase[pos-1]=val;
	(pArr->cnt)++;
	return true;
	}
}
bool delet_arr(struct Arr *pArr,int pos,int * pVal){
	if(is_empty(pArr)) return false;
	if(pos<1||pos>pArr->cnt) return false;
	*pVal=pArr->pBase[pos-1];//把等待删除的元素赋值给了形参*pVal指向主函数的val
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
		t = pArr->pBase[i];//记：t=a,a=b,b=t简单排序
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

