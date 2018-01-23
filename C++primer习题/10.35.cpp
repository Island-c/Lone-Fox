#include<iterator>
#include<fstream>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main(int argc, char** argv)

{
	ifstream in(argv[1]);
	if (!in) { exit(1); }
	istream_iterator<int> in_iter(in),eof;
	vector<int> numbers(in_iter, eof);

	auto num_iter = numbers.end();
	//num_iter--;
	while (num_iter != numbers.begin())
	{
		cout << *(--num_iter) << endl;
//		cout << *num_iter-- << endl;  //当num_iter指向numbers.begin（）时 还要做一次--, 会越界
	}


	system("pause");
	return 0;
}