#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class RandomizedSet
{
	public:
	/** Initialize your data structure here. */
	RandomizedSet()
	{

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val)
	{
		auto it = index.find(val);
		if ( it == index.end() )
		{
			index[val] = nums.size();
			nums.push_back(val);
			return true;
		}
		return false;
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val)
	{
		auto it = index.find(val);
		if ( it == index.end() )
			return false;
		else
		{
			int pos = it->second;
			nums[pos] = nums.back();
			index[nums.back()] = pos;
			index.erase(val);
			nums.pop_back();
		}
		return true;
	}

	/** Get a random element from the set. */
	int getRandom()
	{
		return nums[rand() % nums.size()];
	}
	private:
	vector<int> nums;
	map<int, int> index;
};

/**
* Your RandomizedSet object will be instantiated and called as such:
* RandomizedSet obj = new RandomizedSet();
* bool param_1 = obj.insert(val);
* bool param_2 = obj.remove(val);
* int param_3 = obj.getRandom();
*/

int main()
{
	return 0;
}