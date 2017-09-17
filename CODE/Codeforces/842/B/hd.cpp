#include<bits/stdc++.h>
using namespace std;
int main(){
	int r,d,n,x,y,z,ans = 0;
	scanf("%d%d%d",&r,&d,&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		double k = sqrt(x*x+y*y);
		if (k>=r-d+z && k+z<=r) ans++;
	}
	printf("%d",ans);
	return 0;
}
