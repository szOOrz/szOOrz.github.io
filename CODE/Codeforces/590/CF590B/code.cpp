#include<bits/stdc++.h>
using namespace std;
double T,V,X1,X2,Y1,Y2,X3,Y3,t,vx,vy,wx,wy;
double L,R,mid;
double dist(double a,double b,double c,double d){
	return sqrt((a-c) * (a-c) + (b-d) * (b-d));
}
bool check(double T){
	if (T <= t){
		X3 = X2 - T*vx;
		Y3 = Y2 - T*vy;
		return dist(X1,Y1,X3,Y3) <= T*V;
	} else{
		X3 = X2 - t*vx - (T-t) * wx;
		Y3 = Y2 - t*vy - (T-t) * wy;
		return dist(X1,Y1,X3,Y3) <= T*V;
	} 
}
int main(){
	scanf("%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2);
	scanf("%lf%lf%lf%lf%lf%lf",&V,&t,&vx,&vy,&wx,&wy);
	L = 0;R = 1e10;
	while (R-L > 1e-8){
		mid = (L+R) * 0.5;
		if(check(mid)) R = mid; else L = mid;
	}
	printf("%lf\n",L);
}
