#include <iostream>
#include<string>
using namespace std;



istream& func(istream &is)
{
	string mm;
	while (is >> mm)
		cout << mm << endl;
	is.clear();//����������λ�ĺ���
	return is;

}
int main()
{
	func(cin);
}