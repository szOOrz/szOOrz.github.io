#include <iostream> 
#include <cstdio>
const int oo=1000000000;
int p,h[150005];
int f[150005][2];
int max(int x,int y){return x<y?y:x;};
int main()
{
	scanf("%d",&p);
	for  (int i=1;i<=p;i++) scanf("%d",&h[i]);
	f[0][0]=0;
	f[0][1]=-oo;
	for (int i=1;i<=p;i++)
	{
		f[i][0]=max(f[i-1][0],f[i-1][1]-h[i]);
		f[i][1]=max(f[i-1][1],f[i-1][0]+h[i]);
	}
	printf("%d",max(f[p][0],f[p][1]));
}
