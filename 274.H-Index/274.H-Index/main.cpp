#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int hIndex(vector<int>& citations)
	{
		quick_sort(citations, 0, citations.size() - 1);
		int h = -1;
		for ( int i = 0; i < citations.size(); i++ )
		{
			if ( i + 1 > citations[i] )
			{
				h = i;
				break;
			}
		}
		if ( h == -1 )
			h = citations.size();
		return h;
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
			while ( i < j && nums[j] <= key ) j--;
			while ( i < j && nums[i] >= key ) i++;
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