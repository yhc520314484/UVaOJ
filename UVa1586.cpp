#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	int count = 0;
	cin >> count;
	
	while(count--){
		string org_mal = "";
		cin >> org_mal;
		int len = org_mal.length();
		double number = 0;
		double single = 0;
		double total = 0;
		bool have_num = false;
		
		for(int i = 0; i < len; i++){
			switch(org_mal.at(i)){
				case 'C':
					total += number * single;
					number = 0;
					if(have_num == true)
					{
						total -= single;
						have_num = false;
					}
					single = 12.01;
					total += single;
					break;
				case 'H':
					total += number * single;
					number = 0;
					if(have_num == true)
					{
						total -= single;
						have_num = false;
					}
					single = 1.008;
					total += single;
					break;
				case 'O':
					total += number * single;
					number = 0;
					if(have_num == true)
					{
						total -= single;
						have_num = false;
					}
					single = 16.00;
					total += single;
					break;
				case 'N':
					total += number * single;
					number = 0;
					if(have_num == true)
					{
						total -= single;
						have_num = false;
					}
					single = 14.01;
					total += single;
					break;	
				default:
					number = number * 10 + (org_mal.at(i) - '0');
					have_num = true;
					break;
			}
		}
		if(have_num == true)
		{
			total += (number - 1) * single;
			have_num = false;
		}
		
		printf("%.3lf\n", total);
		total = 0;
		single = 0;
		number = 0;
	}
	return 0;
}
