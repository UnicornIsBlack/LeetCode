#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string intToRoman(int num)
	{
		string result;
		vector<int> nums = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
		vector<string> romans = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

		for ( int i = 0; i < nums.size(); i++ )
		{
			int count = num / nums[i];
			num = num%nums[i];
			while ( count != 0 )
			{
				result += romans[i];
				count--;
			}
		}
		return result;
	}
};

int main()
{
	return 0;
}