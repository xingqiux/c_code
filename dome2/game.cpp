#include <graphics.h>	
#include <conio.h>
#include <stdio.h>
#include <stdbool.h>
#define ALLSHALL  20
bool flag_game = true;  //游戏设置为开始

void game_draw();
void game_init();
void crash(int i);
void scene_shall();
void keycontrol();
void mousecontrol();            

struct Shall {                 //需要摧毁的陨石和炮弹
	int x, y, r =5;
	int speed = 5;
	bool iscrash = false;
	POINT coor[ALLSHALL];
}shall;

struct Airplane {              //角色飞机
	int x, y;
	int blood = 100;
	POINT plane;
}airplane;


int main()
{
	game_init();
	game_draw();

	while (flag_game)
	{
		scene_shall();
		keycontrol();
		game_draw();
	}
}

void game_init()           //游戏的初始化
{
	initgraph(800, 600);

	srand(GetTickCount());
	for (int i = 0; i <ALLSHALL; i++)
	{
		shall.coor[i].x = rand() % 801;
		shall.coor[i].y = -(rand()%601);
	}
	airplane.x = 0;
	airplane.y = 0;
}

void game_draw()                     //游戏画面的展示
{
	BeginBatchDraw();
	setbkcolor(RGB(277,230,195));                //背景
	cleardevice();
	setfillcolor(RGB(209, 73, 78));              //飞机模型
	fillrectangle(350+airplane.x,580+airplane.y,450+airplane.x,600+airplane.y);
	setfillcolor(RGB(230,155,3));                 //飞来的陨石          
	for (int i = 0; i < ALLSHALL; i++)
	{
		solidcircle(shall.coor[i].x,shall.coor[i].y,shall.r);
	}
	EndBatchDraw();

}

void scene_shall()
//控制场景的陨石移动和判定
{
	for (int i = 0; i < ALLSHALL; i++)
	{
		shall.coor[i].y++;
		crash(i);
		if (shall.iscrash)
		{
			shall.coor[i].y = -(rand() % 601);
			shall.iscrash = false;
		}
	}
	Sleep(shall.speed);
	
}


void keycontrol()
{
	if (_kbhit())   //用于非阻塞的检测是否有键盘输入，如果有，再指向，这样就不会阻塞影响到其他函数运行
	{
		switch (_getch())
		{
		case 'w':
			airplane.y -= 5;
			break;
		case 's':
			airplane.y += 5;
			break;
		case 'a':
			airplane.x -= 5;
			break;
		case 'd':
			airplane.x += 5;
			break;
		};
	}


}

void crash(int y)
{
	if (shall.coor[y].y == (580 + airplane.y) && shall.coor[y].x >= (350 + airplane.x) && shall.coor[y].x <= (450 + airplane.x))
		shall.iscrash = true;
}