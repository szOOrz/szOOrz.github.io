/*
ID:cqz15311
LANG:C++
PROG:milk4
*/
#include<bits/stdc++.h>
using namespace std;
bool f[20001],g[20001];
int a[105],b[105];
int Q,n,k;

bool calc(int x){
	if (g[x]) return f[x];
	g[x] = true;
	for (int i=0;i<k;i++){
		if (x>=b[i] && calc(x-b[i])) return (f[x] = true);
	}
	return f[x] = false;
}//记忆化，判断x是否可行
 
void search(int deep,int tot){
	if (tot == k) {
		memset(g,0,sizeof(g));
		f[0] = g[0] = true;
		if (calc(Q)){
			printf("%d",k);
			for (int i=0;i<k;i++) printf(" %d",b[i]);
			puts("");
			exit(0);
		}
		return ;
	}
	if (deep >= n) return;
	b[tot] = a[deep];
	search(deep+1,tot+1);
	search(deep+1,tot);
}
int main(){
	freopen("milk4.in","r",stdin);
	freopen("milk4.out","w",stdout);
	scanf("%d%d",&Q,&n);
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for (k=1;k<=n;k++) search(0,0);
}
