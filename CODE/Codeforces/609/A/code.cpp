#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 105;
int n,m,a[maxn];
int main(){
	scanf("%d",&n);
	scanf("%d",&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for (int i=n;i>=1;i--){
		m-=a[i];
		if (m <= 0){
			printf("%d\n",n-i+1);
			return 0;
		}
	}
	return 0;
}
