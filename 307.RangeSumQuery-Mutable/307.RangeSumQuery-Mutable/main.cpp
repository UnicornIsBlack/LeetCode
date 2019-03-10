#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class NumArray
{
	public:
	NumArray(vector<int> nums)
	{
		copy = vector<int>(nums.begin(), nums.end());
	}

	void update(int i, int val)
	{
		copy[i] = val;
	}

	int sumRange(int i, int j)
	{
		int sum = 0;
		for ( int n = i; n <= j; n++ )
			sum += copy[n];
		return sum;
	}
	private:
	vector<int> copy;
};

/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* obj.update(i,val);
* int param_2 = obj.sumRange(i,j);
*/

int main()
{
	return 0;
}