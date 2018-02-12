#include "my_head.h"

#include <iostream>
#include <vector>
#include <memory>
using namespace std;


std::ostream & operator<< (std::ostream &os, const Query &query)
{
	//Query::rep通过它的Query_base指针对rep（）虚调用。
	return os << query.rep();
}

int main(int argc, char** argv)
{
	ifstream file(argv[1]);

	TextQuery tQuery(file);

	Query q = Query("fieryzzz") | Query("wind");

	std::cout << q;

	system("pause");
	return 0;

}
