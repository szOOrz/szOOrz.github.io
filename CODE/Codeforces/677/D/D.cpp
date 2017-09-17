#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 303;
int tree[4][maxn][maxn];
int n,m,p,dp[maxn*maxn],Ans;
struct A{
	int x,r,c;
	bool operator <(const A &y) const{
		return x < y.x;
	}
}a[maxn*maxn]; 
#define lowbit(x) ((x & (-x)))
const int kx[4] = {-1,-1, 1,1};
const int ky[4] = {-1, 1,-1,1};
int find(int tree[maxn][maxn],int x,int y){
	x++;y++;
	int Ans = 0x3fffffff;
	for (;x>0;x-=lowbit(x)){
		for (int yy=y;yy>0;yy-=lowbit(yy)){
			Ans = min(Ans,tree[x][yy]);
		}
	}
//	printf("%d %d\n",x,y,)
	return Ans;
}
void Del(int tree[maxn][maxn],int x,int y){
	x++;y++;
	for (;x<=n;x+=lowbit(x)){
		for (int yy=y;yy<=m;yy+=lowbit(yy)){
			tree[x][yy] = 0x3fffffff;
		}
	}
}
void update(int tree[maxn][maxn],int x,int y,int val){
	x++;y++;
	for (;x<=n;x+=lowbit(x)){
		for (int yy=y;yy<=m;yy+=lowbit(yy)){
			tree[x][yy] = min(tree[x][yy],val);
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&p);
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			int x;
			scanf("%d",&x);
			a[i*m+j] . x = x;
			a[i*m+j] . r = i;
			a[i*m+j] . c = j;
		}
	}
	/*
	0是左上 x + y - find(x) - find(y)
	1是右上，x是大的，y是小的
	x - find(x) + find(y) - y
	x - y  
	2是左下 
	*/
	memset(tree,0x3f,sizeof(tree));
	memset(dp,0x3f,sizeof(dp));
	sort(a,a+n*m);
	
	int l = 0,r = 0,pre;
	while (a[l].x == a[r].x) r++;
	for (int i=l;i<r;i++) dp[i] = (a[i].r + a[i].c);
	for (int i=l;i<r;i++){
		update(tree[0],a[i].r	  ,a[i].c		,-(a[i].r)		-(a[i].c)		+dp[i]);
		update(tree[1],a[i].r	  ,m-a[i].c-1	,-(a[i].r)		-(m-a[i].c-1) +dp[i]);
		update(tree[2],n-a[i].r-1 ,a[i].c		,-(n-a[i].r-1)	-(a[i].c)		+dp[i]);
		update(tree[3],n-a[i].r-1 ,m-a[i].c-1	,-(n-a[i].r-1)	-(m-a[i].c-1) +dp[i]);
	}
	pre = 0;
	for (l=r;l<n*m;l=r){
		while (r<n*m && a[l].x == a[r].x) r++;
		for (int i=l;i<r;i++){
			dp[i] = min(dp[i],a[i].r		+(a[i].c)		+find(tree[0],a[i].r,a[i].c));
			dp[i] = min(dp[i],a[i].r		+((m-a[i].c-1))	+find(tree[1],a[i].r,m-a[i].c-1));
			dp[i] = min(dp[i],(n-a[i].r-1)	+(a[i].c)		+find(tree[2],n-a[i].r-1,a[i].c));
			dp[i] = min(dp[i],(n-a[i].r-1)	+((m-a[i].c-1))	+find(tree[3],n-a[i].r-1,m-a[i].c-1));
//			puts("");
		}
		for (int i=pre;i<l;i++){
			Del(tree[0],a[i].r		,a[i].c		);
			Del(tree[1],a[i].r		,m-a[i].c-1	);
			Del(tree[2],n-a[i].r-1	,a[i].c		);
			Del(tree[3],n-a[i].r-1	,m-a[i].c-1	);
		}
		for (int i=l;i<r;i++){
			update(tree[0],a[i].r	  ,a[i].c		,-(a[i].r)		-(a[i].c)		+dp[i]);
			update(tree[1],a[i].r	  ,m-a[i].c-1	,-(a[i].r)		-(m-a[i].c-1)  +dp[i]);
			update(tree[2],n-a[i].r-1 ,a[i].c		,-(n-a[i].r-1)   -(a[i].c)		+dp[i]);
			update(tree[3],n-a[i].r-1 ,m-a[i].c-1	,-(n-a[i].r-1)   -(m-a[i].c-1)	+dp[i]);
		}
		pre = l;
/*		printf("(%d,%d\n",l,r-1);
		for (int i=0;i<n;i++) {
			for (int j=0;j<m;j++){
				printf("%15d",find(tree[1],a[i].r,m-a[j].c-1));
			}
			puts("");
		}
*/	}
	Ans = 0x3fffffff;
	for (int i=0;i<n*m;i++){
		if (a[i].x==p) Ans = min(Ans,dp[i]);
//		printf("(%d,%d):%d\n",a[i].r,a[i].c,dp[i]);
	}
	printf("%d\n",Ans);
}
