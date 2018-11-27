#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string longestPalindrome(string s)
	{
		int index = 0;
		int maxLen = 0;
		for ( int i = 0; i < s.size(); i++ )
		{
			int maxOdd = maxPalindrome(s, i, i);
			int maxEven = maxPalindrome(s, i, i + 1);
			int maxNum = max(maxOdd, maxEven);
			if ( maxNum > maxLen )
			{
				if ( maxOdd > maxEven )
				{
					index = i - (maxOdd / 2);
					maxLen = maxOdd;
				}
				else if ( maxOdd < maxEven )
				{
					index = i - (maxEven / 2) + 1;
					maxLen = maxEven;
				}
			}
		}
		return s.substr(index, maxLen);
	}

	int maxPalindrome(string s, int m, int n)
	{
		while ( m >= 0 && n < s.size() && s[m] == s[n] )
		{
			m--;
			n++;
		}
		return n - m - 1;
	}
};

int main()
{
	return 0;
}