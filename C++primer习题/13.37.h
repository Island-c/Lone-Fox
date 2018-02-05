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
	//��ʼ��
	explicit Message (const std::string &str=" "):contents(str){}

	//��������
	Message(const Message& msg);
	Message& operator=(const Message &);
	~Message();

	//�Ӹ�����folder�����\ɾ��message
	void save(Folder&);
	void remove(Folder&);
	void addFldr(Folder *f);

	void print_debug() { cout << contents << endl; }

private:
	std::string contents; //��Ϣ�ı�
	std::set<Folder*> folders; //�����ı���folder
	//�������Ƴ�Աʹ�õĹ��ߺ���
	void add_to_Folders(const Message&);
	void remove_from_Folders();

};	

//�Ż�
void swap(Message &lhs, Message &rhs);

class Folder
{
public:


	Folder() = default;

	Folder(const Folder &);//�������캯��
	~Folder(); //����
	Folder& operator = (const Folder &); //������ֵ�����


public:
	void addMsg(Message *m) { msgs.insert(m); }
	void remMsg(Message *m) { msgs.erase(m); }
	void add_to_Message(const Folder &);
	void remove_from_Message();

	void print_debug() { for (auto m : msgs) std::cout << m->contents; }
private:
	set<Message * > msgs;
};


//Message�еĳ�Ա 

	void Message::save(Folder &f) //����
	{
		folders.insert(&f); //Message��������Ӵ�folder
		f.addMsg(this); //Folder��������Ӵ�Message
	}
	void Message::remove(Folder &f) //�Ƴ�
	{
		folders.erase(&f); //ɾ��Message�е�folder.
		f.remMsg(this);  //ɾ��Folder�����е�Message
	}
	void Message::add_to_Folders(const Message &m) //����ʱ����Message��ӵ�ָ��m��Folder�С�
	{
		for (auto f : m.folders)
		{
			f->addMsg(this);
		}
	}
	void Message::remove_from_Folders() //������ʱ��Ҫ��folders��ɾ����Message
	//��Ϊ������ֵ�������������Ķ���ִ�����Ʋ��������԰��������һ����������������ֵ��������á�
	{
		for (auto f : folders)
		{
			f->remMsg(this);
		}
	}
	void Message::addFldr(Folder *f) { folders.insert(f); }
	Message::~Message() //����
	{
		remove_from_Folders();
	}
	Message::Message(const Message &m) :contents(m.contents), folders(m.folders)
	{
		add_to_Folders(m); //�������캯�� �����´����Ŀ�����ҲҪ��ӵ�Folders�С�
	}
	Message& Message::operator= (const Message &rhs)//������ֵ�����
	{
		//��ɾ��ָ���ٸ�ֵ�� �������Կ�������Folders��Ҳֻ��Ψһ��Message����
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


//Folder�еĳ�Ա.
void Folder::add_to_Message(const Folder &f)
{
	for (auto msg : f.msgs)
		msg->addFldr(this); //�����Folder��ӵ�����Message.
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
