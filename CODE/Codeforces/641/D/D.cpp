#include<bits/stdc++.h> 
using namespace std;
const int maxn = 100500;
double Pmax[maxn],Pmin[maxn],x[maxn],y[maxn],a,b,c;
double sumx,sumy;
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lf",&Pmax[i]);
	for (int i=1;i<=n;i++) scanf("%lf",&Pmin[i]);
	sumx = 0;
	sumy = 0;
	for (int i=1;i<=n;i++){
		a = -1;
		b = (Pmax[i] + Pmin[i] + sumy - sumx);
		c = (Pmax[i] + Pmin[i]) * sumx - Pmax[i];
//		printf("a,b,c=%lf %lf %lf\n",a,b,c);
		double drt = b*b-4*a*c;
		if (drt < 0) drt = 0;
		x[i] = (-b + sqrt(drt)) / 2*a;
		y[i] = Pmax[i] + Pmin[i] - x[i];
		sumx += x[i];
		sumy += y[i];
//		printf("%lf %lf\n",sumx,sumy);
	}
	for (int i=1;i<=n;i++){
		printf("%.20lf ",x[i]);
	}
	puts("");
	for (int i=1;i<=n;i++){
		printf("%.20lf ",y[i]);
	}
	return 0;
}
