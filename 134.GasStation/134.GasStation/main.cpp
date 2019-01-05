#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
		if ( gas.size() == 0 || cost.size() == 0 || gas.size() != cost.size() )
			return -1;
		int len = gas.size();
		for ( int i = 0; i < len; i++ )
		{
			if ( gas[i] < cost[i] )
				continue;
			if ( isBack(gas, cost, i) )
				return i;
		}
		return -1;
	}
	bool isBack(vector<int>& gas, vector<int>& cost, int start)
	{
		int len = gas.size();
		int before = start;
		int i = start + 1;
		if ( i == len )
			i = 0;
		int tankGas = gas[start];
		while ( i != start )
		{
			if ( tankGas < cost[before] )
				return false;
			tankGas = tankGas - cost[before] + gas[i];
			i++;
			before++;
			if ( before == len )
				before = 0;
			if ( i == len )
				i = 0;
		}
		if ( tankGas < cost[before] )
			return false;
		return true;
	}
};

int main()
{
	return 0;
}