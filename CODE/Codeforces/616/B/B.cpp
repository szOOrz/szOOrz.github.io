#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,Min,Max,x;
int main(){
	scanf("%d%d",&n,&m);
	Max = -0x3fffffff;
	for (int i=1;i<=n;i++){
		Min = 0x3fffffff; 
		for (int j=1;j<=m;j++){
			scanf("%d",&x);
			Min = min(Min,x);
		}
		Max = max(Max,Min);
	}
	printf("%d\n",Max);
}
