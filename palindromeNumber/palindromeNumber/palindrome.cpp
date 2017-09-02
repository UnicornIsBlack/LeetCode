#include <stdio.h>
#include <Windows.h>
#include <climits>


bool isPalindrome(int x)
{
	bool flag = false;
	const int MAX = INT_MAX;
	const int MIN = INT_MIN;
	long long y = 0;
	int t = x;
	while ( t > 0 )
	{
		y = y * 10 + t % 10;
		t = t / 10;
	}
	if ( y > MAX || y < MIN )
	{
		flag = false;
	}

	if ( y == x )
	{
		flag = true;
	}

	return flag;
}


int main()
{

	int x = 0;

	while ( scanf("%d", &x) )
	{
		printf("%d\n", isPalindrome(x));
	}
	system("pause");
	return 0;
}