/*
ID:cqz15311
LANG:C++
PROB:packrec
*/
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<vector>
using namespace std;
#define max3(a,b,c) (max(max(a,b),c))
int n,T[10][3];
struct P{
	int W,H;
	P(int _W = 0,int _H = 0){
		W = max(_W,_H);
		H = min(_W,_H);
	}
	bool operator < (const P &x) const{
		return W*H < x.W * x.H || 
			   (W*H==x.W*x.H && H<x.H);
	}
};
vector<P> p;
void Solve(int h1,int w1,int h2,int w2,int h3,int w3,int h4,int w4){
	int W,H;
	{
		W = w1+w2+w3+w4;
		H = max(max(h1,h2),max(h3,h4));
//		printf("1:%d,%d\n",W,H);
		p.push_back(P(W,H));
	}//1
	{
		W = max(w1+w2+w3,w4);
		H = max3(h1,h2,h3)+h4;
//		printf("2:%d,%d\n",W,H);
		p.push_back(P(W,H));
	}//2
	{
		W = max(w1+w2,w3)+w4;
		H = max3(h1+h3,h2+h3,h4);
//		printf("3:%d,%d\n",W,H);
		p.push_back(P(W,H));
	}//3
	{
		W = w1+w2+max(w3,w4);
		H = max3(h1,h3+h4,h2);
//		printf("4:%d,%d\n",W,H);
		p.push_back(P(W,H));
	}//4
	{
		H = max(h1+h3,h2+h4);
		if (h3>=h2+h4) W = max3(w1,w2+w3,w3+w4);
		if (h3>h4 && h3<h2+h4) W = max3(w1+w2,w2+w3,w3+w4);
		if (h4>h3 && h4<h1+h3) W = max3(w1+w2,w1+w4,w3+w4);
		if (h4>=h1+h3) W = max3(w2,w1+w4,w3+w4);
		if (h3==h4) W = max(w1+w2,w3+w4);
//		printf("%d,%d\n",W,H);
		p.push_back(P(W,H));
	}
}
int main(){
	freopen("packrec.in","r",stdin);
	freopen("packrec.out","w",stdout);
	p.clear();
	for (int i=0;i<4;i++){
		scanf("%d%d",&T[i][0],&T[i][1]);
	}
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			if (i == j) continue;
			for (int k=0;k<4;k++){
				if (k == j || k == i) continue;
				int l = 3+2+1-i-j-k;
				for (int a=0;a<2;a++){
					for (int b=0;b<2;b++){
						for (int c=0;c<2;c++){
							for (int d=0;d<2;d++){
								Solve(T[i][a],T[i][a^1],
									  T[j][b],T[j][b^1],
									  T[k][c],T[k][c^1],
									  T[l][d],T[l][d^1]);
							}
						}
					}
				}
			}
		}
	}
	sort(p.begin(),p.end());
	int Ans = p[0].W*p[0].H;
	printf("%d\n",Ans);
	for (int i=0;i<(int)p.size();i++){
		if (p[i].W * p[i].H > Ans) break;
		if (i==0||p[i].H!=p[i-1].H){
			printf("%d %d\n",p[i].H,p[i].W);
		}
	}
	return 0;
}
