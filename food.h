#ifndef FOOD_H
#define FOOD_H

#include "snake.h"
class Snake;
class Food
{
public:
	Food() : big_flag(false), extra_flag(false), x(0), y(0), big_x(0), big_y(0), progress(0){}
    void DrawFood(Snake&, int);
    void DrawBigFood(Snake&, int);
    void VanishBigFood();
    bool GetBigFlag();
	void SetBigFlag(bool s);
    int GetProgress();
	void SetExtraFlag();
	bool GetExtraFlag();
private:
    bool big_flag;//是否有大食物标记
	bool extra_flag;//是否有额外食物标记
    int x, y;
    int big_x, big_y;
    int progress;//限时食物进度
    friend class Snake;
};
#endif // FOOD_H
