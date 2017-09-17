//定义一个符号‘*’， A*B等于一个取自A、一个取自B的所有数字对的乘积的和。计算A*B。 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
int m,t,u,f,d;
char ch; 
int ans;
int main()
{
	scanf("%d%d%d%d%d",&m,&t,&u,&f,&d);
	getchar();
	ans=0;
	for (int i=0;i<t;i++)
	{
		scanf("%c",&ch);
		getchar();
		if (ch=='u')
			ans=ans+u+d;
		else
		if (ch=='f')
			ans=ans+f*2;
		else
		if (ch=='d')
			ans=ans+d+u;
		if (ans > m)
		{
			printf("%d",i);
			return 0;
		}
	}
	printf("%d",t);
	return 0;
}
