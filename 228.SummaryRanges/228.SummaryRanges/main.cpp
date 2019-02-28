#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<string> summaryRanges(vector<int>& nums)
	{
		vector<string> res;
		if ( nums.size() == 0 )
			return res;
		int start = nums[0];
		int end = start;
		for ( int i = 1; i <= nums.size(); i++ )
		{
			if ( i != nums.size() && nums[i] == nums[i - 1] + 1 )
				end++;
			else
			{
				string startStr, endStr;
				int2str(start, startStr);
				int2str(end, endStr);
				if ( start == end )
					res.push_back(startStr);
				else
					res.push_back(startStr + "->" + endStr);
				if ( i == nums.size() )
					break;
				start = nums[i];
				end = nums[i];
			}
		}
		return res;
	}
	void int2str(const int &int_temp, string &string_temp)
	{
		stringstream stream;
		stream << int_temp;
		string_temp = stream.str();
	}
};

int main()
{
	return 0;
}