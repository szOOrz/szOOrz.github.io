/*
ID:cqz15311
PROG:milk3
LANG:C++
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using std::min;
using std::sort;
int f[25][25],qa[25*25],qb[25*25],front,rear,ans[25*25],sum;
int A,B,C,a,b,c;
void push(int x,int y)
{
	if (f[x][y]) return ;
	if (x==0)
	{
		ans[++ans[0]]=sum-x-y;
	}
	qa[rear]=x;
	qb[rear]=y;
	f[x][y]=true;
	rear++;
}
int main()
{
	freopen("milk3.in","r",stdin);
	freopen("milk3.out","w",stdout);
	scanf("%d%d%d",&A,&B,&C);
	sum=C;
	front=rear=0;
	memset(f,0,sizeof(f));
	ans[0]=0;
	push(0,0);
	while (front<rear)
	{
		a=qa[front];
		b=qb[front];
		c=sum-a-b;
//		printf("%d %d %d\n",a,b,c);
		front++;
		push(a-min(a,B-b),b+min(a,B-b));//a->b
		push(a-min(a,C-c),b);//a-->c
		push(a+min(b,A-a),b-min(b,A-a));//b-->a
		push(a,b-min(b,C-c));//b-->c
		push(a+min(c,A-a),b);//c-->a
		push(a,b+min(c,B-b));//c-->b
	}
	sort(ans+1,ans+1+ans[0]);
	printf("%d",ans[1]);
	for (int i=2;i<=ans[0];i++)
	{
		printf(" %d",ans[i]);
	}
	puts("");
	return 0;
}
