#include<bits/stdc++.h> 
using namespace std;
int inv(int x){
	int res = 0;
	while (x){
		res = res * 10 + x % 10;
		x = x / 10;
	}
	return res;
}
int main(){
	for (int i=1;i<=1000;i++){
		printf("%d,%d:%d\n",i*10,inv(i*10),i*10+inv(i*10));
	}
}
