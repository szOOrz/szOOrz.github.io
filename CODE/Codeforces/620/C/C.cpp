#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<vector>
using namespace std;
map<int,int> Map;
vector<int> vx,vy;
int n,x,l; 
int main(){
	scanf("%d",&n);
	Map.clear();
	l = 0;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (++Map[x] == 2){
			Map.clear();
			vx.push_back(l+1);
			vy.push_back(i);
			l = i;
		}
	}
	if (vx.size()==0){
		puts("-1");
	} else{
		printf("%d\n",(int)vx.size());
		vy[(int)vy.size()-1] = n;
		for (int i=0;i<(int)vx.size();i++){
			printf("%d %d\n",vx[i],vy[i]);
		}
	}
	return 0;
}
