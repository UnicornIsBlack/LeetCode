#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string reverseOnlyLetters(string S)
	{
		string result;
		for ( int i = 0, j = S.size() - 1; i < S.size(); i++,j-- )
		{
			if ( isalpha(S[i]) == 0 )
			{
				result = result + S[i];
				j++;
			}
			else
			{
				while ( isalpha(S[j]) == 0 )
					j--;
				result = result + S[j];
			}
		}
		return result;
	}
};

int main()
{
	return 0;
}