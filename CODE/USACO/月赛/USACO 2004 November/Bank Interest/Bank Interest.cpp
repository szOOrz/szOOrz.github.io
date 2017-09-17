#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>

int r,m,y;
double ans;
int main()
{
	scanf("%d %d %d",&r,&m,&y);
	ans=m;
	for (int i=1;i<=y;i++)
	{
		ans=(ans*(100+r)) / 100;
	}
	printf("%d",int(ans));
} 
 
