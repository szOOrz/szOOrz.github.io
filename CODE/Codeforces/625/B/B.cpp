#include<bits/stdc++.h>
using namespace std;
char s[105000],t[105000];
int nxt[105000];
void get_nxt(){
	nxt[0] = 0;
	for (int i=1,k=0;t[i];i++){
		while (k > 0 && t[i] != t[k]) k=nxt[k-1];
		if (t[i] == t[k]) k++;
		nxt[i] = k;
	}
}
int Ans,Lent;
int main(){
	scanf("%s",&s);
	scanf("%s",&t);Lent = strlen(t);
	get_nxt();
	int j = 0;
	Ans = 0;
	for (int i=0;s[i];i++){
		while (j > 0 && s[i] != t[j]) j = nxt[j-1];
		if (s[i] == t[j]) j++;
		if (j == Lent){
			Ans++;
			j = 0;
		}
	}
	printf("%d\n",Ans);
}
