#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> numberOfLines(vector<int>& widths, string S)
	{
		int row = S.size();
		int lines = 1;
		int pos = 0;
		for ( int i = 0; i < row; i++ )
		{
			pos += widths[S[i] - 'a'];
			if ( pos > 100 )
			{
				lines++;
				pos = widths[S[i] - 'a'];
			}
		}
		return{ lines, pos };
	}
};


int main()
{
	return 0;
}