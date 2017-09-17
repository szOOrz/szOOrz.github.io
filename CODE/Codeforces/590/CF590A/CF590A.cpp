#include<bits/stdc++.h>
using namespace std;
const int maxn = 500500;
int a[maxn],Ans,n;
bool T[maxn];
int L,R,l,r,x,y;
int main(){
	scanf("%d",&n);
	int cnt = 0;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0] = a[1]; a[n+1] = a[n];
	memset(T,false,sizeof(T));
	for (int i=1;i<=n;i++){
		if ((a[i-1] != a[i]) && (a[i+1] != a[i])){
			T[i] = true;
		}
	}
//	for (int i=1;i<=n;i++) printf("%d",T[i]);
//	puts("");
	//Ti为true表示要变
	L = 1;Ans = 0;
	for (int R=2;R<=n;R++){
		if (!T[R]){
			l = L + 1,r = R - 1;
			x = a[L],y = a[R];
			cnt = 0;
			while (l <= r){
				a[l] = x;
				a[r] = y;
				l++;
				r--;
				cnt++;
			}
			Ans = max(Ans,cnt);
			L = R;
		}
	}
	printf("%d\n",Ans);
	for (int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
