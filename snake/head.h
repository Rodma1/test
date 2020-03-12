#pragma once
#define x_pos 20
typedef int bool;//定义bool类型的变量
#define true 1
#define false 0
char myArray[20][42] = { "■■■■■■■■■■■■■■■■■■■■\n",//一个■占用两字节
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■                                    ■\n",
							 "■■■■■■■■■■■■■■■■■■■■\n" };
int arraySnake[x_pos][3] = { 0 };
enum { East = 2, South = 1, West = -2, North =- 1 };//枚举方向
int snakeDir = West;
int g_Nx ,g_Ny ;//设置坐标
bool g_proFood = true;
int g_x = 2;//定义蛇长大的全局变量
int g_score = 0;//定义分数变量