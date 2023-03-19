#pragma once

class ConsoleDrawer
{
	int height = 0;
	int width = 0;
	char* screen = nullptr;

	ConsoleDrawer();

public:
	void ResetScreen(char character);
	ConsoleDrawer(int height, int width);
	~ConsoleDrawer();

	void Start();
	void Draw();

	void DrawAtPos(char character, int h, int w);
	void DrawAtPos(const char* string, int h, int w);
};

