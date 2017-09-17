#include<cstdio>
#include<cmath>
#include<cstring>
bool f[100000005];
int b[100];
/*´ò±í³ÌÐò*/

bool hw(int x)
{
	memset(b,0,sizeof(b));
	int i=0;
	while (x>0)
	{
//		printf("%d %d\n",x,i);
		i++;
		b[i]=x % 10;
		x=x / 10; 
	}
	for (int j=1;j<=i;j++)
	{
		if (b[j]!=b[i-j+1]) return false;
	}
	return true;
}

int main()
{
	freopen("1.out","w",stdout);
	memset(f,true,sizeof(f));
	for (int i=2;i<=100000000;i++)
	{
		if (f[i])
		{
			int k=i*2;
			while (k<=100000000)
			{
				f[k]=false;
				k+=i;
			}
		}
	}
	int ans=0;
	for (int i=5;i<=100000000;i++)
	{
		if ((f[i]) && (hw(i)))
		{
			ans++;
			printf("ans[%d]=%d;\n",ans,i);
		}
	} 
	return 0;
}
