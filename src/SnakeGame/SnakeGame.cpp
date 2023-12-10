#include "SnakeGame.h"

SnakeObject::SnakeObject() {
	type = SNAKE_EMPTY;
}

SnakeObject::SnakeObject(SnakeObjectTypes newType) : SimpleBox() {
	type = newType;
}

SnakeGame::SnakeGame() {
	//grid[1][7] = createPlayerPart();
	//grid[2][7] = createPlayerPart();
	grid[3][7] = createPlayerPart();
	snakeSpeedInSeconds = 1.0f;
	ellapsedTime = 0.0f;
	
	direction = RIGHT;
	
	headPositionX = 3;
	headPositionY = 7;
}

void SnakeGame::tick(float* delta) {
	if (ellapsedTime > snakeSpeedInSeconds) {
		moveSnake();
		ellapsedTime = 0.0f;
	}

	for (int x = 0; x < gridSize; x++)
	{
		for (int y = 0; y < gridSize; y++)
		{
			if (grid[x][y].type != SNAKE_EMPTY) {
				grid[x][y].setTransform(x, y, 0);
				grid[x][y].render();
			}
		}
	}

	InputSystem *inputSystem = InputSystem::getInstance();

	if (inputSystem->GetInputDown(SDL_SCANCODE_UP)) {
		direction = UP;
	}

	if (inputSystem->GetInputDown(SDL_SCANCODE_DOWN)) {
		direction = DOWN;
	}

	if (inputSystem->GetInputDown(SDL_SCANCODE_RIGHT)) {
		direction = RIGHT;
	}

	if (inputSystem->GetInputDown(SDL_SCANCODE_LEFT)) {
		direction = LEFT;
	}

	std::cout << *delta << std::endl;

	ellapsedTime += *delta;
}

SnakeObject SnakeGame::createPlayerPart() {
	SnakeObject playerPart(SNAKE_PLAYER);

	playerPart.setScale(0.5f, 0.5f, 1.0f);

	return playerPart;
}

void SnakeGame::moveSnake() {
	int nextHeadPositionX = headPositionX;
	int nextHeadPositionY = headPositionY;

	switch (direction)
	{
		case UP:
			nextHeadPositionY++;
			break;
		case DOWN:
			nextHeadPositionY--;
			break;
		case LEFT:
			nextHeadPositionX--;
			break;
		case RIGHT:
			nextHeadPositionX++;
			break;
	}

	if ((nextHeadPositionX < gridSize && nextHeadPositionX > 0) && (nextHeadPositionY < gridSize && nextHeadPositionY > 0)) {
		grid[nextHeadPositionX][nextHeadPositionY] = grid[headPositionX][headPositionY];
		grid[headPositionX][headPositionY] = SnakeObject(SNAKE_EMPTY);
		
		headPositionX = nextHeadPositionX;
		headPositionY = nextHeadPositionY;
	}
}

