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
	snakeDirection = Right;
	score = 0;
	record = 0;
	randomNumber = 0;
	randomChar = ' ';
	//fruits = new std::vector<Fruit*>;
	SnakePositions = new std::vector<PositionVector>;
	IncrementSnake();
	
}

SnakeLogic::~SnakeLogic()
{
	for (auto f = fruits.begin(); f != fruits.end(); ++f) {
		delete* f;
	}
	//delete fruits;
	delete SnakePositions;
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
	SpawnFruit();
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
		lluviaDeLetrasDrawer->DrawFruits(fruits);
		lluviaDeLetrasDrawer->DrawSnake(SnakePositions);
		MoveSnake();
	
	

		if (elapsedTime > timeToSpawn)
		{
			SpawnFruit();
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
	randomPosY = std::rand() % height-1;
	if(randomPosY<2)
	{
		randomPosY = 4;
	}
	if(randomPosY==height-1)
	{
		randomPosY = height-2;
	}
	randomPosX = std::rand() % width-1;
	if (randomPosX == 0)
	{
		randomPosX = 2;
	}
	if (randomPosX == width-1)
	{
		randomPosX = width-2;
	}
	Fruit* fruit = new Fruit(randomPosX, randomPosY);
	fruits.push_back(fruit);
}


void SnakeLogic::InputPlayer()
{
	if(input->ArrowLeftIsPress())
	{
		//lluviaDeLetrasDrawer->ChangeVerticalLine(4, "left");
		
	}
	else if(input->ArrowRightIsPress())
	{
	}
	else if(input->ArrowUpIsPress())
	{
	}
	else if(input->ArrowDownIsPress())
	{
	}
}





void SnakeLogic::Restart()
{
	gameOver = false;
	score = 0;
	elapsedTime = 0;
	ReviveAll();
}

void SnakeLogic::IncrementSnake()
{
	if(SnakePositions->size() == 0)
	{
		PositionVector pos(width / 2 - 1, height / 2-1);
		SnakePositions->push_back(pos);

		pos = PositionVector (width / 2 -1, height / 2);
		SnakePositions->push_back(pos);
		
		pos = PositionVector(width / 2, height / 2);
		SnakePositions->push_back(pos);
	}
}

void SnakeLogic::MoveSnake()
{
	switch (snakeDirection)
	{
	case Right:
	{
		
		PositionVector aux = SnakePositions->back();
		PositionVector actualPos;
		//PositionVector aux = ;// (std::prev(SnakePositions->end())->getX(), std::prev(SnakePositions->end())->getY());
		if (!(aux.getX() > width))
		{
			std::prev(SnakePositions->end())->setX(std::prev(SnakePositions->end())->getX() + 1);
			for (auto it = std::prev( std::prev(SnakePositions->end())); it != SnakePositions->begin(); --it)
			{
				actualPos.setX(it->getX()); 
				actualPos.setY(it->getY());
				
				it->setY(aux.getY());
				it->setX(aux.getX());
				aux = actualPos;
			}
			SnakePositions->begin()->setY(aux.getY());
			SnakePositions->begin()->setX(aux.getX());
		}
	}

		break;
	case Left:
		break;
	case Up:
		break;
	case Down:
		break;
	default:
		break;
	}
}
