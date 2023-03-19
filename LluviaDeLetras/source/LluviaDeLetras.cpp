#include "GameEngine.h"
#include "SnakeLogic.h"
int main()
{
	SnakeLogic* logic = new SnakeLogic(20,80);
	GameEngine* gameEngine = new GameEngine(1, 20, 80, logic);
	gameEngine->Start();
}

