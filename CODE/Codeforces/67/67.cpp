#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
int a[maxn],b[maxn],n,x;
int main(){
	cin >> n;
	for (int i=1;i<=n;i++) cin >> x,a[x] = i;
	for (int i=1;i<=n;i++) cin >> x,b[i] = -a[x];
	memset(a,0,sizeof(a));
	for (int i=1;i<=n;i++) *lower_bound(a+1,a+1+n,b[i]) = b[i];
	cout << lower_bound(a+1,a+1+n,0) - a - 1 << endl;
	return 0; 
}
