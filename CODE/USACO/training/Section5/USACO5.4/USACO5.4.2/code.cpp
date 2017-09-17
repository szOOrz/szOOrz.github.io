/*
ID:cqz15311
LANG:C++
PROG:charrec
*/
#include<bits/stdc++.h>
using namespace std;
const char letter[30]=" abcdefghijklmnopqrstuvwxyz";
const int maxn = 1201;
int cost[maxn][22],from[maxn][22];
int Ans[maxn],f[maxn],ffrom[maxn];
int a[28][21];
int s[maxn],n;
int cnt[1<<20];
const int inf = 0x3fffffff;
int dif(int i,int j,int k){
	return cnt[a[i][j] ^ s[k]];
}
void DP(){
	f[0] = 0;
	for (int i=1;i<=n;i++) f[i] = inf;
	for (int i=19;i<=n;i++){
		if (i >= 19 && f[i-19] != inf){
			if (f[i-19] + cost[i-18][19]<f[i]){
				f[i] = f[i-19] + cost[i-18][19];
				ffrom[i] = 19;
			}
		}
		if (i >= 20 && f[i-20] != inf){
			if (f[i-20] + cost[i-19][20] < f[i]){
				f[i] = f[i-20] + cost[i-19][20];
				ffrom[i] = 20;
			}
		}
		if (i >= 21 && f[i-21] != inf){
			if (f[i-21] + cost[i-20][21] < f[i]){
				f[i] = f[i-21] + cost[i-20][21];
				ffrom[i] = 21;
			}
		}
//		printf("%d:%d %d\n",i,f[i],ffrom[i]);
	}
}
void get_cost(){
	memset(cost,0x3f,sizeof(cost));
	for (int i=1;i<=n;i++){
		if (i+18<=n){
			for (int j=1;j<=27;j++){
				int tot = 0;
				for (int k=2;k<=20;k++)
					tot+=dif(j,k,i+k-2);
				//如果原本的20行缺了第一行
				if (tot < cost[i][19]) {
					cost[i][19] = tot;
					from[i][19] = j;
				}
				for (int k=2;k<=20;k++){
					tot += dif(j,k-1,i+k-2);
					tot -= dif(j,k,i+k-2);
					if (tot < cost[i][19]){
						cost[i][19] = tot;
						from[i][19] = j;
					}
				}
			}
		}
		if (i + 19 <= n){
			for (int j=1;j<=27;j++){
				int tot = 0;
				for (int k=1;k<=20;k++)
					tot += dif(j,k,i+k-1);
				if (tot < cost[i][20]){
					cost[i][20] = tot;
					from[i][20] = j;
				}
			}
		}
		if (i + 20 <= n){
			for (int j = 1;j<=27;j++){
				int tot = 0;
				for (int k=1;k<=20;k++){
					if (k == 1) tot += dif(j,1,i);
					else 		tot += dif(j,k,i+k);
				}
				if (tot < cost[i][21]){
					cost[i][21] = tot;
					from[i][21] = j;
				}
				for (int k=2;k<=20;k++){
					tot += dif(j,k,i+k-1);
					tot -= dif(j,k,i+k);
					if(tot < cost[i][21]){
						cost[i][21] = tot;
						from[i][21] = j;
					}
				}
			}
		}
//		printf("(%d,%d) (%d,%d) (%d,%d)\n",cost[i][19],from[i][19],cost[i][20],from[i][20],cost[i][21],from[i][21]);
	}
}
int main(){
	freopen("font.in","r",stdin);
	scanf("%d",&n);
	scanf("\n");
	for (int i=1;i<=540;i++){
		a[(i-1)/20+1][(i-1)%20+1] = 0;
		for (int j=1;j<=20;j++){
			a[(i-1)/20+1][(i-1)%20+1]<<=1;
			a[(i-1)/20+1][(i-1)%20+1]|= (getchar() == '1');
		}
		scanf("\n");
	}
	freopen("charrec.in","r",stdin);
	freopen("charrec.out","w",stdout);
	scanf("%d",&n); 
	scanf("\n");
	for (int i=1;i<=n;i++){
		s[i] = 0;
		for (int j=1;j<=20;j++){
			s[i]<<=1;
			s[i]|= (getchar()=='1');
		}
		scanf("\n");
	}
	cnt[0] = 0;
	for (int i=1;i<(1<<20);i++)
		cnt[i] = cnt[i >> 1] + (i & 1);
	get_cost();
	DP();
	Ans[0] = 0;
	for (int i=n;i>=1;i-=ffrom[i]){
//		printf("%d %d %d\n",i,ffrom[i],f[i]);
		Ans[++Ans[0]] = from[i-ffrom[i]+1][ffrom[i]];
	}
//	printf("Ans0 = %d\n",Ans[0]);
	for (int i=Ans[0];i>=1;i--){
//		printf("%d:",Ans[i]);
		printf("%c",letter[Ans[i]-1]);
	}
	puts("");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
抄完代码再调对，简直比自己写出来的还开心。 
*/
