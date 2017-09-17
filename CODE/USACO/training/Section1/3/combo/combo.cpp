/*
ID:cqz15311
PROG:combo
LANG:C++ 
*/ 
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

#define Lson(i) i >> 1
#define rc 2
#define For(i) for (int i=1;i<=n;i++)
using std::sort;
int n,a1,b1,c1,a2,b2,c2,ans;
int jl(int a,int b)
{
	if (abs(a-b)<=2) return 0;
	if (abs(a-b)>=n-2) return 0;
	return 3;
}
int main()
{
	freopen("combo.in","r",stdin);
	freopen("combo.out","w",stdout);
	scanf("%d",&n);
	/*O(n^3)±©Á¦Ã¶¾Ù*/
	scanf("%d%d%d",&a1,&b1,&c1);
	scanf("%d%d%d",&a2,&b2,&c2);
	For(i)
	{
//		if ((jl(i,a1)>rc) && (jl(i,a2)>rc)) continue;
		For(j)
		{
//			if ((jl(j,b1)>rc) && (jl(j,b2)>rc)) continue;
			For (k)
			{
//				if ((jl(k,c1)>rc) && (jl(k,c2)>rc)) continue;
				if (((jl(i,a1)<=rc) && (jl(j,b1)<=rc) && (jl(k,c1)<=rc)) || 
					((jl(i,a2)<=rc) && (jl(j,b2)<=rc) && (jl(k,c2)<=rc))) ans++;
			}
		}
	}
	printf("%d\n",ans);
}
