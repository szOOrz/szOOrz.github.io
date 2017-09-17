#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 100005;
LL b[maxn];
LL n,a[maxn],Ans,sum,remain;
bool cmp(LL a,LL b){
	return a > b;
}
int main(){
	scanf("%I64d",&n);
	sum = 0;
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
		sum = sum + a[i];
	}
	sort(a+1,a+1+n,cmp);
	remain = sum % n;
	sum = sum / n;
	for (int i=1;i<=n;i++){
		b[i] = sum;
		if (remain > 0){
			remain--;
			b[i]++;
		}
	}
	Ans = 0;
	for (int i=1;i<=n;i++){
		Ans = Ans + abs(a[i] - b[i]);
	}
	printf("%I64d\n",Ans / 2);
}
