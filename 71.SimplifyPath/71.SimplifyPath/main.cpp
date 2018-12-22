#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
	public:
	string simplifyPath(string path)
	{
		stack<string> pathStack;
		for ( int i = 0; i < path.size(); )
		{
			while ( path[i] == '/' && i < path.size() )
				i++;
			string pathStr = "";
			while ( path[i] != '/' && i < path.size() )
				pathStr += path[i++];
			if ( pathStr == ".." && !pathStack.empty() )
				pathStack.pop();
			else if ( pathStr != "." && pathStr != ".." && pathStr != "" )
				pathStack.push(pathStr);
		}
		string result = "";
		while ( !pathStack.empty() )
		{
			string p = pathStack.top();
			pathStack.pop();
			result = "/" + p + result;
		}
		if ( result.empty() )
			result = "/";
		return result;
	}
};

int main()
{
	return 0;
}