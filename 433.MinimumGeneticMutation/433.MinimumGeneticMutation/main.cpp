#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int minMutation(string start, string end, vector<string>& bank)
	{

		queue<pair<string, int>> q;
		set<string> strSet;
		q.push(make_pair(start, 0));
		strSet.insert(start);
		int res = -1;
		while ( !q.empty() )
		{
			pair<string, int> front = q.front();
			q.pop();
			string str = front.first;
			int count = front.second;
			if ( compareStr(str, end) == 0 )
			{
				res = count;
				break;
			}
			for ( int i = 0; i < bank.size(); i++ )
			{
				if ( strSet.find(bank[i]) != strSet.end() )
					continue;
				if ( compareStr(str, bank[i]) == 1 )
				{
					q.push(make_pair(bank[i], count + 1));
					strSet.insert(bank[i]);
				}
			}
		}
		return res;
	}

	int compareStr(string a, string b)
	{
		int res = 0;
		for ( int i = 0; i < a.size(); i++ )
		{
			if ( a[i] != b[i] )
				res++;
		}
		return res;
	}
};

int main()
{
	return 0;
}