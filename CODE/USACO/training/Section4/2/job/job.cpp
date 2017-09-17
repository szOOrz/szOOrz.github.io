/*
ID:cqz15311
LANG:C++
PROG:job
*/
#include<bits/stdc++.h>
const int inf = 1 << 20;
using namespace std;
int a[1005],b[1005];
int timea[1005],timeb[1005],time1[1005],time2[1005];
int n,na,nb,Min,ans,k;
int main(){
	freopen("job.in","r",stdin);
	freopen("job.out","w",stdout);
	scanf("%d",&n);
	scanf("%d%d",&na,&nb);
	for (int i=1;i<=na;i++) scanf("%d",&a[i]);
	for (int i=1;i<=nb;i++) scanf("%d",&b[i]);
	memset(timea,0,sizeof(timea));
	memset(timeb,0,sizeof(timeb));
	for (int i=1;i<=n;i++) {
		Min = inf;
		for (int j=1;j<=na;j++){
			if (timea[j] + a[j] < Min) {
				Min = timea[j] + a[j];
				k = j;
			}
		}
		timea[k] = time1[i] = Min;
	}
	printf("%d ",Min);
	for (int i=1;i<=n;i++){
		Min = inf;
		for (int j=1;j<=nb;j++){
			if (timeb[j] + b[j] < Min){
				Min = timeb[j] + b[j];
				k = j;
			}
		}
		timeb[k] = time2[i] = Min;
	}
	ans = 0;
	for (int i=1;i<=n;i++)
		ans = max(ans,time1[i] + time2[n-i+1]);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
}

/*
Executing...
   Test 1: TEST OK [0.000 secs, 4196 KB]
   Test 2: TEST OK [0.000 secs, 4196 KB]
   Test 3: TEST OK [0.000 secs, 4196 KB]
   Test 4: TEST OK [0.000 secs, 4196 KB]
   Test 5: TEST OK [0.000 secs, 4196 KB]
   Test 6: TEST OK [0.000 secs, 4196 KB]
   Test 7: TEST OK [0.000 secs, 4196 KB]
   Test 8: TEST OK [0.000 secs, 4196 KB]
   Test 9: TEST OK [0.000 secs, 4196 KB]
   Test 10: TEST OK [0.000 secs, 4196 KB]
   Test 11: TEST OK [0.000 secs, 4196 KB]
   Test 12: TEST OK [0.000 secs, 4196 KB]

All tests OK.
*/
