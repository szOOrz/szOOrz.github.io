#include<bits/stdc++.h>
using namespace std;
const int maxn = 105000;
int y[maxn],Hash[maxn],n;
int find(int x){
	int L = 1 ,R = Hash[0];
	while (L < R) {
		int Mid = (L + R) >> 1;
		if (Hash[Mid] < x){
			L = Mid + 1;
		} else
		if (Hash[Mid] > x){
			R = Mid - 1; 
		}else 
			return Mid;
	}
	return L;
}
int a[maxn],t[maxn],x[maxn];
multiset<int> Add[maxn],Del[maxn];
#define lowbit(x) ((x & (-x)))
void solve(){
	for (int i=1;i<=n;i++){
		Add[i].clear();
		Del[i].clear();
	}
	for (int i=1;i<=n;i++){
		if (a[i] == 1){
			for (int j = t[i];j <= Hash[0];j+=lowbit(j)){
				Add[j] . insert(x[i]);
			}
		}//Ìí¼ÓÔªËØ 
		if (a[i] == 2){
			for (int j = t[i];j <= Hash[0];j+=lowbit(j)){
				Del[j] . insert(x[i]);
			}
		}
		if (a[i] == 3){
			int Ans = 0;
			for (int j = t[i];j > 0;j-=lowbit(j)){
				Ans += Add[j].count(x[i]);
				Ans -= Del[j].count(x[i]);
			}
			printf("%d\n",Ans);
		}
	}
}
int main(){
	y[0] = 0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&t[i],&x[i]);
		y[++y[0]] = t[i];
	}
	sort(y+1,y+1+y[0]);
	Hash[0] = 0;
	for (int i=1;i<=y[0];i++){
		if (i == 0 || y[i]!=y[i-1])
			Hash[++Hash[0]] = y[i];
	}
	for (int i=1;i<=n;i++)
		t[i] = find(t[i]);
	solve();
	return 0;
}
