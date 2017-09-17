#include<bits/stdc++.h>
using namespace std;
double dist(double a,double b,double c,double d){
	return sqrt(double(a-c)*(a-c)+double(b-d)*(b-d));
}
const double inf = 1e80;
const int maxn = 1e6+5;
double Kx,Ky,Cx,Cy,Tx,Ty,x,y;
int n;
double pre[maxn],suff[maxn],SC[maxn],Sum;
int main(){
	scanf("%lf%lf%lf%lf%lf%lf",&Kx,&Ky,&Cx,&Cy,&Tx,&Ty);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%lf%lf",&x,&y);
		double Add = dist(Tx,Ty,x,y);
		Sum += Add * 2;
		pre[i] = suff[i] = dist(Kx,Ky,x,y) - Add;
		SC[i] = dist(Cx,Cy,x,y) - Add;
	}
	pre[0] = inf;suff[n+1] = inf;
	for (int i=1;i<=n;i++) pre[i] = min(pre[i-1],pre[i]);
	for (int i=n;i>=1;i--) suff[i] = min(suff[i+1],suff[i]);
	double Ans = suff[1] + Sum;
	for (int i=1;i<=n;i++){
		Ans = min(Ans,Sum + min(0.0,min(pre[i-1],suff[i+1]))+SC[i]);
	}
	printf("%.12lf\n",Ans);
} 
