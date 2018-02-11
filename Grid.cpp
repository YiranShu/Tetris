#include "Grid.h"
#include "constant.h"

void Grid::setLocation(int x, int y) {
	this->x = x;
	this->y = y;
}

void Grid::setColor(const vec3 &color) {
	this->color = color;
}

void Grid::moveDown() {
	if (y > 0) {
		y--;
	}
}

void Grid::moveLeft() {
	if (x > 0) {
		x--;
	}
}

void Grid::moveRight() {
	if (x < Rows - 1) {
		x++;
	}
}

int Grid::getX() const {
	return x;
}

int Grid::getY() const {
	return y;
}

vec3 Grid::getColor() const {
	return color;
}