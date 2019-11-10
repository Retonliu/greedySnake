#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include "point.h"
#include "food.h"

class Food;
class Snake
{
public:
	enum Direction {UP, DOWN, LEFT, RIGHT };

	Snake() {
		snake.emplace_back(254, 236);
		snake.emplace_back(268, 236);
		snake.emplace_back(282, 236);
		direction = Direction::RIGHT;
	}
	void InitSnake();
	void Move();
	void NormalMove();
	bool OverEdge();
	bool HitItself();
	bool HitBox();
	bool ChangeDirection();
	bool GetFood(const Food&);
	bool GetBigFood(Food&);
private:
	std::deque<Point> snake;
	Direction direction;
	friend class Food;//将Food类置为友元，以便访问其私有元素
};
#endif // SNAKE_H

