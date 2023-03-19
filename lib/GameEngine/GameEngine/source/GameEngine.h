#pragma once
#include "ConsoleDrawer.h"
#include "TimeManager.h"
#include "PlayerInput.h"
#include "LogicManager.h"

class GameEngine
{
	TimeManager* timeManager = nullptr;
	ConsoleDrawer* drawManager = nullptr;
	LogicManager* logicManager = nullptr;
	PlayerInput* inputManager = nullptr;
	GameEngine();
public:
	GameEngine(int framerate, int height, int width,LogicManager* logic);
	~GameEngine();

	void Start();
	void MainLoop();
	void Update(float deltaTime);
	void Draw();
};

