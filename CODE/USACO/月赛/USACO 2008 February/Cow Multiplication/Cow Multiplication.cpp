//����һ�����š�*���� A*B����һ��ȡ��A��һ��ȡ��B���������ֶԵĳ˻��ĺ͡�����A*B�� 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
char c;
int a=0,b=0;
int main()
{
	c=getchar();
	while (c!=' ')
	{
		a=a+(c-'0');
		c=getchar();
	}
	c=getchar();
	while (c!='\n')
	{
		b=b+(c-'0');
		c=getchar();
	}
	printf("%d",a*b);
} 
