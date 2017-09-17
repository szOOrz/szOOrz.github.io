#include<bits/stdc++.h>
using namespace std;
//				  0 1 2 3 4 5 6 
											 //13+
const int f[20] = {0,1,0,1,2,0,2,0,1,0,1,0,1};//02010201
const int g[20] = {0,1,2};//0101010101
				//3+

int n,k,rec;
int sg(int x){
	if (k & 1){
		if (x < 13) return f[x]; else{
			if (x & 1) return 0; else{
				int T1 = sg(x-1);
				int T2 = sg(x/2);
				for (int i=0;i<3;i++){
					if (i!=T1 && i!=T2) return i;
				}
			}
		}
	} else{
		if (x < 3) return g[x]; else{
			if (x & 1) return 0; else
					   return 1;
		}
	}
}
int main(){ 
	scanf("%d%d",&n,&k);
	rec = 0;
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
	//	printf("%d %d\n",x,sg(x));
		rec = rec ^ sg(x);
	}
	if (rec == 0) puts("Nicky"); else puts("Kevin");
}
