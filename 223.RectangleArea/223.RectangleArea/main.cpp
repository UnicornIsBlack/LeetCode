#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		int area1 = abs(D - B)*abs(C - A);
		int area2 = abs(G - E)*abs(H - F);

		int overlapArea = overlap(A, B, C, D, E, F, G, H);

		return area1 - overlapArea + area2;
	}
	int overlap(int A, int B, int C, int D, int E, int F, int G, int H)
	{
		long w1 = max(A, E);
		long w2 = min(C, G);
		long w = w2 - w1;

		long h1 = max(B, F);
		long h2 = min(D, H);
		long h = h2 - h1;

		if ( w <= 0 || h <= 0 )
			return 0;
		return w*h;
	}
};

int main()
{
	return 0;
}