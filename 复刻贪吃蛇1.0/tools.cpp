#include"tools.h"
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

void SetWindowSize(int cols, int lines)
{
	system("title Ã∞≥‘…ﬂ");
	system("mode con cols=82 lines=32");
}

void SetCursorPosition(const int x, const int y)
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void SetBackColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_BLUE | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
}

void SetColor(int colorID) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
}