#ifndef MY_HEAD_H
#define MY_HEAD_H

#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

template<int H, int W> class Screen;

template <int H, int W>
std::istream& operator >> (std::istream &os, Screen <H, W> &s);

template<int H, int W>
std::ostream& operator << (std::ostream & os, Screen<H, W> &s);


template<int H , int W> class Screen
{
	friend std::istream& operator >> <H, W> (std::istream &, Screen &);
	friend std::ostream& operator << <H, W > (std::ostream &, Screen &);

public:
	Screen():contents (H*W,'@'){} 
	Screen(char c): contents (H*W , c ){}
	friend class Window_mgr; // ???
	char get() const { return contents[cursor]; }
	inline char get(int, int) const;
	Screen &clear(char = bkground);
public:
	Screen &move(int r, int c);
	Screen &set(char);
	Screen &set(int, int, char);

	Screen &display(std::ostream &os)
	{
		do_display(os);
		return *this;
	}
	const Screen &display(std::ostream &os) const
	{
		do_display(os);
		return *this;
	}
private:
	static const char bkground = ' ';
	void do_display(std::ostream &os)const { os << contents << endl; }

	int cursor = 0;
	std::string contents;

};

template<int H, int W>
std::ostream& operator << (std::ostream & os, Screen<H, W> &s) //ºÍÉùÃ÷Ò»ÖÂ.
{
	os << s.contents;
	return os;
}

template <int H, int W>
std::istream& operator >> (std::istream &os, Screen <H, W> &s)
{
	std::string t;
	os >> t;
	for (char &c : t) s.set(c);
	return os;
}


template<int H,int W> 
inline char Screen<H, W>::get(int x, int y)const
{
	return contents[x*W+y]
}

template <int H, int W>
Screen<H, W>& Screen<H, W>::clear(char c)
{
	contents = std::string(H*W, c);
	return *this;
}

template<int H, int W>
inline Screen<H,W>& Screen<H, W>::move(int r, int c)
{
	cursor = r*W + c;
	return *this;
}

template<int H,int W>
Screen<H, W>& Screen<H, W>::set(char c)
{
	contents[cursor++] = c;
	cursor = std::min(cursor, H * W); //?
	return *this;
}

template<int H , int W>
Screen<H, W>& Screen<H, W>::set(int x, int y, char c)
{
	contents[x*W + y] = c;
	return *this;
}


#endif