#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool backspaceCompare(string S, string T)
	{
		string s = "";
		string t = "";
		for ( int i = 0; i < S.size(); i++ )
		{
			if ( S[i] != '#' )
				s += S[i];
			else if ( S[i] == '#' && s.size() > 0 )
				s.erase(s.size() - 1);
		}
		for ( int i = 0; i < T.size(); i++ )
		{
			if ( T[i] != '#' )
				t += T[i];
			else if ( T[i] == '#' && t.size() > 0 )
				t.erase(t.size() - 1);
		}
		if ( s == t )
			return true;
		return false;
	}
};

int main()
{
	return 0;
}