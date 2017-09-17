#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 500
#define inf 0x3f3f3f3f
using namespace std;

struct Syndra
{
	int v,next;
}e[N];
int head[N],d[N],cnt,n,m,root;
void add(int u,int v)
{
	++cnt;
	e[cnt].v=v;
	e[cnt].next=head[u];
	head[u]=cnt;
	d[v]++;
}
int f[N][N],num[N],ans=inf;

void dfs(int x)
{
	int i,j,k,v,temp;
	for(i=head[x];i;i=e[i].next)
	{
		v=e[i].v;
		dfs(v);
		for(j=num[x]+num[v];j;j--)
		{
			int uplimit=min(j,num[v]);
			for(k=max(1,j-num[x]);k<=uplimit;k++)
			{
				f[x][j]=min(f[x][j],f[x][j-k]+f[v][k]);
			}
		}
		num[x]+=num[v];
	}
	f[x][++num[x]]=1;
}

int main()
{
	//freopen("test.in","r",stdin);
	//freopen("b.out","w",stdout);
	int i,j,k;
	int a,b,c;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	memset(f,0x3f,sizeof(f));
	for(i=1;i<=n;i++)
	{
		f[i][0]=0;
		if(!d[i])root=i;
	}
	dfs(root);
	for(i=1;i<=n;i++)
	{
		f[i][num[i]]=0;
		ans=min(ans,f[i][num[i]-m]+1);
		if(i!=root)f[i][n-m]++;
		ans=min(ans,f[i][n-m]);
	}
	printf("%d\n",ans);
	return 0;
}

