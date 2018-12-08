#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<string> generateParenthesis(int n)
	{
		vector<string> result;
		if ( n == 0 )
			return result;
		string parenthesis = "(";
		generate(parenthesis, 1, 1, 2, result, n);
		return result;
	}
	void generate(string parenthesis, int lone, int left, int m, vector<string>& result, int n)
	{
		if ( m == n*2 )
		{
			parenthesis.push_back(')');
			result.push_back(parenthesis);
			parenthesis.pop_back();
			return;
		}
		if ( left < n )
		{
			parenthesis.push_back('(');
			generate(parenthesis, lone + 1, left + 1, m + 1, result, n);
			parenthesis.pop_back();
			if ( lone != 0 )
			{
				parenthesis.push_back(')');
				generate(parenthesis, lone - 1, left, m + 1, result, n);
				parenthesis.pop_back();
			}
		}
		else if ( left == n )
		{
			parenthesis.push_back(')');
			generate(parenthesis, lone - 1, left, m + 1, result, n);
			parenthesis.pop_back();
		}
	}
};

int main()
{
	return 0;
}