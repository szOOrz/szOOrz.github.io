#include <iostream>
#include <cstring>
int n,ans,num,shed[50];
void dfs(int i,int j,int fuhao_before)
{
	if (i==n)
	{
		num+=j*fuhao_before;		
		if (num==0)
		{
			if (ans<20)
			{
				for (int k=1;k<n;k++)
				{
					 printf("%d ",k);
					 if (shed[k]==1) printf("+ ");
					 if (shed[k]==2) printf("- ");
					 if (shed[k]==3) printf(". ");
				}
			printf("%d\n",n);
			}
			ans++;
		}
//		printf("%d\n",num);
		num-=j*fuhao_before;
		return ;
	}
	num+=j*fuhao_before;
	shed[i]=1;
	dfs(i+1,i+1,1);
	shed[i]=2;
	dfs(i+1,i+1,-1);
	num-=j*fuhao_before;
	shed[i]=3;
	if (i+1>=10) dfs(i+1,j*100+(i+1),fuhao_before);else dfs(i+1,j*10+(i+1),fuhao_before);
}
int main()
{
	scanf("%d",&n);
	memset(shed,0,sizeof(shed));
	ans=0;
	num=0;
	dfs(1,1,1);
	printf("%d",ans);
	return 0;
}
