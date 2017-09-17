#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
const int maxn = 1e7;
long long Ans;
int a,n;
int b[maxn+100];
int main(){
	scanf("%d%d",&a,&n);
	for (int i=1;i<=maxn;i++) b[i] = i;
	for (int i=2;i*i<=maxn;i++){
		if (b[i*i] % (i*i) == 0){
			for (int j=1;i*i*j<=maxn;j++){
				while (b[i*i*j] % (i*i) == 0){
					b[i*i*j] /= i*i;
				}
			}
		}
	}
	Ans = 0;
	for (int i=a;i<=a+n-1;i++){
		Ans = Ans + b[i];
	}
	printf("%I64d\n",Ans);
}
