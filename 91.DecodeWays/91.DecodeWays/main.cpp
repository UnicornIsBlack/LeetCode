#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int numDecodings(string s)
	{
		if ( s.empty() )
			return 0;
		int count = 0;
		vector<int> res(s.size(), 0);
		for ( int i = 0; i < res.size(); i++ )
		{
			if ( i == 0 )
			{
				if ( s[i] != '0' )
					res[i]++;
			}
			else
			{
				int a = s[i - 1] - '0';
				int b = s[i] - '0';
				int num = a * 10 + b;
				
				if ( i == 1 )
				{
					if ( b == 0 )
					{
						if ( num == 10 || num == 20 )
							res[i] = 1;
						else
							res[i] = 0;
					}
					else
					{
						if ( num < 10 )
							res[i] = 0;
						else if ( num > 10 && num <= 26 )
							res[i] = 2;
						else
							res[i] = 1;
					}
				}
				else
				{
					if ( a == 0 && b == 0 )
						res[i] = 0;
					else if ( a == 0 && b != 0 )
						res[i] = res[i - 1];
					else if ( a != 0 && b == 0 )
					{
						if ( num <= 26 )
							res[i] = res[i - 2];
						else
							res[i] = 0;
					}
					else
					{
						if ( num <= 26 )
							res[i] = res[i - 1] + res[i - 2];
						else
							res[i] = res[i - 1];
					}
				}
			}

		}
		return res[res.size() - 1];
	}
};

int main()
{
	return 0;
}