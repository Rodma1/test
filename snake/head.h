#pragma once
#define x_pos 20
typedef int bool;//����bool���͵ı���
#define true 1
#define false 0
char myArray[20][42] = { "����������������������������������������\n",//һ����ռ�����ֽ�
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "��                                    ��\n",
							 "����������������������������������������\n" };
int arraySnake[x_pos][3] = { 0 };
enum { East = 2, South = 1, West = -2, North =- 1 };//ö�ٷ���
int snakeDir = West;
int g_Nx ,g_Ny ;//��������
bool g_proFood = true;
int g_x = 2;//�����߳����ȫ�ֱ���
int g_score = 0;//�����������