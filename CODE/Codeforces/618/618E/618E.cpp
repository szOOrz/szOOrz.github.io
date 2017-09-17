#include<bits/stdc++.h>
typedef long double LD;
const LD pi = acos(-1);
const int maxn =  300009;
using namespace std;
struct Tree{
	LD lazy,x,y;
}tree[maxn*4];
int n,m,type,a,b;
void update(int nod){
	tree[nod].x = tree[nod*2].x+tree[nod*2+1].x;
	tree[nod].y = tree[nod*2].y+tree[nod*2+1].y;
}
void build(int nod,int l,int r){
	if (l == r){
		tree[nod].lazy = 0.0;
		tree[nod].x = 1.0;
		tree[nod].y = 0.0;
		return ;
	}
	int mid = (l+r) >> 1;
	build(nod*2,l,mid);
	build(nod*2+1,mid+1,r);
	update(nod);
}
void calc(int nod,LD val){
	LD tmp1,tmp2;
	tmp1 = tree[nod].x;
	tmp2 = tree[nod].y;
	tree[nod].x = tmp1 * cos(val) - tmp2 * sin(val);
	tree[nod].y = tmp1 * sin(val) + tmp2 * cos(val);
	tree[nod].lazy += val;	
}

void push_down(int nod){
	calc(nod*2,tree[nod].lazy);
	calc(nod*2+1,tree[nod].lazy);
	tree[nod].lazy = 0;
	return ;
}
void change_len(int nod,int l,int r,int x,int val){
	if (l == r){
		LD Len;
		Len = sqrt(tree[nod].x*tree[nod].x+tree[nod].y*tree[nod].y);
		tree[nod] . x = tree[nod].x / Len * (Len + val);
		tree[nod] . y = tree[nod].y / Len * (Len + val);
		return ;
	}
	push_down(nod);
	int mid = (l+r) >> 1;
	if (x <= mid) change_len(nod*2,l,mid,x,val); else
				  change_len(nod*2+1,mid+1,r,x,val);
	update(nod);
}
void change_ag(int nod,int l,int r,int x,int y,LD val){
	if ((l == x) && (y == r)){
		calc(nod,val);
		return ;
	}
	push_down(nod);
	int mid =(l+r) >> 1;
	if ((l <= x) && (y <= mid)) change_ag(nod*2,l,mid,x,y,val); else
	if ((mid+1 <= x) && (y <= r)) change_ag(nod*2+1,mid+1,r,x,y,val); else{
		change_ag(nod*2,l,mid,x,mid,val);
		change_ag(nod*2+1,mid+1,r,mid+1,y,val);
	}
	update(nod);
}
int main(){
	scanf("%d%d",&n,&m);
	build(1,1,n);
	while (m--){
		scanf("%d",&type);
		if (type == 1){
			scanf("%d%d",&a,&b);
			change_len(1,1,n,a,b);
		} else{
			scanf("%d%d",&a,&b);
			change_ag(1,1,n,a,n,1.0*(360-b)*pi/180);
		}
		printf("%.12lf %.12lf\n",(double)tree[1].x,(double)tree[1].y);
	}
	return 0;
}
