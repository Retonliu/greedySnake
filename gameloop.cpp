#include <iostream>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "gameloop.h"
#include "map.h"
#include "snake.h"
#include "food.h"
#include <easyx.h>
#include <graphics.h>
#include "memory.h"

void Gameloop::Start()//开始界面
{
	initgraph(655, 510);
}

int Gameloop::Select1() //选择界面1
{  
	Map *init_map = new Map();
	init_map->start();
	delete init_map;
	int tmp_key = 1;  //用于记录选择的选项

	LOGFONT f;
	setbkmode(TRANSPARENT);
	gettextstyle(&f);                     // 获取当前字体设置
	f.lfHeight = 20;
	f.lfWidth = 20;
	f.lfWeight = 40000;
	f.lfItalic = true;
	f.lfPitchAndFamily = VARIABLE_PITCH | FF_MODERN;
	f.lfQuality = NONANTIALIASED_QUALITY;
	_tcscpy_s(f.lfFaceName, _T("黑体"));
	settextstyle(&f);
	settextcolor(BLACK);
	outtextxy(220, 410, _T("开始游戏"));

	LOGFONT g;
	gettextstyle(&g);                     // 获取当前字体设置
	g.lfHeight = 12;
	g.lfWidth = 11;
	g.lfWeight = 40000;
	g.lfEscapement = 140;
	g.lfOrientation = 200;
	g.lfItalic = true;
	g.lfPitchAndFamily = VARIABLE_PITCH | FF_MODERN;
	g.lfQuality = NONANTIALIASED_QUALITY;
	_tcscpy_s(f.lfFaceName, _T("圆体"));
	settextstyle(&g);
	outtextxy(50, 330, _T("积分榜"));

	outtextxy(55, 290, _T("说明"));

	bool flag = false;  //流程控制标记
	MOUSEMSG m;
	while (true){
		m = GetMouseMsg();
		switch (m.uMsg){
		case WM_MOUSEMOVE:
			if (m.x >= 220 && m.x <= 380 && m.y >= 400 && m.y <= 430){
				settextstyle(&f);
				settextcolor(RED);
				outtextxy(220, 410, _T("开始游戏"));
			}
			else if (m.x >= 50 && m.x <= 140 && m.y >= 315 && m.y <= 350){
				settextstyle(&g);
				settextcolor(RED);
				outtextxy(50, 330, _T("积分榜"));
			}
			else if (m.x >= 55 && m.x <= 150 && m.y >= 285 && m.y <= 309){
				settextstyle(&g);
				settextcolor(RED);
				outtextxy(55, 290, _T("说明"));
			}
			else{
				settextstyle(&f);
				settextcolor(BLACK);
				outtextxy(220, 410, _T("开始游戏"));

				settextstyle(&g);
				outtextxy(50, 330, _T("积分榜"));
				settextstyle(&g);
				outtextxy(55, 290, _T("说明"));
			}
			break;
		case WM_LBUTTONDOWN:
			if (m.x >= 220 && m.x <= 380 && m.y >= 400 && m.y <= 430){
				tmp_key = 1;
				flag = true;
			}
			else if (m.x >= 50 && m.x <= 140 && m.y >= 315 && m.y <= 350){
				tmp_key = 2;
				flag = true;
			}
			else if (m.x >= 55 && m.x <= 150 && m.y >= 285 && m.y <= 309){
				tmp_key = 3;
				flag = true;
			}
			break;
		default: break;
		}
		if (flag) break;
	}
	setbkmode(OPAQUE);
	LOGFONT h;
	gettextstyle(&h);
	h.lfHeight = 0;
	h.lfWidth = 0;
	h.lfEscapement = 0;
	h.lfOrientation = 0;
	h.lfItalic = false;
	settextstyle(&h);
	return tmp_key;
}

void Gameloop::Select2()//选择界面2
{
	Map *init_map = new Map();
	init_map->PrintSelect();
	delete init_map;
	settextstyle(17, 0, _T("黑体"));
	settextcolor(BROWN);
	setbkmode(TRANSPARENT);
	outtextxy(260, 70, _T("难度选择："));
	outtextxy(300, 100, _T("简单模式"));
	outtextxy(300, 130, _T("普通模式"));
	outtextxy(300, 160, _T("困难模式"));
	outtextxy(300, 190, _T("炼狱模式"));
	score = 0;
	key = 1;
	bool flag = false;
	/*选择部分*/
	MOUSEMSG m;
	while (true){
		m = GetMouseMsg();
		switch (m.uMsg){
		case WM_MOUSEMOVE:
			if (m.x >= 300 && m.x <= 370 && m.y >= 100 && m.y <= 120){
				settextcolor(RED);
				outtextxy(300, 100, _T("简单模式"));
			}
			else if (m.x >= 300 && m.x <= 370 && m.y >= 130 && m.y <= 150){
				settextcolor(RED);
				outtextxy(300, 130, _T("普通模式"));
			}
			else if (m.x >= 300 && m.x <= 370 && m.y >= 160 && m.y <= 180){
				settextcolor(RED);
				outtextxy(300, 160, _T("困难模式"));
			}
			else if (m.x >= 300 && m.x <= 370 && m.y >= 190 && m.y <= 210){
				settextcolor(RED);
				outtextxy(300, 190, _T("炼狱模式"));
			}
			else{
				settextcolor(BROWN);
				outtextxy(260, 70, _T("难度选择："));
				outtextxy(300, 100, _T("简单模式"));
				outtextxy(300, 130, _T("普通模式"));
				outtextxy(300, 160, _T("困难模式"));
				outtextxy(300, 190, _T("炼狱模式"));
			}
			break;
		case WM_LBUTTONDOWN:  //根据选择的难度设定蛇的移动速度
			if (m.x >= 300 && m.x <= 370 && m.y >= 100 && m.y <= 120){
				key = 1;
				speed = 50;
				flag = true;
			}
			else if (m.x >= 300 && m.x <= 370 && m.y >= 130 && m.y <= 150){
				key = 2;
				speed = 30;
				flag = true;
			}
			else if (m.x >= 300 && m.x <= 370 && m.y >= 160 && m.y <= 180){
				key = 3;
				speed = 1;
				flag = true;
			}
			else if (m.x >= 300 && m.x <= 370 && m.y >= 190 && m.y <= 210){
				key = 4;
				speed = 1;
				flag = true;
			}
			break;
		default: break;
		}
		if (flag) break;
	}
	setbkmode(OPAQUE);
}

int Gameloop::Score_list(int key) //打印积分榜
{
	bool flag = false;  //流程控制标记
	int choose = 1;  //记录选项标记
	cleardevice();
	Map *init_map = new Map();
	init_map->PrintScore();
	delete init_map;
	setbkmode(TRANSPARENT);
	setcolor(0x419564);
	setcolor(BLUE);
	settextstyle(30, 0, _T("黑体"));
	outtextxy(270, 60, _T("积分榜"));
	settextstyle(16, 0, _T("黑体"));
	outtextxy(210, 100, _T("排名"));
	outtextxy(290, 100, _T("难度"));
	outtextxy(370, 100, _T("分数"));
	read();  //读取文件内容，排序后打印
	setcolor(BLUE);
	if (key == 1){  //若在开始界面打开积分榜
		outtextxy(300, 400, _T("返回"));
		MOUSEMSG m;
		while (true){
			m = GetMouseMsg();
			switch (m.uMsg)
			{
				case WM_MOUSEMOVE:
					if (m.x >= 300 && m.x <= 330 && m.y >= 400 && m.y <= 420){
						setcolor(RED);
						outtextxy(300, 400, _T("返回"));
					}
					else{
						setcolor(BLUE);
						outtextxy(300, 400, _T("返回"));
					}
					break;
				case WM_LBUTTONDOWN:
					if (m.x >= 300 && m.x <= 330 && m.y >= 400 && m.y <= 420){
						flag = true;
					}
					break;
			}
			if (flag){
				break;
			}
		}
		setbkmode(OPAQUE);
		return 0;
	}
	else if (key == 2){  //若在死亡界面打开积分榜
		outtextxy(240, 430, _T("重新开始"));
		outtextxy(340, 430, _T("退出游戏"));
		MOUSEMSG m;
		while (true){
			m = GetMouseMsg();
			switch (m.uMsg)
			{
			case WM_MOUSEMOVE:
				if (m.x >= 240 && m.x <= 300 && m.y >= 430 && m.y <= 450){
					setcolor(RED);
					outtextxy(240, 430, _T("重新开始"));
				}
				else if (m.x >= 340 && m.x <= 400 && m.y >= 430 && m.y <= 450){
					setcolor(RED);
					outtextxy(340, 430, _T("退出游戏"));
				}
				else{
					setcolor(BLUE);
					outtextxy(240, 430, _T("重新开始"));
					outtextxy(340, 430, _T("退出游戏"));
				}
				break;
			case WM_LBUTTONDOWN:
				if (m.x >= 240 && m.x <= 300 && m.y >= 430 && m.y <= 450){
					choose = 1;
					flag = true;
				}
				else if (m.x >= 340 && m.x <= 400 && m.y >= 430 && m.y <= 450){
					choose = 2;
					flag = true;
				}
				break;
			}
			if (flag){
				break;
			}
		}
		setbkmode(OPAQUE);
		return choose;
	}
	else
	{
		setbkmode(OPAQUE);
		return 0;
	}
}

int Gameloop::Explain() //绘制说明菜单
{

	cleardevice();
	Map *init_map = new Map();
	init_map->PrintScore();
	delete init_map;
	setbkmode(TRANSPARENT);
	settextcolor(BLUE);
	settextstyle(17, 0, _T("黑体"));
	outtextxy(100, 250, _T("说明：选择的难度越大，蛇的移速越快，吃到"));
	outtextxy(100, 270, _T("小食物得分越高。炼狱模式还会出现障碍物！！"));
	outtextxy(100, 290, _T("吃到大食物有概率获得以下效果："));
	outtextxy(240, 310, _T("1、加分"));
	outtextxy(240, 330, _T("2、减分"));
	outtextxy(240, 350, _T("3、速度加快"));
	outtextxy(240, 370, _T("4、出现额外食物"));
	settextcolor(GREEN);
	outtextxy(280, 410, _T("返回"));
	MOUSEMSG m;
	while (true){
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			if (m.x >= 280 && m.x <= 310 && m.y >= 410 && m.y <= 430){
				setcolor(RED);
				outtextxy(280, 410, _T("返回"));
			}
			else
			{
				setcolor(GREEN);
				outtextxy(280, 410, _T("返回"));
			}
			break;
		case WM_LBUTTONDOWN:
			if (m.x >= 280 && m.x <= 310 && m.y >= 410 && m.y <= 430){
				setbkmode(OPAQUE);
				return 1;
			}
			break;
		}
	}
}

void Gameloop::DrawGame() //绘制游戏界面
{
	cleardevice();//清屏
    /*绘制地图*/
    Map *init_map = new Map();
	init_map->PrintBackground();
    delete init_map;
    /*绘制游戏状态栏*/
	setbkmode(TRANSPARENT);
	settextcolor(0x1BBCFF);
	settextstyle(18, 0, _T("幼圆"));
	Map *wall = new Map();
    switch (key)
    {
    case 1:
		outtextxy(50, 10, _T("简单模式"));
        break;
    case 2:
		outtextxy(50, 10, _T("普通模式"));
        break;
    case 3:
		outtextxy(50, 10, _T("困难模式"));
        break;
    case 4:
		outtextxy(50, 10, _T("炼狱模式"));
		wall->PrintWall();
        break;
    }
	outtextxy(210, 10, _T("得分："));
	outtextxy(260, 10, _T("0"));
	settextstyle(16, 0, _T("宋体"));
}

int Gameloop::PlayGame()//游戏二级循环
{
	/*初始化蛇和食物*/
	Snake *csnake = new Snake();
	Food *cfood1 = new Food();
	Food *cfood2 = new Food();
	Food *cfood3 = new Food();
	csnake->InitSnake();
	srand((unsigned)time(NULL));//设置随机数种子，如果没有，食物的出现位置将会固定
	cfood1->DrawFood(*csnake, key);

	/*游戏循环*/
	while (csnake->OverEdge() && csnake->HitItself()) //判断是否撞墙或撞到自身
	{
		/*调出选择菜单*/
		if (!csnake->ChangeDirection()) //按Esc键时
		{
			int tmp = Menu();//绘制菜单，并得到返回值
			switch (tmp)
			{
			case 1://继续游戏
				break;

			case 2://重新开始
				delete csnake;
				delete cfood1;
				delete cfood2;
				delete cfood3;
				return 1;//将1作为PlayGame函数的返回值返回到Game函数中，表示重新开始

			case 3://退出游戏
				delete csnake;
				delete cfood1;
				delete cfood2;
				delete cfood3;
				return 2;//将2作为PlayGame函数的返回值返回到Game函数中，表示退出游戏

			default:
				break;
			}
		}

		if (key == 4 && csnake->HitBox()) //在炼狱模式中撞墙
			break;

		if (csnake->GetFood(*cfood1)) //吃到食物
		{
			csnake->Move();//蛇增长
			UpdateScore(1);//更新分数，1为分数权重
			RewriteScore();//重新绘制分数
			cfood1->DrawFood(*csnake, key);//绘制新食物
		}
		else if (csnake->GetFood(*cfood2)) //吃到额外食物1
		{
			csnake->Move();
			UpdateScore(1);
			RewriteScore();
			Food *cfood2 = new Food(); //初始化额外食物
		}
		else if (csnake->GetFood(*cfood3)) //吃到额外食物2
		{
			csnake->Move();
			UpdateScore(1);
			RewriteScore();
			Food *cfood3 = new Food(); //初始化额外食物
		}
		else if (csnake->GetBigFood(*cfood1)) //吃到大食物
		{
			csnake->Move();
			int event = (rand() % 5);
			switch (event)
			{
			case 0:
			case 1: //有较大概率加分
				UpdateScore(6);//分数根据限时食物进度条确定
				RewriteScore();
				break;
			case 2: //有一定几率减分
				UpdateScore(-1);//分数根据限时食物进度条确定
				RewriteScore();
				break;
			case 3: //有几率出现额外食物
				cfood2->SetExtraFlag();
				cfood2->DrawFood(*csnake, key);
				cfood3->SetExtraFlag();
				cfood3->DrawFood(*csnake, key);
				break;
			case 4: //有几率增加速度
				if (speed - 5 > 0)
					speed -= 5;
				break;
			default:
				break;
			}
		}
		else
		{
			csnake->NormalMove();//蛇正常移动
		}
		if (cfood1->GetBigFlag()) //使大食物过一段时间后消失
		{
			cfood1->VanishBigFood();
		}

		Sleep(speed);//制造蛇的移动效果
	}

	/*蛇死亡*/
	delete csnake;//释放分配的内存空间
	delete cfood1;
	delete cfood2;
	delete cfood3;
	save(key, score); //保存游戏得分
	int tmp = GameOver();//绘制游戏结束界面，并返回所选项
	switch (tmp)
	{
	case 1:
		return 1;//重新开始
	case 2:
		return 2;//退出游戏
	case 3:
		return 3;//查看积分榜
	default:
		return 2;
	}
}

void Gameloop::UpdateScore(const int& tmp)//更新分数
{
    score += key * 10 * tmp; //所得分数根据游戏难度及传入的参数tmp确定
	if (score < 0) score = 0;  //保证分数不为负数
}

void Gameloop::RewriteScore()//重绘分数
{
	int tmp = score;
	TCHAR score_string[7]; //设定分数最高为六位数，最后一位存放结束标志符
	_stprintf(score_string, _T("%d"), score); //把分数转换为字符串
	setbkmode(OPAQUE);
	setbkcolor(0x1A3A6F);
	settextcolor(0x1BBCFF);
	settextstyle(18, 0, _T("幼圆"));
	outtextxy(260, 10, score_string);
	settextstyle(16, 0, _T("宋体"));
	setbkmode(TRANSPARENT);
}

int Gameloop::Menu()//暂停菜单
{
    /*绘制菜单*/
	setbkmode(TRANSPARENT);
	settextcolor(BROWN);
	settextstyle(18, 0, _T("幼圆"));
	outtextxy(260, 200, _T("菜单："));
    Sleep(100);
	outtextxy(280, 230, _T("继续游戏"));
    Sleep(100);
	outtextxy(280, 260, _T("重新开始"));
    Sleep(100);
	outtextxy(280, 290, _T("退出游戏"));

    /*选择部分*/
    int tmp_key = 1;
    bool flag = false;
	MOUSEMSG m;
	while (true){
		m = GetMouseMsg();
		switch (m.uMsg){
		case WM_MOUSEMOVE:
			if (m.x >= 280 && m.x <= 340 && m.y >= 230 && m.y <= 250){
				settextcolor(RED);
				outtextxy(280, 230, _T("继续游戏"));
			}
			else if (m.x >= 280 && m.x <= 340 && m.y >= 260 && m.y <= 280){
				settextcolor(RED);
				outtextxy(280, 260, _T("重新开始"));
			}
			else if (m.x >= 280 && m.x <= 340 && m.y >= 290 && m.y <= 310){
				settextcolor(RED);
				outtextxy(280, 290, _T("退出游戏"));
			}
			else{
				settextcolor(BROWN);
				outtextxy(280, 230, _T("继续游戏"));
				outtextxy(280, 260, _T("重新开始"));
				outtextxy(280, 290, _T("退出游戏"));
			}
			break;
		case WM_LBUTTONDOWN:
			if (m.x >= 280 && m.x <= 340 && m.y >= 230 && m.y <= 250){
				tmp_key = 1;
				flag = true;
			}
			else if (m.x >= 280 && m.x <= 340 && m.y >= 260 && m.y <= 280){
				tmp_key = 2;
				flag = true;
			}
			else if (m.x >= 280 && m.x <= 340 && m.y >= 290 && m.y <= 310){
				tmp_key = 3;
				flag = true;
			}
			break;
		default: break;
		}
        if (flag)
        {
            break;
        }
    }

    if (tmp_key == 1) //选择继续游戏，则将菜单擦除
    {
		Map *init_map = new Map();
		init_map->clearxy(260, 200, 100,110);
		delete init_map;
		setbkmode(OPAQUE);
    }
	settextstyle(16, 0, _T("宋体"));
    return tmp_key;
}

void Gameloop::Game()//游戏一级循环
{
    Start();//开始界面
    while (true)//游戏可视为一个死循环，直到退出游戏时循环结束
    {
		int tmp_key = Select1();
		if (tmp_key == 1){
			cleardevice();
			Select2();//选择界面
			DrawGame();//绘制游戏界面
			int tmp = PlayGame();//开启游戏循环，当重新开始或退出游戏时，结束循环并返回值给tmp
			if (tmp == 1) //返回值为1时重新开始游戏
			{
				cleardevice();
				continue;
			}
			else if (tmp == 2) //返回值为2时退出游戏
			{
				closegraph();
				break;
			}
			else if (tmp == 3)
			{
				int choose = Score_list(2);
				if (choose == 1){   //重新开始
					cleardevice();
					continue;
				}
				else if (choose == 2){  //退出游戏
					break;
				}
			}
		}
		else if (tmp_key == 2){
			Score_list(1);
			cleardevice();
			continue;
		}
		else if (tmp_key == 3){
			if (Explain()){
				cleardevice();
				continue;
			}
		}
		else{
			break;
		}
	}
}

int Gameloop::GameOver()//游戏结束界面
{
    /*绘制游戏结束界面*/
    Sleep(500);
	setfillcolor(0x24538B);
	setlinecolor(0x01C29A);
	fillroundrect(180, 160, 460, 350, 40, 40);
	setfillcolor(0x1A3A6F);
	setlinecolor(0x1A3A6F);
	fillrectangle(200, 180, 440, 330);
    Sleep(60);
	setbkmode(TRANSPARENT);
	settextcolor(0x1BBCFF);
	outtextxy(280, 180, _T("游戏结束！"));
    Sleep(60);
	outtextxy(270, 210, _T("很遗憾！你挂了"));
    Sleep(60);
	outtextxy(250, 240, _T("你的分数为："));
    Sleep(60);
	TCHAR score_string[7];
	_stprintf(score_string, _T("%d"), score);
	outtextxy(370, 240, score_string);
    Sleep(60);
	settextcolor(GREEN);
	outtextxy(230, 270, _T("重新开始"));
	Sleep(60);
	outtextxy(350, 270, _T("退出游戏"));
	Sleep(60);
	outtextxy(280, 300, _T("查看积分榜"));
    Sleep(100);
    
    /*选择部分*/
    int tmp_key = 1;
    bool flag = false;
	MOUSEMSG m;
	while (true){
		m = GetMouseMsg();
		switch (m.uMsg){
		case WM_MOUSEMOVE:
			if (m.x >= 230 && m.x <= 290 && m.y >= 270 && m.y <= 290){
				settextcolor(RED);
				outtextxy(230, 270, _T("重新开始"));
			}
			else if (m.x >= 350 && m.x <= 410 && m.y >= 270 && m.y <= 290){
				settextcolor(RED);
				outtextxy(350, 270, _T("退出游戏"));
			}
			else if (m.x >= 280 && m.x <= 360 && m.y >= 300 && m.y <= 330){
				settextcolor(RED);
				outtextxy(280, 300, _T("查看积分榜"));
			}
			else{
				settextcolor(GREEN);
				outtextxy(230, 270, _T("重新开始"));
				outtextxy(350, 270, _T("退出游戏"));
				outtextxy(280, 300, _T("查看积分榜"));
			}
			break;
		case WM_LBUTTONDOWN:
			if (m.x >= 230 && m.x <= 290 && m.y >= 270 && m.y <= 290){
				tmp_key = 1;
				flag = true;
			}
			else if (m.x >= 350 && m.x <= 410 && m.y >= 270 && m.y <= 290){
				tmp_key = 2;
				flag = true;
			}
			else if (m.x >= 280 && m.x <= 360 && m.y >= 300 && m.y <= 330){
				tmp_key = 3;
				flag = true;
			}
			break;
		default: break;
		}
		if (flag)
		{
			break;
		}
	}
	setbkcolor(BLACK);
    switch (tmp_key)
    {
    case 1:
        return 1;//重新开始
    case 2:
        return 2;//退出游戏
	case 3:
		return 3;
    default:
        return 1;
    }
}
