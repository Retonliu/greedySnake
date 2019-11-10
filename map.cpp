#include "map.h"
#include <windows.h>
#include <easyx.h>
#include <graphics.h>

void Map::PrintBackground()
{
	IMAGE BG;
	loadimage(&BG, _T("gamemap.jpg"), 655, 510);
	putimage(0, 0, &BG);
}

void Map::PrintWall()
{
	wall.emplace_back(Point(80, 80));
	wall.emplace_back(Point(490, 100));
	wall.emplace_back(Point(300, 360));
	wall.emplace_back(Point(150, 300));
	wall.emplace_back(Point(400, 230));
	for (auto &point : wall)
	{
		point.PrintWall();
	}
}

void Map::clearxy(int x, int y, int width, int height)
{
	IMAGE BG;
	loadimage(&BG, _T("gamemap.jpg"), 655, 510);
	putimage(x, y, width, height, &BG, x, y);  
}

void Map::start()
{
	IMAGE BG;
	loadimage(&BG, _T("start.jpg"), 655, 510);
	putimage(0, 0, &BG);
}

void Map::PrintScore()
{
	IMAGE BG;
	loadimage(&BG, _T("score.jpg"), 655, 510);
	putimage(0, 0, &BG);
}

void Map::PrintSelect()
{
	IMAGE BG;
	loadimage(&BG, _T("select.jpg"), 655, 510);
	putimage(0, 0, &BG);
}