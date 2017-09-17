#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
LL k,t,i;
int main(){
	scanf("%I64d",&k);
	if (k == 0){
		putchar('a');
		return 0;
	}
	i = 'a';
	t = 100000;
	while (k>0){
		while (k < t*(t-1) / 2) t--;
		//k>=t*t
		for (int j=1;j<=t;j++) putchar(i);
		k-=t*(t-1) / 2;
		i++;
	}
	return 0;
}
