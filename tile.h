#ifndef _TILE_H_
#define _TILE_H_
#include "include\Angel.h"
#include "Grid.h"
#include <vector>

class Tile {
public:
	virtual void rotate() = 0;
	virtual std::vector<Grid> rotateWillOccupy() const = 0;
	virtual void initGrids() = 0;
	virtual void moveLeft() = 0;
	virtual void moveRight() = 0;
	virtual void moveDown() = 0;
	virtual std::vector<Grid> getGrids() const = 0;
	virtual vec3 getColor() const = 0;
	virtual ~Tile() = default;
};

class TTile : public Tile {
protected:
	int status;
	std::vector<Grid> grids;
	vec3 color;

public:
	TTile() : color(vec3(0.0f, 1.0f, 0.0f)) {
		status = rand() % 4;
		if (status == 0) {
			int left = rand() % 8;
			grids.emplace_back(1 + left, 19);
			grids.emplace_back(left, 20);
			grids.emplace_back(1 + left, 20);
			grids.emplace_back(2 + left, 20);
		}

		else if (status == 1) {
			int left = rand() % 9;
			grids.emplace_back(1 + left, 19);
			grids.emplace_back(left, 18);
			grids.emplace_back(left, 19);
			grids.emplace_back(left, 20);
		}

		else if (status == 2) {
			int left = rand() % 8;
			grids.emplace_back(1 + left, 20);
			grids.emplace_back(2 + left, 19);
			grids.emplace_back(1 + left, 19);
			grids.emplace_back(left, 19);
		}

		else {
			int left = rand() % 9;
			grids.emplace_back(left, 19);
			grids.emplace_back(1 + left, 20);
			grids.emplace_back(1 + left, 19);
			grids.emplace_back(1 + left, 18);
		}

		for (int i = 0; i < 4; i++) {
			grids[i].setColor(color);
		}
	}

	void rotate() override;
	std::vector<Grid> rotateWillOccupy() const override;
	void initGrids() override;
	void moveLeft() override;
	void moveRight() override;
	void moveDown() override;
	std::vector<Grid> getGrids() const override;
	vec3 getColor() const override;
	virtual ~TTile() { grids.clear(); }
};

class ITile : public Tile {
protected:
	int status;
	std::vector<Grid> grids;
	vec3 color;

public:
	ITile() : color(vec3(0.0f, 0.0f, 1.0f)) {
		status = rand() % 2;
		if (status == 0) {
			int left = rand() % 7;
			grids.emplace_back(left, 19);
			grids.emplace_back(1 + left, 19);
			grids.emplace_back(2 + left, 19);
			grids.emplace_back(3 + left, 19);
		}

		else {
			int left = rand() % 10;
			grids.emplace_back(left, 17);
			grids.emplace_back(left, 18);
			grids.emplace_back(left, 19);
			grids.emplace_back(left, 20);
		}

		for (int i = 0; i < 4; i++) {
			grids[i].setColor(color);
		}
	}

	void rotate() override;
	std::vector<Grid> rotateWillOccupy() const override;
	void initGrids() override;
	void moveLeft() override;
	void moveRight() override;
	void moveDown() override;
	std::vector<Grid> getGrids() const override;
	vec3 getColor() const override;
	virtual ~ITile() { grids.clear(); }
};

class JTile : public Tile {
protected:
	int status;
	std::vector<Grid> grids;
	vec3 color;

public:
	JTile() : color(vec3(1.0f, 0.0f, 0.5f)) {
		status = rand() % 4;
		if (status == 0) {
			int left = rand() % 8;
			grids.emplace_back(2 + left, 19);
			grids.emplace_back(2 + left, 20);
			grids.emplace_back(1 + left, 20);
			grids.emplace_back(left, 20);
		}

		else if (status == 1) {
			int left = rand() % 9;
			grids.emplace_back(1 + left, 20);
			grids.emplace_back(left, 20);
			grids.emplace_back(left, 19);
			grids.emplace_back(left, 18);
		}

		else if (status == 2) {
			int left = rand() % 8;
			grids.emplace_back(left, 20);
			grids.emplace_back(left, 19);
			grids.emplace_back(1 + left, 19);
			grids.emplace_back(2 + left, 19);
		}

		else {
			int left = rand() % 9;
			grids.emplace_back(left, 18);
			grids.emplace_back(1 + left, 18);
			grids.emplace_back(1 + left, 19);
			grids.emplace_back(1 + left, 20);
		}

		for (int i = 0; i < 4; i++) {
			grids[i].setColor(color);
		}
	}

	void rotate() override;
	std::vector<Grid> rotateWillOccupy() const override;
	void initGrids() override;
	void moveLeft() override;
	void moveRight() override;
	void moveDown() override;
	std::vector<Grid> getGrids() const override;
	vec3 getColor() const override;
	virtual ~JTile() { grids.clear(); }
};

class OTile : public Tile {
protected:
	int status;
	std::vector<Grid> grids;
	vec3 color;

public:
	OTile() : status(0), color(vec3(1.0f, 0.0f, 0.0f)) {
		int left = rand() % 9;
		grids.emplace_back(left, 19);
		grids.emplace_back(1 + left, 19);
		grids.emplace_back(left, 20);
		grids.emplace_back(1 + left, 20);
		for (int i = 0; i < 4; i++) {
			grids[i].setColor(color);
		}
	}

	void rotate() override;
	std::vector<Grid> rotateWillOccupy() const override;
	void initGrids() override;
	void moveLeft() override;
	void moveRight() override;
	void moveDown() override;
	std::vector<Grid> getGrids() const override;
	vec3 getColor() const override;
	virtual ~OTile() { grids.clear(); }
};

class LTile : public Tile {
protected:
	int status;
	std::vector<Grid> grids;
	vec3 color;

public:
	LTile() : color(vec3(0.7f, 0.5f, 1.0f)) {
		status = rand() % 4;
		if (status == 0) {
			int left = rand() % 8;
			grids.emplace_back(left, 19);
			grids.emplace_back(left, 20);
			grids.emplace_back(1 + left, 20);
			grids.emplace_back(2 + left, 20);
		}

		else if (status == 1) {
			int left = rand() % 9;
			grids.emplace_back(1 + left, 18);
			grids.emplace_back(left, 18);
			grids.emplace_back(left, 19);
			grids.emplace_back(left, 20);
		}

		else if (status == 2) {
			int left = rand() % 8;
			grids.emplace_back(2 + left, 20);
			grids.emplace_back(2 + left, 19);
			grids.emplace_back(1 + left, 19);
			grids.emplace_back(left, 19);
		}

		else {
			int left = rand() % 9;
			grids.emplace_back(left, 20);
			grids.emplace_back(1 + left, 20);
			grids.emplace_back(1 + left, 19);
			grids.emplace_back(1 + left, 18);
		}

		for (int i = 0; i < 4; i++) {
			grids[i].setColor(color);
		}
	}

	void rotate() override;
	std::vector<Grid> rotateWillOccupy() const override;
	void initGrids() override;
	void moveLeft() override;
	void moveRight() override;
	void moveDown() override;
	std::vector<Grid> getGrids() const override;
	vec3 getColor() const override;
	virtual ~LTile() { grids.clear(); }
};

class STile : public Tile {
protected:
	int status;
	std::vector<Grid> grids;
	vec3 color;

public:
	STile() : color(vec3(1.0f, 0.5f, 0.0f)) {
		status = rand() % 2;
		if (status == 0) {
			int left = rand() % 8;
			grids.emplace_back(left, 19);
			grids.emplace_back(1 + left, 19);
			grids.emplace_back(1 + left, 20);
			grids.emplace_back(2 + left, 20);
		}

		else {
			int left = rand() % 9;
			grids.emplace_back(1 + left, 18);
			grids.emplace_back(1 + left, 19);
			grids.emplace_back(left, 19);
			grids.emplace_back(left, 20);
		}

		for (int i = 0; i < 4; i++) {
			grids[i].setColor(color);
		}
	}

	void rotate() override;
	std::vector<Grid> rotateWillOccupy() const override;
	void initGrids() override;
	void moveLeft() override;
	void moveRight() override;
	void moveDown() override;
	std::vector<Grid> getGrids() const override;
	vec3 getColor() const override;
	virtual ~STile() { grids.clear(); }
};

class ZTile : public Tile {
protected:
	int status;
	std::vector<Grid> grids;
	vec3 color;

public:
	ZTile() : color(vec3(1.0f, 1.0f, 0.0f)) {
		status = rand() % 2;
		if (status == 0) {
			int left = rand() % 8;
			grids.emplace_back(2 + left, 19);
			grids.emplace_back(1 + left, 19);
			grids.emplace_back(1 + left, 20);
			grids.emplace_back(left, 20);
		}

		else {
			int left = rand() % 9;
			grids.emplace_back(1 + left, 20);
			grids.emplace_back(1 + left, 19);
			grids.emplace_back(left, 19);
			grids.emplace_back(left, 18);
		}

		for (int i = 0; i < 4; i++) {
			grids[i].setColor(color);
		}
	}

	void rotate() override;
	std::vector<Grid> rotateWillOccupy() const override;
	void initGrids() override;
	void moveLeft() override;
	void moveRight() override;
	void moveDown() override;
	std::vector<Grid> getGrids() const override;
	vec3 getColor() const override;
	virtual ~ZTile() { grids.clear(); }
};

#endif
