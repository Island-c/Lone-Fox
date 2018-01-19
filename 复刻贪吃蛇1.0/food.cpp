#include"food.h"
#include"tools.h"
#include<cstdlib>
#include<iostream>

void Food::DrawFood(Snake& csnake)
{
	///用rand函数获得随机值 限制在2-29之间， 若获得的坐标和蛇身重叠，则重新获取
	/// 每五颗食物出现就获得一颗限时食物
	while (true) {
		int tem_x = rand() % 30;
		int tem_y = rand() % 30;
		if (tem_x <= 2) tem_x += 2; ///由于蛇的特殊增长方式， 若食物出现在墙的旁边，会直接over
		if (tem_y <= 2) tem_y += 2;

		bool flag = false;
		for (auto& point : csnake.snake)  ///判断食物是否与蛇重合。
		{
			if (  (point.GetX() == tem_x &&point.GetY() == tem_y) 
				|| (tem_x == big_x && tem_y == big_y )  ) {
				flag = true;
				break;
			}

		}
		if (flag) continue;
		x = tem_x;
		y = tem_y;
		SetCursorPosition(x, y);
		SetColor(13);
		std::cout << "*";
		++cnt;
		cnt %= 5;
		if (cnt == 0) {
			DrawBigFood(csnake);
		}
		break;

	}
}

void Food::DrawBigFood(Snake & csnake)

{
	SetCursorPosition(5, 0);
	SetColor(11);
	std::cout << "------------------------------------------"; ///进度条？？？
	progress_bar = 42;
	while (true)
	{
		int tmp_x = rand() % 30;
		int tmp_y = rand() % 30;
		if (tmp_x <= 2) tmp_x += 2;  //不然和墙重合了；
		if (tmp_y <= 2) tmp_y += 2;
		bool flag = false;
		for (auto& point : csnake.snake)  ///point代表蛇的轨迹
		{
			if ((point.GetX() == tmp_x &&point.GetY() == tmp_y) || (tmp_x == x &&tmp_y == y))
			{
				flag = true;			///point.GetX 表示 和蛇重叠  。 直接一个x 表示和点重叠？
				break;
			} 
		}
		if (flag)  continue; ///若重合， 重新生成
		big_x = tmp_x;
		big_y = tmp_y;
		SetCursorPosition(big_x, big_y);
		SetColor(18);
		std::cout << "■";
		big_flag = true;
		flash_flag = true;
		break;
	}
}

int Food::GetCnt()
{
	return cnt;
}

void Food::FlashBigFood() ///会闪的限时食物
{
	SetCursorPosition(big_x, big_y);
	SetColor(18);
	if (flash_flag)
	{

		std::cout << " ";
		flash_flag = false;

	}
	else {
		std::cout << "■";
		flash_flag = true;
	}
	SetCursorPosition( 27 , 0 );
	SetColor(11);
	for (int i = 42; i >= progress_bar; --i) {  /// 进度条缩短
		std::cout << "\b\b ";
	}	
	--progress_bar;
	if (progress_bar == 0) {
		SetCursorPosition(big_x, big_y);
		std::cout << "  ";  //清除big food
		big_flag = false;
		big_x = 0;
		big_y = 0;
	}

}

bool Food::GetBigFlag()
{
	return big_flag;
}

int Food::GetProgressBar()
{
	return progress_bar;
}