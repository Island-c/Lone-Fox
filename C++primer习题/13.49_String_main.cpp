#include "my_head.h"
#include <iostream>
using namespace std;



void foo(String x)
{
	std::cout << x.begin() << std::endl;
}

void bar(const String& x)
{
	std::cout << x.begin() << std::endl;
}

String baz()
{
	String ret("world");
	return ret;
}

int main()
{
	char text[] = "world";

	String s0;
	String s1("hello");
	String s2(s0);
	String s3 = s1;
	String s4(text);
	s2 = s1;

	foo(s1);
	bar(s1);
	foo("temporary");
	bar("temporary");
	String s5 = baz();

	std::vector<String> svec;
	svec.reserve(8);
	svec.push_back(s0);
	svec.push_back(s1);
	svec.push_back(s2);
	svec.push_back(s3);
	svec.push_back(s4);
	svec.push_back(s5);
	svec.push_back(baz());
	svec.push_back("good job");

	//for_each(svec.begin(), svec.end(), [](const String & a) {cout << a.begin() << endl; });
	//cout << svec[1].begin() << endl;
	
	system("pause");
	return 0;
}
