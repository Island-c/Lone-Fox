#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

istream& inn(istream& sin)
{
	string buf;
	while (sin >> buf)
		cout << buf << endl;
	return sin;
}
int main(int argc, char** argv)
{
	string my_string = "we are family";
	istringstream iii(my_string);
	inn(iii);
	system("pause");
	return 0;
}
