#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> shortestToChar(string S, char C)
	{
		vector<int> distance(S.size(), -1);
		for ( int i = 0; i < S.size(); i++ )
		{
			if ( S[i] == C )
			{
				distance[i] = 0;
				int dis = 0;
				for ( int j = i - 1; j >= 0; j-- )
				{
					dis++;
					if ( distance[j] == 0 || (distance[j] != -1 && distance[j] < dis) )
						break;
					else
						distance[j] = dis;
				}
				dis = 0;
				int j = i + 1;
				for ( j = i + 1; j < S.size(); j++ )
				{
					dis++;
					if ( S[j] == C )
						break;
					else
						distance[j] = dis;
				}
				i = j - 1;
			}
		}
		return distance;
	}
};

int main()
{
	return 0;
}