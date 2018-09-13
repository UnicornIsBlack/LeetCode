#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
	public:
	bool hasAlternatingBits(int n)
	{
		int tmp = n;
		bool flag = true;
		int key = tmp & 1;
		tmp >>= 1;
		while ( tmp != 0 )
		{
			if ( key == (tmp & 1) )
			{
				flag = false;
				break;
			}
			key = tmp & 1;
			tmp >>= 1;
		}
		return flag;
	}
};

int main()
{
	return 0;
}