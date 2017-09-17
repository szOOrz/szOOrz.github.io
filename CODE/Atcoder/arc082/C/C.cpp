#include<cstdio> 
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 1e5+100;
int cnt[maxn],Ans;
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	for (int x=1;x<=1e5;x++){
		Ans = max(Ans,cnt[x-1]+cnt[x]+cnt[x+1]);
	}
	printf("%d\n",Ans);
}
