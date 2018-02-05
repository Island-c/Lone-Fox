#ifndef MY_HEAD_H
#define MY_HEAD_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
#include<utility>
#include<map>
#include<set>
#include<string>
using namespace std;
class Folder;
class Message
{
public:
	friend class Folder;
	friend void swap(Message &lhs, Message &rhs);
public:
	//初始化
	explicit Message (const std::string &str=" "):contents(str){}

	//拷贝控制
	Message(const Message& msg);
	Message& operator=(const Message &);
	~Message();

	//从给定的folder中添加\删除message
	void save(Folder&);
	void remove(Folder&);
	void addFldr(Folder *f);

	void print_debug() { cout << contents << endl; }

private:
	std::string contents; //消息文本
	std::set<Folder*> folders; //包含文本的folder
	//拷贝控制成员使用的工具函数
	void add_to_Folders(const Message&);
	void remove_from_Folders();

};	

//优化
void swap(Message &lhs, Message &rhs);

class Folder
{
public:


	Folder() = default;

	Folder(const Folder &);//拷贝构造函数
	~Folder(); //析构
	Folder& operator = (const Folder &); //拷贝赋值运算符


public:
	void addMsg(Message *m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }
	void add_to_Message(const Folder &);
	void remove_from_Message();

	void print_debug() { for (auto m : msgs) std::cout << m->contents; }
private:
	set<Message * > msgs;
};


//Message中的成员 

	void Message::save(Folder &f) //保存
	{
		folders.insert(&f); //Message对象中添加此folder
		f.addMsg(this); //Folder对象中添加此Message
	}
	void Message::remove(Folder &f) //移除
	{
		folders.erase(&f); //删除Message中的folder.
		f.remMsg(this);  //删除Folder对象中的Message
	}
	void Message::add_to_Folders(const Message &m) //拷贝时，将Message添加到指向m的Folder中。
	{
		for (auto f : m.folders)
		{
			f->addMsg(this);
		}
	}
	void Message::remove_from_Folders() //析构的时候，要从folders中删除此Message
	//因为拷贝赋值运算符，会对左侧的对象执行类似操作，所以把它定义成一个函数，供拷贝赋值运算符调用。
	{
		for (auto f : folders)
		{
			f->remMsg(this);
		}
	}
	void Message::addFldr(Folder *f) { folders.insert(f); }
	Message::~Message() //析构
	{
		remove_from_Folders();
	}
	Message::Message(const Message &m) :contents(m.contents), folders(m.folders)
	{
		add_to_Folders(m); //拷贝构造函数 对于新创建的拷贝，也要添加到Folders中。
	}
	Message& Message::operator= (const Message &rhs)//拷贝赋值运算符
	{
		//先删除指针再赋值。 就算是自拷贝，在Folders中也只有唯一的Message存在
		remove_from_Folders();
		contents = rhs.contents;
		folders = rhs.folders;
		add_to_Folders(rhs);
		return *this;

	}
	void swap(Message &lhs, Message &rhs)
	{

		using std::swap;
		for (auto f : lhs.folders)
			f->remMsg(&lhs);
		for (auto f : rhs.folders)
			f->remMsg(&rhs);

		swap(lhs.contents, rhs.contents);
		swap(lhs.folders, rhs.folders);

		for (auto f : lhs.folders)
			f->addMsg(&lhs);
		for (auto f : rhs.folders)
			f->addMsg(&rhs);

	}


//Folder中的成员.
void Folder::add_to_Message(const Folder &f)
{
	for (auto msg : f.msgs)
		msg->addFldr(this); //将这个Folder添加到所有Message.
}
void Folder::remove_from_Message()
{
	while (!msgs.empty())
		(*msgs.begin())->remove(*this);
}

Folder::Folder(const Folder& f):msgs(f.msgs)
{
	add_to_Message(*this);
}
Folder& Folder::operator= (const Folder& f)
{
	remove_from_Message();
	msgs = f.msgs;
	add_to_Message(f);
	return *this;
}
Folder::~Folder()
{
	remove_from_Message();
}

#endif
