#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		map<int, int> hash;
		vector<int> res;
		for ( int i = 0; i < nums.size(); i++ )
			hash[nums[i]]++;
		vector<vector<int>> frequent;
		for ( auto i = hash.begin(); i != hash.end(); i++ )
		{
			vector<int> fre = { i->first, i->second };
			frequent.push_back(fre);
		}
		quick(frequent, 0, frequent.size() - 1);
		for ( int i = frequent.size() - 1; i >= 0 && k > 0; i--,k-- )
		{
			res.push_back(frequent[i][0]);
		}
		return res;
	}
	void quick(vector<vector<int>>& fre, int low, int high)
	{
		if ( low > high )
			return;
		auto key = fre[low];
		int i = low, j = high;
		while ( i < j )
		{
			while ( i < j && fre[j][1] >= key[1] )
				j--;
			while ( i < j && fre[i][1] <= key[1] )
				i++;
			if ( i < j )
			{
				vector<int> tmp = fre[i];
				fre[i] = fre[j];
				fre[j] = tmp;
			}
		}
		fre[low] = fre[i];
		fre[i] = key;
		quick(fre, low, i - 1);
		quick(fre, i + 1, high);
	}
};

int main()
{
	return 0;
}