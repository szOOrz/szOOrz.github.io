/*

题意就是：
给定n,T,M
然后n个歌曲的播放时间 
要从中选出一些歌曲 
使得各个歌曲的播放时间放到M个光盘
每个光盘的容量时间为T，注意
得一个一个放，一个光盘一个光盘放上去。
可以暴力。
用DP[i,j]表示
处理前i个唱片，当前处理到第i个，第i个用了j分钟 
DP[i,0]表示前i-1个唱片，能够获得的最大歌曲 
DP[i,j + x] = DP[i,j] + 1;
并更新 DP[i+1,0] = max(dp[i+1,0],dp[i,j + x])
并更新 ANS 
//如果能够放下 
如果不能放下，那就算了，不放了 

大家可以参考： 
http://train.usaco.org/usacoanal2?a=Q1IQssZeui7&S=rockers
// 
*/ 
/*
ID:cqz15311
LANG:C++
PROG:rockers
*/
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int N,T,M,ans,x,dp[26][26];
int main(){
	freopen("rockers.in","r",stdin);
	freopen("rockers.out","w",stdout);
	scanf("%d%d%d",&N,&T,&M);
	memset(dp,-1,sizeof(dp));
	dp[1][0] = 0; ans = 0;
	while (N--){
		scanf("%d",&x);
		for (int i=M;i>=1;i--){
			for (int j=T-x;j>=0;j--){
				if ((dp[i][j] >= 0) && (dp[i][j+x] < dp[i][j] + 1)){
					dp[i][j+x] = dp[i][j] + 1;
					if (dp[i][j+x]>dp[i+1][0]) dp[i+1][0]=dp[i][j+x];  
					if (dp[i][j+x]>ans) ans=dp[i][j+x]; 
				}
			}
		}//防止重复 
	}
	printf("%d\n",ans); 
}
