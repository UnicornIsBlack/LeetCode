#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	string toLowerCase(string str)
	{
		for ( int i = 0; i < str.size(); i++ )
		{
			if ( isalpha(str[i]) != 0 )
			{
				if ( str[i] >= 'A' && str[i] <= 'Z' )
					str[i] = str[i] - 'A' + 'a';
			}
		}
		return str;
	}
};

int main()
{
	return 0;
}