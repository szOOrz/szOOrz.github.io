//#include<bits/stdc++.h> 
#include<iostream> 
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<set>
using namespace std;
const int maxn = 305000;
set<int> vis,Edge[maxn];
set<int>::iterator v,nxt;
int q[maxn]; 
int front,rear;
void solve(int i){
	front = rear = 0;
	q[rear++] = i;
	vis.erase(i);
	for (;front<rear;front++){
		int u = q[front];
		v = vis.begin();
		while (v!=vis.end()){
			if (Edge[u].count(*v)){
				v++;
				continue;
			}
			q[rear++] = *v;
			(nxt = v)++;
			vis.erase(v,nxt);
			v = nxt;
		}
	}
} 
int n,m,k,In[maxn];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	memset(In,0,sizeof(In));
	for (int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		Edge[a].insert(b);
		Edge[b].insert(a);
		In[a]++;
		In[b]++;
	}
	if (k > n - 1 - In[1]){
		puts("impossible");
		return 0;
	}
	for (int i=1;i<=n;i++){
		if (In[i] == n-1){
			puts("impossible");
			return 0;
		}
	}
	for (int i=2;i<=n;i++){
		vis.insert(i);
	}
	int Rec = 0;
	for (int i=2;i<=n;i++){
		if (vis.count(i)){
			solve(i);
			bool flag = 0;
			for (int j=0;j<rear;j++){
				if (!Edge[1].count(q[j])){
					flag = 1;break;
				}
			}
			if (!flag){
				puts("impossible");
				return 0;
			}
			Rec++;
		}
	}
	if (Rec > k){
		puts("impossible");
		return 0;
	}
	puts("possible");
	return 0;
}
