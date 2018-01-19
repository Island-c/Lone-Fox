#include<string>
#include<vector>
#include<iostream>
using namespace std;

int main(int argc, char** argv)

{
	vector<string> vec;
	int sum = 0;
	while (cin)
	{
		string number;
		cin >> number;
		vec.push_back(number); 
		//cout << number << endl;//用键盘结束输入的时候 ctrl+z也许也被输了进去...所以迭代器范围应为end-1
	}
	auto iter = vec.begin();
	for (iter; iter != vec.end()-1;iter++)
	{
		sum += stoi(*iter);

	} 
	cout << sum << endl;




	system("pause");
	return 0;
}