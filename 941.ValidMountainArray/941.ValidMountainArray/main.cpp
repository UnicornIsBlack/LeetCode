#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool validMountainArray(vector<int>& A)
	{
		bool flag = false;
		if ( A.size() < 3 )
			return false;
		int index = 0;
		for ( int i = 1; i < A.size(); i++ )
		{
			if ( A[i - 1] >= A[i] )
			{
				index = i - 1;
				break;
			}
		}
		if ( index == 0 )
			return false;
		else
		{
			if ( isDecrement(A, index) )
				flag = true;
		}
		return flag;
	}
	bool isDecrement(vector<int>& arr, int index)
	{
		bool flag = true;
		for ( int i = index + 1; i < arr.size(); i++ )
		{
			if ( arr[i - 1] <= arr[i] )
			{
				flag = false;
				break;
			}
		}
		return flag;
	}
};

int main()
{
	return 0;
}