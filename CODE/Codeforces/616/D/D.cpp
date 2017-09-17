#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
const int maxn = 5e5+100;
int a[maxn];
int flag[1000006];
int l,r,L,R,n,k,cnt;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	L = 0;
	R = -1;
	
	l = 1;
	cnt = 0;
	for (r=1;r<=n;r++){
		flag[a[r]]++;
		if (flag[a[r]] == 1) cnt++;
		while (cnt > k){
			flag[a[l]]--;
			if (flag[a[l]] == 0) cnt--;
			l++;
		}
		if (R-L+1 < r-l+1){
			L = l;
			R = r;
		}
	}
	printf("%d %d\n",L,R);
}
