#include "my_head.h"

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

QueryResult TextQuery::query(const string & word) const
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

QueryResult OrQuery::eval(const TextQuery& text) const
{
	//分别对左侧和右侧进行查找。
	auto right = rhs.eval(text);
	auto left = lhs.eval(text);

	//左侧查找结果拷贝到返回的set中
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());

	//将右侧结果插入 ，由于set的机制，已经存在的元素不会重复插入。即实现了or运算。
	ret_lines->insert(right.begin(), right.end());

	return QueryResult(rep(), ret_lines, left.get_file());//庄严的返回一个QueryResult
}

QueryResult AndQuery::eval(const TextQuery& text) const
{
	auto right = rhs.eval(text);
	auto left = lhs.eval(text);

	//空的ret，来保存left和right的共有行号
	auto ret_lines = make_shared<set<line_no>>(); 

	//调用标准库算法，set_intersection 找出公共成员，交给插入迭代器 inserter
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));

	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
	//result 是一个set，保存了有text存在的行号。
	auto result = query.eval(text);

	//空set
	auto ret_lines = make_shared<set<line_no>>(); 

	auto beg = result.begin();
	auto end = result.end();
	auto sz = result.get_file()->size(); //文件的总行数

	for (size_t n = 0; n != sz; ++n) //遍历整个文件
	{
		//因为result是一个set，其中的行号都是按升序排列的，所以不需要每次都遍历整个result。
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;

	}
	return QueryResult(rep(), ret_lines, result.get_file());


}
