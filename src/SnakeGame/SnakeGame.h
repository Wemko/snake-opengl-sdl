#pragma once

#include "../SimpleBox/SimpleBox.h";
#include  "../InputSystem/InputSystem.h";

enum SnakeObjectTypes { SNAKE_EMPTY, SNAKE_BONUS, SNAKE_PLAYER };
enum SnakeDirection { UP, DOWN, LEFT, RIGHT};

const int gridSize = 15;

class SnakeObject : public SimpleBox {
public:
    SnakeObject();
    SnakeObject(SnakeObjectTypes newType);
    SnakeObjectTypes type;
};

class SnakeGame
{
public:
    SnakeGame();
    void tick(float* delta);

private:
    SnakeObject grid[gridSize][gridSize];
    SnakeObject createPlayerPart();
    SnakeObject createBonusPart();
    void moveSnake();
    float ellapsedTime;
    float snakeSpeedInSeconds;
    SnakeDirection direction;
    int headPositionX;
    int headPositionY;
};

