#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	void reverseWords(string &s)
	{
		if ( s.size() == 0 )
			return;
		string result;
		bool isBegin = false;
		int start;
		int end;
		for ( int i = 0; i < s.size(); i++ )
		{
			if ( (i != 0 && s[i] == ' ' && s[i - 1] == ' ') || (i == 0 && s[i] == ' ') )
				continue;
			if ( s[i] == ' ' )
			{
				isBegin = false;
				if ( result.size() == 0 )
					result = string(s.begin() + start, s.begin() + end + 1);
				else
					result = string(s.begin() + start, s.begin() + end + 1) + ' ' + result;
			}
			else
			{
				if ( !isBegin )
				{
					start = i;
					end = start;
					isBegin = true;
				}
				else
					end++;
			}
		}
		if ( s[s.size() - 1] != ' ' )
		{
			if ( result.size() == 0 )
				result = string(s.begin() + start, s.begin() + end + 1);
			else
				result = string(s.begin() + start, s.begin() + end + 1) + ' ' + result;
		}
		s = result;
	}
};

int main()
{
	return 0;
}