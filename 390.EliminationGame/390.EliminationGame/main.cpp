#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int lastRemaining(int n)
	{
		return n == 1 ? 1 : 2 * (n / 2 + 1 - lastRemaining(n / 2));
	}
};

int main()
{
	return 0;
}