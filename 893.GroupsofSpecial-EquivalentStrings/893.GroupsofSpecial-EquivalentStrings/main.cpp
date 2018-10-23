#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class Solution
{
	public:
	int numSpecialEquivGroups(vector<string>& A)
	{
		set<map<char, int>> strSet;
		for (string s : A )
		{
			strSet.insert(countChar(s));
		}
		return strSet.size();
	}

	map<char, int> countChar(string str)
	{
		map<char, int> charCounter;
		for ( int i = 0; i < str.size(); i += 2 )
		{
			charCounter[str[i]]++;
		}
		for ( int i = 1; i < str.size(); i += 2 )
		{
			charCounter[-str[i]]++;
		}
		return charCounter;
	}
};

int main()
{
	return 0;
}