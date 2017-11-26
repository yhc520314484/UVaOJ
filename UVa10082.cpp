// UVa10082.cpp : Defines the entry point for the console application.
//
/*                 Wrong Answer   ID：20400776        */
/*
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line("`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./");
	char c;

	while ((c = getchar()) != EOF)
	{
		if (c == '`' || c == 'Q' || c == 'A' || c == 'Z' || c == ' ')
			cout << c;
		else
		{
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == c)
				{
					cout << line[i - 1];
				}
			}
		}
	}

	return 0;
}
*/
/*ID:20400870*/
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string line("`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./");
	char c;
	bool flag = false;

	while ((c = getchar()) != EOF)
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (line[i] == c)
			{
				cout << line[i - 1];
				flag = true;
			}
		}
		if (flag == false)
			cout << c;
		flag = false;
	}

	return 0;
}

