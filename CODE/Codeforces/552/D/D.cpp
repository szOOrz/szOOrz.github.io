#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
struct P{
	LL x,y;
}p[2005];
struct Line{
	LL a,b;
	Line(LL _a = 0,LL _b = 0){
		a = _a;
		b = _b;
	}
	bool operator < (const Line &t) const{
		return (a<t.a) || (a==t.a && (b < t.b));
	}
};
map<Line,int> Map;
LL N;
LL X0,Ans,t;
int main(){
	scanf("%I64d",&N);
	for (LL i=1;i<=N;i++){
		scanf("%I64d%I64d",&p[i].x,&p[i].y);
	}
	for (LL i=1;i<=N;i++){
		for (LL j=i+1;j<=N;j++){			
			if (p[i].x == p[j].x){
				X0++;
				continue;
			}
			double a = (double(p[i].y-p[j].y) / (p[i].x-p[j].x));
			double b = p[i].y - a * p[i].x;
			Map[Line(LL(a * 10000000),LL(b * 10000000))]++;
		}
	}
	Ans = (N * (N-1) * (N-2)) / 6;
//	printf("%I64d\n",Ans);
	X0 = (LL)sqrt(X0*2.0) + 1;
	if (X0 >= 3){
		Ans = Ans - (X0 * (X0-1) * (X0-2)) / 6;
	}
//	printf("%I64d\n",Ans);
	for (LL i=1;i<=N;i++){
		for (LL j=i+1;j<=N;j++){
			if (p[i].x == p[j].x) continue;
			double a = (double(p[i].y-p[j].y) / (p[i].x-p[j].x));
			double b = p[i].y - a * p[i].x;
			t = Map[Line(LL(a * 10000000),LL(b * 10000000))];
			Map[Line(LL(a * 10000000),LL(b * 10000000))] = 0;
			t = (LL)sqrt(t*2.0) + 1;
			if (t >= 3){
				Ans = Ans - (t * (t-1) * (t-2)) / 6;
			}
		}
	}
	printf("%I64d\n",Ans);
}
