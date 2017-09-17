#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
struct Tree{
	int nxt[2];
	int cnt;
}tree[1<<21];
void clear(int x){
	memset(tree[x].nxt,-1,sizeof(tree[x].nxt));
	tree[x].cnt = 0;
}
int num;
void insert(int x){
	int p = 0;
	for (int i=19;i>=0;i--){
		int t = (x >> i) & 1;
		if (tree[p].nxt[t] == -1){
			tree[p].nxt[t] = num;
			clear(num);
			num++;
		}
		p = tree[p].nxt[t];
	}
	tree[p].cnt = 1;
}
void dfs(int x){
	for (int t=0;t<2;t++)
		if (tree[x].nxt[t]!=-1){
			dfs(tree[x].nxt[t]);
			tree[x].cnt+=tree[tree[x].nxt[t]].cnt;
		}
}
int find(int x){
	int p = 0;
	int Ans = 0;
	for (int i=19;i>=0;i--){
		int t = (x >> i) & 1;
		if (tree[p].nxt[t] == -1) return Ans;
		if (tree[tree[p].nxt[t]].cnt != (1<<i)){
			Ans = Ans + (0 << i);
			p = tree[p].nxt[t];
		} else{
			Ans = Ans + (1 << i);
			if (tree[p].nxt[t ^ 1] == -1) return Ans;
			p = tree[p].nxt[t ^ 1];
		}
	}
	return Ans;
}
const int maxn = 3e5+100;
int n,m,pre,a[maxn];
int main(){
	clear(0);
	num = 1;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		insert(a[i]);
	}
	dfs(0);
	pre = 0;
	while (m--){
		int x;
		scanf("%d",&x);
		pre = pre ^ x;
//		puts("");
//		puts("");
		printf("%d\n",find(pre));
	}
	return 0;
}
