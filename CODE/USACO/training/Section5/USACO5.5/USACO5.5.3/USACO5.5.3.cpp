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
	//����֮��ö�ٵ�k�ǵ����ģ����ֻҪ������Ѿ�ȷ���Ĵ������ 
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
�����ȿ���N�����
����һ������һ�����ӵ������֡�����ôӦ����дʲô���ֵģ�
�������ǵõ���ǰ��д����A��֮����������a 
				��д����B��֮����������b
				��д����C��֮����������c 
���������Ҫ�õ��Ĵ��ڣ����ڣ�a��С��b����ô��ȻӦ����дa 
	�����Ҫ�õ��Ĵ��ڣ����ڣ�b��С��c����ô��ȻӦ����дc 
�����ô�������dfs������������
������Dp[a,b,c,d,e]�ֱ��ʾ��1��~��5��������Щ����
����a<=b<=c<=d<=e 
��ô�����赱ǰҪ��д��k
�����k�Ѿ�����д���ˣ���ô������д��һ��k 
����ȵ�ǰ�е�Ҫ�󣬱ȵ�ǰ�е�Ҫ���λ�ö��ǿ����Եġ�
�õ�һ�����仯DFS�Ĺ��̡�
һλһλȷ�����ܵõ����
��ôW��ʵ��NҪ�򵥶��ˡ�
	ֻ��Ҫ���Ǳ����С���ж��٣�Ҳ��һλһλȷ���������ǰλ����д�ȵ�ǰС�ģ��ܹ���ö������档
ע�������1~5����Ҫ��������[5]������[6]��ֹԽ�硣
�ٶȺܿ죬����0ms 
*/
