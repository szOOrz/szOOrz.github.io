#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
    long long n,m;
    cin>>n>>m;
    long long ans=0;
    ans=(n%mod)*(m%mod)%mod;
    if(m>=n){m=n;}
    long long fx,fy,fz,pre=m;
    long long s=0;
    while(pre>1)
    {
        fy=pre;
        fz=n/pre;
        fx=n/(fz+1);
        long long r;
        if((fy-fx)%2==0)r=((fx+fy+1)%mod)*(((fy-fx)/2)%mod);
        else r=((fx+fy+1)/2)%mod*((fy-fx)%mod);
        s+=(r%mod)*fz%mod;
        s%=mod;
        pre=fx;
    }
    s+=n;
    s%=mod;
    cout<<(ans-s+mod)%mod<<endl;
    return 0;
}
