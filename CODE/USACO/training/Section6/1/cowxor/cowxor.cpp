/*
ID:cqz15311
LANG:C++
PROG:cowxor
*/
#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cstdlib>
struct Node{
	int nxt[2];
}tree[1<<20];
int n,m,sum[100500];
int Ans,Begin,End;
void clear(int x){
	memset(tree[x].nxt,-1,sizeof(tree[x].nxt));
}
void insert(int id){
	int p = 0;
	for (int i=20;i>=0;i--){
		int t = (sum[id] >> i) & 1;
		if (tree[p].nxt[t] == -1){
			tree[p].nxt[t] = ++m;
			clear(m);
		}
		p = tree[p].nxt[t];
	}
}
int get(int id){
	int p = 0,Ans = 0;
	for (int i=20;i>=0;i--){
		int t = (sum[id] >> i) & 1;
		if (tree[p].nxt[t ^ 1] != -1){
			p = tree[p].nxt[t ^ 1];
			Ans |= 1<<i;
		} else{
			if (tree[p].nxt[t] == -1) return Ans; else{
				p = tree[p].nxt[t];
			}
		}
	}
	return Ans;
}
int main(){
	freopen("cowxor.in","r",stdin);
	freopen("cowxor.out","w",stdout);
	m = 0;
	clear(0);
	scanf("%d",&n);
	sum[0] = 0;
	insert(0);
	Ans = -1;
	Begin = 0;
	End = 0;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		sum[i] = sum[i-1] ^ x;
		int tmp = get(i);
		if (tmp > Ans){
			Ans = tmp;
			End = i;
		}
		insert(i);
	}
	for (int j=End-1;j>=0;j--){
		if ((sum[j] ^ sum[End]) == Ans){
			Begin = j;
			break;
		}
	}
	printf("%d %d %d\n",Ans,Begin+1,End);
	return 0;
}
