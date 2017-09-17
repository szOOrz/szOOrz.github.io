/*
如果n是2的倍数，似乎就是个裸的贪心。
可是如果不是，似乎做不来了。。
贪心的想法 好像是错的。
但是可以用DP解！
不妨用dp[i,j]表示当前(i,j)这一段区间，先手-后手的得分 
显然
dp[i,j]可以从dp[i+1,j]和dp[i,j-1]转移
dp[i,j] = max(a[i] - dp[i+1,j],a[j] - dp[i,j-1]);
预先得到最终先手+后手的得分S
解一个2元一次方程组——名字好有趣。 
USER: Jack Chen [cqz15311]
TASK: game1
LANG: C++

Compiling...
Compile: OK

Executing...
   Test 1: TEST OK [0.000 secs, 4216 KB]
   Test 2: TEST OK [0.000 secs, 4216 KB]
   Test 3: TEST OK [0.000 secs, 4216 KB]
   Test 4: TEST OK [0.000 secs, 4216 KB]
   Test 5: TEST OK [0.000 secs, 4216 KB]
   Test 6: TEST OK [0.000 secs, 4216 KB]
   Test 7: TEST OK [0.000 secs, 4216 KB]
   Test 8: TEST OK [0.000 secs, 4216 KB]
   Test 9: TEST OK [0.000 secs, 4216 KB]
   Test 10: TEST OK [0.000 secs, 4216 KB]
   Test 11: TEST OK [0.000 secs, 4216 KB]
   Test 12: TEST OK [0.000 secs, 4216 KB]
   Test 13: TEST OK [0.000 secs, 4216 KB]
   Test 14: TEST OK [0.000 secs, 4216 KB]
   Test 15: TEST OK [0.000 secs, 4216 KB]
   Test 16: TEST OK [0.000 secs, 4216 KB]

All tests OK.
YOUR PROGRAM ('game1') WORKED FIRST TIME!  That's fantastic
-- and a rare thing.  Please accept these special automated
congratulations.

*/ 
/*
ID:cqz15311
LANG:C++
PROG:game1
*/
#include<cstdio>
#include<algorithm>
using namespace std;
int n,dp[105][105],a[105],sum;
int main(){
	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum = sum + a[i];
		dp[i][i] = a[i];
	}
	for (int len=2;len<=n;len++){
		for (int i=1;i<=n-len+1;i++){
			int j = i + len - 1;
			dp[i][j] = max(a[i] - dp[i+1][j],a[j] - dp[i][j-1]);
		}
	}
	printf("%d %d\n",(dp[1][n] + sum) / 2,(sum - dp[1][n]) / 2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
