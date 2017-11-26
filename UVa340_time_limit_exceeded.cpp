// UVa340.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

int main()
{

	bool global_statue = true;
	int game_count = 0;                       //游戏次数计数器
	vector<vector<string> > final_answer;                //每个游戏的猜测结果

	

	while (global_statue)
	{
		int guess_count = 0;                      //每次游戏中猜测了多少次
		vector<int> each_time;                    //每次游戏的每次猜测
		vector<int> each_answer;                  //每次游戏的答案
		int length;                               //每次游戏的输入长度	
		int element;                               //元素输入临时变量
		int each_pos = 0;                           //每次每轮游戏元素位置

		cin >> length;

		if (length == 0)
		{
			global_statue = false;
			break;
		}
		

		game_count++; 
		while (cin >> element)
		{
			each_answer.push_back(element);
			if (getchar() == '\n') break;              //等到回车符号后结束本次循环
		}

		while (cin >> element)
		{
			each_time.push_back(element);
			if (getchar() == '\n')
			{
// 				if ((each_time.size() % length) == 1 && each_time[each_time.size() - 1] == 0)
// 					global_statue = false;

				bool each_end_flag = true;
//				int pos = each_time.size() % length;
				
				for (int i = each_pos; i < each_time.size(); i++)
				{
					if (each_time[i] != 0)
					{
						each_end_flag = false;
						break;
					}
					else
						continue;
				}
				if (each_end_flag)
					break;
				each_pos += length;
				guess_count++;
			}
		}

		int base_pos = 0;           //每次进行匹配的基位置
		int strong = 0;                           //每组猜测强匹配数
		vector<int> strong_number;                  //强匹配的数字
		vector<int> weak_number;                  //弱匹配的数字
//		int weak_number = 0;                  //弱匹配的数字
		int weak = 0;                             //每组猜测弱匹配数
		string answer = "";                  //每轮最后得到的strong和weak
		vector<string> each_game;             //每个游戏每轮的结果   要先设定这个vector后续才可以进行嵌套
		bool is_strong = false;              //该数字已是强匹配数字
		bool is_weak = false;              //该数字已是强匹配数字
		for (int j = 0; j < guess_count; j++)
		{
			for (int i = base_pos, k = 0; i < base_pos + length; i++, k++)
			{
				if (each_time[i] == each_answer[k])
				{
					strong++;
					strong_number.push_back(each_time[i]);
					continue;
				}
				for (auto it = strong_number.cbegin(); it != strong_number.cend(); it++)
				{
					if (each_time[i] == *it)
					{
						is_strong = true;
						break;
					}
				}
				for (auto it = weak_number.cbegin(); it != weak_number.cend(); it++)
				{
					if (each_time[i] == *it)
					{
						is_weak = true;
						break;
					}
				}
				for (int q = 0; q < length; q++)
				{
					if (each_time[i] == each_answer[q] && !is_strong && !is_weak)
					{ 
						weak_number.push_back(each_time[i]);
						is_weak = true;
						weak++;
					}
				}	
				is_strong = false;
				is_weak = false;
			}
//			weak -= strong;
			int same = 0;              //weak和strong中相同的元素，减掉weak
			for (auto itw = weak_number.cbegin(); itw != weak_number.cend(); itw++)
			{
				for (auto its = strong_number.cbegin(); its != strong_number.cend(); its++)
				{
					if (*itw == *its)
					{
						same++;
						break;
					}
				}
			}
			weak -= same;
			base_pos += length;
			ostringstream oss, osw;
			oss << strong;
			osw << weak;
			answer = answer + "(" + oss.str() + "," + osw.str() + ")";
			each_game.push_back(answer);
			weak = 0;
			strong = 0;
			answer = "";
			
			strong_number.clear();
			weak_number.clear();
		}
		final_answer.push_back(each_game);
		each_game.clear();
		each_answer.clear();
	}

	vector<string> output_answer;
	int pos = 0;

// 		for (int j = 0; j < final_answer.size(); j++)
// 			cout << "\t" << final_answer[game_count][j] << endl;
	for (auto ito = final_answer.cbegin(); ito != final_answer.cend(); ito++)
	{
		cout << "Game " << ++pos << ":" << endl;
		output_answer = *ito;
		for (auto iti = output_answer.cbegin(); iti != output_answer.cend(); iti++)
		{
			cout << "    " << *iti << endl;
		}
	}

	

	

	return 0;
}
