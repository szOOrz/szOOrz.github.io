#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if (!b) return a; else return gcd(b,a%b);
}
int n,a[28],ans,Odd,p;
int main(){
	scanf("%d",&n);
	scanf("%d",&a[1]);
	Odd = 0;
	ans = a[1];
	if (a[1] & 1) Odd = 1,p = 1;
	for (int i=2;i<=n;i++){
		scanf("%d",&a[i]);
		ans = gcd(a[i],ans);
		if (a[i] & 1) Odd++ , p = i;
	}
	
	if (n == 1)
	{
		printf("%d\n",a[1]);
		for (int i=1;i<=a[1];i++)
			putchar('a');
		return 0;
	}
	
	if (Odd >= 2){
		puts("0");
		for (int i=1;i<=n;i++){
			for (int j=1;j<=a[i];j++)
				putchar('a'+i-1);
		}
		return 0;
	}
	
	if (Odd == 1){
		printf("%d\n",ans);
		for (int t=1;t<=ans;t++){
			for (int i=1;i<=n;i++)
				if (a[i] % 2 == 0)
					for (int j=1;j<=a[i] / 2 / ans;j++)
						putchar('a' - 1 + i);
			for (int j=1;j<=a[p]/ans;j++)
				putchar('a'-1+p);
			for (int i=n;i>=1;i--)
				if (a[i] % 2 == 0)
					for (int j=1;j<=a[i] / 2 / ans;j++)
						putchar('a' - 1 + i);
		}
		return 0;
	}
	{
		printf("%d\n",ans);
		
		for (int t=1; t<=ans; t++)
		if (t&1){
			for (int i=1; i<=n; i++)
				for (int j=1; j<=a[i]/ans; j++)
					putchar('a'-1+i);
		}
		else{
			for (int i=n; i>=1; i--)
				for (int j=1; j<=a[i]/ans; j++)
					putchar('a'-1+i);
		}
		return 0;
	}
}
