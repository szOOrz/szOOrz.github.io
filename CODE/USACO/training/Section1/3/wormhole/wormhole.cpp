/*
ID:cqz15311
PROG:wormhole
LANG:C++
*/
#include<cstdio>
#include<cmath>
#include<cstring>
int x[13],y[13],next_right[13],n,f[13],ans,mark[13],now;
bool check()
{

	//for (int i=1;i<=n;i++) printf("%d ",f[i]);
		//±©Á¦ÅÐ»·
	for (int i=1;i<=n;i++)
	{
		memset(mark,0,sizeof(mark));
		bool cs=false;
		now=i;
		mark[now]=true; 
		while (1)
		{
		//	printf("%d %d %d\n",cs,now,next_right[now]);
	//		printf("%d-%c->",now,cs+95);
			if (!cs)
			{
				now=next_right[now];
			}
			else
			{
				now=f[now];
				if (mark[now]) return true;
				mark[now]=true;
			} 
			if (now==0) break;
			cs=!cs;
		}
	//	puts("");
	}
	//printf("^^^^"); 
	return false;
}
void dfs(int x,int be)
{
	//puts("");
	//printf("%d %d\n",x,be);
	if (x==((n >> 1)+1))
	{
		if (check()) ans++;
		return ;
	}
	for (int i=be+1;i<=n/*-x+1*/;i++)
	{
		if (!f[i])
		{
			for (int j=i+1;j<=n;j++) 
			{
				if (!f[j])
				{
					f[i]=j;
					f[j]=i;
					dfs(x+1,i); 
					f[i]=0;
					f[j]=0;
				}
			}
		}
	}
}
void solve()
{
	memset(f,0,sizeof(f));
	dfs(1,0);
}
int main() 
{
	freopen("wormhole.in","r",stdin);
	freopen("wormhole.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	for (int i=1;i<=n;i++)
	{
		next_right[i]=0;
		for (int j=1;j<=n;j++)
		{
			if ((y[i]==y[j]) && (x[j]>x[i]))
			{
				if (next_right[i]==0) next_right[i]=j; else
				if (x[j]<x[next_right[i]]) next_right[i]=j;
			}
		}
	}
	//for (int i=1;i<=n;i++) printf("%d %d\n",i,next_right[i]);
	solve();
	printf("%d\n",ans);
	return 0;
}
/*
USER: Jack Chen [cqz15311]
TASK: wormhole
LANG: C++

Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.000 secs, 4188 KB]
   Test 2: TEST OK [0.000 secs, 4188 KB]
   Test 3: TEST OK [0.000 secs, 4188 KB]
   Test 4: TEST OK [0.000 secs, 4188 KB]
   Test 5: TEST OK [0.000 secs, 4188 KB]
   Test 6: TEST OK [0.000 secs, 4188 KB]
   Test 7: TEST OK [0.011 secs, 4188 KB]
   Test 8: TEST OK [0.011 secs, 4188 KB]
   Test 9: TEST OK [0.011 secs, 4188 KB]
   Test 10: TEST OK [0.011 secs, 4188 KB]

All tests OK.
Your program ('wormhole') produced all correct answers!  This is your
submission #2 for this problem.  Congratulations!
*/
