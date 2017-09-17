#include<bits/stdc++.h> 
using namespace std;
const int maxn  = 100005;
map<int,int> Map;
int n;
int a[maxn],f[maxn];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		Map[a[i]]++;
	}
	for (int i=1;i<=n;i++){
		if (Map[a[i]] >= 2){
			f[++f[0]] = a[i];
			Map[a[i]] -= 2;
		}
	}
	sort(f+1,f+1+f[0],cmp);
	if (f[0] <= 1) puts("0"); else{
		printf("%lld\n",(long long)f[1] * f[2]);
	}
	return 0;
}
