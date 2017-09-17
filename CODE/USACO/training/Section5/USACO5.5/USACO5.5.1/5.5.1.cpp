/*
ID:cqz15311
LANG:C++
PROG:picture
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 50005;
//---------------------------------------------------
int y[maxn*2],Hash[maxn*2];
int X1[maxn],X2[maxn],Y1[maxn],Y2[maxn];
int n,m;
int find(int x){
	int L = 1,R = Hash[0];
	while (L < R){
		int Mid = (L + R) >> 1;
		if (Hash[Mid] < x)	L = Mid + 1; else
		if (Hash[Mid] > x)	R = Mid - 1; else
						 	return Mid;
	}
	return L;
}
void init(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d%d",&X1[i],&Y1[i],&X2[i],&Y2[i]);
		y[++y[0]] = Y1[i];
		y[++y[0]] = Y2[i];
	}
	sort(y+1,y+1+y[0]);
	Hash[0] = 0;
 	for (int i=1;i<=y[0];i++){
		if (i == 1 || (y[i]!=y[i-1])){
			Hash[++Hash[0]] = y[i];
		}
	}
}

struct Ques{
	int X,Y1,Y2,type;
	bool operator < (const Ques &t) const{
		return X < t.X || X == t.X && type > t.type;
	}
}Q[maxn*2];

void Add(int X,int Y1,int Y2,int type){
	m++;
	Q[m] . X = X;
	Q[m] . Y1 = Y1;
	Q[m] . Y2 = Y2;
	Q[m] . type = type;
}

void Add_question(){
	m = 0;
	for (int i=1;i<=n;i++){
		Add(X1[i],find(Y1[i]),find(Y2[i]),1);
		Add(X2[i],find(Y1[i]),find(Y2[i]),-1);
	}
	sort(Q+1,Q+1+m);
}

//--------------------------------------------------------------------
struct T{
	int cnt;
	int num,len;
	bool lbd,rbd;
}tree[maxn*4];
void build(int nod,int l,int r){
	tree[nod] . cnt = 0;
	tree[nod] . lbd = tree[nod].rbd = false;
	tree[nod] . num = 0;//有多少个分散的线段 
	tree[nod] . len = 0;//非0的长度 
	if (r-l>1){
		int mid = (l + r) >> 1;
		build(nod*2,l,mid);
		build(nod*2+1,mid,r);
	}
}

void update_len(int nod,int l,int r){
	if (tree[nod].cnt)  tree[nod].len = Hash[r] - Hash[l];else
	if (r-l==1) 		tree[nod].len = 0; else
						tree[nod].len = tree[nod*2].len + tree[nod*2+1].len;
}

void update_num(int nod,int l,int r){
	if (tree[nod].cnt){
		tree[nod].num = 1;
		tree[nod].lbd = tree[nod].rbd = true;
	} else
	if (r-l==1){
		tree[nod].num = 0;
		tree[nod].lbd = tree[nod].rbd = false;
	} else{
		tree[nod].num = tree[nod*2].num + tree[nod*2+1].num - (tree[nod*2].rbd && tree[nod*2+1].lbd);
		tree[nod].lbd = tree[nod*2].lbd;
		tree[nod].rbd = tree[nod*2+1].rbd; 
	}
}

void update(int nod,int l,int r){
	update_num(nod,l,r);
	update_len(nod,l,r);
}


void change(int nod,int l,int r,int x,int y,int val){
	if ((l == x) && (r == y)){
		tree[nod] .cnt+=val;
	} else{
		int mid = (l + r) >> 1;
		if (l <= x && y <= mid)	change(nod*2,l,mid,x,y,val); else
		if (mid <= x && y <= r) change(nod*2+1,mid,r,x,y,val); else{
			change(nod*2,l,mid,x,mid,val);
			change(nod*2+1,mid,r,mid,y,val);
		}
	}
	update(nod,l,r);
}
//------------------------------------------------------------
void solve(){
	build(1,1,Hash[0]);
	int Ans = 0;
	int pre_num = 0,pre_len = 0;
	for (int i=1;i<=m;i++){
		change(1,1,Hash[0],Q[i].Y1,Q[i].Y2,Q[i].type);
		if (i > 1)
			Ans = Ans + (Q[i].X - Q[i-1].X) * 2 * pre_num;
		Ans += abs(pre_len - tree[1].len);
		pre_num = tree[1].num;
		pre_len = tree[1].len;
	}
	printf("%d\n",Ans);
}
//--------------------------------------------------

int main(){
	freopen("picture.in","r",stdin);
	freopen("picture.out","w",stdout);
	init();
	Add_question();
	solve();
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.000 secs, 4808 KB]
   Test 2: TEST OK [0.000 secs, 4808 KB]
   Test 3: TEST OK [0.000 secs, 4808 KB]
   Test 4: TEST OK [0.000 secs, 4808 KB]
   Test 5: TEST OK [0.000 secs, 4808 KB]
   Test 6: TEST OK [0.000 secs, 4808 KB]
   Test 7: TEST OK [0.000 secs, 4808 KB]
   Test 8: TEST OK [0.000 secs, 4808 KB]
   Test 9: TEST OK [0.000 secs, 4808 KB]
   Test 10: TEST OK [0.000 secs, 4808 KB]
   Test 11: TEST OK [0.000 secs, 4808 KB]

All tests OK.
YOUR PROGRAM ('picture') WORKED FIRST TIME!  That's fantastic
-- and a rare thing.  Please accept these special automated
*/
