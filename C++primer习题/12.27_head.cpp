#include "my_head.h"

std::ostream& print(std::ostream &out, const  QueryResult & word)
{
	out << word.word << " occurs " << word.nos->size() << "   "
		<< (word.nos->size() > 1 ? "times" : "time") << endl;
	for (auto num : *word.nos)  //word.nos ��һ��shared_ptr<set<lineNo>>�� num��ʾ���ʳ��ֵ��кš�
	{
		//	out << " \t (line" << num + 1 << " )" << (*word.input)[num] << endl;
		out << " \t (line" << num + 1 << " )" << *(word.input->begin() + num) << endl;
	}
	return out;
}

TextQuery::TextQuery(ifstream &in) :words(new vector<string>())  // TextQuery�Ĺ��캯��
																 //wordֻ��һ��ָ�룬Ҫ�ȸ��������ַ����ʹ�á�
{
	string s;
	while (getline(in, s))
	{

		words->push_back(s);//����һ���ı�
		std::string::size_type n = words->size() - 1;//����vector����һ��string ,size()����1 ���к�Ϊ0
		istringstream line(s);
		string word;
		while (line >> word) //��ȡÿ������
		{
			auto &lines = word_No[word]; //��mapʹ���±���ʷ�������value, ��һ��shared_ptr
			if (!lines) // ��ָ��Ϊ�� ����һ������������ʣ�
				lines.reset(new set<lineNo>);
			lines->insert(n); //���кŲ������set�С�
		}
	}
}

QueryResult TextQuery::query(const string & word)
{
	static shared_ptr<set<lineNo>> nodata(new set <lineNo>);  //��ָ�롣

															   //auto loc = word_No[word];
	auto loc = word_No.find(word); //����ֵ��һ��map , map��first��string �� second��shared_ptr 
	if (loc == word_No.end())
	{
		return QueryResult(word, nodata, words);  //nodata
	}
	else
		return QueryResult(word, loc->second, words);

}