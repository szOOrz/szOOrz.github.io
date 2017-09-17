#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#define N 10
using namespace std;
int main()
{
	freopen("test.in","w",stdout);
	int i,j,k;
	int n,m,p;
	int a,b,c;
	srand((unsigned)time(NULL));
	n=rand()%N+1;
	printf("%d %d\n",n,rand()%n+1);
	for(i=2;i<=n;i++)
	{
		printf("%d %d\n",rand()%(i-1)+1,i);
	}
	return 0;
}
