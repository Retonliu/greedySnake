#include "point.h"
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <easyx.h>

void Point::PrintCircular()//输出蛇身的圆形
{
	setfillcolor(RGB(250, 128, 10));
	solidcircle(x, y, 7);
}

void Point::PrintWall()
{
	IMAGE WA;
	loadimage(&WA, _T("box.jpg"), 100, 100);
	putimage(this->x, this->y, &WA);
}

void Point::Clear(int width, int height)//清除函数
{
	IMAGE AC;
	loadimage(&AC, _T("gamemap.jpg"), 655, 510);
	putimage(this->x - 7, this->y - 7, width, height, &AC, this->x - 7, this->y - 7);
}

void Point::Printsnakeheadup()
{

	IMAGE snakehead;
	loadimage(&snakehead, _T("snakeheadup.jpg"), 14, 14);
	putimage(x - 7, y - 7, &snakehead);

}

void Point::Printsnakeheaddown()
{

	IMAGE snakehead;
	loadimage(&snakehead, _T("snakeheaddown.jpg"), 14, 14);
	putimage(x - 7, y - 7, &snakehead);

}

void Point::Printsnakeheadleft()
{

	IMAGE snakehead;
	loadimage(&snakehead, _T("snakeheadleft.jpg"), 14, 14);
	putimage(x - 7, y - 7, &snakehead);

}

void Point::Printsnakeheadright()
{

	IMAGE snakehead;
	loadimage(&snakehead, _T("snakeheadright.jpg"), 14, 14);
	putimage(x - 7, y - 7, &snakehead);

}


