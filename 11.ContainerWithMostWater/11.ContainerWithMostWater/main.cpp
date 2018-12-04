#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int maxArea(vector<int>& height)
	{
		int area = 0;
		for ( int i = 0; i < height.size(); i++ )
		{
			for ( int j = i + 1; j < height.size(); j++ )
			{
				int weight = j - i;
				int minHeight = min(height[i], height[j]);
				area = max(area, weight*minHeight);
			}
		}
		return area;
	}
};

int main()
{
	return 0;
}