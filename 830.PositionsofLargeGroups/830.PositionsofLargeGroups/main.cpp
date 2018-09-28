#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<vector<int>> largeGroupPositions(string S)
	{
		int begin = 0;
		int end = 0;
		vector<vector<int>> indexs;
		for ( int i = 0; i < S.size(); i++ )
		{
			if ( S[i] == S[begin] )
				end = i;
			else
			{
				if ( end - begin >= 2 )
				{
					vector<int> index;
					index.push_back(begin);
					index.push_back(end);
					indexs.push_back(index);
				}
				begin = i;
				end = i;
			}
			if ( i == S.size() - 1 && end - begin >= 2 )
			{
				vector<int> index;
				index.push_back(begin);
				index.push_back(end);
				indexs.push_back(index);
			}
		}
		return indexs;
	}
};

int main()
{
	return 0;
}