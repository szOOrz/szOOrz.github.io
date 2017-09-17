#include<cstdio> 
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int cnt;
typedef long long LL;
LL x,k;
vector<LL> p;
void init(){
	for (LL i=1;i*i<=x;i++){
		if (x % i == 0){
			p.push_back(i);
			if (i*i == x) break;
			p.push_back(x / i);
		}
	}
	sort(p.begin(),p.end());
	//for (vector<LL>::iterator it=p.begin();it!=p.end();it++) printf("%I64d ",*it);
}

void dfs(LL num,int deep){
	if (deep == 0 || num == 1){
		if (num == 1) putchar('1'),putchar(' '); else printf("%I64d ",num);
		cnt++;
		if (cnt == 1e5) exit(0);
		return ;
	}
	for (vector<LL>::iterator it=p.begin();it!=p.end();it++){
		if (num % (*it) == 0){
			dfs(*it , deep-1);
		} else
			if ((*it) > num) return;
	}
}

int main(){
	scanf("%I64d%I64d",&x,&k);
	cnt = 0;
	init();
	dfs(x,k);
	return 0;
}
/*
963761198400 65535
*/
