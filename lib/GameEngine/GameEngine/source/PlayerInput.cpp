#include "PlayerInput.h"
#include "Windows.h"

PlayerInput::PlayerInput()
{
	pressedKeys = new char[255];
	for (size_t i = 0; i < 255; i++)
	{
		pressedKeys[i] = ' ';
	}
}

PlayerInput::~PlayerInput()
{
	delete[]pressedKeys;
}

void PlayerInput::GetPresedKeys()
{
	totalKeysPressedAtTheSameTime = 0;
	for (int i = 0; i < 255; i++) //a to Z in ascii
	{
		char letra = char(i);
		if (GetKeyState(char(i)) & 0x8000)
		{
			pressedKeys[totalKeysPressedAtTheSameTime] = char(i);
			totalKeysPressedAtTheSameTime++;

		}
	}
	//debug
	for (size_t i = 0; i < totalKeysPressedAtTheSameTime; i++)
	{
		char letra = pressedKeys[i];
	}
}

void PlayerInput::Update()
{
	GetPresedKeys();
}

bool PlayerInput::theGivenCharIsPress(char c)
{
	//inferior a 90 sumar 32 superior restar  intento de ignorar mayus
	for (size_t i = 0; i < totalKeysPressedAtTheSameTime; i++)
	{
		if (pressedKeys[i] == c )
		{
			return true;
		}
		if (c <= 90 && pressedKeys[i]>90) {
			if (c + 32 == c) 
			{
				return true;
			}
		}
		else
		{
			if (c > 90 && pressedKeys[i] <= 90) 
			{
				if (c - 32 == pressedKeys[i]) 
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool PlayerInput::ArrowUpIsPress()
{
	if (GetKeyState(VK_UP) & 0x8000)
		return true;
	else
		return false;

}

bool PlayerInput::ArrowDownIsPress()
{
	if (GetKeyState(VK_DOWN) & 0x8000)
		return true;
	else
		return false;
}

bool PlayerInput::ArrowLeftIsPress()
{
	if (GetKeyState(VK_LEFT) & 0x8000)
		return true;
	else
		return false;
}

bool PlayerInput::ArrowRightIsPress()
{
	if (GetKeyState(VK_RIGHT) & 0x8000)
		return true;
	else
		return false;
}
