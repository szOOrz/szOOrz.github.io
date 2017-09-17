#include<bits/stdc++.h>
using namespace std;
const int maxn = 105050;
int read(){
	char c = getchar();
	while ((c<'0' || c>'9') && (c!='X') && (c!='-')) c = getchar();
	if (c == 'X') return 1e9+1;
	int f = 1;
	if (c == '-') f = -1,c = getchar();
	int a = 0;
	while (c>='0' && c<='9'){
		a = (a << 1) + (a << 3) + c - 48;
		c = getchar();
	}
	return a * f;
}
#define lowbit(x) (x & (-x))
int a[maxn],b[maxn],c[maxn],d[maxn],n;
int cmp(int x,int y){
	return a[x] < a[y];
}
int Add(int x){
	for (;x<=n;x+=lowbit(x)) d[x]++;
}
int get(int x){
	int Ans = 0;
	for (;x>0;x-=lowbit(x)) Ans += d[x];
	return Ans;
}
int count(){
	for (int i=1;i<=n;i++) b[i] = i;
	sort(b+1,b+1+n,cmp);
	for (int i=1;i<=n;i++) c[b[i]] = i;
	memset(d,0,sizeof(d));
	int Ans;
	for (int i=n;i>=1;i--){
		Ans += get(c[i]);
		Add(c[i]);
	}
	return Ans;
}
int main(){
	scanf("%d",&n);
	if (n == 1){
		puts("L");
		return 0;
	}
	int cnt = 0;
	for (int i=1;i<=n;i++){
		a[i] = read();
//		printf("%d %d\n",i,a[i]);
		if (a[i] == 1e9+1) cnt++;
	}
	if (cnt == 0){
		if (count() & 1) puts("W"); else puts("L");
	}else{
		if (cnt & 1) puts("W"); else puts("L");
	}
}
