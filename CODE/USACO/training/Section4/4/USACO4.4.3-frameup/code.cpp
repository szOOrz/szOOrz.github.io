/*
ID:cqz15311
LANG:C++
PROG:frameup
*/
#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int from,to,nxt;
}edge[31*31*31*31];
//邻接矩阵就行了，我是不是太浪费了 
int first[255];
int H,W,In[255],nume,Len;
char a[31][31];
bool find(char x){
	for (int i=0;i<H;i++){
		for (int j=0;j<W;j++){
			if (a[i][j] == x) return true;
		}
	}
	return false;
}
void add_edge(int a,int b){
//	printf("%c-->%c\n",a,b);
//	if (b == 'E') printf("ADDing%c\n",a);
	edge[nume] . from = a;
	edge[nume] . to = b;
	edge[nume] . nxt = first[a];
	first[a] = nume++;
	In[b]++;
}


int cnt;
bool vis[255];
char ans[255];
bool found[255];
void dfs(int x){
	if (x == Len+1){
		for (int i=1;i<=Len;i++) putchar(ans[i]);
		puts("");
		return ;
	}
	for (int i='A';i<='Z';i++){
		if (found[i] && !vis[i] && In[i] == 0){
			vis[i] = true;
			ans[x] = i;
			for (int e=first[i];e!=-1;e=edge[e].nxt) In[edge[e].to]--;
			dfs(x+1);
			for (int e=first[i];e!=-1;e=edge[e].nxt) In[edge[e].to]++;
			vis[i] =false;
			ans[x] = -1;
		}
	}
	//一位一位按照字典序枚举，得到一个解就输出，是满足字典序的。 
}

int main(){
	freopen("frameup.in","r",stdin);
	freopen("frameup.out","w",stdout);
	scanf("%d%d",&H,&W);
	for (int i=0;i<H;i++){
		scanf("%s",&a[i]);
	}
	nume = 0;
	Len = 0;
	memset(found,false,sizeof(found));
	memset(first,-1,sizeof(first));
	for (int c='A';c<='Z';c++){
		if (find(c)){//可能不连续，所以要判断c是否存在 
			found[c] = true;
			Len++;
			int L,R,U,D;
			L = W;
			R = -1;
			U = H;
			D = -1;
			for (int i=0;i<H;i++)
				for (int j=0;j<W;j++)
					if (a[i][j] == c)
						L = min(L,j),R = max(R,j),U = min(U,i),D = max(D,i);
			for (int i=L;i<=R;i++){
				if (a[U][i] != '.' && a[U][i] != c)	add_edge(c,a[U][i]);
				if (a[D][i] != '.' && a[D][i] != c) add_edge(c,a[D][i]);
			}
			for (int i=U;i<=D;i++){
				if (a[i][L] != '.' && a[i][L] != c)	add_edge(c,a[i][L]);
				if (a[i][R] != '.' && a[i][R] != c)	add_edge(c,a[i][R]);
			}
			//注意不能自己向自己连边 
		}
	}
	memset(vis,false,sizeof(vis));
	dfs(1);	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
