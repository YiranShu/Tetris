#ifndef _GRID_H_
#define _GRID_H_
#include "include\Angel.h"

class Grid {
private:
	int x;
	int y;
	vec3 color;

public:
	Grid(int x, int y): x(x), y(y) {}
	Grid(): x(0), y(0) {}
	void setLocation(int x, int y);
	void setColor(const vec3 &color);
	void moveDown();
	void moveLeft();
	void moveRight();
	int getX() const;
	int getY() const;
	vec3 getColor() const;
};

#endif