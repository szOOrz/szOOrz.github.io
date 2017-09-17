#include<bits/stdc++.h>
using namespace std;
long long l,r,x,y,k;
int main(){
//	freopen("sb.in","r",stdin);
	//freopen("sb.out","w",stdout); 
	double l,r,x,y,k; 
	cin >> l >> r >> x >> y >> k;
	if (l/k<=y&&l/k>=x) cout<<"YES"<<endl;
	else if (r/k<=y && r/k>=x) cout<<"YES"<<endl;
	else if (k*x<=r && k*x>=r) puts("YES"); else
	if (k*y<=r && k*y>=l) puts("YES");
	else puts("NO");
	return 0;
}
/*
8 8 2 5 3
NO
*/
