/*
ID:cqz15311 
TASK:fact4
LANG:C++
*/
#include<bits/stdc++.h>
using namespace std;
int n;
long long rec;
int main(){
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
	scanf("%d",&n);
	rec = 1;
	for (int i=1;i<=n;i++){
		rec = rec * i;
		while (rec % 10 == 0) rec = rec / 10;
		rec = rec % 100000000;
	}
	printf("%lld\n",rec % 10);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
