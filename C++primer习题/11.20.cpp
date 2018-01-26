#include<iostream>
#include<map>
#include<string>
#include<fstream>
using namespace std;
int main(int argc, char ** argv)
{
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "error";
		exit(1);
	}
	string word;
	map<string, size_t> words;
	while (in >> word)
	{
		auto ret = words.insert({word,1}); //insert�Ķ�������map<> �е����ͺ���������һ�¡�
		// ret��һ��pair���ͣ� first��һ����������ָ������Ԫ�أ������Ѿ����ڵ��Ǹ���Ҫ�����Ԫ��һ����Ԫ�أ�
		//second��һ��bool���ͣ� ������ɹ�����ֵΪtrue ����map���Ѵ��ڸùؼ��֣����벻�ɹ����򷵻�false�� 
		if (!ret.second)//�Ѿ����ڸ�word.
		{
			++(*(ret.first)).second; 
		}
	}

	for (auto & out : words)
	{
		cout << out.first << "  " << out.second << endl;
	}


	system("pause");
	return 0;
}