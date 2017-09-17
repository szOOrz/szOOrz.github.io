#include<bits/stdc++.h>
using namespace std;
const int maxn = 200005;
int a[maxn],b[maxn],s1,s2;
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i] == 1) s1 = i;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		if (b[i] == 1) s2 = i;
	}
	for (int i=1;i<n;i++){
		if (a[s1] != b[s2]){
			puts("NO");
			return 0;
		}
		s1 = s1 % n + 1;
		if (a[s1] == 0) s1 = s1 % n + 1;
		s2 = s2 % n + 1;
		if (b[s2] == 0) s2 = s2 % n + 1;
	}
	puts("YES");
	return 0;
}
