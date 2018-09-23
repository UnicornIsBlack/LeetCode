#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int numJewelsInStones(string J, string S)
	{
		int count = 0;
		for ( int i = 0; i < S.size(); i++ )
		{
			if ( J.find(S[i]) != -1 )
			{
				count++;
			}
		}
		return count;
	}
};

int main()
{
	return 0;
}