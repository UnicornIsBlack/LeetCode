#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	void sortColors(vector<int>& nums)
	{
		if ( nums.size() < 1 )
			return;
		int red = 0;
		int blue = nums.size() - 1;
		int tmp;
		for ( int i = 0; i <= blue; i++ )
		{
			if ( nums[i] == 0 )
			{
				tmp = nums[i];
				nums[i] = nums[red];
				nums[red] = tmp;
				red++;
			}
			else if ( nums[i] == 2 )
			{
				tmp = nums[i];
				nums[i] = nums[blue];
				nums[blue] = tmp;
				i--;
				blue--;
			}
		}
	}
};

int main()
{
	return 0;
}