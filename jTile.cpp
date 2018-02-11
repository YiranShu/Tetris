#include "tile.h"
#include "Grid.h"
#include "constant.h"
#include "include\Angel.h"

void JTile::rotate() { //check
					//if applicable
	if (status == 0) {
		grids[0].setLocation(grids[2].getX() + 1, grids[2].getY() + 1);
		grids[1].setLocation(grids[2].getX(), grids[2].getY() + 1);
		grids[3].setLocation(grids[2].getX(), grids[2].getY() - 1);
		status++;
	}

	else if (status == 1) {
		grids[0].setLocation(grids[2].getX() - 1, grids[2].getY() + 1);
		grids[1].setLocation(grids[2].getX() - 1, grids[2].getY());
		grids[3].setLocation(grids[2].getX() + 1, grids[2].getY());
		status++;
	}

	else if (status == 2) {
		grids[0].setLocation(grids[2].getX() - 1, grids[2].getY() - 1);
		grids[1].setLocation(grids[2].getX(), grids[2].getY() - 1);
		grids[3].setLocation(grids[2].getX(), grids[2].getY() + 1);
		status++;
	}

	else {
		grids[0].setLocation(grids[2].getX() + 1, grids[2].getY() - 1);
		grids[1].setLocation(grids[2].getX() + 1, grids[2].getY());
		grids[3].setLocation(grids[2].getX() - 1, grids[2].getY());
		status = 0;
	}
}

std::vector<Grid> JTile::rotateWillOccupy() const {
	std::vector<Grid> res;

	if (status == 0) {
		res.emplace_back(grids[2].getX() + 1, grids[2].getY() + 1);
		res.emplace_back(grids[2].getX(), grids[2].getY() + 1);
		res.emplace_back(grids[2].getX(), grids[2].getY() - 1);
	}

	else if (status == 1) {
		res.emplace_back(grids[2].getX() - 1, grids[2].getY() + 1);
		res.emplace_back(grids[2].getX() - 1, grids[2].getY());
		res.emplace_back(grids[2].getX() + 1, grids[2].getY());
	}

	else if(status == 2) {
		res.emplace_back(grids[2].getX() - 1, grids[2].getY() - 1);
		res.emplace_back(grids[2].getX(), grids[2].getY() - 1);
		res.emplace_back(grids[2].getX(), grids[2].getY() + 1);
	}

	else {
		res.emplace_back(grids[2].getX() + 1, grids[2].getY() - 1);
		res.emplace_back(grids[2].getX() + 1, grids[2].getY());
		res.emplace_back(grids[2].getX() - 1, grids[2].getY());
	}

	return res;
}

void JTile::initGrids() {
	color = vec3(0.2f, 0.6f, 0.3f);
	grids[0].setLocation(5, 19);
	grids[1].setLocation(5, 20);
	grids[2].setLocation(4, 20);
	grids[3].setLocation(3, 20);
	for (int i = 0; i < 4; i++) {
		grids[i].setColor(color);
	}
	status = 0;
}

void JTile::moveLeft() {
	if (grids[0].getX() > 0 && grids[1].getX() > 0 && grids[2].getX() > 0 && grids[3].getX() > 0) {
		for (int i = 0; i < 4; i++) {
			grids[i].moveLeft();
		}
	}
}

void JTile::moveRight() {
	if (grids[0].getX() < Columns - 1 && grids[1].getX() < Columns - 1 && grids[2].getX() < Columns - 1 && grids[3].getX() < Columns - 1) {
		for (int i = 0; i < 4; i++) {
			grids[i].moveRight();
		}
	}
}

void JTile::moveDown() { //check
	if (grids[0].getY() > 0 && grids[1].getY() > 0 && grids[2].getY() > 0 && grids[3].getY() > 0) {
		for (int i = 0; i < 4; i++) {
			grids[i].moveDown();
		}
	}
}

std::vector<Grid> JTile::getGrids() const {
	return grids;
}

vec3 JTile::getColor() const {
	return color;
}