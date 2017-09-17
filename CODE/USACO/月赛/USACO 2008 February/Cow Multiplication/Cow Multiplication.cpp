//定义一个符号‘*’， A*B等于一个取自A、一个取自B的所有数字对的乘积的和。计算A*B。 

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
