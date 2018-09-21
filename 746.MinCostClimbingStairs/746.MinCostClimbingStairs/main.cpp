#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int minCostClimbingStairs(vector<int>& cost)
	{
		if ( cost.size() < 2 )
			return 0;
		if ( cost.size() == 2 )
			return min(cost[0], cost[1]);
		cost.push_back(0);
		vector<int> minCost(cost.size(), 0);
		minCost[0] = cost[0];
		minCost[1] = cost[1];
		for ( int i = 2; i < cost.size(); i++ )
		{
			minCost[i] = min(minCost[i - 1], minCost[i - 2]) + cost[i];
		}
		return minCost[cost.size() - 1];
	}
};

int main()
{
	return 0;
}