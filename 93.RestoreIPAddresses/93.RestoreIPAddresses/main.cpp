#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<string> restoreIpAddresses(string s)
	{
		set<string> resSet;
		vector<string> result;
		dfs(resSet, s, 0, 0);
		set<string>::iterator it;
		for ( it = resSet.begin(); it != resSet.end(); it++ )
		{
			result.push_back(*it);
		}
		return result;
	}

	void dfs(set<string>& result, string s, int count, int index)
	{
		if ( count == 3 )
		{
			if ( isValid(s) )
				result.insert(s);
			return;
		}
		if ( index >= s.size() - 1 )
			return;
		for ( int i = 1; i < 4; i++ )
		{
			string tmp = s;
			if ( index + i >= tmp.size() )
				break;
			tmp.insert(index + i, 1, '.');
			dfs(result, tmp, count + 1, index + i + 1);
		}
	}

	void str2int(int &int_temp, const string &string_temp)
	{
		stringstream stream(string_temp);
		stream >> int_temp;
	}

	bool isValid(string s)
	{
		vector<string> str = split(s, ".");
		for ( int i = 0; i < str.size(); i++ )
		{
			if ( str[i].size() > 3 )
				return false;
			if ( str[i].size() > 1 && str[i][0] == '0' )
				return false;
			int tmp;
			str2int(tmp, str[i]);
			if ( tmp > 255 )
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