#include<bits/stdc++.h> 
using namespace std;
char s[10500],t[10500];
int l,r,k,m;
int main(){
	scanf("%s",s+1);
	scanf("%d",&m);
	while (m--){
		scanf("%d%d%d",&l,&r,&k);
		k = k % (r-l+1);
		for (int i=l;i<=r;i++){
			t[i] = s[((i-l-k) % (r-l+1) + (r-l+1)) % (r-l+1) + l];
		}
		for (int i=l;i<=r;i++){
			s[i] = t[i];
		}
	}
	printf("%s\n",s+1);
	return 0;
}
