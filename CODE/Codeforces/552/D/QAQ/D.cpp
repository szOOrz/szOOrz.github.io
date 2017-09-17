#include<bits/stdc++.h> 
typedef long long LL;
struct P{
	int x,y;
}p[2005];
int Cross(P a,P b,P c){
	return (a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y);
}
int n;
LL Ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	Ans = 0;
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++){
			for (int k=j+1;k<=n;k++){
				if (Cross(p[i],p[j],p[k])!=0) Ans++;
			}
		}
	}
	printf("%I64d\n",Ans);
}
