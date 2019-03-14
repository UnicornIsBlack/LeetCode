#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool isValidSerialization(string preorder)
	{
		vector<string> nodes;
		int start = 0;
		for ( int i = 0; i < preorder.size(); i++ )
		{
			if ( preorder[i] == ',' )
			{
				string node = preorder.substr(start, i - start);
				start = i + 1;
				nodes.push_back(node);
			}
			if ( i == preorder.size() - 1 )
			{
				string node = preorder.substr(start, i - start + 1);
				nodes.push_back(node);
			}
		}
		int index = 0;
		for ( int i = 0; i < nodes.size(); i++ )
		{
			if ( i > index )
				return false;
			if ( nodes[i] == "#" )
				continue;
			index += 2;
			if ( index >= nodes.size() )
				return false;
		}
		if ( index != nodes.size() - 1 )
			return false;
		return true;
	}
};

int main()
{
	return 0;
}