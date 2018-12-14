#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<vector<int>> permute(vector<int>& nums)
	{
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		result.push_back(nums);
		while ( nextPermutation(nums) )
		{
			result.push_back(nums);
		}
		return result;
	}

	bool nextPermutation(vector<int>& nums)
	{
		bool flag = false;
		int index = -1;
		int len = nums.size();
		for ( int i = len - 2; i >= 0; i-- )
		{
			for ( int j = len - 1; j > i; j-- )
			{
				if ( nums[j] > nums[i] )
				{
					flag = true;
					int tmp = nums[j];
					nums[j] = nums[i];
					nums[i] = tmp;
					index = i;
					break;
				}
			}
			if ( flag )
				break;
		}
		if ( index == -1 )
			return false;
		quick_sort(nums, index + 1, len - 1);
		return true;
	}
	void quick_sort(vector<int>& nums, int low, int high)
	{
		if ( low > high )
			return;
		int key = nums[low];
		int i = low;
		int j = high;
		while ( i < j )
		{
			while ( i < j && nums[j] >= key )
				j--;
			while ( i < j && nums[i] <= key )
				i++;
			if ( i < j )
			{
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
		nums[low] = nums[i];
		nums[i] = key;
		quick_sort(nums, low, i - 1);
		quick_sort(nums, i + 1, high);
	}
};

int main()
{
	return 0;
}