/* 
ID:cqz15311
LANG:C++ 
PROG:spin 
*/  
#include <cstdio>
#include <iostream>  
using namespace std;  
  
struct ss  
{  
       int s,t;  
} a[6][1000];  
int v[6];  
int times[400];  
int tot[6],ans;  
bool can;  
  
void check(int t)  
{  
     fill_n(times,360,0);  
     for (int i=1;i<=5;++i)  
         for (int j=1;j<=tot[i];++j)  
         {  
             if (t) a[i][j].s=(a[i][j].s+v[i])%360;  
             for (int k=0;k<=a[i][j].t;++k)  
                 ++times[(a[i][j].s+k)%360];  
         }  
     for (int i=0;i<360;++i)  
         if (times[i]>4)  
         {  
                       can=1;  
                       ans=t;  
                       return;  
         }  
}  
  
int main()  
{  
    freopen("spin.in","r",stdin);  
    freopen("spin.out","w",stdout);  
      
    for (int i=1;i<=5;++i)  
    {  
        scanf("%d%d",&v[i],&tot[i]);  
        for (int j=1;j<=tot[i];++j) scanf("%d%d",&a[i][j].s,&a[i][j].t);  
    }  
      
    for (int t=0;t<=360;++t)  
        if (!can)  
           check(t);  
          
    if (can) printf("%d\n",ans);  
    else printf("none\n");  
      
    return 0;  
}  
