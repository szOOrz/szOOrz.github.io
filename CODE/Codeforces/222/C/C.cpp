#include<bits/stdc++.h>
using namespace std;
const int maxval = 1e7;
const int maxn = 1e5+10;
int a[maxn],b[maxn],prime[700000];
bool Isprime[maxval+10];
int prime_id[maxval+10];
int fa[700000],fb[700000],gcd[700000],_gcd[700000];
int n,m,rec;
void init(){
	memset(Isprime,true,sizeof(Isprime));
	prime[0] = 0;
	Isprime[1] = false;
	for (int i=2;i<=maxval;i++){
		if (Isprime[i]){
						prime[++prime[0]] = i;
						prime_id[i] = prime[0];
//						printf("%d :%d\n",i,prime_id[i]);
					   }
		for (int j=1;j<prime[0] && i*prime[j]<=maxval;j++){
			Isprime[i * prime[j]] = false;
			if (i % prime[j] == 0) break;
		}
	}
} 
int main(){
	init();
//	for (int i=1;i<=10000;i++){
//		printf("%d %d\n",prime[i],prime_id[prime[i]]);
//	} 
	memset(fa,0,sizeof(fa));
	memset(fb,0,sizeof(fb));
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		rec = a[i];
		for (int j=1;prime[j]*prime[j] <= rec && j<=prime[0];j++)
			while (rec % prime[j] == 0){
				fa[j]++;
//				printf("\n%d-->%d-->%d\n",rec,prime[j],rec/prime[j]);
				rec /= prime[j];
			}
//		printf("%d,%d:%d\n",rec,prime_id[rec]);
		if (rec!=1) fa[prime_id[rec]]++;
	}
	for (int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		rec = b[i];
		for (int j=1;prime[j]*prime[j] <= rec && j<=prime[0];j++)
			while (rec % prime[j] == 0){
				fb[j]++;
				rec /= prime[j];
			}
		if (rec!=1) fb[prime_id[rec]]++;
	}
	for (int i=1;i<=prime[0];i++){
		gcd[i] = min(fa[i],fb[i]);
		_gcd[i] = min(fa[i],fb[i]);
//		printf("%d (%d,%d)%d\n",prime[i],fa[i],fb[i],gcd[i]);
	}
	printf("%d %d\n",n,m);
	for (int i=1;i<=n;i++){
		rec = a[i];
		for (int j=1;prime[j]*prime[j] <= rec;j++)
			while (rec % prime[j] == 0){
				rec /= prime[j];
				if (_gcd[j]>0){
					a[i] /= prime[j];
					_gcd[j]--;
				} 
			}
		if (rec != 1){
			if (_gcd[prime_id[rec]]>0){
				_gcd[prime_id[rec]]--;
				a[i] /= rec;
			}
		} 
		printf("%d ",a[i]);
	}
	puts("");
	for (int i=1;i<=m;i++){
		rec = b[i];
		for (int j=1;prime[j]*prime[j] <= rec;j++)
			while (rec % prime[j] == 0){
				rec /= prime[j];
				if (gcd[j]>0){
					b[i] /= prime[j];
					gcd[j]--;
				} 
			}
		if (rec != 1){
			if (gcd[prime_id[rec]]>0){
				gcd[prime_id[rec]]--;
				b[i] /= rec;
			}
		} 
		printf("%d ",b[i]);
	}
	return 0;
}
