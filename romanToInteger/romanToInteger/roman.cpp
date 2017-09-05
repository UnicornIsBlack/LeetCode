#include <stdio.h>
#include <Windows.h>

int romanToInt(char* s)//别人写的函数，需要学习
{
	int num = 0, temp = 0;
	while ( *s )
	{
		switch ( *s )
		{
			case 'I':num += 1; temp = 1; break;
			case 'V':num += temp == 1 ? 3 : 5; break;
			case 'X':num += temp == 1 ? 8 : 10; temp = 10; break;
			case 'L':num += temp == 10 ? 30 : 50; break;
			case 'C':num += temp == 10 ? 80 : 100; temp = 100; break;
			case 'D':num += temp == 100 ? 300 : 500; break;
			case 'M':num += temp == 100 ? 800 : 1000; break;
		}
		s++;
	}
	return num;
}

int main()
{
	char c = 0;
	char s[13] = { 0 };
	if ( (c = getchar()) == '"' )
	{
		int i = 0;
		while ( (c = getchar()) != '"' )
		{
			s[i] = c;
			i++;
		}
		s[i] = '\0';
	}
	int num = romanToInt(s);

	printf("%d\n", num);
	return 0;
}