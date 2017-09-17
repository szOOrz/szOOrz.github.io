#include<bits/stdc++.h>
using namespace std;
const int maxn = 100500;
int a[maxn],c[maxn],rec,n;
int main(){
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[a[i]] = c[a[i]-1]+1;
		rec = max(rec,c[a[i]]);
	}
	printf("%d\n",n - rec);
	return 0;
}
