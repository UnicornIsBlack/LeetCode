#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution
{
	public:
	bool hasGroupsSizeX(vector<int>& deck)
	{
		map<int, int> counts;
		bool flag = false;
		for ( int i = 0; i < deck.size(); i++ )
		{
			counts[deck[i]]++;
		}
		for ( int i = 2; i <= deck.size(); i++ )
		{
			if ( deck.size() % i == 0 && hasNX(i, counts) )
			{
				flag = true;
				break;
			}
		}
		return flag;
	}
	bool hasNX(int x, map<int, int>& counts)
	{
		map<int, int>::iterator it;
		bool flag = true;
		for ( it = counts.begin(); it != counts.end(); it++ )
		{
			if ( it->second%x != 0 )
			{
				flag = false;
				break;
			}
		}
		return true;
	}
};

int main()
{
	return 0;
}