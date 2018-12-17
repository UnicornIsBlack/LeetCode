#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using namespace std;

class Solution
{
	public:
	vector<vector<string>> groupAnagrams(vector<string>& strs)
	{

		vector<vector<string>> result;
		if ( strs.empty() )
			return result;
		//set 不允许有重复数据， multiset 允许存在重复数据
		unordered_map<string, multiset<string>> strMap;
		for ( string str : strs )
		{
			string tmp = str;
			sort(tmp.begin(), tmp.end());
			strMap[tmp].insert(str);
		}

		for ( auto m : strMap )
		{
			vector<string> words(m.second.begin(), m.second.end());
			result.push_back(words);
		}
		return result;
	}
};

int main()
{
	return 0;
}