#include "GameEngine.h"
#include <windows.h>


GameEngine::GameEngine(int framerate, int height, int width, LogicManager* logic)
{
	timeManager = new TimeManager(framerate);	
	drawManager = new ConsoleDrawer(height, width);
	inputManager = new PlayerInput();
	logicManager = logic;
}

GameEngine::~GameEngine()
{
	//delete logicManager;
	delete drawManager;
	delete timeManager;
	delete inputManager;
}

void GameEngine::Start()
{
	logicManager->Start(drawManager,inputManager);
	drawManager->Start();

	MainLoop();
}

void GameEngine::MainLoop()
{
	bool shouldExitMainLoop = false;

	while (!shouldExitMainLoop)
	{
		timeManager->Update();
		inputManager->Update();

		logicManager->FastUpdate();
		if (timeManager->ShouldExecuteNextFrame())
		{
			Update(timeManager->GetElapsedTime());
			Draw();
			timeManager->NextFrameExecuted();
		}

		if (GetKeyState(VK_ESCAPE) & 0x8000)
			shouldExitMainLoop = true;
	}
}

void GameEngine::Update(float deltaTime)
{
	logicManager->Update(deltaTime);
}

void GameEngine::Draw()
{
	drawManager->Draw();
}