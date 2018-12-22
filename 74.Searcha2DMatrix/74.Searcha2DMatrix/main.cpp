#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
	bool searchMatrix(vector<vector<int>>& matrix, int target)
	{
		if ( matrix.size() < 1 )
			return false;
		int low = 0;
		int high = matrix.size() - 1;
		if ( matrix[0].size() < 1 )
			return false;
		int len = matrix[0].size();
		while ( low <= high )
		{
			int mid = (low + high) / 2;
			if ( target >= matrix[mid][0] && target <= matrix[mid][len - 1] )
			{
				return searchBinary(matrix[mid], target);
			}
			else if ( target < matrix[mid][0] )
				high = mid - 1;
			else if ( target > matrix[mid][len - 1] )
				low = mid + 1;
		}
		return false;
	}
	bool searchBinary(vector<int>& arr, int target)
	{
		if ( arr.size() < 1 )
			return false;
		int low = 0;
		int high = arr.size() - 1;
		while ( low <= high )
		{
			int mid = (low + high) / 2;
			if ( target == arr[mid] )
				return true;
			else if ( target < arr[mid] )
				high = mid - 1;
			else if ( target > arr[mid] )
				low = mid + 1;
		}
		return false;
	}
};

int main()
{
	return 0;
}