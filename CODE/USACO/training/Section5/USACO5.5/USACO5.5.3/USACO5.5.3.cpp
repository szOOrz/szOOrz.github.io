/*
ID:cqz15311
LANG:C++
PROG:twofive
*/
#include<bits/stdc++.h>
using namespace std;
int maxr[8],maxc[8],Ans[8][8],used[7*7],dp[7][7][7][7][7];
int dfs(int a,int b,int c,int d,int e,int k){
	if (~dp[a][b][c][d][e]) return dp[a][b][c][d][e];
	int rec = 0;
	if (used[k]) return dfs(a,b,c,d,e,k+1);
	if (a+1<=5 && maxr[1]<k && maxc[a+1]<k) rec+=dfs(a+1,b,c,d,e,k+1);
	if (b+1<=a && maxr[2]<k && maxc[b+1]<k) rec+=dfs(a,b+1,c,d,e,k+1);
	if (c+1<=b && maxr[3]<k && maxc[c+1]<k) rec+=dfs(a,b,c+1,d,e,k+1);
	if (d+1<=c && maxr[4]<k && maxc[d+1]<k) rec+=dfs(a,b,c,d+1,e,k+1);
	if (e+1<=d && maxr[5]<k && maxc[e+1]<k) rec+=dfs(a,b,c,d,e+1,k+1);
	//考虑之后枚举的k是递增的，因此只要满足比已经确定的大就行了 
	return dp[a][b][c][d][e] = rec;
}
void solveN(){
	int len[8],N;
	memset(len,0,sizeof(len));
	memset(used,false,sizeof(used));
	memset(maxr,0,sizeof(maxr));
	memset(maxc,0,sizeof(maxc));
	scanf("%d",&N);
	for (int i=1;i<=5;i++){
		for (int j=1;j<=5;j++){
			len[i]++;
			for (int k=1;k<=25;k++){
				if (!used[k] && k>maxr[i] && k>maxc[j]){
					used[k] = true;
					memset(dp,-1,sizeof(dp));
					dp[5][5][5][5][5] = 1;
					int tmp = dfs(len[1],len[2],len[3],len[4],len[5],1);
					maxr[i] = k;
					maxc[j] = k;
					if (tmp >= N){
						Ans[i][j] = k;
						break;
					}
					used[k] =false;
					N -= tmp;
				}
			}
		}
	}
	for (int i=1;i<=5;i++){
		for (int j=1;j<=5;j++){
			printf("%c",Ans[i][j]-1+'A');
		}
	} 
}

void solveW(){
	char s[30];
	int len[8],Ans;
	memset(len,0,sizeof(len));
	memset(maxr,0,sizeof(maxr));
	memset(maxc,0,sizeof(maxc));
	memset(used,false,sizeof(used));
	scanf("%s",s+1);
	Ans = 0;
	for (int i=1;i<=5;i++){
		for (int j=1;j<=5;j++){
			len[i]++;
			int t = (i-1)*5+j;
			for (int k=1;k<s[t] - 'A' + 1;k++){
				if (used[k] || maxr[i] > k || maxc[j] > k) continue;
				used[k] = true;
				memset(dp,-1,sizeof(dp));
				dp[5][5][5][5][5] = 1;
				int tmp1 = maxr[i];maxr[i] = k;
				int tmp2 = maxc[j];maxc[j] = k;
				Ans += dfs(len[1],len[2],len[3],len[4],len[5],1);
				maxr[i] = tmp1;
				maxc[j] = tmp2;
				used[k] = false;
			}
			maxr[i] = s[t]-'A'+1;
			maxc[j] = s[t]-'A'+1;
			used[s[t] - 'A' + 1] = true;
		}
	}
	printf("%d",Ans+1);
}

int main(){
	freopen("twofive.in","r",stdin);
	freopen("twofive.out","w",stdout);
	memset(dp,-1,sizeof(dp));
	dp[5][5][5][5][5] = 1;
	char type;
	type = getchar();
	while (type!='N' && type!='W') type = getchar(); 
	if (type == 'N') solveN(); else
					 solveW();
	puts("");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
我们先考虑N的情况
考虑一个格子一个格子的填数字——那么应该填写什么数字的？
假设我们得到当前填写数字A，之后的总情况是a 
				填写数字B，之后的总情况是b
				填写数字C，之后的总情况是c 
考虑如果我要得到的大于（等于）a，小于b，那么显然应该填写a 
	如果我要得到的大于（等于）b，小于c，那么显然应该填写c 
可以用带备忘的dfs求出上述结果。
考虑用Dp[a,b,c,d,e]分别表示第1行~第5行填了哪些数。
满足a<=b<=c<=d<=e 
那么，假设当前要填写数k
如果数k已经被填写过了，那么考虑填写下一个k 
满足比当前行的要大，比当前列的要大的位置都是可行性的。
得到一个记忆化DFS的过程。
一位一位确定就能得到结果
那么W其实比N要简单多了。
	只需要考虑比这个小的有多少，也是一位一位确定，如果当前位置填写比当前小的，能够获得多少收益。
注意如果是1~5，不要开到数组[5]，至少[6]防止越界。
速度很快，都是0ms 
*/
