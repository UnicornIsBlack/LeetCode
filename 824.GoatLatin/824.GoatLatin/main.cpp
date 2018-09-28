#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string toGoatLatin(string S)
	{
		string vowels = "aeiouAEIOU";
		vector<string> words = split(S, " ");
		for ( int i = 0; i < words.size(); i++ )
		{
			if ( vowels.find(words[i][0]) != string::npos )
				words[i] += "ma";
			else
			{
				char c = words[i][0];
				words[i].erase(0, 1);
				words[i] = words[i] + c;
				words[i] += "ma";
			}
		}
		string result = "";
		string a = "a";
		for ( int i = 0; i < words.size(); i++ )
		{
			result += (words[i] + a);
			if ( i != words.size() - 1 )
				result += " ";
			a += "a";
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