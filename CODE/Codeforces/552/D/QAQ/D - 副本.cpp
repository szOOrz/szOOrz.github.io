#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
struct P{
	LL x,y;
	P(LL a = 0,LL b = 0){
		x = a;
		y = b;
	}
	bool operator < (const P &t) const{
		return x < t.x || x == t.x && y < t.y;
	}
}p[2005];
map<P,int> Map;
LL gcd(LL a,LL b){
	if (a < b) swap(a,b);
	if (!b) return a; else return gcd(b,a%b);
}
LL n;
LL Ans;
int main(){
	scanf("%I64d",&n);
	for (LL i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].x+=105;
		p[i].y+=105;
		//保证所有点都是正的，而且不会出现0
		LL g = gcd(p[i].x,p[i].y);
		printf("%I64d\n",g);
		Map[P(p[i].x / g,p[i].y / g)]++;
	}
	Ans = n * (n-1) * (n-2) / 6;
	printf("%I64d\n",Ans);
	for (LL i=1;i<=n;i++){
		LL g = gcd(p[i].x,p[i].y);
		LL t = Map[P(p[i].x / g,p[i].y / g)];
		Map[P(p[i].x / g,p[i].y / g)] = 0;
		if (t >= 3)
			Ans = Ans - t * (t-1) * (t-2) / 6;
	}
	printf("%I64d\n",Ans);
}
