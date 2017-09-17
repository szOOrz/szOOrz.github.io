/*
ID:cqz15311
PROG:ttwo
LANG:C++
*/
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
/*
模拟，记忆化模拟，用f[a,b,c,d,e,f]表示牛在a,b，人在c,d，牛的状态为e，人的状态为f。
10*10*10*10*4*4=160000 
*/
const int dx[4]={-1,0,1, 0};
const int dy[4]={ 0,1,0,-1};
bool F[10][10][10][10][4][4],found;
int step,map[10][10];
int a,b,c,d,e,f,na,nb,nc,nd,ne,nf;
int main()
{
	 freopen("ttwo.in","r",stdin);
	 freopen("ttwo.out","w",stdout);
	char ch;
	 for (int i=0;i<10;i++)
	 {
	 	for (int j=0;j<10;j++)
	 	{
	 		ch=getchar();
	 		if (ch=='*') map[i][j]=0; else map[i][j]=1;
	 		if (ch=='F')
	 		{
	 			a=i;
	 			b=j;
	 			e=0;
	 		}
	 		if (ch=='C')
	 		{
	 			c=i;
	 			d=j;
	 			f=0;
	 		}
	 	}
	 	ch=getchar();
	 }
	 found=false;
	 memset(F,0,sizeof(F));
	 step=0;
	 while ((step<=10*10*10*10*4*4) && (!F[a][b][c][d][e][f]))
	 {
	 	if ((a==c) && (b==d))
		{
			found=true;
			break;
		} 
	 	step++;
	 	F[a][b][c][d][e][f]=true;
	 	na=a+dx[e];
	 	nb=b+dy[e];
	 	nc=c+dx[f];
	 	nd=d+dy[f];
	 	ne=e;
	 	nf=f;
	 	if ((na<0) || (nb<0) || (na>9) || (nb>9) || (map[na][nb]==0)) 
	 	{
	 		na=a;
	 		nb=b;
	 		ne++;
	 		if(ne==4) ne=0;
	 	}
	 	if ((nc<0) || (nd<0) || (nc>9) || (nd>9) || (map[nc][nd]==0)) 
	 	{
	 		nc=c;
	 		nd=d;
	 		nf++;
	 		if(nf==4) nf=0;
	 	}
	 	a=na;b=nb;c=nc;d=nd;e=ne;f=nf;
/*	 	for (int i=0;i<=9;i++)
	 	{
	 		for (int j=0;j<=9;j++)
	 		{
	 			if ((a==i) && (b==j)) putchar('F'); else 
	 			if ((c==i) && (d==j)) putchar('C'); else 
	 			if (map[i][j]==1) putchar('.'); else putchar('*');
	 		}
	 		puts("");
	 	}
	 	puts("");
	 	printf("%d %d %d %d %d %d_%d\n",a,b,c,d,e,f,step);
*/	 }
	 if (found) printf("%d\n",step); else puts("0");
	 fclose(stdin);
	 fclose(stdout);
	 return 0;
}
