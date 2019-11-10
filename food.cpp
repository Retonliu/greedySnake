#include "food.h"
#include <cstdlib>
#include <iostream>
#include <easyx.h>
#include <graphics.h>
#include "map.h"


void Food::DrawFood(Snake& csnake, int key)//绘制食物
{
	while (true)
	{
		//为了能保证蛇能与食物对准，需要对地图进行分割处理
		int tmp_x = rand() % 41;  //x方向上分成41份，每份14像素
		int tmp_y = rand() % 28;  //x方向上分成28份，每份14像素
		if (tmp_x == 0) tmp_x += 1;
		if (tmp_y == 0) tmp_y += 1;
		tmp_x = 30 + tmp_x * 14;
		tmp_y = 40 + tmp_y * 14;
		bool flag = false;
		for (auto& point : csnake.snake)  //保证食物不与蛇身重合
		{
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y)) {
				flag = true;
				break;
			}
		}
		if (key == 4) //炼狱模式中食物不能出现在盒子内
		{
			if ((tmp_x > 74 && tmp_x < 186 && tmp_y > 74 && tmp_y < 186) ||
				(tmp_x > 484 && tmp_x < 596 && tmp_y > 94 && tmp_y < 206) ||
				(tmp_x > 294 && tmp_x < 406 && tmp_y > 354 && tmp_y < 466) ||
				(tmp_x > 144 && tmp_x < 256 && tmp_y > 294 && tmp_y < 406) ||
				(tmp_x > 394 && tmp_x < 506 && tmp_y > 224 && tmp_y < 336))
				flag = true;
		}
		if (flag || (tmp_x == big_x && tmp_y == big_y)) //保证不与大食物重合
			continue;
		x = tmp_x;
		y = tmp_y;
		IMAGE FOOD;
		loadimage(&FOOD, _T("food.jpg"), 14, 14);
		putimage(x - 7, y - 7, &FOOD);
		break;
	}
	if ((!extra_flag) && (!big_flag) && (rand() % 3) == 1)
	{  //已经有大食物或吃到额外食物时不出现大食物
		DrawBigFood(csnake, key); //三分之一概率出现大食物
	}
}

void Food::DrawBigFood(Snake& csnake, int key)//绘制大食物
{
	progress = 52;
	big_flag = true;
	while (true)
	{
		int tmp_x = rand() % 41;
		int tmp_y = rand() % 28;
		if (tmp_x == 0) tmp_x += 1;
		if (tmp_y == 0) tmp_y += 1;
		tmp_x = 30 + tmp_x * 14;
		tmp_y = 40 + tmp_y * 14;
		bool flag = false;
		for (auto& point : csnake.snake)  //保证食物不与蛇身重合
		{
			if ((point.GetX() == tmp_x && point.GetY() == tmp_y)) {
				flag = true;
				break;
			}
		}
		if (key == 4) //炼狱模式中食物不能出现在盒子内
		{
			if ((tmp_x > 74 && tmp_x < 186 && tmp_y > 74 && tmp_y < 186) ||
				(tmp_x > 484 && tmp_x < 596 && tmp_y > 94 && tmp_y < 206) ||
				(tmp_x > 294 && tmp_x < 406 && tmp_y > 354 && tmp_y < 466) ||
				(tmp_x > 144 && tmp_x < 256 && tmp_y > 294 && tmp_y < 406) ||
				(tmp_x > 394 && tmp_x < 506 && tmp_y > 224 && tmp_y < 336))
				flag = true;
		}
		if (flag || (tmp_x == x  && tmp_y == y))//保证不与小食物重合
			continue;
		big_x = tmp_x;
		big_y = tmp_y;
		IMAGE BIGFOOD;
		loadimage(&BIGFOOD, _T("bigfood.jpg"), 18, 18);
		putimage(big_x - 9, big_y - 9, &BIGFOOD);
		break;
	}
}

void Food::VanishBigFood()//使大食物限时出现
{
	--progress;
	if (progress == 0) {
		Map *init_map = new Map();
		init_map->clearxy(big_x - 10, big_y - 10, 21, 21);
		delete init_map;
		big_flag = false;
		big_x = 0;
		big_y = 0;
	}
}

int Food::GetProgress()
{
	return progress;
}

bool Food::GetBigFlag()
{
	return big_flag;
}

void Food::SetBigFlag(bool s)
{
	big_flag = s;
}

void Food::SetExtraFlag() //设置额外食物标志
{
	extra_flag = true;
}

bool Food::GetExtraFlag() //获取额外食物标志
{
	return extra_flag;
}