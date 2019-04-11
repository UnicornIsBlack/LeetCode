#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string removeKdigits(string num, int k)
	{
		for ( int i = 0; i < k; i++ )
		{
			if ( num.size() == 0 )
				break;
			int index = 0;
			for ( int j = 1; j < num.size(); j++ )
			{
				if ( num[j] >= num[j - 1] )
					index = j;
				else
					break;
			}
			num.erase(index, 1);
		}
		while ( num[0] == '0' && num.size() > 1 )
			num.erase(0, 1);
		if ( num == "" )
			num = "0";
		return num;
	}


};

int main()
{
	return 0;
}