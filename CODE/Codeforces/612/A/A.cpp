#include<bits/stdc++.h>
using namespace std;
int n,p,q,pre;
char s[105];
int main(){
	scanf("%d%d%d",&n,&p,&q);
	scanf("%s",s);
	for (int i=0;i<=n;i++){
		for (int j=0;j<=n;j++){
			if (i * p + j * q == n){
				printf("%d\n",i+j);
				pre = 0;
				for (int a=1;a<=i;a++){
					for (int cnt=0;cnt<p;cnt++,pre++) printf("%c",s[pre]);
					puts("");
				}
				for (int a=1;a<=j;a++){
					for (int cnt=0;cnt<q;cnt++,pre++) printf("%c",s[pre]);
					puts("");
				}
				return 0;
			}
		}
	}
	puts("-1");
	return 0;
}
