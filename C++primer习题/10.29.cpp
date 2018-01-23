#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<fstream>
#include<algorithm>
using namespace std;
int main(int argc, char** argv)
{
	fstream in(argv[1]);
	if (!in) {
		cout << "error" << endl;
		//		return 1;
		exit(1);  //文件打开的日常。
	}
	istream_iterator<string> in_iter(in),eof;
	///ostream_iterator<string> out_iter(cout,"\n");  
	vector<string> my_vector(in_iter,eof); //直接在初始化时候赋值。

	while (in_iter != eof)
	{
		my_vector.push_back(*in_iter++);
	}
	///copy(my_vector.begin(), my_vector.end(), out_iter);
	for (auto &word : my_vector)  //免去不必要的拷贝操作
	{
		cout << word << endl;
	}

	system("pause");
	return 0;
}