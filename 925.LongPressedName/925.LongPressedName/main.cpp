#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool isLongPressedName(string name, string typed)
	{
		bool flag = true;
		for ( int i = 0, j = 0; i < name.size() && j < typed.size(); i++, j++ )
		{
			if ( name[i] == typed[j] )
				continue;
			else
			{
				if ( j > 0 && typed[j] == typed[j - 1] )
				{
					i--;
					continue;
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
		if ( name[name.size() - 1] != typed[typed.size() - 1] )
			flag = false;
		return flag;
	}
};

int main()
{
	return 0;
}