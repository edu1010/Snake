#pragma once
#include "ConsoleDrawer.h"
#include "LluviaDeLetrasDrawer.h"
#include "FallingChar.h"
#include "PlayerInput.h"
#include <vector>

#include "LogicManager.h"
#include "PositionVector.h"
#include "Fruit.h"
enum Directions
{
	Right,
	Left,
	Up,
	Down
};
class SnakeLogic:public LogicManager
{
	SnakeLogic();
	int height = 0;
	int width = 0;

	int indice = 0;
	float elapsedTime = 0;

	float timeToSpawn = 1;
	int heightToDie = 0;
	bool gameOver = false;
	PlayerInput* input =nullptr;
public:
	int   score = 0;
	int   record = 0;
	int   randomNumber=0;
	int   randomPosX=0;
	int   randomPosY=0;
	char  randomChar=' ';
	std::vector<Fruit*> fruits;
	std::vector<PositionVector>* SnakePositions=nullptr;
	LluviaDeLetrasDrawer* lluviaDeLetrasDrawer =nullptr;
	Directions snakeDirection;
	SnakeLogic(int height, int width);
	~SnakeLogic();
	
	void Start(ConsoleDrawer* drawer, PlayerInput* inputManager) override;
	void Update(float deltaTime) override;
	void FastUpdate() override;

	void IncremetScore();
	void ReviveAll();
	void SpawnFruit();

	void InputPlayer();
	
	void Restart();
	void IncrementSnake();
	void IncrementSnake(PositionVector pos);
	void MoveSnake();
	void ChekColisions();

};

