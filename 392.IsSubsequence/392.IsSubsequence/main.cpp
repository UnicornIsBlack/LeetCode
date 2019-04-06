#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool isSubsequence(string s, string t)
	{
		int start = string::npos;
		for ( int i = 0; i < s.size(); i++ )
		{
			if ( i == 0 )
				start = t.find(s[i]);
			else
				start = t.find(s[i], start + 1);
			if ( start == string::npos )
				return false;
		}
		return true;
	}
};

int main()
{
	return 0;
}