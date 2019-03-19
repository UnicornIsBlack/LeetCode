#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)
	{
		vector<int> indexs(nums1.size(), 0);

		vector<pair<int, int>> res;
		if ( nums1.size() == 0 || nums2.size() == 0 )
			return res;

		while ( k > 0 )
		{
			int index = -1;
			pair<int, int> num;
			int sum;
			for ( int i = 0; i < nums1.size(); i++ )
			{
				if ( indexs[i] == nums2.size() )
					continue;
				int sumI = nums1[i] + nums2[indexs[i]];
				if ( index == -1 )
				{
					sum = sumI;
					index = i;
					continue;
				}
				if ( sumI < sum )
				{
					sum = sumI;
					index = i;
				}
			}
			if ( index == -1 )
				break;
			num.first = nums1[index];
			num.second = nums2[indexs[index]];
			res.push_back(num);
			indexs[index]++;
			k--;
		}
		return res;
	}
};

int main()
{
	return 0;
}