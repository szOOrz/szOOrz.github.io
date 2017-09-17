#include<bits/stdc++.h> 
using namespace std;
const int maxn = 500005;
int type,v,father[maxn],son[maxn];
const int maxH = 80;
double dp[maxn][82];
int q,cnt;
int main(){
	scanf("%d",&q);
	father[1] = -1;
	cnt = 1;
	son[1] = 0;
	for (int i=0;i<maxH;i++) dp[1][i] = 1.0;
	for (int i=1;i<=q;i++){
		scanf("%d%d",&type,&v);
		if (type == 1){
			cnt++;
			for (int i=0;i<maxH;i++) dp[cnt][i] = 1.0;
			father[cnt] = v;
			son[v]++;
			son[cnt] = 0;
			double pre = dp[v][0];
			dp[v][0] = pow(0.5,son[v]);
			int u = v; 
			for (int h=1;h<maxH && father[u]!=-1;h++,u=father[u]){
				double tmp = dp[father[u]][h];
				dp[father[u]][h] /= 0.5 + 0.5 * pre;
				dp[father[u]][h] *= 0.5 + 0.5 * dp[u][h-1];
				pre = tmp;
			}
		} else{
			double Ans = 0;
			for (int h=1;h<maxH;h++){
				Ans = Ans + h * (dp[v][h] - dp[v][h-1]); 
			}
			printf("%.10lf\n",Ans);
		}
	}
}
