#ifndef MY_HEAD_H
#define MY_HEAD_H

#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
class DebugDelete
{
public:
	DebugDelete() :os(std::cerr) {}

	template<typename T> 
	void operator() (T *p) { os << "deleting unique_ptr;" << std::endl; delete p; }
private:
	std::ostream &os;
};



#endif