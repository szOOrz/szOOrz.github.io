#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1000009;
int n;
int a[maxn][2];
LL f[maxn],g[maxn];
bool flag;

inline int read(){
	char ch = getchar();
	int a = 0;
	while (ch<'0'||'9'<ch) ch = getchar();
	while ('0'<=ch&&ch<='9'){
		a = a*10 + ch-'0';
		ch = getchar();
	}
	return a;
}

void write(int ans1,int ans2,int ans3,int ans4){
	if (flag) swap(ans1,ans3),swap(ans2,ans4);
	printf("%d\n",ans2-ans1);
	for (int i=ans1+1;i<=ans2;i++) printf("%d ",i);
	puts("");
	printf("%d\n",ans4-ans3);
	for (int i=ans3+1;i<=ans4;i++) printf("%d ",i);
	puts("");
}

int main(){
	n = read();
	f[0] = 0;for (int i=1;i<=n;i++) f[i] = f[i-1] + read();
	g[0] = 0;for (int i=1;i<=n;i++) g[i] = g[i-1] + read();
	flag = false;
	if (f[n] > g[n]){
		flag = true;
		for (int i=0;i<=n;i++) swap(f[i],g[i]);
	}
	int last = 0;
	memset(a,-1,sizeof(a));
	for (int i=0;i<=n;i++){
		while(last+1 <= n && f[i] >= g[last+1]) last++;
		if (a[f[i] - g[last]][0] == -1){
			a[f[i] - g[last]][0] = i;
			a[f[i] - g[last]][1] = last;
		}else{
			write(a[f[i] - g[last]][0],i,a[f[i] - g[last]][1],last);
			return 0;
		}
	}
	return 0;
}
