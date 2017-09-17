/*
你有无限个阻值为1的电阻。
需要组成(并联，串联)成一个a/b的电阻。
求最少需要多少电阻。

注意到，一个阻值为a/b的电阻，
与1串联，得到(a+b)/b，
与1并列，得到a/(a+b)，
于是答案可以在求gcd时计算。
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a, b, ans;

void gcd(LL a, LL b){
	if (!b) return;
	ans += a / b;
	gcd(b, a%b);
}

int main(){
	scanf("%I64d%I64d", &a, &b);
	gcd(a, b);
	printf("%I64d\n", ans);
	return 0;
}