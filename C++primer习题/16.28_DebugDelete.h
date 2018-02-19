#ifndef _DEBUGDELETE_H
#define _DEBUGDELETE_H

#include<iostream>
using namespace std;

class DebugDelete
{
public:
	DebugDelete() :os(std::cerr) {}

	template<typename T>
	void operator ()(T *p) const //对常量对象也要可用
	{
		os << "DebugDelete is working~ " << endl;
		delete p;
	}

private:
	std::ostream &os; //必须是引用。
};

#endif
