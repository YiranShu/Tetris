#include "tile.h"
#include "Grid.h"
#include "constant.h"
#include "include\Angel.h"

void OTile::rotate() { 
	return;
}

std::vector<Grid> OTile::rotateWillOccupy() const {
	return grids;
}

void OTile::initGrids() {
	color = vec3(1.0f, 0.0f, 0.0f);
	grids[0].setLocation(4, 19);
	grids[1].setLocation(5, 19);
	grids[2].setLocation(4, 20);
	grids[3].setLocation(5, 20);
	for (int i = 0; i < 4; i++) {
		grids[i].setColor(color);
	}
	status = 0;
}

void OTile::moveLeft() {
	if (grids[0].getX() > 0 && grids[1].getX() > 0 && grids[2].getX() > 0 && grids[3].getX() > 0) {
		for (int i = 0; i < 4; i++) {
			grids[i].moveLeft();
		}
	}
}

void OTile::moveRight() {
	if (grids[0].getX() < Columns - 1 && grids[1].getX() < Columns - 1 && grids[2].getX() < Columns - 1 && grids[3].getX() < Columns - 1) {
		for (int i = 0; i < 4; i++) {
			grids[i].moveRight();
		}
	}
}

void OTile::moveDown() { //check
	if (grids[0].getY() > 0 && grids[1].getY() > 0 && grids[2].getY() > 0 && grids[3].getY() > 0) {
		for (int i = 0; i < 4; i++) {
			grids[i].moveDown();
		}
	}
}

std::vector<Grid> OTile::getGrids() const {
	return grids;
}

vec3 OTile::getColor() const {
	return color;
}