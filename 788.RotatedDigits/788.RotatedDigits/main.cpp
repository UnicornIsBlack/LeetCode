#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int rotatedDigits(int N)
	{
		int count = 0;
		for ( int i = 1; i <= N; i++ )
		{
			int val = i;
			bool flag = false;
			while ( val != 0 )
			{
				int mod = val % 10;
				val = val / 10;
				int rotate = isNumRotate(mod);
				if ( rotate == -1 )
				{
					flag = false;
					break;
				}
				else if ( rotate == 1 )
					flag = true;
			}
			if ( flag )
				count++;
		}
		return count;
	}

	int isNumRotate(int num)
	{
		int rotate = 0;
		switch ( num )
		{
			case 0:
			case 1:
			case 8:
				rotate = 0;
				break;
			case 2:
			case 5:
			case 6:
			case 9:
				rotate = 1;
				break;
			default:
				rotate = -1;
				break;
		}
		return rotate;
	}
};

int main()
{
	return 0;
}