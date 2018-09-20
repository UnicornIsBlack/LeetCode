#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Solution
{
	public:
	vector<int> selfDividingNumbers(int left, int right)
	{
		vector<int> numbers;
		for ( int i = left; i <= right; i++ )
		{
			if ( isDividing(i) )
				numbers.push_back(i);
		}
	}
	bool isDividing(int num)
	{
		int val = num;
		int mod = 0;
		bool flag = true;
		while ( val != 0 )
		{
			mod = val % 10;
			if ( mod == 0 || num % mod != 0 )
			{
				flag = false;
				break;
			}
			val /= 10;
		}
		return flag;
	}
};


int main()
{
	return 0;
}