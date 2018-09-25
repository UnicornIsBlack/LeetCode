#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool rotateString(string A, string B)
	{
		if ( A.size() != B.size() )
			return false;
		bool flag = false;
		string C = A + A;
		string::size_type it;
		it = C.find(B);
		if ( it != string::npos )
		{
			flag = true;
		}
		return flag;
	}
};

int main()
{
	return 0;
}