#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> diffWaysToCompute(string input)
	{
		vector<int> res;
		for ( int i = 0; i < input.size(); i++ )
		{
			if ( input[i] == '+' || input[i] == '-' || input[i] == '*' )
			{
				vector<int> left = diffWaysToCompute(input.substr(0, i));
				vector<int> right = diffWaysToCompute(input.substr(i + 1));

				for ( int m = 0; m < left.size(); m++ )
				{
					for ( int n = 0; n < right.size(); n++ )
					{
						if ( input[i] == '+' ) res.push_back(left[m] + right[n]);
						else if ( input[i] == '-' ) res.push_back(left[m] - right[n]);
						else if ( input[i] == '*' ) res.push_back(left[m] * right[n]);
					}
				}
			}
		}
		if ( res.empty() ) res.push_back(atoi(input.c_str()));
		return res;
	}
};

int main()
{
	return 0;
}