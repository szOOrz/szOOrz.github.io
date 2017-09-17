#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
/*
首先，我们清楚一个事实，就是假如整个序列，可以最多分成a部分（连续），每一部分，都包含1~k（如果末尾有些不包含，那就舍去），那么，长度为a的所有都是可行的。比如说1，2，……，k-1，k 3，4，……k-1，k， 1,2，3,4……k-1，k只能分为2部分，一部分是前面1~k，第二部分是3~2，最后一部分，显然是多余的，不能算a 那么这个2就是答案。对于本题，我们的做法是，一个一个读进来，如果1~k都读到了，tot加一，然后再重新读……一直读到结束，最后输出tot+1 
*/
int n,k,tot,temp,x;
bool flag[10005];
int main()
{
	scanf("%d%d",&n,&k);
	temp=k;
	memset(flag,true,sizeof(flag));
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if (flag[x])
		{
			temp--;
			flag[x]=false;
			if (temp==0)
			{
				temp=k;
				tot++;
				memset(flag,true,sizeof(flag));
			}
		}
	}
	printf("%d",tot+1);
}
