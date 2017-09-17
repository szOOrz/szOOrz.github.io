#include<bits/stdc++.h>
using namespace std;
int a[105][105],t[10005],r[10005],c[10005],x[10005];
int n,m,q;
void solve1(int r){
	int tmp = a[r][m];
	for (int i=m;i>=2;i--){
		a[r][i] = a[r][i-1];
	}
	a[r][1] = tmp;
}
void solve2(int c){
	int tmp = a[n][c];
	for (int i=n;i>=2;i--){
		a[i][c] = a[i-1][c];
	}
	a[1][c] = tmp;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=q;i++){
		scanf("%d",&t[i]);
		if (t[i] == 1) scanf("%d",&r[i]);
		if (t[i] == 2) scanf("%d",&c[i]);
		if (t[i] == 3) scanf("%d%d%d",&r[i],&c[i],&x[i]);
	}
	memset(a,0,sizeof(a));
	for (int i=q;i>=1;i--){
		if (t[i] == 1)solve1(r[i]); else
		if (t[i] == 2)solve2(c[i]); else
		a[r[i]][c[i]] = x[i];
	}
	for (int j=1;j<=n;j++) {
		for (int k=1;k<=m;k++)
			printf("%d ",a[j][k]);
		puts("");
	}
	puts("");
	return 0;
}
