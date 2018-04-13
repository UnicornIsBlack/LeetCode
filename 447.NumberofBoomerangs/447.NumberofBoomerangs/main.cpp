#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double distance(int* a, int* b, int pointsColSize)
{
	double s = 0;
	double sum = 0;
	int sub = 0;
	for ( int i = 0; i < pointsColSize; i++ )
	{
		sub = a[i] - b[i];
		sum += sub * sub;
	}
	s = sqrt(sum);
	return s;
}
//int numberOfBoomerangs(int** points, int pointsRowSize, int pointsColSize)
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	int count = 0;
//	double distanceIJ;
//	double distanceIK;
//	for ( i = 0; i < pointsRowSize;i++ )
//	{
//		for ( j = 0; j < pointsRowSize; j++ )
//		{
//			if ( j == i )
//				continue;
//			for ( k = 0; k < pointsRowSize; k++ )
//			{
//				if ( k == i || k == j )
//					continue;
//				distanceIJ = distance(points[i], points[j], pointsColSize);
//				distanceIK = distance(points[i], points[k], pointsColSize);
//				if ( distanceIJ == distanceIK )
//					count++;
//			}
//		}
//	}
//	return count;
//}
double* distanceArray(int** points, int pointsRowSize, int pointsColSize, int index)
{
	double* distanceA = (double*)malloc(pointsRowSize*sizeof(double));
	for ( int i = 0; i < pointsRowSize; i++ )
	{
		distanceA[i] = distance(points[index], points[i], pointsColSize);
	}
	return distanceA;
}
int countBoom(double* disArray, int pointsRowSize)
{
	int count = 0;
	for ( int i = 0; i < pointsRowSize; i++ )
	{
		for ( int j = i + 1; j < pointsRowSize; j++ )
		{
			if ( disArray[i] == disArray[j] )
				count++;
		}
	}
	return count;
}
int numberOfBoomerangs(int** points, int pointsRowSize, int pointsColSize)
{
	double* disArray;
	int count = 0;
	for ( int i = 0; i < pointsRowSize; i++ )
	{
		disArray = distanceArray(points, pointsRowSize, pointsColSize, i);
		count += countBoom(disArray, pointsRowSize);
		free(disArray);
	}
	return count * 2;	
}

int main()
{
	return 0;
}