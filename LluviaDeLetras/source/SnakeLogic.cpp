#include "SnakeLogic.h"
#include <iostream>
#include <windows.h>

SnakeLogic::SnakeLogic()
{
	score = 0;
	record = 0;
	randomNumber = 0;
	randomChar = ' ';
}

SnakeLogic::SnakeLogic(int height, int width) : height(height), width(width)
{
	
	gameOver = false;
	heightToDie = height - 2;
	
	score = 0;
	record = 0;
	randomNumber = 0;
	randomChar = ' ';
}

SnakeLogic::~SnakeLogic()
{
	//delete lluviaDeLetrasDrawer;
}



void SnakeLogic::Start(ConsoleDrawer* drawer, PlayerInput* inputManager)
{
	input = inputManager;

	lluviaDeLetrasDrawer = new LluviaDeLetrasDrawer(height, width, drawer);
	//std::cout << "LOGIC - Start" << std::endl;
	//srand(time(NULL));
	srand(clock());
	for (size_t i = 1; i < width-1; i++)
	{
		randomNumber = std::rand() % 26;
		randomChar = 'a' + randomNumber;
		//AddFallingChar(i-1,i+1, randomChar);
	}
}

void SnakeLogic::Update(float deltaTime)
{
	//std::cout << "LOGIC - Update" << std::endl;
	elapsedTime += deltaTime;
	
	if (!gameOver) 
	{
		lluviaDeLetrasDrawer->DrawBoard();
		lluviaDeLetrasDrawer->DrawScore(score);
		lluviaDeLetrasDrawer->DrawRecord(record);
	
		
	
	

		if (elapsedTime > timeToSpawn)
		{
			//SpawnChar();
			elapsedTime = 0;
			indice++;	
		
		}
	}
	else 
	{
		lluviaDeLetrasDrawer->DrawGameOver();
	}
	
}

void SnakeLogic::FastUpdate()
{
	
	if (!gameOver)
	{
	InputPlayer();

	}
	else 
	{
		if(input->theGivenCharIsPress('r'))
		{
			Restart();
		}
		
	}
}

void SnakeLogic::ReviveAll()
{
	randomNumber = std::rand() % 26;
	randomChar = 'a' + randomNumber;
	for (size_t i = 0; i < width - 1; i++)
	{
		randomNumber = std::rand() % 26;
		randomChar = 'a' + randomNumber;
		//fallingCharList[i].Revive(randomChar);
		//AddFallingChar(i - 1, i + 1, randomChar);
	}
}

void SnakeLogic::SpawnFruit()
{
}


void SnakeLogic::InputPlayer()
{
	if(input->ArrowLeftIsPress())
	{
		//lluviaDeLetrasDrawer->ChangeVerticalLine(4, "left");
		lluviaDeLetrasDrawer->Debug('l');
	}
	else if(input->ArrowRightIsPress())
	{}
	else if(input->ArrowUpIsPress())
	{}
	else if(input->ArrowDownIsPress())
	{}
	for (size_t i = 0; i < width - 2; i++)
	{
		if (input->theGivenCharIsPress(' '))
			{
				//fallingCharList[i].TakeDamage();
			
			}
			
		
	}

}





void SnakeLogic::Restart()
{
	gameOver = false;
	score = 0;
	elapsedTime = 0;
	ReviveAll();
}
