#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	/*
	** 下一个排列是全排列的下一个排列。
	*/
	public:
	void nextPermutation(vector<int>& nums)
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
		quick_sort(nums, index + 1, len - 1);
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