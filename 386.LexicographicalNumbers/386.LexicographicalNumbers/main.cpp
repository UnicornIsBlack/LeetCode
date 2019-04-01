#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> lexicalOrder(int n)
	{
		vector<int> res;
		int insert = 0;
		for ( int i = 1; i <= n; i++ )
		{
			if ( i < 10 )
				res.push_back(i);
			else
			{
				while ( !(res[insert] == i / 10 || res[insert] / 10 == i / 10) )
				{
					insert++;
					if ( insert == res.size() )
						insert = 0;
				}
				if ( insert == res.size() - 1 )
				{
					res.push_back(i);
					insert++;
				}
				else
				{
					insert++;
					res.insert(res.begin() + insert, i);
				}				
			}
		}
		return res;
	}
};


int main()
{
	return 0;
}