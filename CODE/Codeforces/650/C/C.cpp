#include<bits/stdc++.h> 
using namespace std;
const int maxn = 1050050;
int read(){
	int a = 0;
	char c = getchar();
	while (!((c>='0') && (c<='9'))) c= getchar();
	while (c>='0' && c<='9'){
		a =a*10+c-48;
		c = getchar();
	}
	return a;
}
int n,m,Hx[maxn],Hy[maxn],X[maxn],Y[maxn],ans[maxn];
struct H{
	int val,r,c;
	bool operator < (const H &x) const{
		return 
		   val  < x.val;/*
		|| val == x.val && r < x.r 
		|| val == x.val && r == x.r && c < x.c;*/
	}
}A[maxn];
int father[maxn];
int getfather(int x){
	if (father[x] == x) return x; else
	return father[x] = getfather(father[x]);
}
void uni(int u,int v){
	int p1 = getfather(u) ;
	int p2 = getfather(v);
	if (p1 != p2) father[p1] = p2;
}
int main(){
	n = read();m = read();
	int num = 0;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			int x = read();
			A[num] . val = x;
			A[num] . r = i;
			A[num] . c = j;
			num++;
		}
	}
	sort(A,A+n*m);
	memset(X,0,sizeof(X));
	memset(Y,0,sizeof(Y));
	memset(Hx,0,sizeof(Hx));
	memset(Hy,0,sizeof(Hy));
	for (int i=0;i<n*m;i++) father[i] = i;
	int j = -1;
	for (int i=0;i<n*m;i++){
		if (i==(n*m-1) || A[i].val != A[i+1].val){
			for (int k=j+1;k<=i;k++){
				int p = A[k].r * m + A[k].c;
				Hx[A[k].r] = p;
				Hy[A[k].c] = p;
			}
			for (int k=j+1;k<=i;k++){
				int p = A[k].r * m + A[k].c;
				uni(Hx[A[k].r],p);
				uni(Hy[A[k].c],p);
			}
			for (int k=j+1;k<=i;k++){
				int p = A[k].r * m + A[k].c;
				int pa = getfather(p);
				ans[pa] = max(ans[pa],max(X[A[k].r],Y[A[k].c])+1);
			}
			for (int k=j+1;k<=i;k++){
				int p = A[k].r * m + A[k].c;
				int pa = getfather(p);
				X[A[k].r] = max(X[A[k].r],ans[pa]);
				Y[A[k].c] = max(Y[A[k].c],ans[pa]);
			}
			j = i; 
		}
	}
	for (int i=0;i<n*m;i++){
		printf("%d ",ans[getfather(i)]);
		if (i % m == m-1) puts("");
	}
	return 0;
}
