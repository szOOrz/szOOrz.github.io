#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
int n,a[105],Ans,pre1[105],pre0[105];
int main(){
	Ans = 0;
	scanf("%d",&n);
	pre0[0] = pre1[0] = 0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre0[i] = pre0[i-1] + (a[i] == 0);
		pre1[i] = pre1[i-1] + (a[i] == 1);
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<=i;j++){
			Ans = max(Ans,pre1[i] - pre1[j] + pre0[j]);
		}
	}
	printf("%d",Ans);
}
