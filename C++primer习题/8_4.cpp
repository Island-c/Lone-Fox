#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

int main(int argc, char** argv)
{
	string infile = "1.txt";
	vector<string> vec; 
	ifstream in(infile);
	if (in)
	{
		string buf;
		while (getline(in, buf))
		{
			vec.push_back(buf);
		}
	}

	else
		cerr << "can't open this file" << endl;

	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}
	system("pause");
	return 0;

}