#include<bits/stdc++.h>
using namespace std;
int w,m,t;
int main(){
	scanf("%d%d",&w,&m);
	while (m){
		t = m % w;
		if ((t!=0) && (t!=1) && (t!=(w-1))){
			puts("NO");
			return 0;
		}
		if (t == w-1)m++;
		if (t == 1)  m--;
		m = m / w;
	}
	puts("YES");
	return 0;
}
