#include "my_head.h"

std::ostream& print(std::ostream &out, const  QueryResult & word)
{
	out << word.word << " occurs " << word.nos->size() << "   "
		<< (word.nos->size() > 1 ? "times" : "time") << endl;
	for (auto num : *word.nos)  //word.nos 是一个shared_ptr<set<lineNo>>； num表示单词出现的行号。
	{
		//	out << " \t (line" << num + 1 << " )" << (*word.input)[num] << endl;
		out << " \t (line" << num + 1 << " )" << *(word.input->begin() + num) << endl;
	}
	return out;
}

TextQuery::TextQuery(ifstream &in) :words(new vector<string>())  // TextQuery的构造函数
																 //word只是一个指针，要先给他分配地址才能使用。
{
	string s;
	while (getline(in, s))
	{

		words->push_back(s);//保存一行文本
		std::string::size_type n = words->size() - 1;//假如vector中有一个string ,size()返回1 ，行号为0
		istringstream line(s);
		string word;
		while (line >> word) //提取每个单词
		{
			auto &lines = word_No[word]; //对map使用下标访问符，返回value, 是一个shared_ptr
			if (!lines) // 若指针为空 （第一次遇到这个单词）
				lines.reset(new set<lineNo>);
			lines->insert(n); //将行号插入这个set中。
		}
	}
}

QueryResult TextQuery::query(const string & word)
{
	static shared_ptr<set<lineNo>> nodata(new set <lineNo>);  //空指针。

															   //auto loc = word_No[word];
	auto loc = word_No.find(word); //返回值是一个map , map的first是string ， second是shared_ptr 
	if (loc == word_No.end())
	{
		return QueryResult(word, nodata, words);  //nodata
	}
	else
		return QueryResult(word, loc->second, words);

}