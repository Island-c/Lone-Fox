#include"point.h"
#include"tools.h"
#include<iostream>

void Point::Print()  ///Êä³ö·½¿é
{
	SetCursorPosition(x, y);
	std::cout << "¡ö";
}

void Point::PrintCircular()
{
	SetCursorPosition(x, y);
	std::cout << "¡ñ";
}

void Point::Clear() {
	SetCursorPosition(x, y);
	std::cout << " ";
}

void Point::ChangePosition(const int x, const int y)
{
	this->x = x;
	this->y = y;

}
