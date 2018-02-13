#include "my_head.h"

#include <iostream>
#include <vector>
#include <memory>
#include<string>
using namespace std;




int main(int argc, char** argv)
{

	//char result = compare('a', 's');
	
	string result = compare(string("are"),string("you"));
	//string result = compare("are", "you"); //error
	cout << result << endl;



	system("pause");
	return 0;

}
