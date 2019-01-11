#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string largestNumber(vector<int>& nums)
	{
		string result;
		if ( nums.size() == 0 )
			return result;
		for ( int i = 0; i < nums.size(); i++ )
		{
			int index = i;
			for ( int j = i + 1; j < nums.size(); j++ )
			{
				if ( !compare(nums, index, j) )
					index = j;
			}
			int tmp = nums[i];
			nums[i] = nums[index];
			nums[index] = tmp;
		}
		for ( int i = 0; i < nums.size(); i++ )
		{
			string res;
			int2str(nums[i], res);
			result += res;
		}
		if ( result[0] == '0' )
			return "0";
		return result;
	}
	bool compare(vector<int>& nums, int i, int j)
	{
		string iStr;
		string jStr;
		int2str(nums[i], iStr);
		int2str(nums[j], jStr);
		string a = iStr + jStr;
		string b = jStr + iStr;
		if ( a >= b )
			return true;
		else
			return false;

	}
	void int2str(const int &int_temp, string &string_temp)
	{
		stringstream stream;
		stream << int_temp;
		string_temp = stream.str();   //此处也可以用 stream>>string_temp  
	}
};

int main()
{
	return 0;
}