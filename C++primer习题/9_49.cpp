#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void word_find(fstream & in)
{
	string word;
	string err("bdfghjklpqty");
	string::size_type pos = 0;
	while (in >> word)
	{
		pos = 0;
		cout << word << ": ";
		while ((pos = word.find_first_not_of(err, pos)) != string::npos)
		{
			cout << word[pos] << "	";
			pos++;
		}
		cout << endl;
	}
}

int main(int argc, char ** argv)
{
	fstream in(argv[1]); //argv[0]存的是文件名， 1 是参数
	if (!in)	cerr << "error";
	word_find(in);


	system("pause");
	return 0;
}