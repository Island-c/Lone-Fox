#include<iostream>
#include<deque>
#include<list>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	list<string> ide;
	string my_word;
	
	while (cin >> my_word)
	{
		ide.insert(ide.begin(),my_word);
	}
	
	for (auto dbegin = ide.cbegin(); dbegin != ide.end(); ++dbegin)
	{
		cout << *dbegin << endl;

	}



	system("pause");
	return 0;
}