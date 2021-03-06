#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<string> reorderLogFiles(vector<string>& logs)
	{
		vector<string> result;
		vector<string> numLogs;
		for ( int i = 0; i < logs.size(); i++ )
		{
			vector<string> words = split(logs[i], " ");
			if ( isNum(words[1]) != 0 )
				numLogs.push_back(logs[i]);
			else
				insertResult(result, logs[i]);
		}
		for ( int i = 0; i < numLogs.size(); i++ )
		{
			result.push_back(numLogs[i]);
		}
		return result;
	}
	void insertResult(vector<string>& result, string& log)
	{
		bool insert = false;
		for ( int i = 0; i < result.size(); i++ )
		{
			vector<string> log1 = split(log, " ");
			vector<string> log2 = split(result[i], " ");
			if ( compareStrings(log1, log2) )
			{
				result.insert(result.begin() + i, log);
				insert = true;
				break;
			}
		}
		if ( !insert )
			result.push_back(log);
	}
	bool compareStrings(vector<string>& log1, vector<string>& log2)
	{
		bool isSame = true;
		bool flag = false;
		for ( int i = 1; i < log1.size() && i < log2.size(); i++ )
		{
			if ( log1[i] == log2[i] )
				continue;
			else
			{
				if ( log1[i] < log2[i] )
				{
					flag = true;
				}
				isSame = false;
				break;
			}
		}
		if ( isSame )
		{
			if ( log1.size() == log2.size() )
			{
				if ( log1[0] <= log2[0] )
					flag = true;
			}
			else if ( log1.size() < log2.size() )
				flag = true;
		}
		return flag;
	}
	bool isNum(string word)
	{
		for ( int i = 0; i < word.size(); i++ )
		{
			if ( isdigit(word[i]) != 0 )
				continue;
			return false;
		}
		return true;
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