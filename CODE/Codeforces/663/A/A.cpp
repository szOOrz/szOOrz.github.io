#include<bits/stdc++.h> 
using namespace std;
char s[500];
int pos,neg,m,n,_n;
int main(){
	pos = neg = m = 0;
	s[0] = '+';
	pos = 1;
	while (true){
		char c;
		scanf(" %c",&c);
		scanf(" %c",&c);
		if (c == '=') break;
		if (c == '+') pos++;
		if (c == '-') neg++;
		s[++m] = c;
	}
	scanf("%d",&n);
	if (pos - n*neg > n || n * pos - neg < n){
		puts("Impossible");
		return 0;
	}
	puts("Possible");
	_n = n;
	for (int i=0;i<m;i++){
		if (s[i] == '+'){
			pos--;
			for (int x=1;x<=_n;x++){
				if (!(pos - _n*neg > n-x|| _n * pos - neg < n-x)){
					n=n-x;
					printf("%d %c ",x,s[i+1]);
					break;
				}
			}
		} else{
			neg--;
			for (int x=1;x<=_n;x++){
				if (!(pos - _n*neg > n+x|| _n * pos - neg < n+x)){
					n=n+x;
					printf("%d %c ",x,s[i+1]);
					break;
				}
			}
		}
	}
	
	printf("%d = %d\n",abs(n),_n);
	return 0;
}
