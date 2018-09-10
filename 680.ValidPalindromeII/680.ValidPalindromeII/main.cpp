#include <iostream>
#include <string>

using namespace std;

class Solution
{
	public:
	bool validPalindrome(string s)
	{
		return isPalindrome(s, 0, s.size() - 1, false);
	}
	bool isPalindrome(string s,int startIndex,int endIndex,bool flag)
	{
		int len = endIndex - startIndex + 1;
		for ( int i = 0; i <= len / 2; i++ )
		{
			if ( s[i + startIndex] != s[endIndex - i] )
			{
				if ( !flag )
				{
					flag = true;
					return isPalindrome(s, i + startIndex, endIndex - i - 1, flag) ||
						isPalindrome(s, i + startIndex + 1, endIndex - i, flag);
				}
				return false;
			}
		}
		return true;
	}
};

int main()
{
	return 0;
}