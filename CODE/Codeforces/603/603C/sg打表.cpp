#include<bits/stdc++.h>
int K;
using namespace std;
int sg(int x){
	if (x == 0) return 0;
	if (x%2==0){
		int t1;
		if (K & 1) t1 = sg(x / 2); else t1 = 0;
		int t2 = sg(x-1);
		for (int i=0;i<=2;i++){
			if ((t1 != i) && (t2 != i)) return i;
		}
	} else
		return sg(x-1) == 0?1:0;
}
int main(){
	for (itn i=1;i<=30;i++) printf("%3d",)
	for (K=1;K<=5;K++){
		for(int i=1;i<=30;i++){
			printf("%d ",sg(i));
		}
		puts("");
	}
}
