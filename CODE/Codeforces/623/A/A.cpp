#include<bits/stdc++.h> 
using namespace std;
const int maxn = 505;
bool f[505][505];
int n,m,a,b,rec;
char Ans[maxn];
int main(){
	scanf("%d%d",&n,&m);
	memset(f,0,sizeof(f));
	for (int i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		f[a][b] = f[b][a] = 1;
	}
	memset(Ans,'c',sizeof(Ans));
	for (int i=1;i<=n;i++){
		rec = 0;
		for (int j=1;j<=n;j++) if (f[i][j] && i!=j) rec++;
//		printf("%d\n",rec);
		if (rec == n-1){
			Ans[i] = 'b';
		}
	}
	for (int i=1;i<=n;i++){
		if (Ans[i] == 'b') continue;
		rec = 0;
		Ans[i] = 'a';
		for (int j=1;j<=n;j++){
			if (f[i][j] && i!=j && Ans[j]!='b'){
				Ans[j] = 'a';
			}
		}
		break;
	}
//	for (int i=1;i<=n;i++) putchar(Ans[i]);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			
			if (i == j) continue;
			bool t = false;
			if (Ans[i] == 'a' && Ans[j] == 'c') t = true;
			if (Ans[i] == 'c' && Ans[j] == 'a') t = true;
//			printf("\n%d %d %d\n",i,j,t);
			if ((!f[i][j] && !t)||(f[i][j] && t)){
					puts("No");
					return 0;
			   }
		}
	} 
	puts("Yes");
	for (int i=1;i<=n;i++) putchar(Ans[i]);
	puts("");
	return 0;
}
