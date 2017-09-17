#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL Mark[1005],y[1005],n;
bool solve(LL a,LL b){
	memset(Mark,0,sizeof(Mark));
//	Mark[x] = Mark[y] = 1;
	LL cnt = 0;
	for (LL i=1;i<=n;i++){
		if ((y[i] - y[a]) *(b-a)== (y[b] - y[a]) * (i-a)) Mark[i] = 1; else
														  cnt++;
	}
	if (cnt == 0) return false;
	if (cnt == 1) return true;
	vector<int> p;
	p.clear();
	for (LL i=1;i<=n;i++){
		if (!Mark[i]){
			p.push_back(i);
		}
	}
	if ((y[p[1]] - y[p[0]]) * (b-a) != (y[b]-y[a]) * (p[1] - p[0])) return false;
	for (LL i=2;i<(int)p.size();i++){
		if ((y[p[i-1]] - y[p[0]]) *(p[i] - p[0]) != (y[p[i]] - y[p[0]]) * (p[i-1] - p[0])) return false;
	} 
	return true;
}
int main(){
	scanf("%I64d",&n);
	for (LL i=1;i<=n;i++) scanf("%I64d",&y[i]);
	if (solve(1,2)) puts("Yes"); else
	if (solve(1,3)) puts("Yes"); else
	if (solve(2,3)) puts("Yes"); else
	puts("No");
	return 0;
}
