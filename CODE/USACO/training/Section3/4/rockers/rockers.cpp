/*

������ǣ�
����n,T,M
Ȼ��n�������Ĳ���ʱ�� 
Ҫ����ѡ��һЩ���� 
ʹ�ø��������Ĳ���ʱ��ŵ�M������
ÿ�����̵�����ʱ��ΪT��ע��
��һ��һ���ţ�һ������һ�����̷���ȥ��
���Ա�����
��DP[i,j]��ʾ
����ǰi����Ƭ����ǰ������i������i������j���� 
DP[i,0]��ʾǰi-1����Ƭ���ܹ���õ������� 
DP[i,j + x] = DP[i,j] + 1;
������ DP[i+1,0] = max(dp[i+1,0],dp[i,j + x])
������ ANS 
//����ܹ����� 
������ܷ��£��Ǿ����ˣ������� 

��ҿ��Բο��� 
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
		}//��ֹ�ظ� 
	}
	printf("%d\n",ans); 
}
