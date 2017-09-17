#include<bits/stdc++.h>
using namespace std;
int n,A,B,C,x,a,b,Mod;
const int maxn = 10001115;
int f[maxn*2],q[maxn*2];
int front,rear,l,r;
long long Ans;
int main(){
	scanf("%d",&n);
	front = rear = l = r = n + 10;
	Ans = 0;
	for (int i=1;i<=n;i++){
		int type;
		scanf("%d",&type);
		if (type==0 || rear-front<=1){
			scanf("%d",&x);
			f[rear++] = x;
			if (l==r || f[q[r-1]] < x) q[r++] = rear-1;
		} else
		if (type==1){
			//在头部插入。
			scanf("%d",&x);
			f[--front] = x;
			while (l<r && f[q[l]] < x) l++;
			q[--l] = front;
		} else{
			rear--;
			if (q[r-1] == rear) r--;
		}
		Ans = Ans + f[q[r-1]];
		for (int j=front;j<rear;j++) printf("%d ",f[j]);
		printf("-----");
		for (int j=l;j<r;j++) printf("%d ",f[q[j]]);
		puts("");
		
	}
	printf("%lld\n",Ans);
}
