#include<bits/stdc++.h> 
using namespace std;
bool cmp(int x,int y){
	
}
int main(){
	scanf("%d%d%d",&n,&w,&h);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&g[i],&p[i],&t[i]);
		if (g[i] == 1){
			//(p[i],-t[i])
			px[p[i]-t[i]+100000].push_back(i);
		}else
		if (g[i] == 2){
			//(-t[i],p[i])
			py[p[i]-t[i]+100000].push_back(i);
		}
	}
	for (int i=0;i<=200000;i++){
		if (px[i].size() == 0 && py[i].size() == 0) continue;
		sort(px[i].begin(),px[i].end(),cmp);
		sort(py[i].begin(),py[i].end(),cmp);
	}
}
