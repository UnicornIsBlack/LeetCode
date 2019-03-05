#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int nthUglyNumber(int n)
	{
		int index2 = 0, index3 = 0, index5 = 0;
		vector<int> ugly = { 1 };
		while ( --n > 0 )
		{
			int val = min(ugly[index2] * 2, min(ugly[index3] * 3, ugly[index5] * 5));
			ugly.push_back(val);
			while ( ugly[index2] * 2 <= val ) index2++;
			while ( ugly[index3] * 3 <= val ) index3++;
			while ( ugly[index5] * 5 <= val ) index5++;
		}
		return ugly.back();
	}
};

int main()
{
	return 0;
}