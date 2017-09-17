/*
ID:cqz15311
LANG:C++
PROG:shuttle
*/
#include<bits/stdc++.h> 
using namespace std;
int n,now,len,cnt;
int main(){
	freopen("shuttle.in","r",stdin);
	freopen("shuttle.out","w",stdout);
	scanf("%d",&n);
	now = n+1;
	cnt = 0;
	for (int i=1;i<=2*n+1;i++){
		if (i <= n+1){
			len = i;
		} else 
			len = 2 * (n+1) - i;
		if (i & 1){
			for (int j=1;j<=len;j++){
				if (i!=1){
					cnt++;
					printf("%d",now);
					if ((i == 2*n+1) && (j == len)) puts(""); else
					if (cnt % 20 == 0) puts(""); else
					putchar(' ');
				}
				now = now - 2;
			}
			now+=2;
			if (i <= n)now--; else now++;
		} else{
			for (int j=1;j<=len;j++){
					cnt++;
					printf("%d",now);
					if (cnt % 20 == 0) puts(""); else
					putchar(' ');
					now = now + 2;
			}
			now-=2;
			if (i <= n)now++; else now--;
		}
	}
	//puts("");这个不能有！害得我没有1A 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 4176 KB]
   Test 2: TEST OK [0.000 secs, 4176 KB]
   Test 3: TEST OK [0.000 secs, 4176 KB]
   Test 4: TEST OK [0.000 secs, 4176 KB]
   Test 5: TEST OK [0.000 secs, 4176 KB]
   Test 6: TEST OK [0.000 secs, 4176 KB]
   Test 7: TEST OK [0.000 secs, 4176 KB]
   Test 8: TEST OK [0.000 secs, 4176 KB]
   Test 9: TEST OK [0.000 secs, 4176 KB]
   Test 10: TEST OK [0.000 secs, 4176 KB]

All tests OK.
Your program ('shuttle') produced all correct answers!  This is your
submission #2 for this problem.  Congratulations!
*/ 
