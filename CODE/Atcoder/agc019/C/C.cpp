#include<bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
typedef long long LL;
const LL maxn = 400050;
struct P{
	LL x,y;
	bool operator < (const P &t) const{
		return x<t.x;
	}
}p[maxn];
LL h[maxn],Hash[maxn];
LL c[maxn];
long double Ans;
#define lowbit(x) ((x & (-x)))
void update(LL x,LL val){
	for (;x<=Hash[0];x+=lowbit(x)){
		c[x] = max(c[x],val);
	}
}
LL get(LL x){
	LL ans = -0x3fffffff;
	for (;x>0;x-=lowbit(x)){
		ans = max(ans,c[x]);
	}
	return ans;
}
LL find(LL x){
	LL L = 1,R = Hash[0];
	while (L <= R){
		LL mid = (L + R) >> 1;
		if (Hash[mid] > x){
			R = mid-1;
		} else
		if (Hash[mid] < x){
			L = mid+1;
		} else
			return mid;
	}
	return -1;
}
LL X1,Y1,X2,Y2;
LL dp[maxn],n;
void solve1(){
	//从左上角到右下角
	LL tmp = Y1;
	Y1 = Y2;
	Y2 = tmp;
	scanf("%lld",&n);
	h[0] = 0;
	h[++h[0]] = Y1;
	h[++h[0]] = Y2;
	for (LL i=1;i<=n;i++){
		scanf("%lld%lld",&p[i].x,&p[i].y);
		if (p[i].x<X1 || p[i].x>X2 || p[i].y<Y1 || p[i].y>Y2){
			i--;
			n--;
			continue;
		}
		p[i].y = (Y2-Y1)-(p[i].y-Y1)+Y1;
		h[++h[0]] = p[i].y;
	}
	sort(h+1,h+1+h[0]);
	Hash[0] = 0;
	for (LL i=1;i<=h[0];i++){
		if (i == 1 || h[i]!=h[i-1])
			Hash[++Hash[0]] = h[i];
	}
	for (LL i=1;i<=Hash[0];i++) c[i] = -0x3fffffff;
	sort(p+1,p+1+n);
	dp[0] = 0;
	update(find(Y1),0);
	for (LL i=1;i<=n;i++){
		tmp = find(p[i].y);
		dp[i] = get(tmp) + 1;
		update(tmp,dp[i]);
	}
	LL t = get(find(Y2));
	Ans = (abs(X1-X2)+abs(Y1-Y2)) * 100 - 20 * t + t * pi * 5;
	if (t == abs(Y1-Y2)+1 || t == abs(X1-X2)+1) Ans = Ans + pi * 5.0;
	printf("%.20Lf\n",Ans);
}

void solve2(){
	//从左下角到右上角 
	scanf("%lld",&n);
	h[0] = 0;
	h[++h[0]] = Y1;
	h[++h[0]] = Y2;
	for (LL i=1;i<=n;i++){
		scanf("%lld%lld",&p[i].x,&p[i].y);
		if (p[i].x<X1 || p[i].x>X2 || p[i].y<Y1 || p[i].y>Y2){
			i--;
			n--;
			continue;
		}
		h[++h[0]] = p[i].y;
	}
	sort(h+1,h+1+h[0]);
	Hash[0] = 0;
	for (LL i=1;i<=h[0];i++){
		if (i == 1 || h[i]!=h[i-1])
			Hash[++Hash[0]] = h[i];
	}
	for (LL i=1;i<=Hash[0];i++) c[i] = -0x3fffffff;
	sort(p+1,p+1+n);
	dp[0] = 0;
	update(find(Y1),0);
	for (LL i=1;i<=n;i++){
		LL tmp = find(p[i].y);
		dp[i] = get(tmp) + 1;
		update(tmp,dp[i]);
	}
	LL t = get(find(Y2));
	Ans = (abs(X1-X2)+abs(Y1-Y2)) * 100.0 - 20.0 * t + t * pi * 5.0;
	if (t == abs(Y1-Y2)+1 || t == abs(X1-X2)+1) Ans = Ans + pi * 5.0;
	printf("%.20Lf\n",Ans);
}

void solve3(){
	scanf("%lld",&n);
	Ans = (max(Y1,Y2) - min(Y1,Y2)) * 100.0;
	for (LL i=1;i<=n;i++){
		LL x,y;
		scanf("%lld%lld",&x,&y);
		if ((x == X1) && (y >= min(Y1,Y2) && y<=max(Y1,Y2))){
			Ans = Ans - 10 * 2 + 10.0 * pi;
		}
	}
	printf("%.20Lf\n",Ans);
}

void solve4(){
	scanf("%lld",&n);
	Ans = (max(X1,X2) - min(X1,X2)) * 100.0;
	for (LL i=1;i<=n;i++){
		LL x,y;
		scanf("%lld%lld",&x,&y);
		if ((y == Y1) && (x >= min(X1,X2) && x<=max(X1,X2))){
			Ans = Ans - 10 * 2 + 10 * pi;
		}
	}
	printf("%.20Lf\n",Ans);
}

int main(){
	scanf("%lld%lld%lld%lld",&X1,&Y1,&X2,&Y2);
	if (X1>X2){
		LL tmp;
		tmp = X1;X1 = X2;X2 = tmp;
		tmp = Y1;Y1 = Y2;Y2 = tmp;
	}
	if (X1 == X2){
		solve3();
		return 0;
	}else
	if (Y1 == Y2){
		solve4();
		return 0;
	}
	if (Y1 > Y2){
		solve1();
		return 0;
	} else{
		solve2();
		return 0;
	}
}
/*
0 0 3 1
2
1 0
2 1
*/
