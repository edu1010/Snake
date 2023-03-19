#pragma once
#include "ConsoleDrawer.h"
#include "LluviaDeLetrasDrawer.h"
#include "FallingChar.h"
#include "PlayerInput.h"
#include <vector>

#include "LogicManager.h"
#include <List>
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
	char  randomChar=' ';
	LluviaDeLetrasDrawer* lluviaDeLetrasDrawer =nullptr;
	SnakeLogic(int height, int width);
	~SnakeLogic();
	
	void Start(ConsoleDrawer* drawer, PlayerInput* inputManager) override;
	void Update(float deltaTime) override;
	void FastUpdate() override;


	void ReviveAll();
	void SpawnFruit();

	void InputPlayer();
	
	void Restart();
};

