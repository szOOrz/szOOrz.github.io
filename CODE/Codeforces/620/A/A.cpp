#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using std::max;
int main(){
	int x1,x2,y1,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	printf("%d\n",max(abs(x1-x2),abs(y1-y2)));
	return 0;
}
