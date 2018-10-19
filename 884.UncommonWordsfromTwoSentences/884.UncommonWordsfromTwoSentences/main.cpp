#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
	public:
	vector<string> uncommonFromSentences(string A, string B)
	{
		vector<string> aStrs = split(A, " ");
		vector<string> bStrs = split(B, " ");
		vector<string> strList;
		map<string,int> words;
		map<string,int>::iterator it;
		for ( int i = 0; i < aStrs.size(); i++ )
		{
			it = words.find(aStrs[i]);
			if ( it != words.end() )
			{
				it->second++;
			}
			else
				words.insert(make_pair(aStrs[i], 1));
		}
		for ( int i = 0; i < bStrs.size(); i++ )
		{
			it = words.find(bStrs[i]);
			if ( it != words.end() )
			{
				it->second++;
			}
			else
				words.insert(make_pair(bStrs[i], 1));
		}
		for ( it = words.begin(); it != words.end(); it++ )
		{
			if ( it->second == 1 )
				strList.push_back(it->first);
		}
		return strList;
	}

	vector<string> split(const string &s, const string &seperator)
	{
		vector<string> result;
		typedef string::size_type string_size;
		string_size i = 0;

		while ( i != s.size() )
		{
			//�ҵ��ַ������׸������ڷָ�������ĸ��
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

			//�ҵ���һ���ָ������������ָ���֮����ַ���ȡ����
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