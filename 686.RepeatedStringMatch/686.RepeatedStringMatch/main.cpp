#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution
{
	public:
	int repeatedStringMatch(string A, string B)
	{
		string str;
		int count = 0;
		while ( str.size() < B.size() )
		{
			count++;
			str.append(A);
		}

		if ( str.find(B) != -1 )
			return count;

		str.append(A);
		if ( str.find(B) != -1 )
			return count + 1;
		return -1;
	}
};


int main()
{
	return 0;
}