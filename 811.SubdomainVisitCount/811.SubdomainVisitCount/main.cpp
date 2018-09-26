#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

class Solution
{
	public:
	vector<string> subdomainVisits(vector<string>& cpdomains)
	{
		map<string, int> domainMap;
		map<string, int>::iterator it;

		for ( int i = 0; i < cpdomains.size(); i++ )
		{
			vector<string> str = split(cpdomains[i], " ");

			int count = 0;
			str2int(count, str[0]);

			vector<string> domains = split(str[1], ".");
			string domain = "";
			for ( int j = domains.size() - 1; j >= 0; j-- )
			{
				domain = domains[j] + domain;
				it = domainMap.find(domain);
				if ( it != domainMap.end() )
				{
					domainMap[it->first] += count;
				}
				else
					domainMap.insert(make_pair(domain, count));
				domain = "." + domain;
			}
		}
		vector<string> domainsCount;
		for ( it = domainMap.begin(); it != domainMap.end(); it++ )
		{
			string count;
			int2str(it->second, count);

			string str = count + " " + it->first;
			domainsCount.push_back(str);
		}
		return domainsCount;
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

	void int2str(const int &int_temp, string &string_temp)
	{
		stringstream stream;
		stream << int_temp;
		string_temp = stream.str();   //此处也可以用 stream>>string_temp  
	}

	void str2int(int &int_temp, const string &string_temp)
	{
		stringstream stream(string_temp);
		stream >> int_temp;
	}
};

int main()
{
	Solution solution;
	vector<string> cpdomains = { "9001 discuss.leetcode.com" };
	solution.subdomainVisits(cpdomains);
	return 0;
}