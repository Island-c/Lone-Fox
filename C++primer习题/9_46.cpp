#include<string>
#include<iostream>

using namespace std;

string name_1(string& s, const string& before, const string& after)
{

	s.insert(s.begin(), before.begin(), before.end());
	//s.append(after.begin(), after.end());
	s.insert(s.end(), after.begin(), after.end());
	return s;
}
int main(int argc, char ** argv)
{
	string name("liu");
	name_1(name, "liu", "liu");
	cout << name << endl;




	system("pause");
	return 0;
}