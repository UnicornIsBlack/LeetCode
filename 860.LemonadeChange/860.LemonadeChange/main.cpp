#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool lemonadeChange(vector<int>& bills)
	{
		int USD5 = 0;
		int USD10 = 0;
		int USD20 = 0;
		for ( int i = 0; i < bills.size(); i++ )
		{
			switch ( bills[i] )
			{
				case 5:
					USD5++; break;
				case 10:
					USD10++; USD5--; break;
				case 20:
					USD20++; 
					if ( USD10 != 0 )
					{
						USD10--; USD5--;
					}
					else
						USD5 -= 3;
					break;
			}
			if ( USD5 < 0 || USD10 < 0 )
				return false;
		}
		return true;
	}
};

int main()
{
	return 0;
}