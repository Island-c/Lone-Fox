#ifndef _HEAD_2_H
#define _HEAD_2_H
#include<string>
#include<iostream>
int kmp_index(const std::string&, const std::string&);
void kmp();
void get_next(const std::string&, int *);

void kmp()
{
	std::string zhu, zi;
	std::cout << "输入主串：";
	std::cin >> zhu;
	std::cout << "输入子串:";
	std::cin >> zi;
	int result;
	result = kmp_index(zhu, zi);
	if (result != -1)
		std::cout << "匹配成功，从主串 " << result << " 位置起" << std::endl;
	else
		std::cout << "匹配失败" << std::endl;

}

int kmp_index(const std::string& a, const std::string &b)
{
	int a_length = a.size();
	int b_length = b.size(); //b是子串
	int *next = new int[b_length];
	get_next(b, next); //得到PMT表

	int i = 0;
	int j = 0;
	while (i < a_length)
	{
		if (j == -1 || a[i] == b[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}

	delete[]next; //记得销毁。
	if (j >= b_length)
		return i - j + 1; //返回成功匹配的起始位置
	else
		return -1;
}

void get_next(const std::string &a, int *next)
{
	int a_length = a.size();
	int i = 0;
	int j = -1;
	next[0] = -1; //!!!
	while (i < a_length - 1) //PMT表整体向右移了一位，并且首位定为了-1.所以i的范围要比子串长度少一
	{
		if (j == -1 || a[i] == a[j])
		{
			i++;
			j++;
			//改进位置
			if (a[i] != a[j])
				next[i] = j;
			else
				next[i] = next[j]; //如果ij相等，则i点失配，j点也失配，直接回溯到j点。
		}
		else
			j = next[j];
	}

}



#endif