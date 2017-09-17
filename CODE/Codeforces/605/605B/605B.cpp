#include<bits/stdc++.h> 
using namespace std;
const int maxn = 100500;
struct Edge{
	int v,f,id;
	bool operator < (const Edge &x){
		return (v < x.v) || (v == x.v) && (f > x.f);
	}
}E[maxn];
int n,m;
int qx[maxn],qy[maxn],Ansx[maxn],Ansy[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&E[i].v,&E[i].f);
		E[i] . id = i;
	}
	sort(E+1,E+1+m);
	bool flag = true;
	int j = 1,k=1;
	int l = 0 ,r = 0;
	for (int i=1;i<=m && flag;i++){
//		printf("%d ->%d :%d\n",E[i].v,E[i].f,E[i].id);
		if (!E[i] . f){
			if (l == r){
				flag = false;
				break;
			}//如果找不到
			Ansx[E[i].id] = qx[l];
			Ansy[E[i].id] = qy[l];
			l++;
		}//如果不是最小生成树的边 
		else{
			k++;
			if (k == n+1){
				flag = false;
				break;
			}
			for (int t=2;t<k && r<=m;t++){
				qx[r] = t;
				qy[r] = k;
				r++;
			}
			Ansx[E[i].id] = 1;
			Ansy[E[i].id] = k;
		}
	}
	if (!flag){
		puts("-1");
	} else
		for (int i=1;i<=m;i++){
			printf("%d %d\n",Ansx[i],Ansy[i]);
		}
	return 0;
}
