/*
ID:cqz15311
PROG:runround
LANG:C++
*/
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
bool flag[20];
int a[20],i,temp,j,t,n;
bool check(int x)
{
	int i;
	j=0;
	memset(flag,0,sizeof(flag)); 
	while (x>0)
	{
		j++;
		a[j]=x % 10;
		if (flag[a[j]]) return false;
		flag[a[j]]=true;
		x=x/10;
	}
	i,temp=j/2; 
	for (i=1;i<=temp;i++)
	{
		t=a[i];
		a[i]=a[j-i+1];
		a[j-i+1]=t;
	}
//	puts("*");
//	for (int i=1;i<=j;i++) printf("%d\n")
//	puts("*");
//	printf("%d\n",j);
	memset(flag,0,sizeof(flag));
	int count;
	for (i=1,count=0;count<j;count++)
	{
//		printf("%d->",i);
		i=(i+a[i]-1)%j+1;
		if (flag[i]) return false;
		flag[i]=true; 
	} 
	if (i==1) return true; else return false;
	
}
int main()
{
	freopen("runround.in","r",stdin);
	freopen("runround.out","w",stdout);
	scanf("%d",&n);
	for (int i=n+1;i<=99999999;i++)
	{
//		printf("%d",i);
//		system("pause");
		if (check(i))
		{
			printf("%d\n",i);
			break;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
