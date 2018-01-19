#include <iostream>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include"controller.h"
#include"tools.h"
#include"startinterface.h"
#include"map.h"
#include"snake.h"
#include"food.h"

void Controller::Start()  //开始界面
{
	SetWindowSize(41, 32); /// 窗口大小
	SetColor(2);///动画颜色
	StartInterface *start = new StartInterface(); ///为什么要用动态分配内存？
	start->Action(); /// k开始动画
	delete start; 

	//设置光标位置，输出提示语
	SetCursorPosition(13, 26);
	std::cout << "Press any key to start...";
	SetCursorPosition(13, 27);
	system("pause");

}

void Controller::Select()
{
	SetColor(3);
	SetCursorPosition(13, 26);
	std::cout << "                          ";
	SetCursorPosition(13, 27);
	std::cout << "                          ";
	SetCursorPosition(6, 21);
	std::cout << "请选择游戏难度";
	SetCursorPosition(6, 22);
	std::cout << "（上下键选择，回车键确认）";
	SetCursorPosition(27, 22);
	SetBackColor();  ///设置背景色，表示当前选中
	std::cout << "简单模式";
	SetCursorPosition(27, 24);
	SetColor(3);
	std::cout << "普通模式";
	SetCursorPosition(27, 26);
	std::cout << "困难模式";
	SetCursorPosition(27, 28);
	std::cout << "炼狱模式";
	SetCursorPosition(0, 31);
	score = 0;

	///上下方向键选择 实现如下：
	int ch; // 记录按键
	key = 1; ///记录选中项
	bool flag = false; ///记录是否键入enter
	while ((ch = _getch()))
	{
		switch(ch)
		{
		case 72: //up 上
			if (key > 1)
			{
				switch (key)
				{

				case 2:
					SetCursorPosition(27, 22);
					SetBackColor();
					std::cout << "简单模式";

					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "普通模式";

					--key;
					break;
				case 3:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "普通模式";

					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "困难模式";

					--key;
					break;
				case 4:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难模式";

					SetCursorPosition(27, 28);
					SetColor(3);
					std::cout << "炼狱模式";

					--key;
					break;

				}
			}
			break;

		case 80:///下方向键
			if (key < 4)
			{
				switch (key)
				{
				case 1:
					SetCursorPosition(27, 24);
					SetBackColor();
					std::cout << "普通模式";
					SetCursorPosition(27, 22);
					SetColor(3);
					std::cout << "简单模式";
					++key;
					break;
				case 2:
					SetCursorPosition(27, 26);
					SetBackColor();
					std::cout << "困难模式";
					SetCursorPosition(27, 24);
					SetColor(3);
					std::cout << "普通模式";
					++key;
					break;
				case 3:
					SetCursorPosition(27, 28);
					SetBackColor();
					std::cout << "炼狱模式";
					SetCursorPosition(27, 26);
					SetColor(3);
					std::cout << "困难模式";
					++key;
					break;
				}
			}
			break;

		case 13:  ///回车键
			flag = true;
			break;
		default:
			break;

		}
		if (flag) break;
		SetCursorPosition(0, 31);  ///光标置于左下角，避免因为光标闪烁影响游戏体验。


	}
	switch (key) ///speed的值越小 蛇的移动速度越快
	{
	case 1:
		speed = 240;
		break;
	case 2:
		speed = 120;
		break;
	case 3:
		speed = 60;
		break;
	case 4:
		speed = 30;
		break;
	default:
		break;
	}
}


void Controller::DrawGame()
{
	system("cls"); ///清屏

	///绘制地图
	SetColor(3);
	Map *init_map = new Map();
	init_map->PrintInitmap();
	delete init_map;

	///绘制侧边栏
	SetColor(3);
	SetCursorPosition(33, 1);
	std::cout << "Greedy Snake";
	SetCursorPosition(34, 2);
	std::cout << "贪吃蛇";
	SetCursorPosition(31, 4);
	std::cout << "难度:";
	SetCursorPosition(36, 5);

	switch (key)
	{
	case 1 :
		std::cout << "简单模式";
		break;
	case 2:
		std::cout << "普通模式";
		break;
	case 3:
		std::cout << "困难模式";
		break;
	case 4:
		std::cout << "炼狱模式";
		break;
	default:
		break;
	}
	SetCursorPosition(31, 7);
	std::cout << "得分:";
	SetCursorPosition(37, 8);
	std::cout << "     0";
	SetCursorPosition(33, 13);
	std::cout << "方向键移动";
	SetCursorPosition(33, 15);
	std::cout << "ESC键暂停";
}


void Controller::UpdateScore(const int& tmp)
{
	score += key * 10 * tmp;
}

void Controller::RewriteScore()
{
	///为了保证分数尾部对齐。将最大分数设为6位，计算当前分数位数，将剩余位数用空格补全。再输出分数
	SetCursorPosition(37, 8);
	SetColor(11);
	int bit = 0;
	int tmp = score;
	while (tmp != 0)
	{
		++bit;
		tmp /= 10;

	}

	for (int i = 0; i < (6 - bit); ++i)
	{
		std::cout << " ";
	}
	std::cout << score;
}

int Controller::Menu() ///选择菜单
{
	///绘制界面
	SetColor(11);
	SetCursorPosition(32, 19);
	std::cout << "菜单:";
	Sleep(100);
	SetCursorPosition(34, 21);
	SetBackColor();
	std::cout << "继续游戏";
	Sleep(100);
	SetCursorPosition(34, 23);
	SetColor(11);
	std::cout << "重新开始";
	Sleep(100);
	SetCursorPosition(34, 25);
	std::cout << "退出游戏";
	SetCursorPosition(0, 31);

	///选择内部实现部分
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 72 :  ///up
			if (tmp_key > 1)
			{
				switch (tmp_key)
				{
				case 2:
					SetCursorPosition(34, 21);
					SetBackColor();
					std::cout << "继续游戏";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "重新开始";
					--tmp_key;
					break;
				case 3:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "重新开始";
					SetCursorPosition(34, 25);
					SetColor(11);
					std::cout << "退出游戏";
					--tmp_key;
					break;
				}
			}
			break;
		case 80: ////DOWM
			if (tmp_key < 3)
			{
				switch (tmp_key)
				{
				case 1:
					SetCursorPosition(34, 23);
					SetBackColor();
					std::cout << "重新开始";
					SetCursorPosition(34, 21);
					SetColor(11);
					std::cout << "继续游戏";
					++tmp_key;
					break;
				case 2:
					SetCursorPosition(34, 25);
					SetBackColor();
					std::cout << "退出游戏";
					SetCursorPosition(34, 23);
					SetColor(11);
					std::cout << "重新开始";
					++tmp_key;
					break;
				}
			}
			break;
		case 13:  ///enter
			flag = true;
			break;
		default:
			break;
		}

		if (flag)  break;

		SetCursorPosition(0, 31);
	}
	return tmp_key; ///返回所指项目，让调用它的函数来处理。。
}

void Controller::Game()
{
	Start();  ///开始动画
	while (true)  ///一级循环？
	{
		Select();
		DrawGame();
		int tmp = PlayGame();
		if (tmp == 1)
		{
			system("cls");
			continue;
		}

		else if (tmp == 2)
			break;
		else
			break;

	}

}

int Controller::GameOver()
{
	/////绘制游戏结束界面
	Sleep(500);
	SetColor(11);
	SetCursorPosition(10, 8);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(30);
	SetCursorPosition(9, 9);
	std::cout << " ┃               Game Over !!!              ┃";
	Sleep(30);
	SetCursorPosition(9, 10);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 11);
	std::cout << " ┃              很遗憾！你挂了              ┃";
	Sleep(30);
	SetCursorPosition(9, 12);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 13);
	std::cout << " ┃             你的分数为：                 ┃";
	SetCursorPosition(24, 13);
	std::cout << score;
	Sleep(30);
	SetCursorPosition(9, 14);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 15);
	std::cout << " ┃   是否再来一局？                         ┃";
	Sleep(30);
	SetCursorPosition(9, 16);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 17);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 18);
	std::cout << " ┃    嗯，好的        不了，还是学习有意思  ┃";
	Sleep(30);
	SetCursorPosition(9, 19);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(9, 20);
	std::cout << " ┃                                          ┃";
	Sleep(30);
	SetCursorPosition(10, 21);
	std::cout << "━━━━━━━━━━━━━━━━━━━━━━";
	Sleep(100);
	SetCursorPosition(12, 18);
	SetBackColor();
	std::cout << "嗯，好的";
	SetCursorPosition(0, 31);


	///具体实现
	int ch;
	int tmp_key = 1;
	bool flag = false;
	while (ch = _getch())
	{
		switch (ch)
		{
		case 75: ///left
			if (tmp_key > 1)
			{
				SetCursorPosition(12, 18);
				SetBackColor();
				std::cout << "嗯，好的";
				SetCursorPosition(20, 18);
				SetColor(11);
				std::cout << "不了，还是学习有意思";
				--tmp_key;
			}
			break;
		case 77: ///right
			if (tmp_key < 2)
			{
				SetCursorPosition(20, 18);
				SetBackColor();
				std::cout << "不了，还是学习有意思";
				SetCursorPosition(12, 18);
				SetColor(11);
				std::cout << "嗯，好的";
				++tmp_key;
			}
			break;
		case 13:///enter
			flag = true;
			break;
		default :
			break;
		}

		if (flag)  break;
		SetCursorPosition(0, 31);  ////这两者的位置 可能引发奇怪的事。。。
	}

	SetColor(11);
	switch (tmp_key)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	default: return 1;
	}


}



int Controller::PlayGame()  ///游戏二级循环。(内部循环)
{
	////初始化蛇和食物
	Snake *csnake = new Snake();
	Food *cfood = new Food();
	SetColor(6);
	csnake->InitSnake();
	srand((unsigned)time(NULL)); ///随机数种子。。 若不设置，食物出现的位置will固定..
	cfood->DrawFood(*csnake);

	///游戏循环
	while (csnake->OverEdge() && csnake->HitItself()) ///是否撞墙 或者撞到自己
	{
		///游戏中的选择菜单
		if (!csnake->ChangeDirection())
		{
			int tmp = Menu();  ///绘制菜单
			switch (tmp)
			{
			case 1:  ///继续游戏
				SetCursorPosition(32, 19);
				std::cout << "        ";
				SetCursorPosition(34, 21);
				std::cout << "        ";
				SetCursorPosition(34, 23);
				std::cout << "        ";
				SetCursorPosition(34, 25);
				std::cout << "        ";
				break;
			case 2:  ///重新开始
				delete csnake;
				delete cfood;
				return 1;  ///返回1 表示重新开始
			case 3:
				delete csnake;
				delete cfood;
				return 2; //返回2 表示退出游戏
			default:
				break;

			}
		}

		if (csnake->GetFood(*cfood)) ///吃到食物
		{
			csnake->Move();
			UpdateScore(1);
			RewriteScore();
			cfood->DrawFood(*csnake);
		}
		else {
			csnake->NormalMove();
		}

		if (csnake->GetBigFood(*cfood))
		{
			csnake->Move();
			UpdateScore(cfood->GetProgressBar() / 5); ///分数由限时食物的进度条决定
			RewriteScore();
		}
		if (cfood->GetBigFlag()) ////闪烁big food
		{
			cfood->FlashBigFood();
		}
		Sleep(speed); //蛇的移动效果

	}

	///蛇死亡
	delete csnake;
	delete cfood;
	int tmp = GameOver();
	switch (tmp)
	{
	case 1:
		return 1;
	case 2:
		return 2;
	default:
		return 2;
	}

}