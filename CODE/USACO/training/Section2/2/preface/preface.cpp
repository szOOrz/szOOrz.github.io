/*
ID:cqz15311
PROG:preface
LANG:C++
*/
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
int n,i,v,x,l,c,d,m,xx;
int main()
{
	freopen("preface.in","r",stdin);
	freopen("preface.out","w",stdout);
	scanf("%d",&n);
	i=0;v=0;x=0;l=0;c=0;d=0;m=0;
	for (int Q=1;Q<=n;Q++)
	{
		xx=Q;
		while (xx>0)
		{
		          if (xx>=1000) {xx-=1000;m++;}
                  if (xx>=900 && xx<1000) {xx-=900;c++;m++;}
                  if (xx>=500 && xx<900) {xx-=500;d++;}
                  if (xx>=400 && xx<500) {xx-=400;c++;d++;}
                  if (xx>=100 && xx<400) {xx-=100;c++;}
                  if (xx>=90 && xx<100) {xx-=90;x++;c++;}
                  if (xx>=50 && xx<90) {xx-=50;l++;}
                  if (xx>=40 && xx<50) {xx-=40;x++;l++;}
                  if (xx>=10 && xx<40) {xx-=10;x++;}
                  if (xx>=9 && xx<10) {xx-=9;i++;x++;}
                  if (xx>=5 && xx<9) {xx-=5;v++;}
                  if (xx>=4 && xx<5) {xx-=4;i++;v++;}
                  if (xx>=1 && xx<4) {xx-=1;i++;}
		}
	}
	if (i!=0) fprintf(stdout,"I %d\n",i);
	if (v!=0) fprintf(stdout,"V %d\n",v);
	if (x!=0) fprintf(stdout,"X %d\n",x);
	if (l!=0) fprintf(stdout,"L %d\n",l);
	if (c!=0) fprintf(stdout,"C %d\n",c);
	if (d!=0) fprintf(stdout,"D %d\n",d);
	if (m!=0) fprintf(stdout,"M %d\n",m);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
