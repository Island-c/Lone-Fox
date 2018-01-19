#include<string>
#include<iostream>

using namespace std;

void find_char(const string& s, const string& c)
{
	cout << "ÔÚ" << s << "ÖÐ²éÕÒ×Ö·û" << c << endl;
	string::size_type pos = 0;
	while ((pos = s.find_first_of(c, pos) )!= string::npos)
	{
		cout << "pos:"<<pos <<"char:"<< s[pos]<< endl;
		pos++;

	}
	pos = 0;
	while ((pos = s.find_first_not_of(c, pos) )!= string::npos)
	{
		cout << "pos:" << pos << "char:" << s[pos] << endl;
		pos++;
	}

}

int main(int argc, char ** argv)
{
	string s("ab2c3d7R4E6");
	string numbers("0123456789");
	find_char(s, numbers);




	system("pause");
	return 0;
}