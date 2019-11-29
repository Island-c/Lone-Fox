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
	std::cout << "����������";
	std::cin >> zhu;
	std::cout << "�����Ӵ�:";
	std::cin >> zi;
	int result;
	result = kmp_index(zhu, zi);
	if (result != -1)
		std::cout << "ƥ��ɹ��������� " << result << " λ����" << std::endl;
	else
		std::cout << "ƥ��ʧ��" << std::endl;

}

int kmp_index(const std::string& a, const std::string &b)
{
	int a_length = a.size();
	int b_length = b.size(); //b���Ӵ�
	int *next = new int[b_length];
	get_next(b, next); //�õ�PMT��

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

	delete[]next; //�ǵ����١�
	if (j >= b_length)
		return i - j + 1; //���سɹ�ƥ�����ʼλ��
	else
		return -1;
}

void get_next(const std::string &a, int *next)
{
	int a_length = a.size();
	int i = 0;
	int j = -1;
	next[0] = -1; //!!!
	while (i < a_length - 1) //PMT��������������һλ��������λ��Ϊ��-1.����i�ķ�ΧҪ���Ӵ�������һ
	{
		if (j == -1 || a[i] == a[j])
		{
			i++;
			j++;
			//�Ľ�λ��
			if (a[i] != a[j])
				next[i] = j;
			else
				next[i] = next[j]; //���ij��ȣ���i��ʧ�䣬j��Ҳʧ�䣬ֱ�ӻ��ݵ�j�㡣
		}
		else
			j = next[j];
	}

}



#endif