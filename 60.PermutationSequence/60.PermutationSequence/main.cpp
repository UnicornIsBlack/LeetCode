#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string getPermutation(int n, int k)
	{
		string str = "123456789";
		string result(str.begin(), str.begin() + n);
		int count = 1;
		while ( count < k )
		{
			nextPermutation(result);
			count++;
		}
		return result;
	}

	void nextPermutation(string& nums)
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
					char tmp = nums[j];
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
	void quick_sort(string& nums, int low, int high)
	{
		if ( low > high )
			return;
		char key = nums[low];
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
				char tmp = nums[i];
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