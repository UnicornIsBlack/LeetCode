#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s)
{
	int len = strlen(s);

	char* stack = (char*)malloc(sizeof(char)*(len / 2 + 1));
	*stack = '#';
	bool flag = false;

	for ( int i = 0; i < len; i++ )
	{
		switch ( s[i] )
		{
			case '(':
			case '[':
			case '{':
				stack++;
				*stack = s[i];
				break;
			case ')':
				if ( *stack != '(' )
					return false;
				else
					stack--;
				break;			
			case ']':
				if ( *stack != '[' )
					return false;
				else
					stack--;
				break;
			case '}':
				if ( *stack != '{' )
					return false;
				else
					stack--;
				break;
		}
	}
	if ( *stack == '#' )
		flag = true;

	return flag;
}

int main()
{

	char* s = "((((()))()[]())]";
	bool flag = isValid(s);
	printf("%d\n", flag);
	return 0;
}