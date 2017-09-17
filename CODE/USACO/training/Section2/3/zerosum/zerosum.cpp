/*
ID:cqz15311
PROG:zerosum
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
char x[15];
int val,n;

int check()
{
	char pre_fh='+';
	int val=0;
	int t=1;
	for (int i=2;i<=n;i++)
	{
		if (x[i-1]==' ') t=t*10+i;
		if ((x[i-1]=='+') || (x[i-1]=='-'))
		{
			if (pre_fh=='+') val=val+t;
			if (pre_fh=='-') val=val-t;
			pre_fh=x[i-1];
			t=i;
		}
	}
			if (pre_fh=='+') val=val+t;
			if (pre_fh=='-') val=val-t;
	return val;
	
}

void dfs(int i)
{
	if (i==n)
	{
		if (check()==0)
		{
			putchar('1');
			for (int i=2;i<=n;i++)
			{
				putchar(x[i-1]);
				putchar(i+'0');
			}
			puts("");
		}
		return ;
	}
	x[i]=' ';
	dfs(i+1);
	x[i]='+';
	dfs(i+1);
	x[i]='-';
	dfs(i+1);
}
int main()
{
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	memset(x,0,sizeof(x));
	scanf("%d",&n);
	val=0;
	dfs(1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
