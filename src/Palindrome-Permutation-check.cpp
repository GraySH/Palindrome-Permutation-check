//============================================================================
// Name        : Palindrome-Permutation-check
// Author      : CSH
// Version     :
// Copyright   : Your copyright notice
// Description : Check if permutation of the string is palindrome
//============================================================================
#include <iostream>
#include <cstring>
#include <map>
#include <vector>

#include <algorithm>    // std::next_permutation, std::sort, std::reverse
#include <list>
#include <utility>
#include <string>

using namespace std;

int main ()
{
	string str = "Tact Coa";

	map<char, int> mapData;

	//change string to lowercase.
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
	//save string char to mapdata hashmap.
	for(unsigned int i = 0; i < str.size(); i++)
	{
		map<char, int>::iterator find;
		find = mapData.find(str.at(i));

		//if char is in map, increase count.
		if(find != mapData.end() && (str.at(i) != ' '))
		{
			//int count = find->second;
			find->second = find->second + 1;
			//cout << "find: " << find->first << " " << find->second <<  endl;
		}
		else if( find == mapData.end() && (str.at(i) != ' ')) // char is not in the map, insert with count 1.
		{
			mapData.insert(std::pair<char,int>(str.at(i), 1));
		}
	}

	int countChar = 0;
	//count number of string without space.
	for(unsigned int i = 0; i < str.size(); i++)
	{
		if( str.at(i) != ' ')
			countChar++;
	}

	bool isPalin = true;
	if( countChar % 2 == 0 ) //mapData has even number element, every char must have its pair.
	{
		for(multimap<char, int>::iterator iter = mapData.begin(); iter != mapData.end(); iter++)
		{
			if( (iter->second % 2) != 0  )
			{
				isPalin = false;
				break;
			}
		}
	}
	else if((countChar % 2 == 1 )) // mapData has odd number element, one odd number element is allowed.
	{
		int oddNumberCount = 0 ;
		for(multimap<char, int>::iterator iter = mapData.begin(); iter != mapData.end(); iter++)
		{
			if( (iter->second % 2) != 0  )
			{
				oddNumberCount++;
				if(oddNumberCount > 1)
				{
					isPalin = false;
					break;
				}
			}
		}
	}

	if(isPalin)
		cout << "Palin!!" << endl;
	else
		cout << "NOT palin!!" << endl;


	for(multimap<char, int>::iterator iter = mapData.begin(); iter != mapData.end(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}

	return 0;
}
