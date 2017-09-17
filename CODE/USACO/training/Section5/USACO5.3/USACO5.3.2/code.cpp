/*
ID:cqz15311
LANG:C++
PROG:window
*/
#include<bits/stdc++.h> 
using namespace std;
int head,tail;
int nxt[255],pre[255];
int L[255],R[255],U[255],D[255];
char str[105];
void Addhead(int x){
	pre[x] = -1;
	nxt[x] = head;
	if (head!=-1) pre[head] = x;
	head = x;
	if (tail==-1) tail = x;
}
void Addtail(int x){
	nxt[x] = -1;
	pre[x] = tail;
	if (tail!=-1) nxt[tail] = x;
	tail = x;
	if (head==-1) head = x;
}
void remove(int x){
	if (x == -1) return;
	if (x != tail) pre[nxt[x]] = pre[x];
	if (x != head) nxt[pre[x]] = nxt[x];
	if (x == tail) tail = pre[x];
	if (x == head) head = nxt[x];
}
int dfs(int l,int r,int u,int d,int n){
	while ((n != -1) && ((l >= R[n]) || (r <= L[n]) || (u >= D[n]) || (d <= U[n]))) n = nxt[n];
	if (n == -1) return (r-l) * (d-u);
	int rec = 0;
	if (l < L[n]){
		rec += dfs(l,L[n],u,d,nxt[n]);
		l = L[n];
	}
	if (r > R[n]){
		rec += dfs(R[n],r,u,d,nxt[n]);
		r = R[n];
	}
	if (u < U[n]){
		rec += dfs(l,r,u,U[n],nxt[n]);
		u = U[n];
	}
	if (d > D[n]){
		rec += dfs(l,r,D[n],d,nxt[n]);
		d = D[n];
	}
	return rec;
}

void solve_w(){
	int n = str[2];
	sscanf(str+4,"%d,%d,%d,%d",&L[n],&D[n],&R[n],&U[n]);
	if (R[n]<L[n]) swap(L[n],R[n]);
	if (D[n]<U[n]) swap(U[n],D[n]);
	Addtail(n);
}

void solve_t(){
	int n = str[2];
	remove(n);
	Addtail(n);
}
void solve_b(){
	int n = str[2];
	remove(n);
	Addhead(n);
}
void solve_d(){
	int n = str[2];
	remove(n);
}
void solve_s(){
	int n = str[2];
	int res = dfs(L[n],R[n],U[n],D[n],nxt[n]);
	int total = (R[n] - L[n]) * (D[n] - U[n]);
	printf("%.3lf\n",res / (double)total * 100);
}
void init(){
	memset(nxt,-1,sizeof(nxt));
	memset(pre,-1,sizeof(pre));
	head = tail = -1;
}
int main(){
	freopen("window.in","r",stdin);
	freopen("window.out","w",stdout);
	init();
	while (~scanf("%s",str)){
		if (str[0] == 'w') solve_w();
		if (str[0] == 't') solve_t();
		if (str[0] == 'b') solve_b();
		if (str[0] == 'd') solve_d();
		if (str[0] == 's') solve_s();
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
Executing...
   Test 1: TEST OK [0.014 secs, 4184 KB]
   Test 2: TEST OK [0.014 secs, 4184 KB]
   Test 3: TEST OK [0.014 secs, 4184 KB]
   Test 4: TEST OK [0.014 secs, 4184 KB]
   Test 5: TEST OK [0.014 secs, 4184 KB]
   Test 6: TEST OK [0.014 secs, 4184 KB]
   Test 7: TEST OK [0.014 secs, 4184 KB]
   Test 8: TEST OK [0.014 secs, 4184 KB]
   Test 9: TEST OK [0.000 secs, 4184 KB]
   Test 10: TEST OK [0.014 secs, 4184 KB]
   Test 11: TEST OK [0.014 secs, 4184 KB]
All tests OK.
*/
