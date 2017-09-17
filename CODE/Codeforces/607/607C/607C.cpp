#include<bits/stdc++.h> 
const int maxn = 1e6+100;
const int Mod = 1e9+7;
const int bit = 23333;
int Pow[maxn],n;
typedef long long LL;
char a[maxn],b[maxn];
LL f,g;
using namespace std;
int main(){
	scanf("%d",&n);
	n--;
	scanf("%s%s",&a,&b);
	for (int i=0;i<n;i++){
		if (b[i] == 'N') b[i] = 'S'; else
		if (b[i] == 'S') b[i] = 'N'; else
		if (b[i] == 'W') b[i] = 'E'; else
		if (b[i] == 'E') b[i] = 'W';
	}
	Pow[0] = 1;
	for (int i=1;i<=n;i++){
		Pow[i] = 1LL * Pow[i-1] * bit % Mod; 
	}
	int f = 0,g = 0;
	for (int i=n-1;i>=0;i--){
//		printf("%c %c\n",a[i],b[i]);
		f = (f + 1LL * a[i] * Pow[n-(i+1)]) % Mod;
		g = (1LL * g * bit + b[i]) % Mod;
//		printf("%d %d\n",f,g);
		if (f == g){
//			printf("%d\n",i);
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}

