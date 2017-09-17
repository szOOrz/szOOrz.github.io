#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,a[105];
int f[105],g[105];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(f,false,sizeof(f));
	memset(g,false,sizeof(g));
	g[0] = true;
	for (int i=1;i<=n;i++){
		if (a[i] & 1){
			for (int j=1;j<=i;j++){
				if ((a[j] & 1) && (f[j-1]) && ((i-j+1) & 1)){
					g[i] = true;
					break;
				}
			}
		}
		if (a[i] & 1){
			for (int j=1;j<=i;j++){
				if ((a[j] & 1) && (g[j-1]) && ((i-j+1) & 1)){
					f[i] = true;
					break;
				}
			}
		}
	}
	if (f[n]){
		puts("Yes");
	} else
		puts("No");
	return 0;
}
