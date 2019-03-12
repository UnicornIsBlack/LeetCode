#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int bulbSwitch(int n)
	{
		int bulb = 0;
		for ( int i = 1; i*i <= n; i++ )
			bulb++;
		return bulb;
	}
};

int main()
{
	return 0;
}