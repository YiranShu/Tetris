#include "gameBoard.h"

bool GameBoard::checkLine(int line) {
	for (int i = 0; i < Columns; i++) {
		if (!gridsFilled[line][i]) {
			return false;
		}
	}

	return true;
}

void GameBoard::removeLine(int line) {
	for (int i = line; i < Rows; i++) {
		for (int j = 0; j < Columns; j++) {
			gridsFilled[i][j] = gridsFilled[i + 1][j];
			colorFilled[i][j] = colorFilled[i + 1][j];
		}
	}

	for (int i = 0; i < Columns; i++) {
		gridsFilled[Rows][i] = 0;
		colorFilled[Rows][i] = vec3(0.0f, 0.0f, 0.0f);
	}
}

std::vector<std::vector<int>> GameBoard::getGridsMap() const {
	return gridsFilled;
}

void GameBoard::land(int x, int y, vec3 color) {
	gridsFilled[y][x] = 1;
	colorFilled[y][x] = color; //!!
}

vec3 GameBoard::getGridColor(int x, int y) const {
	return colorFilled[y][x];
}

void GameBoard::clear() {
	for (unsigned int i = 0; i < AllRows; i++) {
		for (unsigned int j = 0; j < Columns; j++) {
			gridsFilled[i][j] = 0;
			colorFilled[i][j] = vec3(0.0f, 0.0f, 0.0f);
		}
	}
}
