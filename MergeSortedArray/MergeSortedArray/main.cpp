#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* nums1, int m, int* nums2, int n)
{
	int i = m - 1;
	int j = n - 1;
	int s = m + n - 1;

	while ( i >= 0 && j >= 0 )
	{
		if ( nums1[i] > nums2[j] )
		{
			nums1[s] = nums1[i];
			i--;
		}
		else
		{
			nums1[s] = nums2[j];
			j--;
		}
		s--;
	}
	while ( j >= 0 )
	{
		nums1[s] = nums2[j];
		s--;
		j--;
	}

}

int main()
{
	int nums1[9] = {  };
	int m = 0;
	int nums2[1] = {  };
	int n = 0;
	merge(nums1, m, nums2, n);
	for ( int i = 0; i < n + m; i++ )
	{
		printf("%d ", nums1[i]);
	}
	printf("\n");
	return 0;
}