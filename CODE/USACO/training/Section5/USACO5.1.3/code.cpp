/*
ID:cqz15311
LANG:C++
PROG:theme
*/
#include<bits/stdc++.h>
const int Mod = (1e6+7);
const int bit1 = 17;
const int bit2 = 23;
//但位17好像第八个点过了，第九个点WA了
//其实可以多重哈希，多取几个模数。
//我弄了2个bit就能过USACO所有数据了——其实最好还是取模数，代码改改少 
//其实如果是17，3之类的我试了一下是WA的，懒惰就改数字，其实最好是改模数
//这题坑了我好久，但是说到底还是Hash的题目做得少。
//或者说，以前做hash的题目都不卡单hash的。
const int maxn = 5005;
using namespace std;
typedef long long LL;
int Hash1[Mod],Hash2[Mod];
LL f1[maxn],f2[maxn],a[maxn];
LL Pow1[maxn],Pow2[maxn];
int n,L,R,Mid;
bool check(int Len){
	LL rec1 = 0,rec2 = 0;
	for (int i=1;i<=Len;i++) rec1 = (rec1 * bit1 + a[i]) % Mod,rec2 = (rec2 * bit2 + a[i]) % Mod;
	f1[Len] = rec1;
	f2[Len] = rec2;
	for (int i=Len+1;i<=n;i++){
		rec1 = (((rec1 - Pow1[Len-1] * a[i - Len]) % Mod + Mod) % Mod * bit1 + a[i]) % Mod;
		rec2 = (((rec2 - Pow2[Len-1] * a[i - Len]) % Mod + Mod) % Mod * bit2 + a[i]) % Mod;
		f1[i] = rec1;	//注意是Len-1不是Len——卡了N久 
		f2[i] = rec2;
	}
	bool flag = false;
	for (int i=Len;i<=n;i++){
		if (Hash1[f1[i]] == -1) Hash1[f1[i]] = i;
		if (Hash2[f2[i]] == -1) Hash2[f2[i]] = i;
		if ((Hash1[f1[i]] < i - Len/*+1*/) && (Hash2[f2[i]] < i - Len)) flag = true;
				/*不能加一，因为差分过的最后一个等于前面最前面的一个*/
	}
	for (int i=Len;i<=n;i++){
		Hash1[f1[i]] = -1;
		Hash2[f2[i]] = -1;
	}
	if (flag) return true; else return false;
}

int main(){
	freopen("theme.in","r",stdin);
	freopen("theme.out","w",stdout);
	Pow1[0] = 1,Pow2[0] = 1;
	memset(Hash1,-1,sizeof(Hash1));
	memset(Hash2,-1,sizeof(Hash2));
	for (int i=1;i<=5000;i++)Pow1[i] = Pow1[i-1] * bit1 % Mod;
	for (int i=1;i<=5000;i++)Pow2[i] = Pow2[i-1] * bit2 % Mod;
	scanf("%d",&n);
	a[0] = 0;
	for (int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for (int i=n-1;i>=1;i--){
		a[i] = a[i] - a[i-1];
		a[i] = (a[i] % Mod + Mod) % Mod;
	}//a0没用
	n--;
	L = 1;
	R = n;
	while (L < R){
		Mid = (L + R + 1) >> 1;
		if (check(Mid)){
			L = Mid;
		} else 
			R = Mid - 1;
	}
	if (L+1 < 5)  puts("0"); else printf("%d\n",L + 1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
