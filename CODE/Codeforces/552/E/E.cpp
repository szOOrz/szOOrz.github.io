#include<bits/stdc++.h> 
using namespace std;
typedef long long LL;
char s[5008];
LL n,pos[20],num;
LL ans,rec,Ans;
LL get(LL l,LL r){
	if (l > r) return 1;
	LL ans = 0;
	LL rec = 1;
	for (LL i=l;i<=r;i++){
		if (s[i] == '+'){
			ans = ans + rec;
			rec = 1;
		} else
		if ((s[i] >= '1') && (s[i] <= '9')){
			rec = rec * (s[i]-'0');
		}
	}
	ans = ans + rec;
	return ans;
}
int main(){
	scanf("%s",s + 1);
	n = strlen(s + 1);
	num = 0;
	pos[++num] = 0;
	for (LL i=1;i<=n;i++){
		if (s[i] == '*'){
			pos[++num] = i;
		}
	}
	pos[++num] = n+1;
	Ans = 0;
	for (LL l=1;l<=num;l++){
		//从第l个乘号的右边开始
			//到第r个乘号的左边结束 
		for (LL r=l+1;r<=num;r++){ 
			LL a = get(pos[l]+1,pos[r]-1);
//			printf("%I64d-->%I64d:%I64d---->",pos[l]+1,pos[r]-1,a);
			
			ans = 0;
			rec = 1;
			
			for (LL k=1;k<=pos[l]-1;k++){
//				printf("%c",s[k]);
				if (s[k] == '+'){
					ans = ans + rec;
					rec = 1;
				} else
				if ((s[k] >= '0') && (s[k] <= '9')){
					rec = rec * (s[k] - '0');
				}
			}
//			printf("\n%I64d,%I64d\n",ans,rec);
			rec = rec * a;
			for (LL k = pos[r]+1;k<=n;k++){
//				printf("%c",s[k]);
				if (s[k] == '+'){
					ans = ans + rec;
					rec = 1;
				} else
				if ((s[k] >= '0') && (s[k] <= '9')){
					rec = rec * (s[k] - '0');
				}
			}
			ans = ans + rec;
//			printf("%I64d\n",ans);
			Ans = max(Ans,ans);
		}
	}
	printf("%I64d\n",Ans);
}
