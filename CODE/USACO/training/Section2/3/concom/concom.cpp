/*
ID:cqz15311
PROG:concom
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using std::min;
using std::max;
int n,m,a,b,c,f[105][105];
bool vis[105];
void dfs(int s,int x){
	vis[x]=true;
	for (int y=1;y<=n;y++)
	if (!vis[y])
	{
		if (x!=s) f[s][y]+=f[x][y];
		if (f[s][y]>50) dfs(s,y);
	}
}
int main()
{
	freopen("concom.in","r",stdin);
	freopen("concom.out","w",stdout);
	scanf("%d",&m);
	n=0;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		f[a][b]=c;
		n=max(n,a);n=max(n,b);
	}
	for (int i=1;i<=n;i++){
		memset(vis,false,sizeof(vis));
		dfs(i,i); 
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j)
				if (f[i][j]>50) printf("%d %d\n",i,j);
	fclose(stdin);
	fclose(stdout);
}
/*

        Here are the respective outputs:
        ----- our output ---------
        2_3
        2_4
        2_5
        3_4
        3_5
        4_5
        ---- your output ---------
        1_3
        1_4
        1_5
        2_3
        2_4
        2_5
        3_4
        3_5
        4_3
        4_4
        4_5
        5_4
        5_5
        --------------------------

        ------ Data for Run 3 [length=44 bytes] ------
        6 
        1 2 30 
        2 3 52 
        3 4 51 
        4 5 70 
        5 4 20 
        4 3 20 
        --------------------------
        
*/
