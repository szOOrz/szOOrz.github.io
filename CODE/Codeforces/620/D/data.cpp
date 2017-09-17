#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("1.in","w",stdout);
	srand(time(NULL));
	int n = rand() % 100 + 1;
	printf("%d\n",n);
	for (int i=1;i<=n;i++) printf("%d ",rand() -1000);
	puts("");
	int m = rand() % 100 + 1;
	printf("%d\n",m);
	for (int i=1;i<=m;i++) printf("%d ",rand() -1000);
	return 0;
}
