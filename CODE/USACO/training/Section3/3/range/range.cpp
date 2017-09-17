/*
6
101111
001111
111111
001111
101101
111001

2 10
3 4
4 1
*/  

/*
ID:cqz15311
LANG:C++
PROG:range
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int ans[255],a[255][255],f[255][255];
int n;
int read(){
	int a = 0;
	char c = getchar();
	while (!((c>='0') && (c<='9'))) c = getchar();
	while ((c>='0') && (c<='9')){
		a = a * 10 + c - 48;
		c = getchar();
	}
	return a;
}
int main(){
	freopen("range.in","r",stdin);
	freopen("range.out","w",stdout);
	n = read();
	char c;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			c = getchar();
			while (!((c>='0') && (c<='1'))) c = getchar();
			a[i][j] = c - 48;
		}
	}
	memset(ans,0,sizeof(ans));
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (a[i][j] == 1){
				f[i][j] = min(f[i-1][j],min(f[i][j-1],f[i-1][j-1]))+1;
				ans[f[i][j]]++;
			}
//			printf("%d ",f[i][j]);
		}
//		puts("");
	}
	for (int i=n-1;i>=1;i--){
		ans[i] += ans[i+1];
	}
	for (int i=2;i<=n;i++){
		if (ans[i] > 0){
			printf("%d %d\n",i,ans[i]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
