#include <iostream>
#include <string>

using namespace std;

int main()
{
	int count = 0;
	
	cin >> count;
	
	while(count--)
	{
		string org_str = "";
		cin >> org_str;
		
		int single_score = 0;
		int total_score = 0;
		int len = org_str.length();
		
		for(int i = 0; i < len; i++)
		{
			if(org_str.at(i) == 'O')
				total_score += ++single_score;
			else
				single_score = 0;
		}
		cout << total_score << endl;
	}
}
