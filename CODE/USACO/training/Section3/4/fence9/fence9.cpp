/*
ID:cqz15311 
LANG:C++ 
PROG:fence9
*/
#include<bits/stdc++.h>
using namespace std;  
int gcd(int a,int b){
	if(!b)return a;else return gcd(b,a%b);  
}  
int main(){  
    freopen("fence9.in","r",stdin);  
    freopen("fence9.out","w",stdout);  
    int n,m,p;  
    scanf("%d%d%d",&n,&m,&p);
    int s,a,b;  
    b=0;  
    b+=gcd(n,m);
    b+=gcd(abs(p-n),m);
    b+=p;  
    s=(p*m) / 2;  
    a=s-b / 2+1;  
    printf("%d\n",a);
    return 0;
}  
/*
Executing...
   Test 1: TEST OK [0.000 secs, 4176 KB]
   Test 2: TEST OK [0.000 secs, 4176 KB]
   Test 3: TEST OK [0.000 secs, 4176 KB]
   Test 4: TEST OK [0.000 secs, 4176 KB]
   Test 5: TEST OK [0.000 secs, 4176 KB]
   Test 6: TEST OK [0.000 secs, 4176 KB]
   Test 7: TEST OK [0.000 secs, 4176 KB]
   Test 8: TEST OK [0.000 secs, 4176 KB]
   Test 9: TEST OK [0.000 secs, 4176 KB]
   Test 10: TEST OK [0.000 secs, 4176 KB]
   Test 11: TEST OK [0.000 secs, 4176 KB]
   Test 12: TEST OK [0.000 secs, 4176 KB]

All tests OK.
*/
