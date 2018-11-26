#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	vector<int> diStringMatch(string S)
	{
		vector<int> result;
		for ( int i = 0; i <= S.size(); i++ )
		{
			result.push_back(i);
		}
		for ( int i = 1; i < result.size(); i++ )
		{
			if ( S[i - 1] == 'D' )
			{
				int num = howMachD(S, i - 1);
				exangeArr(result, i - 1, num + 1);
				i += (num - 1);
			}
		}
		return result;
	}

	int howMachD(string S, int index)
	{
		int num = 0;
		for ( int i = index; i < S.size(); i++ )
		{
			if ( S[i] != 'D' )
				break;
			num++;
		}
		return num;
	}
	void exangeArr(vector<int>& arr, int start, int num)
	{
		int end = start + num - 1;
		for ( int i = 0; i < num / 2; i++ )
		{
			int tmp = arr[start + i];
			arr[start + i] = arr[end - i];
			arr[end - i] = tmp;
		}
	}
};

int main()
{
	return 0;
}