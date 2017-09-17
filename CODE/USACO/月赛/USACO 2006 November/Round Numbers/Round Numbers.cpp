#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
int num[105],dp[50][50][50],L,Start,Finish;
int dfs(int len,int k,bool fp,int tl)
{
//	printf("%d %d %d %d\n",len,k,fp,tl);
	if (len==0) if ((k>=((tl+1)/2))) return 1; else return 0;
	
	if (fp)
	{
		if (tl==0) 
		{
			if (num[len]) return dfs(len-1,k,false,0)+dfs(len-1,k,true,len); else
						  return dfs(len-1,k+1,true,0);
		}
		else
		{
			if (num[len]) return dfs(len-1,k+1,false,tl)+dfs(len-1,k,true,tl); else
						  return dfs(len-1,k+1,true,tl);	
		}
	}
	else
	{
		if (dp[len][k][tl]!=-1) return dp[len][k][tl];
		
		if (tl==0)
		{
			dp[len][k][tl]=dfs(len-1,k,false,0)+
						   dfs(len-1,k,false,len);
		}
		else
		{
			dp[len][k][tl]=dfs(len-1,k+1,false,tl)+
						   dfs(len-1, k ,false,tl);
		}
		return dp[len][k][tl];
	}
}
int solve(int x)
{
	L=0;
	while (x)
	{
		L++;
		num[L]=x % 2;
		x=x / 2;
	}
	return dfs(L,0,true,0);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	//dp[i][j][k]表示二进制下长度为i，有至少超过j个0，第一个1在从右往左第k位出现的roundnumber的个数 
	scanf("%d%d",&Start,&Finish);
//	for (int i=0;i<=100;i++)
//	printf("%d %d\n",i,solve(i));
	printf("%d\n",solve(Finish)-solve(Start-1));
	return 0; 
}
