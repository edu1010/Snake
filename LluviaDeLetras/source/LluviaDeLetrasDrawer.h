#pragma once
#include "ConsoleDrawer.h"
class LluviaDeLetrasDrawer
{
	ConsoleDrawer* drawManager;
	int height, width;
	LluviaDeLetrasDrawer();
public:
	LluviaDeLetrasDrawer(int h,int w, ConsoleDrawer* drawer);
	~LluviaDeLetrasDrawer();
	void ChangeVerticalLine(int line,char c);
	void ChangeVerticalLine(int line, const char* string);
	void DrawScore(int score);
	void DrawRecord(int record);
	void DrawBoard();
	void DrawGameOver();
	void DrawCharInLine(int line, int indexOfLine, char c);

	void Debug(char c);

	void Explosion(int line, int indexOfLine);
	
	void DrawCharInLineShield(int line, int indexOfLine, char c);
};

