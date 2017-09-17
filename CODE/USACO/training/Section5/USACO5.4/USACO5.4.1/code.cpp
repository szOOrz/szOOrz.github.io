/*
ID:cqz15311
LANG:C++
PROG:tour
*/
#include<bits/stdc++.h> 
using namespace std;
string a,b;
map<string,int> Name; 
const int inf = 0x3fffffff;
bool g[105][105];
int f[105][105],n,m,ans;
char s[105],t[105];
int main(){
	freopen("tour.in","r",stdin);
	freopen("tour.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> s;
		Name[s] = i;
	}
	memset(g,false,sizeof(g));
	for (int i=1;i<=m;i++){
		cin >> s >> t;
		g[Name[s]][Name[t]] = true;
		g[Name[t]][Name[s]] = true;
	}
	f[1][1] = 1;
	for (int i=1;i<=n;i++){
		for (int j=i+1;j<=n;j++){
			f[i][j] = -inf;
			for (int k=1;k<j;k++)
				if (g[k][j] && f[i][k]>0 && f[i][k]>f[i][j])
					f[i][j] = f[i][k];
			f[j][i] = ++f[i][j];
//			printf("%d %d:%d\n",i,j,f[i][j]);
		}
	}
	ans = 1;
	for (int i=1;i<=n;i++)
		if (g[i][n] && f[i][n] > ans) ans = f[i][n];
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 4236 KB]
   Test 2: TEST OK [0.000 secs, 4236 KB]
   Test 3: TEST OK [0.000 secs, 4236 KB]
   Test 4: TEST OK [0.000 secs, 4236 KB]
   Test 5: TEST OK [0.000 secs, 4236 KB]
   Test 6: TEST OK [0.000 secs, 4236 KB]
   Test 7: TEST OK [0.000 secs, 4236 KB]
   Test 8: TEST OK [0.000 secs, 4236 KB]
   Test 9: TEST OK [0.000 secs, 4236 KB]
   Test 10: TEST OK [0.000 secs, 4236 KB]
   Test 11: TEST OK [0.000 secs, 4236 KB]

All tests OK.
YOUR PROGRAM ('tour') WORKED FIRST TIME!  That's fantastic
-- and a rare thing.  Please accept these special automated
congratulations.
*/
