#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<fstream>

using namespace std;

string& trans(string & s)
{
		for (int i = 0; i<s.size(); ++i)
	{
		if (s[i] >= 65 && s[i] <= 90)	s[i] += 32;
		else if (s[i] == ',' || s[i] == '.') s.erase(i);
	}
	//Ī���Ĵ���д��
	int i = 0;
	for (auto &c : s)
	{
		if (c >= 65 && c <= 90)	c += 32;
		else if (c == ',' || c == '.') s.erase(i); //����Ϊ���� �ı���s!
		//��һ��Containerִ����һ��earse����֮��ԭ������������iterator��ʧЧ�ˣ�����Ϊ�ǲ���Ԥ���
		//���ֻɾ����һ������Ҫ���Ԫ�أ�����erase�������һ��break ����ֹ�����������ͺ��ˡ�
		++i;
	}


	return s;

}

map<string, size_t> build_map(ifstream &in)
{
	map<string, size_t> words;
	string word;

	while (in >> word)
		++words[trans(word)];

	return words;
}



int main(int argc, char **argv)
{
	ifstream in(argv[1]);
	if (!in) {
		cerr << "error" << endl;
		system("pause");
		exit(1);
	}
	map<string, size_t> words = build_map(in);
	
	auto begin = words.begin();
	while (begin != words.end())
	{
		cout << (*begin).first << "   " << begin->second << endl;
		++begin;
	}

	system("pause");
	return 0;
}