/*
ID:cqz15311
PROG:palsquare
LANG:C++
*/
#include<cstdio>
#include<cstring>
int b[50],x,B;
void print(int x)
{
	if (x<=9) putchar(x+'0'); else putchar(x+'A'-10);
}
bool could(int x)
{
	memset(b,0,sizeof(b));
	int i=0;
	while (x>0)
	{
//		printf("%d %d\n",x,i);
		i++;
		b[i]=x % B;
		x=x / B; 
	}
	for (int j=1;j<=i;j++)
	{
		if (b[j]!=b[i-j+1]) return false;
	}
	return true;
}
void pt(int x)
{
	memset(b,0,sizeof(B));
	int i=0;
	while (x>0)
	{
		i++;
		b[i]=x % B;
		x=x / B; 
	}
	while (i)
	{
		print(b[i]);
		i--;
	}
}
int main()
{
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout); 
	scanf("%d",&B);
	for (int i=1;i<=300;i++)
	{
		if (could(i*i)){
			pt(i);
			printf(" ");
			pt(i*i);
			puts("");
		}
	}
} 
