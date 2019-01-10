#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int compareVersion(string version1, string version2)
	{
		vector<string> v1 = split(version1, '.');
		vector<string> v2 = split(version2, '.');
		for ( int i = 0; i < v1.size() && i < v2.size(); i++ )
		{
			int ver1;
			int ver2;
			str2int(ver1, v1[i]);
			str2int(ver2, v2[i]);
			if ( ver1 > ver2 )
				return 1;
			else if ( ver1 < ver2 )
				return -1;
		}
		if ( v1.size() == v2.size() )
			return 0;
		else if ( v1.size() < v2.size() )
		{
			for ( int i = v1.size(); i < v2.size(); i++ )
			{
				int ver2;
				str2int(ver2, v2[i]);
				if ( ver2 != 0 )
					return -1;
			}
		}
		else if ( v1.size() > v2.size() )
		{
			for ( int i = v2.size(); i < v1.size(); i++ )
			{
				int ver1;
				str2int(ver1, v1[i]);
				if ( ver1 != 0 )
					return 1;
			}
		}
		return 0;
	}
	void str2int(int &int_temp, const string &string_temp)
	{
		stringstream stream(string_temp);
		stream >> int_temp;
	}

	vector<string> split(string str, char s)
	{
		vector<string> result;
		int start = 0;
		int end = 0;
		bool flag = false;
		for ( int i = 0; i < str.size(); i++ )
		{
			if ( str[i] != s  )
			{
				if ( !flag )
				{
					start = i;
					end = i;
					flag = true;
				}
				else
					end++;
				
			}
			if ( i == str.size() - 1 )
				result.push_back(str.substr(start, end - start + 1));
			if ( str[i] == s )
			{
				if ( flag )
				{
					flag = false;
					result.push_back(str.substr(start, end - start + 1));
				}
			}
		}
		return result;
	}
};

int main()
{
	return 0;
}