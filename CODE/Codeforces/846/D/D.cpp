#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,k,Q,x,y,t;
int a[555][555],M[555][555],Ans;
using namespace std;
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&Q);
	memset(a,-1,sizeof(a));
	while (Q--){
		scanf("%d%d%d",&x,&y,&t);
		a[x][y] = t;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j+k-1<=m;j++){
			M[i][j] = -1;
			for (int t=j;t<=j+k-1;t++){
				if (a[i][t] == -1){M[i][j] = -1;break;}
				M[i][j] = max(M[i][j],a[i][t]);
			}
//			printf("%d ",M[i][j]);
		}
//		puts("");
	}
	Ans = -1;
	for (int i=1;i+k-1<=n;i++){
		for (int j=1;j+k-1<=m;j++){
//			printf("%d %d\n",i,j);
			int Rec = -1;
			for (int t=i;t<=i+k-1;t++){
				if (M[t][j] == -1){Rec = -1;break;}
				Rec = max(Rec,M[t][j]);
			}
//			printf("Rec == %d\n",Rec);
			if (Rec != -1){
				if (Ans == -1) Ans = Rec; else Ans = min(Ans,Rec);
			}
		}
	}
	printf("%d\n",Ans);
}
