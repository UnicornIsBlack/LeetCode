#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
	public:
	string mostCommonWord(string paragraph, vector<string>& banned)
	{
		vector<string> words = split(paragraph, " ,.;/!?@#$%^&*():'\"<>");
		for ( int i = 0; i < banned.size(); i++ )
		{
			transform(banned[i].begin(), banned[i].end(), banned[i].begin(), ::tolower);
		}
		map<string,int> wordsMap;
		map<string, int>::iterator mapIt;
		vector<string>::iterator vectorIt;
		for ( int i = 0; i < words.size(); i++ )
		{
			transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
			vectorIt = find(banned.begin(), banned.end(), words[i]);
			if ( vectorIt != banned.end() )
				continue;
			mapIt = wordsMap.find(words[i]);
			if ( mapIt != wordsMap.end() )
				wordsMap[mapIt->first] += 1;
			else
				wordsMap.insert(make_pair(words[i], 1));
		}
		int maxNum = 0;
		string result = "";
		for ( mapIt = wordsMap.begin(); mapIt != wordsMap.end(); mapIt++ )
		{
			if ( maxNum < mapIt->second )
			{
				result = mapIt->first;
				maxNum = mapIt->second;
			}
		}
		return result;
	}
	vector<string> split(const string &s, const string &seperator)
	{
		vector<string> result;
		typedef string::size_type string_size;
		string_size i = 0;

		while ( i != s.size() )
		{
			//找到字符串中首个不等于分隔符的字母；
			int flag = 0;
			while ( i != s.size() && flag == 0 )
			{
				flag = 1;
				for ( string_size x = 0; x < seperator.size(); ++x )
				if ( s[i] == seperator[x] )
				{
					++i;
					flag = 0;
					break;
				}
			}

			//找到又一个分隔符，将两个分隔符之间的字符串取出；
			flag = 0;
			string_size j = i;
			while ( j != s.size() && flag == 0 )
			{
				for ( string_size x = 0; x < seperator.size(); ++x )
				if ( s[j] == seperator[x] )
				{
					flag = 1;
					break;
				}
				if ( flag == 0 )
					++j;
			}
			if ( i != j )
			{
				result.push_back(s.substr(i, j - i));
				i = j;
			}
		}
		return result;
	}
};

int main()
{
	return 0;
}