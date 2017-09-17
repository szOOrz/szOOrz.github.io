#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int Ans[maxn];
int n,q,t,x;
/*int read(){
	int a = 0;
	char c = getchar();
	int f = 1;
	while ((!((c>='0') && (c<='9'))) && (c!='-')) c = getchar();
	if (c == '-'){
		c = getchar();
		f = -1;
	}
	while ((c>='0') && (c<='0')){
		a = a * 10 + c -48;
		c = getchar();
	}
	return a * f;
}*/
int s1,s2;
int main(){

	scanf("%d%d",&n,&q);
	s1 = 0;
	s2 = 1;
	for (int i=1;i<=q;i++){
		scanf("%d",&t);
		if(t == 1){
			scanf("%d",&x);
			s1 = (s1 + x + n) % n;
			s2 = (s2 + x + n) % n;
		} else
		if (t == 2){
			s1 ^= 1;
			s2 ^= 1;
		}
	}
	for (int i=0;i<(n>>1);i++){
		Ans[(s1 + i*2 + n) % n] = i*2+0;
		Ans[(s2 + i*2 + n) % n] = i*2+1;
	}
	for (int i=0;i<n;i++){
		printf("%d ",Ans[i]+1);
	}
}
