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
		//cout << number << endl;//�ü��̽��������ʱ�� ctrl+zҲ��Ҳ�����˽�ȥ...���Ե�������ΧӦΪend-1
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