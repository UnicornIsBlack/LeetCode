#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	void wiggleSort(vector<int>& nums)
	{
		sort_quick(nums, 0, nums.size() - 1);
		int len = nums.size(), low = 0, high = len - 1, mid = nums[len / 2], i = 0;
		auto index = [=](int pos) { return (1 + pos * 2) % (len | 1); };
		while ( i <= high )
		{
			if ( nums[index(i)] > mid ) swap(nums[index(i++)], nums[index(low++)]);
			else if ( nums[index(i)]<mid ) swap(nums[index(i)], nums[index(high--)]);
			else i++;
		}
	}

	void sort_quick(vector<int>& nums, int low, int high)
	{
		if ( low > high )
			return;
		int i = low, j = high;
		int key = nums[low];
		int tmp;
		while ( i < j )
		{
			while ( i < j && nums[j] >= key ) j--;
			while ( i < j && nums[i] <= key ) i++;
			if ( i < j )
			{
				tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
		nums[low] = nums[i];
		nums[i] = key;
		sort_quick(nums, low, i - 1);
		sort_quick(nums, i + 1, high);
	}
};

int main()
{
	return 0;
}