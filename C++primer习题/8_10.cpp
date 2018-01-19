#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

int main(int agrc, char** argv)
{
	vector<string> vec;
	ifstream in("1.txt", ifstream::in);
	if (in) {
		string line;
		while (getline(in, line))
		{
			cout << line << endl;
			string word;
			istringstream inn(line);
			while (inn >> word)
			{
				vec.push_back(word);
			}
			for (int i = 0; i < vec.size(); ++i)
			{
				cout << vec[i] << endl;
			}

		}
		in.close();

	}
	else
		cerr << "error" << endl;
	

	system("pause");
	return 0;
}