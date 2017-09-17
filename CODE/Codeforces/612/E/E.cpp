#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
int n,p[maxn],vis[maxn],num,ans[maxn];
vector<int> a[maxn],b[maxn];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=n;i++){
		num = 0;
		for (int j=i;!vis[j];j=p[j]){
			vis[j] = true;
			++num;
			a[i].push_back(j); 
		}
		b[num].push_back(i); 
	}
	for (int i=1;i<=n;i++){
		if (i % 2 == 0 && (b[i].size() & 1)){
			puts("-1");
			return 0;
		}
	}
	for (int i=0;i<(int)b[1].size();i++)
		ans[b[1][i]] = b[1][i];
	memset(vis,false,sizeof(vis));
	for (int i=2;i<=n;i++){
		for (int j=0;j<(int)b[i].size();j++){
			if (i & 1){
				int x = a[b[i][j]][0],y=a[b[i][j]][i/2+1];
				while (!vis[x]){
					vis[x] = vis[y] = 1;
					ans[x] =  y;
					x = p[x];
					ans[y] = x;
					y = p[y];
				}
			} else{
				int x = a[b[i][j]][0],y = a[b[i][j+1]][0];
				while (!vis[x] && !vis[y]){
					vis[x] = vis[y] = 1;
					ans[x] = y;
					x = p[x];
					ans[y] = x;
					y = p[y];
				}
				j++;
			}
		}
	}
	for (int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
