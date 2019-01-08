#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> res;
		for ( int i = 0; i < tokens.size(); i++ )
		{
			if ( tokens[i].size() == 1 && isdigit(tokens[i][0]) == 0 )
			{
				calculate(res, tokens[i][0]);
			}
			else
			{
				int num;
				str2int(num, tokens[i]);
				res.push(num);
			}
		}
		int result = res.top();
		res.pop();
		return result;
	}

	void calculate(stack<int>& res, char c)
	{
		int b = res.top();
		res.pop();
		int a = res.top();
		res.pop();
		int result;
		switch ( c )
		{
			case '+':
				result = a + b;
				break;
			case '-':
				result = a - b;
				break;
			case '*':
				result = a * b;
				break;
			case '/':
				result = a / b;
				break;
		}
		res.push(result);
	}

	void str2int(int &int_temp, const string &string_temp)
	{
		stringstream stream(string_temp);
		stream >> int_temp;
	}
};

int main()
{
	return 0;
}