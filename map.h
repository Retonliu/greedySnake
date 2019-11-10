#ifndef MAP_H
#define MAP_H

#include <vector>
#include "point.h"

class Map
{
public:
	void PrintBackground(); //»æÖÆ±³¾°Í¼Æ¬
	void PrintWall();
	void clearxy(int x, int y, int width, int height); //Çå³ýº¯Êý
	void start();  //¿ªÊ¼½çÃæ±³¾°Í¼Æ¬
	void PrintScore();  //»ý·Ö°ñ±³¾°Í¼Æ¬
	void PrintSelect();  //ÄÑ¶ÈÑ¡Ôñ±³¾°Í¼Æ¬
	std::vector<Point> wall;
};
#endif // MAP_H
