#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int hIndex(vector<int>& citations)
	{
		int h = -1;
		int len = citations.size();
		for ( int i = 1; i <= len; i++ )
		{
			if ( i > citations[len - i] )
			{
				h = i - 1;
				break;
			}
		}
		if ( h == -1 )
			h = len;
		return h;
	}
};

int main()
{
	return 0;
}