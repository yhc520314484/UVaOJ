// UVa401.cpp : Defines the entry point for the console application.
//

/*Wrong Answer ID:20401158     输出格式出错   应全部读取完后再依此输出每个结果*/
/*
#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	string in_string;
	bool pai_flag = true;
	bool mir_flag = true;
	string org_mir("AEHIJLMOSTUVWXYZ12358");
	string cha_mir("A3HILJMO2TUVWXY51SEZ8");
	
	while (getline(cin, in_string))
	{
		for (int i = 0; i < in_string.length() / 2; i++)
		{
			if (mir_flag == true)
			{
				for (int j = 0; j < org_mir.length(); j++)
				{
					if (in_string[i] == org_mir[j] && in_string[in_string.length() - i - 1] != cha_mir[j])
					{
						mir_flag = false;
						break;
					}
				}
			}
			if (pai_flag == true)
			{
				if (in_string[i] != in_string[in_string.length() - i - 1])
				{
					pai_flag = false;
				}
			}
			if (pai_flag == false && mir_flag == false)
			{
				break;
			}
		}

		in_string += " -- is ";

		if (pai_flag == false && mir_flag == false)
			cout << in_string << "not a palindrome.\n" << endl;     //题目要求加空行，千万不要忘了
		else if (pai_flag == true && mir_flag == false)
			cout << in_string << "a regular palindrome.\n" << endl;
		else if (pai_flag == false && mir_flag == true)
			cout << in_string << "a mirrored string.\n" << endl;
		else
			cout << in_string << "a mirrored palindrome.\n" << endl;

		pai_flag = true;
		mir_flag = true;
	}
	
	return 0;
}
*/

/*Wrong Answer ID:20401235    Don't know where is the error?*/
#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<string> lib;
	string first_in;
	string in_string;
	bool pai_flag = true;
	bool mir_flag = true;
	string org_mir("AEHIJLMOSTUVWXYZ12358");
	string cha_mir("A3HILJMO2TUVWXY51SEZ8");

	while (getline(cin, first_in))
	{
		lib.push_back(first_in);
	}

	for(int j = 0; j < lib.size(); j++)
	{
		in_string = lib[j];
		for (int i = 0; i < in_string.length() / 2; i++)
		{
			if (mir_flag == true)
			{
				for (int j = 0; j < org_mir.length(); j++)
				{
					if (in_string[i] == org_mir[j] && in_string[in_string.length() - i - 1] != cha_mir[j])
					{
						mir_flag = false;
						break;
					}
				}
			}
			if (pai_flag == true)
			{
				if (in_string[i] != in_string[in_string.length() - i - 1])
				{
					pai_flag = false;
				}
			}
			if (pai_flag == false && mir_flag == false)
			{
				break;
			}
		}

		in_string += " -- is ";

		if (pai_flag == false && mir_flag == false)
			cout << in_string << "not a palindrome.\n" << endl;     //题目要求加空行，千万不要忘了
		else if (pai_flag == true && mir_flag == false)
			cout << in_string << "a regular palindrome.\n" << endl;
		else if (pai_flag == false && mir_flag == true)
			cout << in_string << "a mirrored string.\n" << endl;
		else
			cout << in_string << "a mirrored palindrome.\n" << endl;

		pai_flag = true;
		mir_flag = true;
	}

	return 0;
}
