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
		exit(1);  //�ļ��򿪵��ճ���
	}
	istream_iterator<string> in_iter(in),eof;
	///ostream_iterator<string> out_iter(cout,"\n");  
	vector<string> my_vector(in_iter,eof); //ֱ���ڳ�ʼ��ʱ��ֵ��

	while (in_iter != eof)
	{
		my_vector.push_back(*in_iter++);
	}
	///copy(my_vector.begin(), my_vector.end(), out_iter);
	for (auto &word : my_vector)  //��ȥ����Ҫ�Ŀ�������
	{
		cout << word << endl;
	}

	system("pause");
	return 0;
}