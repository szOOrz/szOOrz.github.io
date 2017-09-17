/*
ID:cqz15311
PROG:fracdec
LANG:C++
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
/*
模拟手算，加上余数记录，如果余数相同，那么就表示循环了。 
*/
const int dx[4]={-1,0,1, 0};
const int dy[4]={ 0,1,0,-1};
bool F[10][10][10][10][4][4],found;
int step,map[10][10];
int a,b,R[100050],r,val;
int ans[100050],w;
int o;
void write(char k)
{
	putchar(k);
	o++;
	if (o%76==0) puts("");
}
int main()
{
	 freopen("fracdec.in","r",stdin);
	 freopen("fracdec.out","w",stdout);
	 scanf("%d %d",&a,&b);
	 int x=a/b;
	 o=0;
	 if (x==0) o++;
	 while (x>0)
	 {
	 	o++;
	 	x/=10;
	 }
	 printf("%d",a/b);
	 memset(R,0,sizeof(R));
	 w=0;
	 r=a % b;
	 if (r!=0)
	 {
	 write('.');
	 while (!R[r])
	 {
	 	R[r]=++w;
	 	r=r*10;
	 	val=r / b;
	 	r=r-val*b;
	 	ans[w]=val;
	// 	printf("*%d*%d*\n",r,val);
	 }
	 for (int i=1;i<=w;i++)
	 {
	 	if ((i==R[r]) && (r!=0))
		 	write('(');
	 	if (i!=w) write(ans[i]+'0');
	 }
	 if (r!=0) write(ans[w]+'0'),write(')');
	 }
	 else
	 {
		write('.');
		write('0');
	 }
	 puts("");
	 fclose(stdin);
	 fclose(stdout);
	 return 0;
}
