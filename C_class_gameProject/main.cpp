#include <stdio.h>
#include<conio.h>
#include <graphics.h>
#include<stdlib.h>
#include <time.h>

//定义游戏的基本操作
#define ROW 29 //游戏区行数
#define COL 29 //游戏区列数
#define DOWN 80 //方向键：下
#define LEFT 75 //方向键：左
#define RIGHT 77 //方向键：右

#define SPACE 32 //空格键
#define ESC 27 //Esc键

struct Face		//全局的位置结构
{
	unsigned char data[ROW][COL];		//位置信息
 //	COLORREF color[ROW][COL][1];	//在每个方块的位置存储RGB颜色信息		
}face;

struct Block		//方块结构
{
	unsigned char space[4][4];
}block[7][4]; //一个方块由4x4的方块空间组成，一共有7种方块，每个方块有4个旋转角度


//初始化界面
void InitInterface();
//初始化方块信息
void InitBlockInfo();
//画出方块
void DrawBlock(int shape, int form, int x, int y);
//清除方块
void DrawSpace(int shape, int form, int x, int y);
//合法性判断
int IsLegal(int shape, int form, int x, int y);
//判断得分与结束
int JudeFunc();
//游戏主体逻辑函数
void StartGame();
//游戏结束
void GameOver();
//从文件读取最高分
void ReadGrade();
//更新最高分到文件
void WriteGrade();

int max,grade; // 定义全局变量

int main()
{
	max = 0, grade = 0; //初始化变量
	InitInterface();
	InitBlockInfo(); //初始化方块信息
	StartGame();

}


void showShape(int x, int y)//用于显示单个方块
{
	solidrectangle(3 + (20 * x), 3 + (20 * y), 20 + (20 * x), 20 + (20 * y));
}

void textInit(char x, char y, char a, char b, LPCTSTR s)
{
	RECT r = { 3 + 20 * (x + a), 3 + 20 * (y), 20 + 20 * (x + b), 20 + 20 * (y + b) };
	drawtext(s, &r, DT_LEFT);
}

//初始化界面
void InitInterface()
{
		unsigned char x, y;
		initgraph(10 + 20 * ROW, 10 + 20 * COL);
		setbkcolor(RGB(255, 255, 255));
		cleardevice();

		//初始化游戏操作框架界面
		setfillcolor(RGB(0, 0, 0));
		for (x = 0; x < ROW; x++)		//画出框架
		{
			for (y = 0; y < COL; y++)
			{
				if (x == 0 || x == 18 || x == 28 || y == COL - 1 || (y == 8 && x > 18 && x < 28))
				{
					showShape(x, y);
					/*
					 这里的y和x的位置对应了显示时的初始化顺序
					 初始化时，x不变，绘制y轴，在二维数组上，就是一位数组一直在递增，然后输入数据给
					一位数组中的第x个数组，所以才需要这样的初始化顺序
					*/ 
					face.data[y][x] = 1;
				}
				else { face.data[y][x] = 0; }

				//列出提示
				settextcolor(RGB(0, 0, 0));
				if (x == 19)
				{
					if (y == 1)
					{
						textInit(x, y, 0, 6, _T("下一个方块是:"));
					}
					else if (y == 10)
					{
						textInit(x, y, 2, 5, _T("左移：←"));
					}
					else if (y == 12)
					{
						textInit(x, y, 2, 5, _T("右移：→"));
					}
					else if (y == 14)
					{
						textInit(x, y, 2, 5, _T("加速：↓"));
					}
					else if (y == 16)
					{
						textInit(x, y, 2, 7, _T("旋转：空格"));
					}
					else if (y == 18)
					{
						textInit(x, y, 2, 7, _T("暂停: S"));
					}

					else if (y == 20)
					{
						textInit(x, y, 2, 7, _T("退出: Esc"));
					}
					else if (y == 22)
					{
						textInit(x, y, 2, 8, _T("重新开始:R"));
					}
					///*else if (y == 24)
					//{
					//	textInit(x, y, 2, 8, _T("最高纪录:"));
					//}
					//else if (y == 26)
					//{
					//	textInit(x, y, 2, 8, _T("最高纪录:"));*/
					//}
				}

			}
		}
	}

//初始化方块信息
void InitBlockInfo()
{
	//“T”形
	for (int i = 0; i <= 2; i++)
		block[0][0].space[1][i] = 1;
	block[0][0].space[2][1] = 1;

	//“L”形
	for (int i = 1; i <= 3; i++)
		block[1][0].space[i][1] = 1;
	block[1][0].space[3][2] = 1;

	//“J”形
	for (int i = 1; i <= 3; i++)
		block[2][0].space[i][2] = 1;
	block[2][0].space[3][1] = 1;

	for (int i = 0; i <= 1; i++)
	{
		//“Z”形
		block[3][0].space[1][i] = 1;
		block[3][0].space[2][i + 1] = 1;
		//“S”形
		block[4][0].space[1][i + 1] = 1;
		block[4][0].space[2][i] = 1;
		//“O”形
		block[5][0].space[1][i + 1] = 1;
		block[5][0].space[2][i + 1] = 1;
	}
	//“I”形
	for (int i = 0; i <= 3; i++)
		block[6][0].space[i][1] = 1;
	//!!
	//用顺时针90度旋转矩阵算法建立出各个形态的方块模型   算法主要是a[i][j]旋转后的公式是a[3-j][i]
	int temp[4][4];
	for (int shape = 0; shape < 7; shape++) //7种形状
	{
		for (int form = 0; form < 3; form++) //4种形态（已经有了一种，这里每个还需增加3种）
		{
			//获取第form种形态
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					temp[i][j] = block[shape][form].space[i][j];
				}
			}
			//将第form种形态顺时针旋转，得到第form+1种形态
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					block[shape][form + 1].space[i][j] = temp[3 - j][i];
				}
			}
		}
	}
}

//用于判断方块在下一个状态是否合法，如果可以返回1否则返回0
int IsLegal(int shape, int form, int x, int y)
{
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				//如果方块落下的位置本来就已经有方块了，则不合法
				if ((block[shape][form].space[j][i] == 1) && (face.data[y + i][x + j] == 1))
					return 0; //不合法
			}
		}
		return 1; //合法
	}
}


int JudeFunc()
{

	//for (int x = 0; x < COL; x++)		//画出框架
	//{
	//	for (int y = 0; y < ROW; y++)
	//	{
	//		printf("%d", face.data[x][y]);
	//	}
	//	printf("\n");
	//}
	for (int i = ROW - 2; i > 0; i--)
	{
		//方块消除的代码和计分部分
		int sum = 0;			//用于计算是否是完整的一行
		for (int j = 1; j < 18; j++)		//从i行自下往上进行计算比较
		{
			sum += face.data[i][j];
		}
		if (sum == 0) //该行没有方块，无需再判断其上的层次（无需再继续判断是否得分）
			break; //跳出循环
		if (sum == 17)
		{
			for (int j = 1; j < 18; j++)		//这一行的数据先进行归零
			{
				face.data[i][j] = 0;
			}
			for (int m = i; m > 1; m--)			//从满的这一行的开始操作
			{
				sum = 0; //记录上一行的方块个数
				for (int n = 1; n < 18; n++)
				{
					sum += face.data[m - 1][n]; //统计上一行的方块个数
					face.data[m][n] = face.data[m - 1][n]; //将上一行方块的标识移到下一行
					if (face.data[m][n] == 1) //上一行移下来的是方块，打印方块
					{
						setfillcolor(RGB(0,0,0));
						showShape(n,m);
					}
					else //上一行移下来的是空格，打印空格
					{
						setfillcolor(RGB(255, 255, 255));
						showShape(n, m);
					}
				}
			}

				if (sum == 0) //上一行移下来的全是空格，无需再将上层的方块向下移动（移动结束）
				return 1; //返回1，表示还需调用该函数进行判断（移动下来的可能还有满行）
		}
	}
	int sum = 0;		//用于计算最上面一层是否有方块
	for (int j = 1; j < 18; j++)
	{
		sum += face.data[2][j];
	}
	if (sum)	//如果最上层有方块，结束游戏进行结算
	{
		GameOver();
	}
	return 0;
}



void DrawBlock(int shape,int from, int x, int y)		//用于在指定位置绘制方块模型
{
	setfillcolor(RGB(0, 0, 0));
	for (int i = 0; i < 4 ; i++)
	{
		for (int j = 0; j < 4 ; j++)
		{
			if (block[shape][from].space[i][j] == 1)
				showShape(x+i, y+j);
		}
	}
}
void DrawSpace(int shape, int from, int x, int y)		//用于在指定位置绘制白色方块模型
{
	setfillcolor(RGB(255, 255, 255));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[shape][from].space[i][j] == 1)
				showShape(x + i, y + j);
		}
	}
}

void recodBlock(int shape, int form, int x, int y)			//将模型的位置信息写入到全局位置的对应data中
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (block[shape][form].space[i][j] == 1)
			{
				face.data[y + j][x + i] = block[shape][form].space[i][j];
			}
		}
	}
}
void StartGame()
{
	srand((unsigned int)time(NULL)); //设置随机数生成的起点
	int shape = rand() % 7, form = rand() % 4; //随机获取第一次方块的形状和形态
	while (1)
	{
		int t = 0;//初始化时间
		int nextShape = rand() % 7, nextForm = rand() % 4; //随机获取下一个方块的形状和形态
		int x = 9, y = 0; //方块初始下落位置的横纵坐标
		DrawBlock(nextShape, nextForm, 22, 2); //将该方块显示在初始下落位置
		//操作和主体逻辑
		while (1)
		{
			DrawBlock(shape, form, x, y); //将该方块显示在初始下落位置
			if (t == 0)
				t = 15000;				//下降速度，如果越小下降速度y
			while (--t)
			{
				if (_kbhit() != 0) //若键盘被敲击, 则退出循环
					break;
			}
			if (t == 0)				//键盘没有被敲击的情况
			{
				if (!IsLegal(shape, form, x, y + 1))		//如果下一个下落的位置不合法
				{
					//将当前方块的信息录入face当中
					recodBlock(shape,form,x,y);
					while(JudeFunc());				//判断是否是满的，如果一行满了消除
					break;
				} 
				else  //未到达底部
				{
					DrawSpace(shape, form, x, y); //用空格覆盖当前方块所在位置
					y++; //纵坐标自增（下一次显示方块时就相当于下落了一格了）
				}
			}
			else	//有被敲击键盘
			{
				//gameControl(shape, form, x, y);   
				//不能放在函数里面是因为形参按照值传递
				//控制部分
				if (_kbhit()) // 检测键盘输入
				{
					char key = _getch(); // 获取按键

					switch (key)
					{
					case DOWN: //方向键：下
						if (IsLegal(shape, form, x, y + 1) == 1) //判断方块向下移动一位后是否合法
						{
							//方块下落后合法才进行以下操作
							DrawSpace(shape, form, x, y); //用空格覆盖当前方块所在位置
							y++; //纵坐标自增（下一次显示方块时就相当于下落了一格了）
						}
						break;
					case LEFT: //方向键：左
						if (IsLegal(shape, form, x - 1, y) == 1) //判断方块向左移动一位后是否合法
						{
							//方块左移后合法才进行以下操作
							DrawSpace(shape, form, x, y); //用空格覆盖当前方块所在位置
							x--; //横坐标自减（下一次显示方块时就相当于左移了一格了）
						}
						break;
					case RIGHT: //方向键：右
						
						if (IsLegal(shape, form, x + 1, y) == 1) //判断方块向右移动一位后是否合法
						{
							//方块右移后合法才进行以下操作
							DrawSpace(shape, form, x, y); //用空格覆盖当前方块所在位置
							x++; //横坐标自增（下一次显示方块时就相当于右移了一格了）
						}
						break;
					case SPACE: //空格键
						if (IsLegal(shape, (form + 1) % 4, x, y + 1) == 1) //判断方块旋转后是否合法
						{
							//方块旋转后合法才进行以下操作
							DrawSpace(shape, form, x, y); //用空格覆盖当前方块所在位置
							y++; //纵坐标自增（总不能原地旋转吧）
							form = (form + 1) % 4; //方块的形态自增（下一次显示方块时就相当于旋转了）
						}
						break;
						//case ESC: //Esc键
						//	system("cls"); //清空屏幕
						//	color(7);
						//	CursorJump(COL, ROW / 2);
						//	printf("  游戏结束  ");
						//	CursorJump(COL, ROW / 2 + 2);
						//	exit(0); //结束程序
					case 's':
					case 'S':  //暂停
						system("pause>nul"); //暂停（按任意键继续）
						break;
					case 'r':
					case 'R': //重新开始
						system("cls"); //清空屏幕
						main(); //重新执行主函数
					}
				}
			}
		}
		shape = nextShape, form = nextForm; //获取下一个方块的信息
		DrawSpace(nextShape, nextForm, 22, 2); //将右上角的方块信息用空格覆盖
	}
}

void GameOver()
{
//	printf("进入");
	setbkcolor(RGB(255, 165, 0));
	cleardevice();
	RECT r = { 0,0,10 + 20 * ROW, 10 + 20 * COL };
	drawtext(_T("Game Over"), &r, DT_CENTER);
	 r = { 50,50,10 + 20 * ROW-50, 10 + 20 * COL-50 };
	drawtext(_T("按R重新开始游戏"), &r, DT_CENTER);
	while (1) {
		if (_kbhit()) // 检测键盘输入
		{
			char key = _getch(); // 获取按键

			switch (key)
			{
			case 'r':
			case 'R': //重新开始
				system("cls"); //清空屏幕
				main(); //重新执行主函数
			}
		}
	}
}