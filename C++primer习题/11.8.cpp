#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	string word;
	vector<string> words;
	while (cin >> word)
	{
		if (!words.find(word))  //�������find����.....
		{
			words.push_back(word);
		}
	}
	for (auto &m_word : words)
	{
		cout << m_word << endl;
	}


	system("pause");
	return 0;
}