#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cstdlib>
struct Node{
	int nxt[2];
};
void clear(int x){
	memset(tree[x].nxt,-1,sizeof(tree[x].nxt));
}
void insert(int x,int id){
	p = 0;
	for (int i=21;i>=0;i--){
		t = (x >> i) & 1;
		if (tree[p].nxt[t] == -1){
			tree[p].nxt[t] = ++m;
			clear(m);
		}
		p = tree[p].nxt[t];
	}
	tree[p].val = id;
}
int getval()
int main(){
	m = 0;
	clear(0);
	scanf("%d",&n);
	sum = 0;
	insert(0,0);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		sum = sum ^ x;
		Ans = max(Ans,get(sum));
		insert(sum,i);
	}
}
