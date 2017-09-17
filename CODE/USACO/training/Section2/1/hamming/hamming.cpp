/*
ID:cqz15311
PROG:hamming
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
bool find;
int val[80],_Max,N,B,D;
int dist(int a,int b)
{
	int c=a ^ b;
	int sum=0;
	while (c)
	{
		if (c & 1)sum++;
		c>>=1;
	}
//	printf("%d %d %d\n",a,b,sum); 
	return sum;
}
bool check(int n,int x)
{
	bool could=true;
	for (int i=1;i<n;i++)
	{
		if (dist(val[i],x)<D) could=false;
	}
	return could;
}
void search(int x)
{
//	printf("%d %d\n",x-1,val[x-1]);
	if (x==(N+1))
	{
		find=true;
		return ;
	}
	for (int i=0;i<_Max;i++)
	{
		if (check(x,i))
		{
			val[x]=i;
			search(x+1);
			if (find) return ;
			val[x]=-1;
		}
	}
}
int main()
{
	freopen("hamming.in","r",stdin);
	freopen("hamming.out","w",stdout);
//	printf("%d\n",check(0,6));
	find=false;
	scanf("%d%d%d",&N,&B,&D);
	_Max=1 << B;
	search(1);
	//if (find)
	for (int i=1;i<=N;i++)
	{
		if (i ==   N ) printf("%d",val[i]); else 
		if (i % 10==0) printf("%d\n",val[i]); else
		printf("%d ",val[i]);
	}
	puts("");
	return 0;
}
/*
USER: Jack Chen [cqz15311]
TASK: hamming
LANG: C++

Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.000 secs, 4184 KB]
   Test 2: TEST OK [0.000 secs, 4184 KB]
   Test 3: TEST OK [0.000 secs, 4184 KB]
   Test 4: TEST OK [0.000 secs, 4184 KB]
   Test 5: TEST OK [0.000 secs, 4184 KB]
   Test 6: TEST OK [0.000 secs, 4184 KB]
   Test 7: TEST OK [0.000 secs, 4184 KB]
   Test 8: TEST OK [0.000 secs, 4184 KB]
   Test 9: TEST OK [0.000 secs, 4184 KB]
   Test 10: TEST OK [0.000 secs, 4184 KB]
   Test 11: TEST OK [0.000 secs, 4184 KB]

All tests OK.

*/ 
