#include<bits/stdc++.h>
using namespace std;
const int Mod = 1e9+7;
int dp[27],Ans,last[27];
char t[1000005];
int n,m,K,sum;
int main(){
	scanf("%d%d%s",&n,&K,t);
	m = strlen(t);
	for (int i=0;i<K;i++){
		dp[i] = 0;
		last[i] = -1;
	}
	sum = 0;
	for (int i=0;i<m;i++){
		last[t[i]-'a'] = i;
		int tmp = dp[t[i] - 'a'];
		dp[t[i] - 'a'] = (sum+1) % Mod;
		sum = (((sum * 2) + 1 - tmp) % Mod + Mod) % Mod;
	}
	for (int i=0;i<n;i++){
		int ptr = -1;
		for (int j=0;j<K;j++){
			if ((ptr == -1) || (last[j] < last[ptr])) ptr = j;
		}
		int tmp = dp[ptr];
		dp[ptr]  = (sum+1) % Mod;
		sum=(((sum*2)+1-tmp) % Mod + Mod) % Mod;
		last[ptr] = m+i;
	}
	Ans = 0;
	for (int i=0;i<K;i++)
		Ans = (Ans + dp[i]) % Mod;
	printf("%d\n",Ans+1);
}
