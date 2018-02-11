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
	TTile() : status(0), color(vec3(0.0f, 1.0f, 0.0f)) {
		grids.emplace_back(4, 19);
		grids.emplace_back(3, 20);
		grids.emplace_back(4, 20);
		grids.emplace_back(5, 20);
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
	ITile() : status(0), color(vec3(0.0f, 0.0f, 1.0f)) {
		grids.emplace_back(3, 19);
		grids.emplace_back(4, 19);
		grids.emplace_back(5, 19);
		grids.emplace_back(6, 19);
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
	JTile() : status(0), color(vec3(1.0f, 0.0f, 0.5f)) {
		grids.emplace_back(5, 19);
		grids.emplace_back(5, 20);
		grids.emplace_back(4, 20);
		grids.emplace_back(3, 20);
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
		grids.emplace_back(4, 19);
		grids.emplace_back(5, 19);
		grids.emplace_back(4, 20);
		grids.emplace_back(5, 20);
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
	LTile() : status(0), color(vec3(0.7f, 0.5f, 1.0f)) {
		grids.emplace_back(3, 19);
		grids.emplace_back(3, 20);
		grids.emplace_back(4, 20);
		grids.emplace_back(5, 20);
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
	STile() : status(0), color(vec3(1.0f, 0.5f, 0.0f)) {
		grids.emplace_back(3, 19);
		grids.emplace_back(4, 19);
		grids.emplace_back(4, 20);
		grids.emplace_back(5, 20);
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
	ZTile() : status(0), color(vec3(1.0f, 1.0f, 0.0f)) {
		grids.emplace_back(5, 19);
		grids.emplace_back(4, 19);
		grids.emplace_back(4, 20);
		grids.emplace_back(3, 20);
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
