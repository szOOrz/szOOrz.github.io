/*
ID:cqz15311
LANG:C++
PROG:comehome
*/
/*
反向边，最短路，为了方便写了floyd 
*/ 
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using std::cin; 
using std::min;
int d[150][150],P,c,k;
char a,b;
int main()
{
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	scanf("%d",&P);
	memset(d,0x1F,sizeof(d));
	for (int i=1;i<=P;i++)
	{
		cin >> a >> b >> c;
		d[b][a]=min(d[b][a],c);
		d[a][b]=min(d[a][b],c);
		//printf("%c--->%c %d\n",b,a,c); 
	}
	for (int kk='A';kk<='z';kk++)
		for (int i='A';i<='z';i++)
			for (int j='A';j<='z';j++)
				d[i][j]=min(d[i][j],d[i][kk]+d[kk][j]);
	k=65;
	for (int i='A';i<='Z'-1;i++)
	{
	//	printf("%c %d\n",i,d['Z'][i]);
		if (d['Z'][i]<d['Z'][k]) k=i;
	}
	printf("%c %d\n",k,d['Z'][k]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
