#include <stdio.h>
#include <Windows.h>
#include <climits>



int reverse(int x)
{

	const int MAX = INT_MAX;
	const int MIN = INT_MIN;
	int flag = 1;
	if ( x < 0 )
	{
		flag = -1;
		x *= -1;
	}

	long long y = 0;
	while ( x>0 )
	{
		y = y * 10 + x % 10;
		x = x / 10;
	}

	if ( y > MAX || y < MIN )
	{
		return 0;
	}


	return y*flag;
}

int main()
{

	int x = 0;
	while ( scanf("%d", &x) )
	{

		int y = reverse(x);
		printf("%d to %d\n", x, y);
	}

	system("pause");
	return 0;
}

/*
class Solution {
public:
int reverse(int x) {
int res = 0;
while (x != 0) {
if (abs(res) > INT_MAX / 10) return 0;
res = res * 10 + x % 10;
x /= 10;
}
return res;
}
};


class Solution {
public:
int reverse(int x) {
long long res = 0;
while (x != 0) {
res = 10 * res + x % 10;
x /= 10;
}
return (res > INT_MAX || res < INT_MIN) ? 0 : res;
}
};
*/