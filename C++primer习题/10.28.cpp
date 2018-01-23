#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<iterator>
using namespace std;

int main(int argc, char **argv)
{
	vector<int> my_vec{ 1,1,2,3,4,5,6,7,8,9 };
	list<int> my_vec_1, my_vec_2, my_vec_3;    ///vector��֧��front_inserter ,�ᵼ�´������ƶ�������
	//������ STL �ӿڣ�concept�����ŵ㣬Ҳ�Ƿ��ͱ�������������ķ��棺��ȷ��ʱ�临�Ӷȣ����ṩ���Ƹ�Чʵ���Ч�Ĳ�������������
	ostream_iterator<int> out_iter(cout, " ");


	copy(my_vec.begin(), my_vec.end(), back_inserter(my_vec_1));
	unique_copy(my_vec.begin(), my_vec.end(), front_inserter(my_vec_2)); //ȥ�ؿ���
	copy(my_vec.begin(), my_vec.end(), inserter(my_vec_3, my_vec_3.begin()));

	copy(my_vec_1.begin(), my_vec_1.end(), out_iter);  //��ÿ��Ԫ�ؿ�������������� ����cout.
	cout << endl;
	copy(my_vec_2.begin(), my_vec_2.end(), out_iter);
	cout << endl;
	copy(my_vec_3.begin(), my_vec_3.end(), out_iter);





	system("pause");
	return 0;
}