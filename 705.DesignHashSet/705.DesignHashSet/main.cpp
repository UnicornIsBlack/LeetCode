#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define HASH_UNIT 128

class MyHashSet
{
	public:
	/** Initialize your data structure here. */
	vector<vector<bool>> table;
	MyHashSet()
	{
		table = vector<vector<bool>>(HASH_UNIT, vector<bool>(HASH_UNIT, false));
	}

	void add(int key)
	{
		if ( contains(key) )
			return;
		this->table[key / HASH_UNIT][key%HASH_UNIT] = true;
	}

	void remove(int key)
	{
		if ( !contains(key) )
			return;
		this->table[key / HASH_UNIT][key%HASH_UNIT] = false;
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key)
	{
		return this->table[key / HASH_UNIT][key%HASH_UNIT];
	}
};

/**
* Your MyHashSet object will be instantiated and called as such:
* MyHashSet obj = new MyHashSet();
* obj.add(key);
* obj.remove(key);
* bool param_3 = obj.contains(key);
*/

int main()
{
	return 0;
}