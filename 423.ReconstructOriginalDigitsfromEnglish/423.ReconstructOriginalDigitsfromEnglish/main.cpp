#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string originalDigits(string s)
	{
		string res = "";
		vector<string> words{ "zero", "two", "four", "six", "eight", "three", "five", "seven", "one", "nine" };
		vector<string> nums{ "0", "2", "4", "6", "8", "3", "5", "7", "1", "9" };
		vector<char> ch{ 'z', 'w', 'u', 'x', 'g', 't', 'f', 's', 'o', 'n' };
		for ( int i = 0; i < nums.size(); i++ )
		{
			while ( s.find(ch[i]) != string::npos )
			{
				deleteStr(s, words[i]);
				res += nums[i];
			}
		}
		sort(res.begin(), res.end());
		return res;
	}

	void deleteStr(string& s, string& str)
	{
		for ( int i = 0; i < str.size(); i++ )
		{
			int index = s.find(str[i]);
			s.erase(index, 1);
		}
	}
};

int main()
{
	return 0;
}