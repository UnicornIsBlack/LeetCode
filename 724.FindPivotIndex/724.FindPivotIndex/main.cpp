#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int pivotIndex(vector<int>& nums)
	{
		int sum = 0;
		for ( int i = 0; i < nums.size(); i++ )
		{
			sum += nums[i];
		}

		int index = -1;
		int sumLeft = 0;
		int sumRight = sum;
		for ( int i = 0; i < nums.size(); i++ )
		{
			sumRight -= nums[i];
			if ( sumLeft == sumRight )
			{
				index = i;
				break;
			}
			sumLeft += nums[i];
		}
		return index;
	}
};

int main()
{
	return 0;
}