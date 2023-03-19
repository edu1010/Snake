#include "LluviaDeLetrasDrawer.h"

LluviaDeLetrasDrawer::LluviaDeLetrasDrawer(int h, int w, ConsoleDrawer* drawer)
{
	drawManager = drawer;
	height = h;
	width = w;

}

void LluviaDeLetrasDrawer::ChangeVerticalLine(int line,char c)
{
	for (size_t h = 0; h < height; h++)
	{
		for (size_t w = 0; w < width; w++)
		{
			if (w == line)
			{
				drawManager->DrawAtPos(c, h, w);

			}
		}
	}
}

void LluviaDeLetrasDrawer::ChangeVerticalLine(int line, const char* string)
{
	for (size_t h = 0; h < height; h++)
	{
		for (size_t w = 0; w < width; w++)
		{
			if (w == line)
			{
				if (string[h] != '\0')
				{
					drawManager->DrawAtPos(string[h], h, w);
				}
				else 
				{
					drawManager->DrawAtPos(' ', h, w);
				}

			}
		}
	}

}
void LluviaDeLetrasDrawer::DrawScore(int score)
{
	if (score > 99) 
	{
		int digit1 = score % 10; 
		score /= 10; 

		int digit2 = score % 10; 
		score /= 10; 

		int digit3 = score % 10; 


		char caracter1 = digit1 + '0';
		char caracter2 = digit2 + '0';
		char caracter3 = digit3 + '0';

		drawManager->DrawAtPos(caracter1, 1, 9);
		drawManager->DrawAtPos(caracter2, 1, 8);
		drawManager->DrawAtPos(caracter3, 1, 7);
	}
	if(score>9)
	{
		int digit1 = score % 10; 
		score /= 10; 

		int digit2 = score % 10;
		char caracter1 = digit1 + '0';
		char caracter2 = digit2 + '0';
		drawManager->DrawAtPos(caracter1, 1, 8);
		drawManager->DrawAtPos(caracter2, 1, 7);

	}
	if (score < 10) 
	{
		char caracter = score + '0';
		drawManager->DrawAtPos(caracter, 1, 7);
	}
}

void LluviaDeLetrasDrawer::DrawRecord(int record)
{
	if (record > 999) 
	{
		record = 999;
	}
	if (record > 99)
	{
		int digit1 = record % 10;
		record /= 10;

		int digit2 = record % 10;
		record /= 10;

		int digit3 = record % 10;


		char caracter1 = digit1 + '0';
		char caracter2 = digit2 + '0';
		char caracter3 = digit3 + '0';

		drawManager->DrawAtPos(caracter1, 1, width -3);
		drawManager->DrawAtPos(caracter2, 1, width-4);
		drawManager->DrawAtPos(caracter3, 1, width-5);
	}
	if (record > 9)
	{
		int digit1 = record % 10;
		record /= 10;

		int digit2 = record % 10;
		char caracter1 = digit1 + '0';
		char caracter2 = digit2 + '0';
		drawManager->DrawAtPos(caracter1, 1, width-4);
		drawManager->DrawAtPos(caracter2, 1, width-5);

	}
	if (record < 10)
	{
		char caracter = record + '0';
		drawManager->DrawAtPos(caracter, 1, width-5);
	}
}
void LluviaDeLetrasDrawer::DrawBoard()
{
	//https://theasciicode.com.ar/extended-ascii-code/box-drawing-character-double-line-upper-left-corner-ascii-code-201.html
	drawManager->ResetScreen(' ');
	drawManager->DrawAtPos(201, 0, 0);
	drawManager->DrawAtPos(187, 0, width-1);

	drawManager->DrawAtPos("SCORE:", 1, 1);
	drawManager->DrawAtPos("RECORD:", 1, width - 12);
	for (size_t i = 1; i < width-1; i++)
	{
		drawManager->DrawAtPos(205, 0, i);
	}
		drawManager->DrawAtPos(186, 1, 0);
		drawManager->DrawAtPos(186, 1, width-1);
		drawManager->DrawAtPos(185, 2, width-1);
		drawManager->DrawAtPos(204, 2, 0);
		for (size_t i = 2; i < height-1; i++)
		{
			drawManager->DrawAtPos(186, i, 0);
			drawManager->DrawAtPos(186, i, width - 1);
		}
	for (size_t i = 1; i < width-1; i++)
	{
		drawManager->DrawAtPos(205, 2, i);
	}
	
	for (size_t i = 1; i < width-1; i++)
	{
		drawManager->DrawAtPos('~', height-3, i);
	}

	for (size_t i = 1; i < width-1; i++)
	{
		drawManager->DrawAtPos(205, height-1,i);
	}
	drawManager->DrawAtPos(186, height-1,0);//Vertical

	drawManager->DrawAtPos(200, height-1,0);
	drawManager->DrawAtPos(188, height-1,width-1);
	//ChangeVerticalLine(0,201);
}

void LluviaDeLetrasDrawer::DrawGameOver()
{
	drawManager->ResetScreen(' ');
	drawManager->DrawAtPos("GAME OVER", height / 2, (width/2)-5);
	drawManager->DrawAtPos("PRESS R TO RESTART", (height / 2)+1, (width/2)-9);
	

}

void LluviaDeLetrasDrawer::DrawCharInLine(int line, int indexOfLine, char c)
{
	int index = 2;
	for (size_t h = 2; h < height; h++)
	{
		for (size_t w = 0; w < width; w++)
		{
			if (w == line)
			{
				index++;
				if (index == indexOfLine)
				{
					drawManager->DrawAtPos(c, h, w);
				}
				else if(index< indexOfLine)
				{
					drawManager->DrawAtPos('.', h, w);

				}
			}
		}
	}

}
void LluviaDeLetrasDrawer::Debug(char c) 
{
	drawManager->DrawAtPos(c, height/2, width/2);
}
void LluviaDeLetrasDrawer::Explosion(int line, int indexOfLine)
{
	int index = 0;
	for (size_t h = 0; h < height; h++)
	{
		for (size_t w = 0; w < width; w++)
		{
			if (w == line)
			{
				index++;

				if (index == indexOfLine)
				{
					if (h - 1 > 0&& w-1>0&& w<width) 
					{
						drawManager->DrawAtPos('\\', h-1, w - 1);
						drawManager->DrawAtPos('/', h - 1, w + 1);
					}
					if (h + 1 > 0 && w - 1 > 0 && w < width)
					{
						drawManager->DrawAtPos('\\', h + 1, w + 1);
						drawManager->DrawAtPos('/', h + 1, w - 1);
					}

					drawManager->DrawAtPos('-', h, w - 1);
					drawManager->DrawAtPos('o', h, w);
					drawManager->DrawAtPos('-', h, w + 1);
				}
				else if (index < indexOfLine)
				{
					drawManager->DrawAtPos('.', h, w);

				}

			}
		}
	}
}
void LluviaDeLetrasDrawer::DrawCharInLineShield(int line, int indexOfLine, char c)
{
	int index = 2;
	for (size_t h = 2; h < height; h++)
	{
		for (size_t w = 0; w < width; w++)
		{
			if (w == line)
			{
				index++;
				if (index == indexOfLine)
				{
					drawManager->DrawAtPos('[', h, w-1);
					drawManager->DrawAtPos(c, h, w);
					drawManager->DrawAtPos(']', h, w+1);
				}
				else if (index < indexOfLine)
				{
					drawManager->DrawAtPos('.', h, w);

				}
			}
		}
	}
}
