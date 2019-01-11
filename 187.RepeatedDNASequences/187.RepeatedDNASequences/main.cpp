#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<string> findRepeatedDnaSequences(string s)
	{
		set<string> res;
		set<string> substr;
		vector<string> result;
		if ( s.size() < 11 )
			return result;
		for ( int i = 0; i < s.size() - 9; i++ )
		{
			string str = s.substr(i, 10);
			if ( substr.find(str) != substr.end() )
				res.insert(str);
			else
				substr.insert(str);
		}

		result = vector<string>(res.begin(), res.end());
		return result;
	}
};

int main()
{
	return 0;
}