#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
const int Mod = (1e9+7);
const int maxn = 5005;
int n;
int dp[maxn][maxn],lcp[maxn][maxn];
char s[maxn];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for (int i=n;i>=1;i--){
		for (int j=n;j>=1;j--){
			if (s[i] == s[j]) lcp[i][j] = lcp[i+1][j+1]+1; else
							  lcp[i][j] = 0;
		}
	}
	dp[1][1] = 1;
	for (int i=1;i<=n;i++){
		if (s[i] == '0') continue;
		for (int j=1;j<=n;j++)
			dp[i][j] =(dp[i][j] + dp[i][j-1]) % Mod;
		for (int j=i;j-i+1<=n-j;j++){
			if (s[j+1] == '0') continue;
			int t = lcp[i][j+1];
			if (t >= j-i+1){
				//i~j和(j+1 ~ (2*j-i+1)))这两段相同
				dp[j+1][2*j-i+2] = (dp[j+1][2*j-i+2] + dp[i][j]) % Mod;
			} else{
				if (s[i+t] < s[j+1+t]){
					dp[j+1][2*j-i+1] = (dp[j+1][2*j-i+1] + dp[i][j]) % Mod;
				}else{
					dp[j+1][2*j-i+2] = (dp[j+1][2*j-i+2] + dp[i][j]) % Mod;
				}
			}	
		}
	}
	ans = 0;
	for (int i=1;i<=n;i++){
		ans = (ans + dp[i][n]) % Mod;
	}
	printf("%d\n",ans);
	return 0;
}
