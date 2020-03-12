#include<stdio.h>
#include<stdlib.h>
#include<conio.h>//_getch头文件
#include <time.h>
#include"head.h"
#include<windows.h>
#include<mmsystem.h>//音频头文件
#pragma comment(lib, "WINMM.LIB")//音频必加
#pragma warning (disable : 4996)//strncpy不安全，得加上
void one_interface();//初始界面
void myPlaySound();//音频
void _space();//点击空格键进入游戏界面
void stop_MyPlaySound();//停止播放
void two_interface();//游戏界面
void set_snakePos();//设置蛇得坐标
void set_snake();//画蛇
void set_snakeRun();//蛇动
void delete_ophiurid();//消去蛇尾
void set_direction();//设置🐍得按键方向
bool set_snakeDead();//蛇撞墙死亡
void set_snakeFood();//设置食物
void set_snakeUp();//蛇吃食物长大
void set_score();//设置分数
int main(void)
{
	one_interface();
	myPlaySound();
	_space();
	system("cls");//清屏
	printf("\t\t\t\t\t\t欢迎进入游戏\n");
	Sleep(2000);
	stop_MyPlaySound();// 先消去再跑，顺序不能乱
	set_snakePos();//这个函数必须放在界面上面才能显示
	
	while (1)
	{
		system("cls");
		
		set_snakeFood();//产生食物
		set_snakeUp();//蛇变长
		if (false == set_snakeDead())//蛇死亡
		{
			printf("snake dead");
			break;
		}
		set_snakeRun();//蛇跑
		two_interface();//游戏界面
		set_score();//得分
		Sleep(500);
		
	}
	system("pause");
	return 0;
}
void one_interface() {
	printf("\n\n\n");
	printf("\t\t\t\t\t\t--------------------\n");
	printf("\n");
	printf("\t\t\t\t\t\t欢迎来到贪吃蛇游戏\n");
	printf("\n");
	printf("\t\t\t\t\t\t请按下空格进入游戏\n");
	printf("\n");
	printf("   \t\t\t\t\t      根据 w a s d方向键控制\n");
	printf("--------------------------------------------------------------------------------------------------------------\n");
}
//音乐
void myPlaySound()
{
	PlaySound("1.wav", NULL, SND_FILENAME | SND_ASYNC);
}
//空格跳转
void _space()
{
	while (1)
	{
		char charSpace;
		charSpace = _getch();//输入自动读进charSpace
		if (' ' == charSpace)
		{
			break;
		}
	}

}
//停止播放
void stop_MyPlaySound()
{ 
	PlaySound( NULL,0,0);
}
//游戏边框
void two_interface()
{
	int i = 0;
		for (i = 0;i < 20; i++)
		{
			printf(myArray[i]);
		}
}
//蛇的坐标
void set_snakePos()
{
	int x=-1,y=-1;//设置坐标
	srand((unsigned int)time (NULL));//获得随机数
	x = rand() % 14+3;
	y = rand() % 14+3;
	//设置🐍的数组
	arraySnake[0][0] = y;//行
	arraySnake[0][1] = x*2;//列
	arraySnake[0][2] = West;
	//蛇头
	arraySnake[1][0] = y;
	arraySnake[1][1] = x*2+2;
	arraySnake[1][2] = West;
	//蛇身
	arraySnake[2][0] = y;
	arraySnake[2][1] = x*2+4;
	arraySnake[2][2] = West;
	//蛇尾
	set_snake();
}
//蛇身
void set_snake()
{
	for (int i = 0; arraySnake[i][0] != 0; i++)
	{
		strncpy(&myArray[arraySnake[i][0]][arraySnake[i][1]], "◆",2 );//拷贝
	}
}
//蛇跑
void set_snakeRun()
{
	int i = x_pos - 1;
	set_direction();
	delete_ophiurid();//删除原来的蛇
	
	for (i;i>=1;i--)
	{
		//过滤掉非法🐍
		if (0 == arraySnake[i][1])
		{
			continue;
		}
		//把前一个结点的值，赋值给当前结点
		arraySnake[i][0] = arraySnake[i-1][0];//行
		arraySnake[i][1] = arraySnake[i-1][1];//列
		arraySnake[i][2] = arraySnake[i-1][2];//方向
	}
	//初始向西移动
	arraySnake[0][2] = snakeDir;
	if (West== arraySnake[0][2]||East== arraySnake[0][2])
	{
		arraySnake[0][1] += arraySnake[0][2];//列加二或减二
	}
	else
	{
		arraySnake[0][0] += arraySnake[0][2];//行加二或减二
	}
	set_snake();
	
}
//消除尾节点
void delete_ophiurid()
{
	for (int i = 0; arraySnake[i][0] != 0; i++)
	{
		strncpy(&myArray[arraySnake[i][0]][arraySnake[i][1]], "  ", 2);//空两格，因为正方体是占两个节点
	}
}
//按键移动
//bug：每次蛇头到接近边框边界的前一个节点时时就移动不了
void set_direction()
{
	//_getch同步检测：必须得输入才能运行，每次循环都得输入
	if (GetAsyncKeyState('W'))//异步检测：如果输入字母就改变阿，不输入就跳过这个函数🐍继续动
	{
		if (South != arraySnake[0][2])//如果蛇头不向南移动，才可以点击s键向北，否则无效
		{
			snakeDir = North;
		}
	}
	else if (GetAsyncKeyState('A'))
	{
		if (East != arraySnake[0][2])
		{
			snakeDir = West;
		}
	}
	else if (GetAsyncKeyState('S'))
	{
		if (North != arraySnake[0][2])
		{
			snakeDir = South;
		}
	}
	else if (GetAsyncKeyState('D'))
	{
		if (West != arraySnake[0][2])
		{
			snakeDir = East;
		}
	}
}
//这里有一个bug：吃自己有时候死不了，有时候可以(好像是有两条命，等撞自己两次才死，哈哈)
bool set_snakeDead()
{
	
	if (East == arraySnake[0][2] || West == arraySnake[0][2])
	{
		if ( 0 == strncmp(&myArray[arraySnake[0][0]][arraySnake[0][1] + arraySnake[0][2]], "■", 2))
		{
			return false;
		}
		else if(0 == strncmp(&myArray[arraySnake[0][0] + arraySnake[0][2]][arraySnake[0][1]], "◆", 2))
		{
			return false;
		}
	}
	else
	{
		if ( 0 == strncmp(&myArray[arraySnake[0][0] + arraySnake[0][2]][arraySnake[0][1]], "■", 2))
		{
			return false;
		}
		else if (0 == strncmp(&myArray[arraySnake[0][0] + arraySnake[0][2]][arraySnake[0][1]], "◆", 2) )
		{
			return false;
		}
	}
	return true;

}
//食物
void set_snakeFood()
{
	//如果有食物就返回，没有点添加食物
	if (false == g_proFood)
	{
		return ;
	}
	//设置坐标
	srand((unsigned int)time(NULL));//获得随机数
	g_Nx = rand() % 16 +2;
	g_Ny = rand() % 16 + 2;
	bool a_pos = true;
	while (1)
	{
		for (int i = 0; arraySnake[i][0] != 0; i++)
		{
			if (g_Nx * 2 == arraySnake[i][1] &&g_Ny == arraySnake[i][0])
			{
				a_pos = false;
			}
		}
		if (true == a_pos)
		{
			break;
		}
	}
	strncpy(&myArray[g_Ny][g_Nx*2], "●", 2);//不要忘记乘二，卡在这里好久了
	//添加食物后变成false
	g_proFood = false;
}
//蛇长大
void set_snakeUp()
{
	
	//如果蛇头和食物坐标相同1。蛇增长
	if (g_Nx*2 == arraySnake[0][1] && g_Ny == arraySnake[0][0])
	{
		//蛇长大
		/*不明白的地方：为什么arraySnake[g_x][0];
							  arraySnake[g_x][0]-2;
							  arraySnake[g_x][0];这也能编译出来*/
		if (East==arraySnake[g_x][2])
		{
			arraySnake[g_x+1][0] = arraySnake[g_x][0];//行
			arraySnake[g_x+1][1] = arraySnake[g_x][1]-2;//列
			arraySnake[g_x+1][2] = arraySnake[g_x][2];//方向
		}
		else if (West == arraySnake[g_x][2])
		{
			arraySnake[g_x + 1][0] = arraySnake[g_x][0];//行
			arraySnake[g_x + 1][1] = arraySnake[g_x][1] + 2;//列
			arraySnake[g_x + 1][2] = arraySnake[g_x][2];//方向
		}
		else if (South == arraySnake[g_x][2])
		{
			arraySnake[g_x + 1][0] = arraySnake[g_x][0]+1;//行
			arraySnake[g_x + 1][1] = arraySnake[g_x][1];//列
			arraySnake[g_x + 1][2] = arraySnake[g_x][2];//方向
		}
		else if (North == arraySnake[g_x][2])
		{
			arraySnake[g_x + 1][0] = arraySnake[g_x][0]-1;//行
			arraySnake[g_x + 1][1] = arraySnake[g_x][1] ;//列
			arraySnake[g_x + 1][2] = arraySnake[g_x][2];//方向
		}
		g_x++;
		//如果蛇吃了食物就没有食物了，返回true给set_snakeFood()添加食物
		g_proFood = true;
		g_score++;
	}
}
//设置分数
void set_score()
{
	COORD rd;
	rd.X = 45;
	rd.Y = 2;
	//设置位置
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),rd);
	//打印
	printf("score\n");
	rd.X = 47;
	rd.Y = 4;
	//设置位置
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rd);
	//打印
	printf("%d\n",g_score);
}