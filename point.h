#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point(){}
	Point(const int x, const int y) : x(x), y(y) {}
	void PrintHead();
	void PrintCircular();
	void PrintWall();
	void Clear(int width, int height);
	void Printsnakeheadup();
	void Printsnakeheaddown();
	void Printsnakeheadleft();
	void Printsnakeheadright();
	bool operator== (const Point& point) { return (point.x == this->x) && (point.y == this->y); }
	int GetX(){ return this->x; }
	int GetY(){ return this->y; }
private:
	int x, y;
};
#endif // POINT_H

