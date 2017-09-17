//定义一个符号‘*’， A*B等于一个取自A、一个取自B的所有数字对的乘积的和。计算A*B。 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
int n,k,x,front,rear;
int queue[100099];
int time[100099];
bool flag[100099];

int main()
{
 scanf("%d%d",&n,&k);
 memset(flag,true,sizeof(flag));
 memset(time,0,sizeof(time));
 front=0;
 rear=1;
 queue[0]=n;
 time[n]=0;
 while (front<rear)
 {
 	x=queue[front];
 	if (x==k)
 	{
 		printf("%d",time[front]);
 		return 0;
 	}
 	if (((x+1)<=100000) and flag[x+1])
 	{
 		queue[rear]=x+1;
 		flag[x+1]=false;
 		time[rear]=time[front]+1;
 		rear++;
 	}
 	if ((x>=0) and flag[x-1])
 	{
 		queue[rear]=x-1;
 		flag[x-1]=false;
 		time[rear]=time[front]+1;
 		rear++;
 	}
 	if (((x*2)<=100000) and flag[x*2])
 	{
 		queue[rear]=x*2;
 		flag[x*2]=false;
 		time[rear]=time[front]+1;
 		rear++;
 	}
 	front++;
 }
}
