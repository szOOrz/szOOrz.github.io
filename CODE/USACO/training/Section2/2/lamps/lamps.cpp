
/*
ID:cqz15311
PROG:lamps
LANG:C++
*/
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
int n,c,x,f[10],light[10],ans[999],l1,l2,l3,l4,cc;
bool find,could; 

int willwrite[10];
void write(int x)
{
	
	for (int k=1;k<=6;k++)
	{
		willwrite[7-k]=x % 10;
		x=x / 10;
	}
	for (int i=1;i<=n;i++)
	{
		putchar(willwrite[(i-1) % 6 + 1]+'0');
	}
	puts("");
}
int main()
{
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&c);
	scanf("%d",&x);

	find=false;
	 
	memset(f,0,sizeof(f));

	while (x!=-1)
	{
		f[(x-1) % 6 + 1]=1;//ÁÁ×ÅµÄ
		scanf("%d",&x);  
	}
	scanf("%d",&x); 
	
	
	while (x!=-1)
	{
		if (f[(x-1) % 6 + 1]==1) 
		{
			puts("IMPOSSIBLE");
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		f[(x-1) % 6 + 1]=-1;//°µµÄ 
		scanf("%d",&x);  
	}

	ans[0]=0;
	for (l1=0;l1<=1;l1++)
	for (l2=0;l2<=1;l2++)
	for (l3=0;l3<=1;l3++)
	for (l4=0;l4<=1;l4++)
	{
		for (int i=1;i<=6;i++) light[i]=1;
		cc=l1+l2+l3+l4;
		if ((cc>c) || ((c-cc) & 1)) continue;
		if (l1)
		{
			for (int i=1;i<=6;i++) light[i]=light[i]^1;
		}
		if (l2)
		{
			for (int i=1;i<=3;i++) light[i*2-1]=light[i*2-1] ^ 1;
		}
		if (l3)
		{
			for (int i=1;i<=3;i++) light[i*2]=light[i*2] ^ 1;
		}
		if (l4)
		{
			for (int i=1;i<=2;i++) light[i*3-2]=light[i*3-2] ^ 1;
		}
		could=true;
		for (int i=1;i<=6;i++)
		{
			if ((f[i]==1) && (light[i]!=1)) could=false;
			if ((f[i]==-1) && (light[i]!=0)) could=false;
		}
		if (could)
		{
//			printf("%d %d %d %d\n",l1,l2,l3,l4);
			++ans[0];
			ans[ans[0]]=0;
			for (int i=1;i<=6;i++)
			{
				ans[ans[0]]*=10;
				ans[ans[0]]+=light[i];
			}
			find=true;
		}
	}
	if (!find) puts("IMPOSSIBLE");
	else
	{
//		printf("%d\n",ans[0]);
		std::sort(ans+1,ans+1+ans[0]);
		for (int i=1;i<=ans[0];i++)
		{
			write(ans[i]);
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
