#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
const int maxn = 205000;
vector<LL> X;
LL n,k,b,c;
priority_queue<LL> heap[5];
LL sum[5],now[5],a[maxn],t[maxn][5],Ans;
int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&k,&b,&c);
	b = min(b,5LL*c);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		a[i]+=1e9;
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		int r = a[i] % 5;
		for (int j=0;j<5;j++){
			t[i][r] = a[i] + j;
			r = (r+1) % 5;
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<5;j++){
			X.push_back(t[i][j]);
		}
	}
	Ans = 0x3fffffffffffffff;
	sort(X.begin(),X.end());
	memset(now,0,sizeof(now));
	for (int i=0;i<X.size();i++){
		if (i == 0 || X[i]!=X[i-1]){
			int x = X[i];
			int r = x % 5;
	//		printf("QAQ:%d %d\n",x,r);
			while (now[r]+1 <= n && t[now[r]+1][r] <= x){
				now[r]++;
				sum[r] += t[now[r]][r] * c - a[now[r]] * c - t[now[r]][r] / 5 * b;
				heap[r] . push(t[now[r]][r] * c - a[now[r]] * c - t[now[r]][r] / 5 * b);
				while (heap[r].size() > k){
					sum[r] -= heap[r].top();
					heap[r].pop();
				}
			}
	//		printf("%I64d %I64d\n",k*(x/5*b),sum[r]);
			if (heap[r].size() == k)
				Ans = min(Ans,k *( x / 5 * b) + sum[r]);
		}
	}
	printf("%I64d\n",Ans);
}
