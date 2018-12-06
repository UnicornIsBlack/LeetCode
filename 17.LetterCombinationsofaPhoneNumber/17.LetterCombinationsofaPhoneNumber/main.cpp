#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<string> letterCombinations(string digits)
	{
		if ( digits.size() == 0 )
			return{};
		vector<string> element = { " ", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		int len = 1;
		for ( int i = 0; i < digits.size(); i++ )
		{
			int num = digits[i] - '0';
			len *= element[num].size();
		}
		vector<string> result(len);
		for ( int i = 0; i < len; i++ )
		{
			int mod = len;
			for ( int j = 0; j < digits.size(); j++ )
			{
				int num = digits[j] - '0';
				int divisor = mod / element[num].size();
				int index = (i%mod) / divisor;
				result[i] = result[i] + element[num][index];
				mod /= element[num].size();
			}
		}
		return result;
	}
};

int main()
{
	return 0;
}