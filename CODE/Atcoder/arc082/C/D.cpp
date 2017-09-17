#include<bits/stdc++.h> 
using namespace std;
const int maxn = 1e5+100;
int n,a[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int cnt = 0,i;
	for (i=1;i<=n;i++){
		if (a[i] == i) cnt++,i++;
	}
	printf("%d\n",cnt);
}
