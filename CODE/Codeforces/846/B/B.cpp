#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,k,M,t[55],All,Rec,_M,Ans;
int main(){
	scanf("%d%d%d",&n,&k,&M);
	for (int i=1;i<=k;i++) scanf("%d",&t[i]);
	All = 0;
	for (int i=1;i<=k;i++) All = All + t[i];
	sort(t+1,t+1+k);
	for (int i=0;i<=n;i++){
		//枚举有多少个全部选择 
		_M = M - All * i;
		Rec = (k+1) * i;
		if (_M < 0) break;
		for (int j=1;j<=k;j++){
			if (_M - t[j] * (n - i) >= 0){
				Rec = Rec + (n - i);
				_M = _M - t[j] * (n - i);
			} else{
				Rec = Rec + _M / t[j];
				_M %= t[j];
				break;
			}
		}
		Ans = max(Ans,Rec);
	}
	printf("%d\n",Ans);
}
