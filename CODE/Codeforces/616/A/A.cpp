#include<bits/stdc++.h>
using namespace std;
char a[1000005],b[1000005];
int ta,tb,sa,sb,Lena,Lenb;
int main(){
	scanf("%s",a);
	scanf("%s",b);
	ta = strlen(a);
	tb = strlen(b);
	sa = 0;
	sb = 0;
	for (int i=0;a[i];i++){
		if (a[i] != '0') break;
		sa++;
	}
	for (int i=0;b[i];i++){
		if (b[i] != '0') break;
		sb++;
	}
	Lena = (ta - sa);
	Lenb = (tb - sb);
//	printf("%d %d\n",Lena,Lenb);
	if (Lena>Lenb) {puts(">");return 0;} else
	if (Lena<Lenb) {puts("<");return 0;} else{
		for (int i=1;i<=Lena;i++){
			if (a[sa] < b[sb]){
				puts("<");
				return 0;
			}
			if (a[sa] > b[sb]){
				puts(">");
				return 0;
			}
			sa++;
			sb++; 
		}
	}
	puts("=");
	return 0;
}
