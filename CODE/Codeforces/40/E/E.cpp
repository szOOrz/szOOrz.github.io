#include<bits/stdc++.h>
using namespace std;
int C[1005][1005];
int n,m,a[1005][1005],p,Ans;
void init(){
	C[0][0] = 1;
	for (int i=1;i<=1000;i++){
		C[i][0] = 1;
		for (int j=1;j<=i;j++) {
			C[i][j] = (C[i-1][j-1] + C[i-1][j]) % p;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	if ((n&1) ^ (m&1)){
		puts("0");
		return 0;
	}
	bool swaped = false; 
	if (n < m){
		swap(n,m);
		swaped = true;
	}
	int k;
	scanf("%d",&k);
	memset(a,0,sizeof(a));
	for (int i=1;i<=k;i++){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		if (swaped) swap(y,x);
		a[x][y] = v;
	}
	scanf("%d",&p);
	init();
	for (int i=1;i<=n;i++){
		bool flag = true;
		for (int j=1;j<=m;j++){
			if (a[i][j] != 0){
				flag = false;
				break;
			}
		}
		if (flag){
			for (int j=1;j<=m;j++){
				swap(a[1][j],a[i][j]);
			}
			break;
		}
	}
	Ans = 1;
	for (int i=2;i<=n;i++){
		int t = 1;
		int cnt = m;
		for (int j=1;j<=m;j++) 
			if (a[i][j] != 0){
				cnt--;
				t = t * a[i][j];
//				printf("*times* %d %d\n",cnt,a[i][j]);
			}
//		printf("%dt = %d\n",i,t);
		int tmp = 0;
		if (t == -1){
			for (int c=0;c<=cnt;c+=2){
				tmp = (tmp + C[cnt][c]) % p;
			}
			//在cnt个里面，选出奇数个，填成-1有多少种填法 
		} else{
			for (int c=1;c<=cnt;c+=2){
				tmp = (tmp + C[cnt][c]) % p;
			} 
		}
//		printf("%d:%d\n",i,tmp);
		Ans = 1LL * Ans * tmp % p; 
	}
	printf("%d\n",Ans);
	return 0;
}
