#include<iostream>
#include<algorithm>
#include<iterator>
#include<fstream>

using namespace std;
int main(int argc, char **argv)
{
	ofstream out_1("奇数.txt");
	ofstream out_2("偶数.txt");
	fstream in(argv[1]);
	if (!in)
	{
		cerr << "error" << endl;
		exit(1);
	}
	if (!out_1)	cout << "error open out_1";   //如果使用fstream out_1 ，就会出现error 。
	if (!out_2) cout << "error open out_2";

	istream_iterator<int> in_iter(in),eof;
	ostream_iterator<int> out_iter_1(out_1, "\n");
	ostream_iterator<int> out_iter_2(out_2, "\n");

	while (in_iter != eof)
	{
		if (*in_iter % 2 == 0)	//copy(in_iter, ++in_iter, out_iter_2);
			*out_iter_2++ = *in_iter;
			
		else //copy(in_iter, ++in_iter, out_iter_1);
			*out_iter_1++ = *in_iter;
		in_iter++;
	}



	system("pause");
	return 0;
}