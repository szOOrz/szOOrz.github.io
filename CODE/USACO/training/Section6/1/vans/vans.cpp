/*
ID:cqz15311
LANG:C++
PROG:vans
*/
#include<cstdio> 
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;  
int n;
struct GJD{
	static const int BASE = 100000000;
	static const int WIDTH = 8;	
    long long val[55];
	int len;
    bool operator < (const GJD &x) const{
        if (len < x.len) return true;
        if (len > x.len) return false;
        for (int i=len;i>=1;i--){
            if (val[i] < x.val[i]) return true;
            if (val[i] > x.val[i]) return false;
        }
        return false;//等于 
    }
    bool operator > (const GJD &b)const{return b < *this;}
    bool operator <= (const GJD &b)const{return !(b < *this);}
    bool operator >= (const GJD &b)const{return !(*this < b);}
    bool operator == (const GJD &b)const{return !(b<*this) && !(*this<b);}
    bool operator != (const GJD &b)const{return !(*this == b);}
    
    GJD operator + (const GJD &x) const{
		GJD c;
		if (len < x.len) c.len = x.len; else c.len = len;
		for (int i=1;i<=c.len;i++)c.val[i] += val[i] + x.val[i],c.val[i+1] += c.val[i] / BASE,c.val[i] %= BASE;
		while (c.val[c.len+1] > 0)c.len++,c.val[c.len+1] += c.val[c.len] / BASE,c.val[c.len] %= BASE;
		return c;
	}

	GJD operator - (const GJD &x) const{
		GJD c;
		for (int i=len;i>=1;i--){
			c.val[i] = val[i] - x.val[i];
			int j = i;
			while (c.val[j] < 0){
				c.val[j]+=BASE;
				c.val[j+1]-=1;
			}
		}
		c.len = len;
		while (len>=1 && c.val[c.len] == 0) c.len--;
		return c;
	}//无负数减法 
	
    GJD operator * (const GJD &x) const{
        GJD c;
        for (int i=1;i<=len;i++)
            for (int j=1;j<=x.len;j++)
                c.val[i+j-1] += val[i] * x.val[j];
        
        c.len = len + x.len - 1;
        for (int i=1;i<=c.len;i++){
            c.val[i+1] += c.val[i] / BASE;
            c.val[i] %= BASE;
        }
        while (c.val[c.len+1] > 0){
            c.len++;
            c.val[c.len+1] += c.val[c.len] / BASE;
            c.val[c.len] %= BASE;
        }
        return c;
    }
	GJD operator / (const int &x) const{
        GJD a;
        a.len = len;
        for (int i=1;i<=len;i++) a.val[i] = val[i];
        GJD c;
        memset(c.val,0,sizeof(c.val));
        c.len = a.len;
        for (int i=c.len;i>=1;i--){
            c.val[i] = a.val[i] / x;
            a.val[i-1] += (a.val[i] % x) * 10;
        }
        while (c.val[c.len] == 0) c.len--;
        return c;
    }
    GJD(int x = 0){
    	*this = x;
    }
    GJD(long long x){
    	*this = x;
    }
    GJD operator = (long long x){
		memset(val,0,sizeof(val));len = 0;
		if (x == 0){len = 1;return *this;}
		while (x) val[++len] = x % BASE,x/=BASE;
		return *this;
    }
    GJD operator = (int x){
    	*this = (long long)x;
    	return *this;
    }
    
    GJD operator = (char ch[]){
    	memset(val,0,sizeof(val));
    	int Len = strlen(ch);
    	len = (strlen(ch)-1) / WIDTH + 1;
		for (int bit=1;bit<=len-1;bit++){
			for (int j=Len-bit*WIDTH;j<Len-(bit-1)*WIDTH;j++) val[bit] = val[bit] * 10 + ch[j] - 48;
		} 
		for (int j=0;j<Len - WIDTH*(len-1);j++) val[len] = val[len] * 10 + ch[j] - 48;
    }
    GJD operator *=(GJD x){*this = *this * x;return *this;}
    GJD operator +=(GJD x){*this = *this + x;return *this;}
    
    void write(){
		printf("%d",val[len]);
		for (int i=len-1;i>=1;i--){ 
            printf("%.8d",val[i]);
        }
        puts("");
    }
}f[1001],g[1001];
int main(){
	freopen("vans.in","r",stdin);
	freopen("vans.out","w",stdout);
	scanf("%d",&n);  
	g[1] = 2;g[2] = 2;g[3] = 8; 
	f[1] = 0;f[2] = 2;f[3] = 4;  
	for (int i=4;i<=n;i++){
		g[i]=((f[i-1] * 2) + g[i-1] + g[i-2]) - g[i-3];  
		f[i]=f[i-1] + g[i-1];
	}  
	f[n].write();
	return 0;
}  
