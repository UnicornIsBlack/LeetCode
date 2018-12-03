#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int myAtoi(string str)
	{
		string num;
		string positiveMax = "2147483647";
		string negativeMax = "2147483648";
		bool start = false;
		char flag = '+';
		for ( int i = 0; i < str.size(); i++ )
		{
			if ( str[i] == ' ' && !start )
				continue;
			else
			{
				if ( (str[i] == '+' || str[i] == '-') && !start )
				{
					flag = str[i];
					start = true;
					continue;
				}
				else if ( isdigit(str[i]) != 0 )
				{
					start = true;
					if ( str[i] == '0' && num.size() == 0 )
						continue;
					num = num + str[i];
				}
				else
					break;
			}
		}
		if ( num.empty() )
			return 0;
		int result = 0;
		for ( int i = 0; i < num.size(); i++ )
		{
			result = result * 10 + (num[i] - '0');
		}
		if ( flag == '+' )
		{
			if ( num.size() > positiveMax.size() || (num.size() == positiveMax.size() && num > positiveMax) )
				return 2147483647;
			return result;
		}
		else
		{
			if ( num.size() > negativeMax.size() || (num.size() == negativeMax.size() && num > negativeMax) )
				return -2147483648;
			return -result;
		}

		return result;
	}

};

int main()
{
	string str = "  -297 words and 987";
	Solution solution;
	if ( "42" > "2222" )
		cout << 1 << endl;
	cout << solution.myAtoi(str) << endl;
	return 0;
}