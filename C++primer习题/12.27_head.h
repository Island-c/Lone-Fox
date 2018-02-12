#ifndef MY_HEAD_H
#define MY_HEAD_H

#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<set>
#include<fstream>
#include<memory>
#include<sstream>
#include<algorithm>
using namespace std;

class QueryResult;
class TextQuery
{
public:	
	
	using lineNo = vector<string>::size_type;
	//�������Ƴ�Ա�� 
	TextQuery():words(nullptr){} //Ĭ�Ϲ��캯��
	TextQuery(ifstream &in);
	TextQuery(const TextQuery &rhs) : words(new vector<string>(*(rhs.words))), word_No(rhs.word_No) { cout << "�������캯��" << endl; } //�������캯��
	TextQuery(TextQuery &&rhs) : words(new vector<string>(std::move(*(rhs.words)))), word_No(std::move(rhs.word_No))
	{
		rhs.words = nullptr; 
		std::cout << "�ƶ����캯��" << std::endl;
	} //�ƶ����캯����
	TextQuery& operator=(const TextQuery &rhs) //������ֵ�����
	{
		words = make_shared<vector<string>> (*(rhs.words));
		word_No = rhs.word_No;
		cout << "������ֵ�����" << endl;
		return *this;
	}
	TextQuery& operator=( TextQuery &&rhs) //�ƶ���ֵ�����
	{
		if (this != &rhs)
		{
			words = shared_ptr<vector<string>> (new vector<string>(std::move(*rhs.words)));
			word_No=std::move(rhs.word_No);
			rhs.words = nullptr;
		}
		cout << "�ƶ���ֵ�����" << endl;
		return *this;
	}

	~TextQuery() { cout << "��������" << endl; }
	

	
	QueryResult query(const string & word); //���Һ�����

private:

	shared_ptr <vector<string>> words; //����ÿ���ı�
	map<string, shared_ptr<set<lineNo>>> word_No; //ÿ������ �Ͷ�Ӧ�ĳ��ֹ������кŵ�set.
};


class QueryResult
{
public:
	friend std::ostream& print(std::ostream &out, const  QueryResult & word);
public:
	QueryResult(const std::string &s, std::shared_ptr<std::set<TextQuery::lineNo>> set, std::shared_ptr<std::vector<string>> v) :
		word(s), nos(set), input(v) { }

private:
	std::string word; //Ҫ���ҵĵ���
	std::shared_ptr<std::set<TextQuery::lineNo>> nos; //�õ��ʶ�Ӧ����
	std::shared_ptr<std::vector<std::string>> input; //ȫ���ı�
};



#endif
