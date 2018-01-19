#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

inline void output_words(vector<string> & word)
{
	for (auto &a : word)
	{
		cout << a << " ";
	}
	cout << endl;
}

void elimDups(vector<string> &words)
{
	output_words(words);
	sort(words.begin(), words.end());
	output_words(words);
	auto end_unique = unique(words.begin(), words.end());
	words.erase(end_unique, words.end());
	output_words(words);
}

void biggies(vector<string> &word, vector<string>::size_type sz)
{
	elimDups(word);
	
	stable_sort(word.begin(), word.end(), [](const string &a, const string& b) {return a.size() > b.size(); });
	output_words(word);
	auto wc = find_if(word.begin(), word.end(), [sz](const string &a) {return a.size() >= sz; });

	auto count = word.end() - wc;

	cout << count<< endl;

}

int main(int argc, char** argv)
{

	ifstream in(argv[1]);
	if (!in) {
		cerr << "error" << endl;
		exit(1);
	}
	vector<string> words;
	string word;
	while (in >> word)
	{
		words.push_back(word);

	}
	biggies(words, 4);
	system("pause");
	return 0;
}