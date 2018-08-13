#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* Return an array of size *returnSize.
* Note: The returned array must be malloced, assume caller calls free().
*/
char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize)
{
	int sum = 0;
	int count = 0;
	int* index = (int*)malloc(list1Size*sizeof(int));
	for ( int sum = 0; sum < list1Size + list2Size - 1; sum++ )
	{
		for ( int i = 0; i < list1Size; i++ )
		{
			int j = sum - i;
			if ( j < 0 )
				break;
			if ( j >= list2Size )
				continue;
			if ( strcmp(list1[i], list2[j]) == 0 )
			{
				index[count] = i;
				count++;
			}
		}
		if ( count != 0 )
			break;
	}
	char** restaurants = (char**)malloc(count*sizeof(char*));
	for ( int i = 0; i < count; i++ )
	{
		int len = strlen(list1[index[i]]) + 1;
		restaurants[i] = (char*)malloc(len*sizeof(char));
		strcpy(restaurants[i], list1[index[i]]);
		restaurants[i][len - 1] = '\0';
	}
	free(index);
	(*returnSize) = count;
	return restaurants;
}

int main()
{
	return 0;
}