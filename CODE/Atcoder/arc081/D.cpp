#include<bits/stdc++.h> 
using namespace std;
const int Mod = 1000000007;
char s1[100],s2[100];
int n;
long long Ans;
int main(){
	scanf("%d",&n);
	scanf("%s%s",s1,s2);
	Ans = 1;
	int i = 0;
	if (s1[0] == s2[0]){
		Ans = 3;
		i+=1;
	} else{
		Ans = 6;
		i+=2;
	}
	for (;i<n;){
		if (s1[i] == s2[i]){
			if (s1[i-1] == s2[i-1]){
				Ans = Ans * 2 % Mod;
			} else{
				Ans = Ans * 1 % Mod;
			}
			i++;
		} else{
			if (s1[i-1] == s2[i-1]){
				Ans = Ans * 2 % Mod;
			} else
				Ans = Ans * 3 % Mod;
			i+=2;
		}
	}
	printf("%lld\n",Ans);
}



	/*
	-- -- 
	-- -- 
	这样的话 右边有
	12 
	21
	
	13 
	21
	
	12 
	23
	3种
	
	-- |
	-- |
	这样的话
	有1种
	
	|--
	|--
	这样的话有
	12
	13
	
	13
	12
	有2种
	
	||
	||
	这样的话有2种
	12
	12
	
	13
	13
	*/

