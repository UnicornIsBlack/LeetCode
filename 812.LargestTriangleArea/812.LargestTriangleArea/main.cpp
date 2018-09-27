#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	double largestTriangleArea(vector<vector<int>>& points)
	{
		double area = 0;
		for ( int i = 0; i < points.size(); i++ )
		{
			for ( int j = i + 1; j < points.size(); j++ )
			{
				for ( int k = j + 1; k < points.size(); k++ )
					area = max(area, triangleArea(points[i], points[j], points[k]));
			}
		}
		return area;
	}
	double triangleArea(vector<int>& a, vector<int>& b, vector<int>& c)
	{
		int area = a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - a[1] * b[0] - b[1] * c[0] - c[1] * a[0];
		return 0.5*abs(area);
	}

};

int main()
{
	return 0;
}