#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int lengthLongestPath(string input)
	{
		input += '\n';
		int res = 0, spaceCount = 0, curPathLen = 0, len = input.size();
		bool dotFlag = false;
		stack<pair<string, int>> st;
		string curDir, extension;
		for ( int i = 0; i < len; i++ )
		{
			if ( input[i] != '\n' )
			{
				if ( input[i] != '\t' )
					curDir += input[i];
				if ( dotFlag )
					extension += input[i];
				if ( input[i] == '\t' )
					spaceCount++;
				if ( input[i] == '.' )
					dotFlag = true;
				continue;
			}

			while ( !st.empty() && spaceCount <= st.top().second )
			{
				curPathLen -= st.top().first.size();
				st.pop();
			}
			if ( dotFlag )
				res = max(curPathLen + (int)curDir.size() + 1, res);
			else
			{
				st.push(make_pair("/" + curDir, spaceCount));
				curPathLen += curDir.size() + 1;
			}
			extension = "";
			dotFlag = false;
			spaceCount = 0;
			curDir = "";
		}
		return res == 0 ? 0 : res - 1;
	}
};

int main()
{
	return 0;
}