#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
const int maxn = 1e6+100;
using namespace std;
vector<int> xL,xR;
int l[maxn],r[maxn];
/*
给出n个区间[li,ri]以及一个整数k，
称一个数的令人满意的如果它至少被
这n个区间中的k个区间覆盖，输出所
有令人满意的数构成的区间 
*/
#define mid ((L+R)>>1)
struct Y{
	int v,t;	
	
	bool operator < (const Y &x)const{
		return v<x.v || v==x.v && t>x.t;
	}
}y[maxn*2];
int numy;
int n,k,rec;
int main(){
	scanf("%d%d",&n,&k);
	numy = 0;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
		y[++numy].v = l[i];y[numy].t = 1;
		y[++numy].v = r[i];y[numy].t =-1;
	}
	sort(y+1,y+1+2*n);
	for (int i=2;i<=2*n;i++) y[i].t+=y[i-1].t;
	
	xL.clear();
	xR.clear();
	for (int i=1;i<=2*n;i++){
		if (y[i].t >= k){
			int L,R;
			L = y[i].v;
			while(y[i].t>=k){
				i++;
			}
			R = y[i].v;
			xL.push_back(L);
			xR.push_back(R);
		}
	}
	printf("%d\n",xL.size());
	for (int i=0;i<xL.size();i++){
		printf("%d %d\n",xL[i],xR[i]);
	}
	return 0;
}
/*
4 1
1 4
2 4


2 1 4 3
*/
