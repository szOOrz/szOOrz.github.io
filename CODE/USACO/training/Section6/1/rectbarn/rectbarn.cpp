/*
ID:cqz15311
LANG:C++
PROG:rectbarn
我竟然把i&1打成了i^1，找了半个小时. 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
const int maxn = 3005;
int up[2][maxn],r,c,P,x,y;
int top,stack[maxn],Ans;
int L[maxn],R[maxn];
vector<int> p[maxn];
int main(){
	freopen("rectbarn.in","r",stdin);
	freopen("rectbarn.out","w",stdout);
	scanf("%d%d%d",&r,&c,&P);
	while (P--){
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
	}
	for (int i=1;i<=c;i++) up[0][i] = 0;
	for (int i=1;i<=r;i++){
		for (int j=1;j<=c;j++) up[i&1][j] = up[(i-1)&1][j]+1;
		for (int j=0;j<(int)p[i].size();j++) up[i&1][p[i][j]] = 0;
		up[i&1][c+1] = -1;
		top = 0;
		for (int j=1;j<=c+1;j++){
			while (top > 0 && up[i&1][stack[top]] > up[i&1][j])	R[stack[top--]] = j-1;
			stack[++top] = j;
		}
		up[i&1][0] = -1;
		top = 0;
		for (int j=c;j>=0;j--){
			while (top>0 && up[i&1][stack[top]] > up[i&1][j]) L[stack[top--]] = j+1;
			stack[++top] = j;
		}
		for (int j=1;j<=c;j++){
			Ans = max(Ans,up[i&1][j] * (R[j] - L[j] + 1));
//			printf("%d %d :%d %d\n",i,j,R[j],L[j]);
		}
//		printf("%d\n",c);
	}
	printf("%d\n",Ans);
	return 0;
}
