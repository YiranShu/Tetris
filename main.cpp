#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "include\Angel.h"
#include "gameBoard.h"
#include "tile.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

GameBoard game;
Tile *tile;
GLuint vaoGrid;
GLuint vaoLine;
vec2 linePoints[NumberLinePoints];
vec3 lineColors[NumberLinePoints];
vec2 points[800];
vec3 colors[800];

std::vector<GLfloat> translateGrid(int x, int y) {
	std::vector<GLfloat> res;

	res.push_back(LeftBorder + x * (RightBorder - LeftBorder) / Columns); // horizontal coor of left bottom point
	res.push_back(BottomBorder + y * (TopBorder - BottomBorder) / Rows); //vertical coor of left bottom point
	res.push_back(LeftBorder + x * (RightBorder - LeftBorder) / Columns); // horizontal coor of left top point
	res.push_back(BottomBorder + (y + 1) * (TopBorder - BottomBorder) / Rows); //vertical coor of left top point
	res.push_back(LeftBorder + (x + 1) * (RightBorder - LeftBorder) / Columns); // horizontal coor of right top point
	res.push_back(BottomBorder + (y + 1) * (TopBorder - BottomBorder) / Rows); //vertical coor of right top point
	res.push_back(LeftBorder + (x + 1) * (RightBorder - LeftBorder) / Columns); // horizontal coor of right bottom point
	res.push_back(BottomBorder + y * (TopBorder - BottomBorder) / Rows); //vertical coor of right bottom point

	return res;
}

std::vector<GLfloat> translateTile() {
	std::vector<Grid> grids(tile->getGrids());
	std::vector<GLfloat> res;
	for (Grid& grid : grids) {
		// need to add some statements
		if (grid.getY() < Rows) {
			std::vector<GLfloat> temp = translateGrid(grid.getX(), grid.getY());
			res.insert(res.end(), temp.begin(), temp.end());
		}
	}

	return res;
}

void generateTile() {
	//need to modify
	int random = rand() % 7;
	if (random == 0) {
		tile = new TTile();
	}

	else if (random == 1) {
		tile = new OTile();
	}

	else if (random == 2) {
		tile = new ITile();
	}

	else if (random == 3) {
		tile = new STile();
	}

	else if (random == 4) {
		tile = new ZTile();
	}

	else if (random == 5) {
		tile = new LTile();
	}

	else {
		tile = new JTile();
	}
}

bool isEnd() {
	std::vector<std::vector<int>> gridsMap(game.getGridsMap());

	for (int i = 0; i < Columns; i++) {
		if (gridsMap[Rows][i]) {
			return true;
		}
	}

	return false;
}

bool isOverlap() {
	if (tile == NULL) {
		return false;
	}

	std::vector<Grid> grids(tile->getGrids());
	std::vector<std::vector<int>> gridsMap(game.getGridsMap());

	for (Grid& grid : grids) {
		if (gridsMap[grid.getY()][grid.getX()]) {
			return true;
		}
	}

	return false;
}

bool canRotate() {
	if (tile == NULL) {
		return false;
	}

	std::vector<Grid> temp = tile->rotateWillOccupy();
	std::vector<std::vector<int>> tempBoard(game.getGridsMap());

	for (Grid& i : temp) {
		if (i.getX() < 0 || i.getX() >= Columns || i.getY() < 0
			|| i.getY() >= Rows || tempBoard[i.getY()][i.getX()]) {
			return false;
		}
	}

	return true;
}

bool canMoveLeft() {
	if (tile == NULL) {
		return false;
	}

	std::vector<Grid> grids = tile->getGrids();
	std::vector<std::vector<int>> gridsMap(game.getGridsMap());

	for (Grid& grid : grids) {
		if (grid.getX() <= 0 || gridsMap[grid.getY()][grid.getX() - 1]) {
			return false;
		}
	}

	return true;
}

bool canMoveRight() {
	if (tile == NULL) {
		return false;
	}

	std::vector<Grid> grids = tile->getGrids();
	std::vector<std::vector<int>> gridsMap(game.getGridsMap());

	for (Grid& grid : grids) {
		if (grid.getX() >= Columns - 1 || gridsMap[grid.getY()][grid.getX() + 1]) {
			return false;
		}
	}

	return true;
}

bool canMoveDown() {
	if (tile == NULL) {
		return false;
	}

	std::vector<Grid> grids = tile->getGrids();
	std::vector<std::vector<int>> gridsMap(game.getGridsMap());

	for (Grid& grid : grids) {
		if (grid.getY() <= 0 || gridsMap[grid.getY() - 1][grid.getX()]) {
			return false;
		}
	}

	return true;
}

bool hitGround() {
	if (tile == NULL) {
		return false;
	}

	std::vector<Grid> grids = tile->getGrids();
	std::vector<std::vector<int>> gridMap(game.getGridsMap());

	for (Grid& grid : grids) {
		if (grid.getY() <= 0 || gridMap[grid.getY() - 1][grid.getX()]) {
			return true;
		}
	}

	return false;
}

void restart() {
	game.clear();
}

void gameProcess(int) {
	if (canMoveDown()) {
		tile->moveDown();
	}

	if (hitGround()) {
		//wait for some time
		std::vector<Grid> grids = tile->getGrids();
		for (Grid& grid : grids) {
			game.land(grid.getX(), grid.getY(), grid.getColor());
		}

		int i = 0;
		while (i < Rows) {
			if (game.checkLine(i)) {
				game.removeLine(i);
			}
			else {
				i++;
			}
		}

		if (tile != NULL) {
			delete tile;
			tile = NULL;
		}

		if (isEnd()) {
			restart();
		}

		if (tile == NULL) {
			generateTile();
		}

		if (isOverlap()) {
			if (tile != NULL) {
				delete tile;
				tile = NULL;
			}
			restart();
			if (tile == NULL) {
				generateTile();
			}
		}
	}

	glutPostRedisplay();
	glutTimerFunc(500, gameProcess, 0);
}

void init() {
	generateTile();

	for (int i = 0; i <= Rows; i++) {
		linePoints[2 * i] = vec2(LeftBorder, BottomBorder + i * (TopBorder - BottomBorder) / Rows);
		linePoints[2 * i + 1] = vec2(RightBorder, BottomBorder + i * (TopBorder - BottomBorder) / Rows);
	}

	for (int i = 0; i <= Columns; i++) {
		linePoints[2 * Rows + 2 * i + 2] = vec2(LeftBorder + i * (RightBorder - LeftBorder) / Columns, BottomBorder);
		linePoints[2 * Rows + 2 * i + 3] = vec2(LeftBorder + i * (RightBorder - LeftBorder) / Columns, TopBorder);
	}

	for (int i = 0; i < NumberLinePoints; i++) {
		lineColors[i] = vec3(1.0f, 1.0f, 1.0f);
	}

	glGenVertexArrays(1, &vaoLine);
	glBindVertexArray(vaoLine);

	GLuint bufferLine;
	glGenBuffers(1, &bufferLine);
	glBindBuffer(GL_ARRAY_BUFFER, bufferLine);
	glBufferData(GL_ARRAY_BUFFER, sizeof(linePoints) + sizeof(lineColors), linePoints, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(linePoints), linePoints);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(linePoints), sizeof(lineColors), lineColors);

	GLuint lineProgram = InitShader("vshader.glsl", "fshader.glsl");
	glUseProgram(lineProgram);

	GLuint lineLoc = glGetAttribLocation(lineProgram, "vPosition");
	glEnableVertexAttribArray(lineLoc);
	glVertexAttribPointer(lineLoc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	GLuint lineVColor = glGetAttribLocation(lineProgram, "vColor");
	glEnableVertexAttribArray(lineVColor);
	glVertexAttribPointer(lineVColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(linePoints)));

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void keyBoardSpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_DOWN:
		if (canMoveDown()) {
			tile->moveDown();
			glutPostRedisplay();
		}
		break;

	case GLUT_KEY_UP:
		if (canRotate()) {
			tile->rotate();
			glutPostRedisplay();
		}
		break;

	case GLUT_KEY_LEFT:
		if (canMoveLeft()) {
			tile->moveLeft();
			glutPostRedisplay();
		}
		break;

	case GLUT_KEY_RIGHT:
		if (canMoveRight()) {
			tile->moveRight();
			glutPostRedisplay();
		}
		break;

	default:
		break;
	}
}

void keyBoard(unsigned char key, int x, int y) {
	switch (key) {
	case 113:
		if (tile != NULL) {
			delete tile;
			tile = NULL;
		}
		exit(EXIT_SUCCESS);

	case 114:
		if (tile != NULL) {
			delete tile;
			tile = NULL;
		}
		restart();
		if (tile == NULL) {
			generateTile();
		}
		break;

	default:
		break;
	}
}

void closeWindow() {
	if (tile != NULL) {
		delete tile;
		tile = NULL;
	}

	exit(EXIT_SUCCESS);
}

void display() {
	std::vector<std::vector<int>> gridsMap(game.getGridsMap()); //error
	std::vector<vec2> pointsVector;
	std::vector<vec3> colorsVector;

	//for (int i = 0; i < Rows; i++) {
	//	for (int j = 0; j < Columns; j++) {
	//		if (gridsMap[i][j]) {
	//			// draw that grid
	//			std::vector<GLfloat> grid = translateGrid(j, i);
	//			for (unsigned int k = 0; k < grid.size(); k += 2) {
	//				pointsVector.push_back(vec2(grid[k], grid[k + 1]));
	//				colorsVector.push_back(game.getGridColor(j, i));
	//			}
	//		}
	//	}
	//}

	int pointsCount = 0;
	int colorsCount = 0;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < Columns; j++) {
			if (gridsMap[i][j]) {
				// draw that grid
				std::vector<GLfloat> grid = translateGrid(j, i);
				for (unsigned int k = 0; k < grid.size(); k += 2) {
					points[pointsCount++] = vec2(grid[k], grid[k + 1]);
					colors[colorsCount++] = game.getGridColor(j, i);
				}
			}
		}
	}

	std::vector<GLfloat> tilePoints = translateTile();
	for (unsigned int i = 0; i < tilePoints.size(); i += 2) {
		points[pointsCount++] = vec2(tilePoints[i], tilePoints[i + 1]);
		colors[colorsCount++] = tile->getColor();
	}

	//const int pointArraySize = pointsVector.size() * sizeof(vec2);
	//const int colorArraySize = colorsVector.size() * sizeof(vec3);

	glGenVertexArrays(1, &vaoGrid);
	glBindVertexArray(vaoGrid);

	GLuint bufferGrid;
	glGenBuffers(1, &bufferGrid);
	glBindBuffer(GL_ARRAY_BUFFER, bufferGrid);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vec2) * pointsCount + sizeof(vec3) * colorsCount, points, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vec2) * pointsCount, points);
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(vec2) * pointsCount, sizeof(vec3) * colorsCount, colors);

	GLuint gridProgram = InitShader("vshader.glsl", "fshader.glsl");
	glUseProgram(gridProgram);

	GLuint gridLoc = glGetAttribLocation(gridProgram, "vPosition");
	glEnableVertexAttribArray(gridLoc);
	glVertexAttribPointer(gridLoc, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));

	GLuint vGridColor = glGetAttribLocation(gridProgram, "vColor");
	glEnableVertexAttribArray(vGridColor);
	glVertexAttribPointer(vGridColor, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(vec2) * pointsCount));

	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(vaoGrid);
	glDrawArrays(GL_QUADS, 0, pointsCount);

	glBindVertexArray(vaoLine);
	glDrawArrays(GL_LINES, 0, NumberLinePoints);

	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Tetris");

	glewExperimental = GL_TRUE;
	glewInit();
	srand(time(NULL));
	init();

	glutDisplayFunc(display);
	glutTimerFunc(500, gameProcess, 0);
	glutKeyboardFunc(keyBoard);
	glutSpecialFunc(keyBoardSpecial);
	glutCloseFunc(closeWindow);

	glutMainLoop();

	return 0;
}