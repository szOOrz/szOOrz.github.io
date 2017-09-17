#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
LL a[255],ans;
char s[205050];
int main(){
	scanf("%s",s);
	ans = 0;
	for (LL i=0;s[i];i++) {
		ans+=i-a[s[i]];
		a[s[i]]++;
	}
	printf("%lld\n",ans+1);
}
/*
4
aatt
taat
ttaa
atat
atta

a,a,t,t,aa,tt
6
(1+4) * 4 / 2 = 10
10 - 6 = 4



a,b,r,a,c,a,d,a,b,r,a

*/
