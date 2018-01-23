#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<iterator>
using namespace std;

int main(int argc, char **argv)
{
	vector<int> my_vec{ 1,1,2,3,4,5,6,7,8,9 };
	list<int> my_vec_1, my_vec_2, my_vec_3;    ///vector不支持front_inserter ,会导致大量的移动操作。
	//这正是 STL 接口（concept）的优点，也是泛型编程优于面向对象的方面：明确的时间复杂度，不提供看似高效实则低效的操作，以免误用
	ostream_iterator<int> out_iter(cout, " ");


	copy(my_vec.begin(), my_vec.end(), back_inserter(my_vec_1));
	unique_copy(my_vec.begin(), my_vec.end(), front_inserter(my_vec_2)); //去重拷贝
	copy(my_vec.begin(), my_vec.end(), inserter(my_vec_3, my_vec_3.begin()));

	copy(my_vec_1.begin(), my_vec_1.end(), out_iter);  //将每个元素拷贝给输出迭代器 代替cout.
	cout << endl;
	copy(my_vec_2.begin(), my_vec_2.end(), out_iter);
	cout << endl;
	copy(my_vec_3.begin(), my_vec_3.end(), out_iter);





	system("pause");
	return 0;
}