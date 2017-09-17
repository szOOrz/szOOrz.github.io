/*
ID:cqz15311
LANG:C++
PROG:humble
*/
#include<bits/stdc++.h>
using namespace std;
int k,n,a[105],humble[105000],from[105];
int i,j,t;
int main(){
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	scanf("%d%d",&k,&n);
	for (i=1;i<=k;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+k);
	humble[0]=1;
	for (i=1;i<=k;i++){
		from[i]=0;
	}
	for (i=1;i<=n;i++){
		t=1;
		for (j=2;j<=k;j++){
			if (a[j]*humble[from[j]]<a[t]*humble[from[t]]){
				t=j;
			}
		}
		humble[i]=a[t]*humble[from[t]];
		from[t]++;
		for (j=1;j<=k;j++){
			if (a[j]*humble[from[j]]==humble[i]){
				from[j]++;
			}
		}
	}
//	for (i=1;i<=n;i++){
//		printf("%d\n",humble[i]);
//	}
	printf("%d\n",humble[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

