#include "ConsoleDrawer.h"
#include <iostream>

ConsoleDrawer::ConsoleDrawer()
{
}

ConsoleDrawer::ConsoleDrawer(int height, int width): height(height), width(width)
{
	screen = new char[height * width];
}

ConsoleDrawer::~ConsoleDrawer()
{
	delete[] screen;
}

void ConsoleDrawer::Start()
{
	ResetScreen('*');

	DrawAtPos(' ', 4, 46);
	DrawAtPos('O', 2, 2);
	DrawAtPos(' ', 1, 59);
	DrawAtPos('@', 15, 62);
	DrawAtPos('+', 8, 22);

}

void ConsoleDrawer::Draw()
{
	system("cls");
	
	for (size_t h = 0; h < height; h++)
	{
		for (size_t w = 0; w < width; w++)
			std::cout << screen[h*width+w];

		std::cout << std::endl;
	}
}

void ConsoleDrawer::DrawAtPos(char character, int h, int w)
{
	screen[h * width + w] = character;
}

void ConsoleDrawer::DrawAtPos(const char* string, int h, int w)
{
	int i = 0;
	while (string[i] != '\0' && i < 999)
	{
		char* puntero = &(screen[h * width + w + i]);
		*puntero = string[i];
		i++;
	}
}

void ConsoleDrawer::ResetScreen(char character)
{
	for (size_t i = 0; i < height * width; i++)
		screen[i] = character;
}
