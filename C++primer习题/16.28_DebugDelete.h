#ifndef _DEBUGDELETE_H
#define _DEBUGDELETE_H

#include<iostream>
using namespace std;

class DebugDelete
{
public:
	DebugDelete() :os(std::cerr) {}

	template<typename T>
	void operator ()(T *p) const //�Գ�������ҲҪ����
	{
		os << "DebugDelete is working~ " << endl;
		delete p;
	}

private:
	std::ostream &os; //���������á�
};

#endif
