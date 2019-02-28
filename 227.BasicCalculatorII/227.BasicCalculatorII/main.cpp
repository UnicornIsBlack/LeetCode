#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int calculate(string s)
	{
		long num = 0;
		char op = '+';
		stack<int> resSt;
		for ( int i = 0; i < s.size(); i++ )
		{
			if ( s[i] >= '0' && s[i] <= '9' )
				num = (num * 10 + s[i] - '0');
			if ( (s[i] < '0' && s[i] != ' ') || i == s.size() - 1 )
			{
				if ( op == '+' ) resSt.push(num);
				if ( op == '-' ) resSt.push(-num);
				if ( op == '*' || op == '/' )
				{
					num = (op == '*') ? num*resSt.top() : resSt.top() / num;
					resSt.pop();
					resSt.push(num);
				}
				op = s[i];
				num = 0;
			}
		}
		int res = 0;
		while ( !resSt.empty() )
		{
			res += resSt.top();
			resSt.pop();
		}
		return res;
	}
};

int main()
{
	return 0;
}