#ifndef _HEAD_2_H
#define _HEAD_2_H
#include<string>
#include<iostream>

//BF暴力匹配

int violent(const std::string &a, const std::string &b)
{
	int i = 0;
	int j = 0;
	int a_length = a.size();
	int b_length = b.size();
	while (i<a_length && a_length - i >=b_length)
	{
		if (a[i] == b[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;// i回溯回下一位，j归零再来。
			j = 0;
		}
		if (j >= b_length)
			return i - j + 1;
	}
	return -1;

}

#endif