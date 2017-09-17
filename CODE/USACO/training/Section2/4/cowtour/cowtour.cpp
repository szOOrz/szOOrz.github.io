/*
ID:cqz15311
LANG:C++
PROG:cowtour
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
char ch;
int n,x[155],y[155];
double dist[155][155],ZJ[155],z[3],maxs[155],ans;
int father[155],cntz;
int getfather(int x)
{
	if (father[x]==x) return x;
	father[x]=getfather(father[x]);
	return father[x];
}
double calc(int a,int b)
{
	double X=x[a]-x[b];
	double Y=y[a]-y[b];
	return sqrt(X*X+Y*Y);
}
int main()
{
	freopen("cowtour.in","r",stdin);
	freopen("cowtour.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	memset(dist,0x7F,sizeof(dist));
	for (int i=1;i<=n;i++) father[i]=i;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			ch=getchar();
			while ((ch!='0') && (ch!='1')) ch=getchar();
			if (ch=='1'){
						dist[i][j]=calc(i,j);
						father[getfather(i)]=getfather(j);
			}
		}
		dist[i][i]=0;
	}
	//init
	for (int k=1;k<=n;k++){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
	//floyd
	for (int i=1;i<=n;i++)
	{
		maxs[i]=-1;
		for (int j=1;j<=n;j++)
		{
			if (dist[i][j]>5000000) continue;
			maxs[i]=max(maxs[i],dist[i][j]);
		}
//		printf("%d %.5lf\n",i,maxs[i]);
	}
	//get_maxs
	memset(ZJ,0,sizeof(ZJ));
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (dist[i][j]>5000000) continue;
			if(getfather(i)==getfather(j))
			{
				ZJ[getfather(i)]=max(ZJ[getfather(i)],dist[i][j]);
			}
		}
	}
	cntz=0;
	for (int i=1;i<=n;i++)
	{
		if (ZJ[i]!=0)
		{
			z[++cntz]=ZJ[i];
		}
	}
	//printf("%.3lf %.3lf\n",z[1],z[2]);
//	ans=max(z[1],z[2]);
	ans=5000000;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (getfather(i)!=getfather(j))
			{
				ans=min(ans,maxs[i]+maxs[j]+calc(i,j));
			}
		}
	}
	if (ans<z[1]) ans=z[1];
	if (ans<z[2]) ans=z[2];
	/*这两排一定要！*/ 
	printf("%.6lf\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
