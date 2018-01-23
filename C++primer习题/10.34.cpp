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
	auto num_iter = numbers.crbegin();
	while (num_iter != numbers.crend())
	{
		cout << *num_iter++ << endl;
	}


	system("pause");
	return 0;
}