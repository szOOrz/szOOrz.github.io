#include<iostream>
#include<cstring>
int g[1005][85],x,y,xx,yy;
bool flag[1005][85];
int W,H,ans,cnt,qx[1005*85],qy[1005*85],front,rear;
char c;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};
int main()
{
	scanf("%d%d",&W,&H);
	for (int i=1;i<=H;i++)
	{
		for (int j=1;j<=W;j++)
		{
			c=getchar();
			while ((c!='.') && (c!='*')) c=getchar();
			if (c=='*') g[i][j]=1; else g[i][j]=0;
		}
	}
	ans=0;
	memset(flag,true,sizeof(flag));
	for (int i=1;i<=H;i++)
	{
		for (int j=1;j<=W;j++)
		{
			if (flag[i][j])
			{
				cnt=0;
				front=rear=0;
				qx[rear]=i;
				qy[rear++]=j;
				flag[i][j]=0;
				while (front<rear)
				{
					x=qx[front];
					y=qy[front++
					];
					for (int d=0;d<4;d++)
					{
						xx=x+dx[d];
						yy=y+dy[d];
						if ((xx>0) && (yy>0) && (xx<H) && (yy<W))
							if (flag[xx][yy])
							{
								flag[xx][yy]=false;
								cnt++;
								qx[rear]=xx;
								qy[rear++]=yy;
							}
					}
				}
				if (cnt>ans) ans=cnt;
			}
		}
	}
	printf("%d",cnt);
}
