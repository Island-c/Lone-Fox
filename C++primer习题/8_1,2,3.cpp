#include <iostream>
#include<string>
using namespace std;



istream& func(istream &is)
{
	string mm;
	while (is >> mm)
		cout << mm << endl;
	is.clear();//对流进行置位的函数
	return is;

}
int main()
{
	func(cin);
}