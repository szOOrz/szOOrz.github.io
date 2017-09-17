/*
i=1
g = (n-1) * abs(di + i - n) 
*/


/*
i = n-4
di = 4

i = n-3
di = 3

i = n-2
di = 2

i = n-1
di = 1

i = n
随意



对于n是偶数 
(n-3)(n-1)(n-1)(n-3)(n-2)(n)(n-2)(n)
对于n是奇数
(n-3)(n-1)(n-1)(n-3)(n-4)(n-2)(n)(n-2)(n-4)(n)
*/ 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
const int maxn = 5e5+100;
int l,r,x,n;
int a[2*maxn];
int main(){
	scanf("%d",&n);
	if (n & 1){
		l = 1;r = n-1;
		x = 2;
		while (l < r){
			a[l] = a[r] = x;
			l++;r--;
			x+=2;
		}
		x = 1;
		l = n;r = 2*n-1;
		while (l < r){
			a[l] = a[r] = x;
			l++;r--;
			x+=2;
		}
		a[l] = a[2*n] = n;
	} else{
		l = 1;r = n;
		x = 1;
		while (l < r){
			a[l] = a[r] = x;
			l++;r--;
			x+=2;
		}
		l = n+1;r = 2*n-1;
		x = 2;
		while (l < r) {
			a[l] = a[r] = x;
			l++;r--;
			x+=2;
		}
		a[l] = a[2*n] = n;
	}
	for (int i=1;i<=2*n;i++) printf("%d ",a[i]);
}
