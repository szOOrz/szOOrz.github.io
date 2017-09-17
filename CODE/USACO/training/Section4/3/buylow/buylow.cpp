/*
ID:cqz15311
LANG:C++
PROG:buylow 
*/ 
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long LL;
const int maxn = 5333;

struct GJD{
	int val[400],len;
	bool operator < (const GJD &x) const{
		if (len < x.len) return true;
		if (len > x.len) return false;
		for (int i=len;i>=1;i--){
			if (val[i] < x.val[i]) return true;
			if (val[i] > x.val[i]) return false;
		}
		return false;//µÈÓÚ 
	}
	
	GJD operator + (const GJD &x) const{
		GJD c;
		memset(c.val,0,sizeof(c.val));
		if (len < x.len) c.len = x.len; else
						 c.len = len;
		for (int i=1;i<=c.len;i++){
			c.val[i] += val[i] + x.val[i];
			c.val[i+1] += c.val[i] / 10;
			c.val[i] %= 10;
		}
		while (c.val[c.len+1] > 0){
			c.len++;
			c.val[c.len+1] += c.val[c.len] / 10;
			c.val[c.len] %= 10;
		}
		return c;
	}
	GJD operator * (const int &x) const{
		GJD c;
		memset(c.val,0,sizeof(c.val));
		c.len = len;
		for (int i=1;i<=c.len;i++){
			c.val[i] = val[i] * x;
		}
		for (int i=1;i<=c.len;i++){
			c.val[i+1] += c.val[i] / 10;
			c.val[i] %= 10;
		}
		while (c.val[c.len+1] > 0){
			c.len++;
			c.val[c.len+1] += c.val[c.len] / 10;
			c.val[c.len] %= 10;
		}
		return c;
	}
	
	GJD operator * (const GJD &x) const{
		GJD c;
		memset(c.val,0,sizeof(c.val));
		for (int i=1;i<=len;i++){
			for (int j=1;j<=x.len;j++){
				c.val[i+j-1] += val[i] * x.val[j];
			}
		}
		c.len = len + x.len - 1;
		for (int i=1;i<=c.len;i++){
			c.val[i+1] += c.val[i] / 10;
			c.val[i] %= 10;
		}
		while (c.val[c.len+1] > 0){
			c.len++;
			c.val[c.len+1] += c.val[c.len] / 10;
			c.val[c.len] %= 10;
		}
		return c;
	}
	
	GJD operator / (const int &x) const{
		GJD a;
		a.len = len;
		for (int i=1;i<=len;i++) a.val[i] = val[i];
		GJD c;
		memset(c.val,0,sizeof(c.val));
		c.len = a.len;
		for (int i=c.len;i>=1;i--){
			c.val[i] = a.val[i] / x;
			a.val[i-1] += (a.val[i] % x) * 10;
		}
		while (c.val[c.len] == 0) c.len--;
		return c;
	}
	
	void clear(int x){
		if (x == 0){
			len = 1;
			memset(val,0,sizeof(val));
			return ;
		}
		len = 0;
		while (x){
			val[++len] = x % 10;
			x /= 10;
		}
	}
	
	void write(){
//		printf("%d\n",len);
		printf("%d",val[len]);
		for (int i=len-1;i>=1;i--){
			//if (val[i] < 100) ¡­¡­ 
			printf("%d",val[i]);
		}
	}
}num[maxn];


int a[maxn],dp[maxn],n;
bool used[maxn];
struct Y{
	int val,id;
	bool operator < (const Y &x) const{
		return val < x.val;
	}
}y[maxn];
int main(){
	freopen("buylow.in","r",stdin);
	freopen("buylow.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		y[i] . val = a[i];
		y[i] . id = i;
	}
	sort(y+1,y+1+n);
	int cnt = 0;
	for (int i=1;i<=n;i++){
		if (i == 1 || y[i] . val != y[i-1] . val){
			a[y[i] . id] = ++cnt;
		} else
			a[y[i] . id] = cnt;
	}
	
	a[0] = n+1;
	a[++n] = -1;
	num[0] .clear(1);dp[0] = 0;
	memset(used,false,sizeof(used));
	for (int i=1;i<=n;i++){
		dp[i] = 1;
		for (int j=i-1;j>=0;j--){
			if (a[i] < a[j]){
				if (dp[j] + 1 > dp[i])	dp[i] = dp[j] + 1;
			}
		}

		for (int j=i-1;j>=0;j--){
			if ((a[j] > a[i]) && (dp[i] == (dp[j]+1))){
				if (!used[a[j]]){
					num[i] = num[i] + num[j];
					used[a[j]] = true;
				}
			}
		}

		for (int j=i-1;j>=0;j--) used[a[j]] = false;
	}
	printf("%d ",dp[n]-1);
	num[n] . write();
	puts("");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*


Executing...
   Test 1: TEST OK [0.000 secs, 12620 KB]
   Test 2: TEST OK [0.000 secs, 12620 KB]
   Test 3: TEST OK [0.000 secs, 12620 KB]
   Test 4: TEST OK [0.000 secs, 12620 KB]
   Test 5: TEST OK [0.000 secs, 12620 KB]
   Test 6: TEST OK [0.014 secs, 12620 KB]
   Test 7: TEST OK [0.000 secs, 12620 KB]
   Test 8: TEST OK [0.000 secs, 12620 KB]
   Test 9: TEST OK [0.042 secs, 12620 KB]
   Test 10: TEST OK [0.308 secs, 12620 KB]

All tests OK.
Your program ('buylow') produced all correct answers!  This is your
submission #2 for this problem.  Congratulations!
*/ 
