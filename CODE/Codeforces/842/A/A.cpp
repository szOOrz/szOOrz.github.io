#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL l,r,x,y,k;
int main(){
//	freopen("sb.in","r",stdin);
	//freopen("std.out","w",stdout); 
	scanf("%I64d%I64d%I64d%I64d%I64d",&l,&r,&x,&y,&k);
	for (LL b=x;b<=y;b++){
		LL t = b * k;
		if ((l <= t) && (t <= r)){
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}
