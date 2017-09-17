/*
ID:cqz15311
LANG:C++
PROB:calfflac
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
char x[205000],s[405000];
int maxR,pos,n,p[405000];
int Pos[405000];
int main(){
	freopen("calfflac.in","r",stdin);
	freopen("calfflac.out","w",stdout);
	int t = 0,x0 = 0;
	while (1){
		t = getchar();
		if (t == -1) break;
		x[x0++] = t;	
	}
	s[0] = '#';
	n = 1;
	for (int i=0;x[i];i++){
		if ((x[i]<'A'||x[i]>'Z')&&(x[i]<'a'||x[i]>'z')) continue;
//		printf("%c",x[i]);
		Pos[n] = i;
		s[n] = x[i] >= 'a'?x[i] - 'a' + 'A':x[i];
		n++;
		Pos[n] = i;
		s[n] = '#';
		n++;
	}
	p[0] = 1;
	maxR = 0;
	pos = 0;
//	printf("%d\n",n);
	for (int i=1;i<n;i++){
		if (i < maxR) p[i] = min(p[2*pos - i],maxR - i); else p[i] = 1;
		while (i - p[i] >= 0 && i + p[i] < n && s[i-p[i]] == s[i+p[i]]) p[i]++;
		if (p[i] + i - 1 > maxR) maxR = p[pos = i];
	}
//	for (int i=0;i<n;i++){printf("%c",s[i]);}puts("");
	int MAXID = 0;
	for (int i=0;i<n;i++){
		p[i]--;
//		printf("%d %d %d\n",i,p[i],Pos[i]);
		if (p[i] > p[MAXID]) MAXID = i;
	}
	int i,j,tmp;
	printf("%d\n",p[MAXID]);
	if (p[MAXID] & 1){
//		printf("%d\n",Pos[MAXID]);
		tmp = p[MAXID] / 2;
		for (i=Pos[MAXID]-1;tmp;i--)
			if (x[i] >= 'A' && x[i] <= 'Z' || x[i] >= 'a' && x[i] <= 'z') tmp--;
		tmp = p[MAXID] / 2;
		for (j=Pos[MAXID]+1;tmp;j++)
			if (x[j] >= 'A' && x[j] <= 'Z' || x[j] >= 'a' && x[j] <= 'z') tmp--;
		for (int k=i+1;k<=j-1;k++) printf("%c",x[k]);
	} else{
		tmp = p[MAXID] / 2;
		for (i=Pos[MAXID];tmp;i--)
			if (x[i] >= 'A' && x[i] <= 'Z' || x[i] >= 'a' && x[i] <= 'z') tmp--;
		tmp = p[MAXID] / 2;
		for (j=Pos[MAXID]+1;tmp;j++)
			if (x[j] >= 'A' && x[j] <= 'Z' || x[j] >= 'a' && x[j] <= 'z') tmp--;
//		printf("%d %d\n",i,j);
		for (int k=i+1;k<=j-1;k++) printf("%c",x[k]);
	}
	puts("");
}
