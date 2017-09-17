#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>


int queueX[1800005],queueY[1800005],queueT[1800005];
int xx,yy;
int found;
long n,front,rear,k;
bool flag[40005][205];


inline int min(int x,int y){if (x<y) return x;else return y;}
inline void doo(int t,int x,int y)
{
	int xx=x;
	int yy=y;
	if (xx<yy){int temp=xx;xx=yy;yy=temp;}
	if ((xx>=0) and (yy>=0) and (xx<=40000) and (yy<=200))
	{
		if (flag[xx][yy])
		{
			queueX[rear]=xx;
			queueY[rear]=yy;
			queueT[rear]=t+1;
			flag[xx][yy]=false;
			if ((xx==n) ||(yy==n))
			{
				//printf("%d %d\n",xx,yy);
				found=queueT[rear];
			}
			rear=rear+1;
		}
	} 
}

int main()
{
	memset(flag,true,sizeof(flag));
	memset(queueX,0,sizeof(queueX));
	memset(queueY,0,sizeof(queueY));
	memset(queueT,0,sizeof(queueT));
//	printf("%d",sizeof(flag)+sizeof(queueX)+sizeof(queueY)+sizeof(queueT));
	scanf("%d",&n);
	k=n;
	front=0;
	rear=1;
	queueX[0]=1;
	queueY[0]=0;
	queueT[0]=0;
	flag[1][0]=false;
//	printf("%d\n",sizeof(flag)+sizeof(queueX)+sizeof(queueY)+sizeof(queueT));
	found=-1;
	while (true)
	{
		xx=queueX[front];
		yy=queueY[front];
		
//		if ((xx==k) or (yy==k))
//		{
//			printf("%d",queueT[front]);
//			break;
//		}

		doo(queueT[front],xx,yy+xx);
		doo(queueT[front],yy,yy+xx);
		
		doo(queueT[front],xx,xx-yy);
		doo(queueT[front],yy,xx-yy);
		
		doo(queueT[front],xx+xx,yy);
		doo(queueT[front],xx+xx,xx);
		
		doo(queueT[front],xx,yy+yy);
		doo(queueT[front],yy,yy+yy);
		
		front=front+1;
		if (found!=-1) break;
	}
	printf("%d",found);
	return 0;
}
