#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
const int maxn = 1e5+100;
char s[10];
int n,m,type[maxn],val[maxn];
int get(int x,int bit){
	for (int i=1;i<=n;i++){
		if (type[i] == 1) x&=val[i]>>bit;
		if (type[i] == 2) x|=val[i]>>bit;
		if (type[i] == 3) x^=val[i]>>bit;
	}
	return x;
}
int main(){
//	freopen("ex_sleep2.in","r",stdin);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s%d",s,&val[i]);
		if (s[0] == 'A') type[i] = 1; else
		if (s[0] == 'O') type[i] = 2; else
		if (s[0] == 'X') type[i] = 3;
	}
	bool flag = true;
	int Ans=0,limit;
	for (int bit=29;bit>=0;bit--){
		if (flag) limit = (m >> bit) & 1; else limit = 1;
		if (limit == 1)
			if (get(0,bit) < get(1,bit)) Ans |= 1<<bit; else flag = false;
	}
//	printf("%d\n",Ans);
	for (int i=1;i<=n;i++){
		if (type[i] == 1) Ans&=val[i];
		if (type[i] == 2) Ans|=val[i];
		if (type[i] == 3) Ans^=val[i];
	}
	printf("%d\n",Ans);
	return 0;
}
