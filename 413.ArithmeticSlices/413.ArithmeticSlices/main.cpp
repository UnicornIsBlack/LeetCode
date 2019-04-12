#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int numberOfArithmeticSlices(vector<int>& A)
	{
		if ( A.size() < 3 )
			return 0;
		map<pair<int, int>, int> pairMap;
		for ( int i = 0; i < A.size() - 2; i++ )
		{
			if ( A[i + 2] - A[i + 1] == A[i + 1] - A[i] )
				pairMap[make_pair(i, i + 2)] = A[i + 1] - A[i];
		}
		int res = 0;
		for ( int i = 0; i < A.size() - 2; i++ )
		{
			map<pair<int, int>, int>::iterator it = pairMap.find(make_pair(i, i + 2));
			if ( it == pairMap.end() )
				continue;
			int end = i + 2;
			for ( int j = 3; j < A.size(); j++ )
			{
				map<pair<int, int>, int>::iterator it2 = pairMap.find(make_pair(j - 2, j));
				if ( it2 == pairMap.end() )
					break;
				
				if ( it2->second != it->second )
					break;
				res++;
			}
		}
		return res;
	}
};

int main()
{
	return 0;
}