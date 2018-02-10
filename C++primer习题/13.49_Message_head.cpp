#include "my_head.h"
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

void Message::move_Folders(Message * m)
{
	folders = std::move(m->folders);
	for (auto f : folders)
	{
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear(); 
}

void Message::addFldr(Folder *f) { folders.insert(f); }

Message::Message(Message && m)
{
	move_Folders(&m);
}
Message & Message::operator=(Message  &&m)
{
	if (this != &m)
	{
		remove_from_Folders();
		contents = std::move(m.contents);
		move_Folders(&m);
	}
	return *this;
}
Message::Message(const Message &m) :contents(m.contents), folders(m.folders)
{
	add_to_Folders(m); //�������캯�� �����´����Ŀ�����ҲҪ��ӵ�Folders�С�
}
Message::~Message() //����
{
	remove_from_Folders();
}

/*Message::Message(Message && m) noexcept:contents(m.contents)
{
	add_to_Folders(*this);

}*/

Message& Message::operator= (const Message &rhs)//������ֵ�����
{
	//��ɾ��ָ���ٸ�ֵ�� �������Կ�������Folders��Ҳֻ��Ψһ��Message����
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;

}

/*Message& Message::operator= (Message &&m) noexcept
{
	if (this != &m)
	{
		remove_from_Folders();
		add_to_Folders(m);
	}
	return *this;
}*/
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

Folder::Folder(const Folder& f) :msgs(f.msgs)
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
