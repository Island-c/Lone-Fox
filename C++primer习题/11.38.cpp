#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

int main(int argc, char ** argv)
{
	unordered_multimap<string, size_t> words;
	//unordered_map<string,size_t> words;
	string word;
	while (cin >> word)
	{
		//++words[word];  //multi��map��֧���±����... ��Ϊ��һ�Զ�
		words.insert({word,1});
	}
	for (auto &out : words)
	{
		cout << out.first << "  " << out.second << endl;
	}


	system("pause");
	return 0;
}