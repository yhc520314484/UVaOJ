// UVa272.cpp : Defines the entry point for the console application.
//
/*
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string in_string;
	cin >> in_string;
	bool flag = false;
	int pos = 0;
	for (auto c : in_string)                //string 每次得到的是一个单词而不是一个字母
	{
		if (c == '"')
		{ 
			if(flag == false)
			{
				c = '`';
				in_string.insert(pos, "'");
				flag = true;
			}
			else if (flag == true)
			{
				c = '\'';                    //转义！！
				in_string.insert(pos, "'");
				flag = false;
			}
		}
		pos++;
	}
	cout << in_string;
*/


/***Wrong answer***/
//手动输入EOF用windows:ctrl-z  linux:ctrl-d
/*
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<char> Vchar;
	string line;
	bool flag = false;
	char c;

	while(getline(cin, line))
	{
		for(int i = 0; i < line.length(); i++)
		{
			c = line[i];
			if (c == '"')
			{ 
				if(flag == false)
				{
					c = '`';
					Vchar.push_back('`');
					flag = true;
				}
				else if (flag == true)
				{
					c = '\'';                    //转义！！
					Vchar.push_back('\'');
					flag = false;
				}
			}
			Vchar.push_back(c);
		}
	}
	
	for (auto it = Vchar.cbegin(); it != Vchar.cend(); it++)
		cout << *it;

    return 0;
}*/

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	char c;
	bool flag = false;

	while ((c=getchar()) != EOF)
	{
		if (c == '"')
		{
			if (flag == false)
			{
				cout << "``";
				flag = true;
			}
			else
			{
				cout << "''";
				flag = false;
			}
		}
		else
			cout << c;
	}

	return 0;
}

