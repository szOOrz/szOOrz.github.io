#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
char A[maxn];
int f[20][255];
int n,Len,cnt;
int main(){
	scanf("%s",A + 1);
	n = strlen(A + 1);
	puts("");
	//长度不超过20
	memset(f,0,sizeof(f));
	cnt = 0;
	Len = 0;
	for (int i=1;i<=n;i++){
		if (!f[Len][A[i]]) cnt++;
		f[Len][A[i]]++;
//		printf("%c",A[i]);
		if (cnt == 26){
			cnt = 0;
			Len++;
			puts("");
		}
	}
	printf("%d\n",Len);
	for (int i=0;i<=Len;i++){
		for (int j='a';j<='z';j++){
			if (f[i][j] == 1 || f[i][j] == 0){
				putchar(j);
				break;
			}
		}
	
	}
	return 0;
}
