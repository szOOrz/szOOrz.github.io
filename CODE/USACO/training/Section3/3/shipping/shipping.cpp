/*
ID:cqz15311
LANG:C++
PROG:shopping
*/
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;
int s,cc,kk,dp[6][6][6][6][6],pp[6],t[6],c[206][6],p[206];
int nn[6],tt;
int ord(int x){
	for (int i=1;i<=tt;i++){
		if (x == nn[i]) return i;
	}
	tt++;
//	printf("nn[%d] = %d\n",tt,x);
	nn[tt] = x;
	return tt;
}
int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	scanf("%d",&s);
	memset(c,0,sizeof(c));
	tt = 0;
	for (int i=1;i<=s;i++){
		int n,cc,kk;
		scanf("%d",&n);
		for (int j=1;j<=n;j++){
			scanf("%d%d",&cc,&kk);
			c[i][ord(cc)] = kk;
		}
		scanf("%d",&p[i]);
//		puts("************");
	}
	int b;
	scanf("%d",&b);
	for (int i=1;i<=b;i++){
		int cc;
		scanf("%d",&cc);
		scanf("%d%d",&t[ord(cc)],&pp[ord(cc)]);
		s++;
		p[s] = pp[ord(cc)];
		c[s][ord(cc)] = 1;
	}
	for (int i1=0;i1<=t[1];i1++)
		for (int i2=0;i2<=t[2];i2++) 
			for (int i3=0;i3<=t[3];i3++)
				for (int i4=0;i4<=t[4];i4++)
					for (int i5=0;i5<=t[5];i5++){
						dp[i1][i2][i3][i4][i5] = i1 * pp[1] + i2 * pp[2] + i3 * pp[3] + i4 * pp[4] + i5 * pp[5];
						for (int i=1;i<=s;i++){
//							printf("*%d %d %d*\n",i,p[i],c[i][1]);
							int t1 = i1 - c[i][1];
							int t2 = i2 - c[i][2];
							int t3 = i3 - c[i][3];
							int t4 = i4 - c[i][4];
							int t5 = i5 - c[i][5];
							if ((t1 >= 0) && (t2 >= 0) && (t3 >= 0) && (t4 >= 0) && (t5 >= 0))
								dp[i1][i2][i3][i4][i5] = min(dp[i1][i2][i3][i4][i5],dp[t1][t2][t3][t4][t5] + p[i]);
						}
//						printf("dp[%d][%d][%d][%d][%d] = %d\n",i1,i2,i3,i4,i5,dp[i1][i2][i3][i4][i5]);
					}
	printf("%d\n",dp[t[1]][t[2]][t[3]][t[4]][t[5]]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}



