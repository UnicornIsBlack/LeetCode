#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<string> letterCasePermutation(string S)
	{
		vector<string> result;
		getStrings(S, 0, result);
		return result;
	}
	void getStrings(string S, int i, vector<string> &result)
	{
		if ( i == S.size() )
		{
			result.push_back(S);
			return;
		}
		if ( isdigit(S[i]) != 0 )
			getStrings(S, i + 1, result);
		else
		{
			int index = S[i] - 'a';
			if ( index < 0 || index > 25 )
				index = S[i] - 'A';
			S[i] = index + 'a';
			getStrings(S, i + 1, result);
			S[i] = index + 'A';
			getStrings(S, i + 1, result);
		}
	}
};

int main()
{
	return 0;
}