#include "my_head.h"

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

QueryResult TextQuery::query(const string & word) const
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

QueryResult OrQuery::eval(const TextQuery& text) const
{
	//�ֱ�������Ҳ���в��ҡ�
	auto right = rhs.eval(text);
	auto left = lhs.eval(text);

	//�����ҽ�����������ص�set��
	auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());

	//���Ҳ������� ������set�Ļ��ƣ��Ѿ����ڵ�Ԫ�ز����ظ����롣��ʵ����or���㡣
	ret_lines->insert(right.begin(), right.end());

	return QueryResult(rep(), ret_lines, left.get_file());//ׯ�ϵķ���һ��QueryResult
}

QueryResult AndQuery::eval(const TextQuery& text) const
{
	auto right = rhs.eval(text);
	auto left = lhs.eval(text);

	//�յ�ret��������left��right�Ĺ����к�
	auto ret_lines = make_shared<set<line_no>>(); 

	//���ñ�׼���㷨��set_intersection �ҳ�������Ա��������������� inserter
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));

	return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
	//result ��һ��set����������text���ڵ��кš�
	auto result = query.eval(text);

	//��set
	auto ret_lines = make_shared<set<line_no>>(); 

	auto beg = result.begin();
	auto end = result.end();
	auto sz = result.get_file()->size(); //�ļ���������

	for (size_t n = 0; n != sz; ++n) //���������ļ�
	{
		//��Ϊresult��һ��set�����е��кŶ��ǰ��������еģ����Բ���Ҫÿ�ζ���������result��
		if (beg == end || *beg != n)
			ret_lines->insert(n);
		else if (beg != end)
			++beg;

	}
	return QueryResult(rep(), ret_lines, result.get_file());


}
