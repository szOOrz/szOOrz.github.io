#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
struct Point{
	int x,y;
	int id;
}p1[105000],p2[105000];
int n,k;
LL Ans;
bool cmpx(Point a,Point b){
	return a.x < b.x;
}
bool cmpy(Point a,Point b){
	return a.y < b.y;
}
bool used[105000];
void update_ans(int l,int r,int u,int d){
	while (used[p2[u].id]) u++;
	while (used[p2[d].id]) d--;
	while (used[p1[l].id]) l++;
	while (used[p1[r].id]) r--;	
	LL Xval = p1[r].x - p1[l].x;
	if (Xval == 0) Xval = 2; else
				   Xval += Xval & 1;
	LL Yval = p2[d].y - p2[u].y;
	if (Yval == 0) Yval = 2; else
				   Yval += Yval & 1;
	LL Rec = Xval * Yval;
	if (Ans > Rec) Ans = Rec;
}
void dfsy(int l,int r,int u,int d,int k){
	while (used[p2[u].id]) u++;
	while (used[p2[d].id]) d--;
	if (k == 0){
		update_ans(l,r,u,d);
	} else{
		used[p2[u].id] = true;
		dfsy(l,r,u+1,d,k-1);
		used[p2[u].id] = false;
		used[p2[d].id] = true;
		dfsy(l,r,u,d-1,k-1);
		used[p2[d].id] = false;
	}
}
void dfsx(int l,int r,int k){
//	printf("(%d,%d,%d,%d,%d\n",l,r,1,n,k);
	if (k == 0){
		update_ans(l,r,1,n);
		return ;
	} else{
		used[p1[l].id] = true;
		dfsx(l+1,r,k-1);
		used[p1[l].id] = false;
		used[p1[r].id] = true;
		dfsx(l,r-1,k-1);
		used[p1[r].id] = false;
		
		dfsy(l,r,1,n,k);
	}
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		double X1,X2,Y1,Y2;
		scanf("%lf%lf%lf%lf",&X1,&Y1,&X2,&Y2);
		p1[i].x = (X1 + X2);
		p1[i].y = (Y1 + Y2);
		p1[i].id = i;
		p2[i].x = p1[i].x;
		p2[i].y = p1[i].y;
		p2[i].id = i;
	}
	sort(p1+1,p1+1+n,cmpx);//°´ÕÕxÅÅÐò
	sort(p2+1,p2+1+n,cmpy);//°´ÕÕyÅÅÐò 
	memset(used,false,sizeof(used));
	Ans = 0x3fffffffffffffff;
	dfsx(1,n,k);
	printf("%I64d\n",Ans / 4);
}
