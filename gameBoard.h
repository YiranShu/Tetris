#ifndef _GAME_BOARD_H_
#define _GAME_BOARD_H_
#include "include\Angel.h"
#include "constant.h"
#include <vector>

class GameBoard {
private:
	std::vector<std::vector<int>> gridsFilled;
	vec3 colorFilled[AllRows][Columns];

public:
	GameBoard() {
		gridsFilled = std::vector<std::vector<int>>(AllRows, std::vector<int>(Columns));
		for (int i = 0; i < AllRows; i++) {
			for (int j = 0; j < Columns; j++) {
				gridsFilled[i][j] = 0;
				colorFilled[i][j] = vec3(0.0f, 0.0f, 0.0f);
			}
		}
	}

	bool checkLine(int line);
	void removeLine(int line);
	std::vector<std::vector<int>> getGridsMap() const;
	void land(int x, int y, vec3 color);
	vec3 getGridColor(int x, int y) const;
	void clear();
};

#endif

