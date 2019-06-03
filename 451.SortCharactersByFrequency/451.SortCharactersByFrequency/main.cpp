#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string frequencySort(string s)
	{
		unordered_map<char, int> um;
		for ( int i = 0; i < s.size(); i++ )
			um[s[i]]++;
		vector<string> str(s.size() + 1, "");
		for ( auto val : um )
			str[val.second].append(val.second, val.first);
		string res;
		for ( int i = s.size(); i > 0; i-- )
			res += str[i];
		return res;
	}
};

int main()
{
	return 0;
}