#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prevToNext(char* prev, char* next)
{

	int pLen = strlen(prev);
	int j = 0;
	int count = 0;
	char num = prev[0];
	for ( int i = 0; i < pLen; i++ )
	{
		if ( num == prev[i] )
		{
			count++;
		}
		else
		{
			next[j] = count + '0';
			next[j + 1] = num;
			next[j + 2] = '\0';
			j += 2;
			num = prev[i];
			count = 1;
		}

		if ( i == pLen - 1 )
		{
			next[j] = count + '0';
			next[j + 1] = num;
			next[j + 2] = '\0';
		}
	}
}
char* countAndSay(int n)
{
	char *prev = (char*)malloc(sizeof(char)* 10000);
	char *next = (char*)malloc(sizeof(char)* 10000);

	if ( n == 1 )
		return "1";

	next[0] = '1';
	next[1] = '\0';

	for ( int i = 1; i < n; i++ )
	{
		int nLen = strlen(next);
		for ( int j = 0; j <= nLen; j++ )
		{
			prev[j] = next[j];
		}
		prevToNext(prev, next);
	}
	return next;
}

int main()
{
	int n = 7;
	char* p = countAndSay(n);
	printf("%s\n", p);
	return 0;
}

/*
#define maxn 10005
char s[maxn], t[maxn];

char* countAndSay(int n) {


strcpy(s, "1");
strcpy(t, "");
int cnt = 1;
char tmp[3];
for(int i = 2;i <= n;i++){
int len = strlen(s);
for(int j = 0;j < len;j++){
if(s[j] == s[j + 1]){
cnt++;
}else {
tmp[0] = cnt + '0';
tmp[1] = s[j];
tmp[2] = '\0';
strcat(t, tmp);
cnt = 1;
}
}
strcpy(s, t);
strcpy(t, "");
}

return s;
}
*/