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
	//friend class Folder;
	friend void swap(Message &lhs, Message &rhs);
public:
	//初始化
	explicit Message(const std::string &str = " "):contents(str) {}

	//拷贝控制
	Message(const Message& msg);
	Message& operator=(const Message &);
	//Message(Message &&) noexcept;
	//Message& operator=(Message &&) noexcept;
	Message(Message &&);
	Message& operator=(Message &&);
	~Message();

	//从给定的folder中添加\删除message
	//用户代码
	void save(Folder&);
	void remove(Folder&);
	void addFldr(Folder *f);
	std::string get_contents() { return contents; }
	void print_debug() { cout << contents << endl; }

private:

	void add_to_Folders(const Message&);
	void remove_from_Folders();
	void move_Folders(Message *m); 


	std::string contents; //消息文本
	std::set<Folder*> folders; //包含文本的folder
							   //拷贝控制成员使用的工具函数

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
	void print_debug() { for (auto m : msgs) std::cout << m->get_contents(); }
public:
	void addMsg(Message *m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }
	void add_to_Message(const Folder &);
	void remove_from_Message();


private:
	set<Message * > msgs;
};


#endif
