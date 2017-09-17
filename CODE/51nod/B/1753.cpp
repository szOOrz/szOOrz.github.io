#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
const int Mod = 1e9+7;
const int maxn = 300050;
int Pow[maxn];

int get(int s1,int s2){
	int i1 = s1,i2 = s2;
	for (int i=19;i>=0;i--){
		if (Hash[i][i1] == Hash[i][i2]) i1 += (1<<i),i2 += (1<<i);
	}
	return i1 - s1;
}
int main(){
	//考虑用f[i,j]表示第i个开始，持续j个的Hahs值是多少。
	//考虑转化为26进制。%1e9+7 
	scanf("%s",s);
	n = strlen(s);
	Pow[0] = 1;
	for (int i=1;i<=n;i++) Pow[i] = 1LL * Pow[i-1] * 26 % Mod;
	for (int i=0;i<n;i++) Hash[0][i] = s[i];
	for (int i=1;i<=19;i++){
		for (int j=0;j<n;j++) Hash[i][j] = Hash[i-1][j]*Pow[i] + Hash[i-1][j+(1<<(i-1))];
	}
	int T;
	scanf("%d",&T);
	int k,l1,r1,l2,r2;
	while (T--){
		scanf("%d%d%d%d%d",&k,&l1,&r1,&l2,&r2);
		int First = get(l1,l2);
		if (First > l2-l1) puts("YES"); else{
			int Second = get(l1 + First,l2+First);
			if (Second >l2-l1) puts("YES"); else puts("NO");
		}
	}
	return 0;
}
