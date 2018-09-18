#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool isOneBitCharacter(vector<int>& bits)
	{
		bool flag = false;
		if ( bits.size() == 1 )
			return true;
		if ( bits[bits.size()-2] == 0 )
			return true;
		for ( int i = 0; i < bits.size(); i++ )
		{
			if ( bits[i] == 1 )
			{
				flag = false;
				i++;
			}
			else
			{
				flag = true;
			}
		}
		return flag;
	}
};


int main()
{
	return 0;
}