#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

int n,i,j,k,ans;
int a[500][500];
int pay[500];
bool flag[500];
int main()
{
	while (true)
	{
		n=0;
		scanf("%d",&n);
		if (n==0) return 0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				scanf("%d\n",&a[i][j]);		
			}		
		ans=0;
		memset(flag,false,sizeof(flag));
		flag[0]=true;
		for (int i=0;i<n;i++) pay[i]=a[0][i];
		pay[499]=999999;
		for (int i=0;i<n-1;i++)
		{
			k=499;
			for (int j=0;j<n;j++)
			if ((flag[j]==false) and (pay[j]<pay[k])) k=j;
			ans+=pay[k];
			flag[k]=true;
			for (int j=0;j<n;j++)
				if ((flag[j]==false) and (pay[j]>a[k][j])) pay[j]=a[k][j];
		}
		printf("%d\n",ans);
	}
	return 0;
	
}
