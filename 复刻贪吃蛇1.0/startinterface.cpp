#include"startinterface.h"
#include <windows.h>

void StartInterface::PrintFirst()  //从左边屏幕边框到完全出现。
{
	for (auto& point : startsnake) {
		point.Print();
		Sleep(speed);
	}
}

void StartInterface::PrintSecond()  //从屏幕左边向右移动
{
	for (int i = 10; i != 40; ++i)
	{
		///计算蛇头的下一个位置， 并将其压入startsnake中，绘制出来。
		int j = (((i - 2) % 8) < 4) ? (15 + (i - 2) % 8) : (21 - (i - 2) % 8);
		startsnake.emplace_back(Point(i, j));
		startsnake.back().Print();
		startsnake.front().Clear();
		startsnake.pop_front();
		Sleep(speed);
	}
}

void StartInterface::PrintThird()
{
	while (!startsnake.empty() || textsnake.back().GetX() < 33) ///33为指定停止位置
	{
		if (!startsnake.empty())
		{
			startsnake.front().Clear();
			startsnake.pop_front();
		}
		ClearText();
		PrintText();
		Sleep(speed);
	}
}

void StartInterface::PrintText()
{
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
		{
			point.Print();
		}
	}
}

void StartInterface::ClearText()
{
	for (auto& point : textsnake)
	{
		if (point.GetX() >= 0)
			point.Clear();
		point.ChangePosition(point.GetX() + 1, point.GetY()); //清除文字，再向右一格 再输出
	}
}

void StartInterface::Action()
{
	PrintFirst();
	PrintSecond();
	PrintThird();
}
