/*
ID:cqz15311
LANG:C++
PROG:fc
*/
#include<bits/stdc++.h>
const double eps = 1e-8;
using namespace std;
struct Point{
	double x,y;
}tmp,P[10005],Stack[10005];
int n; 
double Cross(Point a,Point b,Point c){//这里以c为源点 
	return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}
bool cmp(Point a,Point b){
	return Cross(a,b,P[0]) > 0;
	//大于0表示a在b的顺时针方向，所以a应该排在b的前面 
}
void init(){
	freopen("fc.in","r",stdin);
	freopen("fc.out","w",stdout);
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%lf%lf",&P[i].x,&P[i].y);
	}
	int k = 0;
	for (int i=1;i<n;i++){
		if ((P[i].x < P[k].x) || (fabs(P[i].x-P[k].x)<eps) && (P[i].y < P[k].y)){
			k = i;
		}
	}
	tmp = P[k];P[k] = P[0];P[0] = tmp;
	sort(P+1,P+n,cmp);
}
int top;
void solve(){
	top = 0;
	Stack[top] . x = P[0].x;
	Stack[top] . y = P[0].y;
	top++;
	for (int i=1;i<n;i++){
		while ((top >= 2) && (Cross(P[i],Stack[top-1],Stack[top-2]) > 0)) top--;
		Stack[top] . x = P[i].x;
		Stack[top] . y = P[i].y;
		top++;
	}
}
double dis(Point a,Point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
void Write(){
	double Ans = 0;
	for (int i=1;i<top;i++){
		Ans = Ans + dis(Stack[i-1],Stack[i]);
	}
	Ans = Ans + dis(Stack[top-1],Stack[0]);
	printf("%.2lf\n",Ans);
	fclose(stdin);
	fclose(stdout);
}
int main(){
	init();
	solve();
	Write();
	return 0;
}
