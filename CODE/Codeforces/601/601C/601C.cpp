#include<bits/stdc++.h>
using namespace std;
const int maxn = 101;
const int maxm = 1010;
int n,m,s,a[maxn];
double dp[maxn*maxm],dpp[maxn*maxm];
int main(){
	scanf("%d%d",&n,&m);
	s = 0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s+=a[i];
	}
	if (m == 1){
		puts("1");
		return 0;
	}
	memset(dp,0,sizeof(dp));
	dp[0] = m-1;
	for (int i=1;i<=n;i++){
		memset(dpp,0,sizeof(dpp));
		for (int j=0;j<=n*m;j++){
			double p = dp[j] / (m-1);
			dpp[j+1] += p;
			dpp[j+m+1] -= p;
			dpp[j+a[i]] -= p;
			dpp[j+a[i]+1] += p;
		}
		dp[0] = dpp[0];
		for (int j=1;j<=n*m;j++)
			dpp[j] += dpp[j-1],dp[j] = dpp[j];
	}
	double ans = 0;
	for (int j=0;j<s;j++) ans += dp[j];
	printf("%.12lf\n",ans+1.0);
	return 0;
}
/*
��s=a[1]+a[2]+��+a[n]����֪������˵�����������ֻ��Ҫ֪��n������������m-1����������������s�������������ɣ���Ϊÿ��������������������ָ�����ͬ����������m-1���˶���һ���ģ���һ���˼��ɣ���dp[i][j]��ʾi����������m-1������������j������������dp[0][0]=m-1��ʾ��û����ʱ������0����������������m-1���ˣ��ڵ�i��������m-1���˵��������ȸ���ȡ1~m�г�a[i]��m-1����������ת�Ʒ���dp[i][j]=sum{dp[i-1][j-k],1<=k<=m,k!=a[i]}/(m-1)����ǰ׺���Ż��¸�ת�ƣ�dp[i-1][k]������[dp[i][k+1],dp[i][k+m]]��ȥdp[i][k+a[i]]��Ĺ��׶���dp[i-1][k]/(m-1)������ÿ���ڶ˵㴦���������һ��ǰ׺�ͼ����һ��ת�ƣ����մ𰸾���dp[n][1]+��+dp[n][s-1]+1����Ϊ���˵�����Ҫ����Щ��������ǰ���˺���һ�� 
*/
