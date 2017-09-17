#include<cstdio>
#include<cstring>
#include<cmath>
struct Q{
	int val,date;
}q[255]; 
int n,B,K,a[255][255],front,rear;
int f1[255][255],max[255][255],f2[255][255],min[255][255];
int l,r;
int main()
{
	scanf("%d%d%d",&n,&B,&K);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++) scanf("%d",&a[i][j]);
	for (int i=0;i<n;i++)
	{
		front=0;rear=0;		
		for (int j=0;j<n;j++)
		{
//			for (int t=front;t<rear;t++) printf("%d ",q[t].val);puts("");
			while ((front<rear) && (j-q[front].date>=B)) front++;
			while ((front<rear) && (q[rear-1].val<=a[i][j])) rear--;
			q[rear].val=a[i][j];
			q[rear].date=j;
			rear++;
			if (j-B+1>=0) f1[i][j-B+1]=q[front].val;
		}
	}//先求大的每排
	for (int j=0;j<n-B+1;j++)
	{
		front=0;rear=0;
		for (int i=0;i<n;i++)
		{
			while ((front<rear) && (i-q[front].date>=B)) front++;
			while ((front<rear) && (q[rear-1].val<=f1[i][j])) rear--;
			q[rear].val=f1[i][j];
			q[rear].date=i;
			rear++;
			if (i-B+1>=0) max[i-B+1][j]=q[front].val;
		}
	}//求出二维的大的
	for (int i=0;i<n;i++)
	{
		front=0;rear=0;		
		for (int j=0;j<n;j++)
		{
	//		for (int t=front;t<rear;t++) printf("%d ",q[t].val);puts("");
			while ((front<rear) && (j-q[front].date>=B)) front++;
			while ((front<rear) && (q[rear-1].val>=a[i][j])) rear--;
			q[rear].val=a[i][j];
			q[rear].date=j;
			rear++;
			if (j-B+1>=0) f2[i][j-B+1]=q[front].val;
		}
	}//先求小的每排
	for (int j=0;j<n-B+1;j++)
	{
		front=0;rear=0;
		for (int i=0;i<n;i++)
		{
			while ((front<rear) && (i-q[front].date>=B)) front++;
			while ((front<rear) && (q[rear-1].val>=f2[i][j])) rear--;
			q[rear].val=f2[i][j];
			q[rear].date=i;
			rear++;
			if (i-B+1>=0) min[i-B+1][j]=q[front].val;
		}
	}//求出二维的小的
	for (int i=0;i<K;i++)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",max[l-1][r-1]-min[l-1][r-1]);
	}
	return 0;
}
/*
5 3 1
5 1 2 6 3
1 3 5 2 7
7 2 4 6 1
9 9 8 6 5
0 6 9 3 9
1 2
*/
