#include<bits/stdc++.h> 
using namespace std;
int n,k,L,R,mid;
int s[105050];
char t[105050];
bool check(int mid){
	for (int i=1;i<=n;i++){
		if (t[i] == '1') continue;
		int l,r;
		l = max(0,i - mid - 1);
		r = min(n,i + mid);
//		printf("%d %d{{{\n",l,r);
		if (s[r] - s[l] > k) return true;
	}
	return false;
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",t+1);
	s[0] = 0;
	for(int i=1;i<=n;i++){
		s[i] = s[i-1] + (t[i] == '0');
//		printf("%d %d\n",i,s[i]);
	}
	L = 0;R = n;
	while (L < R){
		int mid = (L+R) >> 1;
		if (check(mid)){
			R = mid;
		} else
			L = mid+1;
	}
	printf("%d\n",L);
}
