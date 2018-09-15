#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class KthLargest
{
	public:
	int k;
	vector<int> nums;
	KthLargest(int k, vector<int> nums)
	{
		this->k = k;
		this->nums = nums;
		sort(this->nums.begin(), this->nums.end());
	}

	int add(int val)
	{
		if ( this->nums.size() == 0 )
			this->nums.push_back(val);
		else if ( val >= this->nums[this->nums.size() - 1] )
			this->nums.push_back(val);
		else
		{
			for ( int i = 0; i < this->nums.size(); i++ )
			{
				if ( val <= this->nums[i] )
				{
					this->nums.insert(this->nums.begin() + i, val);
					break;
				}
			}
		}
		
		for ( int i = 0; i<this->nums.size(); i++ )
		{
			cout << this->nums[i] << " " ;
		}
		cout << endl;
		return this->nums[this->nums.size() - this->k];
	}
};

/**
* Your KthLargest object will be instantiated and called as such:
* KthLargest obj = new KthLargest(k, nums);
* int param_1 = obj.add(val);
*/

int main()
{
	return 0;
}