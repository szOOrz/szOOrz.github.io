/*
ID:cqz15311
PROG:holstein
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
int need[30],n[20][30],val[30];
int ans1,ans2,V,G,k,t,qx[40000],front,rear;
bool find,mark[40000];
void push(int x)
{
//	printf("%d\n",x);
	if (mark[x]) return ;
	
	
	memset(val,0,sizeof(val));
	for (int i=1;i<=G;i++)
	{
		if (x & (1 << (i-1))) 
		for (int j=1;j<=V;j++)
		{
			val[j]+=n[i][j];
		}
	}
	find=true;
	for (int j=1;j<=V;j++) 
	{
		if (need[j]>val[j]) find=false;
	}
	if (find)
	{
		ans1=0;
		for (int i=1;i<=G;i++)
		{
			if (x & (1<<(i-1))) ans1++;
		}
		printf("%d",ans1);
		for (int i=1;i<=G;i++)
		{
			if (x & (1<<(i-1))) printf(" %d",i);
		}
		puts("");
	}
	
	qx[rear++]=x;
	mark[x]=true;
}
int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	scanf("%d",&V);
	for (int i=1;i<=V;i++) scanf("%d",&need[i]);
	scanf("%d",&G);
	for (int i=1;i<=G;i++)
		for (int j=1;j<=V;j++) scanf("%d",&n[i][j]);
	memset(mark,false,sizeof(mark));
	push(0); 
	while (front<rear)
	{
		int xx=qx[front++];
		for (int i=1;i<=G;i++)
		{
			push(xx | (1<< (i-1)));
			if (find) break;
		}
		if (find) break;
	}
	return 0;
} 
