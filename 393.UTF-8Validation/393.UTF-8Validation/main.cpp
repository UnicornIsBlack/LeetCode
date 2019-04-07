#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Solution
{
	public:
	bool validUtf8(vector<int>& data)
	{
		int count = 0;
		for ( auto c : data )
		{
			if ( count == 0 )
			{
				if ( (c >> 5) == 0x06 )count = 1;
				else if ( (c >> 4) == 0x0E )count = 2;
				else if ( (c >> 3) == 0x1E )count = 3;
				else if ( (c >> 7) )return false;
			}
			else
			{
				if ( (c >> 6) != 0x02 )return false;
				count--;
			}
		}
		return count == 0;
	}
};

int main()
{
	return 0;
}