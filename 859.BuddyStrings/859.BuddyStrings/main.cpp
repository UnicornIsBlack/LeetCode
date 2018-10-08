#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
	public:
	bool buddyStrings(string A, string B)
	{
		if ( A.size() != B.size() )
			return false;
		vector<int> index;
		set<char> strSet;
		set<char>::iterator it;
		for ( int i = 0; i < A.size(); i++ )
		{
			if ( A[i] != B[i] )
				index.push_back(i);
			it = strSet.find(A[i]);
			if ( it == strSet.end() )
				strSet.insert(A[i]);
		}
		if ( index.size() != 2 && index.size() != 0 )
			return false;
		else if ( index.size() == 2 )
		{
			int m = index[0];
			int n = index[1];
			if ( A[m] != B[n] || A[n] != B[m] )
				return false;
			return true;
		}
		else if ( index.size() == 0 )
		{
			if ( strSet.size() < A.size() )
				return true;
		}
		return false;
	}
};

int main()
{
	return 0;
}