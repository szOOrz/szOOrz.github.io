/*
ID:cqz15311
LANG:C++
PROB:fence8
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn = 55;
const int maxm = 1025;
int n,m,V[maxn],r[maxm],All,Sum[maxm];
bool Judge(int i,int waste,int last){
	if (waste < 0) return false;
	if (i == -1) return true;
	int limit = n-1;
	if (last != -1 && r[i] == r[i+1]) limit = last;
	for (int j=limit;j>=0;j--){
		if (V[j] >= r[i]){
			V[j]-=r[i];
			int tmp = Judge(i-1,waste - V[j]*(V[j]<r[0]),j);
			V[j]+=r[i];
			if (tmp) return true;
		}
	}
	return false;
}
void init(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&V[i]);
	}
	sort(V,V+n);
	scanf("%d",&m);
	for (int i=0;i<m;i++){
		scanf("%d",&r[i]);
		if (r[i] > V[n-1]) i--,m--;//如果大于最大背包容量 
	}
	sort(r,r+m);
	for (int i=0;i<n;i++){
		if (V[i] < r[0]){
			for (int j=0;j<n-1;j++) V[j] = V[j+1];
			i--,n--;
		}
	}
	All = 0;
	for (int i=0;i<n;i++) All += V[i];
	Sum[0] = r[0];
	for (int i=1;i<m;i++) Sum[i] = Sum[i-1] + r[i];
}
int Ans;
int main(){
	freopen("fence8.in","r",stdin);
	freopen("fence8.out","w",stdout);
	init();
	Ans = 0;
	int L = 1,R = m;
	while (L <= R){
		int Mid = (L + R) >> 1;
		if (Judge(Mid - 1,All - Sum[Mid-1],-1)){//可以放下Mid件 
			Ans = Mid;
			L = Mid + 1;
		} else{
			R = Mid - 1;
		}
	}
	printf("%d\n",Ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*假设总原材料为all，前K个木头总和为sum，那么all-sum就是这一次切割过程中能【浪费】的最大数目。对于一个切剩下的原材料，若它比最小的目标木头还要小，则它可视为【无用】的，无用的也就是浪费的，若浪费>all-sum，则直接返回false*/

