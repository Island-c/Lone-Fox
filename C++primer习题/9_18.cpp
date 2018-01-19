#include<iostream>
#include<deque>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	deque<string> ide;
	string my_word;
	while (cin >> my_word)
	{
		ide.push_back(my_word);
	}
	
	for (auto dbegin = ide.cbegin(); dbegin != ide.end(); ++dbegin)
	{
		cout << *dbegin << endl;

	}



	system("pause");
	return 0;
}