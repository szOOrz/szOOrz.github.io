#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,A,B,C,x,a,b,Mod;
const int maxn = 10001115;
int f[maxn*2],q[maxn*2];
int front,rear,l,r;
long long Ans;
int main(){
	scanf("%d%d%d%d%d%d%d%d",&n,&A,&B,&C,&x,&a,&b,&Mod);
	front = rear = l = r = n + 10;
	Ans = 0;
	for (int i=1;i<=n;i++){
		x = (1LL * x * a + b) % Mod;
		if (x % (A+B+C) < A || rear-front<=1){
			f[rear++] = x;
			if (l==r || f[q[r-1]] < x) q[r++] = rear-1;
		} else
		if (x % (A+B+C) < A+B){
			//在头部插入。
			f[--front] = x;
			while (l<r && f[q[l]] < x) l++;
			q[--l] = front;
		} else{
			rear--;
			if (q[r-1] == rear) r--;
		}
		Ans = (Ans + f[q[r-1]]) % ((int)1e9+7);
	}
	printf("%lld\n",Ans);
}
