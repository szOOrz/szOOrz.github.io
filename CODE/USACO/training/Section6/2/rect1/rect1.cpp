/*
ID:cqz15311
PROB:rect1
LANG:C++
*/
#include<cstdio> 
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
int L[1005],D[1005],R[1005],U[1005],c[1005];
int Ans[2550],n,A,B;
void solve(int i,int c,int l,int d,int r,int u){
//	printf("%d %d %d %d %d\n",c,r,l,u,d);
	while (i<=n && ((r <= L[i] || l >= R[i] || u <= D[i] || d >= U[i]))) i++;
	if (i == n+1){
		Ans[c]+=(u-d)*(r-l);
		return ;
	}
	if (L[i] >= l) solve(i+1,c,l,d,L[i],u),l = L[i];
	if (R[i] <= r) solve(i+1,c,R[i],d,r,u),r = R[i];
	if (U[i] <= u) solve(i+1,c,l,U[i],r,u),u = U[i];
	if (D[i] >= d) solve(i+1,c,l,d,r,D[i]),d = D[i];
}

int main(){
	freopen("rect1.in","r",stdin);
	freopen("rect1.out","w",stdout);
	scanf("%d%d%d",&A,&B,&n);
	L[0] = 0;//×óÏÂ½Çx 
	D[0] = 0;//×óÏÂ½Çy
	R[0] = A;
	U[0] = B; 
	c[0] = 1;
	for (int i=1;i<=n;i++){
		scanf("%d%d%d%d%d",&L[i],&D[i],&R[i],&U[i],&c[i]);
	}
	memset(Ans,0,sizeof(Ans));
	for (int i=0;i<=n;i++){
		solve(i+1,c[i],L[i],D[i],R[i],U[i]);
	}
	for (int i=0;i<=2500;i++) {
		if (Ans[i] != 0){
			printf("%d %d\n",i,Ans[i]);
		}
	}
}
